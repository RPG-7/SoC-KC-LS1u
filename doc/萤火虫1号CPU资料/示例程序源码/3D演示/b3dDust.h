#ifndef  __B3D_DUST_H__
#define  __B3D_DUST_H__

#include "b3dlib.h"

#define LIFE_BASE               8000
#define DUSTNUM                 128
#define DUSTRANGE               30.0f
#define DUSTRANGE_DOUBLE        60.0f
#define DUSTRESETDISTANCE_SQ    1600.0f

//need to be re-cal carefully
#define DUST_Z_BUFF_SCALE_FACT   190.0f
#define INV65535                1.52590218967e-5f

typedef struct{
    vect3_t    position;
    s32        life;
}dust_t;



void DustInit(void);
void DustUpdateAndRender(render_t *pRender,B3LObj_t *pObj,u32 time);
#endif
