/*===================================================================*/
/*                                                                   */
/*  K6502.cpp : 6502 Emulator                                        */
/*                                                                   */
/*  2000/5/10   InfoNES Project ( based on pNesX )                   */
/*                                                                   */
/*===================================================================*/

/*-------------------------------------------------------------------*/
/*  Include files                                                    */
/*-------------------------------------------------------------------*/

#include "K6502.h"
#include "InfoNES_System.h"
#include "InfoNES.h"

/*-------------------------------------------------------------------*/
/*  Operation Macros                                                 */
/*-------------------------------------------------------------------*/

// Clock Op.
#define CLK(a)   g_wPassedClocks += (BYTE)(a);

// Addressing Op.
// Address
// (Indirect,X)
#define AA_IX    K6502_ReadZpW( (++PC, ROMBANK_P[0]) + X )
// (Indirect),Y
#define AA_IY    K6502_ReadZpW( (++PC, ROMBANK_P[0]) ) + Y
// Zero Page
#define AA_ZP    (++PC, ROMBANK_P[0])
// Zero Page,X
#define AA_ZPX   (BYTE)( (++PC, ROMBANK_P[0]) + X )
// Zero Page,Y
#define AA_ZPY   (BYTE)( (++PC, ROMBANK_P[0]) + Y )
// Absolute
#define AA_ABS   ( K6502_Read( PC++ ) | (WORD)K6502_Read( PC++ ) << 8 )
// Absolute2 ( PC-- )
#define AA_ABS2  ( K6502_Read( PC++ ) | (WORD)K6502_Read( PC ) << 8 )
// Absolute,X
#define AA_ABSX  AA_ABS + X
// Absolute,Y
#define AA_ABSY  AA_ABS + Y

// Data
// (Indirect,X)
#define A_IX    K6502_Read( AA_IX )
// (Indirect),Y
#define A_IY    K6502_ReadIY()
// Zero Page
#define A_ZP    RAM[ AA_ZP ]
// Zero Page,X
#define A_ZPX   RAM[ AA_ZPX ]
// Zero Page,Y
#define A_ZPY   RAM[ AA_ZPY ]
// Absolute
#define A_ABS   K6502_Read( AA_ABS )
// Absolute,X
#define A_ABSX  K6502_ReadAbsX()
// Absolute,Y
#define A_ABSY  K6502_ReadAbsY()
// Immediate
#define A_IMM   (++PC, ROMBANK_P[0])

// Flag Op.
#define SETF(a)  F |= (BYTE)(a)
#define RSTF(a)  F &= (BYTE)~(a)
#define TEST(a)  RSTF( FLAG_N | FLAG_Z ); SETF( g_byTestTable[ a ] )

// Load & Store Op.
#define STA(a)    K6502_Write( (a), A );
#define STX(a)    K6502_Write( (a), X );
#define STY(a)    K6502_Write( (a), Y );
#define LDA(a)    A = (a); TEST( A );
#define LDX(a)    X = (a); TEST( X );
#define LDY(a)    Y = (a); TEST( Y );

// Stack Op.
#define PUSH(a)   K6502_Write( BASE_STACK + SP--, (a) )
#define PUSHW(a)  PUSH( (a) >> 8 ); PUSH( (a) & (BYTE)0xff )
#define POP(a)    a = K6502_Read( BASE_STACK + ++SP )
#define POPW(a)   POP(a); a |= ( (WORD)K6502_Read( BASE_STACK + ++SP ) << 8 )

// Logical Op.
#define ORA(a)  A |= (a); TEST( A )
#define AND(a)  A &= (a); TEST( A )
#define EOR(a)  A ^= (a); TEST( A )
#define BIT(a)  byD0 = (a); RSTF( FLAG_N | FLAG_V | FLAG_Z ); SETF( ( byD0 & ( FLAG_N | FLAG_V ) ) | ( ( byD0 & A ) ? (BYTE)0 : FLAG_Z ) );
#define CMP(a)  wD0 = (WORD)A - (a); RSTF( FLAG_N | FLAG_Z | FLAG_C ); SETF( g_byTestTable[ ((BYTE*)&wD0)[0] ] | ( ((BYTE*)&wD0)[1] == (BYTE)0 ? FLAG_C : (BYTE)0 ) );
#define CPX(a)  wD0 = (WORD)X - (a); RSTF( FLAG_N | FLAG_Z | FLAG_C ); SETF( g_byTestTable[ ((BYTE*)&wD0)[0] ] | ( ((BYTE*)&wD0)[1] == (BYTE)0 ? FLAG_C : (BYTE)0 ) );
#define CPY(a)  wD0 = (WORD)Y - (a); RSTF( FLAG_N | FLAG_Z | FLAG_C ); SETF( g_byTestTable[ ((BYTE*)&wD0)[0] ] | ( ((BYTE*)&wD0)[1] == (BYTE)0 ? FLAG_C : (BYTE)0 ) );
  
// Math Op. (A D flag isn't being supported.)
#define ADC(a)  byD0 = (a); \
                wD0 = (WORD)A + byD0 + ( F & FLAG_C ); \
                byD1 = ((BYTE*)&wD0)[0]; \
                RSTF( FLAG_N | FLAG_V | FLAG_Z | FLAG_C ); \
                SETF( g_byTestTable[ byD1 ] | ( ( ~( A ^ byD0 ) & ( A ^ byD1 ) & (BYTE)0x80 ) ? FLAG_V : (BYTE)0 ) | ( ((BYTE*)&wD0)[1] != (BYTE)0 ) ); \
                A = byD1;

#define SBC(a)  byD0 = (a); \
                wD0 = (WORD)A - byD0 - ( ~F & FLAG_C ); \
                byD1 = ((BYTE*)&wD0)[0]; \
                RSTF( FLAG_N | FLAG_V | FLAG_Z | FLAG_C ); \
                SETF( g_byTestTable[ byD1 ] | ( ( ( A ^ byD0 ) & ( A ^ byD1 ) & (BYTE)0x80 ) ? FLAG_V : (BYTE)0 ) | ( ((BYTE*)&wD0)[1] == (BYTE)0 ) ); \
                A = byD1;

#define DEC(a)  wA0 = a; byD0 = K6502_Read( wA0 ); --byD0; K6502_Write( wA0, byD0 ); TEST( byD0 )
#define INC(a)  wA0 = a; byD0 = K6502_Read( wA0 ); ++byD0; K6502_Write( wA0, byD0 ); TEST( byD0 )

// Shift Op.
#define ASLA    RSTF( FLAG_N | FLAG_Z | FLAG_C ); SETF( g_ASLTable[ A ].byFlag ); A = g_ASLTable[ A ].byValue 
#define ASL(a)  RSTF( FLAG_N | FLAG_Z | FLAG_C ); wA0 = a; byD0 = K6502_Read( wA0 ); SETF( g_ASLTable[ byD0 ].byFlag ); K6502_Write( wA0, g_ASLTable[ byD0 ].byValue )
#define LSRA    RSTF( FLAG_N | FLAG_Z | FLAG_C ); SETF( g_LSRTable[ A ].byFlag ); A = g_LSRTable[ A ].byValue 
#define LSR(a)  RSTF( FLAG_N | FLAG_Z | FLAG_C ); wA0 = a; byD0 = K6502_Read( wA0 ); SETF( g_LSRTable[ byD0 ].byFlag ); K6502_Write( wA0, g_LSRTable[ byD0 ].byValue ) 
#define ROLA    byD0 = F & FLAG_C; RSTF( FLAG_N | FLAG_Z | FLAG_C ); SETF( g_ROLTable[ byD0 ][ A ].byFlag ); A = g_ROLTable[ byD0 ][ A ].byValue 
#define ROL(a)  byD1 = F & FLAG_C; RSTF( FLAG_N | FLAG_Z | FLAG_C ); wA0 = a; byD0 = K6502_Read( wA0 ); SETF( g_ROLTable[ byD1 ][ byD0 ].byFlag ); K6502_Write( wA0, g_ROLTable[ byD1 ][ byD0 ].byValue )
#define RORA    byD0 = F & FLAG_C; RSTF( FLAG_N | FLAG_Z | FLAG_C ); SETF( g_RORTable[ byD0 ][ A ].byFlag ); A = g_RORTable[ byD0 ][ A ].byValue 
#define ROR(a)  byD1 = F & FLAG_C; RSTF( FLAG_N | FLAG_Z | FLAG_C ); wA0 = a; byD0 = K6502_Read( wA0 ); SETF( g_RORTable[ byD1 ][ byD0 ].byFlag ); K6502_Write( wA0, g_RORTable[ byD1 ][ byD0 ].byValue )

// Jump Op.
#define JSR     wA0 = AA_ABS2; PUSHW( PC ); PC = wA0; 
#define BRA(a)  if ( a ) { wA0 = PC; PC += (char)ROMBANK_P[0]; CLK( (BYTE)3 + ( ( ((BYTE*)&wA0)[1] & (BYTE)0x01 ) != ( ((BYTE*)&PC)[1] & (BYTE)0x01 ) ) ); ++PC; } else { ++PC; CLK( 2 ); }
#define JMP(a)  PC = a;

/*-------------------------------------------------------------------*/
/*  Global valiables                                                 */
/*-------------------------------------------------------------------*/

// 6502 Register
WORD PC = 0;
BYTE SP = 0;
BYTE F = 0;
BYTE A = 0;
BYTE X = 0;
BYTE Y = 0;

// The state of the IRQ pin
BYTE IRQ_State;

// Wiring of the IRQ pin
BYTE IRQ_Wiring;

// The state of the NMI pin
BYTE NMI_State;

// Wiring of the NMI pin
BYTE NMI_Wiring;

// The number of the clocks that it passed
BYTE g_wPassedClocks = 0;

// A table for the test
BYTE g_byTestTable[ 256 ];

// Value and Flag Data
struct value_table_tag
{
  BYTE byValue;
  BYTE byFlag;
};

// A table for ASL
struct value_table_tag g_ASLTable[ 256 ];

// A table for LSR
struct value_table_tag g_LSRTable[ 256 ];

// A table for ROL
struct value_table_tag g_ROLTable[ 2 ][ 256 ];

// A table for ROR
struct value_table_tag g_RORTable[ 2 ][ 256 ];

/*===================================================================*/
/*                                                                   */
/*                K6502_Init() : Initialize K6502                    */
/*                                                                   */
/*===================================================================*/
void K6502_Init()
{
/*
 *  Initialize K6502
 *
 *  You must call this function only once at first.
 */

  BYTE idx;
  BYTE idx2;

  // The establishment of the IRQ pin
  NMI_Wiring = NMI_State = 1;
  IRQ_Wiring = IRQ_State = 1;

  // Make a table for the test
  idx = 0;
  do
  {
    if ( idx == 0 )
      g_byTestTable[ 0 ] = FLAG_Z;
    else
    if ( idx > 127 )
      g_byTestTable[ idx ] = FLAG_N;
    else
      g_byTestTable[ idx ] = 0;

    ++idx;
  } while ( idx != 0 );

  // Make a table ASL
  idx = 0;
  do
  {
    g_ASLTable[ idx ].byValue = idx << 1;
    g_ASLTable[ idx ].byFlag = 0;

    if ( idx > 127 )
      g_ASLTable[ idx ].byFlag = FLAG_C;

    if ( g_ASLTable[ idx ].byValue == 0 )
      g_ASLTable[ idx ].byFlag |= FLAG_Z;
    else
    if ( (g_ASLTable[ idx ].byValue & (BYTE)0x80) == (BYTE)0x80)
      g_ASLTable[ idx ].byFlag |= FLAG_N;

    ++idx;
  } while ( idx != 0 );

  // Make a table LSR
  idx = 0;
  do
  {
    g_LSRTable[ idx ].byValue = idx >> 1;
    g_LSRTable[ idx ].byFlag = 0;

    if ( idx & 1 )
      g_LSRTable[ idx ].byFlag = FLAG_C;

    if ( g_LSRTable[ idx ].byValue == 0 )
      g_LSRTable[ idx ].byFlag |= FLAG_Z;

    ++idx;
  } while ( idx != 0 );

  // Make a table ROL
  for ( idx2 = 0; idx2 < 2; ++idx2 )
  {
    idx = 0;
    do
    {
      g_ROLTable[ idx2 ][ idx ].byValue = ( idx << 1 ) | idx2;
      g_ROLTable[ idx2 ][ idx ].byFlag = 0;

      if ( idx > 127 )
        g_ROLTable[ idx2 ][ idx ].byFlag = FLAG_C;

      if ( g_ROLTable[ idx2 ][ idx ].byValue == 0 )
        g_ROLTable[ idx2 ][ idx ].byFlag |= FLAG_Z;
      else
      if ( (g_ROLTable[ idx2 ][ idx ].byValue & (BYTE)0x80) == (BYTE)0x80)
        g_ROLTable[ idx2 ][ idx ].byFlag |= FLAG_N;

      ++idx;
    } while ( idx != 0 );
  }

  // Make a table ROR
  for ( idx2 = 0; idx2 < 2; ++idx2 )
  {
    idx = 0;
    do
    {
      g_RORTable[ idx2 ][ idx ].byValue = ( idx >> 1 ) | ( idx2 << 7 );
      g_RORTable[ idx2 ][ idx ].byFlag = 0;

      if ( idx & 1 )
        g_RORTable[ idx2 ][ idx ].byFlag = FLAG_C;

      if ( g_RORTable[ idx2 ][ idx ].byValue == 0 )
        g_RORTable[ idx2 ][ idx ].byFlag |= FLAG_Z;
      else
      if ( (g_RORTable[ idx2 ][ idx ].byValue & (BYTE)0x80) == (BYTE)0x80)
        g_RORTable[ idx2 ][ idx ].byFlag |= FLAG_N;

      ++idx;
    } while ( idx != 0 );
  }
}

/*===================================================================*/
/*                                                                   */
/*                K6502_Reset() : Reset a CPU                        */
/*                                                                   */
/*===================================================================*/
void K6502_Reset()
{
/*
 *  Reset a CPU
 *
 */

  // Reset Registers
  PC = K6502_ReadW( VECTOR_RESET );
  SP = 0xFF;
  A = X = Y = 0;
  F = FLAG_Z | FLAG_R | FLAG_I;

  // Set up the state of the Interrupt pin.
  NMI_State = NMI_Wiring;
  IRQ_State = IRQ_Wiring;

  // Reset Passed Clocks
  g_wPassedClocks = 0;
}

/*===================================================================*/
/*                                                                   */
/*    K6502_Set_Int_Wiring() : Set up wiring of the interrupt pin    */
/*                                                                   */
/*===================================================================*/
void K6502_Set_Int_Wiring( BYTE byNMI_Wiring, BYTE byIRQ_Wiring )
{
/*
 * Set up wiring of the interrupt pin
 *
 */

  NMI_Wiring = byNMI_Wiring;
  IRQ_Wiring = byIRQ_Wiring;
}

BYTE byCode = 0;
WORD wA0 = 0;
BYTE byD0 = 0;
BYTE byD1 = 0;
WORD wD0 = 0;
BYTE* ROMBANK_P = 0;
BYTE AD = 0;

void instruct_0() {
    ++PC; PUSHW(PC); SETF(FLAG_B); PUSH(F); SETF(FLAG_I); RSTF(FLAG_D); PC = K6502_ReadW(VECTOR_IRQ); CLK(7);
}
void instruct_1() {
    ORA(A_IX); CLK(6);
}
void instruct_2() {
}
void instruct_3() {}
void instruct_4() {
    PC++;
    CLK(3);
}
void instruct_5() {
    ORA(A_ZP); CLK(3);
}
void instruct_6() {
    ASL(AA_ZP); CLK(5);
}
void instruct_7() {}
void instruct_8() {
    SETF(FLAG_B); PUSH(F); CLK(3);
}
void instruct_9() {
    ORA(A_IMM); CLK(2);
}
void instruct_10() {
    ASLA; CLK(2);
}
void instruct_11() {}
void instruct_12() {
    PC += 2;
    CLK(4);
}
void instruct_13() {
    ORA(A_ABS); CLK(4);
}
void instruct_14() {
    ASL(AA_ABS); CLK(6);
}
void instruct_15() {}
void instruct_16() {
    BRA(!(F & FLAG_N));
}
void instruct_17() {
    ORA(A_IY); CLK(5);
}
void instruct_18() {}
void instruct_19() {}
void instruct_20() {
    PC++;
    CLK(4);
}
void instruct_21() {
    ORA(A_ZPX); CLK(4);
}
void instruct_22() {
    ASL(AA_ZPX); CLK(6);
}
void instruct_23() {}
void instruct_24() {
    RSTF(FLAG_C); CLK(2);
}
void instruct_25() {
    ORA(A_ABSY); CLK(4);
}
void instruct_26() {
    CLK(2);
}
void instruct_27() {}
void instruct_28() {
    PC += 2;
    CLK(4);
}
void instruct_29() {
    ORA(A_ABSX); CLK(4);
}
void instruct_30() {
    ASL(AA_ABSX); CLK(7);
}
void instruct_31() {}
void instruct_32() {
    ((BYTE*)&wA0)[0] = ROMBANK_P[0];
    ((BYTE*)&wA0)[1] = ROMBANK_P[1];
    ++PC;
    RAM[BASE_STACK + SP--] = ((BYTE*)&PC)[1]; //优化操作
    RAM[BASE_STACK + SP--] = ((BYTE*)&PC)[0];
    PC = wA0;
    CLK(6);
    //JSR; CLK(6);
}
void instruct_33() {
    AND(A_IX); CLK(6);
}
void instruct_34() {}
void instruct_35() {}
void instruct_36() {
    BIT(A_ZP); CLK(3);
}
void instruct_37() {
    AND(A_ZP); CLK(3);
}
void instruct_38() {
    ROL(AA_ZP); CLK(5);
}
void instruct_39() {}
void instruct_40() {
    POP(F); SETF(FLAG_R); CLK(4);
}
void instruct_41() {
    AND(A_IMM); CLK(2);
}
void instruct_42() {
    ROLA; CLK(2);
}
void instruct_43() {}
void instruct_44() {
    BIT(A_ABS); CLK(4);
}
void instruct_45() {
    AND(A_ABS); CLK(4);
}
void instruct_46() {
    ROL(AA_ABS); CLK(6);
}
void instruct_47() {}
void instruct_48() {
    BRA(F & FLAG_N);
}
void instruct_49() {
    AND(A_IY); CLK(5);
}
void instruct_50() {}
void instruct_51() {}
void instruct_52() {
    PC++;
    CLK(4);
}
void instruct_53() {
    AND(A_ZPX); CLK(4);
}
void instruct_54() {
    ROL(AA_ZPX); CLK(6);
}
void instruct_55() {}
void instruct_56() {
    SETF(FLAG_C); CLK(2);
}
void instruct_57() {
    AND(A_ABSY); CLK(4);
}
void instruct_58() {
    CLK(2);
}
void instruct_59() {}
void instruct_60() {
    PC += 2;
    CLK(4);
}
void instruct_61() {
    AND(A_ABSX); CLK(4);
}
void instruct_62() {
    ROL(AA_ABSX); CLK(7);
}
void instruct_63() {}
void instruct_64() {
    POP(F); SETF(FLAG_R); POPW(PC); CLK(6);
}
void instruct_65() {
    EOR(A_IX); CLK(6);
}
void instruct_66() {}
void instruct_67() {}
void instruct_68() {
    PC++;
    CLK(3);
}
void instruct_69() {
    EOR(A_ZP); CLK(3);
}
void instruct_70() {
    LSR(AA_ZP); CLK(5);
}
void instruct_71() {}
void instruct_72() {
    PUSH(A); CLK(3);
}
void instruct_73() {
    EOR(A_IMM); CLK(2);
}
void instruct_74() {
    LSRA; CLK(2);
}
void instruct_75() {}
void instruct_76() {
    JMP(AA_ABS); CLK(3);
}
void instruct_77() {
    EOR(A_ABS); CLK(4);
}
void instruct_78() {
    LSR(AA_ABS); CLK(6);
}
void instruct_79() {}
void instruct_80() {
    BRA(!(F & FLAG_V));
}
void instruct_81() {
    EOR(A_IY); CLK(5);
}
void instruct_82() {}
void instruct_83() {}
void instruct_84() {
    PC++;
    CLK(4);
}
void instruct_85() {
    EOR(A_ZPX); CLK(4);
}
void instruct_86() {
    LSR(AA_ZPX); CLK(6);
}
void instruct_87() {}
void instruct_88() {
    byD0 = F;
    RSTF(FLAG_I); CLK(2);
    if ((byD0 & FLAG_I) && IRQ_State != IRQ_Wiring)
    {
        IRQ_State = IRQ_Wiring;
        CLK(7);

        PUSHW(PC);
        PUSH(F & (BYTE)~FLAG_B);

        RSTF(FLAG_D);
        SETF(FLAG_I);

        PC = K6502_ReadW(VECTOR_IRQ);
    }
}
void instruct_89() {
    EOR(A_ABSY); CLK(4);
}
void instruct_90() {
    CLK(2);
}
void instruct_91() {}
void instruct_92() {
    PC += 2;
    CLK(4);
}
void instruct_93() {
    EOR(A_ABSX); CLK(4);
}
void instruct_94() {
    LSR(AA_ABSX); CLK(7);
}
void instruct_95() {}
void instruct_96() {
    ((BYTE*)&PC)[0] = RAM[BASE_STACK + ++SP]; //优化操作
    ((BYTE*)&PC)[1] = RAM[BASE_STACK + ++SP];
    ++PC;
    CLK(6);
    //POPW(PC); ++PC; CLK(6);
}
void instruct_97() {
    ADC(A_IX); CLK(6);
}
void instruct_98() {}
void instruct_99() {}
void instruct_100() {
    PC++;
    CLK(3);
}
void instruct_101() {
    ADC(A_ZP); CLK(3);
}
void instruct_102() {
    ROR(AA_ZP); CLK(5);
}
void instruct_103() {}
void instruct_104() {
    A = RAM[BASE_STACK + ++SP]; //优化操作
    TEST(A);
    CLK(4);
    //POP(A); TEST(A); CLK(4);
}
void instruct_105() {
    ADC(A_IMM); CLK(2);
}
void instruct_106() {
    RORA; CLK(2);
}
void instruct_107() {}
void instruct_108() {
    JMP(K6502_ReadW2(AA_ABS)); CLK(5);
}
void instruct_109() {
    ADC(A_ABS); CLK(4);
}
void instruct_110() {
    ROR(AA_ABS); CLK(6);
}
void instruct_111() {}
void instruct_112() {
    BRA(F & FLAG_V);
}
void instruct_113() {
    ADC(A_IY); CLK(5);
}
void instruct_114() {}
void instruct_115() {}
void instruct_116() {
    PC++;
    CLK(4);
}
void instruct_117() {
    ADC(A_ZPX); CLK(4);
}
void instruct_118() {
    ROR(AA_ZPX); CLK(6);
}
void instruct_119() {}
void instruct_120() {
    SETF(FLAG_I); CLK(2);
}
void instruct_121() {
    ADC(A_ABSY); CLK(4);
}
void instruct_122() {
    CLK(2);
}
void instruct_123() {}
void instruct_124() {
    PC += 2;
    CLK(4);
}
void instruct_125() {
    ADC(A_ABSX); CLK(4);
}
void instruct_126() {
    ROR(AA_ABSX); CLK(7);
}
void instruct_127() {}
void instruct_128() {
    PC++;
    CLK(2);
}
void instruct_129() {
    STA(AA_IX); CLK(6);
}
void instruct_130() {
    PC++;
    CLK(2);
}
void instruct_131() {}
void instruct_132() {
    RAM[(++PC, ROMBANK_P[0])] = Y; //优化操作
    CLK(3);
    //STY(AA_ZP); CLK(3);
}
void instruct_133() {
    STA(AA_ZP); CLK(3);
}
void instruct_134() {
    RAM[(++PC, ROMBANK_P[0])] = X; //优化操作
    //STX(AA_ZP); CLK(3);
}
void instruct_135() {}
void instruct_136() {
    --Y; TEST(Y); CLK(2);
}
void instruct_137() {
    PC++;
    CLK(2);
}
void instruct_138() {
    A = X; TEST(A); CLK(2);
}
void instruct_139() {}
void instruct_140() {
    STY(AA_ABS); CLK(4);
}
void instruct_141() {
    STA(AA_ABS); CLK(4);
}
void instruct_142() {
    STX(AA_ABS); CLK(4);
}
void instruct_143() {}
void instruct_144() {
    BRA(!(F & FLAG_C));
}
void instruct_145() {
    STA(AA_IY); CLK(6);
}
void instruct_146() {}
void instruct_147() {}
void instruct_148() {
    STY(AA_ZPX); CLK(4);
}
void instruct_149() {
    RAM[AA_ZPX] = A; //优化操作
    CLK(4);
    //STA(AA_ZPX); CLK(4);
}
void instruct_150() {
    STX(AA_ZPY); CLK(4);
}
void instruct_151() {}
void instruct_152() {
    A = Y; TEST(A); CLK(2);
}
void instruct_153() {
    STA(AA_ABSY); CLK(5);
}
void instruct_154() {
    SP = X; CLK(2);
}
void instruct_155() {}
void instruct_156() {}
void instruct_157() {
    RAM[*((WORD*)ROMBANK_P) + X] = A; //优化操作
    PC += 2;
    CLK(5);
}
void instruct_158() {}
void instruct_159() {}
void instruct_160() {
    LDY(A_IMM); CLK(2);
}
void instruct_161() {
    LDA(A_IX); CLK(6);
}
void instruct_162() {
    LDX(A_IMM); CLK(2);
}
void instruct_163() {}
void instruct_164() {
    LDY(A_ZP); CLK(3);
}
void instruct_165() {
    LDA(A_ZP); CLK(3);
}
void instruct_166() {
    LDX(A_ZP); CLK(3);
}
void instruct_167() {}
void instruct_168() {
    Y = A; TEST(A); CLK(2);
}
void instruct_169() {
    LDA(A_IMM); CLK(2);
}
void instruct_170() {
    X = A; TEST(A); CLK(2);
}
void instruct_171() {}
void instruct_172() {
    LDY(A_ABS); CLK(4);
}
void instruct_173() {
    LDA(A_ABS); CLK(4);
}
void instruct_174() {
    LDX(A_ABS); CLK(4);
}
void instruct_175() {}
void instruct_176() {
    BRA(F & FLAG_C);
}
void instruct_177() {
    BYTE i;
    WORD wA0, wA1;
    ((BYTE*)&wA0)[0] = RAM[ROMBANK_P[0]];
    ((BYTE*)&wA0)[1] = RAM[ROMBANK_P[0] + 1];
    ++PC;
    wA1 = wA0 + Y;
    CLK((((BYTE*)&wA0)[1] & 0x01) != (((BYTE*)&wA1)[1] & 0x01)); //优化操作
    i = ((BYTE*)&wA1)[1] >> 5;
    if (i == 0x0)
        A = RAM[wA1];
    else if (i == 0x4)
        A = ROMBANK0[wA1 & 0x1fff];
    else if (i == 0x5)
        A = ROMBANK1[wA1 & 0x1fff];
    else if (i == 0x6)
        A = ROMBANK2[wA1 & 0x1fff];
    else if (i == 0x7)
        A = ROMBANK3[wA1 & 0x1fff];
    TEST(A);
    CLK(5);
}
void instruct_178() {}
void instruct_179() {}
void instruct_180() {
    LDY(A_ZPX); CLK(4);
}
void instruct_181() {
    LDA(A_ZPX); CLK(4);
}
void instruct_182() {
    LDX(A_ZPY); CLK(4);
}
void instruct_183() {}
void instruct_184() {
    RSTF(FLAG_V); CLK(2);
}
void instruct_185() {
    LDA(A_ABSY); CLK(4);
}
void instruct_186() {
    X = SP; TEST(X); CLK(2);
}
void instruct_187() {}
void instruct_188() {
    LDY(A_ABSX); CLK(4);
}
void instruct_189() {
    /*
    BYTE i;
    WORD wA0, wA1;
    wA1 = (wA0 = *((WORD*)ROMBANK_P)) + X;
    CLK((((BYTE*)&wA0)[1] & 0x01) != (((BYTE*)&wA1)[1] & 0x01)); //优化操作
    i = ((BYTE*)&wA1)[1] >> 5;
    if (i == 0x0)
        A = RAM[wA1];
    else if (i == 0x4)
        A = ROMBANK0[wA1 & 0x1fff];
    else if (i == 0x5)
        A = ROMBANK1[wA1 & 0x1fff];
    else if (i == 0x6)
        A = ROMBANK2[wA1 & 0x1fff];
    else if (i == 0x7)
        A = ROMBANK3[wA1 & 0x1fff];
    TEST(A);
    PC += 2;
    CLK(4);
    */
    LDA(A_ABSX); CLK(4);
}
void instruct_190() {
    LDX(A_ABSY); CLK(4);
}
void instruct_191() {}
void instruct_192() {
    CPY(A_IMM); CLK(2);
}
void instruct_193() {
    CMP(A_IX); CLK(6);
}
void instruct_194() {
    PC++;
    CLK(2);
}
void instruct_195() {}
void instruct_196() {
    CPY(A_ZP); CLK(3);
}
void instruct_197() {
    CMP(A_ZP); CLK(3);
}
void instruct_198() {
    TEST(--RAM[AA_ZP]); //优化操作
    CLK(5);
    //DEC(AA_ZP); CLK(5);
}
void instruct_199() {}
void instruct_200() {
    ++Y; TEST(Y); CLK(2);
}
void instruct_201() {
    CMP(A_IMM); CLK(2);
}
void instruct_202() {
    --X; TEST(X); CLK(2);
}
void instruct_203() {}
void instruct_204() {
    CPY(A_ABS); CLK(4);
}
void instruct_205() {
    CMP(A_ABS); CLK(4);
}
void instruct_206() {
    DEC(AA_ABS); CLK(6);
}
void instruct_207() {}
void instruct_208() {
    BRA(!(F & FLAG_Z));
}
void instruct_209() {
    CMP(A_IY); CLK(5);
}
void instruct_210() {}
void instruct_211() {}
void instruct_212() {
    PC++;
    CLK(4);
}
void instruct_213() {
    CMP(A_ZPX); CLK(4);
}
void instruct_214() {
    DEC(AA_ZPX); CLK(6);
}
void instruct_215() {}
void instruct_216() {
    RSTF(FLAG_D); CLK(2);
}
void instruct_217() {
    CMP(A_ABSY); CLK(4);
}
void instruct_218() {
    CLK(2);
}
void instruct_219() {}
void instruct_220() {
    PC += 2;
    CLK(4);
}
void instruct_221() {
    CMP(A_ABSX); CLK(4);
}
void instruct_222() {
    DEC(AA_ABSX); CLK(7);
}
void instruct_223() {}
void instruct_224() {
    CPX(A_IMM); CLK(2);
}
void instruct_225() {
    SBC(A_IX); CLK(6);
}
void instruct_226() {
    PC++;
    CLK(2);
}
void instruct_227() {}
void instruct_228() {
    CPX(A_ZP); CLK(3);
}
void instruct_229() {
    SBC(A_ZP); CLK(3);
}
void instruct_230() {
    INC(AA_ZP); CLK(5);
}
void instruct_231() {}
void instruct_232() {
    ++X; TEST(X); CLK(2);
}
void instruct_233() {
    SBC(A_IMM); CLK(2);
}
void instruct_234() {
    CLK(2);
}
void instruct_235() {}
void instruct_236() {
    CPX(A_ABS); CLK(4);
}
void instruct_237() {
    SBC(A_ABS); CLK(4);
}
void instruct_238() {
    INC(AA_ABS); CLK(6);
}
void instruct_239() {}
void instruct_240() {
    BRA(F & FLAG_Z);
}
void instruct_241() {
    SBC(A_IY); CLK(5);
}
void instruct_242() {}
void instruct_243() {}
void instruct_244() {
    PC++;
    CLK(4);
}
void instruct_245() {
    SBC(A_ZPX); CLK(4);
}
void instruct_246() {
    INC(AA_ZPX); CLK(6);
}
void instruct_247() {}
void instruct_248() {
    SETF(FLAG_D); CLK(2);
}
void instruct_249() {
    SBC(A_ABSY); CLK(4);
}
void instruct_250() {
    CLK(2);
}
void instruct_251() {}
void instruct_252() {
    PC += 2;
    CLK(4);
}
void instruct_253() {
    SBC(A_ABSX); CLK(4);
}
void instruct_254() {
    INC(AA_ABSX); CLK(7);
}
void instruct_255() {}

typedef void (*vfp)(void);

vfp ef[256] = {
    instruct_0,
    instruct_1,
    instruct_2,
    instruct_3,
    instruct_4,
    instruct_5,
    instruct_6,
    instruct_7,
    instruct_8,
    instruct_9,
    instruct_10,
    instruct_11,
    instruct_12,
    instruct_13,
    instruct_14,
    instruct_15,
    instruct_16,
    instruct_17,
    instruct_18,
    instruct_19,
    instruct_20,
    instruct_21,
    instruct_22,
    instruct_23,
    instruct_24,
    instruct_25,
    instruct_26,
    instruct_27,
    instruct_28,
    instruct_29, 
    instruct_30,
    instruct_31,
    instruct_32,
    instruct_33,
    instruct_34,
    instruct_35,
    instruct_36,
    instruct_37,
    instruct_38,
    instruct_39,
    instruct_40,
    instruct_41,
    instruct_42,
    instruct_43,
    instruct_44,
    instruct_45,
    instruct_46,
    instruct_47,
    instruct_48,
    instruct_49,
    instruct_50,
    instruct_51,
    instruct_52,
    instruct_53,
    instruct_54,
    instruct_55,
    instruct_56,
    instruct_57,
    instruct_58,
    instruct_59,
    instruct_60,
    instruct_61,
    instruct_62,
    instruct_63,
    instruct_64,
    instruct_65,
    instruct_66,
    instruct_67,
    instruct_68,
    instruct_69,
    instruct_70,
    instruct_71,
    instruct_72,
    instruct_73,
    instruct_74,
    instruct_75,
    instruct_76,
    instruct_77,
    instruct_78,
    instruct_79,
    instruct_80,
    instruct_81,
    instruct_82,
    instruct_83,
    instruct_84,
    instruct_85,
    instruct_86,
    instruct_87,
    instruct_88,
    instruct_89,
    instruct_90,
    instruct_91,
    instruct_92,
    instruct_93,
    instruct_94,
    instruct_95,
    instruct_96,
    instruct_97,
    instruct_98,
    instruct_99,
    instruct_100,
    instruct_101,
    instruct_102,
    instruct_103,
    instruct_104,
    instruct_105,
    instruct_106,
    instruct_107,
    instruct_108,
    instruct_109,
    instruct_110,
    instruct_111,
    instruct_112,
    instruct_113,
    instruct_114,
    instruct_115,
    instruct_116,
    instruct_117,
    instruct_118,
    instruct_119,
    instruct_120,
    instruct_121,
    instruct_122,
    instruct_123,
    instruct_124,
    instruct_125,
    instruct_126,
    instruct_127,
    instruct_128,
    instruct_129,
    instruct_130,
    instruct_131,
    instruct_132,
    instruct_133,
    instruct_134,
    instruct_135,
    instruct_136,
    instruct_137,
    instruct_138,
    instruct_139,
    instruct_140,
    instruct_141,
    instruct_142,
    instruct_143,
    instruct_144,
    instruct_145,
    instruct_146,
    instruct_147,
    instruct_148,
    instruct_149,
    instruct_150,
    instruct_151,
    instruct_152,
    instruct_153,
    instruct_154,
    instruct_155,
    instruct_156,
    instruct_157,
    instruct_158,
    instruct_159,
    instruct_160,
    instruct_161,
    instruct_162,
    instruct_163,
    instruct_164,
    instruct_165,
    instruct_166,
    instruct_167,
    instruct_168,
    instruct_169,
    instruct_170,
    instruct_171,
    instruct_172,
    instruct_173,
    instruct_174,
    instruct_175,
    instruct_176,
    instruct_177,
    instruct_178,
    instruct_179,
    instruct_180,
    instruct_181,
    instruct_182,
    instruct_183,
    instruct_184,
    instruct_185,
    instruct_186,
    instruct_187,
    instruct_188,
    instruct_189,
    instruct_190,
    instruct_191,
    instruct_192,
    instruct_193,
    instruct_194,
    instruct_195,
    instruct_196,
    instruct_197,
    instruct_198,
    instruct_199,
    instruct_200,
    instruct_201,
    instruct_202,
    instruct_203,
    instruct_204,
    instruct_205,
    instruct_206,
    instruct_207,
    instruct_208,
    instruct_209,
    instruct_210,
    instruct_211,
    instruct_212,
    instruct_213,
    instruct_214,
    instruct_215,
    instruct_216,
    instruct_217,
    instruct_218,
    instruct_219,
    instruct_220,
    instruct_221,
    instruct_222,
    instruct_223,
    instruct_224,
    instruct_225,
    instruct_226,
    instruct_227,
    instruct_228,
    instruct_229,
    instruct_230,
    instruct_231,
    instruct_232,
    instruct_233,
    instruct_234,
    instruct_235,
    instruct_236,
    instruct_237,
    instruct_238,
    instruct_239,
    instruct_240,
    instruct_241,
    instruct_242,
    instruct_243,
    instruct_244,
    instruct_245,
    instruct_246,
    instruct_247,
    instruct_248,
    instruct_249,
    instruct_250,
    instruct_251,
    instruct_252,
    instruct_253,
    instruct_254,
    instruct_255,
};

/*===================================================================*/
/*                                                                   */
/*  K6502_Step() :                                                   */
/*          Only the specified number of the clocks execute Op.      */
/*                                                                   */
/*===================================================================*/
void K6502_Step( BYTE wClocks )
{
/*
 *  Only the specified number of the clocks execute Op.
 *
 *  Parameters
 *    WORD wClocks              (Read)
 *      The number of the clocks
 */
  
  // Dispose of it if there is an interrupt requirement
  if ( NMI_State != NMI_Wiring )
  {
    // NMI Interrupt
    NMI_State = NMI_Wiring;
    CLK( 7 );

    PUSHW( PC );
    PUSH( F & (BYTE)~FLAG_B );

    RSTF( FLAG_D );
    SETF( FLAG_I );

    PC = K6502_ReadW( VECTOR_NMI );
  }
  else
  if ( IRQ_State != IRQ_Wiring )
  {
    // IRQ Interrupt
    // Execute IRQ if an I flag isn't being set
    if ( !( F & FLAG_I ) )
    {
      IRQ_State = IRQ_Wiring;
      CLK( 7 );

      PUSHW( PC );
      PUSH( F & (BYTE)~FLAG_B );

      RSTF( FLAG_D );
      SETF( FLAG_I );
    
      PC = K6502_ReadW( VECTOR_IRQ );
    }
  }

  // It has a loop until a constant clock passes
  while ( g_wPassedClocks < wClocks )
  {
    // Read an instruction
    AD = ((BYTE*)&PC)[1] >> 5;

    if (AD == (BYTE)0x4) {
        byCode = (*(ROMBANK_P = &ROMBANK0[PC & (WORD)0x1fff]));
    }
    else if (AD == (BYTE)0x5) {
        byCode = (*(ROMBANK_P = &ROMBANK1[PC & (WORD)0x1fff]));
    }
    else if (AD == (BYTE)0x6) {
        byCode = (*(ROMBANK_P = &ROMBANK2[PC & (WORD)0x1fff]));
    }
    else if (AD == (BYTE)0x7) {
        byCode = (*(ROMBANK_P = &ROMBANK3[PC & (WORD)0x1fff]));
    }
    else {
        byCode = (*(ROMBANK_P = &RAM[PC & (WORD)0x7ff]));
    }
    ++PC;
    ++ROMBANK_P;

    if (byCode == (BYTE)0x4C) {
        /* JMP Abs */
        PC = *((WORD*)ROMBANK_P);
        CLK(3);
        continue;
    }
    else if (byCode == (BYTE)0x65) {
        /* ADC Zpg */
        byD0 = RAM[ROMBANK_P[0]];
        wD0 = (WORD)A + byD0 + (F & FLAG_C);
        byD1 = ((BYTE*)&wD0)[0];
        RSTF(FLAG_N | FLAG_V | FLAG_Z | FLAG_C);
        SETF(g_byTestTable[byD1] | (((~(A ^ byD0) & (A ^ byD1) & (BYTE)0x80) >> 7) * FLAG_V) | ((BYTE*)&wD0)[1]);
        A = byD1;
        ++PC;
        CLK(3);
        continue;
    }
    else if (byCode == (BYTE)0x85) {
        /* STA Zpg */
        RAM[ROMBANK_P[0]] = A;
        ++PC;
        CLK(3);
        continue;
    }
    else if (byCode == (BYTE)0xA5) {
        /* LDA Zpg */
        A = RAM[ROMBANK_P[0]];
        TEST(A);
        ++PC;
        CLK(3);
        continue;
    }

    // Execute an instruction.
    ef[byCode]();

  }  /* end of while ... */

  // Correct the number of the clocks
  g_wPassedClocks -= wClocks;
}

// Addressing Op.
// Data
// Absolute,X
static BYTE K6502_ReadAbsX(){ WORD wA0, wA1; wA0 = AA_ABS; wA1 = wA0 + X; CLK( ( wA0 & 0x0100 ) != ( wA1 & 0x0100 ) ); return K6502_Read( wA1 ); }
// Absolute,Y
static BYTE K6502_ReadAbsY(){ WORD wA0, wA1; wA0 = AA_ABS; wA1 = wA0 + Y; CLK( ( wA0 & 0x0100 ) != ( wA1 & 0x0100 ) ); return K6502_Read( wA1 ); }
// (Indirect),Y
static BYTE K6502_ReadIY(){ WORD wA0, wA1; wA0 = K6502_ReadZpW( K6502_Read( PC++ ) ); wA1 = wA0 + Y; CLK( ( wA0 & 0x0100 ) != ( wA1 & 0x0100 ) ); return K6502_Read( wA1 ); }

/*===================================================================*/
/*                                                                   */
/*                  6502 Reading/Writing Operation                   */
/*                                                                   */
/*===================================================================*/
#include "K6502_rw.h"
