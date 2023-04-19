#include "b3dDust.h"
#include <stdlib.h>
#ifdef WIN32 
#define __attribute__(A)
#endif

#pragma GCC optimize("-O3")


dust_t starDust[128];

#if B3L_ARM  == 1
__attribute__((always_inline)) static  inline u32   SatToU8(u32 in){
    u32 result;
    __ASM ("usat %0,#8,%1" : "=t"(result) : "t"(in));
    return result; 
}
#else
static u32   SatToU8(u32 in){
    const uint32_t max = ((1U << 8) - 1U);
    if (in > max){
        return max;
    }else{
        return in;
    }
}
#endif
static void  Vect3Xmat4WithTestToScreen4(vect3_t *pV, mat4_t *pMat, screen4_t *pResult){
    f32 x = pV->x; f32 y = pV->y; f32 z = pV->z;
    f32 rx,ry,rz,rw;
    u32 testResult=0;
    #define dotCol(col)\
        ((x*(pMat->m##col##0)) +\
        (y*(pMat->m##col##1)) +\
        (z*(pMat->m##col##2)) +\
        (pMat->m##col##3))
    
    rx = dotCol(0);
    ry = dotCol(1);
    rz = dotCol(2);
    rw = dotCol(3);

    if (rz<0.0f){//if the near plane clip, then don't do the calculation, set bit and return directly
        B3L_SET(testResult,B3L_NEAR_PLANE_CLIP); 
        pResult->test = testResult;     
        return;
    }else{
        if((rx<=rw)&&(rx>=-rw)&&(ry<=rw)&&(ry>=-rw)&&(rz<=rw)){
            B3L_SET(testResult,B3L_IN_SPACE);
              
        }
    }
    {
        f32 factor = 1.0f / (rw);//rw won't be zero due we returned already rz<0 (rz>0, rw must >0)
        s32 intX = (int32_t)(HALF_RESOLUTION_X + rx * factor * HALF_RESOLUTION_X);
        s32 intY = (int32_t)(HALF_RESOLUTION_Y - ry * factor * HALF_RESOLUTION_Y);
        rz = rz * factor;
        pResult->test = testResult;
        pResult->x = intX;
        pResult->y = intY;
        pResult->z = rz;
        pResult->w = rw;
    }
    #undef dotCol


}





void DustInit(void){
    s32 dustNum = DUSTNUM;
    while(dustNum--){
        starDust[dustNum].position.x=0.0f;
        starDust[dustNum].position.y=0.0f;
        starDust[dustNum].position.z=0.0f;
        starDust[dustNum].life = 0;
    }
}

void DustUpdateAndRender(render_t *pRender,B3LObj_t *pObj,u32 time){
    u32 test;
    s32 dustNum = DUSTNUM;
    vect3_t *pObjPosition = &(pObj->transform.translation);
    mat4_t  *pW2CMat = &(pRender->camera.camW2CMat);
    vect3_t vectToObj;
    screen4_t positionInScreen;
    f32   distanceSq;
    f32   x,y,z;
    u32   randomNum;
    fBuff_t  color;
    dust_t *pCurtDust;
    static s32 privousTime = 0;
    s32 deltaTime = time - privousTime;
    privousTime = time;
    while(dustNum--){
        pCurtDust = &(starDust[dustNum]);
        //check dust life,if life < 0, set it to a new random position
        pCurtDust->life -=deltaTime;
        //check distance to obj
        B3L_Vect3Sub(&(pCurtDust->position),pObjPosition,&vectToObj);
        x = vectToObj.x;
        y = vectToObj.y;
        z = vectToObj.z;
        distanceSq = x*x+y*y+z*z;
        //if((pCurtDust->life <=0)){
        if((pCurtDust->life <=0)||(distanceSq >DUSTRESETDISTANCE_SQ )){
            //relocate it to a new position and new life longth
            randomNum = B3L_Rnd((u32)DUSTRANGE_DOUBLE);
            pCurtDust->position.x = (f32)(randomNum)  - DUSTRANGE + pObjPosition->x;
            randomNum = B3L_Rnd((u32)DUSTRANGE_DOUBLE);
            pCurtDust->position.y = (f32)(randomNum)  - DUSTRANGE + pObjPosition->y;
            randomNum = B3L_Rnd((u32)DUSTRANGE_DOUBLE);
            pCurtDust->position.z = (f32)(randomNum)  - DUSTRANGE + pObjPosition->z;
            randomNum = B3L_Random();
            pCurtDust->life = LIFE_BASE + B3L_Rnd( LIFE_BASE>>1) ;
        }
        

        //draw the dust
            //get the world->clip matrix
        Vect3Xmat4WithTestToScreen4(&(pCurtDust->position), pW2CMat, &positionInScreen);
            //calculate the dust position in screen space
        //if it is in screen
        test = positionInScreen.test;
        if (B3L_TEST(test,B3L_IN_SPACE)){
            //decide current draw color
            s32 life = pCurtDust->life;
            u32 zcolor;
            color = SatToU8((life)>>2);

            zcolor = 255 - SatToU8(((u32)((positionInScreen.z)*DUST_Z_BUFF_SCALE_FACT)));
            //printf("%.3f\n",positionInScreen.z);
            color = B3L_MIN(color,zcolor);
#if (FRAME_BUFF_COLOR_TYPE  == 1)
            color= color>>4;
            color = 0xF<<12|color<<8|color<<4|color;
#endif
#if (FRAME_BUFF_COLOR_TYPE  == 0)
            color = 0xFF<<24|color<<16|color<<8|color;
#endif
            //draw with z check

            B3L_DrawPixel_ZCheck(pRender,color,positionInScreen.x,
                                 positionInScreen.y,positionInScreen.z);
        }

    }
}

