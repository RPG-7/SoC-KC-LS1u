//camera function is modified from small3dlib 
//tri draw function is modified from adafruit gfx lib
//math function sin is from cmsis dsp lib
//arcsin function is copy from nvidia cg fast math lib
//invert sqrtf is copy from id soft quake


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "b3dlib.h"

#ifndef   __ASM
#define   __ASM        __asm
#endif
#ifdef WIN32 
#define __attribute__(A)
#endif

#pragma GCC optimize("-O3")
//config the ram position if necessary
u32            B3L_seed = 0x31415926;
screen3f_t     vectBuff[VECT_BUFF_SIZE]; //8KB
__attribute__((section(".zbuff")))  zBuff_t  zBuff[Z_BUFF_LENTH];        //
#ifdef B3L_USING_PARTICLE
B3L_Particle_t  particleBuff[B3L_PARTICLE_BUFF_DEPTH];//18KB
#endif


#if Z_BUFF_LEVEL == 2
    #define Z_LIMIT_NUM      (1.0f)
#endif
#if Z_BUFF_LEVEL == 1
    #define Z_LIMIT_NUM      (65535u)
#endif
#if Z_BUFF_LEVEL == 0
    #define Z_LIMIT_NUM      (255u)
#endif

#ifndef _swap_f32_t
#define _swap_f32_t(a, b) { f32 t = a; a = b; b = t; }
#endif
#ifndef _swap_int32_t
#define _swap_int32_t(a, b) { int32_t t = a; a = b; b = t; }
#endif

/*Private Fuction declare ---------------------------------------------------*/ 
/*-----------------------------------------------------------------------------
Math functions
-----------------------------------------------------------------------------*/
#if  B3L_ARM == 1
__attribute__((always_inline)) static  inline f32      B3L_Sqrtf(f32 in);
__attribute__((always_inline)) static  inline f32      B3L_Absf(f32 in);
#else
#define B3L_Sqrtf   sqrtf
#define B3L_Absf    fabsf
#endif 
__attribute__((always_inline)) static  inline s32      B3L_RoundingToS(f32 in);
__attribute__((always_inline)) static  inline s32      B3L_RoundingToU(f32 in);
__attribute__((always_inline)) static  inline f32      FastInvertSqrt(f32 x);  
__attribute__((always_inline)) static  inline s32      VcvtF32ToS32_Fix(f32 in);
__attribute__((always_inline)) static  inline f32      VcvtS32ToF32_Fix(s32 in);
__attribute__((always_inline)) static  inline u32      SatToU8(u32 in);
__attribute__((always_inline)) static  inline u32      SatToU16(u32 in);
__attribute__((always_inline)) static  inline f32      Interp_f(f32 x1, f32 x2, f32 t);
__attribute__((always_inline)) static  inline s32      Clamp_i(s32 v, s32 v1, s32 v2);
__attribute__((always_inline)) static  inline f32      Clamp_f(f32 v, f32 v1, f32 v2);
/*-----------------------------------------------------------------------------
Vector and matrix functions
-----------------------------------------------------------------------------*/
__attribute__((always_inline)) static  inline void     Vect3_Add(vect3_t *pV1,vect3_t *pV2,vect3_t *pResult);
__attribute__((always_inline)) static  inline void     MakeClipMatrix(u32 state,f32 near_plane,f32 far_plane,f32 focalLength, f32 aspectRatio,mat4_t *pMat);
__attribute__((always_inline)) static  inline void     Vect3Xmat4(vect3_t *pV, mat4_t *pMat, vect4_t *pResult);
__attribute__((always_inline)) static  inline void     Vect3Xmat4WithTestToScreen4(vect3_t *pV, mat4_t *pMat, screen4_t *pResult);
__attribute__((always_inline)) static  inline void     Vect3Xmat4WithTest_f(vect3_t *pV, mat4_t *pMat, screen3f_t *pResult);
__attribute__((always_inline)) static  inline bool     Vect4BoundTest(vect4_t *pV);
/*-----------------------------------------------------------------------------
Z buff functions
-----------------------------------------------------------------------------*/
__attribute__((always_inline)) static  inline zBuff_t  CalZbuffValue(f32 z);
/*-----------------------------------------------------------------------------
Light functions
-----------------------------------------------------------------------------*/
__attribute__((always_inline)) static  inline fBuff_t  LightBlend(u32 inputPixel, u8 r, u8 g, u8 b);
__attribute__((always_inline)) static  inline u32      CalLightFactor(f32 normalDotLight, f32 lightFactor0,f32 lightFactor1);
 /*-----------------------------------------------------------------------------
Testing functions
-----------------------------------------------------------------------------*/
static bool Vect3InClipSpace(vect3_t *pV, mat4_t *pMat);
static bool BoundBoxTest(f32 *pMaxMin,mat4_t *pMat);
__attribute__((always_inline)) static  inline bool     TriangleFaceToViewer_f(f32 x0, f32 y0, f32 x1, f32 y1, f32 x2, f32 y2);
__attribute__((always_inline)) static  inline bool     TriVisable(u32 r0,u32 r1,u32 r2);
 /*-----------------------------------------------------------------------------
Draw functions
-----------------------------------------------------------------------------*/ 
__attribute__((always_inline)) static  inline fBuff_t  GetFinalColor(fBuff_t color,u32 lightFactor);
__attribute__((always_inline)) static  inline fBuff_t  GetColorValue(texLUT_t *lut,u8 colorIdx,u32 lightFactor);
__attribute__((always_inline)) static  inline void     DrawPixel(fBuff_t color,s32 x,s32 y,f32 z,
                                                                        fBuff_t *pFrameBuff,zBuff_t *pZbuff);
__attribute__((always_inline)) static  inline void     DrawPixelWithTest(fBuff_t color,s32 x,s32 y,f32 z,
                                                                        fBuff_t *pFrameBuff,zBuff_t *pZbuff);                                                                        
__attribute__((always_inline)) static  inline void     DrawTriTexture(
                                                                        f32 x0,f32 y0,f32 u0,f32 v0,f32 z0,
                                                                        f32 x1,f32 y1,f32 u1,f32 v1,f32 z1,
                                                                        f32 x2,f32 y2,f32 u2,f32 v2,f32 z2,
                                                                        u32 renderLevel,u32 lightFactor,B3L_texture_t *pTexture,
                                                                        fBuff_t *pFrameBuff,zBuff_t *pZbuff);
__attribute__((always_inline)) static  inline void     DrawTriColor(
                                                                        f32 x0,f32 y0,f32 z0,
                                                                        f32 x1,f32 y1,f32 z1,
                                                                        f32 x2,f32 y2,f32 z2,
                                                                        u32 renderLevel,u32 lightFactor,fBuff_t color,
                                                                        fBuff_t *pFrameBuff,zBuff_t *pZbuff);
__attribute__((always_inline)) static  inline void     DrawTexHLine(f32 x,s32 y,f32 b, f32 aZ, f32 bZ,
                                                                        f32 aU,f32 aV,f32 bU,f32 bV,u32 lightFactor, 
                                                                        fBuff_t *pFrameBuff,zBuff_t *pZbuff,
                                                                        B3L_texture_t *pTexture);
__attribute__((always_inline)) static  inline void     DrawColorHLine(f32 x,s32 y,f32 b, f32 aZ, f32 bZ,
                                                                        fBuff_t finalColor, 
                                                                        fBuff_t *pFrameBuff,zBuff_t *pZbuff); 
__attribute__((always_inline)) static  inline void     DrawDepthLineNoClip(s32 Ax,s32 Ay,f32 Az,s32 Bx,s32 By,f32 Bz, 
                                                                        texLUT_t color,fBuff_t *pFrameBuff,zBuff_t *pZbuff);  
__attribute__((always_inline)) static  inline void     DrawDepthLineClip(s32 Ax,s32 Ay,f32 Az,s32 Bx,s32 By,f32 Bz, 
                                                                        texLUT_t color,fBuff_t *pFrameBuff,zBuff_t *pZbuff);             
 /*-----------------------------------------------------------------------------
Camera functions
-----------------------------------------------------------------------------*/
static void     UpdateCam(render_t *pRender);
static void     GenerateW2CMatrix(camera_t *pCam);

static void     CamCalNewTrackPosition(camera_t *pCam);
static void     CamCalNewTrackQuaternion(camera_t *pCam);
 /*-----------------------------------------------------------------------------
Obj list functions
-----------------------------------------------------------------------------*/
static void ResetObjList(scene_t *pScene);
static void AddObjToTwoWayList(B3LObj_t *pObj, B3LObj_t **pStart);
 /*-----------------------------------------------------------------------------
Particle list functions
-----------------------------------------------------------------------------*/
static void ResetParticleList(B3L_Particle_t *pPool,B3L_Particle_t **pStart,u32 num);
 /*-----------------------------------------------------------------------------
Buffer functions
-----------------------------------------------------------------------------*/
static void ClearFrameBuff(fBuff_t *pFramebuff,fBuff_t value,u32 lineNum,u32 lineLength,u32 lineSkip);
static void ClearZbuff(zBuff_t *pZbuff,u32 length);
 /*-----------------------------------------------------------------------------
Obj render functions
-----------------------------------------------------------------------------*/
static void RenderMeshObjs(render_t *pRender);
#ifdef B3L_USING_PARTICLE
static void UpdateParticleObjs(render_t *pRender, u32 time);
static void RenderParticleObjs(render_t *pRender);
#endif
static void RenderTexMesh(B3LMeshObj_t *pObj,render_t *pRender, mat4_t *pMat,u32 renderLevel);
static void RenderNoTexMesh(B3LMeshNoTexObj_t *pObj,render_t *pRender, mat4_t *pMat,u32 renderLevel);
static void RenderPolygon(B3LPolygonObj_t *pObj,render_t *pRender, mat4_t *pMat);

/*Function defines-----------------------------------------------------------*/
/*-----------------------------------------------------------------------------
Math function
-----------------------------------------------------------------------------*/
#if B3L_ARM  == 1
__attribute__((always_inline)) static  inline f32 B3L_Sqrtf(f32 in){
    f32 result;
__ASM("vsqrt.f32 %0,%1" : "=t"(result) : "t"(in));
  return (result);
}
__attribute__((always_inline)) static  inline f32 B3L_Absf(f32 in){
    f32 result;
    __ASM("vabs.f32 %0,%1" : "=t"(result) : "t"(in));
    return (result); 
}
__attribute__((always_inline)) static  inline s32   VcvtF32ToS32_Fix(f32 in){
    s32 result;
    __ASM ("vcvt.s32.f32 %0,%1,#B3L_FIX_BITS" : "=t"(result) : "t"(in));
    return result; 
}

__attribute__((always_inline)) static  inline f32   VcvtS32ToF32_Fix(s32 in){
    s32 result;
    __ASM ("vcvt.f32.s32 %0,%1,#B3L_FIX_BITS" : "=t"(result) : "t"(in));
    return result; 
}

__attribute__((always_inline)) static  inline u32   SatToU8(u32 in){
    u32 result;
    __ASM ("usat %0,#8,%1" : "=t"(result) : "t"(in));
    return result; 
}

__attribute__((always_inline)) static  inline u32   SatToU16(u32 in){
    u32 result;
    __ASM ("usat %0,#16,%1" : "=t"(result) : "t"(in));
    return result; 
}

__attribute__((always_inline)) static  inline s32   B3L_RoundingToS(f32 in){
    s32 result;
    __ASM ("vcvtr.s32.f32 %0,%1" : "=t"(result) : "t"(in));
    return result; 
}

__attribute__((always_inline)) static  inline s32   B3L_RoundingToU(f32 in){
    u32 result;
    __ASM ("vcvtr.u32.f32 %0,%1" : "=t"(result) : "t"(in));
    return result; 
}

#else
__attribute__((always_inline)) static  inline s32   VcvtF32ToS32_Fix(f32 in){
    return ((s32)(in*((f32)(1<<B3L_FIX_BITS))));
}
__attribute__((always_inline)) static  inline f32   VcvtS32ToF32_Fix(s32 in){
    return ((f32)in)/((f32)(1<<B3L_FIX_BITS));
}
__attribute__((always_inline)) static  inline u32   SatToU8(u32 in){
    const uint32_t max = ((1U << 8) - 1U);
    if (in > max){
        return max;
    }else{
        return in;
    }
}
__attribute__((always_inline)) static  inline u32   SatToU16(u32 in){
    const uint32_t max = ((1U << 16) - 1U);
    if (in > max){
        return max;
    }else{
        return in;
    }
}

__attribute__((always_inline)) static  inline s32   B3L_RoundingToS(f32 in){
    return (s32)roundf(in); 
}

__attribute__((always_inline)) static  inline s32   B3L_RoundingToU(f32 in){
    return (u32)roundf(in); 
}
#endif //end of B3L_ARM

__attribute__((always_inline)) static  inline f32 Clamp_f(f32 v, f32 v1, f32 v2){
    return v > v1 ? (v < v2 ? v : v2) : v1;
}

__attribute__((always_inline)) static  inline s32 Clamp_i(s32 v, s32 v1, s32 v2)
{
    return v >= v1 ? (v <= v2 ? v : v2) : v1;
}

//inv sqrt black magic from quake 
__attribute__((always_inline)) static  inline f32 FastInvertSqrt(f32 x){
    f32 xhalf = 0.5f * x;
        int i = *(int*)&x;            // store floating-point bits in integer
        i = 0x5f3759df - (i >> 1);    // initial guess for Newton's method
        x = *(float*)&i;              // convert new bits into float
        x = x*(1.5f - xhalf*x*x);     // One round of Newton's method
        return x;
}

__attribute__((always_inline)) static inline f32 Interp_f(f32 x1, f32 x2, f32 t){
    return x1 + (x2 - x1) * t;
}

__attribute__((always_inline)) static  inline void Vect3_Add(vect3_t *pV1,vect3_t *pV2,vect3_t *pResult){
    pResult->x = pV1->x + pV2->x;
    pResult->y = pV1->y + pV2->y;
    pResult->z = pV1->z + pV2->z;
}

/*
    Create 3*3 matrix for rotation in x axis
*/
void B3L_Mat3XRotate(mat3_t *pMat,f32 angle){
    f32 cosp = B3L_cos(angle);
    f32 sinp = B3L_sin(angle);
    pMat->m00=1.0f; pMat->m01=0.0f; pMat->m02=0.0f;
    pMat->m10=0.0f; pMat->m11=cosp; pMat->m12=-sinp;
    pMat->m20=0.0f; pMat->m21=sinp; pMat->m22=cosp;
}

/*
    Create 3*3 matrix for rotation in y axis
*/
void B3L_Mat3YRotate(mat3_t *pMat,f32 angle){
    f32 cosh = B3L_cos(angle);
    f32 sinh = B3L_sin(angle);
    pMat->m00=cosh; pMat->m01=0.0f; pMat->m02=sinh;
    pMat->m10=0.0f; pMat->m11=1.0f; pMat->m12=0.0f;
    pMat->m20=-sinh; pMat->m21=0.0f; pMat->m22=cosh;
}

/*
    Create 3*3 matrix for rotation in z axis
*/
void B3L_Mat3ZRotate(mat3_t *pMat,f32 angle){
    f32 cosb = B3L_cos(angle);
    f32 sinb = B3L_sin(angle);
    pMat->m00=cosb; pMat->m01=-sinb; pMat->m02=0.0f;
    pMat->m10=sinb; pMat->m11=cosb; pMat->m12=0.0f;
    pMat->m20=0.0f; pMat->m21=0.0f; pMat->m22=1.0f;
}

/*
    Rotate obj matrix in obj space by x axis
*/
void B3L_RotateObjInOX(quat4_t *pQuat,f32 angle){
    quat4_t rqat;
    B3L_QuatCreateXRotate(&rqat,angle);
    B3L_QuatMult(pQuat,&rqat, pQuat);
}

/*
    Rotate obj matrix in obj space by y axis
*/
void B3L_RotateObjInOY(quat4_t *pQuat,f32 angle){
    quat4_t rqat;
    B3L_QuatCreateYRotate(&rqat,angle);
    B3L_QuatMult(pQuat,&rqat, pQuat);
}

/*
    Rotate obj matrix in obj space by z axis
*/
void B3L_RotateObjInOZ(quat4_t *pQuat,f32 angle){
    quat4_t rqat;
    B3L_QuatCreateZRotate(&rqat,angle);
    B3L_QuatMult(pQuat,&rqat, pQuat);
}

/*
    Rotate obj matrix in world space by x axis
*/
void B3L_RotateObjInWX(quat4_t *pQuat,f32 angle){
    quat4_t rqat;
    B3L_QuatCreateXRotate(&rqat,angle);
    B3L_QuatMult(&rqat, pQuat,pQuat);
}

/*
    Rotate obj matrix in world space by y axis
*/
void B3L_RotateObjInWY(quat4_t *pQuat,f32 angle){
    quat4_t rqat;
    B3L_QuatCreateYRotate(&rqat,angle);
    B3L_QuatMult(&rqat, pQuat,pQuat);
}

/*
    Rotate obj matrix in world space by z axis ?? may should use matrix type ABA
*/
void B3L_RotateObjInWZ(quat4_t *pQuat,f32 angle){
    quat4_t rqat;
    B3L_QuatCreateZRotate(&rqat,angle);
    B3L_QuatMult(&rqat, pQuat,pQuat);

}

__attribute__((always_inline)) static inline void Vect3Xmat4(vect3_t *pV, mat4_t *pMat, vect4_t *pResult){
    f32 x = pV->x; f32 y = pV->y; f32 z = pV->z;
    #define dotCol(col)\
        ((x*(pMat->m##col##0)) +\
        (y*(pMat->m##col##1)) +\
        (z*(pMat->m##col##2)) +\
        (pMat->m##col##3))
    
    pResult->x = dotCol(0);
    pResult->y = dotCol(1);
    pResult->z = dotCol(2);
    pResult->w = dotCol(3);
    #undef dotCol
}

__attribute__((always_inline)) static  inline void  Vect3Xmat4WithTest_f(vect3_t *pV, mat4_t *pMat, screen3f_t *pResult){
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
    
    f32 factor=1.0f / (rw);//rw won't be zero due we returned already rz<0 (rz>0, rw must >0)
    f32 intX = (HALF_RESOLUTION_X + rx *factor* HALF_RESOLUTION_X);
    f32 intY = (HALF_RESOLUTION_Y - ry *factor* HALF_RESOLUTION_Y);
    rz = rz*factor;
    pResult->test = testResult; 
    pResult->x = intX;
    pResult->y = intY;
    pResult->z = rz;
    #undef dotCol

}

__attribute__((always_inline)) static  inline void  Vect3Xmat4WithTestToScreen4(vect3_t *pV, mat4_t *pMat, screen4_t *pResult){
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

    f32 factor=1.0f / (rw);//rw won't be zero due we returned already rz<0 (rz>0, rw must >0)
    s32 intX = (int32_t)(HALF_RESOLUTION_X + rx *factor* HALF_RESOLUTION_X);
    s32 intY = (int32_t)(HALF_RESOLUTION_Y - ry *factor* HALF_RESOLUTION_Y);
    rz = rz*factor;
    pResult->test = testResult;  
    pResult->x = intX;
    pResult->y = intY;
    pResult->z = rz;
    pResult->w = rw;
    #undef dotCol

}

void     B3L_Vect3MulMat3(vect3_t *pV, mat3_t *pMat, vect3_t *pResult){
    f32 x = pV->x; f32 y = pV->y; f32 z = pV->z;
    f32 rx,ry,rz;

    #define dotCol(col)\
        (x*(pMat->m##col##0)) +\
        (y*(pMat->m##col##1)) +\
        (z*(pMat->m##col##2)) 
    
    rx = dotCol(0);
    ry = dotCol(1);
    rz = dotCol(2);

    pResult->x = rx;
    pResult->y = ry;
    pResult->z = rz;
    #undef dotCol 
}

void     B3L_Point3MulMat4(vect3_t *pV, mat4_t *pMat, vect3_t *pResult){
    f32 x = pV->x; f32 y = pV->y; f32 z = pV->z;
    f32 rx,ry,rz;

    #define dotCol(col)\
        (x*(pMat->m##col##0)) +\
        (y*(pMat->m##col##1)) +\
        (z*(pMat->m##col##2)) +\
        pMat->m##col##3
    
    rx = dotCol(0);
    ry = dotCol(1);
    rz = dotCol(2);

    pResult->x = rx;
    pResult->y = ry;
    pResult->z = rz;
    #undef dotCol
}

__attribute__((always_inline)) static  inline bool Vect4BoundTest(vect4_t *pV){
    f32 x=pV->x;f32 y=pV->y;f32 z=pV->z;f32 w=pV->w;
    if((x<=w)&&(x>=-w)&&(y<=w)&&(y>=-w)&&(z>=0)&&(z<=w)){
        return true;
    }else{
        return false;
    }

}

/*-----------------------------------------------------------------------------
    Math functions
-----------------------------------------------------------------------------*/
f32 B3L_sin(f32 in){
    in = in-(f32)((s32)in);//scale to -1~1
    if (in>0.25f){in = 0.5f - in;}
    if (in<-0.25f){in = -0.5f -in;}
    if (in>0.25f){in = 0.5f - in;}
    f32 v2 = in*in;
    f32 v3 = in*v2;
    f32 v5 = v3*v2;
    f32 v7 = v5*v2;
    return  6.28316394434f*in-41.3371315018f*v3+81.3404239211f*v5-70.99090501333f*v7;
}

f32 B3L_cos(f32 in){
    return B3L_sin(in + 0.25f);
}

f32 B3L_asin(f32 in){
    in = Clamp_f(in, -1.0f,1.0f);
    float negate = (f32)(in < 0);
    
    if (in < 0.0f){
        in = -1.0f*in;
    }
    float ret = -0.0187293f;
    ret *= in;
    ret += 0.0742610f;
    ret *= in;
    ret -= 0.2121144f;
    ret *= in;
    ret += 1.5707288f;
    ret = 3.14159265358979f*0.5f - B3L_Sqrtf(1.0f - in)*ret;
    ret = (ret - 2 * negate * ret)*0.15915494309f;
    return ret;
}

f32  B3L_atan2(f32 y,f32 x){
    f32 t0, t1, t3, t4;

    t3 = B3L_Absf(x);
    t1 = B3L_Absf(y);
    t0 = B3L_MAX(t3, t1);
    t1 = B3L_MIN(t3, t1);
    t3 = 1.0f / t0;
    t3 = t1 * t3;
    t4 = t3 * t3;
    t0 =         - 0.013480470f;
    t0 = t0 * t4 + 0.057477314f;
    t0 = t0 * t4 - 0.121239071f;
    t0 = t0 * t4 + 0.195635925f;
    t0 = t0 * t4 - 0.332994597f;
    t0 = t0 * t4 + 0.999995630f;
    t3 = t0 * t3 * 0.159154943f;
    t3 = (B3L_Absf(y) > B3L_Absf(x)) ? 0.25f - t3 : t3;
    t3 = (x < 0) ?  0.5f - t3 : t3;
    t3 = (y < 0) ? -t3 : t3;
    return t3;
}

//random function
void B3L_SetSeed(u32 seed){
    B3L_seed = seed|1;
}
//using rand xorshift algorithm from george marsaglia's paper
u32 B3L_Random(void){
    B3L_seed ^=(B3L_seed<<13);
    B3L_seed ^=(B3L_seed>>17);
    B3L_seed ^=(B3L_seed<<5);
    return B3L_seed;
}

u32  B3L_Rnd(u32 range){
    return B3L_Random()%range;
}
/*-----------------------------------------------------------------------------
Vector functions
-----------------------------------------------------------------------------*/
vect2_t B3L_Vect2(f32 x,f32 y){
    vect2_t output = {.x=x,.y=y};
    return output;
}

vect3_t B3L_Vect3(f32 x,f32 y,f32 z){
    vect3_t output = {.x=x,.y=y,.z=z};
    return output;
}

vect4_t B3L_Vect4(f32 x,f32 y,f32 z,f32 w){
    vect4_t output = {.x=x,.y=y,.z=z,.w=w};
    return output;
}

f32 B3L_Vec2Length(vect2_t *pV){
    return B3L_Sqrtf(pV->x*pV->x+pV->y*pV->y);
}

void B3L_Vect2Normalize(vect2_t *pV,vect2_t *pResult){
    f32 x = pV->x;f32 y= pV->y;
    f32 factor = FastInvertSqrt(x*x+y*y);
    pResult->x = (x*factor);
    pResult->y = (y*factor);
}

void B3L_Vect3Normalize(vect3_t *pV,vect3_t *pResult){
    f32 x = pV->x;f32 y= pV->y;f32 z= pV->z;
    //f32 factor = FastInvertSqrt(x*x+y*y+z*z);
    f32 factor = 1.0f/B3L_Sqrtf(x*x+y*y+z*z);
    pResult->x = (x*factor);
    pResult->y = (y*factor);
    pResult->z = (z*factor);
}

f32 B3L_Vect3Length(vect3_t *pV){
    f32 x = pV->x;f32 y= pV->y;f32 z= pV->z;
    return B3L_Sqrtf(x * x + y*y + z*z);  
}

void B3L_Vect3Add(vect3_t *pVa,vect3_t *pVb,vect3_t *pResult){
    pResult->x = pVa->x + pVb->x;
    pResult->y = pVa->y + pVb->y;
    pResult->z = pVa->z + pVb->z;
}

void B3L_Vect3Sub(vect3_t *pVa,vect3_t *pVb,vect3_t *pResult){
    pResult->x = pVa->x - pVb->x;
    pResult->y = pVa->y - pVb->y;
    pResult->z = pVa->z - pVb->z;

}

void B3L_Vect3Cross(vect3_t *pA, vect3_t *pB, vect3_t *pResult){
    pResult->x = pA->y * pB->z - pA->z * pB->y;
    pResult->y = pA->z * pB->x - pA->x * pB->z;
    pResult->z = pA->x * pB->y - pA->y * pB->x;  
}

f32 B3L_Vect3Dot(vect3_t *pA, vect3_t *pB){
    return (pA->x*pB->x+pA->y*pB->y+pA->z*pB->z);
}

void B3L_Vect3Scale(vect3_t *pV,f32 scale,vect3_t *pResult){
    pResult->x = scale*pV->x;
    pResult->y = scale*pV->y;
    pResult->z = scale*pV->z;
}

void B3L_Vect3Interp(vect3_t *pVa,vect3_t *pVb,vect3_t *pResult,f32 t){
    pResult->x = Interp_f(pVa->x,pVb->x,t);
    pResult->y = Interp_f(pVa->y,pVb->y,t);
    pResult->z = Interp_f(pVa->z,pVb->z,t);
}

/*-----------------------------------------------------------------------------
Matrix functions
-----------------------------------------------------------------------------*/
void B3L_InitUnitMat3(mat3_t *pMat){
    pMat->m00 = 1.0f;pMat->m01 = 0.0f;pMat->m02 = 0.0f;
    pMat->m10 = 0.0f;pMat->m11 = 1.0f;pMat->m12 = 0.0f;
    pMat->m20 = 0.0f;pMat->m21 = 0.0f;pMat->m22 = 1.0f;
}

void B3L_CreateO2WMat(mat3_t *pRMat, vect3_t *pTranslation, vect3_t *pScale, mat4_t *pResult){
    f32 sx = pScale->x;f32 sy = pScale->y;f32 sz = pScale->z;
    pResult->m03 = pTranslation->x; pResult->m13 = pTranslation->y; pResult->m23 = pTranslation->z;
    pResult->m00 = pRMat->m00*sx; pResult->m01 = pRMat->m01*sy; pResult->m02 = pRMat->m02*sz;
    pResult->m10 = pRMat->m10*sx; pResult->m11 = pRMat->m11*sy; pResult->m12 = pRMat->m12*sz;
    pResult->m20 = pRMat->m20*sx; pResult->m21 = pRMat->m21*sy; pResult->m22 = pRMat->m22*sz;
    pResult->m30 = 0.0f; pResult->m31 = 0.0f; pResult->m32 = 0.0f; pResult->m33 = 1.0f;
}

__attribute__((always_inline)) static inline void MakeClipMatrix(u32 state,f32 near_plane,f32 far_plane,
                                                                 f32 focalLength, f32 aspectRatio,mat4_t *pMat){
    f32 zero = 0.0f;
    f32 one = 1.0f;
    #define M(x,y) (pMat)->m##x##y
    if(B3L_TEST(state,B3L_PROJECT_MODE)==PERSPECTIVE_PROJECT){
        M(0,0) = focalLength; M(1,0) = zero;   M(2,0) = zero;   M(3,0) = zero; 
        M(0,1) = zero;   M(1,1) = focalLength*aspectRatio; M(2,1) = zero;   M(3,1) = zero; 
        M(0,2) = zero;   M(1,2) = zero;   M(2,2) = far_plane/(far_plane-near_plane); M(3,2) = one; 
        M(0,3) = zero;   M(1,3) = zero;   M(2,3) =-near_plane*far_plane/(far_plane-near_plane);   M(3,3) = zero; 
    }else{
        M(0,0) = focalLength; M(1,0) = zero;   M(2,0) = zero;   M(3,0) = zero; 
        M(0,1) = zero;   M(1,1) = focalLength*aspectRatio; M(2,1) = zero;   M(3,1) = zero; 
        M(0,2) = zero;   M(1,2) = zero;   M(2,2) = one/(far_plane-near_plane); M(3,2) = zero; 
        M(0,3) = zero;   M(1,3) = zero;   M(2,3) =near_plane/(far_plane-near_plane);   M(3,3) = one; 
    }
    
    #undef M
}

void B3L_InitMat4One(mat4_t *pMat){
    #define M(x,y) (pMat)->m##x##y
    M(0,0) = 1.0f; M(1,0) = 0.0f; M(2,0) = 0.0f; M(3,0) = 0.0f; 
    M(0,1) = 0.0f; M(1,1) = 1.0f; M(2,1) = 0.0f; M(3,1) = 0.0f; 
    M(0,2) = 0.0f; M(1,2) = 0.0f; M(2,2) = 1.0f; M(3,2) = 0.0f; 
    M(0,3) = 0.0f; M(1,3) = 0.0f; M(2,3) = 0.0f; M(3,3) = 1.0f; 
    #undef M
}

void B3L_TransposeMat4(mat4_t *pMat){
    f32 temp;
    temp = ((f32 *)pMat)[1];
    ((f32 *)pMat)[1]=((f32 *)pMat)[4];
    ((f32 *)pMat)[4] = temp;

    temp = ((f32 *)pMat)[2];
    ((f32 *)pMat)[2]=((f32 *)pMat)[8];
    ((f32 *)pMat)[8] = temp;

    temp = ((f32 *)pMat)[6];
    ((f32 *)pMat)[6]=((f32 *)pMat)[9];
    ((f32 *)pMat)[9] = temp;
    
    temp = ((f32 *)pMat)[3];
    ((f32 *)pMat)[3]=((f32 *)pMat)[12];
    ((f32 *)pMat)[12] = temp;

    temp = ((f32 *)pMat)[7];
    ((f32 *)pMat)[7]=((f32 *)pMat)[13];
    ((f32 *)pMat)[13] = temp;

    temp = ((f32 *)pMat)[11];
    ((f32 *)pMat)[11]=((f32 *)pMat)[14];
    ((f32 *)pMat)[14] = temp;
}

//mat1 * mat2 -> mat3, it is safe to set mat1 same as mat3
void B3L_Mat4XMat4(mat4_t *pMat1,mat4_t *pMat2, mat4_t *pMat3){
    f32 t0,t1,t2,t3;
    f32 s0,s1,s2,s3;
    #define M(x,y) (pMat1)->m##x##y
    #define N(x,y) (pMat2)->m##x##y
    #define O(x,y) (pMat3)->m##x##y
    s0=M(0,0);s1=M(1,0);s2=M(2,0);s3=M(3,0);
    t0 = s0*N(0,0)+s1*N(0,1)+s2*N(0,2)+s3*N(0,3);
    t1 = s0*N(1,0)+s1*N(1,1)+s2*N(1,2)+s3*N(1,3);
    t2 = s0*N(2,0)+s1*N(2,1)+s2*N(2,2)+s3*N(2,3);
    t3 = s0*N(3,0)+s1*N(3,1)+s2*N(3,2)+s3*N(3,3);
    O(0,0) = t0;O(1,0) = t1;O(2,0) = t2;O(3,0) = t3;
    s0=M(0,1);s1=M(1,1);s2=M(2,1);s3=M(3,1);
    t0 =s0*N(0,0)+s1*N(0,1)+s2*N(0,2)+s3*N(0,3);
    t1 =s0*N(1,0)+s1*N(1,1)+s2*N(1,2)+s3*N(1,3);
    t2 =s0*N(2,0)+s1*N(2,1)+s2*N(2,2)+s3*N(2,3);
    t3 =s0*N(3,0)+s1*N(3,1)+s2*N(3,2)+s3*N(3,3);
    O(0,1) = t0;O(1,1) = t1;O(2,1) = t2;O(3,1) = t3;
    s0=M(0,2);s1=M(1,2);s2=M(2,2);s3=M(3,2);
    t0 =s0*N(0,0)+s1*N(0,1)+s2*N(0,2)+s3*N(0,3);
    t1 =s0*N(1,0)+s1*N(1,1)+s2*N(1,2)+s3*N(1,3);
    t2 =s0*N(2,0)+s1*N(2,1)+s2*N(2,2)+s3*N(2,3);
    t3 =s0*N(3,0)+s1*N(3,1)+s2*N(3,2)+s3*N(3,3);
    O(0,2) = t0;O(1,2) = t1;O(2,2) = t2;O(3,2) = t3;
    s0=M(0,3);s1=M(1,3);s2=M(2,3);s3=M(3,3);
    t0 = s0*N(0,0)+s1*N(0,1)+s2*N(0,2)+s3*N(0,3);
    t1 = s0*N(1,0)+s1*N(1,1)+s2*N(1,2)+s3*N(1,3);
    t2 = s0*N(2,0)+s1*N(2,1)+s2*N(2,2)+s3*N(2,3);
    t3 = s0*N(3,0)+s1*N(3,1)+s2*N(3,2)+s3*N(3,3);
    O(0,3) = t0;O(1,3) = t1;O(2,3) = t2;O(3,3) = t3;
    #undef M
    #undef N
    #undef O
}

/*
    matrix 3*3 B = AB
*/
void B3L_Mat3MultMat3ABB(mat3_t *pMatA,mat3_t *pMatB){
f32 t0,t1,t2;
    f32 s0,s1,s2;
    #define M(x,y) (pMatA)->m##x##y
    #define N(x,y) (pMatB)->m##x##y
    s0=N(0,0);s1=N(0,1);s2=N(0,2);
    t0 = s0*M(0,0)+s1*M(1,0)+s2*M(2,0);
    t1 = s0*M(0,1)+s1*M(1,1)+s2*M(2,1);
    t2 = s0*M(0,2)+s1*M(1,2)+s2*M(2,2);  
    N(0,0) = t0;N(0,1) = t1;N(0,2) = t2;
    s0=N(1,0);s1=N(1,1);s2=N(1,2);
    t0 = s0*M(0,0)+s1*M(1,0)+s2*M(2,0);
    t1 = s0*M(0,1)+s1*M(1,1)+s2*M(2,1);
    t2 = s0*M(0,2)+s1*M(1,2)+s2*M(2,2);   
    N(1,0) = t0;N(1,1) = t1;N(1,2) = t2;
    s0=N(2,0);s1=N(2,1);s2=N(2,2);
    t0 = s0*M(0,0)+s1*M(1,0)+s2*M(2,0);
    t1 = s0*M(0,1)+s1*M(1,1)+s2*M(2,1);
    t2 = s0*M(0,2)+s1*M(1,2)+s2*M(2,2);   
    N(2,0) = t0;N(2,1) = t1;N(2,2) = t2;   
    #undef M
    #undef N
}

/*
    matrix 3*3 A = AB
*/
void B3L_Mat3MultMat3ABA(mat3_t *pMatA,mat3_t *pMatB){
    f32 t0,t1,t2;
    f32 s0,s1,s2;
    #define M(x,y) (pMatA)->m##x##y
    #define N(x,y) (pMatB)->m##x##y
    s0=M(0,0);s1=M(1,0);s2=M(2,0);
    t0 = s0*N(0,0)+s1*N(0,1)+s2*N(0,2);
    t1 = s0*N(1,0)+s1*N(1,1)+s2*N(1,2);
    t2 = s0*N(2,0)+s1*N(2,1)+s2*N(2,2);
    M(0,0) = t0;M(1,0) = t1;M(2,0) = t2;
    s0=M(0,1);s1=M(1,1);s2=M(2,1);
    t0 =s0*N(0,0)+s1*N(0,1)+s2*N(0,2);
    t1 =s0*N(1,0)+s1*N(1,1)+s2*N(1,2);
    t2 =s0*N(2,0)+s1*N(2,1)+s2*N(2,2);
    M(0,1) = t0;M(1,1) = t1;M(2,1) = t2;
    s0=M(0,2);s1=M(1,2);s2=M(2,2);
    t0 =s0*N(0,0)+s1*N(0,1)+s2*N(0,2);
    t1 =s0*N(1,0)+s1*N(1,1)+s2*N(1,2);
    t2 =s0*N(2,0)+s1*N(2,1)+s2*N(2,2);
    M(0,2) = t0;M(1,2) = t1;M(2,2) = t2;
    #undef M
    #undef N
}

void B3L_MakeScaleMatrix(f32 scaleX,f32 scaleY,f32 scaleZ,mat4_t *pMat){
    #define M(x,y) (pMat)->m##x##y

    M(0,0) = scaleX; M(1,0) = 0.0f;   M(2,0) = 0.0f;   M(3,0) = 0.0f; 
    M(0,1) = 0.0f;   M(1,1) = scaleY; M(2,1) = 0.0f;   M(3,1) = 0.0f; 
    M(0,2) = 0.0f;   M(1,2) = 0.0f;   M(2,2) = scaleZ; M(3,2) = 0.0f; 
    M(0,3) = 0.0f;   M(1,3) = 0.0f;   M(2,3) = 0.0f;   M(3,3) = 1.0f; 

    #undef M
}

void B3L_MakeTranslationMat(f32 offsetX,f32 offsetY,f32 offsetZ,mat4_t *pMat){
    #define M(x,y) (pMat)->m##x##y
    f32 one = 1.0f;
    M(0,0) = one; M(1,0) = 0.0f; M(2,0) = 0.0f; M(3,0) = 0.0f; 
    M(0,1) = 0.0f; M(1,1) = one; M(2,1) = 0.0f; M(3,1) = 0.0f; 
    M(0,2) = 0.0f; M(1,2) = 0.0f; M(2,2) = one; M(3,2) = 0.0f; 
    M(0,3) = offsetX; M(1,3) = offsetY; M(2,3) = offsetZ; M(3,3) = one;
    #undef M
}

void B3L_MakeO2CMatrix(mat3_t *pRMat,vect3_t *pScale,vect3_t *pTrans,mat4_t *pCamMat, mat4_t *pResult){

    f32 t0,t1,t2,t3;
    f32 s0,s1,s2;
    #define M(x,y) (pRMat)->m##x##y
    #define N(x,y) (pCamMat)->m##x##y
    #define O(x,y) (pResult)->m##x##y
    f32 scaleVal = pScale->x;
    s0=M(0,0)*scaleVal;s1=M(1,0)*scaleVal;s2=M(2,0)*scaleVal;
    t0 = s0*N(0,0)+s1*N(0,1)+s2*N(0,2);
    t1 = s0*N(1,0)+s1*N(1,1)+s2*N(1,2);
    t2 = s0*N(2,0)+s1*N(2,1)+s2*N(2,2);
    t3 = s0*N(3,0)+s1*N(3,1)+s2*N(3,2);
    O(0,0) = t0;O(1,0) = t1;O(2,0) = t2;O(3,0) = t3;
    scaleVal = pScale->y;
    s0=M(0,1)*scaleVal;s1=M(1,1)*scaleVal;s2=M(2,1)*scaleVal;
    t0 =s0*N(0,0)+s1*N(0,1)+s2*N(0,2);
    t1 =s0*N(1,0)+s1*N(1,1)+s2*N(1,2);
    t2 =s0*N(2,0)+s1*N(2,1)+s2*N(2,2);
    t3 =s0*N(3,0)+s1*N(3,1)+s2*N(3,2);
    O(0,1) = t0;O(1,1) = t1;O(2,1) = t2;O(3,1) = t3;
    scaleVal = pScale->z;
    s0=M(0,2)*scaleVal;s1=M(1,2)*scaleVal;s2=M(2,2)*scaleVal;
    t0 =s0*N(0,0)+s1*N(0,1)+s2*N(0,2);
    t1 =s0*N(1,0)+s1*N(1,1)+s2*N(1,2);
    t2 =s0*N(2,0)+s1*N(2,1)+s2*N(2,2);
    t3 =s0*N(3,0)+s1*N(3,1)+s2*N(3,2);
    O(0,2) = t0;O(1,2) = t1;O(2,2) = t2;O(3,2) = t3;
    s0=pTrans->x;s1=pTrans->y;s2=pTrans->z;
    t0 = s0*N(0,0)+s1*N(0,1)+s2*N(0,2)+N(0,3);
    t1 = s0*N(1,0)+s1*N(1,1)+s2*N(1,2)+N(1,3);
    t2 = s0*N(2,0)+s1*N(2,1)+s2*N(2,2)+N(2,3);
    t3 = s0*N(3,0)+s1*N(3,1)+s2*N(3,2)+N(3,3);
    O(0,3) = t0;O(1,3) = t1;O(2,3) = t2;O(3,3) = t3;
    #undef M
    #undef N
    #undef O

}


__attribute__((always_inline)) static  inline zBuff_t CalZbuffValue(f32 z){
             #if  (Z_BUFF_LEVEL == 0) 
            u32 tempZ = B3L_RoundingToU(z*255.0f);
            u8  compZ = SatToU8(tempZ);
            #endif
            #if (Z_BUFF_LEVEL == 1)
            u32 tempZ = B3L_RoundingToU(z*65535.0f);
            u16 compZ = SatToU16(tempZ);
            #endif
            #if (Z_BUFF_LEVEL == 2)
            f32 compZ = z;           
            #endif 
            return compZ;
}
/*-----------------------------------------------------------------------------
Triangle testing functions
-----------------------------------------------------------------------------*/
__attribute__((always_inline)) static inline bool TriangleFaceToViewer_f(f32 x0, f32 y0, f32 x1, f32 y1, f32 x2, f32 y2){
  f32 winding =
    (x1 - x0) * (y2 - y0) - (y1 - y0) * (x2 - x0) ;
    // ^ cross product for points with z == 0

  return winding >= 0.0f ? true : false;
}

__attribute__((always_inline)) static  inline bool TriVisable(u32 r0,u32 r1,u32 r2){
    bool returnVal=true;
    //u32 nearPlaneCount = 0;
    //u32 inSpaceCount = 0;

    if(B3L_TEST(r0,B3L_IN_SPACE)||B3L_TEST(r1,B3L_IN_SPACE)||B3L_TEST(r2,B3L_IN_SPACE)){
        //test near plan
        if (B3L_TEST(r0,B3L_NEAR_PLANE_CLIP)||B3L_TEST(r1,B3L_NEAR_PLANE_CLIP)||B3L_TEST(r2,B3L_NEAR_PLANE_CLIP)){
            returnVal= false;
        }
    }else{
        returnVal= false;
    }
    return returnVal;
    
}
/*-----------------------------------------------------------------------------
light functions
-----------------------------------------------------------------------------*/
void B3L_ResetLight(light_t *pLight){
    B3L_CLR(pLight->state,LIGHT_TYPE_BIT); //parallel light
    B3L_VECT3_SET(pLight->lightVect,0.0f,1.0f,0.0f);
    pLight->color = 0xFF000000;
    pLight->factor_0 = 1.01f; //make sure it is larger than 0, now the range is 0.01~2.01
    pLight->factor_1 =126.7f;

}

__attribute__((always_inline)) static inline u32 CalLightFactor(f32 normalDotLight, f32 lightFactor0,f32 lightFactor1){
    s32 lightValue;
    normalDotLight += lightFactor0;
    lightValue =B3L_RoundingToS(normalDotLight*lightFactor1);
    lightValue = B3L_MAX(lightValue,0);
#if FRAME_BUFF_COLOR_TYPE == 1
    lightValue = lightValue>>4; //only use high 4 bit
#endif
    return lightValue;
}

void B3L_SetLightType(render_t *pRender,lightType_e type){
    if (parallelLight == type ){
        B3L_CLR(pRender->light.state,LIGHT_TYPE_BIT);
    }
    if (dotLight == type ){
        B3L_SET(pRender->light.state,LIGHT_TYPE_BIT);
    }
}

void B3L_SetLightVect(render_t *pRender, f32 x,f32 y,f32 z){
    if (B3L_TEST(pRender->light.state,LIGHT_TYPE_BIT) == PARALLEL_LIGHT){//parallel light
        //normalized the vector
        f32 invSqrt = FastInvertSqrt(x*x+y*y+z*z);
        x = x*invSqrt;
        y = y*invSqrt;
        z = z*invSqrt;
    }
    B3L_VECT3_SET(pRender->light.lightVect,x,y,z);
}
/*-----------------------------------------------------------------------------
Camera functions
-----------------------------------------------------------------------------*/
void B3L_InitCamera(render_t *pRender){
    camera_t *pCam = &(pRender->camera);
    pCam->aspectRate = DEFAULT_ASPECT_RATIO;
    pCam->focalLength = DEFAULT_FOCUS_LENGTH;
    B3L_VECT3_SET(pCam->transform.scale,1.0f,1.0f,1.0f);
    B3L_VECT3_SET(pCam->transform.translation,0.0f,0.0f,0.0f);
    B3L_InitUnitMat3(&(pCam->mat));
    B3L_VECT4_SET(pCam->transform.quaternion,0.0f,0.0f,0.0f,1.0f);
    pCam->pTrackObj = (B3LObj_t *)NULL;
    
    MakeClipMatrix(pCam->state,pRender->nearPlane,pRender->farPlane,pCam->focalLength,pCam->aspectRate,&(pCam->clipMat));
    //printf("after init clip matrix:\n");
    //B3L_logMat4(pCam->clipMat);
    pCam->state = 0; //default is PERSPECTIVE_PROJECT
}

void B3L_SetOrthographicProject(render_t *pRender){
    B3L_SET(pRender->camera.state,B3L_PROJECT_MODE);
    B3L_UpdateClipMatrix(pRender);
}

void B3L_SetPerspectiveProject(render_t *pRender){
    B3L_CLR(pRender->camera.state,B3L_PROJECT_MODE);
    B3L_UpdateClipMatrix(pRender);
}

void B3L_UpdateClipMatrix(render_t *pRender){
    camera_t *pCam = &(pRender->camera);
    MakeClipMatrix(pCam->state,pRender->nearPlane,pRender->farPlane,pCam->focalLength,pCam->aspectRate,&(pCam->clipMat));
}

void B3L_CamSetFocusLengthByFOV(render_t *pRender, f32 fov){
    f32 halfFOV = 0.5f*fov;
    f32 sinh = B3L_sin(halfFOV);
    f32 cosh = B3L_cos(halfFOV);
    pRender->camera.focalLength = cosh/sinh;
    B3L_UpdateClipMatrix(pRender);
}

static void GenerateW2CMatrix(camera_t *pCam){
    mat3_t *pMat3 = &(pCam->mat);
    mat4_t *pW2CMat = &(pCam->camW2CMat);
    f32 x = -(pCam->transform.translation.x);
    f32 y = -(pCam->transform.translation.y);
    f32 z = -(pCam->transform.translation.z);
    //get the shift by translation
    f32 zero = 0.0f;
    pW2CMat->m33 = 1.0f;pW2CMat->m30 = zero;pW2CMat->m31 = zero;pW2CMat->m32 = zero;
    pW2CMat->m00 = pMat3->m00;pW2CMat->m01 = pMat3->m10;pW2CMat->m02 = pMat3->m20;
    pW2CMat->m10 = pMat3->m01;pW2CMat->m11 = pMat3->m11;pW2CMat->m12 = pMat3->m21;
    pW2CMat->m20 = pMat3->m02;pW2CMat->m21 = pMat3->m12;pW2CMat->m22 = pMat3->m22;
    pW2CMat->m03 = x*pW2CMat->m00 + y*pW2CMat->m01 + z*pW2CMat->m02;
    pW2CMat->m13 = x*pW2CMat->m10 + y*pW2CMat->m11 + z*pW2CMat->m12;
    pW2CMat->m23 = x*pW2CMat->m20 + y*pW2CMat->m21 + z*pW2CMat->m22;
}


void B3L_CameraMoveTo(vect3_t position,camera_t *pCam){
    pCam->transform.translation.x = position.x;
    pCam->transform.translation.y = position.y;
    pCam->transform.translation.z = position.z;
}


void B3L_CameraLookAt(camera_t *pCam, vect3_t *pAt,vect3_t *pUp){
    B3L_SET(pCam->state,CAM_NEED_MATRIX_UPDATE);
    B3L_CreateLookAtQuaternion(&(pCam->transform.translation), 
                                pAt, pUp, &(pCam->transform.quaternion));
}

void B3L_CamStopTrack(camera_t *pCam){
    B3L_CLR(pCam->state,B3L_CAMERA_TRACK_OBJ_MODE);
}

void B3L_CamStartTrack(camera_t *pCam){
    B3L_SET(pCam->state,B3L_CAMERA_TRACK_OBJ_MODE);
}


void B3L_CamInitTrack(camera_t *pCam,B3LObj_t *pObj,f32 camX,f32 camY,f32 camZ,f32 lookAtX,f32 lookAtY,f32 lookAtZ){
    //B3L_SET(pCam->state,B3L_CAMERA_TRACK_OBJ_MODE);
    pCam->pTrackObj = pObj;
    pCam->targetPosition.x = camX;
    pCam->targetPosition.y = camY;
    pCam->targetPosition.z = camZ;
    vect3_t from = {camX,camY,camZ};
    vect3_t at = {lookAtX,lookAtY,lookAtZ};
    vect3_t up = {0.0f,1.0f,0.0f};
    B3L_CreateLookAtQuaternion(&from, &at, &up, &(pCam->targetQuat));
    //printf("target quat:");
    //B3L_logVec4(pCam->targetQuat);
}

static void CamCalNewTrackPosition(camera_t *pCam){
    B3LObj_t *pObj = pCam->pTrackObj;
    if (B3L_TEST(pObj->state,OBJ_NEED_MATRIX_UPDATE)){
        //update it's matrix and clear the flag
        B3L_QuaternionToMatrix(&(pObj->transform.quaternion), &(pObj->mat));
        B3L_CLR(pObj->state,OBJ_NEED_MATRIX_UPDATE);
    }
    vect3_t result;
    B3L_Vect3MulMat3(&(pCam->targetPosition), &(pObj->mat), &result);

    B3L_Vect3Add(&result,&(pObj->transform.translation),&(pCam->transform.translation));
}

static void CamCalNewTrackQuaternion(camera_t *pCam){
    quat4_t targetQuat;
    B3LObj_t *pObj = pCam->pTrackObj;
    if(B3L_TEST(pObj->state,OBJ_NEED_QUAT_UPDATE)){
        //update it's matrix and clear the flag
        B3L_MatrixToQuaternion( &(pObj->mat),&(pObj->transform.quaternion));
        B3L_CLR(pObj->state,OBJ_NEED_QUAT_UPDATE);
    }
    B3L_QuatMult(&(pObj->transform.quaternion),&(pCam->targetQuat), &targetQuat);
    //now the targetQuat in world space
    f32 cosHalfAngel = B3L_QuatDot(&targetQuat,&(pCam->transform.quaternion));
    f32 t = (1.0f - B3L_Absf(cosHalfAngel))*8.0f;
    B3L_QuaternionInterp(&(pCam->transform.quaternion), &targetQuat ,&(pCam->transform.quaternion), t);
    B3L_SET(pCam->state,CAM_NEED_MATRIX_UPDATE);
    //printf("new quat:");
    //B3L_logVec4(pCam->transform.quaternion);
}


static void  UpdateCam(render_t *pRender){
    camera_t *pCam = &(pRender->camera);
    if(B3L_TEST(pCam->state,B3L_CAMERA_TRACK_OBJ_MODE)){
        CamCalNewTrackPosition(pCam);
        CamCalNewTrackQuaternion(pCam);
        //printf("current camera position:");
        //B3L_logVec3(pCam->transform.translation);
    }
    if(B3L_TEST(pCam->state,CAM_NEED_MATRIX_UPDATE)){
        B3L_QuaternionToMatrix(&(pCam->transform.quaternion), &(pCam->mat));
        B3L_CLR(pCam->state,CAM_NEED_MATRIX_UPDATE);
    }
    GenerateW2CMatrix(&(pRender->camera));
    B3L_Mat4XMat4(&(pCam->camW2CMat),&(pCam->clipMat),&(pCam->camW2CMat));  
    //printf("clip mat:");
    //B3L_logMat4(pCam->clipMat);
    //printf("W2C mat:");
    //B3L_logMat4(pCam->camW2CMat);
}
/*-----------------------------------------------------------------------------
obj functions
-----------------------------------------------------------------------------*/
#ifdef B3L_USING_PARTICLE
static void UpdateParticleObjs(render_t *pRender, u32 time){
    B3LObj_t  *pCurrentObj =(pRender->scene.pActiveParticleGenObjs);
    u32 state;
    while(pCurrentObj != (B3LObj_t  *)NULL){
        state = pCurrentObj->state;
        //only update those active particle generater
        if (B3L_TEST(state ,OBJ_PARTICLE_ACTIVE)==0){  //obj active is fail
            pCurrentObj = pCurrentObj->next;
            continue;
        }
        if (B3L_TEST(state,OBJ_NEED_MATRIX_UPDATE)){
            //update the matrix from quat4
            B3L_QuaternionToMatrix(&(((B3LParticleGenObj_t *)pCurrentObj)->transform.quaternion), &(pCurrentObj->mat));
            B3L_CLR(pCurrentObj->state,OBJ_NEED_MATRIX_UPDATE);
        }
        ((B3LParticleGenObj_t *)pCurrentObj)->PtlUpdFunc(time,(B3LParticleGenObj_t *)pCurrentObj,
                                                         &(((B3LParticleGenObj_t *)pCurrentObj)->mat),
                                                         &(((B3LParticleGenObj_t *)pCurrentObj)->transform.translation),
                                                         pRender);   
        pCurrentObj = pCurrentObj->next;    
    }
}

static void RenderParticleObjs(render_t *pRender) {
    B3LObj_t  *pCurrentObj =(pRender->scene.pActiveParticleGenObjs);
    u32 state;
    mat4_t *pcamW2CMat = &(pRender->camera.camW2CMat);
    screen4_t screenVect;
    u32 i;
    B3L_Particle_t *pParticle;
    fBuff_t *pFBuff = pRender->pFrameBuff;
    zBuff_t *pZBuff = pRender->pZBuff;

    while(pCurrentObj != (B3LObj_t  *)NULL){
        B3L_DrawFunc_t DrawFunc = ((B3LParticleGenObj_t *)pCurrentObj)->DrawFunc;
        state = pCurrentObj->state;
        i =((B3LParticleGenObj_t *)pCurrentObj)->particleNum;
        if ((B3L_TEST(state ,OBJ_VISUALIZABLE)==0)||(i == 0)){  //obj visual is false, or no particle is alive
            pCurrentObj = (pCurrentObj->next);
            continue;
        }
       
        pParticle = ((B3LParticleGenObj_t *)pCurrentObj)->pParticleActive;     
        //project the particle from world space to screen space
        while(i--){
            Vect3Xmat4WithTestToScreen4(&(pParticle->position), pcamW2CMat, &screenVect);
            //get the screen position
            u32 test = screenVect.test;
            if (B3L_TEST(test,B3L_IN_SPACE)){
                //draw it
                //((B3LParticleGenObj_t *)pCurrentObj)->DrawFunc(pParticle,&screenVect,pFBuff,pZBuff);
                DrawFunc(pParticle,&screenVect,pFBuff,pZBuff);
            } 
            pParticle = pParticle->next;
        }
        pCurrentObj = pCurrentObj->next;    
    }
}

void B3L_UpdateAllParticlesStatesInGen(render_t *pRender,B3LParticleGenObj_t *pGen,u32 deltaTime,vect3_t *pForce){
    u32 i = pGen->particleNum ;
    B3L_Particle_t *pParticle = pGen->pParticleActive;
    B3L_Particle_t *pPrevParticle = pGen->pParticleActive;
    vect3_t deltadelta;
    while(i--){
        pParticle->life -= deltaTime;
        if (pParticle->life <= 0){
            //dead particle, remove it back to the free particle pool
            if (pGen->pParticleActive == pParticle){ //the first one
                pGen->pParticleActive = pParticle->next;
            }else{
                pPrevParticle->next = pParticle->next;                    
            }           
            pGen->particleNum -=1;  
            B3L_ReturnParticleToPool(pParticle,&(pRender->scene));
            pParticle = pPrevParticle->next;
        }else{
            B3L_Vect3Scale(pForce,(f32)deltaTime,&deltadelta);
            Vect3_Add(&(pParticle->delta), &deltadelta ,&(pParticle->delta));//update the delta
            B3L_Vect3Scale(&(pParticle->delta),(f32)deltaTime,&deltadelta);
            Vect3_Add(&(pParticle->position),&(deltadelta),&(pParticle->position));//update the position
            pPrevParticle = pParticle;
            pParticle = pParticle->next;
        }            
    }
}



#endif

static bool Vect3InClipSpace(vect3_t *pV, mat4_t *pMat){
    vect4_t output;
    Vect3Xmat4(pV, pMat, &output);
    return Vect4BoundTest( &output);
}

static bool BoundBoxTest(f32 *pMaxMin,mat4_t *pMat){
    bool result;
    f32 maxX = pMaxMin[0];f32 maxY = pMaxMin[1];f32 maxZ = pMaxMin[2];
    f32 minX = pMaxMin[3];f32 minY = pMaxMin[4];f32 minZ = pMaxMin[5];
    //test 8 point
    vect3_t testV;
    B3L_VECT3_SET(testV,maxX,maxY,maxZ);result = Vect3InClipSpace(&testV,pMat);
    if (result == true){return true;}
    B3L_VECT3_SET(testV,maxX,maxY,minZ);result = Vect3InClipSpace(&testV,pMat);
    if (result == true){return true;}
    B3L_VECT3_SET(testV,maxX,minY,minZ);result = Vect3InClipSpace(&testV,pMat);
    if (result == true){return true;}
    B3L_VECT3_SET(testV,minX,minY,minZ);result = Vect3InClipSpace(&testV,pMat);
    if (result == true){return true;}
    B3L_VECT3_SET(testV,minX,minY,maxZ);result = Vect3InClipSpace(&testV,pMat);
    if (result == true){return true;}
    B3L_VECT3_SET(testV,minX,maxY,maxZ);result = Vect3InClipSpace(&testV,pMat);
    if (result == true){return true;}
    B3L_VECT3_SET(testV,maxX,minY,maxZ);result = Vect3InClipSpace(&testV,pMat);
    if (result == true){return true;}
    B3L_VECT3_SET(testV,minX,maxY,minZ);result = Vect3InClipSpace(&testV,pMat);
    return result;
}

static void RenderMeshObjs(render_t *pRender){
    mat4_t mat; //64 byte
    u32 state;
    u32 renderLevel;
    f32 distance;
//get the list enter point obj
    B3LObj_t *pCurrentObj = pRender->scene.pActiveMeshObjs;
//printf("start draw obj\n");
    f32 lvl0Distance = pRender->lvl0Distance;
    f32 lvl1Distance = pRender->lvl1Distance;
    while(pCurrentObj != (B3LObj_t *)NULL){ 
        state = pCurrentObj->state;
        if (B3L_TEST(state ,OBJ_VISUALIZABLE)==0){  //obj visual is false
            pCurrentObj = pCurrentObj->next;
            continue;
        }
        //create the obj->clip matrix  
        if (B3L_TEST(state,OBJ_NEED_MATRIX_UPDATE)){
            B3L_QuaternionToMatrix(&(pCurrentObj->transform.quaternion), &(pCurrentObj->mat));
            B3L_CLR(pCurrentObj->state,OBJ_NEED_MATRIX_UPDATE);
        }
        B3L_MakeO2CMatrix(&(pCurrentObj->mat),&(pCurrentObj->transform.scale),
                          &(pCurrentObj->transform.translation),&(pRender->camera.camW2CMat), &mat);
        //test boundBoxTestFactor to check if the obj out of clip range
        if (BoundBoxTest(pCurrentObj->pBoundBox,&mat)!= true){  //all points outside the clip range
            pCurrentObj = pCurrentObj->next;
            continue;
        }
        //calculate the distance
        f32 x = mat.m03;
        f32 y = mat.m13;
        f32 z = mat.m23;
        distance = B3L_Sqrtf(x*x+y*y+z*z);
        //decide render level info        
        if (B3L_TEST(state ,OBJ_IGNORE_RENDER_LEVEL)){
            renderLevel = (state & OBJ_RENDER_LEVEL_MASK)>>OBJ_FIX_RENDER_LEVEL_SHIFT;
        }else{
            if (distance < lvl0Distance){
                renderLevel = 0;
            }else if (distance < lvl1Distance){
                renderLevel = 1;
            }else{
                renderLevel = 2;
            }            
        }
        switch(state & OBJ_TYPE_MASK){
            case (1<<MESH_OBJ):
                RenderTexMesh((B3LMeshObj_t *)pCurrentObj,pRender,&mat,renderLevel);
                break;
            case (1<<POLYGON_OBJ):
                RenderPolygon((B3LPolygonObj_t *)pCurrentObj,pRender,&mat);
                break;
            case (1<<NOTEX_MESH_OBJ):                
                RenderNoTexMesh((B3LMeshNoTexObj_t *)pCurrentObj,pRender,&mat,renderLevel);
                break;
        }      
        //point to the next obj
        pCurrentObj = pCurrentObj->next;
    }

}

void B3L_RenderScence(render_t *pRender){
    //from camera's rotation matrix to create world -> clip space matrix
    UpdateCam(pRender);
    RenderMeshObjs(pRender);
#ifdef B3L_USING_PARTICLE
    RenderParticleObjs(pRender);
#endif

}

void B3L_Update(render_t *pRender,u32 time){
    static u32 oldTime = 0;
    if (oldTime == 0) {//first time run
      oldTime = time;
    }
    u32 deltaTime = time - oldTime;
    if (deltaTime >= B3L_UPDATE_CYCLE){//if the time is longer than the limit for update
#ifdef B3L_USING_PARTICLE
        UpdateParticleObjs(pRender, time);
#endif
        oldTime = time;//update oldTime only it is run the update codes
    }
    //TODO: Add particle update and other hook here
}

void B3L_NewRenderStart(render_t *pRender,fBuff_t color){
    #if B3L_DMA2D == 0
    ClearFrameBuff(pRender->pFrameBuff,color,RENDER_RESOLUTION_Y,RENDER_RESOLUTION_X,RENDER_LINE_SKIP);
    //ClearFrameBuff(pRender->pFrameBuff,0xFF003423,Z_BUFF_LENTH);//need to add shift
    ClearZbuff(pRender->pZBuff,Z_BUFF_LENTH);//need to add shift
    #else
    B3L_CLEAN_FRAME_COLOR = color;
    #endif   //if DMA2D == 1, the clean work would be done by DMA2D
}    

void B3L_ResetScene(scene_t *pScene){
    pScene->freeObjNum = OBJ_BUFF_SIZE; //reset free obj numbers
    pScene->pActiveMeshObjs = (B3LObj_t *)NULL; //reset active obj list
    ResetObjList(pScene);
#ifdef B3L_USING_PARTICLE
    pScene->pActiveParticleGenObjs = (B3LObj_t *)NULL;//reset particle generator obj list 
    pScene->freeParticleNum = B3L_PARTICLE_BUFF_DEPTH;   //reset particle numbers
    ResetParticleList(particleBuff,&(pScene->pfreeParticles),B3L_PARTICLE_BUFF_DEPTH); //reset particle list
    //call reset particle one-way list function
#endif
}

static void ResetObjList(scene_t *pScene){
    u32 i;
    pScene->pFreeObjs = pScene->objBuff;  //reset all the obj buffer
    pScene->objBuff[0].state = 0x00000000;
    pScene->objBuff[0].privous = pScene->pFreeObjs;
    pScene->objBuff[0].next= &(pScene->objBuff[1]);
    for (i = 1;i<OBJ_BUFF_SIZE;i++){
        pScene->objBuff[i].state = 0x00000000;
        pScene->objBuff[i].privous = &(pScene->objBuff[i-1]);
        pScene->objBuff[i].next = &(pScene->objBuff[i+1]);
    }
    pScene->objBuff[OBJ_BUFF_SIZE - 1].next = (B3LObj_t *)NULL;
}

#ifdef B3L_USING_PARTICLE
static void ResetParticleList(B3L_Particle_t *pPool,B3L_Particle_t **pStart,u32 num){
    u32 i;
    *pStart = pPool;
    for (i=0;i<(num-1);i++){
        pPool->state = 0x00000000;
        pPool[i].next = &(pPool[i+1]);
    }
    pPool[(num-1)].next = (B3L_Particle_t *)NULL;

}

void B3L_ReturnParticleToPool(B3L_Particle_t *pParticle,scene_t *pScene){
    
    B3L_Particle_t *temp=pScene->pfreeParticles;
    pParticle->state = 0x00000000;
    pScene->pfreeParticles = pParticle;
    pParticle->next = temp;
    pScene->freeParticleNum +=1;
}

void B3L_AddParticleToGenerator(B3L_Particle_t *pParticle,B3LParticleGenObj_t  *pGenerator){
    B3L_Particle_t *pTemp = pGenerator->pParticleActive;
    pGenerator->pParticleActive = pParticle;
    pParticle->next = pTemp;
    pGenerator->particleNum +=1;
}


B3L_Particle_t *B3L_GetFreeParticle(scene_t *pScene){
    //todo
    if (pScene->freeParticleNum == 0){
        return (B3L_Particle_t *)NULL;
    }
    pScene->freeParticleNum --;
    B3L_Particle_t *popParticle = pScene->pfreeParticles;
    pScene->pfreeParticles = pScene->pfreeParticles->next;
    return popParticle;
}
#endif

static void AddObjToTwoWayList(B3LObj_t *pObj, B3LObj_t **pStart){
    pObj->next = *pStart;
    *pStart = pObj;
    pObj->privous = pObj;
    if (pObj->next != (B3LObj_t *)NULL){
        pObj->next->privous = pObj;       
    }   
}

u32 B3L_GetFreeObjNum(render_t *pRender){
    return pRender->scene.freeObjNum;
}

u32 B3L_GetFreeParticleNum(render_t *pRender){
    #ifdef  B3L_USING_PARTICLE 
    return pRender->scene.freeParticleNum;
    #else
    return 0;
    #endif
}

B3LObj_t * B3L_GetFreeObj(render_t *pRender){
    B3LObj_t *returnObj;
    if (pRender->scene.pFreeObjs != (B3LObj_t *)NULL){
        pRender->scene.freeObjNum -=1;
        returnObj = pRender->scene.pFreeObjs;
        pRender->scene.pFreeObjs = pRender->scene.pFreeObjs->next;
        pRender->scene.pFreeObjs->privous = pRender->scene.pFreeObjs;
        //isolate the returned obj 
        returnObj->next = (B3LObj_t *)NULL;
        returnObj->privous = (B3LObj_t *)NULL;
        returnObj->state = 0;
        B3L_VECT4_SET(returnObj->transform.quaternion,0.0f,0.0f,0.0f,1.0f);
        B3L_VECT3_SET(returnObj->transform.scale,1.0f,1.0f,1.0f);
        B3L_VECT3_SET(returnObj->transform.translation,0.0f,0.0f,0.0f);
        B3L_InitUnitMat3(&(returnObj->mat));
        return returnObj;
    }else{
        return (B3LObj_t *)NULL;
    }
}

B3LMeshObj_t *B3L_GetFreeMeshObj(render_t *pRender){
    B3LObj_t *pObj = B3L_GetFreeObj(pRender);
    if (pObj !=  (B3LObj_t *)NULL){
        B3L_SET(pObj->state,MESH_OBJ);
        B3L_SET(pObj->state,OBJ_VISUALIZABLE);
    }
    return (B3LMeshObj_t *)pObj;
}

B3LMeshNoTexObj_t *B3L_GetFreeMeshNoTexObj(render_t *pRender){
    B3LObj_t *pObj = B3L_GetFreeObj(pRender);
    if (pObj !=  (B3LObj_t *)NULL){
        B3L_SET(pObj->state,NOTEX_MESH_OBJ);
        B3L_SET(pObj->state,OBJ_VISUALIZABLE);
    }
    return (B3LMeshNoTexObj_t *)pObj;
}

B3LPolygonObj_t    *B3L_GetFreePolygonObj(render_t *pRender){
    B3LObj_t *pObj = B3L_GetFreeObj(pRender);
    if (pObj !=  (B3LObj_t *)NULL){
        B3L_SET(pObj->state,POLYGON_OBJ);
        B3L_SET(pObj->state,OBJ_VISUALIZABLE);       
    }
    return (B3LPolygonObj_t *)pObj;
}

B3LParticleGenObj_t  *B3L_GetFreeParticleGeneratorObj(render_t *pRender){
    B3LObj_t *pObj = B3L_GetFreeObj(pRender);
    if (pObj !=  (B3LObj_t *)NULL){
        B3L_SET(pObj->state,PARTICLE_GEN_OBJ);
        B3L_SET(pObj->state,OBJ_VISUALIZABLE);
        B3L_SET(pObj->state,OBJ_PARTICLE_ACTIVE);
        ((B3LParticleGenObj_t  *)pObj)->particleNum = 0;
        ((B3LParticleGenObj_t  *)pObj)->pParticleActive = (B3L_Particle_t *)NULL;
        ((B3LParticleGenObj_t  *)pObj)->lastTime = 0;
    }
    return (B3LParticleGenObj_t  *)pObj;
}

void B3L_AddObjToRenderList(B3LObj_t *pObj, render_t *pRender){
    //get the statement
    u32 type = (pObj->state & OBJ_TYPE_MASK);

    if ((type == (1<<MESH_OBJ))||(type == (1<<POLYGON_OBJ))||(type == (1<<NOTEX_MESH_OBJ))){
        AddObjToTwoWayList(pObj, &(pRender->scene.pActiveMeshObjs));    
    }
    #ifdef B3L_USING_PARTICLE
    if (type == (1<<PARTICLE_GEN_OBJ)){
        AddObjToTwoWayList(pObj, &(pRender->scene.pActiveParticleGenObjs)); 
    }
    #endif  
}

void B3L_PopObjFromRenderList(B3LObj_t *pObj, render_t *pRender){
    if (pObj->privous != pObj){
        if (pObj->next != (B3LObj_t *)NULL){
            pObj->next->privous = pObj->privous;
        }
        pObj->privous->next = pObj->next; 
    }else{
        u32 type = (pObj->state & OBJ_TYPE_MASK);
        if ((type == (1<<MESH_OBJ))||(type == (1<<POLYGON_OBJ))||(type == (1<<NOTEX_MESH_OBJ))){
            pRender->scene.pActiveMeshObjs = pObj->next;
            if (pObj->next != (B3LObj_t *)NULL){
                pObj->next->privous = pRender->scene.pActiveMeshObjs;
            }
        }
        #ifdef B3L_USING_PARTICLE
        if (type == (1<<PARTICLE_GEN_OBJ)){
            pRender->scene.pActiveParticleGenObjs = pObj->next;
            if (pObj->next != (B3LObj_t *)NULL){
                pObj->next->privous = pRender->scene.pActiveParticleGenObjs;
            }
        }
        #endif       
    }   
    pObj->next = (B3LObj_t *)NULL;
    pObj->privous = (B3LObj_t *)NULL;
}

void B3L_ReturnObjToInactiveList(B3LObj_t *pObj,  render_t *pRender){
    if (pObj->privous != (B3LObj_t *)NULL){ //it is now in the active list
        B3L_PopObjFromRenderList(pObj,  pRender);
    }
    //clean the obj statement
    pObj->state = 0x00000000;
    pRender->scene.freeObjNum +=1;
    AddObjToTwoWayList(pObj, &(pRender->scene.pFreeObjs));
}

void B3L_RenderInit(render_t *pRender,fBuff_t *pFrameBuff){
    pRender->pFrameBuff = pFrameBuff;
    pRender->pZBuff = zBuff;
    pRender->pVectBuff = vectBuff;
    pRender->lvl0Distance = LEVEL_0_DEFAULT_DISTANCE;
    pRender->lvl1Distance = LEVEL_1_DEFAULT_DISTANCE;
    pRender->lvl1Light = LEVEL_1_DEFAULT_LIGHT;
    pRender->farPlane = DEFAULT_FAR_PLANE;
    pRender->nearPlane = DEFAULT_NEAR_PLANE;
    B3L_ResetScene(&(pRender->scene));
    B3L_InitCamera(pRender);
    B3L_ResetLight(&(pRender->light));
}
/*-----------------------------------------------------------------------------
Draw functions
-----------------------------------------------------------------------------*/
__attribute__((always_inline)) static  inline fBuff_t     GetColorValue(texLUT_t *lut,u8 colorIdx,u32 lightFactor){
    fBuff_t color;
    color = lut[colorIdx];
    color = GetFinalColor(color,lightFactor);
    return color;
}

__attribute__((always_inline)) static  inline void     DrawPixel(fBuff_t color,s32 x,s32 y,f32 z,
                                                                        fBuff_t *pFrameBuff,zBuff_t *pZbuff){
        zBuff_t *pCurrentPixelZ = pZbuff + (y*RENDER_RESOLUTION_X) + x;
        fBuff_t *pixel= pFrameBuff + (y*RENDER_X_SHIFT) + x; 
        zBuff_t compZ = CalZbuffValue(z);
        if (compZ<= *pCurrentPixelZ){          
            *pCurrentPixelZ = compZ;
            *pixel =color;           
        }
}

__attribute__((always_inline)) static  inline void     DrawPixelWithTest(fBuff_t color,s32 x,s32 y,f32 z,
                                                                        fBuff_t *pFrameBuff,zBuff_t *pZbuff){
        if ((x<0)||(y<0)||(x>=RENDER_RESOLUTION_X)||(y>=RENDER_RESOLUTION_Y)){
            return;
        }
        zBuff_t *pCurrentPixelZ = pZbuff + (y*RENDER_RESOLUTION_X) + x;
        fBuff_t *pixel= pFrameBuff + (y*RENDER_X_SHIFT) + x; 
        zBuff_t compZ = CalZbuffValue(z);
        if (compZ<= *pCurrentPixelZ){          
            *pCurrentPixelZ = compZ;
            *pixel =color;           
        }
}

static void ClearFrameBuff(fBuff_t *pFramebuff,fBuff_t value,u32 lineNum,u32 lineLength,u32 lineSkip){
//in stm32, we could use DMA to do this job   
    int32_t i;   
    u32  lineNumDiv16Left = lineLength&0x0000000F;
    #define Addr pFramebuff
    //fBuff_t value = 0;
    while(lineNum--){
        i=(lineLength>>4);
        while(i--){
            *Addr = value;Addr++;*Addr = value;Addr++;*Addr = value;Addr++;
            *Addr = value;Addr++;*Addr = value;Addr++;*Addr = value;Addr++;
            *Addr = value;Addr++;*Addr = value;Addr++;*Addr = value;Addr++;
            *Addr = value;Addr++;*Addr = value;Addr++;*Addr = value;Addr++;
            *Addr = value;Addr++;*Addr = value;Addr++;*Addr = value;Addr++;
            *Addr = value;Addr++;
        }
        switch(lineNumDiv16Left){
        case 15:*Addr = value;Addr++;
        case 14:*Addr = value;Addr++;
        case 13:*Addr = value;Addr++;
        case 12:*Addr = value;Addr++;
        case 11:*Addr = value;Addr++;
        case 10:*Addr = value;Addr++;
        case 9:*Addr = value;Addr++;
        case 8:*Addr = value;Addr++;
        case 7:*Addr = value;Addr++;
        case 6:*Addr = value;Addr++;
        case 5:*Addr = value;Addr++;
        case 4:*Addr = value;Addr++;    
        case 3:*Addr = value;Addr++;
        case 2:*Addr = value;Addr++;
        case 1:*Addr = value;Addr++;
        case 0:break;
        }
        Addr +=lineSkip;
    }
    #undef Addr
}

static void ClearZbuff(zBuff_t *pZbuff,u32 length){
//in stm32, we could use DMA to do this job   
    int32_t i=length&0x0000000F; 
    length = length>>4;  
    #define Addr pZbuff
    zBuff_t value = Z_LIMIT_NUM;
    while(length--){  
        *Addr = value;Addr++;*Addr = value;Addr++;*Addr = value;Addr++;
        *Addr = value;Addr++;*Addr = value;Addr++;*Addr = value;Addr++;
        *Addr = value;Addr++;*Addr = value;Addr++;*Addr = value;Addr++;
        *Addr = value;Addr++;*Addr = value;Addr++;*Addr = value;Addr++;
        *Addr = value;Addr++;*Addr = value;Addr++;*Addr = value;Addr++;
        *Addr = value;Addr++;
    }
    switch(i){
        case 15:*Addr = value;Addr++;
        case 14:*Addr = value;Addr++;
        case 13:*Addr = value;Addr++;
        case 12:*Addr = value;Addr++;
        case 11:*Addr = value;Addr++;
        case 10:*Addr = value;Addr++;
        case 9:*Addr = value;Addr++;
        case 8:*Addr = value;Addr++;
        case 7:*Addr = value;Addr++;
        case 6:*Addr = value;Addr++;
        case 5:*Addr = value;Addr++;
        case 4:*Addr = value;Addr++;    
        case 3:*Addr = value;Addr++;
        case 2:*Addr = value;Addr++;
        case 1:*Addr = value;
        case 0:break;
    }
    #undef Addr
}

static void RenderNoTexMesh(B3LMeshNoTexObj_t *pObj,render_t *pRender, mat4_t *pMat,u32 renderLevel){
    int32_t i;
    B3L_Mesh_NoTex_t *pMesh= pObj->pMesh;
    vect3_t *pVectSource = ((vect3_t *)(pMesh->pVect));
    screen3f_t *pVectTarget =pRender->pVectBuff;
    u8  *pColorIdx = pMesh->pColorIdx;
    texLUT_t       *pLUT = pObj->pLUT;
    fBuff_t *pFrameBuff =pRender->pFrameBuff;
    zBuff_t *pZBuff =  pRender->pZBuff;
//process all the vectors
    for(i=pMesh->vectNum - 1;i>=0;i--){ 
        Vect3Xmat4WithTest_f(pVectSource+i, pMat, pVectTarget+i);
    }
    f32 lightX,lightY,lightZ;
    f32 normalFact;
    f32   lightFactor0;
    f32   lightFactor1;
    if (renderLevel==0){//light calculation is needed, so normalized the normal
        
        pVectSource = ((vect3_t *)(pMesh->pNormal));// now the vectsource point to the normal vect
        //calculate the Light vect in clip space;      
        if(B3L_TEST(pRender->light.state,LIGHT_TYPE_BIT) == POINT_LIGHT){  
             //dot light, calculate the vect point  to light from obj (both already in camera space)
            vect3_t *translation = &(pObj->transform.translation);
            lightX = pRender->light.lightVect.x - translation->x;
            lightY = pRender->light.lightVect.y - translation->y;
            lightZ = pRender->light.lightVect.z - translation->z;
            //normalize the obj to light vector
            normalFact = FastInvertSqrt(lightX*lightX+lightY*lightY+lightZ*lightZ);
            lightX = lightX * normalFact;
            lightY = lightY * normalFact;
            lightZ = lightZ * normalFact;

        }else{
            //parallel light, the point to light vect is already in camera space
            lightX = pRender->light.lightVect.x;
            lightY = pRender->light.lightVect.y;
            lightZ = pRender->light.lightVect.z;
        }
        
        lightFactor0 = pRender->light.factor_0;
        lightFactor1 = pRender->light.factor_1;
    }               
    u16 *pTriIdx = pMesh->pTri;
    u32 cullingState = ((pObj->state)&OBJ_CULLING_MASK)>>OBJ_CULLING_SHIFT;
    u32 vect0Idx,vect1Idx,vect2Idx;
    vect3_t normalVect;
    f32   normalDotLight;
    fBuff_t color;
    //if the render level is not zero, then the lightValue would fix at 0xff
    u32 lightValue=pRender->lvl1Light;
//draw tri loop
    for (i=pMesh->triNum -1;i>=0;i--){
        //pTriRenderState[i]=0;
        vect0Idx = pTriIdx[i*3];
        vect1Idx = pTriIdx[i*3+1];
        vect2Idx = pTriIdx[i*3+2];
        u32 result0 = pVectTarget[vect0Idx].test;
        u32 result1 = pVectTarget[vect1Idx].test;
        u32 result2 = pVectTarget[vect2Idx].test;
        if(!TriVisable(result0,result1,result2)){
            continue;
        }
        //screen3_t *screenVect = pVectTarget;
        f32 x0 = pVectTarget[vect0Idx].x;
        f32 y0 = pVectTarget[vect0Idx].y;
        f32 x1 = pVectTarget[vect1Idx].x;
        f32 y1 = pVectTarget[vect1Idx].y;
        f32 x2 = pVectTarget[vect2Idx].x;
        f32 y2 = pVectTarget[vect2Idx].y;
        bool backFaceCullingResult = TriangleFaceToViewer_f(x0, y0, x1, y1, x2, y2); 
        if (((cullingState==1) && backFaceCullingResult)||((cullingState==2) && (!backFaceCullingResult))){    
            continue;
        }
        if (renderLevel==0){
            //Norm3Xmat4Normalize(pVectSource+i, pMat, &normalVect); 
            B3L_Vect3MulMat3(pVectSource+i, &(pObj->mat),&normalVect);
            //dot multi light and normalvect to get the light factor
            normalDotLight = normalVect.x*lightX + normalVect.y*lightY + normalVect.z*lightZ;
            //normalDotLight is in the range -1.0f to 1.0f
            lightValue = CalLightFactor(normalDotLight,lightFactor0,lightFactor1);
        }
        //printf("renderLevel %d,lightValue %d\n",renderLevel,lightValue);
        #if (FRAME_BUFF_COLOR_TYPE  == 0) || (FRAME_BUFF_COLOR_TYPE  == 1)
        color = pLUT[pColorIdx[i]];
        #endif
        #if (FRAME_BUFF_COLOR_TYPE  == 2)
        color = pColorIdx[i];
        #endif
        DrawTriColor(
            x0,y0,pVectTarget[vect0Idx].z,x1,y1,pVectTarget[vect1Idx].z,
            x2,y2,pVectTarget[vect2Idx].z,renderLevel,lightValue,color,
            pFrameBuff,pZBuff);
    }        
}

static void RenderPolygon(B3LPolygonObj_t *pObj,render_t *pRender, mat4_t *pMat){
    int32_t i;
    fBuff_t *pFrameBuff =pRender->pFrameBuff;
    zBuff_t *pZBuff =  pRender->pZBuff;
    B3L_Polygon_t *pPoly = pObj->pPolygon;
    texLUT_t color= pObj->color;
    vect3_t *pVectSource = ((vect3_t *)(pPoly->pVect));
    screen3f_t *pVectTarget =pRender->pVectBuff;
    //project all the vect into screen space
    for(i=pPoly->vectNum - 1;i>=0;i--){ 
        Vect3Xmat4WithTest_f(pVectSource+i, pMat, pVectTarget+i);
    }
    u8 *pLine = pPoly->pLine;
    u8 lineIdxA,lineIdxB;
    u32 testA, testB;
    for (i=pPoly->lineNum -1;i>=0;i--){    
        //draw every line
        lineIdxA = pLine[i*2];
        lineIdxB = pLine[i*2+1];
        testA = pVectTarget[lineIdxA].test;
        testB = pVectTarget[lineIdxB].test;
        if (B3L_TEST(testA,B3L_NEAR_PLANE_CLIP)||
            B3L_TEST(testB,B3L_NEAR_PLANE_CLIP)){
                continue;
        }
        s32 Ax = B3L_RoundingToS(pVectTarget[lineIdxA].x);
        s32 Ay = B3L_RoundingToS(pVectTarget[lineIdxA].y);
        f32 Az = pVectTarget[lineIdxA].z;
        s32 Bx = B3L_RoundingToS(pVectTarget[lineIdxB].x);
        s32 By = B3L_RoundingToS(pVectTarget[lineIdxB].y);
        f32 Bz = pVectTarget[lineIdxB].z;
        if (B3L_TEST(testA,B3L_IN_SPACE )&&
            B3L_TEST(testB,B3L_IN_SPACE )){
            DrawDepthLineNoClip(Ax,Ay,Az,Bx,By,Bz,color,pFrameBuff,pZBuff);
        }else{
            DrawDepthLineClip(Ax,Ay,Az,Bx,By,Bz,color,pFrameBuff,pZBuff);
        }
    }
}


static void RenderTexMesh(B3LMeshObj_t *pObj,render_t *pRender, mat4_t *pMat,u32 renderLevel){
    int32_t i;
    B3L_Mesh_t *pMesh= pObj->pMesh;
    vect3_t *pVectSource = ((vect3_t *)(pMesh->pVect));
    screen3f_t *pVectTarget =pRender->pVectBuff;
    u8 * pUV = pObj->pMesh->pUv;
    B3L_texture_t *pTexture = pObj->pTexture;
    fBuff_t *pFrameBuff =pRender->pFrameBuff;
    zBuff_t *pZBuff =  pRender->pZBuff;
//process all the vectors
    for(i=pMesh->vectNum - 1;i>=0;i--){ 
        Vect3Xmat4WithTest_f(pVectSource+i, pMat, pVectTarget+i);
    }
    f32 lightX,lightY,lightZ;
    f32 normalFact;
    f32   lightFactor0;
    f32   lightFactor1;
    if (renderLevel==0){//light calculation is needed, so normalized the normal  
        pVectSource = ((vect3_t *)(pMesh->pNormal));// now the vectsource point to the normal vect
        //calculate the Light vect in clip space;      
        if(B3L_TEST(pRender->light.state,LIGHT_TYPE_BIT) == POINT_LIGHT){  
             //dot light, calculate the vect point  to light from obj (both already in camera space)
            vect3_t *translation = &(pObj->transform.translation);
            lightX = pRender->light.lightVect.x - translation->x;
            lightY = pRender->light.lightVect.y - translation->y;
            lightZ = pRender->light.lightVect.z - translation->z;
            normalFact = FastInvertSqrt(lightX*lightX+lightY*lightY+lightZ*lightZ);
            lightX = lightX * normalFact;
            lightY = lightY * normalFact;
            lightZ = lightZ * normalFact;
        }else{
            //parallel light, the point to light vect is already in camera space
            lightX = pRender->light.lightVect.x;
            lightY = pRender->light.lightVect.y;
            lightZ = pRender->light.lightVect.z;
        }      
        lightFactor0 = pRender->light.factor_0;
        lightFactor1 = pRender->light.factor_1;
    }         
    u32 state = pObj->state;     
    u16 *pTriIdx = pMesh->pTri;
    u32 cullingState = ((state)&OBJ_CULLING_MASK)>>OBJ_CULLING_SHIFT;
    u32 vect0Idx,vect1Idx,vect2Idx;
    vect3_t normalVect;
    f32   normalDotLight;
    u32 lightValue;
   
    //if the render level is not zero, then the lightValue would fix at lvl1Light
    if (B3L_TEST(state,OBJ_SPECIAL_LIGHT_VALUE)){
        lightValue= (state &OBJ_SPECIAL_LIGHT_MASK )>>OBJ_SPECIAL_LIGHT_SHIFT;
    }else{
        lightValue=pRender->lvl1Light;
    }  
//draw tri loop
    for (i=pMesh->triNum -1;i>=0;i--){
        //pTriRenderState[i]=0;
        vect0Idx = pTriIdx[i*3];
        vect1Idx = pTriIdx[i*3+1];
        vect2Idx = pTriIdx[i*3+2];
        u32 result0 = pVectTarget[vect0Idx].test;
        u32 result1 = pVectTarget[vect1Idx].test;
        u32 result2 = pVectTarget[vect2Idx].test;
        if(!TriVisable(result0,result1,result2)){
            continue;
        }
        //screen3f_t *screenVect = pVectTarget;
        f32 x0 = pVectTarget[vect0Idx].x;
        f32 y0 = pVectTarget[vect0Idx].y;
        f32 x1 = pVectTarget[vect1Idx].x;
        f32 y1 = pVectTarget[vect1Idx].y;
        f32 x2 = pVectTarget[vect2Idx].x;
        f32 y2 = pVectTarget[vect2Idx].y;
        bool backFaceCullingResult = TriangleFaceToViewer_f(x0, y0, x1, y1, x2, y2);     
        if (((cullingState==1) && backFaceCullingResult)||((cullingState==2) && (!backFaceCullingResult))){    
            continue;
        }
        if (renderLevel==0){
            //Norm3Xmat4Normalize(pVectSource+i, pMat, &normalVect); 
            B3L_Vect3MulMat3(pVectSource+i, &(pObj->mat),&normalVect);
            //dot multi light and normalvect to get the light factor
            normalDotLight = normalVect.x*lightX + normalVect.y*lightY + normalVect.z*lightZ;
            //normalDotLight is in the range -1.0f to 1.0f
            lightValue = CalLightFactor(normalDotLight,lightFactor0,lightFactor1);
        }
        DrawTriTexture(
            x0,y0,(f32)(pUV[i*6]),(f32)(pUV[i*6+1]),pVectTarget[vect0Idx].z,
            x1,y1,(f32)(pUV[i*6+2]),(f32)(pUV[i*6+3]),pVectTarget[vect1Idx].z,
            x2,y2,(f32)(pUV[i*6+4]),(f32)(pUV[i*6+5]),pVectTarget[vect2Idx].z,
            renderLevel,lightValue,pTexture,
            pFrameBuff,pZBuff);
    }        
}

__attribute__((always_inline)) static inline void DrawDepthLineNoClip(s32 Ax,s32 Ay,f32 Az,s32 Bx,s32 By,f32 Bz, 
                                                            texLUT_t color,fBuff_t *pFrameBuff,zBuff_t *pZbuff){
//todo here~
    s32 steep = abs(Ay - By) > abs(Ax - Bx);
    //fBuff_t drawColor;
    if (steep){
        _swap_int32_t(Ax,Ay);
        _swap_int32_t(Bx,By);
    }
    if (Ax>Bx){
        //swap a,b point
        _swap_int32_t(Ax, Bx);
        _swap_int32_t(Ay, By);
        _swap_f32_t(Az, Bz);
    }
    s32 dx, dy;
    dx = Bx - Ax;
    dy = abs(By - Ay);
    f32 dz = (Bz - Az)/((f32)dx);
    s32 err = dx / 2;
    s32 ystep;
    if (Ay < By) {
        ystep = 1;
    } else {
        ystep = -1;
    }
    for (; Ax <= Bx; Ax++) {
    if (steep) {
        DrawPixel(color,Ay,Ax,Az,pFrameBuff,pZbuff);
    } else {
        DrawPixel(color,Ax,Ay,Az,pFrameBuff,pZbuff);
    }
    Az = Az + dz;
    err -= dy;
    if (err < 0) {
        Ay += ystep;
        err += dx;
    }
  }
}

__attribute__((always_inline)) static inline void DrawDepthLineClip(s32 Ax,s32 Ay,f32 Az,s32 Bx,s32 By,f32 Bz, 
                                                                        texLUT_t color,fBuff_t *pFrameBuff,zBuff_t *pZbuff){

    //now A is in the left and B is in the right
    s32 steep = abs(Ay - By) > abs(Ax - Bx);
    //fBuff_t drawColor;
    if (steep){
        _swap_int32_t(Ax,Ay);
        _swap_int32_t(Bx,By);
    }
    if (Ax>Bx){
        //swap a,b point
        _swap_int32_t(Ax, Bx);
        _swap_int32_t(Ay, By);
        _swap_f32_t(Az, Bz);
    }
    s32 dx, dy;
    dx = Bx - Ax;
    dy = abs(By - Ay);
    f32 dz = (Bz - Az)/((f32)dx);
    s32 err = dx / 2;
    s32 ystep;
    if (Ay < By) {
        ystep = 1;
    } else {
        ystep = -1;
    }
    for (; Ax <= Bx; Ax++) {
        if (steep) {
            DrawPixelWithTest(color,Ay,Ax,Az,pFrameBuff,pZbuff);
        } else {
            DrawPixelWithTest(color,Ax,Ay,Az,pFrameBuff,pZbuff);
        }
        Az = Az + dz;
        err -= dy;
        if (err < 0) {
            Ay += ystep;
            err += dx;
        }
    }
}


__attribute__((always_inline)) static inline void DrawColorHLine(f32 x,s32 y,f32 b, f32 aZ, f32 bZ,
                                       fBuff_t finalColor, fBuff_t *pFrameBuff,zBuff_t *pZbuff) {
    s32 intx = B3L_RoundingToS(x),inty=y,intb=(B3L_RoundingToS(b));
    s32 clipL = 0;
    s32 clipR = RENDER_RESOLUTION_X ;
    f32 invlength = 1.0f/((f32)(intb-intx));
    intb = intb - 1;
    if ((intx>=clipR)||(b<clipL)){
        return;
    }
    f32 dZ = (bZ - aZ)*invlength;
    f32 skip;
    //u32 intu,intv;
    if (intx< clipL){
        skip = (f32)(clipL -intx);
        intx = clipL;
        aZ += (skip)*dZ;
    }
    if (intb>=clipR){
        intb = clipR-1;
    }
    s32 i = intb-intx;
    u32 shift = inty*RENDER_RESOLUTION_X  + intx;
    zBuff_t  *pCurrentPixelZ = pZbuff + shift;  
    shift = inty*RENDER_X_SHIFT  + intx;
    fBuff_t *pixel = pFrameBuff +shift;
    zBuff_t compZ;
    for (;i>=0;i--){ //don't draw the most right pixel, so the b has already -1
        compZ = CalZbuffValue(aZ);
        if (compZ<= *pCurrentPixelZ){          
            *pCurrentPixelZ = compZ;
            *pixel =finalColor;           
        }
        aZ = aZ + dZ;
        pCurrentPixelZ ++;
        pixel++;
    }    
}

__attribute__((always_inline)) static inline void DrawTexHLine(f32 x,s32 y,f32 b, f32 aZ, f32 bZ,
f32 aU,f32 aV,f32 bU,f32 bV, u32 lightFactor, fBuff_t *pFrameBuff,zBuff_t *pZbuff, B3L_texture_t *pTexture) {
    //printf("auv%.2f,%.2f,buv%.2f,%.2f\n",aU,aV,bU,bV);
    s32 intx = B3L_RoundingToS(x),inty=y,intb=(B3L_RoundingToS(b));
    //s32 b = x + length -1;//correct
    f32 u=aU,v=aV;
    s32 clipL = 0;
    s32 clipR = RENDER_RESOLUTION_X ;
    f32 invlength = 1.0f/((f32)(intb-intx));
    intb = intb - 1;
    if ((intx>=clipR)||(b<clipL)){
        return;
    }
    f32 dZ = (bZ - aZ)*invlength;
    f32 du = (bU - aU)*invlength;
    f32 dv = (bV - aV)*invlength; 
    f32 skip;
    u32 intu,intv;
    if (intx< clipL){
        skip = (f32)(clipL -intx);
        intx = clipL;
        u += (skip)*du;
        v += (skip)*dv; 
        aZ += (skip)*dZ;
    }
    if (intb>=clipR){
        intb = clipR-1;
    }
    s32 i = intb-intx;
    u32 shift = inty*RENDER_RESOLUTION_X  + intx;
    zBuff_t  *pCurrentPixelZ = pZbuff + shift;  
    shift = inty*RENDER_X_SHIFT  + intx;
    fBuff_t *pixel = pFrameBuff +shift; 
    u32 uvSize = pTexture->uvSize;
    u8  *uvData = pTexture->pData;
    texLUT_t *lut = pTexture->pLUT;
    u8  colorIdx = 0;
    //fBuff_t color;
    u8 transColorIdx = pTexture->transColorIdx;
    zBuff_t compZ;
    switch(pTexture->type){
        case LUT16:
        for (;i>=0;i--){  //don't draw the most right pixel, so the b has already -1
            compZ = CalZbuffValue(aZ);
            if (compZ<= *pCurrentPixelZ){           
                intu = (uint32_t)u;
                intv = (uint32_t)v;
                colorIdx = uvData[intv*(uvSize>>1) + (intu>>1)];
                colorIdx = colorIdx>>(4*(intu & 0x01));
                colorIdx = colorIdx&0x0F;
                if (colorIdx == transColorIdx){
                    continue;
                }                
                *pCurrentPixelZ = compZ;
                *pixel = GetColorValue(lut,colorIdx,lightFactor);          
            }
            u +=du;
            v +=dv;
            aZ +=dZ;
            pCurrentPixelZ ++;
            pixel++;
        }
        break;
        case LUT256:
        for (;i>=0;i--){
            compZ = CalZbuffValue(aZ);
            if (compZ<= *pCurrentPixelZ){          
                intu = (uint32_t)u;
                intv = (uint32_t)v;  
                colorIdx = uvData[intv*uvSize + intu];
                if (colorIdx == transColorIdx){
                    continue;
                }
                *pCurrentPixelZ = compZ;
                *pixel = GetColorValue(lut,colorIdx,lightFactor);           
            }
            u +=du;
            v +=dv;
            aZ +=dZ;
            pCurrentPixelZ++;
            pixel++;
        }
        break;
    } 
}

__attribute__((always_inline)) static  inline void  DrawTriTexture(
                                                                        f32 x0,f32 y0,f32 u0,f32 v0,f32 z0,
                                                                        f32 x1,f32 y1,f32 u1,f32 v1,f32 z1,
                                                                        f32 x2,f32 y2,f32 u2,f32 v2,f32 z2,
                                                                        u32 renderLevel,u32 lightFactor,B3L_texture_t *pTexture,
                                                                        fBuff_t *pFrameBuff,zBuff_t *pZbuff){
    s32 y,last;
    if(y0 > y1){
        //B3L_SWAP_DRAW_TRI_VECT(0,1);
        _swap_f32_t(y0,y1);
        _swap_f32_t(x0,x1);
        _swap_f32_t(u0,u1);
        _swap_f32_t(v0,v1); 
        _swap_f32_t(z0,z1); 
        //_swap_int32_t(inty0,inty1);  
    }
    if (y1 > y2) {
        //B3L_SWAP_DRAW_TRI_VECT(2,1);
        _swap_f32_t(y2,y1);
        _swap_f32_t(x2,x1);
        _swap_f32_t(u2,u1);
        _swap_f32_t(v2,v1);
        _swap_f32_t(z2,z1);  
        //_swap_int32_t(inty1,inty2);  
    }
    if(y0 > y1){
        //B3L_SWAP_DRAW_TRI_VECT(0,1);
        _swap_f32_t(y0,y1);
        _swap_f32_t(x0,x1);
        _swap_f32_t(u0,u1);
        _swap_f32_t(v0,v1);
        _swap_f32_t(z0,z1); 
        //_swap_int32_t(inty0,inty1);   
    }
    s32 inty0 = B3L_RoundingToS(y0),inty1 = B3L_RoundingToS(y1),inty2 = B3L_RoundingToS(y2);
    if(inty0 == inty2) { // Handle awkward all-on-same-line case as its own thing
        return;
    }
    f32 dy01 = 1.0f/(inty1 - inty0);
    f32 dy02 = 1.0f/(inty2 - inty0);
    f32 dy12 = 1.0f/(inty2 - inty1);

    f32 dx01 = (x1 - x0)*dy01;
    f32 dx02 = (x2 - x0)*dy02;
    f32 dx12 = (x2 - x1)*dy12;
    
    f32 du01 = (u1 - u0)*dy01;
    f32 dv01 = (v1 - v0)*dy01;
    f32 du02 = (u2 - u0)*dy02;
    f32 dv02 = (v2 - v0)*dy02;
    f32 du12 = (u2 - u1)*dy12;
    f32 dv12 = (v2 - v1)*dy12;
    f32 dz01 = (z1 - z0)*dy01;
    f32 dz02 = (z2 - z0)*dy02;
    f32 dz12 = (z2 - z1)*dy12;

    f32  aZ=z0;f32  bZ=z0;f32  a=x0;f32  b=x0;
    f32  aU=u0;f32  bU=u0;f32  aV=v0;f32  bV=v0;
    /*
    if(inty1 == inty2) last = inty1;   // Include y1 scanline
    else last = inty1-1; // Skip it
    */
    last = inty1-1;
    if (last>=RENDER_RESOLUTION_Y){
            last = RENDER_RESOLUTION_Y -1;
    }
    //printf("in first half\n");
    for(y=inty0; y<=last; y++) {
        if ((aZ>1.0f) && (bZ>1.0f)){
            continue;
        }  
        if(!((y<0)||((B3L_RoundingToS(a))==(B3L_RoundingToS(b))))){
        //include a, and b how many pixel
            if(a > b){
                DrawTexHLine(b,y,a,bZ,aZ,bU,bV,aU,aV,lightFactor,pFrameBuff,pZbuff,pTexture);
            }else{
                DrawTexHLine(a,y,b,aZ,bZ,aU,aV,bU,bV,lightFactor,pFrameBuff,pZbuff,pTexture);
            } 
        }
        a   += dx01;
        b   += dx02;
        aU +=du01;
        aV +=dv01;
        bU +=du02;
        bV +=dv02;
        aZ = aZ + dz01;
        bZ = bZ + dz02;
    }

    //s32 deltaY1 = y-inty1;
    s32 deltaY0 = y-inty0;
    a = x1;
    b = x0 + dx02*deltaY0;
    aZ = z1;
    aU = u1;
    aV = v1;
    bU = u0+du02*deltaY0;
    bV = v0+dv02*deltaY0;
    //s32 y2 = tri->y2;
    if (inty2>=RENDER_RESOLUTION_Y){
        inty2= RENDER_RESOLUTION_Y -1;
    }
    for(; y<=inty2; y++) {
        if ((aZ>1.0f) && (bZ>1.0f)){
            continue;
        }
        if(!((y<0)||((B3L_RoundingToS(a))==(B3L_RoundingToS(b))))){
        //include a, and b how many pixel
            if(a > b){
                DrawTexHLine(b,y,a,bZ,aZ,bU,bV,aU,aV,lightFactor,pFrameBuff,pZbuff,pTexture);
            }else{
                DrawTexHLine(a,y,b,aZ,bZ,aU,aV,bU,bV,lightFactor,pFrameBuff,pZbuff,pTexture);
            } 
        }
        a  += dx12;
        b  += dx02;
        aU += du12;
        aV += dv12;
        bU += du02;
        bV += dv02;
        aZ += dz12;
        bZ += dz02; 
    }
}

__attribute__((always_inline)) static  inline fBuff_t GetFinalColor(fBuff_t color,u32 lightFactor){
#if B3L_IN_SITU_LIGHT_CAL == 0    
    #if FRAME_BUFF_COLOR_TYPE == 0               
        fBuff_t  finalColor = (color&0x00FFFFFF)|(((u32)lightFactor)<<24);
    #endif
    #if FRAME_BUFF_COLOR_TYPE == 1
        fBuff_t  finalColor  = (color&0x0FFF)|(((u16)lightFactor)<<12);
    #endif
    #if FRAME_BUFF_COLOR_TYPE == 2
        fBuff_t  finalColor  = (color&0x00FF)|(((u16)lightFactor)<<8);
    #endif
#endif
#if B3L_IN_SITU_LIGHT_CAL == 1   
    #if FRAME_BUFF_COLOR_TYPE == 0 
        u32 red = ((color&0x00FF0000)*lightFactor)>>8;
        u32 green = ((color&0x0000FF00)*lightFactor)>>8;
        u32 blue = ((color&0x000000FF)*lightFactor)>>8;
        fBuff_t finalColor = 0xFF000000|(red<<16)|(green<<8)|blue;
    #endif
    #if FRAME_BUFF_COLOR_TYPE == 1
        u16 red =  ((color&0x0F00)*lightFactor)>>4;
        u16 green =  ((color&0x00F0)*lightFactor)>>4;
        u16 blue = ((color&0x000F)*lightFactor)>>4;
        fBuff_t finalColor = 0xF000|(red<<8)|(green<<4)|blue;
    #endif 
#endif
    return finalColor;
}


__attribute__((always_inline)) static  inline void  DrawTriColor(
                                                                        f32 x0,f32 y0,f32 z0,
                                                                        f32 x1,f32 y1,f32 z1,
                                                                        f32 x2,f32 y2,f32 z2,
                                                                        u32 renderLevel,u32 lightFactor,fBuff_t color,
                                                                        fBuff_t *pFrameBuff,zBuff_t *pZbuff){

    fBuff_t finalColor = GetFinalColor(color,lightFactor);
    s32 y,last;
    if(y0 > y1){
        _swap_f32_t(y0,y1);
        _swap_f32_t(x0,x1);
        _swap_f32_t(z0,z1); 
        //_swap_int32_t(inty0,inty1);  
    }
    if (y1 > y2) {
        _swap_f32_t(y2,y1);
        _swap_f32_t(x2,x1);
        _swap_f32_t(z2,z1);  
        //_swap_int32_t(inty1,inty2);  
    }
    if(y0 > y1){
        _swap_f32_t(y0,y1);
        _swap_f32_t(x0,x1);
        _swap_f32_t(z0,z1); 
        //_swap_int32_t(inty0,inty1);   
    }
    s32 inty0 = B3L_RoundingToS(y0),inty1 = B3L_RoundingToS(y1),inty2 = B3L_RoundingToS(y2);
    if(inty0 == inty2) { // Handle awkward all-on-same-line case as its own thing
        return;
    }
    f32 dy01 = 1.0f/(inty1 - inty0);
    f32 dy02 = 1.0f/(inty2 - inty0);
    f32 dy12 = 1.0f/(inty2 - inty1);
    f32 dx01 = (x1 - x0)*dy01;
    f32 dx02 = (x2 - x0)*dy02;
    f32 dx12 = (x2 - x1)*dy12;
    f32 dz01 = (z1 - z0)*dy01;
    f32 dz02 = (z2 - z0)*dy02;
    f32 dz12 = (z2 - z1)*dy12;
    f32  aZ=z0;
    f32  bZ=z0;
    f32  a=x0;
    f32  b=x0;
    /*
    if(inty1 == inty2) last = inty1;   // Include y1 scanline
    else last = inty1-1; // Skip it
    */
    last = inty1-1;
    if (last>=RENDER_RESOLUTION_Y){
            last = RENDER_RESOLUTION_Y -1;
    }
    //printf("in first half\n");
    for(y=inty0; y<=last; y++) {
        if ((aZ>1.0f) && (bZ>1.0f)){
            continue;
        } 
        if(!((y<0)||((B3L_RoundingToS(a))==(B3L_RoundingToS(b))))){
        //include a, and b how many pixel
            if(a > b){
                DrawColorHLine(b,y,a,bZ,aZ,finalColor,pFrameBuff,pZbuff);
            }else{
                DrawColorHLine(a,y,b,aZ,bZ,finalColor,pFrameBuff,pZbuff);
            } 
        }
        a   += dx01;
        b   += dx02;
        aZ = aZ + dz01;
        bZ = bZ + dz02;
    }

    //s32 deltaY1 = y-inty1;
    s32 deltaY0 = y-inty0;
    a = x1;
    b = x0 + dx02*deltaY0;
    aZ = z1;
    if (inty2>=RENDER_RESOLUTION_Y){
        inty2= RENDER_RESOLUTION_Y -1;
    }
    //printf("aU,%.3f aV,%.3f bU,%.3f bV%.3f \n",aU,aV,bU,bV);    
    for(; y<=inty2; y++) {
        if ((aZ>1.0f) && (bZ>1.0f)){
            continue;
        }
        if(!((y<0)||((B3L_RoundingToS(a))==(B3L_RoundingToS(b))))){
        //include a, and b how many pixel
            if(a > b){
                DrawColorHLine(b,y,a,bZ,aZ,finalColor,pFrameBuff,pZbuff);
            }else{
                DrawColorHLine(a,y,b,aZ,bZ,finalColor,pFrameBuff,pZbuff);
            } 
        }
        a  += dx12;
        b  += dx02;
        aZ += dz12;
        bZ += dz02; 
    }
}

/*-----------------------------------------------------------------------------
Rotation calculation functions 
-----------------------------------------------------------------------------*/
void B3L_EulerToMatrix(euler3_t *pEuler,mat3_t *pMat){
    f32 byX = pEuler->x;f32 byY = pEuler->y;f32 byZ = pEuler->z;
    f32 sx = B3L_sin(byX);f32 sy = B3L_sin(byY);f32 sz = B3L_sin(byZ);
    f32 cx = B3L_cos(byX);f32 cy = B3L_cos(byY);f32 cz = B3L_cos(byZ);
    #define M(x,y) (pMat)->m##x##y
    M(0,0) = (cy * cz)  + (sy * sx * sz);
    M(0,1) = (cz * sy * sx)  - (cy * sz);
    M(0,2) = (cx * sy) ;
    M(1,0) = (cx * sz) ;
    M(1,1) = (cx * cz);
    M(1,2) = -1.0f * sx;
    M(2,0) = (cy * sx * sz)  - (cz * sy);
    M(2,1) = (cy * cz * sx)+ (sy * sz) ;
    M(2,2) = (cy * cx) ;
    #undef M

}
void B3L_MatrixToEuler(mat3_t *pMat, euler3_t *pEuler){
    f32 sp = -pMat->m12;
    if (sp <= -1.0f){
        pEuler->x = -0.25f;
    } else if (sp>=1.0f){
        pEuler->x = 0.25f;
    } else {
        pEuler->x = B3L_asin(sp);
    }
    if (B3L_Absf(sp)>0.9999f){
        pEuler->z = 0.0f;
        pEuler->y = B3L_atan2(-pMat->m02,pMat->m00);
    }else{
        pEuler->y = B3L_atan2(pMat->m02,pMat->m22);
        pEuler->z = B3L_atan2(pMat->m10,pMat->m11);
    }
}

void B3L_QuaternionToMatrix(quat4_t *pQuat, mat3_t *pMat){
    f32 x = pQuat->x; f32 y = pQuat->y; f32 z = pQuat->z; f32 w = pQuat->w;
    pMat->m00 = 1.0f - 2.0f*(y*y + z*z);
    pMat->m01 = 2.0f*(x*y - w*z);
    pMat->m02 = 2.0f*(x*z + w*y);
    pMat->m10 = 2.0f*(x*y + w*z);
    pMat->m11 = 1.0f - 2.0f*(x*x + z*z);
    pMat->m12 = 2.0f*(y*z - w*x);
    pMat->m20 = 2.0f*(x*z - w*y);
    pMat->m21 = 2.0f*(y*z + w*x);
    pMat->m22 = 1.0f - 2.0f*(x*x + y*y);
}

void B3L_MatrixToQuaternion(mat3_t *pMat, quat4_t *pQuat){
    f32 fWSM = pMat->m00 + pMat->m11 + pMat->m22;
    f32 fXSM = pMat->m00 - pMat->m11 - pMat->m22;
    f32 fYSM = pMat->m11 - pMat->m00 - pMat->m22;
    f32 fZSM = pMat->m22 - pMat->m00 - pMat->m11;
    s32 biggestIndex = 0;
    f32 fBSM = fWSM;
    if (fXSM>fBSM){
        fBSM = fXSM;
        biggestIndex = 1;
    }
    if(fYSM>fBSM){
        fBSM=fYSM;
        biggestIndex = 2;
    }
    if(fZSM>fBSM){
        fBSM=fZSM;
        biggestIndex = 3;
    }
    f32 biggestVal = B3L_Sqrtf(fBSM + 1.0f)*0.5f;
    f32 mult = 0.25f/biggestVal;
    switch(biggestIndex){
        case 0:
            pQuat->w = biggestVal;
            pQuat->x = (pMat->m21 - pMat->m12)*mult;
            pQuat->y = (pMat->m02 - pMat->m20)*mult;
            pQuat->z = (pMat->m10 - pMat->m01)*mult;
        break;
        case 1:
            pQuat->x = biggestVal;
            pQuat->w = (pMat->m21 - pMat->m12)*mult;
            pQuat->y = (pMat->m10 - pMat->m01)*mult;
            pQuat->z = (pMat->m02 + pMat->m20)*mult;
        break;
        case 2:
            pQuat->y = biggestVal;
            pQuat->w = (pMat->m02 - pMat->m20)*mult;
            pQuat->x = (pMat->m10 - pMat->m01)*mult;
            pQuat->z = (pMat->m21 + pMat->m12)*mult;
        break;
        case 3:
            pQuat->z = biggestVal;
            pQuat->w = (pMat->m10 - pMat->m01)*mult;
            pQuat->x = (pMat->m02 - pMat->m20)*mult;
            pQuat->y = (pMat->m21 + pMat->m12)*mult;
        break;
    }
}

void B3L_EulerToQuaternion(euler3_t *pEuler,quat4_t *pQuat){
    f32 cp = B3L_cos(pEuler->x * 0.5f);f32 ch = B3L_cos(pEuler->y * 0.5f);
    f32 cb = B3L_cos(pEuler->z * 0.5f);f32 sp = B3L_sin(pEuler->x * 0.5f);
    f32 sh = B3L_sin(pEuler->y * 0.5f);f32 sb = B3L_sin(pEuler->z * 0.5f);
    pQuat->w = ch*cp*cb + sh*sp*sb;
    pQuat->x = ch*sp*cb + sh*cp*sb;
    pQuat->y = sh*cp*cb - ch*sp*sb;
    pQuat->z = ch*cp*sb - sh*sp*cb;
}


void B3L_QuaternionToEuler(quat4_t *pQuat,euler3_t *pEuler){
    f32 x = pQuat->x;f32 y = pQuat->y;f32 z = pQuat->z;f32 w = pQuat->w;
    f32 sp = -2.0f*(y*z - w*x);
    if (B3L_Absf(sp)>0.9999f){
        pEuler->x = 0.25f * sp;
        pEuler->y = B3L_atan2(-x*z+w*y,0.5f-y*y-z*z);
        pEuler->z = 0.0f;
    }else{
        pEuler->x = B3L_asin(sp);
        pEuler->y = B3L_atan2(x*z+w*y,0.5f-x*x-y*y);
        pEuler->z = B3L_atan2(x*y+w*z,0.5f-x*x-z*z);
    }
}

/*-----------------------------------------------------------------------------
Quaternion functions
-----------------------------------------------------------------------------*/
void B3L_QuaternionInterp(quat4_t *pFrom,quat4_t *pTo,quat4_t *pResult, f32 t){
    f32 w0 = pFrom->w; f32 x0 = pFrom->x; f32 y0 = pFrom->y; f32 z0 = pFrom->z;
    f32 w1 = pTo->w; f32 x1 = pTo->x; f32 y1 = pTo->y; f32 z1 = pTo->z;
    f32 cosOmega = w0*w1+x0*x1+y0*y1+z0*z1;
    if(cosOmega <0.0f){
        w1 = -w1;x1 = -x1; y1 = -y1; z1 = -z1; 
        cosOmega = -cosOmega;
    }
    f32 k0,k1;
    if (cosOmega >0.9999f){
        k0 = 1.0f-t;
        k1 = t;
    }else{
        f32 sinOmega = B3L_Sqrtf(1.0f - cosOmega*cosOmega);
        f32 omega = B3L_atan2(sinOmega,cosOmega);
        f32 oneOverSinOmega = 1.0f/sinOmega;
        k0 = B3L_sin((1.0f-t)*omega)*oneOverSinOmega;
        k1 = B3L_sin(t*omega)*oneOverSinOmega;
    }
    pResult->w = w0*k0 + w1*k1;
    pResult->x = x0*k0 + x1*k1;
    pResult->y = y0*k0 + y1*k1;
    pResult->z = z0*k0 + z1*k1;
}

void B3L_QuatMult(quat4_t *pL,quat4_t *pR, quat4_t *pResult){
    f32 x1 = pL->x;f32 y1 = pL->y;f32 z1 = pL->z;f32 w1 = pL->w;
    f32 x2 = pR->x;f32 y2 = pR->y;f32 z2 = pR->z;f32 w2 = pR->w;
    pResult->x = w1*x2+x1*w2+y1*z2-z1*y2;
    pResult->y = w1*y2+y1*w2+z1*x2-x1*z2;
    pResult->z = w1*z2+z1*w2+x1*y2-y1*x2;
    pResult->w = w1*w2-x1*x2-y1*y2-z1*z2;
}

f32  B3L_QuatDot(quat4_t *pL,quat4_t *pR){
    return pL->w*pR->w + pL->x*pR->x + pL->y*pR->y +pL->z*pR->z ;
}

void B3L_CreateQuaternionByAxisAngle(vect3_t *pAxis, f32 angle, quat4_t *pResult){
    f32 halfAngle = 0.5f*angle;
    f32 sinh = B3L_sin(halfAngle);
    f32 cosh = B3L_cos(halfAngle);
    pResult->x = pAxis->x*sinh;
    pResult->y = pAxis->y*sinh;
    pResult->z = pAxis->z*sinh;
    pResult->w = cosh;
}

void B3L_FromToRotation(vect3_t *pFrom, vect3_t *pTo,quat4_t *pResult){
    vect3_t fN;
    vect3_t tN;
    B3L_Vect3Normalize(pFrom,&fN);
    B3L_Vect3Normalize(pTo,&tN);
    vect3_t normal;
    B3L_Vect3Cross(pFrom, pTo, &normal);
    f32 cosA = B3L_Vect3Dot(&fN,&tN);
    f32 cosh = B3L_Sqrtf(0.5f + cosA*0.5f);
    f32 sinh = B3L_Sqrtf(0.5f - cosA*0.5f);
    pResult->x = normal.x*sinh;
    pResult->y = normal.y*sinh;
    pResult->z = normal.z*sinh;
    pResult->w = cosh;
}

//create a quaternion that rotates vector a to vector b
void B3L_LookRotation(vect3_t *pA, vect3_t *pB, vect3_t *pUp, quat4_t *pResult){
    vect3_t aN;
    vect3_t bN;
    vect3_t uN;
    B3L_Vect3Normalize(pA,&aN);
    B3L_Vect3Normalize(pB,&bN); 
    B3L_Vect3Normalize(pUp,&uN);  
    f32 dot = B3L_Vect3Dot(&aN,&bN);
    
    if (dot < -0.9999f){
        //printf("less than -0.99f\n");
        B3L_CreateQuaternionByAxisAngle(&uN,0.5f,pResult);
        return;
    }else if(dot > 0.9999f){
        //printf("> than 0.99f\n");
        SET_IDENTITY_P_QUAT(pResult);
        return;
    }

    f32 rotAngle = 0.25f-B3L_asin(dot);
    vect3_t ortAxis;
    B3L_Vect3Cross(&aN,&bN,&ortAxis);
    B3L_Vect3Normalize(&ortAxis,&ortAxis);
    B3L_CreateQuaternionByAxisAngle(&ortAxis,rotAngle,pResult);
}

void B3L_CreateLookAtQuaternion(vect3_t *pFrom, vect3_t *pAt, vect3_t *pUp, quat4_t *pResult){
    vect3_t toObj;
    B3L_Vect3Sub(pAt,pFrom,&toObj);
    vect3_t zAxis = {0.0f,0.0f,1.0f};
    B3L_LookRotation(&zAxis,&toObj, pUp, pResult);
}

void B3L_QuatCreateXRotate(quat4_t *pQ,f32 angle){
    f32 halfAngle = 0.5f*angle;
    f32 cosh = B3L_cos(halfAngle);f32 sinh = B3L_sin(halfAngle);
    pQ->w = cosh;pQ->x = sinh;pQ->y = 0.0f;pQ->z = 0.0f;
}

void B3L_QuatCreateYRotate(quat4_t *pQ,f32 angle){
    f32 halfAngle = 0.5f*angle;
    f32 cosh = B3L_cos(halfAngle);f32 sinh = B3L_sin(halfAngle);
    pQ->w = cosh;pQ->x = 0.0f;pQ->y = sinh;pQ->z = 0.0f;
}

void B3L_QuatCreateZRotate(quat4_t *pQ,f32 angle){
    f32 halfAngle = 0.5f*angle;
    f32 cosh = B3L_cos(halfAngle);f32 sinh = B3L_sin(halfAngle);
    pQ->w = cosh;pQ->x = 0.0f;pQ->y = 0.0f;pQ->z = sinh;
}

fBuff_t *B3L_3dRenderAreaShiftCal(fBuff_t *startOfWholeFrameBuff,u32 x, u32 y){
    startOfWholeFrameBuff += y*WHOLE_FRAME_BUFF_WIDTH+x;
    return startOfWholeFrameBuff;
}

#define RGB_BLEND(sr, sg, sb, dr, dg, db, a) \
    uint8_t mr = (sr * a) >> 8; \
    uint8_t mg = (sg * a) >> 8; \
    uint8_t mb = (sb * a) >> 8; \
    uint16_t ia = 256 - a; \
    dr = (mr + ((dr * ia) >> 8)); \
    dg = (mg + ((dg * ia) >> 8)); \
    db = (mb + ((db * ia) >> 8)); \

__attribute__((always_inline)) static  inline fBuff_t  LightBlend(u32 inputPixel, u8 r, u8 g, u8 b){
    u8 s_r = (inputPixel>>16)&0xFF;
    u8 s_g = (inputPixel>>8)&0xFF;
    u8 s_b = (inputPixel)&0xFF;
    u8 s_a = (inputPixel>>24)&0xFF;
    RGB_BLEND(s_r,s_g,s_b,r,g,b,s_a)
    return (0xFF000000)|(r<<16)|(g<<8)|(b<<0);
}

void  B3L_AppliedLightFromAlpha(render_t *pRender){
    u32 j = RENDER_RESOLUTION_Y;
    u32 lineDiv16Left = (RENDER_RESOLUTION_X)&0x0000000F;
    fBuff_t *pFBuff = pRender->pFrameBuff;
    uint32_t backColor = pRender->light.color;
    u8 r =  (backColor&(0x00FF0000))>>16;
    u8 g =  (backColor &(0x0000FF00))>>8;
    u8 b =  (backColor &(0x000000FF));
    while(j--){
        u32 i=(RENDER_RESOLUTION_X>>4);
        while(i--){
            *pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;
            *pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;
            *pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;
            *pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;
            *pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;
            *pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;
            *pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;
            *pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;
            *pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;
            *pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;
            *pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;
            *pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;
            *pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;
            *pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;
            *pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;
            *pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;
        }
        switch(lineDiv16Left){
            case 15:*pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;               
            case 14:*pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;               
            case 13:*pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;               
            case 12:*pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;               
            case 11:*pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;               
            case 10:*pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;               
            case 9:*pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;                
            case 8:*pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;               
            case 7:*pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;    
            case 6:*pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;    
            case 5:*pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;     
            case 4:*pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;    
            case 3:*pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;     
            case 2:*pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;           
            case 1:*pFBuff = LightBlend(*pFBuff, r, g, b);pFBuff++;         
            case 0:break;        
        }
        pFBuff+= RENDER_LINE_SKIP;
    }
}

__attribute__((always_inline)) static  inline u32  LightBlend4(u16 inputPixel, u8 r, u8 g, u8 b){
    u8 s_r = ((inputPixel>>8)&0x0F)<<4;
    u8 s_g = ((inputPixel>>4)&0x0F)<<4;
    u8 s_b = ((inputPixel)&0x0F)<<4;
    u8 s_a = ((inputPixel>>12)&0x0F)<<4;
    RGB_BLEND(s_r,s_g,s_b,r,g,b,s_a)
    return (0xFF000000)|(r<<16)|(g<<8)|(b<<0);
    //return (0xFF000000)|(s_r<<16)|(s_g<<8)|(s_b<<0);
}

void  B3L_AppliedLightFromAlpha4444To8888(render_t *pRender,u32 *pTgetBuff){
u32 j = RENDER_RESOLUTION_Y;
    u32 lineDiv16Left = (RENDER_RESOLUTION_X)&0x0000000F;
    fBuff_t *pFBuff = pRender->pFrameBuff;
    
    uint32_t backColor = pRender->light.color;
    u8 r =  (backColor&(0x00FF0000))>>16;
    u8 g =  (backColor &(0x0000FF00))>>8;
    u8 b =  (backColor &(0x000000FF));
    while(j--){
        u32 i=(RENDER_RESOLUTION_X>>4);
        while(i--){
            *pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;
            *pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;
            *pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;
            *pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;
            *pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;
            *pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;
            *pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;
            *pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;
            *pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;
            *pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;
            *pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;
            *pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;
            *pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;
            *pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;
            *pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;
            *pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;
        }
        switch(lineDiv16Left){
            case 15:*pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;               
            case 14:*pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;               
            case 13:*pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;               
            case 12:*pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;               
            case 11:*pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;               
            case 10:*pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;             
            case 9:*pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;                
            case 8:*pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;               
            case 7:*pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;               
            case 6:*pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;               
            case 5:*pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;                
            case 4:*pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;               
            case 3:*pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;               
            case 2:*pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;                   
            case 1:*pTgetBuff = LightBlend4(*pFBuff, r, g, b);pTgetBuff++;pFBuff++;                 
            case 0:break;      
        }
        pFBuff+= RENDER_LINE_SKIP;
        pTgetBuff+= RENDER_LINE_SKIP;
    }
}

#if  B3L_DMA2D  == 1


#include "stm32h7xx_ll_bus.h"
#include "core_cm7.h"
#include "stm32h7xx_ll_dma2d.h"
#ifndef STM32H750xx
#define STM32H750xx
#endif

#define DMA2D_START_WORKING     (DMA2DOccupied = true);  
#define DMA2D_STOP_WORKING      (DMA2DOccupied = false); 

static volatile bool DMA2DOccupied; 
static volatile uint32_t DMACallbackCounter;
static fBuff_t B3L_CLEAN_FRAME_COLOR;

static void DMA2DDefaultCallback(void);
static void Apply_Zoom_ColorTrans_Callback(void);


void (*pDMA2DIRQCallback)(void);

void B3L_DMA2D_Init(void){
    DMA2DOccupied = false;
    DMACallbackCounter = 0;
    LL_AHB3_GRP1_EnableClock(LL_AHB3_GRP1_PERIPH_DMA2D);
    NVIC_SetPriority(DMA2D_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),B3L_DMA2D_IRQ_PRIORITY , B3L_DMA2D_IRQ_SUB_PRIORITY ));
    NVIC_EnableIRQ(DMA2D_IRQn);
    //irq init
    SET_BIT(DMA2D->CR, DMA2D_CR_TCIE|DMA2D_CR_TEIE|DMA2D_CR_CEIE);
    pDMA2DIRQCallback = DMA2DDefaultCallback;
}

void DMA2D_IRQHandler(void){
//clear the flag
    DMA2D->IFCR = (uint32_t)(0x1F);
 //call current callback
    (*pDMA2DIRQCallback)();
}

static void DMA2DDefaultCallback(void){
    DMACallbackCounter = 0;   
     
    DMA2D_STOP_WORKING
}

static void Apply_Zoom_ColorTrans_Callback(void){
    switch (DMACallbackCounter){
  case 0://copy 16bit color to its side pixel
    //set the transform type
    MODIFY_REG(DMA2D->CR, DMA2D_CR_MODE, LL_DMA2D_MODE_M2M);
    //set the input address, type
    MODIFY_REG(DMA2D->FGPFCCR, DMA2D_FGPFCCR_CM, LL_DMA2D_INPUT_MODE_RGB565);
    DMA2D->FGMAR = B3L_LCD_BUFF_ADDR+WHOLE_FRAME_BUFF_WIDTH*WHOLE_FRAME_BUFF_HEIGHT*4; 
    //set the target address, type
    MODIFY_REG(DMA2D->OPFCCR, DMA2D_OPFCCR_CM, LL_DMA2D_OUTPUT_MODE_RGB565);
    DMA2D->OMAR = B3L_LCD_BUFF_ADDR+WHOLE_FRAME_BUFF_WIDTH*WHOLE_FRAME_BUFF_HEIGHT*4+2; 
    
    //set the shape, 
    MODIFY_REG(DMA2D->NLR, DMA2D_NLR_PL, (1 << DMA2D_NLR_PL_Pos)); 
    MODIFY_REG(DMA2D->NLR, DMA2D_NLR_NL, (WHOLE_FRAME_BUFF_WIDTH*WHOLE_FRAME_BUFF_HEIGHT)); 
    
    //set the input 1 pixel skip
    MODIFY_REG(DMA2D->FGOR, DMA2D_FGOR_LO, 1);
    //set the output 1 pixel skip
    MODIFY_REG(DMA2D->OOR, DMA2D_OOR_LO, 1);
   
    break;
  case 1://copy line to ltdc buffer
    //set the transform type
    MODIFY_REG(DMA2D->CR, DMA2D_CR_MODE, LL_DMA2D_MODE_M2M);
    //set the input address, type
    MODIFY_REG(DMA2D->FGPFCCR, DMA2D_FGPFCCR_CM, LL_DMA2D_INPUT_MODE_RGB565);
    DMA2D->FGMAR = B3L_LCD_BUFF_ADDR+WHOLE_FRAME_BUFF_WIDTH*WHOLE_FRAME_BUFF_HEIGHT*4; 
    //set the shape, 
    MODIFY_REG(DMA2D->NLR, DMA2D_NLR_PL, ((WHOLE_FRAME_BUFF_WIDTH*2) << DMA2D_NLR_PL_Pos)); 
    MODIFY_REG(DMA2D->NLR, DMA2D_NLR_NL, (WHOLE_FRAME_BUFF_HEIGHT)); 
    //set the target address, type
    MODIFY_REG(DMA2D->OPFCCR, DMA2D_OPFCCR_CM, LL_DMA2D_OUTPUT_MODE_RGB565);
    DMA2D->OMAR = B3L_LCD_BUFF_ADDR; 
    //set the input 0 pixel skip
    MODIFY_REG(DMA2D->FGOR, DMA2D_FGOR_LO, 0);
    //set the output 320 pixel skip
    MODIFY_REG(DMA2D->OOR, DMA2D_OOR_LO, WHOLE_FRAME_BUFF_WIDTH*2);
 
    break;
  case 2://copy line again to next
    //set the transform type
    MODIFY_REG(DMA2D->CR, DMA2D_CR_MODE, LL_DMA2D_MODE_M2M);
    //set the input address, type
    MODIFY_REG(DMA2D->FGPFCCR, DMA2D_FGPFCCR_CM, LL_DMA2D_INPUT_MODE_RGB565);
    DMA2D->FGMAR = B3L_LCD_BUFF_ADDR; 
    //set the shape, 
    MODIFY_REG(DMA2D->NLR, DMA2D_NLR_PL, ((WHOLE_FRAME_BUFF_WIDTH*2) << DMA2D_NLR_PL_Pos)); 
    MODIFY_REG(DMA2D->NLR, DMA2D_NLR_NL, (WHOLE_FRAME_BUFF_HEIGHT)); 
    //set the target address, type
    MODIFY_REG(DMA2D->OPFCCR, DMA2D_OPFCCR_CM, LL_DMA2D_OUTPUT_MODE_RGB565);
    DMA2D->OMAR = B3L_LCD_BUFF_ADDR + WHOLE_FRAME_BUFF_WIDTH*4; //double pixel and 2 byte per pixel 
    //set the input 0 pixel skip
    MODIFY_REG(DMA2D->FGOR, DMA2D_FGOR_LO,WHOLE_FRAME_BUFF_WIDTH*2);
    //set the output 320 pixel skip
    MODIFY_REG(DMA2D->OOR, DMA2D_OOR_LO,WHOLE_FRAME_BUFF_WIDTH*2);
    break;
  case 3://clear the framebuff
    MODIFY_REG(DMA2D->CR, DMA2D_CR_MODE, LL_DMA2D_MODE_R2M);
    //set the reg color
    DMA2D->FGCOLR = B3L_CLEAN_FRAME_COLOR;
    //set the shape, 
    MODIFY_REG(DMA2D->NLR, DMA2D_NLR_PL, (WHOLE_FRAME_BUFF_WIDTH << DMA2D_NLR_PL_Pos)); 
    MODIFY_REG(DMA2D->NLR, DMA2D_NLR_NL, (WHOLE_FRAME_BUFF_HEIGHT)); 
    
    //set the target address, type
    MODIFY_REG(DMA2D->OPFCCR, DMA2D_OPFCCR_CM, LL_DMA2D_OUTPUT_MODE_ARGB8888);
    DMA2D->OMAR = B3L_FRAMEBUFF_ADDR ; 

    //set the output 0 pixel skip
    MODIFY_REG(DMA2D->OOR, DMA2D_OOR_LO,0);
    
    break;
  case 4:
    //clear z buff
    MODIFY_REG(DMA2D->CR, DMA2D_CR_MODE, LL_DMA2D_MODE_R2M);
    #if Z_BUFF_LEVEL == 2
    //set the reg color
    DMA2D->FGCOLR = 0x3f800000; //1.0f
    //set the shape, 
    MODIFY_REG(DMA2D->OPFCCR, DMA2D_OPFCCR_CM, LL_DMA2D_OUTPUT_MODE_ARGB8888);
    #elif Z_BUFF_LEVEL == 1
    DMA2D->FGCOLR = 0xFFFF;
    //set the shape, 
    MODIFY_REG(DMA2D->OPFCCR, DMA2D_OPFCCR_CM, LL_DMA2D_OUTPUT_MODE_RGB565); 
    #elif Z_BUFF_LEVEL == 0
    DMA2D->FGCOLR = 0xFF;
    //set the shape, 
    MODIFY_REG(DMA2D->OPFCCR, DMA2D_OPFCCR_CM, LL_DMA2D_OUTPUT_MODE_L8);     
    #endif
    MODIFY_REG(DMA2D->NLR, DMA2D_NLR_PL, ((WHOLE_FRAME_BUFF_WIDTH) << DMA2D_NLR_PL_Pos)); 
    MODIFY_REG(DMA2D->NLR, DMA2D_NLR_NL, (WHOLE_FRAME_BUFF_HEIGHT));
    
    DMA2D->OMAR = (u32)zBuff; 
    //set the output 0 pixel skip
    MODIFY_REG(DMA2D->OOR, DMA2D_OOR_LO,0); 
    pDMA2DIRQCallback = DMA2DDefaultCallback; 
    break;
  }
  DMACallbackCounter++;
  //start the next dma2d process
  DMA2D->CR |= DMA2D_CR_START;
}

void  B3L_DMA2DAppliedLightAndUpScale(u32 *addr,u32 wholeWidth,u32 wholeheight,u32 invLightColor){
    SCB_CleanInvalidateDCache_by_Addr(addr, wholeWidth * wholeheight * 4);
    //check the resource lock
    while(B3L_DMA2DIsOccupied()){};
    //change the callback
    pDMA2DIRQCallback = Apply_Zoom_ColorTrans_Callback;
    //reset the counter
    DMACallbackCounter = 0;
    //start the first DMA2D process
    //set the transform type
    MODIFY_REG(DMA2D->CR, DMA2D_CR_MODE, LL_DMA2D_MODE_M2M_BLEND_FIXED_COLOR_BG);
    //set the input address, type
    MODIFY_REG(DMA2D->FGPFCCR, DMA2D_FGPFCCR_CM, LL_DMA2D_INPUT_MODE_ARGB8888);
    DMA2D->FGMAR = B3L_FRAMEBUFF_ADDR; 
    DMA2D->BGCOLR = invLightColor;
    //set the target address, type
    MODIFY_REG(DMA2D->OPFCCR, DMA2D_OPFCCR_CM, LL_DMA2D_OUTPUT_MODE_RGB565);
    DMA2D->OMAR = B3L_LCD_BUFF_ADDR+WHOLE_FRAME_BUFF_WIDTH*WHOLE_FRAME_BUFF_HEIGHT*4;   
    //set the shape, 
    MODIFY_REG(DMA2D->NLR, DMA2D_NLR_PL, (1 << DMA2D_NLR_PL_Pos)); 
    MODIFY_REG(DMA2D->NLR, DMA2D_NLR_NL, (WHOLE_FRAME_BUFF_WIDTH*WHOLE_FRAME_BUFF_HEIGHT));         
    //set the line skip
    MODIFY_REG(DMA2D->FGOR, DMA2D_FGOR_LO,0);
    MODIFY_REG(DMA2D->OOR, DMA2D_OOR_LO, 1);
    DMA2D_START_WORKING
    DMA2D->CR |= DMA2D_CR_START;
}

void B3L_DMA2DAppliedLightTo565(u32 *addr,u32 wholeWidth,u32 wholeheight,u32 invLightColor){
    #if (FRAME_BUFF_COLOR_TYPE  == 1) 
    SCB_CleanInvalidateDCache_by_Addr(addr, wholeWidth * wholeheight * 2);
    MODIFY_REG(DMA2D->FGPFCCR, DMA2D_FGPFCCR_CM, LL_DMA2D_INPUT_MODE_ARGB4444);
    #endif
    #if (FRAME_BUFF_COLOR_TYPE  == 2)
    SCB_CleanInvalidateDCache_by_Addr(addr, wholeWidth * wholeheight * 2);
    MODIFY_REG(DMA2D->FGPFCCR, DMA2D_FGPFCCR_CM, LL_DMA2D_INPUT_MODE_AL88);
    #endif
    #if (FRAME_BUFF_COLOR_TYPE  == 0)
    SCB_CleanInvalidateDCache_by_Addr(addr, wholeWidth * wholeheight * 4);
    MODIFY_REG(DMA2D->FGPFCCR, DMA2D_FGPFCCR_CM, LL_DMA2D_INPUT_MODE_ARGB8888);
    #endif
    //check the resource lock
    while(B3L_DMA2DIsOccupied()){};
    //change the callback
    pDMA2DIRQCallback = DMA2DDefaultCallback;
    //reset the counter
    DMACallbackCounter = 0;
    //start the first DMA2D process
    //set the transform type
    MODIFY_REG(DMA2D->CR, DMA2D_CR_MODE, LL_DMA2D_MODE_M2M_BLEND_FIXED_COLOR_BG);
    //set the input address, type

    DMA2D->FGMAR = B3L_FRAMEBUFF_ADDR; 
    DMA2D->BGCOLR = invLightColor;
    //set the target address, type
    MODIFY_REG(DMA2D->OPFCCR, DMA2D_OPFCCR_CM, LL_DMA2D_OUTPUT_MODE_RGB565);
    DMA2D->OMAR = B3L_LCD_BUFF_ADDR;   
    //set the shape, 
    MODIFY_REG(DMA2D->NLR, DMA2D_NLR_PL, (WHOLE_FRAME_BUFF_WIDTH << DMA2D_NLR_PL_Pos)); 
    MODIFY_REG(DMA2D->NLR, DMA2D_NLR_NL, (WHOLE_FRAME_BUFF_HEIGHT));         
    //set the line skip
    MODIFY_REG(DMA2D->FGOR, DMA2D_FGOR_LO,0);
    MODIFY_REG(DMA2D->OOR, DMA2D_OOR_LO, 0);
    DMA2D_START_WORKING
    DMA2D->CR |= DMA2D_CR_START;
}

bool  B3L_DMA2DOcupied(void){
    return DMA2DOccupied;
}
#endif


//public draw functions
void B3L_DrawPixel_ZCheck(render_t *pRender,fBuff_t color,s32 x,s32 y,f32 z){
    zBuff_t *pZbuff = pRender->pZBuff;
    fBuff_t *pFrameBuff = pRender->pFrameBuff;
    zBuff_t *pCurrentPixelZ = pZbuff + (y*RENDER_RESOLUTION_X) + x;
    fBuff_t *pixel= pFrameBuff + (y*RENDER_X_SHIFT) + x; 
    zBuff_t compZ = CalZbuffValue(z);
    if (compZ<= *pCurrentPixelZ){          
        *pCurrentPixelZ = compZ;
        *pixel =color;           
    }
}





