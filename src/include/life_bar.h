#ifndef __LIFE_BAR__
#define __LIFE_BAR__

#include "genesis.h"

u32 HPB_init(u16 tileIndex);
void HPB_animate(u16 energy, u8 player);
void HPB_deinit();

#endif