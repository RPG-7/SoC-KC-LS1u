#ifndef __B3DLIB_H__
#define __B3DLIB_H__
/*
This is a 3d render lib for cortex m4/7 mcu with FPU 
(if B3L_ARM == 0, then any cpu with FPU is fine)

Left-hand coordinate was used in this lib
    ^ y
    |    ^ z
    |  /
    |/
    +--------> x
Screen coordinate is x y[0,0] from top left corner. The real render area is 
defined by the RENDER_RESOLUTION_X/Y, the whole frameBuff is defined by 
WHOLE_FRAME_BUFF_WIDTH/HEIGHT, the position shift of the render window is 
controlled by the address given to the init function.
0,0 ---------> x
   |
   |
   |
 y v
Always using row vector, so v * mat -> new v
Z buff range used [1.~0.] 1/z for near/ far plane (invert directX style), this kind of set could
help to get better resolution for floating point type z buff. For a small area rendering, could 
change the near plane to 0.1f. In a open space, 4.0f near plane could provide a resonable range 
to 400.0f.

Rotations used quaternion internally in transform struct
You could also set the rotation by euler angles in ZXY order, 
Positive rotation about an axis follow left-hand method.

light effect is done by setting the pixel alpha channel value and alpha blending
with a given color background, so after the render(),we need to call DMA2D in 
hardware or by software to apply the alpha blending.

*/

//#include <stdint.h>
#include "GlowTypedef.h"
#include <math.h>
#include "b3dlibCfg.h"
/*---------------------------------------------------------------------------*/
//not used for current state
#define B3L_FIX_BITS             10
  
//the obj buff at least has 2 slot
#if OBJ_BUFF_SIZE<2
#undef OBJ_BUFF_SIZE
#define OBJ_BUFF_SIZE            2
#endif
//some per defined value
#define RENDER_LINE_SKIP        (RENDER_X_SHIFT - RENDER_RESOLUTION_X)
#define VIDEO_BUFF_LENTH        ((RENDER_X_SHIFT)*(RENDER_RESOLUTION_Y))
#define Z_BUFF_LENTH            ((RENDER_RESOLUTION_X)*(RENDER_RESOLUTION_Y))

/*Type defines---------------------------------------------------------------*/
typedef float    f32;
typedef int32_t  s32;
typedef uint32_t u32;
typedef uint16_t u16;
typedef int16_t  s16;
typedef uint8_t  u8;
typedef int8_t   s8;
typedef uint32_t q32;

#define B3L_FIX_0_5        (1<<(B3L_FIX_BITS-1))
#define B3L_FIX_1          (1<<B3L_FIX_BITS)

#if Z_BUFF_LEVEL == 0
typedef  u8 zBuff_t;
#endif


#if Z_BUFF_LEVEL == 1
typedef u16 zBuff_t; 
#endif

#if Z_BUFF_LEVEL == 2
typedef float zBuff_t;
#endif

#if (FRAME_BUFF_COLOR_TYPE  == 0)
typedef  u32 fBuff_t;
typedef  u32 texLUT_t;
#define LIGHT_BIT           8
#endif
#if (FRAME_BUFF_COLOR_TYPE  == 1)
typedef  u16 fBuff_t;
typedef  u16 texLUT_t;
#define LIGHT_BIT           4
#endif
#if (FRAME_BUFF_COLOR_TYPE  == 2)
typedef  u16 fBuff_t;
typedef  u8  texLUT_t;
#define LIGHT_BIT           8
#endif


typedef struct{
    f32                 x;
    f32                 y;   
}vect2_t;

typedef struct{
    f32                 x;
    f32                 y;  
    f32                 z; 
}vect3_t;

//screen3_t is for 2d screen drawing step, it has same length as vect4_t
#define B3L_IN_SPACE             (0u)
//#define B3L_NEAR_PLANE_CLIP      (1u) ÐÞ¸Ä

typedef struct{
    int32_t             x;
    int32_t             y; 
    f32                 z;
    f32                 w;
    u32                 test;
}screen4_t;

typedef struct{
    f32                 x;
    f32                 y; 
    f32                 z;
    u32                 test;
}screen3f_t;

typedef struct{
    f32                 x;
    f32                 y; 
    f32                 z;
    f32                 w;  
}vect4_t;

typedef vect3_t euler3_t;
typedef vect4_t quat4_t;
//in column first order, mxy -- x is column num, y is the row number
typedef struct{
    //row0  row1    row2    row3    
    f32 m00;f32 m01;f32 m02;f32 m03;//column 0
    f32 m10;f32 m11;f32 m12;f32 m13;//column 1
    f32 m20;f32 m21;f32 m22;f32 m23;//column 2
    f32 m30;f32 m31;f32 m32;f32 m33;//column 3
}mat4_t;

typedef struct{
    //row0  row1    row2    row3    
    f32 m00;f32 m01;f32 m02;//column 0
    f32 m10;f32 m11;f32 m12;//column 1
    f32 m20;f32 m21;f32 m22;//column 2
}mat3_t;


typedef struct{
    quat4_t             quaternion;
    vect3_t             scale;
    vect3_t             translation;
}transform3D_t;


typedef struct {
    u16                 vectNum;
    u16                 lineNum;
    f32                 *pVect;
    u8                  *pLine;  
}B3L_Polygon_t;

typedef struct {
    u16                 vectNum;
    u16                 triNum;
    f32                 *pVect;
    u16                 *pTri;
    u8                  *pColorIdx;
    f32                 *pNormal;
}B3L_Mesh_NoTex_t;

typedef struct {
    u16                 vectNum;
    u16                 triNum;
    f32                 *pVect;
    u16                 *pTri;
    u8                  *pUv;
    f32                 *pNormal;
}B3L_Mesh_t;

//36 byte for single particle
typedef struct B3L_PARTICLE{
    struct B3L_PARTICLE *next;
    uint32_t            state;
    int32_t             life;
    vect3_t             position;
    vect3_t             delta;
}B3L_Particle_t;


#define LUT4         0
#define LUT16        1
#define LUT256       2
typedef struct{
    u16                 type;
    u16                 uvSize;
    texLUT_t            *pLUT;
    u8                  *pData;
    u8                  transColorIdx; 
}B3L_texture_t ;

/*
B3LObj_t state
   31     2423     1615      87
   ------------------------------------
31|$$$$$$$$|******RQ|PONMLKJI|***EDCBA|0
  ------------------------------------
  A-- mesh obj with texture
  B-- polygon obj
  C-- mesh obj without texture
  D-- particle generator obj
  E-- Bitmap obj
  I-- obj visualization
  J-- Back face culling clock wise
  K-- Back face culling anti-clock wise
  L-- fix render level switch
  M-- Particle generator acitve state
  N-- need update euler angle
  O-- need update matrix
  P-- special light value
  QR-- fix render level number
  $-- the 8 bit special light value defined by P

*/
#define OBJ_TYPE_MASK            0x000000FF
#define MESH_OBJ                            (0)
#define POLYGON_OBJ                         (1)
#define NOTEX_MESH_OBJ                      (2)
#define PARTICLE_GEN_OBJ                    (3)
#define BITMAP_OBJ                          (4)
//obj visualizable control
#define OBJ_VISUALIZABLE                    (8)

#define OBJ_BACK_CULLING_CLOCK              (9)
#define OBJ_BACK_CULLING_ANTICLOCK         (10)
#define OBJ_CULLING_MASK             0x00000600  
#define OBJ_CULLING_SHIFT             (9)

#define OBJ_IGNORE_RENDER_LEVEL            (11)
#define OBJ_PARTICLE_ACTIVE                (12)
#define OBJ_NEED_QUAT_UPDATE               (13)
#define OBJ_NEED_MATRIX_UPDATE             (14)
#define OBJ_SPECIAL_LIGHT_VALUE            (15)
//render stage information
#define OBJ_RENDER_LEVEL_MASK        0x00030000
#define OBJ_FIX_RENDER_LEVEL_SHIFT   (16)

#define OBJ_SPECIAL_LIGHT_MASK       0xFF000000
#define OBJ_SPECIAL_LIGHT_SHIFT      (24)

//all different obj types's size is <= sizeof(B3LObj_t)
typedef struct B3LOBJ{
    struct B3LOBJ       *privous;//8 4
    struct B3LOBJ       *next;//8 4
    u32                 state;//4 4
    mat3_t              mat;//36 36
    transform3D_t       transform;//40 40
    f32                 *pBoundBox;//8 4
    #if B3L_ARM  == 1   
    u32                 dummy[4];//   16----100 
    #else    
    u32                 dummy[6];//24 ----136
    #endif
}B3LObj_t;//16 not common on ARM32,24 not common on WIN64 ?why 96byte not 88?

typedef struct{
    B3LObj_t            *privous;
    B3LObj_t            *next;
    u32                 state;
    mat3_t              mat;
    transform3D_t       transform; 
    f32                 *pBoundBox;
    B3L_Mesh_t          *pMesh;
    B3L_texture_t       *pTexture;   
}B3LMeshObj_t;//16 not common on ARM32,24 not common on WIN64


typedef struct{
    B3LObj_t            *privous;
    B3LObj_t            *next;
    u32                 state;
    mat3_t              mat;
    transform3D_t       transform; 
    f32                 *pBoundBox;
    B3L_Mesh_NoTex_t    *pMesh; 
    texLUT_t            *pLUT;
}B3LMeshNoTexObj_t;//16 not common on ARM32,24 not common on WIN64

typedef struct{
    B3LObj_t            *privous;
    B3LObj_t            *next;
    u32                 state;
    mat3_t              mat;
    transform3D_t       transform;
    f32                 *pBoundBox; 
    B3L_Polygon_t       *pPolygon; 
    texLUT_t            color;
}B3LPolygonObj_t;//16 not common on ARM32,23 not common on WIN64

typedef struct{
    B3LObj_t            objBuff[OBJ_BUFF_SIZE];
    u32                 freeObjNum; 
    B3LObj_t            *pFreeObjs;   
    B3LObj_t            *pActiveMeshObjs;
#ifdef B3L_USING_PARTICLE
    B3LObj_t            *pActiveParticleGenObjs;
    u32                 freeParticleNum;
    B3L_Particle_t      *pfreeParticles;
#endif
}scene_t;

//state
typedef enum {   
    parallelLight = 0,
    dotLight = 1,
}lightType_e;
/*
light_t state
   31     2423     1615      87
   ------------------------------------
31|        |        |        |       A|0
  ------------------------------------
A-- 1, point light
    0, parallel light
*/
#define LIGHT_TYPE_BIT         (0)
#define POINT_LIGHT         (1u<<LIGHT_TYPE_BIT)
#define PARALLEL_LIGHT      (0u<<LIGHT_TYPE_BIT)
typedef struct{
    u32                 state;
    vect3_t             lightVect;
    u32                 color;
    f32                 factor_0;
    f32                 factor_1;
}light_t;

/*
camera_t state
   31     2423     1615      87
   ------------------------------------
31|********|********|*ON*****|******BA|0
  ------------------------------------

A-- camera track obj mode
B-- Project mode
N-- need update euler angle
O-- need update matrix
*/
#define  B3L_CAMERA_TRACK_OBJ_MODE           (0)
#define  B3L_PROJECT_MODE                    (1)
#define  OTHROGRAPHIC_PROJECT                (1u<<B3L_PROJECT_MODE)
#define  PERSPECTIVE_PROJECT                 (0u<<B3L_PROJECT_MODE)
//bit 24
#define  CAM_NEED_QUAT_UPDATE                OBJ_NEED_QUAT_UPDATE            
//bit 25
#define  CAM_NEED_MATRIX_UPDATE              OBJ_NEED_MATRIX_UPDATE
typedef struct{
    u32                 state;
    f32                 aspectRate;
    f32                 focalLength;
    mat3_t              mat;
    transform3D_t       transform; 
    mat4_t              clipMat;
    mat4_t              camW2CMat;
    vect3_t             targetPosition;
    quat4_t             targetQuat;
    B3LObj_t           *pTrackObj;
}camera_t;

typedef struct{   
    fBuff_t             *pFrameBuff;
    zBuff_t             *pZBuff;
    screen3f_t          *pVectBuff;
    camera_t            camera;
    light_t             light;    
    scene_t             scene;
    f32                 lvl0Distance;
    f32                 lvl1Distance;
    f32                 farPlane;
    f32                 nearPlane;
    u8                  lvl1Light;
}render_t;   


typedef struct PARTICLEGENOBJ{
    B3LObj_t            *privous;//8  4
    B3LObj_t            *next;//8   4
    u32                 state;//4   4
    mat3_t              mat;//36    36
    transform3D_t       transform;//40    40
    u32                 lastTime;//4   4
    u32                 particleNum;//4   4
    B3L_Particle_t      *pParticleActive;//8   4   
    void      (*DrawFunc)(B3L_Particle_t *, screen4_t *,fBuff_t *,zBuff_t *);//8   4
    void      (*PtlUpdFunc)(u32,struct PARTICLEGENOBJ *,mat3_t *,vect3_t *,render_t *); //8    4  
    //time, self, obj->world matrix,free particle num pointer,free particle pool  
}B3LParticleGenObj_t; //15 not common on ARM32,22 not common on WIN64

typedef void (*B3L_DrawFunc_t)(B3L_Particle_t *, screen4_t *,fBuff_t *,zBuff_t *);
/*Useful macros--------------------------------------------------------------*/
#define B3L_SET(PIN,N)  (PIN |=  (1u<<N))
#define B3L_CLR(PIN,N)  (PIN &= ~(1u<<N))
#define B3L_TEST(PIN,N) (PIN &   (1u<<N))

#define B3L_logVec2(v)\
  printf("Vector 2: %.3f %.3f\n",((v).x),((v).y))
#define B3L_logVec3(v)\
  printf("Vector 3: %.3f %.3f %.3f\n",((v).x),((v).y),((v).z))
#define B3L_logVec4(v)\
  printf("Vector 4: %.3f %.3f %.3f %.3f\n",((v).x),((v).y),((v).z),((v).w))
#define B3L_logMat4(m)\
  printf("Matrix4:\n  %.3f %.3f %.3f %.3f\n  %.3f %.3f %.3f %.3f\n  %.3f %.3f %.3f %.3f\n  %.3f %.3f %.3f %.3f\n"\
   ,(m).m00,(m).m10,(m).m20,(m).m30,\
    (m).m01,(m).m11,(m).m21,(m).m31,\
    (m).m02,(m).m12,(m).m22,(m).m32,\
    (m).m03,(m).m13,(m).m23,(m).m33)
#define B3L_logMat3(m)\
  printf("Matrix3:\n  %.3f %.3f %.3f \n  %.3f %.3f %.3f \n  %.3f %.3f %.3f \n"\
   ,(m).m00,(m).m10,(m).m20,\
    (m).m01,(m).m11,(m).m21,\
    (m).m02,(m).m12,(m).m22)
    

/*Function declear-----------------------------------------------------------*/
/*-----------------------------------------------------------------------------
Render functions
-----------------------------------------------------------------------------*/
extern void     B3L_RenderInit(render_t *pRender,fBuff_t *pFrameBuff);
extern void     B3L_RenderScence(render_t *pRender); //draw work 
extern void     B3L_ResetScene(scene_t *pScene); //reset all the scene resource
extern void     B3L_NewRenderStart(render_t *pRender,fBuff_t color); //clear buffs
extern void     B3L_Update(render_t *pRender,u32 time); //update particles etc
/*-----------------------------------------------------------------------------
Render obj functions
-----------------------------------------------------------------------------*/
extern u32                  B3L_GetFreeObjNum(render_t *pRender);
extern B3LObj_t             *B3L_GetFreeObj(render_t *pRender);
extern B3LMeshObj_t         *B3L_GetFreeMeshObj(render_t *pRender);
extern B3LMeshNoTexObj_t    *B3L_GetFreeMeshNoTexObj(render_t *pRender);
extern B3LPolygonObj_t      *B3L_GetFreePolygonObj(render_t *pRender);
#ifdef B3L_USING_PARTICLE
extern B3LParticleGenObj_t  *B3L_GetFreeParticleGeneratorObj(render_t *pRender);
#endif
extern void                 B3L_AddObjToRenderList(B3LObj_t *pObj, render_t *pRender);
extern void                 B3L_PopObjFromRenderList(B3LObj_t *pObj, render_t *pRender);
extern void                 B3L_ReturnObjToInactiveList(B3LObj_t *pObj,  render_t *pRender);
/*-----------------------------------------------------------------------------
Target rotate control functions
-----------------------------------------------------------------------------*/
extern void     B3L_RotateObjInOX(quat4_t *pQuat,f32 angle);
extern void     B3L_RotateObjInOY(quat4_t *pQuat,f32 angle);
extern void     B3L_RotateObjInOZ(quat4_t *pQuat,f32 angle);
extern void     B3L_RotateObjInWX(quat4_t *pQuat,f32 angle);
extern void     B3L_RotateObjInWY(quat4_t *pQuat,f32 angle);
extern void     B3L_RotateObjInWZ(quat4_t *pQuat,f32 angle);
#define         SET_OBJ_ROTATE_BY_EULER(pObj,pEuler)          B3L_EulerToQuaternion(pEuler,&((pObj)->transform.quaternion);\
                                                                        B3L_SET((pObj)->state,OBJ_NEED_MATRIX_UPDATE)
#define         ROTATE_IN_BODY_X(pObj,angle)                  B3L_RotateObjInOX(&((pObj)->transform.quaternion),angle);\
                                                                        B3L_SET((pObj)->state,OBJ_NEED_MATRIX_UPDATE)
#define         ROTATE_IN_BODY_Y(pObj,angle)                  B3L_RotateObjInOY(&((pObj)->transform.quaternion),angle);\
                                                                        B3L_SET((pObj)->state,OBJ_NEED_MATRIX_UPDATE)
#define         ROTATE_IN_BODY_Z(pObj,angle)                  B3L_RotateObjInOZ(&((pObj)->transform.quaternion),angle);\
                                                                        B3L_SET((pObj)->state,OBJ_NEED_MATRIX_UPDATE)
#define         ROTATE_IN_WORLD_X(pObj,angle)                 B3L_RotateObjInWX(&((pObj)->transform.quaternion),angle);\
                                                                        B3L_SET((pObj)->state,OBJ_NEED_MATRIX_UPDATE)
#define         ROTATE_IN_WORLD_Y(pObj,angle)                 B3L_RotateObjInWY(&((pObj)->transform.quaternion),angle);\
                                                                        B3L_SET((pObj)->state,OBJ_NEED_MATRIX_UPDATE)
#define         ROTATE_IN_WORLD_Z(pObj,angle)                 B3L_RotateObjInWZ(&((pObj)->transform.quaternion),angle);\
                                                                        B3L_SET((pObj)->state,OBJ_NEED_MATRIX_UPDATE)
#define         SYNC_ROTATION_STATE_NOW(pObj)                 if(B3L_TEST((pObj)->state,OBJ_NEED_QUAT_UPDATE)){\
                                                                   B3L_MatrixToQuaternion(&((pObj)->mat),&((pObj)->transform.quaternion));\
                                                                   B3L_CLR((pObj)->state,OBJ_NEED_QUAT_UPDATE);}\
                                                              else if(B3L_TEST((pObj)->state,OBJ_NEED_MATRIX_UPDATE)){\
                                                                   B3L_QuaternionToMatrix(&((pObj)->transform.quaternion),&((pObj)->mat));\
                                                                   B3L_CLR((pObj)->state,OBJ_NEED_MATRIX_UPDATE);}
/*-----------------------------------------------------------------------------
Camera functions
-----------------------------------------------------------------------------*/
// you could use obj rotate macros for camera also
extern void     B3L_InitCamera(render_t *pRender);
extern void     B3L_SetOrthographicProject(render_t *pRender);
extern void     B3L_SetPerspectiveProject(render_t *pRender);//default mode
//call after you reset the aspect ratio, focus length, near/far plane, project mode 
extern void     B3L_UpdateClipMatrix(render_t *pRender);
extern void     B3L_CamSetFocusLengthByFOV(render_t *pRender, f32 fov);
extern void     B3L_CameraMoveTo(vect3_t position,camera_t *pCam);
extern void     B3L_CameraLookAt(camera_t *pCam, vect3_t *pAt,vect3_t *pUp);
extern void     B3L_CamStopTrack(camera_t *pCam);
extern void     B3L_CamStartTrack(camera_t *pCam);
extern void     B3L_CamInitTrack(camera_t *pCam,B3LObj_t *pObj,f32 camX,f32 camY,f32 camZ,f32 lookAtX,f32 lookAtY,f32 lookAtZ);
/*-----------------------------------------------------------------------------
Light functions
-----------------------------------------------------------------------------*/
extern void     B3L_ResetLight(light_t *pLight);
extern void     B3L_SetLightType(render_t *pRender,lightType_e type);
extern void     B3L_SetLightVect(render_t *pRender, f32 x,f32 y,f32 z);
/*-----------------------------------------------------------------------------
Math functions
-----------------------------------------------------------------------------*/
extern f32      B3L_sin(f32 in);
extern f32      B3L_cos(f32 in);
extern f32      B3L_asin(f32 in);
extern f32      B3L_atan2(f32 y,f32 x);
extern void     B3L_SetSeed(u32 seed);
extern u32      B3L_Random(void); 
extern u32      B3L_Rnd(u32 range);
#define         B3L_MIN(a,b)      ((a) >= (b) ? (b) : (a))
#define         B3L_MAX(a,b)      ((a) >= (b) ? (a) : (b))
/*-----------------------------------------------------------------------------
Vector functions
-----------------------------------------------------------------------------*/
extern vect2_t  B3L_Vect2(f32 x,f32 y);
extern vect3_t  B3L_Vect3(f32 x,f32 y,f32 z);
extern vect4_t  B3L_Vect4(f32 x,f32 y,f32 z,f32 w);
#define         B3L_VECT2_SET(v,vx,vy)         v.x=vx;v.y=vy
#define         B3L_VECT3_SET(v,vx,vy,vz)      v.x=vx;v.y=vy;v.z=vz
#define         B3L_VECT4_SET(v,vx,vy,vz,vw)   v.x=vx;v.y=vy;v.z=vz;v.w=vw
extern f32      B3L_Vec2Length(vect2_t *pV);
extern void     B3L_Vect2Normalize(vect2_t *pV, vect2_t *pResult);
extern f32      B3L_Vect3Length(vect3_t *pV);
extern void     B3L_Vect3Normalize(vect3_t *pV,vect3_t *pResult);
extern void     B3L_Vect3Add(vect3_t *pVa,vect3_t *pVb,vect3_t *pResult);
extern void     B3L_Vect3Sub(vect3_t *pVa,vect3_t *pVb,vect3_t *pResult);
extern f32      B3L_Vect3Dot(vect3_t *pA, vect3_t *pB);
extern void     B3L_Vect3Cross(vect3_t *pA, vect3_t *pB, vect3_t *pResult);
extern void     B3L_Vect3Interp(vect3_t *pVa,vect3_t *pVb,vect3_t *pResult,f32 t);
extern void     B3L_Vect3Scale(vect3_t *pV,f32 scale,vect3_t *pResult);
/*-----------------------------------------------------------------------------
Rotation convert functions
-----------------------------------------------------------------------------*/
extern void     B3L_EulerToMatrix(euler3_t *pEuler,mat3_t *pMat);
extern void     B3L_MatrixToEuler(mat3_t *pMat, euler3_t *pEuler);
extern void     B3L_QuaternionToMatrix(quat4_t *pQuat, mat3_t *pMat);
extern void     B3L_MatrixToQuaternion(mat3_t *pMat, quat4_t *pQuat);
extern void     B3L_EulerToQuaternion(euler3_t *pEuler,quat4_t *pQuat);
extern void     B3L_QuaternionToEuler(quat4_t *pQuat,euler3_t *pEuler);
/*-----------------------------------------------------------------------------
Quaternion functions
-----------------------------------------------------------------------------*/
#define         SET_IDENTITY_P_QUAT(a)       (a)->x=0.0f;(a)->y=0.0f;(a)->z=0.0f;(a)->w=1.0f
extern void     B3L_QuatMult(quat4_t *pL,quat4_t *pR, quat4_t *pResult);
extern f32      B3L_QuatDot(quat4_t *pL,quat4_t *pR);
extern void     B3L_CreateQuaternionByAxisAngle(vect3_t *pAxis, f32 angle, quat4_t *pResult);
extern void     B3L_FromToRotation(vect3_t *pFrom, vect3_t *pTo,quat4_t *pResult);
extern void     B3L_LookRotation(vect3_t *pA, vect3_t *pB, vect3_t *pUp, quat4_t *pResult);
extern void     B3L_CreateLookAtQuaternion(vect3_t *pFrom, vect3_t *pAt, vect3_t *pUp, quat4_t *pResult);
extern void     B3L_QuatCreateXRotate(quat4_t *pQ,f32 angle);
extern void     B3L_QuatCreateYRotate(quat4_t *pQ,f32 angle);
extern void     B3L_QuatCreateZRotate(quat4_t *pQ,f32 angle);
extern void     B3L_QuaternionInterp(quat4_t *pFrom,quat4_t *pTo,quat4_t *pResult, f32 t);

/*-----------------------------------------------------------------------------
Particle functions
-----------------------------------------------------------------------------*/
#ifdef B3L_USING_PARTICLE
extern B3L_Particle_t       *B3L_GetFreeParticle(scene_t *pScene);
extern u32                  B3L_GetFreeParticleNum(render_t *pRender);
extern void                 B3L_ReturnParticleToPool(B3L_Particle_t *pParticle,scene_t *pScene);
extern void                 B3L_AddParticleToGenerator(B3L_Particle_t *pParticle,B3LParticleGenObj_t  *pGenerator);
extern void                 B3L_UpdateAllParticlesStatesInGen(render_t *pRender,B3LParticleGenObj_t *pGen,
                                                              u32 deltaTime,vect3_t *pForce);
#define                     B3L_SET_PARTICLE_POSITION(pP,px,py,pz)   pP->position.x=px;pP->position.y=py;pP->position.z=pz                                                                                                
#define                     B3L_SET_PARTICLE_DELTA(pP,dx,dy,dz)      pP->delta.x=dx;pP->delta.y=dy;pP->delta.z=dz                                                                                                
#endif  //end of  B3L_USING_PARTICLE
/*-----------------------------------------------------------------------------
Matrix functions
-----------------------------------------------------------------------------*/
extern void     B3L_InitUnitMat3(mat3_t *pMat);
extern void     B3L_Mat3XRotate(mat3_t *pMat,f32 angle);
extern void     B3L_Mat3YRotate(mat3_t *pMat,f32 angle);
extern void     B3L_Mat3ZRotate(mat3_t *pMat,f32 angle);
extern void     B3L_CreateO2WMat(mat3_t *pRMat, vect3_t *pTranslation, vect3_t *pScale, mat4_t *pResult);
extern void     B3L_InitMat4One(mat4_t *pMat);
extern void     B3L_TransposeMat4(mat4_t *pMat);
extern void     B3L_Mat4XMat4(mat4_t *pMat1,mat4_t *pMat2, mat4_t *pMat3);
extern void     B3L_Mat3MultMat3ABB(mat3_t *pMatA,mat3_t *pMatB);
extern void     B3L_Mat3MultMat3ABA(mat3_t *pMatA,mat3_t *pMatB);
extern void     B3L_MakeScaleMatrix(f32 scaleX,f32 scaleY,f32 scaleZ,mat4_t *pMat);
extern void     B3L_MakeTranslationMat(f32 offsetX,f32 offsetY,f32 offsetZ,mat4_t *pMat);
extern void     B3L_MakeO2CMatrix(mat3_t *pRMat,vect3_t *pScale,vect3_t *pTrans,mat4_t *pCamMat, mat4_t *pResult);
extern void     B3L_Vect3MulMat3(vect3_t *pV, mat3_t *pMat, vect3_t *pResult);
extern void     B3L_Point3MulMat4(vect3_t *pV, mat4_t *pMat, vect3_t *pResult);
/*-----------------------------------------------------------------------------
Resolution helper functions
-----------------------------------------------------------------------------*/
extern fBuff_t *B3L_3dRenderAreaShiftCal(fBuff_t *startOfWholeFrameBuff, u32 x, u32 y);
/*-----------------------------------------------------------------------------
After effect functions
-----------------------------------------------------------------------------*/
extern void                 B3L_AppliedLightFromAlpha(render_t *pRender);
extern void                 B3L_AppliedLightFromAlpha4444To8888(render_t *pRender,u32 *pTgetBuff);
#if  B3L_DMA2D  == 1
//Call by flip function
//irq config
#define B3L_DMA2D_IRQ_PRIORITY        2U
#define B3L_DMA2D_IRQ_SUB_PRIORITY    0U
//call init during the init phase
extern void                 B3L_DMA2D_Init(void);
//call replace the flip()
extern void                 B3L_DMA2DAppliedLightAndUpScale(u32 *addr,u32 wholeWidth,u32 wholeheight,u32 invLightColor);
extern void                 B3L_DMA2DAppliedLightTo565(u32 *addr,u32 wholeWidth,u32 wholeheight,u32 invLightColor);
//test before every render
extern bool                 B3L_DMA2DOcupied(void);
//irq handler 
extern void                 DMA2D_IRQHandler(void);
#endif
/*-----------------------------------------------------------------------------
Draw functions
-----------------------------------------------------------------------------*/
extern void B3L_DrawPixel_ZCheck(render_t *pRender,fBuff_t color,s32 x,s32 y,f32 z);
//extern void     B3L_SetFont();
//extern void     B3L_SetFrontColor();
//extern void     B3L_SetBackColor();
//extern void     B3L_PrintStr();
//extern void     B3L_DrawLine();
//extern void     B3L_Draw



#endif//end of file
