#include "InfoNES_System.h"
#include "InfoNES.h"
#include "printf.h"
#include "string.h"
#include "ff.h"
#include "st7789.h"
#include "ch375.h"

BYTE System_ROM_buf[256 * 1024];
BYTE System_VROM_buf[256 * 1024];

// Palette data
WORD NesPalette[64] =
{
  0x738e, 0x20d1, 0x0015, 0x4013, 0x880e, 0xa802, 0xa000, 0x7840,
  0x4140, 0x0200, 0x0280, 0x01c2, 0x19cb, 0x0000, 0x0000, 0x0000,
  0xbdd7, 0x029d, 0x21dd, 0x801e, 0xb817, 0xe00b, 0xd940, 0xca41,
  0x8b80, 0x0480, 0x0540, 0x0487, 0x0411, 0x0000, 0x0000, 0x0000,
  0xffff, 0x3ddf, 0x5c9f, 0x445f, 0xf3df, 0xfb96, 0xfb8c, 0xfcc7,
  0xf5c7, 0x8682, 0x4ec9, 0x5fd3, 0x075b, 0x0000, 0x0000, 0x0000,
  0xffff, 0xaf1f, 0xc69f, 0xd65f, 0xfe1f, 0xfe1b, 0xfdd6, 0xfed5,
  0xff14, 0xe7d4, 0xaf97, 0xb7d9, 0x9fde, 0x0000, 0x0000, 0x0000
};


/*===================================================================*/
/*                                                                   */
/*                  InfoNES_Menu() : Menu screen                     */
/*                                                                   */
/*===================================================================*/
int InfoNES_Menu()
{
    /*
     *  Menu screen
     *
     *  Return values
     *     0 : Normally
     *    -1 : Exit InfoNES
     */

     // Nothing to do here
    return 0;
}


/*===================================================================*/
/*                                                                   */
/*               InfoNES_ReadRom() : Read ROM image file             */
/*                                                                   */
/*===================================================================*/
int InfoNES_ReadRom(const char* pszFileName)
{
    /*
     *  Read ROM image file
     *
     *  Parameters
     *    const char *pszFileName          (Read)
     *
     *  Return values
     *     0 : Normally
     *    -1 : Error
     */

    FIL fp;
    UINT rn;

    /* Open ROM file */
    if (f_open(&fp, pszFileName, FA_READ))
        return -1;

    /* Read ROM Header */
    if (f_read(&fp, &NesHeader, sizeof NesHeader, &rn))
        return -1;
    if (memcmp(NesHeader.byID, "NES\x1a", 4) != 0)
    {
        /* not .nes file */
        f_close(&fp);
        return -1;
    }

    /* Clear SRAM */
    memset(SRAM, 0, SRAM_SIZE);

    /* If trainer presents Read Triner at 0x7000-0x71ff */
    if (NesHeader.byInfo1 & 4)
    {
        if (f_read(&fp, &SRAM[0x1000], 512, &rn))
            return -1;
    }

    /* Allocate Memory for ROM Image */
    ROM = System_ROM_buf;

    /* Read ROM Image */
    if (f_read(&fp, ROM, (long)NesHeader.byRomSize * 0x4000, &rn))
        return -1;

    if (NesHeader.byVRomSize > 0)
    {
        /* Allocate Memory for VROM Image */
        VROM = System_VROM_buf;

        /* Read VROM Image */
        if (f_read(&fp, VROM, (long)NesHeader.byVRomSize * 0x2000, &rn))
            return -1;
    }

    /* File close */
    f_close(&fp);

    /* Successful */
    return 0;
}


/*===================================================================*/
/*                                                                   */
/*           InfoNES_ReleaseRom() : Release a memory for ROM         */
/*                                                                   */
/*===================================================================*/
void InfoNES_ReleaseRom(){}

void InfoNES_LoadFrame() {}

void InfoNES_PadState(DWORD* pdwPad1, DWORD* pdwPad2, DWORD* pdwSystem) {

    if (UsbUpdate() == (unsigned char)1) {
        *pdwPad1 = Keyboard_P |
            Keyboard_O << 1 |
            Keyboard_T << 2 |
            Keyboard_Y << 3 |
            Keyboard_W << 4 |
            Keyboard_S << 5 |
            Keyboard_A << 6 |
            Keyboard_D << 7;
    }
    *pdwPad2 = 0;
    *pdwSystem = 0;
}

void* InfoNES_MemoryCopy(void* dest, const void* src, int count) {
    return memcpy(dest, src, count);
}

void* InfoNES_MemorySet(void* dest, int c, int count) {
    return memset(dest, c, count);
}

void InfoNES_DebugPrint(char* pszMsg) {}

void InfoNES_Wait() {}

void InfoNES_SoundInit(void) {}

int InfoNES_SoundOpen(int samples_per_sync, int sample_rate) {
    return 1;
}

void InfoNES_SoundClose(void) {}

void InfoNES_SoundOutput(int samples, BYTE* wave1, BYTE* wave2, BYTE* wave3, BYTE* wave4, BYTE* wave5) {}

void InfoNES_MessageBox(char* pszMsg, ...) {
    va_list va;

    Printf_Set(0, 0, 0xffff, 0);
    va_start(va, pszMsg);
    vprintf(pszMsg, va);
    va_end(va);
}
