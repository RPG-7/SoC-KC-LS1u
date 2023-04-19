/*===================================================================*/
/*                                                                   */
/*  K6502.h : Header file for K6502                                  */
/*                                                                   */
/*  2000/05/29  InfoNES Project ( based on pNesX )                   */
/*                                                                   */
/*===================================================================*/

#ifndef K6502_H_INCLUDED
#define K6502_H_INCLUDED

// Type definition
#include "GlowTypedef.h"

#ifndef NULL
#define NULL 0
#endif

/* 6502 Flags */
#define FLAG_C (BYTE)0x01
#define FLAG_Z (BYTE)0x02
#define FLAG_I (BYTE)0x04
#define FLAG_D (BYTE)0x08
#define FLAG_B (BYTE)0x10
#define FLAG_R (BYTE)0x20
#define FLAG_V (BYTE)0x40
#define FLAG_N (BYTE)0x80

/* Stack Address */
#define BASE_STACK   (WORD)0x100

/* Interrupt Vectors */
#define VECTOR_NMI   (WORD)0xfffa
#define VECTOR_RESET (WORD)0xfffc
#define VECTOR_IRQ   (WORD)0xfffe

// NMI Request
#define NMI_REQ  NMI_State = 0;

// IRQ Request
#define IRQ_REQ  IRQ_State = 0;

// Emulator Operation
void K6502_Init();
void K6502_Reset();
void K6502_Set_Int_Wiring( BYTE byNMI_Wiring, BYTE byIRQ_Wiring );
void K6502_Step( register BYTE wClocks );

// I/O Operation (User definition)
static BYTE K6502_Read( WORD wAddr);
static WORD K6502_ReadW( WORD wAddr );
static WORD K6502_ReadW2( WORD wAddr );
static BYTE K6502_ReadZp( BYTE byAddr );
static WORD K6502_ReadZpW( BYTE byAddr );
static BYTE K6502_ReadAbsX();
static BYTE K6502_ReadAbsY();
static BYTE K6502_ReadIY();

static void K6502_Write( WORD wAddr, BYTE byData );
static void K6502_WriteW( WORD wAddr, WORD wData );

// The state of the IRQ pin
extern BYTE IRQ_State;

// The state of the NMI pin
extern BYTE NMI_State;

// The number of the clocks that it passed
extern BYTE g_wPassedClocks;

#endif /* !K6502_H_INCLUDED */
