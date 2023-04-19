#include "TJpg_Decoder.h"
#include "st7789.h"

static uint32_t array_index;
static int16_t jpeg_x;
static int16_t jpeg_y;
static uint8_t workspace[TJPGD_WORKSPACE_SIZE];
static const uint8_t* array_data;

/***************************************************************************************
** Function name:           jd_input (declared static)
** Description:             Called by tjpgd.c to get more data
***************************************************************************************/
static unsigned int jd_input(JDEC* jdec, uint8_t* buf, unsigned int len)
{
    // If buf is valid then copy len bytes to buffer
    if (buf) memcpy(buf, (const uint8_t*)(array_data + array_index), len);

    // Move pointer
    array_index += len;

    return len;
}

/***************************************************************************************
** Function name:           jd_output (declared static)
** Description:             Called by tjpgd.c with an image block for rendering
***************************************************************************************/
// Pass image block back to the sketch for rendering, may be a complete or partial MCU
static int jd_output(JDEC* jdec, void* bitmap, JRECT* jrect)
{
    // Retrieve rendering parameters and add any offset
    int16_t  x = jrect->left + jpeg_x;
    int16_t  y = jrect->top + jpeg_y;
    uint16_t w = jrect->right + 1 - jrect->left;
    uint16_t h = jrect->bottom + 1 - jrect->top;

    Lcd_MappRam(x, y, w, h, (uint16_t*)bitmap);

    // Pass the image block and rendering parameters in a callback to the sketch
    return 1;
}

/***************************************************************************************
** Function name:           drawJpg
** Description:             Draw a jpg saved in a FLASH memory array
***************************************************************************************/
JRESULT drawJpg(int32_t x, int32_t y, const uint8_t jpeg_data[]) {
    JDEC jdec;
    JRESULT jresult = JDR_OK;

    array_index = 0;
    array_data = jpeg_data;

    jpeg_x = x;
    jpeg_y = y;

    jdec.swap = 0;

    // Analyse input data
    jresult = jd_prepare(&jdec, jd_input, workspace, TJPGD_WORKSPACE_SIZE, 0);

    // Extract image and render
    if (jresult == JDR_OK) {
        jresult = jd_decomp(&jdec, jd_output, 0);
    }

    return jresult;
}
