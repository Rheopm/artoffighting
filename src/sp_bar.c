#include "include/sp_bar.h"
#include "interface.h"
#include "gfx.h"


static TileMap sp_bar_p1 = {.compression = COMPRESSION_NONE, .h=1, .w=12};
static TileMap sp_bar_p2 = {.compression = COMPRESSION_NONE, .h=1, .w=12};
static u16 sp_bar_p1_data[12], sp_bar_p2_data[12];



static u16 TileIndex;
Sprite *barNumberP1, *barNumberP2;
Sprite *pow;

u32 SPB_init(u16 tileIndex)
{
    TileIndex = 0x6ee;
    u16 numTile = barra_amarela2.numTile; 

    memsetU16(sp_bar_p1_data, 0x6ee, 12);
    memsetU16(sp_bar_p2_data, 0x6ee, 12);

    sp_bar_p1.tilemap = sp_bar_p1_data;
    sp_bar_p2.tilemap = sp_bar_p2_data;

    VDP_loadTileSet(&barra_amarela2, 0x6ee, DMA);
    
    VDP_setTileMapEx(BG_A, &sp_bar_p1, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, 0), 6, 3, 0, 0, 12, 1, DMA_QUEUE);
    VDP_setTileMapEx(BG_A, &sp_bar_p2, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, 0), 22, 3, 0, 0, 12, 1, DMA_QUEUE);

    // barNumberP1 = SPR_addSpriteEx(&spr_bar_sp_stacks, 13*8, 26*8, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY  | SPR_FLAG_AUTO_TILE_UPLOAD);
    // SPR_setVRAMTileIndex(barNumberP1, 0x6fa);// stacks da barra do p1
    // barNumberP2 = SPR_addSpriteEx(&spr_bar_sp_stacks, 24*8, 26*8, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY  | SPR_FLAG_AUTO_TILE_UPLOAD);
    // SPR_setVRAMTileIndex(barNumberP2, 0x6f7);// stacks da barra do p2
    // SPR_setHFlip(barNumberP2, TRUE);

    // pow = SPR_addSpriteEx(&spr_pow, 2*8, 26*8, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY  | SPR_FLAG_AUTO_TILE_UPLOAD);
    // SPR_setVRAMTileIndex(pow, 0x6fd);// sprite pow da barra do p1
    

    // pow = SPR_addSpriteEx(&spr_pow, 35*8, 26*8, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY  | SPR_FLAG_AUTO_TILE_UPLOAD);
    // SPR_setVRAMTileIndex(pow, 0x6fd);// sprite pow da barra do p2

    return TileIndex + numTile;
}

void SPB_animate(u16 energy, u8 player)
{

    // const s16 y =  26;

    // const u16 tilemap_index = energy/8;
    // const u16 tile_index = energy%8 + TileIndex;

    

    // TileMap* bar;

    // if(player == 1)
    // {
    //     bar = &sp_bar_p1;
    //     bar->tilemap = sp_bar_p1_data;
        
    // }
    // else
    // {
    //     bar = &sp_bar_p2;
    //     bar->tilemap = sp_bar_p2_data;
    // }
    // if(energy == 0)
    // {
    //     memsetU16(bar->tilemap, TileIndex, 8);
    // }
    // else
    // {
    //     if(player == 2)
    //     {
    //         bar->tilemap[7 - tilemap_index] = tile_index;
    //         if(tilemap_index < 8)
    //         {
    //             memsetU16(&bar->tilemap[8-tilemap_index], TileIndex+8,  tilemap_index);
    //         }
    //     }
    //     else
    //     {
    //         bar->tilemap[tilemap_index] = tile_index;
    //         if(tilemap_index < 8 )
    //         {
    //             memsetU16(&bar->tilemap[0], TileIndex+8, tilemap_index);
    //         }
    //     }
    // }

    // if(player == 1)
    // {
    //     VDP_setTileMapEx(BG_A, bar, TILE_ATTR_FULL(PAL1, TRUE, FALSE,TRUE, 0), 5, y, 0, 0, 8, 1, DMA_QUEUE);
    // }
    // else
    // {
    //     VDP_setTileMapEx(BG_A, bar, TILE_ATTR_FULL(PAL1, TRUE, FALSE,FALSE, 0), 27, y, 0, 0, 8, 1, DMA_QUEUE);
    // }
}

void SPB_changeNumber( u8 number, u8 player)
{
    Sprite *barNumber;
    if(player == 1)
    {
        barNumber = barNumberP1;
    }
    else
    {
        barNumber = barNumberP2;
    }

    if(number==3){ 
        SPR_setAnim(barNumber, 3);
    }
    else if(number==2){ 
         SPR_setAnim(barNumber, 2);
    }
    else if(number==1){ 
        SPR_setAnim(barNumber, 1);
    }
    else if(number==0){ 
        SPR_setAnim(barNumber, 0);
    }
}
