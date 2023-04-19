
#include "b3dTestObj.h"

#ifdef WIN32 
#define __attribute__(A)
#endif

const u8 B3L_polygonIdx[24] = {
    0,1,0,2,1,3,2,3,0,4,1,5,2,6,3,7,4,5,4,6,5,7,6,7
};


const f32   B3L_boxVect[24] = {
    /* 0 front, bottom, right */
     0.5f, -0.5f, -0.5f,
     /* 1 front, bottom, left */
    -0.5f, -0.5f, -0.5f,
     /* 2 front, top,    right */
     0.5f,  0.5f, -0.5f,
     /* 3 front, top,    left */
    -0.5f,  0.5f, -0.5f,
     /* 4 back,  bottom, right */
     0.5f, -0.5f,  0.5f,
     /* 5 back,  bottom, left */
    -0.5f, -0.5f,  0.5f,
     /* 6 back,  top,    right */
     0.5f,  0.5f,  0.5f,
     /* 7 back,  top,    left */
    -0.5f,  0.5f,  0.5f
};

const u16 B3L_boxTri[36] ={
    3, 0, 2, /* front  */
    1, 0, 3,
    0, 4, 2, /* right  */
    2, 4, 6,
    4, 5, 6, /* back   */
    7, 6, 5,
    3, 7, 1, /* left   */
    1, 7, 5,
    6, 3, 2, /* top    */
    7, 3, 6,
    1, 4, 0, /* bottom */
    5, 4, 1
};

const u8 B3L_boxColorIdx[12]={
    0,1,2,3,4,5,
    6,7,8,9,10,11
};



#define m 15
const u8 B3L_boxUV[72]={
    0,0,  m,m,  m,0,\
    0,m,  m,m,  0,0,\
    m,m,  m,0,  0,m,\
    0,m,  m,0,  0,0,\
    m,0,  0,0,  m,m,\
    0,m,  m,m,  0,0,\
    0,0,  0,m,  m,0,\
    m,0,  0,m,  m,m,\
    0,0,  m,m,  m,0,\
    0,m,  m,m,  0,0,\
    m,0,  0,m,  m,m,\
    0,0,  0,m,  m,0
};
#undef m

const f32 B3L_boxBound[6]={
    1.0f,1.0f,1.0f,
    -1.0f,-1.0f,-1.0f,
};

const f32 B3L_boxNormal[36]={
    0.0f,0.0f,-1.0f,
    0.0f,0.0f,-1.0f,
    1.0f,0.0f, 0.0f,
    1.0f,0.0f, 0.0f,
    0.0f,0.0f, 1.0f,
    0.0f,0.0f, 1.0f,
    -1.0f,0.0f, 0.0f,
    -1.0f,0.0f, 0.0f,
    0.0f,1.0f,0.0f,
    0.0f,1.0f,0.0f,
    0.0f,-1.0f,0.0f,
    0.0f,-1.0f,0.0f,
};

#if (FRAME_BUFF_COLOR_TYPE == 0) ||(FRAME_BUFF_COLOR_TYPE == 2)
const u32 B3L_boxLUT32bit[16]={
    0XFF000000,0XFF1D2B53,0XFF7E2553,0XFF008751,
    0XFFAB5236,0XFF5F574F,0XFFC2C3C7,0XFFFFF1E8,
    0XFFFF004D,0XFFFFA300,0XFFFFEC27,0XFF00E436,
    0XFF29ADFF,0XFF83769C,0XFFFF77A8,0XFFFFCCAA
};
#endif
#if FRAME_BUFF_COLOR_TYPE == 1
const u16 B3L_boxLUT4444[16]={
    0XF000,0XF235,0XF825,0XF085,
    0XFB53,0XF655,0XFCCC,0XFFFF,
    0XFF05,0XFFA0,0XFFF2,0XF0E3,
    0XF3BF,0XF87A,0XFF7B,0XFFDB
};
#endif
#if FRAME_BUFF_COLOR_TYPE == 2
const u8 B3L_boxLUTL8Idx[16]={
    0,1,2,3,
    4,5,6,7,
    8,9,10,11,
    12,13,14,15
};
#endif

const u8 B3L_boxTexData[128]={
	0X44, 0X44, 0X44, 0X44, 0X44, 0X44, 0X44, 0X44, 0X44, 0X99, 0X99, 0X99, 0X99, 0X99, 0X99, 0X49, 
	0X14, 0X73, 0X77, 0XFF, 0XFF, 0X22, 0XD2, 0X49, 0X14, 0XA3, 0XAA, 0XAA, 0XAA, 0XAA, 0XDA, 0X49, 
	0X14, 0XB3, 0XBB, 0XBB, 0XBB, 0XBB, 0XDB, 0X49, 0X14, 0XC3, 0XCC, 0XCC, 0XCC, 0XCC, 0XDC, 0X49, 
	0X14, 0X83, 0X88, 0X88, 0X88, 0X88, 0XD8, 0X49, 0X14, 0XE3, 0XEE, 0XEE, 0XEE, 0XEE, 0XDE, 0X49, 
	0X14, 0XED, 0XEE, 0XEE, 0XEE, 0XEE, 0X5E, 0X49, 0X14, 0X8D, 0X88, 0X88, 0X88, 0X88, 0X58, 0X49, 
	0X14, 0XCD, 0XCC, 0XCC, 0XCC, 0XCC, 0X5C, 0X49, 0X14, 0XBD, 0XBB, 0XBB, 0XBB, 0XBB, 0X5B, 0X49, 
	0X14, 0XAD, 0XAA, 0XAA, 0XAA, 0XAA, 0X5A, 0X49, 0X14, 0X2D, 0X22, 0XFF, 0XFF, 0X77, 0X57, 0X49, 
	0X14, 0X11, 0X11, 0X11, 0X11, 0X11, 0X11, 0X44, 0X66, 0X66, 0X66, 0X66, 0X66, 0X66, 0X66, 0X66, 
};
const B3L_Mesh_t B3L_box = {
                      .vectNum = 8,
                      .triNum  = 12,
                      .pVect   = (f32 *)B3L_boxVect,
                      .pTri    = (u16 *)B3L_boxTri,
                      .pUv     = (u8 *)B3L_boxUV,
                      .pNormal = (f32 *)B3L_boxNormal
                      };
const B3L_Mesh_NoTex_t B3L_box_noTex = {
                      .vectNum = 8,
                      .triNum  = 12,
                      .pVect   = (f32 *)B3L_boxVect,
                      .pTri    = (u16 *)B3L_boxTri,
                      .pColorIdx  = (u8  *)B3L_boxColorIdx,
                      .pNormal = (f32 *)B3L_boxNormal
                      };

const B3L_Polygon_t B3L_box_Polygon = {
                        .vectNum = 8,
                        .lineNum = 12,
                        .pVect = (f32 *)B3L_boxVect,
                        .pLine = (u8 *) B3L_polygonIdx
                        };


const B3L_texture_t B3L_boxTexture = { 
                                 .type    = LUT16,
                                 .uvSize  = 16,
                                 #if FRAME_BUFF_COLOR_TYPE == 0
                                 .pLUT    = (texLUT_t *)B3L_boxLUT32bit,
                                 #endif
                                 #if FRAME_BUFF_COLOR_TYPE == 1
                                 .pLUT    =  (texLUT_t *)B3L_boxLUT4444,
                                 #endif
                                 #if FRAME_BUFF_COLOR_TYPE == 2
                                 .pLUT    =  (texLUT_t *)B3L_boxLUTL8Idx,
                                 #endif
                                 .pData   = (u8 *)B3L_boxTexData,
                                 .transColorIdx = 16
};

/*-----------------------------------------------------------------------------
Testing functions
-----------------------------------------------------------------------------*/
void B3L_InitBoxObj(B3LMeshObj_t *pObj,f32 size){
    pObj->privous = (B3LObj_t *)NULL;
    pObj->next = (B3LObj_t *)NULL;
    pObj->pMesh = (B3L_Mesh_t *)&B3L_box;
    pObj->pTexture = (B3L_texture_t *)&B3L_boxTexture;
    B3L_VECT3_SET(pObj->transform.translation,0.0f,0.0f,0.0f);
    B3L_VECT3_SET(pObj->transform.scale,size,size,size);
    pObj->pBoundBox = (f32 *)B3L_boxBound;

    B3L_SET(pObj->state,MESH_OBJ); 
    B3L_SET(pObj->state,OBJ_VISUALIZABLE);

    B3L_SET(pObj->state,OBJ_BACK_CULLING_CLOCK);
}


void B3L_InitBoxObjNoTexture(B3LMeshNoTexObj_t *pObj,f32 size){
    pObj->privous = (B3LObj_t *)NULL;
    pObj->next = (B3LObj_t *)NULL;
    pObj->pMesh = (B3L_Mesh_NoTex_t *)&B3L_box_noTex;
    B3L_VECT3_SET(pObj->transform.translation,0.0f,0.0f,0.0f);
    B3L_VECT3_SET(pObj->transform.scale,size,size,size);
    pObj->pBoundBox = (f32 *)B3L_boxBound;
    #if FRAME_BUFF_COLOR_TYPE == 0
    pObj->pLUT =  (texLUT_t *)B3L_boxLUT32bit;
    #endif
    #if FRAME_BUFF_COLOR_TYPE == 1
    pObj->pLUT =  (texLUT_t *)B3L_boxLUT4444;
    #endif
    #if FRAME_BUFF_COLOR_TYPE == 2
    pObj->pLUT =  (texLUT_t *)B3L_boxLUTL8Idx;
    #endif
    B3L_SET(pObj->state,NOTEX_MESH_OBJ); 
    B3L_SET(pObj->state,OBJ_VISUALIZABLE);

    B3L_SET(pObj->state,OBJ_BACK_CULLING_CLOCK);

}


void B3L_InitBoxObjPolygon(B3LPolygonObj_t *pObj,f32 size){
    pObj->privous = (B3LObj_t *)NULL;
    pObj->next = (B3LObj_t *)NULL;
    pObj->pPolygon = (B3L_Polygon_t *)&B3L_box_Polygon;
    B3L_VECT3_SET(pObj->transform.translation,0.0f,0.0f,0.0f);
    B3L_VECT3_SET(pObj->transform.scale,size,size,size);
    pObj->pBoundBox = (f32 *)B3L_boxBound;
    #if FRAME_BUFF_COLOR_TYPE == 0
    pObj->color = 0xFF00FF00;
    #endif
    #if FRAME_BUFF_COLOR_TYPE == 1
    pObj->color = 0xF0F0;
    #endif
    #if FRAME_BUFF_COLOR_TYPE == 2
    pObj->color = 1;
    #endif
    B3L_SET(pObj->state,POLYGON_OBJ); 
    B3L_SET(pObj->state,OBJ_VISUALIZABLE);

    //B3L_SET(pObj->state,OBJ_BACK_CULLING_CLOCK);

}

__attribute__((always_inline)) static  inline void Vect3_Scale(vect3_t *pSource,f32 factor,vect3_t *pResult){
    f32 x = pSource->x; f32 y = pSource->y; f32 z = pSource->z;
    pResult->x = x*factor;
    pResult->y = y*factor;
    pResult->z = z*factor;
}
#ifdef B3L_USING_PARTICLE
void     B3L_InitDemoParticleGenObj(B3LParticleGenObj_t  *pParticleGen){
    //todo create a generator based on default functions
    pParticleGen->DrawFunc = B3L_DefaultParticleDrawFunc;
    pParticleGen->PtlUpdFunc = B3L_DefaultParticleUpdFunc;
    pParticleGen->lastTime = 0;
    pParticleGen->particleNum = 0;
    B3L_VECT3_SET(pParticleGen->transform.translation,0.0f,0.0f,0.0f);
    B3L_VECT4_SET(pParticleGen->transform.quaternion,0.0f,0.0f,0.0f,1.0f);
    pParticleGen->pParticleActive = (B3L_Particle_t *)NULL;
    B3L_SET(pParticleGen->state,PARTICLE_GEN_OBJ);
    B3L_SET(pParticleGen->state,OBJ_VISUALIZABLE);
    B3L_SET(pParticleGen->state,OBJ_PARTICLE_ACTIVE);


}


void    B3L_DefaultParticleUpdFunc(u32 time,B3LParticleGenObj_t *pSelf,mat3_t *pMat,vect3_t *pTrans,render_t *pRender){
//TODO here
    u32 deltaTime;
    u32 i;
    B3L_Particle_t *pParticle;
    //B3L_Particle_t *pPrevParticle;
    vect3_t  delta;
    vect3_t  force ={.x=0.0f,.y=-0.00001f,.z=0.0f};
    u32 newParticleNum = 10;
    if(pSelf->lastTime == 0){//this is the first time a generator is updated, only get the time
        pSelf->lastTime = time;
        return;
    }else{
        //calculate the delta time 
        deltaTime = time - pSelf->lastTime;
        pSelf->lastTime = time;
        //add necessary new particles into the list
        i = B3L_MIN(pRender->scene.freeParticleNum,newParticleNum);
        s32 randValue;
        f32 inv256 = 0.00390625f;
        while(i--){
            pParticle = B3L_GetFreeParticle(&(pRender->scene));
            //setup position
            B3L_SET_PARTICLE_POSITION(pParticle,pTrans->x,pTrans->y,pTrans->z);
            //setup lifetime
            pParticle->life = 200;
            //setup init delta
            randValue = B3L_Random();
            randValue = randValue&0x000000FF;
            delta.x = 0.5f*((f32)(randValue-128))*inv256;//need a fast rendom function here!
            randValue = B3L_Random();
            randValue = randValue&0x000000FF;
            delta.y = 0.5f*((f32)randValue)*inv256;
            randValue = B3L_Random();
            randValue = randValue&0x000000FF;
            delta.z = 0.5f*((f32)(randValue-128))*inv256;
            B3L_Vect3MulMat3(&delta, pMat, &delta);
            B3L_SET_PARTICLE_DELTA(pParticle,delta.x,delta.y,delta.z);

            B3L_AddParticleToGenerator(pParticle,pSelf);
        }
        Vect3_Scale(&force,(f32)deltaTime,&force);//force * time
        B3L_UpdateAllParticlesStatesInGen(pRender,pSelf,deltaTime,&force);
    }
}
#ifdef WIN32 
#define __attribute__(A)
#endif
__attribute__((always_inline)) static  inline s32   B3L_RoundingToU(f32 in){
    return (u32)roundf(in); 
}
__attribute__((always_inline)) static  inline u32   SatToU16(u32 in){
    const uint32_t max = ((1U << 16) - 1U);
    if (in > max){
        return max;
    }else{
        return in;
    }
}

__attribute__((always_inline)) static  inline u32   SatToU8(u32 in){
    const uint32_t max = ((1U << 8) - 1U);
    if (in > max){
        return max;
    }else{
        return in;
    }
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

void B3L_DefaultParticleDrawFunc(B3L_Particle_t *pParticle, screen4_t *pScreenVect,fBuff_t *pFBuff,zBuff_t *pZBuff){

    zBuff_t compZ = CalZbuffValue(pScreenVect->z);
    s32     intX = pScreenVect->x;
    s32     intY = pScreenVect->y;
    u32     shift = RENDER_RESOLUTION_X*intY + intX;
    pZBuff = (pZBuff+shift);
    shift = RENDER_X_SHIFT *intY + intX;
    pFBuff = (pFBuff+shift);
    if (compZ<= *pZBuff){
        *pZBuff = compZ;
        *pFBuff = 0XFFFFFFFF;
    }

}

#endif