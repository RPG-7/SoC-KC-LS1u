#ifndef __B3D_TEST_OBJ_H__
#define __B3D_TEST_OBJ_H__
#include "b3dlib.h"

/*-----------------------------------------------------------------------------
Demo objs functions
-----------------------------------------------------------------------------*/
extern void                 B3L_InitBoxObj(B3LMeshObj_t *pObj,f32 size);
extern void                 B3L_InitBoxObjNoTexture(B3LMeshNoTexObj_t *pObj,f32 size);
extern void                 B3L_InitBoxObjPolygon(B3LPolygonObj_t *pObj,f32 size);
extern void                 B3L_InitDemoParticleGenObj(B3LParticleGenObj_t  *pParticleGen);
#ifdef B3L_USING_PARTICLE
extern void                 B3L_DefaultParticleDrawFunc(B3L_Particle_t *pParticle, screen4_t *pScreenVect,fBuff_t *pFBuff,zBuff_t *pZBuff);
extern void                 B3L_DefaultParticleUpdFunc(u32 time,B3LParticleGenObj_t *pSelf,mat3_t *pMat,vect3_t *pTrans,render_t *pRender);
#endif
#endif