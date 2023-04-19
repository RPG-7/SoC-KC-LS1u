#ifndef __B3D_LIB_CFG_H__
#define __B3D_LIB_CFG_H__

/*Config area----------------------------------------------------------------*/


#define  B3L_ARM                0

#define  B3L_DMA2D              0
//the in situ light calculation will use the light fact to calculate the pixel rgb value,
//if it is 0, we will use alpha channel to store the light value and do the shade after rendering

#define  B3L_IN_SITU_LIGHT_CAL  0

#define  B3L_NEAR_PLANE_CLIP    0

#if B3L_DMA2D ==  1
#define B3L_LCD_BUFF_ADDR     0xXXXXXXXX
#define B3L_FRAMEBUFF_ADDR    0xXXXXXXXX
#endif

#define  B3L_DEBUG              0

//smallest update cycles in ms
#define B3L_UPDATE_CYCLE       25

//vect buff size limited the max vectors in single obj
#define VECT_BUFF_SIZE          512
//obj buff size limited the max objs in a scene 
#define OBJ_BUFF_SIZE           64
//Zbuffer level 2: f32, 1:u16, 0: u8  //may a half float 16bit would be better?
#define Z_BUFF_LEVEL            1
/*
Type 0: 32bit 8:8:8:8 ARGB  
type 1: 16bit 4:4:4:4 ARGB
type 2: 16bit 8:8     AL
*/
//current only type 0 tested
#define FRAME_BUFF_COLOR_TYPE   1
//the whole frame buff size
#define WHOLE_FRAME_BUFF_WIDTH  320
#define WHOLE_FRAME_BUFF_HEIGHT 240
//the render window size
#define RENDER_RESOLUTION_X     320
#define RENDER_RESOLUTION_Y     240
#define RENDER_X_SHIFT          WHOLE_FRAME_BUFF_WIDTH
//half resolution in floating point value
#define HALF_RESOLUTION_X       159.5f
#define HALF_RESOLUTION_Y       119.5f
//The default aspect ratio value, you could change it at camera parm
#define DEFAULT_ASPECT_RATIO    ((4.0f)/(3.0f))
//1.0f == 90 degree fov,smaller is larger fov
#define DEFAULT_FOCUS_LENGTH    (1.0f)

//maybe all here parameter could be dynamic set in render struct to balance render load?
#define DEFAULT_FAR_PLANE            800.0f
#define DEFAULT_NEAR_PLANE             4.0f
#define LEVEL_0_DEFAULT_DISTANCE     400.0f
#define LEVEL_1_DEFAULT_DISTANCE     800.0f
#define LEVEL_1_DEFAULT_LIGHT          0xA0
//level 0, calculate light, texture
//level 1, calculate texture
//level 2,??

//if you want to use any particle effects
#define B3L_USING_PARTICLE   
//max particle numbers in a scene, different particle generator share the same buff pool for the particle
//36 byte per particle for ARM32 system, it is ~18KB for 512 particle
#ifdef B3L_USING_PARTICLE
#define B3L_PARTICLE_BUFF_DEPTH    512
#endif



#endif
