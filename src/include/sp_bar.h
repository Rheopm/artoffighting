#ifndef __SP_BAR__
#define __SP_BAR__

#include "genesis.h"

u32 SPB_init(u16 tileIndex);
void SPB_animate(u16 energy, u8 player);
void SPB_changeNumber( u8 number, u8 player);

#endif