#ifndef __CAT_M__
#define __CAT_M__

#include "b3dlib.h"
extern const float cat100_vect[267];
extern const float cat100_normal[522];
extern const uint16_t cat100_triIdx[522];
extern const uint8_t cat100_uv[1044];
extern const B3L_Mesh_t cat100_mesh;
extern const float cat100bound[24];
extern const uint32_t cat_pal[256];
extern const uint8_t cat_img[65536];
extern const B3L_texture_t cat_texture;


extern void InitCatObj(B3LMeshObj_t *pObj,f32 size);
#endif