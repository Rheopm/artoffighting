#ifndef __COMMUN_H__
#define __COMMUN_H__
#include <genesis.h>

#if LIB_DEBUG
#define DEBUG_PRINT(x) KLog(x)
#else
#define DEBUG_PRINT(x)
#endif

extern s16  camPosX;
extern s16  camPosY;
extern u32 gFrames;
#endif