/*===================================================================*/
/*                                                                   */
/*  InfoNES.cpp : NES Emulator for Win32, Linux(x86), Linux(PS2)     */
/*                                                                   */
/*  2000/05/18  InfoNES Project ( based on pNesX )                   */
/*                                                                   */
/*===================================================================*/

/*-------------------------------------------------------------------
 * File List :
 *
 * [NES Hardware]
 *   InfoNES.cpp
 *   InfoNES.h
 *   K6502_rw.h
 *
 * [Mapper function]
 *   InfoNES_Mapper.cpp
 *   InfoNES_Mapper.h
 *
 * [The function which depends on a system]
 *   InfoNES_System_ooo.cpp (ooo is a system name. win, ...)
 *   InfoNES_System.h
 *
 * [CPU]
 *   K6502.cpp
 *   K6502.h
 *
 * [Others]
 *   InfoNES_Types.h
 *
 --------------------------------------------------------------------*/

/*-------------------------------------------------------------------*/
/*  Include files                                                    */
/*-------------------------------------------------------------------*/

#include "InfoNES.h"
#include "InfoNES_System.h"
#include "InfoNES_Mapper.h"
#include "InfoNES_pAPU.h"
#include "K6502.h"

#include "printf.h"
#include "st7789.h"
#include "ds1302.h"

/*-------------------------------------------------------------------*/
/*  NES resources                                                    */
/*-------------------------------------------------------------------*/

/* RAM */
BYTE RAM[ RAM_SIZE ];

/* SRAM */
BYTE SRAM[ SRAM_SIZE ];

/* ROM */
BYTE *ROM;

/* SRAM BANK ( 8Kb ) */
BYTE *SRAMBANK;

/* ROM BANK ( 8Kb * 4 ) */
BYTE *ROMBANK0;
BYTE *ROMBANK1;
BYTE *ROMBANK2;
BYTE *ROMBANK3;

/*-------------------------------------------------------------------*/
/*  PPU resources                                                    */
/*-------------------------------------------------------------------*/

/* PPU RAM */
BYTE PPURAM[ PPURAM_SIZE ];

/* VROM */
BYTE *VROM;

/* PPU BANK ( 1Kb * 16 ) */
BYTE *PPUBANK[ 16 ];

/* Sprite RAM */
BYTE SPRRAM[ SPRRAM_SIZE ];

/* PPU Register */
BYTE PPU_R0;
BYTE PPU_R1;
BYTE PPU_R2;
BYTE PPU_R3;
BYTE PPU_R7;

/* Vertical scroll value */
BYTE PPU_Scr_V;
BYTE PPU_Scr_V_Next;
BYTE PPU_Scr_V_Byte;
BYTE PPU_Scr_V_Byte_Next;
BYTE PPU_Scr_V_Bit;
BYTE PPU_Scr_V_Bit_Next;

/* Horizontal scroll value */
BYTE PPU_Scr_H;
BYTE PPU_Scr_H_Next;
BYTE PPU_Scr_H_Byte;
BYTE PPU_Scr_H_Byte_Next;
BYTE PPU_Scr_H_Bit;
BYTE PPU_Scr_H_Bit_Next;

/* PPU Address */
WORD PPU_Addr;

/* PPU Address */
WORD PPU_Temp;

/* The increase value of the PPU Address */
WORD PPU_Increment;

/* Current Scanline */
WORD PPU_Scanline = 0;

/* Scanline Table */
BYTE PPU_ScanTable[ 263 ];

/* Name Table Bank */
BYTE PPU_NameTableBank;

/* BG Base Address */
WORD *PPU_BG_Base;

/* Sprite Base Address */
WORD *PPU_SP_Base;

/* Sprite Height */
WORD PPU_SP_Height;

/* Sprite #0 Scanline Hit Position */
int SpriteJustHit;

/* VRAM Write Enable ( 0: Disable, 1: Enable ) */
BYTE byVramWriteEnable;

/* PPU Address and Scroll Latch Flag*/
BYTE PPU_Latch_Flag;

/* Up and Down Clipping Flag ( 0: non-clip, 1: clip ) */ 
BYTE PPU_UpDown_Clip;

/* Frame IRQ ( 0: Disabled, 1: Enabled )*/
BYTE FrameIRQ_Enable;
WORD FrameStep;

/*-------------------------------------------------------------------*/
/*  Display and Others resouces                                      */
/*-------------------------------------------------------------------*/

/* Frame Skip */
WORD FrameSkip;
WORD FrameCnt;

/* Display Buffer */
#if 0
WORD DoubleFrame[ 2 ][ NES_DISP_WIDTH * NES_DISP_HEIGHT ];
WORD *WorkFrame;
WORD WorkFrameIdx;
#else
WORD WorkFrame[ (long)NES_DISP_WIDTH * NES_DISP_HEIGHT ];
#endif

/* Character Buffer */
WORD ChrBuf[ (long)256 * 2 * 1 * 8 ];

/* Update flag for ChrBuf */
BYTE ChrBufUpdate;

/* Palette Table */
WORD PalTable[ 32 ];

/* Table for Mirroring */
BYTE PPU_MirrorTable[][ 4 ] =
{
  { NAME_TABLE0, NAME_TABLE0, NAME_TABLE1, NAME_TABLE1 },
  { NAME_TABLE0, NAME_TABLE1, NAME_TABLE0, NAME_TABLE1 },
  { NAME_TABLE1, NAME_TABLE1, NAME_TABLE1, NAME_TABLE1 },
  { NAME_TABLE0, NAME_TABLE0, NAME_TABLE0, NAME_TABLE0 },
  { NAME_TABLE0, NAME_TABLE1, NAME_TABLE2, NAME_TABLE3 },
  { NAME_TABLE0, NAME_TABLE0, NAME_TABLE0, NAME_TABLE1 }
};

/*-------------------------------------------------------------------*/
/*  APU and Pad resources                                            */
/*-------------------------------------------------------------------*/

/* APU Register */
BYTE APU_Reg[ 0x18 ];

/* APU Mute ( 0:OFF, 1:ON ) */
int APU_Mute = 0;

/* Pad data */
DWORD PAD1_Latch;
DWORD PAD2_Latch;
DWORD PAD_System;
DWORD PAD1_Bit;
DWORD PAD2_Bit;

/*-------------------------------------------------------------------*/
/*  Mapper Function                                                  */
/*-------------------------------------------------------------------*/

/* Initialize Mapper */
void (*MapperInit)();
/* Write to Mapper */
void (*MapperWrite)( WORD wAddr, BYTE byData );
/* Write to SRAM */
void (*MapperSram)( WORD wAddr, BYTE byData );
/* Write to Apu */
void (*MapperApu)( WORD wAddr, BYTE byData );
/* Read from Apu */
BYTE (*MapperReadApu)( WORD wAddr );
/* Callback at VSync */
void (*MapperVSync)();
/* Callback at HSync */
void (*MapperHSync)();
/* Callback at PPU read/write */
void (*MapperPPU)( WORD wAddr );
/* Callback at Rendering Screen 1:BG, 0:Sprite */
void (*MapperRenderScreen)( BYTE byMode );

/*-------------------------------------------------------------------*/
/*  ROM information                                                  */
/*-------------------------------------------------------------------*/

/* .nes File Header */
struct NesHeader_tag NesHeader;

/* Mapper Number */
BYTE MapperNo;

/* Mirroring 0:Horizontal 1:Vertical */
BYTE ROM_Mirroring;
/* It has SRAM */
BYTE ROM_SRAM;
/* It has Trainer */
BYTE ROM_Trainer;
/* Four screen VRAM  */
BYTE ROM_FourScr;

/*===================================================================*/
/*                                                                   */
/*                InfoNES_Init() : Initialize InfoNES                */
/*                                                                   */
/*===================================================================*/
void InfoNES_Init()
{
/*
 *  Initialize InfoNES
 *
 *  Remarks
 *    Initialize K6502 and Scanline Table.
 */
  int nIdx;

  // Initialize 6502
  K6502_Init();

  // Initialize Scanline Table
  for ( nIdx = 0; nIdx < 263; ++nIdx )
  {
    if ( nIdx < SCAN_ON_SCREEN_START )
      PPU_ScanTable[ nIdx ] = SCAN_ON_SCREEN;
    else
    if ( nIdx < SCAN_BOTTOM_OFF_SCREEN_START )
      PPU_ScanTable[ nIdx ] = SCAN_ON_SCREEN;
    else
    if ( nIdx < SCAN_UNKNOWN_START )
      PPU_ScanTable[ nIdx ] = SCAN_ON_SCREEN;
    else
    if ( nIdx < SCAN_VBLANK_START )
      PPU_ScanTable[ nIdx ] = SCAN_UNKNOWN;
    else
      PPU_ScanTable[ nIdx ] = SCAN_VBLANK;
  }
}

/*===================================================================*/
/*                                                                   */
/*                InfoNES_Fin() : Completion treatment               */
/*                                                                   */
/*===================================================================*/
void InfoNES_Fin()
{
/*
 *  Completion treatment
 *
 *  Remarks
 *    Release resources
 */
  // Finalize pAPU
  InfoNES_pAPUDone();

  // Release a memory for ROM
  InfoNES_ReleaseRom();
}

/*===================================================================*/
/*                                                                   */
/*                  InfoNES_Load() : Load a cassette                 */
/*                                                                   */
/*===================================================================*/
int InfoNES_Load( const char *pszFileName )
{
/*
 *  Load a cassette
 *
 *  Parameters
 *    const char *pszFileName            (Read)
 *      File name of ROM image
 *
 *  Return values
 *     0 : It was finished normally.
 *    -1 : An error occurred.
 *
 *  Remarks
 *    Read a ROM image in the memory. 
 *    Reset InfoNES.
 */

  // Release a memory for ROM
  InfoNES_ReleaseRom();

  // Read a ROM image in the memory
  if ( InfoNES_ReadRom( pszFileName ) < 0 )
    return -1;

  // Reset InfoNES
  if ( InfoNES_Reset() < 0 )
    return -1;

  // Successful
  return 0;
}

/*===================================================================*/
/*                                                                   */
/*                 InfoNES_Reset() : Reset InfoNES                   */
/*                                                                   */
/*===================================================================*/
int InfoNES_Reset()
{
/*
 *  Reset InfoNES
 *
 *  Return values
 *     0 : Normally
 *    -1 : Non support mapper
 *
 *  Remarks
 *    Initialize Resources, PPU and Mapper.
 *    Reset CPU.
 */

  int nIdx;

  /*-------------------------------------------------------------------*/
  /*  Get information on the cassette                                  */
  /*-------------------------------------------------------------------*/

  // Get Mapper Number
  MapperNo = NesHeader.byInfo1 >> 4;

  // Check bit counts of Mapper No.
  for ( nIdx = 4; nIdx < 8 && NesHeader.byReserve[ nIdx ] == 0; ++nIdx )
    ;

  if ( nIdx == 8 )
  {
    // Mapper Number is 8bits
    MapperNo |= ( NesHeader.byInfo2 & 0xf0 );
  }

  // Get information on the ROM
  ROM_Mirroring = NesHeader.byInfo1 & 1;
  ROM_SRAM = NesHeader.byInfo1 & 2;
  ROM_Trainer = NesHeader.byInfo1 & 4;
  ROM_FourScr = NesHeader.byInfo1 & 8;

  /*-------------------------------------------------------------------*/
  /*  Initialize resources                                             */
  /*-------------------------------------------------------------------*/

  // Clear RAM
  InfoNES_MemorySet( RAM, 0, sizeof RAM );

  // Reset frame skip and frame count
  FrameSkip = 0;
  FrameCnt = 0;

#if 0
  // Reset work frame
  WorkFrame = DoubleFrame[ 0 ];
  WorkFrameIdx = 0;
#endif

  // Reset update flag of ChrBuf
  ChrBufUpdate = 0xff;

  // Reset palette table
  InfoNES_MemorySet( PalTable, 0, sizeof PalTable );

  // Reset APU register
  InfoNES_MemorySet( APU_Reg, 0, sizeof APU_Reg );

  // Reset joypad
  PAD1_Latch = PAD2_Latch = PAD_System = 0;
  PAD1_Bit = PAD2_Bit = 0;

  /*-------------------------------------------------------------------*/
  /*  Initialize PPU                                                   */
  /*-------------------------------------------------------------------*/

  InfoNES_SetupPPU();

  /*-------------------------------------------------------------------*/
  /*  Initialize pAPU                                                  */
  /*-------------------------------------------------------------------*/

  InfoNES_pAPUInit();

  /*-------------------------------------------------------------------*/
  /*  Initialize Mapper                                                */
  /*-------------------------------------------------------------------*/

  // Get Mapper Table Index
  for ( nIdx = 0; MapperTable[ nIdx ].nMapperNo != -1; ++nIdx )
  {
    if ( MapperTable[ nIdx ].nMapperNo == MapperNo )
      break;
  }

  if ( MapperTable[ nIdx ].nMapperNo == -1 )
  {
    // Non support mapper
    InfoNES_MessageBox( "Mapper #%d is unsupported.\n", MapperNo );
    return -1;
  }

  // Set up a mapper initialization function
  MapperTable[ nIdx ].pMapperInit();

  /*-------------------------------------------------------------------*/
  /*  Reset CPU                                                        */
  /*-------------------------------------------------------------------*/

  K6502_Reset();

  // Successful
  return 0;
}

/*===================================================================*/
/*                                                                   */
/*                InfoNES_SetupPPU() : Initialize PPU                */
/*                                                                   */
/*===================================================================*/
void InfoNES_SetupPPU()
{
/*
 *  Initialize PPU
 *
 */
  int nPage;

  // Clear PPU and Sprite Memory
  InfoNES_MemorySet( PPURAM, 0, sizeof PPURAM );
  InfoNES_MemorySet( SPRRAM, 0, sizeof SPRRAM );

  // Reset PPU Register
  PPU_R0 = PPU_R1 = PPU_R2 = PPU_R3 = PPU_R7 = 0;

  // Reset latch flag
  PPU_Latch_Flag = 0;

  // Reset up and down clipping flag
  PPU_UpDown_Clip = 0;

  FrameStep = 0;
  FrameIRQ_Enable = 0;

  // Reset Scroll values
  PPU_Scr_V = PPU_Scr_V_Next = PPU_Scr_V_Byte = PPU_Scr_V_Byte_Next = PPU_Scr_V_Bit = PPU_Scr_V_Bit_Next = 0;
  PPU_Scr_H = PPU_Scr_H_Next = PPU_Scr_H_Byte = PPU_Scr_H_Byte_Next = PPU_Scr_H_Bit = PPU_Scr_H_Bit_Next = 0;

  // Reset PPU address
  PPU_Addr = 0;
  PPU_Temp = 0;

  // Reset scanline
  PPU_Scanline = 0;

  // Reset hit position of sprite #0 
  SpriteJustHit = 0;

  // Reset information on PPU_R0
  PPU_Increment = 1;
  PPU_NameTableBank = NAME_TABLE0;
  PPU_BG_Base = ChrBuf;
  PPU_SP_Base = ChrBuf + 256 * 8;
  PPU_SP_Height = 8;

  // Reset PPU banks
  for ( nPage = 0; nPage < 16; ++nPage )
    PPUBANK[ nPage ] = &PPURAM[ nPage * 0x400 ];

  /* Mirroring of Name Table */
  InfoNES_Mirroring( ROM_Mirroring );

  /* Reset VRAM Write Enable */
  byVramWriteEnable = ( NesHeader.byVRomSize == 0 ) ? 1 : 0;
}

/*===================================================================*/
/*                                                                   */
/*       InfoNES_Mirroring() : Set up a Mirroring of Name Table      */
/*                                                                   */
/*===================================================================*/
void InfoNES_Mirroring( int nType )
{
/*
 *  Set up a Mirroring of Name Table
 *
 *  Parameters
 *    int nType          (Read)
 *      Mirroring Type
 *        0 : Horizontal
 *        1 : Vertical
 *        2 : One Screen 0x2400
 *        3 : One Screen 0x2000
 *        4 : Four Screen
 *        5 : Special for Mapper #233
 */

  PPUBANK[ NAME_TABLE0 ] = &PPURAM[ PPU_MirrorTable[ nType ][ 0 ] * 0x400 ];
  PPUBANK[ NAME_TABLE1 ] = &PPURAM[ PPU_MirrorTable[ nType ][ 1 ] * 0x400 ];
  PPUBANK[ NAME_TABLE2 ] = &PPURAM[ PPU_MirrorTable[ nType ][ 2 ] * 0x400 ];
  PPUBANK[ NAME_TABLE3 ] = &PPURAM[ PPU_MirrorTable[ nType ][ 3 ] * 0x400 ];
}

/*===================================================================*/
/*                                                                   */
/*              InfoNES_Main() : The main loop of InfoNES            */
/*                                                                   */
/*===================================================================*/
void InfoNES_Main()
{
/*
 *  The main loop of InfoNES
 *
 */

  // Initialize InfoNES
  InfoNES_Init();
  
  // Main loop
  while ( 1 )
  {
    /*-------------------------------------------------------------------*/
    /*  To the menu screen                                               */
    /*-------------------------------------------------------------------*/
    if ( InfoNES_Menu() == -1 )
      break;  // Quit

    /*-------------------------------------------------------------------*/
    /*  Start a NES emulation                                            */
    /*-------------------------------------------------------------------*/
    InfoNES_Cycle();
  }

  // Completion treatment
  InfoNES_Fin();
}

/*===================================================================*/
/*                                                                   */
/*              InfoNES_Cycle() : The loop of emulation              */
/*                                                                   */
/*===================================================================*/
void InfoNES_Cycle()
{
/*
 *  The loop of emulation
 *
 */

  // Set the PPU adress to the buffered value
  if ( ( PPU_R1 & R1_SHOW_SP ) || ( PPU_R1 & R1_SHOW_SCR ) )
		PPU_Addr = PPU_Temp;
 
  // Emulation loop
  for (;;)
  {    
    int nStep;

    // Set a flag if a scanning line is a hit in the sprite #0
    if ( SpriteJustHit == PPU_Scanline &&
      PPU_ScanTable[ PPU_Scanline ] == SCAN_ON_SCREEN )
    {
      // # of Steps to execute before sprite #0 hit
      nStep = (long)SPRRAM[ SPR_X ] * STEP_PER_SCANLINE / NES_DISP_WIDTH;

      // Execute instructions
      K6502_Step( nStep );

      // Set a sprite hit flag
      if ( ( PPU_R1 & R1_SHOW_SP ) && ( PPU_R1 & R1_SHOW_SCR ) )
        PPU_R2 |= R2_HIT_SP;

      // NMI is required if there is necessity
      if ( ( PPU_R0 & R0_NMI_SP ) && ( PPU_R1 & R1_SHOW_SP ) )
        NMI_REQ;

      // Execute instructions
      K6502_Step(STEP_PER_SCANLINE - nStep);
    }
    else
    {
      // Execute instructions
      K6502_Step( STEP_PER_SCANLINE );
    }

    // Frame IRQ in H-Sync
    FrameStep += STEP_PER_SCANLINE;
    if ( FrameStep > STEP_PER_FRAME && FrameIRQ_Enable )
    {
      FrameStep %= STEP_PER_FRAME;
      IRQ_REQ;
      APU_Reg[ 0x4015 ] |= 0x40;
    }

    // A mapper function in H-Sync
    MapperHSync();
    
    // A function in H-Sync
    if ( InfoNES_HSync() == -1 )
      return;  // To the menu screen

    // HSYNC Wait
    //InfoNES_Wait();
  }
}

/*===================================================================*/
/*                                                                   */
/*              InfoNES_HSync() : A function in H-Sync               */
/*                                                                   */
/*===================================================================*/
int InfoNES_HSync()
{

/*
 *  A function in H-Sync
 *
 *  Return values
 *    0 : Normally
 *   -1 : Exit an emulation
 */

    static BYTE LastSec = 0;
    static WORD LineCount = 0;
    static WORD UpdateDelay = 0;
    static BYTE frame = 0;

    ++LineCount;
    if (++UpdateDelay == (WORD)50) {
        UpdateDelay = 0;
        if (DS1302_RD_REG(DS1302_SEC) != LastSec) {
            LastSec = DS1302_RD_REG(DS1302_SEC);
            Printf_Set(0, 0, 0xffff, 0);
            printf("FPS:\n%.1f ", LineCount / 263.0);
            LineCount = 0;
        }
    }

  /*-------------------------------------------------------------------*/
  /*  Render a scanline                                                */
  /*-------------------------------------------------------------------*/
  if ( FrameCnt == 0 &&
       PPU_ScanTable[ PPU_Scanline ] == SCAN_ON_SCREEN )
  {
      //if (PPU_Scanline == (WORD)0)
      //    ++frame;
      //if(((frame & (BYTE)0x01) == (BYTE)0 && (PPU_Scanline & (BYTE)0x01) == (BYTE)0) || ((frame & (BYTE)0x01) == (BYTE)1 && (PPU_Scanline & (BYTE)0x01) == (BYTE)1))
        InfoNES_DrawLine();
  }

  /*-------------------------------------------------------------------*/
  /*  Set new scroll values                                            */
  /*-------------------------------------------------------------------*/
  PPU_Scr_V      = PPU_Scr_V_Next;
  PPU_Scr_V_Byte = PPU_Scr_V_Byte_Next;
  PPU_Scr_V_Bit  = PPU_Scr_V_Bit_Next;

  PPU_Scr_H      = PPU_Scr_H_Next;
  PPU_Scr_H_Byte = PPU_Scr_H_Byte_Next;
  PPU_Scr_H_Bit  = PPU_Scr_H_Bit_Next;

  /*-------------------------------------------------------------------*/
  /*  Next Scanline                                                    */
  /*-------------------------------------------------------------------*/
  PPU_Scanline = ( PPU_Scanline == SCAN_VBLANK_END ) ? 0 : PPU_Scanline + 1;

  /*-------------------------------------------------------------------*/
  /*  Operation in the specific scanning line                          */
  /*-------------------------------------------------------------------*/
  switch ( PPU_Scanline )
  {
    case SCAN_TOP_OFF_SCREEN:
      // Reset a PPU status
      PPU_R2 = 0;

      // Set up a character data
      if ( NesHeader.byVRomSize == 0 && FrameCnt == 0 )
        InfoNES_SetupChr();

      // Get position of sprite #0
      InfoNES_GetSprHitY();
      break;

    case SCAN_UNKNOWN_START:
      if ( FrameCnt == 0 )
      {
        // Transfer the contents of work frame on the screen
        //InfoNES_LoadFrame();
        
#if 0
        // Switching of the double buffer
        WorkFrameIdx = 1 - WorkFrameIdx;
        WorkFrame = DoubleFrame[ WorkFrameIdx ];
#endif
      }
      break;

    case SCAN_VBLANK_START:
      // FrameCnt + 1
      FrameCnt = ( FrameCnt >= FrameSkip ) ? 0 : FrameCnt + 1;

      // Set a V-Blank flag
      PPU_R2 = R2_IN_VBLANK;

      // Reset latch flag
      PPU_Latch_Flag = 0;

      // pAPU Sound function in V-Sync
      //if ( !APU_Mute )
      //  InfoNES_pAPUVsync();

      // A mapper function in V-Sync
      MapperVSync();

      // Get the condition of the joypad
      InfoNES_PadState( &PAD1_Latch, &PAD2_Latch, &PAD_System );
      
      // NMI on V-Blank
      if ( PPU_R0 & R0_NMI_VB )
        NMI_REQ;

      // Exit an emulation if a QUIT button is pushed
      if ( PAD_PUSH( PAD_System, PAD_SYS_QUIT ) )
        return -1;  // Exit an emulation      
      
      break;
  }

  // Successful
  return 0;
}

/*===================================================================*/
/*                                                                   */
/*              InfoNES_DrawLine() : Render a scanline               */
/*                                                                   */
/*===================================================================*/

BYTE nX = 0;
BYTE nY = 0;
BYTE nY4 = 0;
BYTE nYBit = 0;
WORD* pPalTbl = 0;
BYTE* pAttrBase_0 = 0;
BYTE* pAttrBase_1 = 0;
BYTE nNameTable = 0;
BYTE* pbyNameTable = 0;
BYTE* pbyNameTable_0 = 0;
BYTE* pbyNameTable_1 = 0;
BYTE* pSPRRAM = 0;
BYTE nAttr = 0;
BYTE nSprCnt = 0;
BYTE bySprCol = 0;
WORD* PPU_BG_Base_Add_nYBit = 0;
WORD* pPalTbl_buf_0[32];
WORD* pPalTbl_buf_1[32];
BYTE nY_0 = 255;
BYTE nNameTable_0 = 255;
WORD byChrData = 0;
WORD pd = 0;
WORD SP_nX = 0;
unsigned long long llpd = 0;
BYTE nX_0 = 255;
BYTE SP_Scanline_count[NES_DISP_HEIGHT];

void InfoNES_DrawLine()
{
    /*
     *  Render a scanline
     *
     */

     /*-------------------------------------------------------------------*/
     /*  Render Background                                                */
     /*-------------------------------------------------------------------*/

     /* MMC5 VROM switch */
     //MapperRenderScreen( 1 );

     // Pointer to the render position

    // Clear a scanline if screen is off
    if (!(PPU_R1 & R1_SHOW_SCR))
    {
        Lcd_Fill_Rectangle(32, PPU_Scanline, NES_DISP_WIDTH, 1, 0);
    }
    else
    {
        Lcd_SetRegion(32, 32 + 256 - 1, PPU_Scanline, 239);
        Lcd_WriteIndex(0x2c);

        nNameTable = PPU_NameTableBank;

        nY = PPU_Scr_V_Byte + (PPU_Scanline >> 3);

        nYBit = PPU_Scr_V_Bit + (PPU_Scanline & 7);

        if (nYBit > (BYTE)7)
        {
            ++nY;
            nYBit &= (BYTE)7;
        }
        PPU_BG_Base_Add_nYBit = PPU_BG_Base + nYBit;

        if (nY > (BYTE)29)
        {
            // Next NameTable (An up-down direction)
            nNameTable ^= NAME_TABLE_V_MASK;
            nY -= (BYTE)30;
        }

        nX = PPU_Scr_H_Byte;

        if (nNameTable != nNameTable_0) {
            nY_0 = ~nY;
            nNameTable_0 = nNameTable;
        }

        /*-------------------------------------------------------------------*/
        /*  Rendering of the block of the left end                           */
        /*-------------------------------------------------------------------*/

        if (nY != nY_0) {
            nY4 = ((nY & (BYTE)2) << 1);
            pbyNameTable_0 = PPUBANK[nNameTable] + (WORD)nY * (WORD)32 + nX;
            pAttrBase_0 = PPUBANK[nNameTable] + (WORD)0x3c0 + (nY / (BYTE)4) * (WORD)8;
            *((WORD**)((BYTE*)pPalTbl_buf_0 + (nX << 2))) = (WORD*)((BYTE*)PalTable + (((pAttrBase_0[nX >> 2] >> ((nX & (BYTE)2) + nY4)) & (BYTE)3) << 3));
        }
        pbyNameTable = pbyNameTable_0;

        byChrData = *((WORD*)((BYTE*)PPU_BG_Base_Add_nYBit + ((WORD)*pbyNameTable << 4)));
        pPalTbl = *((WORD**)((BYTE*)pPalTbl_buf_0 + (nX << 2)));

        if ((PPU_Scr_H_Bit & (BYTE)0x4) == (BYTE)0x4) {
            if ((PPU_Scr_H_Bit & (BYTE)0x2) == (BYTE)0x2) {
                if ((PPU_Scr_H_Bit & (BYTE)1) == (BYTE)1) {
                    //0x7
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] << 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                }
                else {
                    //0x6
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] >> 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] << 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                }
            }
            else {
                if ((PPU_Scr_H_Bit & (BYTE)1) == (BYTE)1) {
                    //0x5
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] >> 3) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] >> 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] << 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                }
                else {
                    //0x4
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] >> 5) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] >> 3) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] >> 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] << 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                }
            }
        }
        else {
            if ((PPU_Scr_H_Bit & (BYTE)0x2) == (BYTE)0x2) {
                if ((PPU_Scr_H_Bit & (BYTE)1) == (BYTE)1) {
                    //0x3
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] << 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] >> 5) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] >> 3) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] >> 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] << 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                }
                else {
                    //0x2
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] >> 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] << 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] >> 5) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] >> 3) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] >> 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] << 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                }
            }
            else {
                if ((PPU_Scr_H_Bit & (BYTE)1) == (BYTE)1) {
                    //0x1
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] >> 3) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] >> 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] << 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] >> 5) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] >> 3) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] >> 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] << 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                }
                else {
                    //0x0
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] >> 5) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] >> 3) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] >> 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] << 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] >> 5) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] >> 3) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] >> 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] << 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                }
            }
        }

        // Callback at PPU read/write
        //MapperPPU( PATTBL( pbyChrData ) );

        ++nX;
        ++pbyNameTable;

        /*-------------------------------------------------------------------*/
        /*  Rendering of the left table                                      */
        /*-------------------------------------------------------------------*/

        nX_0 = 255;
        for (; nX < (BYTE)32; ++nX)
        {
            if (nY != nY_0) { //1.375
                *((WORD**)((BYTE*)pPalTbl_buf_0 + (nX << 2))) = (WORD*)((BYTE*)PalTable + (((pAttrBase_0[nX >> 2] >> ((nX & (BYTE)2) + nY4)) & (BYTE)3) << 3));
            }
            if ((nX >> 1) != nX_0) { //1.625
                llpd = **((unsigned long long**)((BYTE*)pPalTbl_buf_0 + (nX << 2))); //11.8125
                nX_0 = nX >> 1;
            }
            byChrData = *((WORD*)((BYTE*)PPU_BG_Base_Add_nYBit + ((WORD)*pbyNameTable++ << 4))); //14.125

            if ((((BYTE*)&byChrData)[1] & (BYTE)0x80) == (BYTE)0x80) { //11
                if ((((BYTE*)&byChrData)[1] & (BYTE)0x40) == (BYTE)0x40) { //11
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[3]); //110
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[2]);
                }
            }
            else {
                if ((((BYTE*)&byChrData)[1] & (BYTE)0x40) == (BYTE)0x40) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[1]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[0]);
                }
            }

            if ((((BYTE*)&byChrData)[1] & (BYTE)0x20) == (BYTE)0x20) {
                if ((((BYTE*)&byChrData)[1] & (BYTE)0x10) == (BYTE)0x10) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[3]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[2]);
                }
            }
            else {
                if ((((BYTE*)&byChrData)[1] & (BYTE)0x10) == (BYTE)0x10) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[1]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[0]);
                }
            }

            if ((((BYTE*)&byChrData)[1] & (BYTE)0x08) == (BYTE)0x08) {
                if ((((BYTE*)&byChrData)[1] & (BYTE)0x04) == (BYTE)0x04) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[3]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[2]);
                }
            }
            else {
                if ((((BYTE*)&byChrData)[1] & (BYTE)0x04) == (BYTE)0x04) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[1]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[0]);
                }
            }

            if ((((BYTE*)&byChrData)[1] & (BYTE)0x02) == (BYTE)0x02) {
                if ((((BYTE*)&byChrData)[1] & (BYTE)0x01) == (BYTE)0x01) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[3]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[2]);
                }
            }
            else {
                if ((((BYTE*)&byChrData)[1] & (BYTE)0x01) == (BYTE)0x01) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[1]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[0]);
                }
            }

            if ((((BYTE*)&byChrData)[0] & (BYTE)0x80) == (BYTE)0x80) {
                if ((((BYTE*)&byChrData)[0] & (BYTE)0x40) == (BYTE)0x40) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[3]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[2]);
                }
            }
            else {
                if ((((BYTE*)&byChrData)[0] & (BYTE)0x40) == (BYTE)0x40) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[1]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[0]);
                }
            }

            if ((((BYTE*)&byChrData)[0] & (BYTE)0x20) == (BYTE)0x20) {
                if ((((BYTE*)&byChrData)[0] & (BYTE)0x10) == (BYTE)0x10) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[3]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[2]);
                }
            }
            else {
                if ((((BYTE*)&byChrData)[0] & (BYTE)0x10) == (BYTE)0x10) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[1]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[0]);
                }
            }

            if ((((BYTE*)&byChrData)[0] & (BYTE)0x08) == (BYTE)0x08) {
                if ((((BYTE*)&byChrData)[0] & (BYTE)0x04) == (BYTE)0x04) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[3]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[2]);
                }
            }
            else {
                if ((((BYTE*)&byChrData)[0] & (BYTE)0x04) == (BYTE)0x04) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[1]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[0]);
                }
            }

            if ((((BYTE*)&byChrData)[0] & (BYTE)0x02) == (BYTE)0x02) {
                if ((((BYTE*)&byChrData)[0] & (BYTE)0x01) == (BYTE)0x01) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[3]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[2]);
                }
            }
            else {
                if ((((BYTE*)&byChrData)[0] & (BYTE)0x01) == (BYTE)0x01) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[1]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[0]);
                }
            }

            // Callback at PPU read/write
            //MapperPPU( PATTBL( pbyChrData ) );
        }

        // Holizontal Mirror
        nNameTable ^= NAME_TABLE_H_MASK;

        if (nY != nY_0) {
            pbyNameTable_1 = PPUBANK[nNameTable] + (WORD)nY * (WORD)32;
            pAttrBase_1 = PPUBANK[nNameTable] + (WORD)0x3c0 + (nY / (BYTE)4) * (WORD)8;
        }
        pbyNameTable = pbyNameTable_1;

        /*-------------------------------------------------------------------*/
        /*  Rendering of the right table                                     */
        /*-------------------------------------------------------------------*/

        for (nX = 0; nX < PPU_Scr_H_Byte; ++nX)
        {
            if (nY != nY_0) {
                *((WORD**)((BYTE*)pPalTbl_buf_1 + (nX << 2))) = (WORD*)((BYTE*)PalTable + (((pAttrBase_1[nX >> 2] >> ((nX & (BYTE)2) + nY4)) & (BYTE)3) << 3));
            }
            if ((nX >> 1) != nX_0) {
                llpd = **((unsigned long long**)((BYTE*)pPalTbl_buf_1 + (nX << 2)));
                nX_0 = nX >> 1;
            }
            byChrData = *((WORD*)((BYTE*)PPU_BG_Base_Add_nYBit + ((WORD)*pbyNameTable++ << 4)));

            if ((((BYTE*)&byChrData)[1] & (BYTE)0x80) == (BYTE)0x80) {
                if ((((BYTE*)&byChrData)[1] & (BYTE)0x40) == (BYTE)0x40) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[3]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[2]);
                }
            }
            else {
                if ((((BYTE*)&byChrData)[1] & (BYTE)0x40) == (BYTE)0x40) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[1]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[0]);
                }
            }

            if ((((BYTE*)&byChrData)[1] & (BYTE)0x20) == (BYTE)0x20) {
                if ((((BYTE*)&byChrData)[1] & (BYTE)0x10) == (BYTE)0x10) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[3]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[2]);
                }
            }
            else {
                if ((((BYTE*)&byChrData)[1] & (BYTE)0x10) == (BYTE)0x10) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[1]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[0]);
                }
            }

            if ((((BYTE*)&byChrData)[1] & (BYTE)0x08) == (BYTE)0x08) {
                if ((((BYTE*)&byChrData)[1] & (BYTE)0x04) == (BYTE)0x04) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[3]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[2]);
                }
            }
            else {
                if ((((BYTE*)&byChrData)[1] & (BYTE)0x04) == (BYTE)0x04) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[1]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[0]);
                }
            }

            if ((((BYTE*)&byChrData)[1] & (BYTE)0x02) == (BYTE)0x02) {
                if ((((BYTE*)&byChrData)[1] & (BYTE)0x01) == (BYTE)0x01) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[3]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[2]);
                }
            }
            else {
                if ((((BYTE*)&byChrData)[1] & (BYTE)0x01) == (BYTE)0x01) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[1]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[0]);
                }
            }

            if ((((BYTE*)&byChrData)[0] & (BYTE)0x80) == (BYTE)0x80) {
                if ((((BYTE*)&byChrData)[0] & (BYTE)0x40) == (BYTE)0x40) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[3]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[2]);
                }
            }
            else {
                if ((((BYTE*)&byChrData)[0] & (BYTE)0x40) == (BYTE)0x40) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[1]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[0]);
                }
            }

            if ((((BYTE*)&byChrData)[0] & (BYTE)0x20) == (BYTE)0x20) {
                if ((((BYTE*)&byChrData)[0] & (BYTE)0x10) == (BYTE)0x10) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[3]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[2]);
                }
            }
            else {
                if ((((BYTE*)&byChrData)[0] & (BYTE)0x10) == (BYTE)0x10) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[1]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[0]);
                }
            }

            if ((((BYTE*)&byChrData)[0] & (BYTE)0x08) == (BYTE)0x08) {
                if ((((BYTE*)&byChrData)[0] & (BYTE)0x04) == (BYTE)0x04) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[3]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[2]);
                }
            }
            else {
                if ((((BYTE*)&byChrData)[0] & (BYTE)0x04) == (BYTE)0x04) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[1]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[0]);
                }
            }

            if ((((BYTE*)&byChrData)[0] & (BYTE)0x02) == (BYTE)0x02) {
                if ((((BYTE*)&byChrData)[0] & (BYTE)0x01) == (BYTE)0x01) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[3]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[2]);
                }
            }
            else {
                if ((((BYTE*)&byChrData)[0] & (BYTE)0x01) == (BYTE)0x01) {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[1]);
                }
                else {
                    Lcd_WriteData_16Bit_V(((WORD*)&llpd)[0]);
                }
            }

            // Callback at PPU read/write
            //MapperPPU( PATTBL( pbyChrData ) );

            //++pbyNameTable;
        }

        /*-------------------------------------------------------------------*/
        /*  Rendering of the block of the right end                          */
        /*-------------------------------------------------------------------*/

        byChrData = *((WORD*)((BYTE*)PPU_BG_Base_Add_nYBit + ((WORD)*pbyNameTable << 4)));
        if (nY != nY_0) {
            *((WORD**)((BYTE*)pPalTbl_buf_1 + (nX << 2))) = (WORD*)((BYTE*)PalTable + (((pAttrBase_1[nX >> 2] >> ((nX & (BYTE)2) + nY4)) & (BYTE)3) << 3));
            nY_0 = nY;
        }
        pPalTbl = *((WORD**)((BYTE*)pPalTbl_buf_1 + (nX << 2)));

        if ((PPU_Scr_H_Bit & (BYTE)0x4) == (BYTE)0x4) {
            if ((PPU_Scr_H_Bit & (BYTE)0x2) == (BYTE)0x2) {
                if ((PPU_Scr_H_Bit & (BYTE)1) == (BYTE)1) {
                    //0x7
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] >> 5) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] >> 3) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] >> 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] << 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] >> 5) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] >> 3) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] >> 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                }
                else {
                    //0x6
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] >> 5) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] >> 3) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] >> 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] << 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] >> 5) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] >> 3) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                }
            }
            else {
                if ((PPU_Scr_H_Bit & (BYTE)1) == (BYTE)1) {
                    //0x5
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] >> 5) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] >> 3) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] >> 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] << 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[0] >> 5) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                }
                else {
                    //0x4
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] >> 5) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] >> 3) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] >> 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] << 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                }
            }
        }
        else {
            if ((PPU_Scr_H_Bit & (BYTE)0x2) == (BYTE)0x2) {
                if ((PPU_Scr_H_Bit & (BYTE)1) == (BYTE)1) {
                    //0x3
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] >> 5) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] >> 3) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] >> 1) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                }
                else {
                    //0x2
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] >> 5) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                    pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] >> 3) & (BYTE)6)));
                    Lcd_WriteData_16Bit_V(pd);
                }
            }
            else if ((PPU_Scr_H_Bit & (BYTE)1) == (BYTE)1) {
                //0x1
                pd = *((WORD*)(((BYTE*)pPalTbl) + ((((BYTE*)&byChrData)[1] >> 5) & (BYTE)6)));
                Lcd_WriteData_16Bit_V(pd);
            }
        }

        // Callback at PPU read/write
        //MapperPPU( PATTBL( pbyChrData ) );

        /*-------------------------------------------------------------------*/
        /*  Backgroud Clipping                                               */
        /*-------------------------------------------------------------------*/
        if (!(PPU_R1 & R1_CLIP_BG))
        {
            Lcd_Set_Reg_X(32);
            Lcd_Set_Reg_Y(PPU_Scanline);
            Lcd_WriteIndex(0x2c);
            Lcd_WriteData_16Bit(0);
            Lcd_WriteData_16Bit(0);
            Lcd_WriteData_16Bit(0);
            Lcd_WriteData_16Bit(0);
            Lcd_WriteData_16Bit(0);
            Lcd_WriteData_16Bit(0);
            Lcd_WriteData_16Bit(0);
            Lcd_WriteData_16Bit(0);
        }

        /*-------------------------------------------------------------------*/
        /*  Clear a scanline if up and down clipping flag is set             */
        /*-------------------------------------------------------------------*/
        if (PPU_UpDown_Clip &&
            (SCAN_ON_SCREEN_START > PPU_Scanline || PPU_Scanline > SCAN_BOTTOM_OFF_SCREEN_START))
        {
            Lcd_Fill_Rectangle(32, PPU_Scanline, NES_DISP_WIDTH, 1, 0);
        }
    }

    /*-------------------------------------------------------------------*/
    /*  Render a sprite                                                  */
    /*-------------------------------------------------------------------*/

    /* MMC5 VROM switch */
    //MapperRenderScreen( 0 );

    if (PPU_R1 & R1_SHOW_SP)
    {
        if (PPU_Scanline == (WORD)0) {
            for (nY = 0; nY < NES_DISP_HEIGHT; ++nY) {
                SP_Scanline_count[nY] = 0;
            }
            nSprCnt = 0;
            do {
                nY = SPRRAM[nSprCnt];
                if (nY + PPU_SP_Height <= NES_DISP_HEIGHT) {
                    SP_Scanline_count[nY] = 1;
                    SP_Scanline_count[nY + 1] = 1;
                    SP_Scanline_count[nY + 2] = 1;
                    SP_Scanline_count[nY + 3] = 1;
                    SP_Scanline_count[nY + 4] = 1;
                    SP_Scanline_count[nY + 5] = 1;
                    SP_Scanline_count[nY + 6] = 1;
                    SP_Scanline_count[nY + 7] = 1;
                    if (PPU_SP_Height == (WORD)16) {
                        SP_Scanline_count[nY + 8] = 1;
                        SP_Scanline_count[nY + 9] = 1;
                        SP_Scanline_count[nY + 10] = 1;
                        SP_Scanline_count[nY + 11] = 1;
                        SP_Scanline_count[nY + 12] = 1;
                        SP_Scanline_count[nY + 13] = 1;
                        SP_Scanline_count[nY + 14] = 1;
                        SP_Scanline_count[nY + 15] = 1;
                    }
                }
                nSprCnt += (BYTE)4;
            }
            while (nSprCnt != (BYTE)0);
        }

        if (SP_Scanline_count[PPU_Scanline] != (BYTE)0) {
            // Reset Scanline Sprite Count
            PPU_R2 &= (BYTE)~R2_MAX_SP;

            // Render a sprite to the sprite buffer
            nSprCnt = 0;
            for (pSPRRAM = SPRRAM + ((BYTE)63 << 2); pSPRRAM >= SPRRAM; pSPRRAM -= 4)
            {
                nY = pSPRRAM[SPR_Y] + (BYTE)1;
                if (nY > PPU_Scanline || nY + PPU_SP_Height <= PPU_Scanline)
                    continue;  // Next sprite

                 /*-------------------------------------------------------------------*/
                 /*  A sprite in scanning line                                        */
                 /*-------------------------------------------------------------------*/

                // Holizontal Sprite Count +1
                ++nSprCnt;

                nAttr = pSPRRAM[SPR_ATTR];
                nYBit = PPU_Scanline - nY;
                if ((nAttr & SPR_ATTR_V_FLIP) == SPR_ATTR_V_FLIP)
                    nYBit = PPU_SP_Height - nYBit - (BYTE)1;

                if ((PPU_R0 & R0_SP_SIZE) == R0_SP_SIZE)
                {
                    // Sprite size 8x16
                    if (pSPRRAM[SPR_CHR] & (BYTE)1)
                    {
                        byChrData = *((WORD*)((BYTE*)ChrBuf + (((WORD)(256 * 8) + ((WORD)(pSPRRAM[SPR_CHR] & (BYTE)0xfe) << 3) + nYBit) << 1)));
                    }
                    else
                    {
                        byChrData = *((WORD*)((BYTE*)ChrBuf + ((((WORD)(pSPRRAM[SPR_CHR] & (BYTE)0xfe) << 3) + nYBit) << 1)));
                    }
                }
                else
                {
                    // Sprite size 8x8
                    byChrData = *((WORD*)((BYTE*)PPU_SP_Base + ((((WORD)pSPRRAM[SPR_CHR] << 3) + nYBit) << 1)));
                }

                nAttr ^= SPR_ATTR_PRI;
                if ((nAttr & SPR_ATTR_PRI) == SPR_ATTR_PRI) {

                    bySprCol = (nAttr & SPR_ATTR_COLOR | (BYTE)0x4) << 3;
                    ((BYTE*)&SP_nX)[1] = 0;
                    ((BYTE*)&SP_nX)[0] = pSPRRAM[SPR_X];

                    Lcd_Set_Reg_Y(PPU_Scanline);
                    if ((nAttr & SPR_ATTR_H_FLIP) == SPR_ATTR_H_FLIP)
                    {
                        // Horizontal flip
                        if ((((BYTE*)&byChrData)[0] & (BYTE)3) != (BYTE)0) {
                            Lcd_Set_Reg_X(SP_nX + (WORD)32);
                            pd = *((WORD*)(((BYTE*)PalTable) + (bySprCol | ((((BYTE*)&byChrData)[0] << 1) & (BYTE)6))));
                            Lcd_WriteIndex(0x2c);
                            Lcd_WriteData_16Bit_V(pd);
                        }
                        if (((((BYTE*)&byChrData)[0] >> 2) & (BYTE)3) != (BYTE)0) {
                            Lcd_Set_Reg_X(SP_nX + (WORD)33);
                            pd = *((WORD*)(((BYTE*)PalTable) + (bySprCol | ((((BYTE*)&byChrData)[0] >> 1) & (BYTE)6))));
                            Lcd_WriteIndex(0x2c);
                            Lcd_WriteData_16Bit_V(pd);
                        }
                        if (((((BYTE*)&byChrData)[0] >> 4) & (BYTE)3) != (BYTE)0) {
                            Lcd_Set_Reg_X(SP_nX + (WORD)34);
                            pd = *((WORD*)(((BYTE*)PalTable) + (bySprCol | ((((BYTE*)&byChrData)[0] >> 3) & (BYTE)6))));
                            Lcd_WriteIndex(0x2c);
                            Lcd_WriteData_16Bit_V(pd);
                        }
                        if (((((BYTE*)&byChrData)[0] >> 6) & (BYTE)3) != (BYTE)0) {
                            Lcd_Set_Reg_X(SP_nX + (WORD)35);
                            pd = *((WORD*)(((BYTE*)PalTable) + (bySprCol | ((((BYTE*)&byChrData)[0] >> 5) & (BYTE)6))));
                            Lcd_WriteIndex(0x2c);
                            Lcd_WriteData_16Bit_V(pd);
                        }
                        if ((((BYTE*)&byChrData)[1] & (BYTE)3) != (BYTE)0) {
                            Lcd_Set_Reg_X(SP_nX + (WORD)36);
                            pd = *((WORD*)(((BYTE*)PalTable) + (bySprCol | ((((BYTE*)&byChrData)[1] << 1) & (BYTE)6))));
                            Lcd_WriteIndex(0x2c);
                            Lcd_WriteData_16Bit_V(pd);
                        }
                        if (((((BYTE*)&byChrData)[1] >> 2) & (BYTE)3) != (BYTE)0) {
                            Lcd_Set_Reg_X(SP_nX + (WORD)37);
                            pd = *((WORD*)(((BYTE*)PalTable) + (bySprCol | ((((BYTE*)&byChrData)[1] >> 1) & (BYTE)6))));
                            Lcd_WriteIndex(0x2c);
                            Lcd_WriteData_16Bit_V(pd);
                        }
                        if (((((BYTE*)&byChrData)[1] >> 4) & (BYTE)3) != (BYTE)0) {
                            Lcd_Set_Reg_X(SP_nX + (WORD)38);
                            pd = *((WORD*)(((BYTE*)PalTable) + (bySprCol | ((((BYTE*)&byChrData)[1] >> 3) & (BYTE)6))));
                            Lcd_WriteIndex(0x2c);
                            Lcd_WriteData_16Bit_V(pd);
                        }
                        if (((((BYTE*)&byChrData)[1] >> 6) & (BYTE)3) != (BYTE)0) {
                            Lcd_Set_Reg_X(SP_nX + (WORD)39);
                            pd = *((WORD*)(((BYTE*)PalTable) + (bySprCol | ((((BYTE*)&byChrData)[1] >> 5) & (BYTE)6))));
                            Lcd_WriteIndex(0x2c);
                            Lcd_WriteData_16Bit_V(pd);
                        }
                    }
                    else
                    {
                        // Non flip
                        if (((((BYTE*)&byChrData)[1] >> 6) & (BYTE)3) != (BYTE)0) {
                            Lcd_Set_Reg_X(SP_nX + (WORD)32);
                            pd = *((WORD*)(((BYTE*)PalTable) + (bySprCol | ((((BYTE*)&byChrData)[1] >> 5) & (BYTE)6))));
                            Lcd_WriteIndex(0x2c);
                            Lcd_WriteData_16Bit_V(pd);
                        }
                        if (((((BYTE*)&byChrData)[1] >> 4) & (BYTE)3) != (BYTE)0) {
                            Lcd_Set_Reg_X(SP_nX + (WORD)33);
                            pd = *((WORD*)(((BYTE*)PalTable) + (bySprCol | ((((BYTE*)&byChrData)[1] >> 3) & (BYTE)6))));
                            Lcd_WriteIndex(0x2c);
                            Lcd_WriteData_16Bit_V(pd);
                        }
                        if (((((BYTE*)&byChrData)[1] >> 2) & (BYTE)3) != (BYTE)0) {
                            Lcd_Set_Reg_X(SP_nX + (WORD)34);
                            pd = *((WORD*)(((BYTE*)PalTable) + (bySprCol | ((((BYTE*)&byChrData)[1] >> 1) & (BYTE)6))));
                            Lcd_WriteIndex(0x2c);
                            Lcd_WriteData_16Bit_V(pd);
                        }
                        if ((((BYTE*)&byChrData)[1] & (BYTE)3) != (BYTE)0) {
                            Lcd_Set_Reg_X(SP_nX + (WORD)35);
                            pd = *((WORD*)(((BYTE*)PalTable) + (bySprCol | ((((BYTE*)&byChrData)[1] << 1) & (BYTE)6))));
                            Lcd_WriteIndex(0x2c);
                            Lcd_WriteData_16Bit_V(pd);
                        }
                        if (((((BYTE*)&byChrData)[0] >> 6) & (BYTE)3) != (BYTE)0) {
                            Lcd_Set_Reg_X(SP_nX + (WORD)36);
                            pd = *((WORD*)(((BYTE*)PalTable) + (bySprCol | ((((BYTE*)&byChrData)[0] >> 5) & (BYTE)6))));
                            Lcd_WriteIndex(0x2c);
                            Lcd_WriteData_16Bit_V(pd);
                        }
                        if (((((BYTE*)&byChrData)[0] >> 4) & (BYTE)3) != (BYTE)0) {
                            Lcd_Set_Reg_X(SP_nX + (WORD)37);
                            pd = *((WORD*)(((BYTE*)PalTable) + (bySprCol | ((((BYTE*)&byChrData)[0] >> 3) & (BYTE)6))));
                            Lcd_WriteIndex(0x2c);
                            Lcd_WriteData_16Bit_V(pd);
                        }
                        if (((((BYTE*)&byChrData)[0] >> 2) & (BYTE)3) != (BYTE)0) {
                            Lcd_Set_Reg_X(SP_nX + (WORD)38);
                            pd = *((WORD*)(((BYTE*)PalTable) + (bySprCol | ((((BYTE*)&byChrData)[0] >> 1) & (BYTE)6))));
                            Lcd_WriteIndex(0x2c);
                            Lcd_WriteData_16Bit_V(pd);
                        }
                        if ((((BYTE*)&byChrData)[0] & (BYTE)3) != (BYTE)0) {
                            Lcd_Set_Reg_X(SP_nX + (WORD)39);
                            pd = *((WORD*)(((BYTE*)PalTable) + (bySprCol | ((((BYTE*)&byChrData)[0] << 1) & (BYTE)6))));
                            Lcd_WriteIndex(0x2c);
                            Lcd_WriteData_16Bit_V(pd);
                        }
                    }
                }
            }
            Lcd_Set_Reg_X(32 + 256);
            Lcd_Set_Reg_Y(PPU_Scanline);
            Lcd_WriteIndex(0x2c);
            Lcd_WriteData_16Bit(0);
            Lcd_WriteData_16Bit(0);
            Lcd_WriteData_16Bit(0);
            Lcd_WriteData_16Bit(0);
            Lcd_WriteData_16Bit(0);
            Lcd_WriteData_16Bit(0);
            Lcd_WriteData_16Bit(0);

            /*-------------------------------------------------------------------*/
            /*  Sprite Clipping                                                  */
            /*-------------------------------------------------------------------*/
            if ((PPU_R1 & R1_CLIP_SP) == (BYTE)0)
            {
                Lcd_Set_Reg_X(32);
                Lcd_Set_Reg_Y(PPU_Scanline);
                Lcd_WriteIndex(0x2c);
                Lcd_WriteData_16Bit(0);
                Lcd_WriteData_16Bit(0);
                Lcd_WriteData_16Bit(0);
                Lcd_WriteData_16Bit(0);
                Lcd_WriteData_16Bit(0);
                Lcd_WriteData_16Bit(0);
                Lcd_WriteData_16Bit(0);
                Lcd_WriteData_16Bit(0);
            }

            if (nSprCnt >= (BYTE)8)
                PPU_R2 |= R2_MAX_SP;  // Set a flag of maximum sprites on scanline
        }
    }
}

/*===================================================================*/
/*                                                                   */
/* InfoNES_GetSprHitY() : Get a position of scanline hits sprite #0  */
/*                                                                   */
/*===================================================================*/
void InfoNES_GetSprHitY()
{
    /*
     * Get a position of scanline hits sprite #0
     *
     */

    BYTE nYBit;
    WORD* pdwChrData;
    int nOff;

    if (SPRRAM[SPR_ATTR] & SPR_ATTR_V_FLIP)
    {
        // Vertical flip
        nYBit = PPU_SP_Height - 1;
        nOff = -1;
    }
    else
    {
        // Non flip
        nYBit = 0;
        nOff = 1;
    }

    if (PPU_R0 & R0_SP_SIZE)
    {
        // Sprite size 8x16
        if (SPRRAM[SPR_CHR] & 1)
        {
            pdwChrData = &ChrBuf[256 * 16 + ((WORD)(SPRRAM[SPR_CHR] & 0xfe) << 3) + nYBit];
        }
        else
        {
            pdwChrData = &ChrBuf[((WORD)(SPRRAM[SPR_CHR] & 0xfe) << 3) + nYBit];
        }
    }
    else
    {
        // Sprite size 8x8
        pdwChrData = &PPU_SP_Base[((WORD)SPRRAM[SPR_CHR] << 3) + nYBit];
    }

    if ((SPRRAM[SPR_Y] + 1 <= SCAN_UNKNOWN_START) && (SPRRAM[SPR_Y] > 0))
    {
        BYTE nLine;

        for (nLine = 0; nLine < PPU_SP_Height; nLine++)
        {
            if (*pdwChrData != 0)
            {
                // Scanline hits sprite #0
                SpriteJustHit = SPRRAM[SPR_Y] + 1 + nLine;
                return;
            }
            pdwChrData += nOff;
        }
    }
    else {
        // Scanline didn't hit sprite #0
        SpriteJustHit = SCAN_UNKNOWN_START + 1;
    }
}

/*===================================================================*/
/*                                                                   */
/*            InfoNES_SetupChr() : Develop character data            */
/*                                                                   */
/*===================================================================*/
void InfoNES_SetupChr()
{
    /*
     *  Develop character data
     *
     */

    BYTE* pbyBGData;
    BYTE byData1;
    BYTE byData2;
    int nIdx;
    int nY;
    static BYTE* pbyPrevBank[8];
    int nBank;
    WORD* ChrBufp;

    for (nBank = 0; nBank < 8; ++nBank)
    {
        if (pbyPrevBank[nBank] == PPUBANK[nBank] && !((ChrBufUpdate >> nBank) & 1))
            continue;  // Next bank

          /*-------------------------------------------------------------------*/
          /*  An address is different from the last time                       */
          /*    or                                                             */
          /*  An update flag is being set                                      */
          /*-------------------------------------------------------------------*/

        for (nIdx = 0; nIdx < 64; ++nIdx)
        {
            ChrBufp = &ChrBuf[(nBank << 9) + (nIdx << 3)];

            for (nY = 0; nY < 8; ++nY)
            {
                pbyBGData = PPUBANK[nBank] + (nIdx << 4) + nY;

                byData1 = ((pbyBGData[0] >> 1) & 0x55) | (pbyBGData[8] & 0xAA);
                byData2 = (pbyBGData[0] & 0x55) | ((pbyBGData[8] << 1) & 0xAA);

                *ChrBufp = byData1 >> 6;
                *ChrBufp = (*ChrBufp << 2) | (byData2 >> 6);
                *ChrBufp = (*ChrBufp << 2) | ((byData1 >> 4) & 3);
                *ChrBufp = (*ChrBufp << 2) | ((byData2 >> 4) & 3);
                *ChrBufp = (*ChrBufp << 2) | ((byData1 >> 2) & 3);
                *ChrBufp = (*ChrBufp << 2) | ((byData2 >> 2) & 3);
                *ChrBufp = (*ChrBufp << 2) | (byData1 & 3);
                *ChrBufp = (*ChrBufp << 2) | (byData2 & 3);

                ++ChrBufp;
            }
        }
        // Keep this address
        pbyPrevBank[nBank] = PPUBANK[nBank];
    }

    // Reset update flag
    ChrBufUpdate = 0;
}
