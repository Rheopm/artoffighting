#include "include/life_bar.h"
#include "interface.h"


static TileMap life_bar_p1 = {.compression = COMPRESSION_NONE, .h=1, .w=12};
static TileMap life_bar_p2 = {.compression = COMPRESSION_NONE, .h=1, .w=12};
static u16 life_bar_p1_data[12], life_bar_p2_data[12];

static u16 TileIndex;

u16** sprTileIndexes;

static void frameChanged(Sprite* sprite)
{
    u16 tileIndex = sprTileIndexes[sprite->animInd][sprite->frameInd];
    SPR_setVRAMTileIndex(sprite, tileIndex);
}

u32 HPB_init(u16 tileIndex)
{
    TileIndex = 0x6e5;
    u16 numTile; 

    memsetU16(life_bar_p1_data, 0x6e5+8, 12);
    memsetU16(life_bar_p2_data, 0x6e5+8, 12);

    life_bar_p1.tilemap = life_bar_p1_data;
    life_bar_p2.tilemap = life_bar_p2_data;

    VDP_loadTileSet(&barra_amarela, 0x6e5, DMA);
    
    VDP_setTileMapEx(BG_A, &life_bar_p1, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, 0), 6, 2, 0, 0, 12, 1, DMA_QUEUE);
    VDP_setTileMapEx(BG_A, &life_bar_p2, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, 0), 22, 2, 0, 0,12, 1, DMA_QUEUE);
    return barra_amarela.numTile;
}

void HPB_deinit()
{
}

void HPB_animate(u16 energy, u8 player)
{
    u16 tilesetIndex = TileIndex;
    const u16 tilemap_index = energy/8;
    const u16 tile_index = energy%8 + tilesetIndex;

    TileMap* bar;

    if(player == 1)
    {
        bar = &life_bar_p1;
        bar->tilemap = life_bar_p1_data;
        
    }
    else
    {
        bar = &life_bar_p2;
        bar->tilemap = life_bar_p2_data;
    }
    if(energy == 96)
    {
        memsetU16(bar->tilemap, tilesetIndex + 8, 12);
    }
    else
    {
        if(player == 1)
        {
            bar->tilemap[11 - tilemap_index] = tile_index;
            memsetU16(bar->tilemap, TileIndex, 11 - tilemap_index);
        }
        else
        {
            bar->tilemap[tilemap_index] = tile_index;
            memsetU16(&bar->tilemap[tilemap_index +1], TileIndex, 11 - tilemap_index);
        }
    }

    if(player == 1)
    {
        VDP_setTileMapEx(BG_A, bar, TILE_ATTR_FULL(PAL1, FALSE, FALSE,FALSE, 0), 6, 2, 0, 0, 12, 1, DMA_QUEUE);
    }
    else
    {
        VDP_setTileMapEx(BG_A, bar, TILE_ATTR_FULL(PAL1, FALSE, FALSE,TRUE, 0), 22, 2, 0, 0, 12, 1, DMA_QUEUE);
    }
    
}
