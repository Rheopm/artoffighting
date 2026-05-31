#include "include/cenarios.h"
#include "gfx.h"
#include "maths.h"
#include "cenarios_res.h"
#include "interface.h"
#include "include/commun.h"

#define CEN_SPRITE_MAX 10

enum Direction{
	DIREITA,
	ESQUERDA,
	PAUSA,
};

typedef struct {
	Sprite *s;
	f16 x;
	f16 y;
	u16 pausa_frames;
	enum Direction direction;
}BgSprite;



static BgSprite bg_s[CEN_SPRITE_MAX];

static CenarioAnimation cenarioAnimation;

static u16 animationIndex = 0;


static void CEN_AnimeSprite(enum CENARIOS gBG_Choice, BgSprite *bg_s);

static u8 index_paleta ;


void CEN_Anima(enum CENARIOS gBG_Choice, u8 ping)
{
	if(gBG_Choice==CENARIO_JAPAO){ 
		CEN_AnimeSprite(gBG_Choice, bg_s);
		if(ping == 9 || ping == 6 || ping == 3)
		{
			for(int i = 0;  cenarioAnimation.frames!= NULL && i< cenarioAnimation.frames->squareNumber; i++)
			{
				
				TileMap *map = NULL;
				u16 index = 0;
				if(cenarioAnimation.frames[animationIndex].squares[i].bgPlane == BG_B)
				{
					map  = cenarioAnimation.bgb;
					index = cenarioAnimation.tilesetIndexBgb;
				}
				else if(cenarioAnimation.frames[animationIndex].squares[i].bgPlane == BG_A)
				{
					map  = cenarioAnimation.bga;
					index = cenarioAnimation.tilesetIndexBga;
					
				}
				
				u8 result = VDP_setTileMapEx(cenarioAnimation.frames[animationIndex].squares[i].bgPlane, map, TILE_ATTR_FULL(PAL0,0,FALSE,FALSE,index),
					cenarioAnimation.frames[animationIndex].squares[i].x_plane, cenarioAnimation.frames[animationIndex].squares[i].y_plane,
					cenarioAnimation.frames[animationIndex].squares[i].x_image, cenarioAnimation.frames[animationIndex].squares[i].y_image, 
					cenarioAnimation.frames[animationIndex].squares[i].w, cenarioAnimation.frames[animationIndex].squares[i].h, DMA_QUEUE);
				
			}
			animationIndex ++;
			if(animationIndex >= cenarioAnimation.AnimationNumber)
			{
				animationIndex = 0;
			}
			
		}
	}
	else if(gBG_Choice==CENARIO_OMEGA){
		if(ping==9){
			index_paleta +=1;
			if(index_paleta>14){
				index_paleta = 0;
			}
			
			if(index_paleta == 0){PAL_setPalette(PAL0, bga_omega_pal5.data, DMA);}
			else if (index_paleta == 1){PAL_setPalette(PAL0, bga_omega_pal4.data, DMA);}
			else if (index_paleta == 2){PAL_setPalette(PAL0, bga_omega_pal3.data, DMA);}
			else if (index_paleta == 3){PAL_setPalette(PAL0, bga_omega_pal2.data, DMA);}
			else if (index_paleta == 4){PAL_setPalette(PAL0, omega_bga.palette->data, DMA);}
			else if (index_paleta == 11){PAL_setPalette(PAL0, bga_omega_pal2.data, DMA);}
			else if (index_paleta == 12){PAL_setPalette(PAL0, bga_omega_pal3.data, DMA);}
			else if (index_paleta == 13){PAL_setPalette(PAL0, bga_omega_pal4.data, DMA);}
			else if (index_paleta == 14){PAL_setPalette(PAL0, bga_omega_pal5.data, DMA);}
		}
		//animando os tiles
		CEN_AnimeSprite(gBG_Choice, bg_s);
		if(ping == 9)
		{
			for(int i = 0;  cenarioAnimation.frames!= NULL && i< cenarioAnimation.frames->squareNumber; i++)
			{
				
		
				TileMap *map = NULL;
				u16 index = 0;
				if(cenarioAnimation.frames[animationIndex].squares[i].bgPlane == BG_B)
				{
					map  = cenarioAnimation.bgb;
					index = cenarioAnimation.tilesetIndexBgb;
				}
				else if(cenarioAnimation.frames[animationIndex].squares[i].bgPlane == BG_A)
				{
					
					map  = cenarioAnimation.bga;
					index = cenarioAnimation.tilesetIndexBga;
					
					
				}
				
				
				VDP_setTileMapEx(cenarioAnimation.frames[animationIndex].squares[i].bgPlane, map, TILE_ATTR_FULL(PAL0,0,FALSE,FALSE,index),
					cenarioAnimation.frames[animationIndex].squares[i].x_plane, cenarioAnimation.frames[animationIndex].squares[i].y_plane,
					cenarioAnimation.frames[animationIndex].squares[i].x_image, cenarioAnimation.frames[animationIndex].squares[i].y_image, 
					cenarioAnimation.frames[animationIndex].squares[i].w, cenarioAnimation.frames[animationIndex].squares[i].h, DMA_QUEUE);
				
					
			}
			animationIndex ++;
			if(animationIndex >= cenarioAnimation.AnimationNumber)
			{
				animationIndex = 0;
			}
		}
	}
	else if(gBG_Choice==CENARIO_SPAIN){
		
		//animando os tiles
		
		// if(ping == 9)
		// {
		// 	for(int i = 0;  cenarioAnimation.frames!= NULL && i< cenarioAnimation.frames->squareNumber; i++)
		// 	{
				
		// 		TileMap *map = NULL;
		// 		u16 index = 0;
		// 		if(cenarioAnimation.frames[animationIndex].squares[i].bgPlane == BG_B)
		// 		{
		// 			map  = cenarioAnimation.bgb;
		// 			index = cenarioAnimation.tilesetIndexBgb;
		// 		}
		// 		else if(cenarioAnimation.frames[animationIndex].squares[i].bgPlane == BG_A)
		// 		{
		// 			map  = cenarioAnimation.bga;
		// 			index = cenarioAnimation.tilesetIndexBga;
		// 		}
				
		// 		VDP_setTileMapEx(cenarioAnimation.frames[animationIndex].squares[i].bgPlane, map, TILE_ATTR_FULL(PAL0,0,FALSE,FALSE,index),
		// 			cenarioAnimation.frames[animationIndex].squares[i].x_plane, cenarioAnimation.frames[animationIndex].squares[i].y_plane,
		// 			cenarioAnimation.frames[animationIndex].squares[i].x_image, cenarioAnimation.frames[animationIndex].squares[i].y_image, 
		// 			cenarioAnimation.frames[animationIndex].squares[i].w, cenarioAnimation.frames[animationIndex].squares[i].h, DMA_QUEUE);
					
		// 	}
		// 	animationIndex ++;
		// 	if(animationIndex >= cenarioAnimation.AnimationNumber)
		// 	{
		// 		animationIndex = 0;
		// 	}
		// }
	}
	else if(gBG_Choice==CENARIO_INCORPORADO){
		
		//animando os tiles
		
		if(ping == 9)
		{
			// for(int i = 0;  cenarioAnimation.frames!= NULL && i< cenarioAnimation.frames->squareNumber; i++)
			// {
				
			// 	TileMap *map = NULL;
			// 	u16 index = 0;
			// 	if(cenarioAnimation.frames[animationIndex].squares[i].bgPlane == BG_B)
			// 	{
			// 		map  = cenarioAnimation.bgb;
			// 		index = cenarioAnimation.tilesetIndexBgb;
			// 	}
			// 	else if(cenarioAnimation.frames[animationIndex].squares[i].bgPlane == BG_A)
			// 	{
			// 		map  = cenarioAnimation.bga;
			// 		index = cenarioAnimation.tilesetIndexBga;
			// 	}
				
			// 	VDP_setTileMapEx(cenarioAnimation.frames[animationIndex].squares[i].bgPlane, map, TILE_ATTR_FULL(PAL0,0,FALSE,FALSE,index),
			// 		cenarioAnimation.frames[animationIndex].squares[i].x_plane, cenarioAnimation.frames[animationIndex].squares[i].y_plane,
			// 		cenarioAnimation.frames[animationIndex].squares[i].x_image, cenarioAnimation.frames[animationIndex].squares[i].y_image, 
			// 		cenarioAnimation.frames[animationIndex].squares[i].w, cenarioAnimation.frames[animationIndex].squares[i].h, DMA_QUEUE);
					
			// }
			// animationIndex ++;
			// if(animationIndex >= cenarioAnimation.AnimationNumber)
			// {
			// 	animationIndex = 0;
			// }
		}
	}
	else if(gBG_Choice==CENARIO_KOREA){
		
		//animando os tiles
		
		if(ping == 9)
		{
			// for(int i = 0;  cenarioAnimation.frames!= NULL && i< cenarioAnimation.frames->squareNumber; i++)
			// {
				
			// 	TileMap *map = NULL;
			// 	u16 index = 0;
			// 	if(cenarioAnimation.frames[animationIndex].squares[i].bgPlane == BG_B)
			// 	{
			// 		map  = cenarioAnimation.bgb;
			// 		index = cenarioAnimation.tilesetIndexBgb;
			// 	}
			// 	else if(cenarioAnimation.frames[animationIndex].squares[i].bgPlane == BG_A)
			// 	{
			// 		map  = cenarioAnimation.bga;
			// 		index = cenarioAnimation.tilesetIndexBga;
			// 	}
				
			// 	VDP_setTileMapEx(cenarioAnimation.frames[animationIndex].squares[i].bgPlane, map, TILE_ATTR_FULL(PAL0,0,FALSE,FALSE,index),
			// 		cenarioAnimation.frames[animationIndex].squares[i].x_plane, cenarioAnimation.frames[animationIndex].squares[i].y_plane,
			// 		cenarioAnimation.frames[animationIndex].squares[i].x_image, cenarioAnimation.frames[animationIndex].squares[i].y_image, 
			// 		cenarioAnimation.frames[animationIndex].squares[i].w, cenarioAnimation.frames[animationIndex].squares[i].h, DMA_QUEUE);
					
			// }
			// animationIndex ++;
			// if(animationIndex >= cenarioAnimation.AnimationNumber)
			// {
			// 	animationIndex = 0;
			// }
		}
	}
	else if(gBG_Choice==CENARIO_BRASIL){
		
		//animando os tiles
		
		if(ping == 9)
		{
			// for(int i = 0;  cenarioAnimation.frames!= NULL && i< cenarioAnimation.frames->squareNumber; i++)
			// {
				
			// 	TileMap *map = NULL;
			// 	u16 index = 0;
			// 	if(cenarioAnimation.frames[animationIndex].squares[i].bgPlane == BG_B)
			// 	{
			// 		map  = cenarioAnimation.bgb;
			// 		index = cenarioAnimation.tilesetIndexBgb;
			// 	}
			// 	else if(cenarioAnimation.frames[animationIndex].squares[i].bgPlane == BG_A)
			// 	{
			// 		map  = cenarioAnimation.bga;
			// 		index = cenarioAnimation.tilesetIndexBga;
			// 	}
				
			// 	VDP_setTileMapEx(cenarioAnimation.frames[animationIndex].squares[i].bgPlane, map, TILE_ATTR_FULL(PAL0,0,FALSE,FALSE,index),
			// 		cenarioAnimation.frames[animationIndex].squares[i].x_plane, cenarioAnimation.frames[animationIndex].squares[i].y_plane,
			// 		cenarioAnimation.frames[animationIndex].squares[i].x_image, cenarioAnimation.frames[animationIndex].squares[i].y_image, 
			// 		cenarioAnimation.frames[animationIndex].squares[i].w, cenarioAnimation.frames[animationIndex].squares[i].h, DMA_QUEUE);
					
			// }
			// animationIndex ++;
			// if(animationIndex >= cenarioAnimation.AnimationNumber)
			// {
			// 	animationIndex = 0;
			// }
		}
	}
}

void CEN_AnimaEx(u16 x, u16 y, u16 x_len, u16 y_len, u8 frames_num)
{

}

static void CEN_AnimeSprite(enum CENARIOS gBG_Choice, BgSprite *bg_s)
{
	// if(gBG_Choice==CENARIO_JAPAO){ 
	// 	for(int i = 0; i < 5; i++)
	// 	{
	// 		u16 t = ((512*i)-gFrames) & 0x3FF;
	// 		fix16 doubleCos2t = cosFix16((t << 1) & 0x3FF) << 1;

	// 		bg_s[i].x = fix16Mul(fix16Mul(FIX16(25), cosFix16(t)), doubleCos2t)+ FIX16(200+200*i);
	// 		bg_s[i].y = fix16Mul(fix16Mul(FIX16(25), sinFix16(t)), doubleCos2t)+ FIX16(100-10*i);

	// 		if(bg_s[i].s != NULL)
	// 		{
	// 			s16 x = fix16ToInt(bg_s[i].x) - camPosX;
	// 			s16 y = fix16ToInt(bg_s[i].y) - camPosY;
	// 			if( x < -100)
	// 			{
	// 				x = -100;
	// 			}

	// 			SPR_setPosition(bg_s[i].s, x, y);
	// 		}
	// 	}
	// }

}

u16 CEN_init(enum CENARIOS gBG_Choice)
{   
    u16 tileset_size = 0;
	CEN_clearMemory();
		

    if(gBG_Choice==CENARIO_JAPAO){ 
		cenarioAnimation.bgb = unpackTileMap(ring_bgb.tilemap, NULL);
		if(cenarioAnimation.bgb == NULL)
		{
			
		}
		cenarioAnimation.bga = unpackTileMap(ring_bga.tilemap, NULL);
		if(cenarioAnimation.bga == NULL)
		{
			
		}
		
		// sprites do cenario
		// bg_s[0].x =FIX16(117);
		// bg_s[0].y =FIX16(78);
		// bg_s[0].direction = DIREITA;
		// bg_s[0].s = SPR_addSpriteEx(&spr_vagalume, bg_s[0].x, bg_s[0].y, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY  | SPR_FLAG_AUTO_TILE_UPLOAD);
		// SPR_setVRAMTileIndex(bg_s[0].s, 0x3ee);// vagalume

		// bg_s[1].x =FIX16(221);
		// bg_s[1].y =FIX16(138);
		// bg_s[1].direction = ESQUERDA;
		// bg_s[1].s = SPR_addSpriteEx(&spr_vagalume, bg_s[1].x, bg_s[1].y, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY  | SPR_FLAG_AUTO_TILE_UPLOAD);
		// SPR_setVRAMTileIndex(bg_s[1].s, 0x3ee);// vagalume
		

		VDP_loadTileSet(ring_bga.tileset,0,DMA);
        tileset_size = ring_bga.tileset->numTile;
		VDP_loadTileSet(ring_bgb.tileset,tileset_size,DMA);
		PAL_setPalette(PAL0, ring_bga.palette->data, DMA_QUEUE);
		VDP_setTileMapEx(BG_A, cenarioAnimation.bga, TILE_ATTR_FULL(PAL0, FALSE,FALSE,FALSE, 0),0,0,0,0,64,28, DMA_QUEUE);
		VDP_setTileMapEx(BG_B, cenarioAnimation.bgb, TILE_ATTR_FULL(PAL0, FALSE,FALSE,FALSE, tileset_size),0,0,0,0,64,28, DMA_QUEUE);

		cenarioAnimation.tilesetIndexBga = 0;
		cenarioAnimation.tilesetIndexBgb = tileset_size;

		cenarioAnimation.AnimationNumber = 2;

		CenarioFrame *frames = malloc(sizeof(CenarioFrame)*cenarioAnimation.AnimationNumber);
 
		if(frames != NULL)
		{
			frames[0].squareNumber = 2;
			frames[0].squares = malloc(sizeof(CenarioFrameSquare)*frames[0].squareNumber);
			if(frames[0].squares != NULL)
			{
				frames[0].squares[0].x_plane = 10;    	//x do plano
				frames[0].squares[0].y_plane = 7;    	//y do plano
				frames[0].squares[0].x_image = 0;    	//x da imagem
				frames[0].squares[0].y_image = 28;    	//y da imagem
				frames[0].squares[0].w = 43;          	//larguara do frame
				frames[0].squares[0].h = 13;          	//altura do frame
				frames[0].squares[0].bgPlane = BG_A;   //plano do frame

				

			
				

				

				


			}
			frames[1].squareNumber = 2;
			frames[1].squares = malloc(sizeof(CenarioFrameSquare)*frames[1].squareNumber);
			if(frames[1].squares != NULL)
			{
				frames[1].squares[0].x_plane = 10;    	//x do plano
				frames[1].squares[0].y_plane = 7;    	//y do plano
				frames[1].squares[0].x_image = 10;    	//x da imagem
				frames[1].squares[0].y_image = 7;    	//y da imagem
				frames[1].squares[0].w = 43;          	//larguara do frame
				frames[1].squares[0].h = 13;          	//altura do frame
				frames[1].squares[0].bgPlane = BG_A;   //plano do frame

			
				

				


			}
			
			
			
		
			// else
			// {
			// 	kprintf("fail to alocate squares");
			// }
			// frames[1].squareNumber = 2;
			// frames[1].squares = malloc(sizeof(CenarioFrameSquare)*frames[1].squareNumber);

			// if(frames[1].squares != NULL)
			// {
			// 	frames[1].squares[0].x_plane = 19;    	//x do plano
			// 	frames[1].squares[0].y_plane = 7;    	//y do plano
			// 	frames[1].squares[0].x_image = 6;    	//x da imagem
			// 	frames[1].squares[0].y_image = 28;    	//y da imagem
			// 	frames[1].squares[0].w = 6;          	//larguara do frame
			// 	frames[1].squares[0].h = 6;          	//altura do frame
			// 	frames[1].squares[0].bgPlane = BG_A;   //plano do frame
				
			// 	frames[1].squares[1].x_plane = 19;    	//x do plano
			// 	frames[1].squares[1].y_plane = 7;    	//y do plano
			// 	frames[1].squares[1].x_image = 19;    	//x da imagem
			// 	frames[1].squares[1].y_image = 7;    	//y da imagem
			// 	frames[1].squares[1].w = 6;          	//larguara do frame
			// 	frames[1].squares[1].h = 6;          	//altura do frame
			// 	frames[1].squares[1].bgPlane = BG_A;   //plano do frame

				
			
			// }
			// else
			// {
			// 	kprintf("fail to alocate squares");
			// }

			// frames[2].squareNumber = 2;
			// frames[2].squares = malloc(sizeof(CenarioFrameSquare)*frames[2].squareNumber);

			// if(frames[2].squares != NULL)
			// {
			// 	frames[2].squares[0].x_plane = 37;    	//x do plano
			// 	frames[2].squares[0].y_plane = 7;    	//y do plano
			// 	frames[2].squares[0].x_image = 12;    	//x da imagem
			// 	frames[2].squares[0].y_image = 28;    	//y da imagem
			// 	frames[2].squares[0].w = 6;          	//larguara do frame
			// 	frames[2].squares[0].h = 6;          	//altura do frame
			// 	frames[2].squares[0].bgPlane = BG_A;   //plano do frame

			// 	frames[2].squares[1].x_plane = 37;    	//x do plano
			// 	frames[2].squares[1].y_plane = 7;    	//y do plano
			// 	frames[2].squares[1].x_image = 37;    	//x da imagem
			// 	frames[2].squares[1].y_image = 7;    	//y da imagem
			// 	frames[2].squares[1].w = 6;          	//larguara do frame
			// 	frames[2].squares[1].h = 6;          	//altura do frame
			// 	frames[2].squares[1].bgPlane = BG_A;   //plano do frame

				
			// }
			// else
			// {
			// 	kprintf("fail to alocate squares");
			// }

			// frames[3].squareNumber = 2;
			// frames[3].squares = malloc(sizeof(CenarioFrameSquare)*frames[3].squareNumber);

			// if(frames[3].squares != NULL)
			// {
			// 	frames[3].squares[0].x_plane = 46;    	//x do plano
			// 	frames[3].squares[0].y_plane = 7;    	//y do plano
			// 	frames[3].squares[0].x_image = 18;    	//x da imagem
			// 	frames[3].squares[0].y_image = 28;    	//y da imagem
			// 	frames[3].squares[0].w = 6;          	//larguara do frame
			// 	frames[3].squares[0].h = 6;          	//altura do frame
			// 	frames[3].squares[0].bgPlane = BG_A;   //plano do frame
				
			// 	frames[3].squares[1].x_plane = 46;    	//x do plano
			// 	frames[3].squares[1].y_plane = 7;    	//y do plano
			// 	frames[3].squares[1].x_image = 46;    	//x da imagem
			// 	frames[3].squares[1].y_image = 7;    	//y da imagem
			// 	frames[3].squares[1].w = 6;          	//larguara do frame
			// 	frames[3].squares[1].h = 6;          	//altura do frame
			// 	frames[3].squares[1].bgPlane = BG_A;   //plano do frame

				
				
			// }
			// else
			// {
			// 	kprintf("fail to alocate squares");
			// }
			// frames[4].squareNumber = 2;
			// frames[4].squares = malloc(sizeof(CenarioFrameSquare)*frames[4].squareNumber);
			// if(frames[4].squares != NULL)
			// {
			// 	frames[4].squares[0].x_plane = 8;    	//x do plano
			// 	frames[4].squares[0].y_plane = 32;    	//y do plano
			// 	frames[4].squares[0].x_image = 24;    	//x da imagem
			// 	frames[4].squares[0].y_image = 29;    	//y da imagem
			// 	frames[4].squares[0].w = 1;          	//larguara do frame
			// 	frames[4].squares[0].h = 4;          	//altura do frame
			// 	frames[4].squares[0].bgPlane = BG_A;   //plano do frame
				
			// 	frames[4].squares[1].x_plane = 8;    	//x do plano
			// 	frames[4].squares[1].y_plane = 32;    	//y do plano
			// 	frames[4].squares[1].x_image = 8;    	//x da imagem
			// 	frames[4].squares[1].y_image = 32;    	//y da imagem
			// 	frames[4].squares[1].w = 1;          	//larguara do frame
			// 	frames[4].squares[1].h = 4;          	//altura do frame
			// 	frames[4].squares[1].bgPlane = BG_A;   //plano do frame

				
				
			// }
			// else
			// {
			// 	kprintf("fail to alocate squares");
			// }
			// frames[5].squareNumber = 2;
			// frames[5].squares = malloc(sizeof(CenarioFrameSquare)*frames[5].squareNumber);
			// if(frames[5].squares != NULL)
			// {
			// 	frames[5].squares[0].x_plane = 41;    	//x do plano
			// 	frames[5].squares[0].y_plane = 16;    	//y do plano
			// 	frames[5].squares[0].x_image = 25;    	//x da imagem
			// 	frames[5].squares[0].y_image = 29;    	//y da imagem
			// 	frames[5].squares[0].w = 14;          	//larguara do frame
			// 	frames[5].squares[0].h = 2;          	//altura do frame
			// 	frames[5].squares[0].bgPlane = BG_A;   //plano do frame
				
			// 	frames[5].squares[1].x_plane = 41;    	//x do plano
			// 	frames[5].squares[1].y_plane = 16;    	//y do plano
			// 	frames[5].squares[1].x_image = 41;    	//x da imagem
			// 	frames[5].squares[1].y_image = 16;    	//y da imagem
			// 	frames[5].squares[1].w = 1;          	//larguara do frame
			// 	frames[5].squares[1].h = 4;          	//altura do frame
			// 	frames[5].squares[1].bgPlane = BG_A;   //plano do frame

				
				
			// }
			// else
			// {
			// 	kprintf("fail to alocate squares");
			// }
			

		}
		else
		{
			
		}
		cenarioAnimation.frames = frames;

		tileset_size = tileset_size + ring_bgb.tileset->numTile;
	}else if (gBG_Choice==CENARIO_OMEGA)
	{
		cenarioAnimation.bgb = unpackTileMap(omega_bgb.tilemap, NULL);
		if(cenarioAnimation.bgb == NULL)
		{
			
		}
		cenarioAnimation.bga = unpackTileMap(omega_bga.tilemap, NULL);
		if(cenarioAnimation.bga == NULL)
		{
			
		}

		VDP_loadTileSet(omega_bga.tileset,0,DMA);
        tileset_size = omega_bga.tileset->numTile;
		VDP_loadTileSet(omega_bgb.tileset,tileset_size,DMA);
		//PAL_setColors(0, omega_bga.palette->data, 32, DMA_QUEUE);
		VDP_setTileMapEx(BG_A, cenarioAnimation.bga, TILE_ATTR_FULL(PAL0, FALSE,FALSE,FALSE, 0),0,0,0,0,64,28, DMA_QUEUE);
		VDP_setTileMapEx(BG_B, cenarioAnimation.bgb, TILE_ATTR_FULL(PAL0, FALSE,FALSE,FALSE, tileset_size),0,0,0,0,52,28, DMA_QUEUE);

		cenarioAnimation.tilesetIndexBga = 0;
		cenarioAnimation.tilesetIndexBgb = tileset_size;
		cenarioAnimation.AnimationNumber = 4;

		CenarioFrame *frames = malloc(sizeof(CenarioFrame)*cenarioAnimation.AnimationNumber);
 
		if(frames != NULL)
		{
			frames[0].squareNumber = 3;
			frames[0].squares = malloc(sizeof(CenarioFrameSquare)*frames[0].squareNumber);
			if(frames[0].squares != NULL)
			{
				frames[0].squares[0].x_plane = 4;    	//x do plano
				frames[0].squares[0].y_plane = 14;    	//y do plano
				frames[0].squares[0].x_image = 0;    	//x da imagem
				frames[0].squares[0].y_image = 0;    	//y da imagem
				frames[0].squares[0].w = 4;          	//larguara do frame
				frames[0].squares[0].h = 4;          	//altura do frame
				frames[0].squares[0].bgPlane = BG_A;   //plano do frame

				frames[0].squares[1].x_plane = 56;    	//x do plano
				frames[0].squares[1].y_plane = 14;    	//y do plano
				frames[0].squares[1].x_image = 39;    	//x da imagem
				frames[0].squares[1].y_image = 0;    	//y da imagem
				frames[0].squares[1].w = 4;          	//larguara do frame
				frames[0].squares[1].h = 4;          	//altura do frame
				frames[0].squares[1].bgPlane = BG_A;   //plano do frame

				frames[0].squares[2].x_plane = 50;    	//x do plano
				frames[0].squares[2].y_plane = 14;    	//y do plano
				frames[0].squares[2].x_image = 12;    	//x da imagem
				frames[0].squares[2].y_image = 0;    	//y da imagem
				frames[0].squares[2].w = 4;          	//larguara do frame
				frames[0].squares[2].h = 4;          	//altura do frame
				frames[0].squares[2].bgPlane = BG_A;   //plano do frame			

			}
			else
			{
				
			}
			frames[1].squareNumber = 3;
			frames[1].squares = malloc(sizeof(CenarioFrameSquare)*frames[1].squareNumber);

			if(frames[1].squares != NULL)
			{
				frames[1].squares[0].x_plane = 4;    	//x do plano
				frames[1].squares[0].y_plane = 14;    	//y do plano
				frames[1].squares[0].x_image = 4;    	//x da imagem
				frames[1].squares[0].y_image = 0;    	//y da imagem
				frames[1].squares[0].w = 4;          	//larguara do frame
				frames[1].squares[0].h = 4;          	//altura do frame
				frames[1].squares[0].bgPlane = BG_A;   //plano do frame
				
				frames[1].squares[1].x_plane = 56;    	//x do plano
				frames[1].squares[1].y_plane = 14;    	//y do plano
				frames[1].squares[1].x_image = 43;    	//x da imagem
				frames[1].squares[1].y_image = 0;    	//y da imagem
				frames[1].squares[1].w = 4;          	//larguara do frame
				frames[1].squares[1].h = 4;          	//altura do frame
				frames[1].squares[1].bgPlane = BG_A;   //plano do frame

				frames[1].squares[2].x_plane = 50;    	//x do plano
				frames[1].squares[2].y_plane = 14;    	//y do plano
				frames[1].squares[2].x_image = 16;    	//x da imagem
				frames[1].squares[2].y_image = 0;    	//y da imagem
				frames[1].squares[2].w = 4;          	//larguara do frame
				frames[1].squares[2].h = 4;          	//altura do frame
				frames[1].squares[2].bgPlane = BG_A;   //plano do frame
			
			}
			else
			{
				
			}

			frames[2].squareNumber = 3;
			frames[2].squares = malloc(sizeof(CenarioFrameSquare)*frames[2].squareNumber);

			if(frames[2].squares != NULL)
			{
				frames[2].squares[0].x_plane = 4;    	//x do plano
				frames[2].squares[0].y_plane = 14;    	//y do plano
				frames[2].squares[0].x_image = 8;    	//x da imagem
				frames[2].squares[0].y_image = 0;    	//y da imagem
				frames[2].squares[0].w = 4;          	//larguara do frame
				frames[2].squares[0].h = 4;          	//altura do frame
				frames[2].squares[0].bgPlane = BG_A;   //plano do frame

				frames[2].squares[1].x_plane = 56;    	//x do plano
				frames[2].squares[1].y_plane = 14;    	//y do plano
				frames[2].squares[1].x_image = 47;    	//x da imagem
				frames[2].squares[1].y_image = 0;    	//y da imagem
				frames[2].squares[1].w = 4;          	//larguara do frame
				frames[2].squares[1].h = 4;          	//altura do frame
				frames[2].squares[1].bgPlane = BG_A;   //plano do frame

				frames[2].squares[2].x_plane = 50;    	//x do plano
				frames[2].squares[2].y_plane = 14;    	//y do plano
				frames[2].squares[2].x_image = 20;    	//x da imagem
				frames[2].squares[2].y_image = 0;    	//y da imagem
				frames[2].squares[2].w = 4;          	//larguara do frame
				frames[2].squares[2].h = 4;          	//altura do frame
				frames[2].squares[2].bgPlane = BG_A;   //plano do frame
			}
			else
			{
				
			}

			frames[3].squareNumber = 3;
			frames[3].squares = malloc(sizeof(CenarioFrameSquare)*frames[3].squareNumber);

			if(frames[3].squares != NULL)
			{
				frames[3].squares[0].x_plane = 4;    	//x do plano
				frames[3].squares[0].y_plane = 14;    	//y do plano
				frames[3].squares[0].x_image = 4;    	//x da imagem
				frames[3].squares[0].y_image = 0;    	//y da imagem
				frames[3].squares[0].w = 4;          	//larguara do frame
				frames[3].squares[0].h = 4;          	//altura do frame
				frames[3].squares[0].bgPlane = BG_A;   //plano do frame
				
				frames[3].squares[1].x_plane = 56;    	//x do plano
				frames[3].squares[1].y_plane = 14;    	//y do plano
				frames[3].squares[1].x_image = 43;    	//x da imagem
				frames[3].squares[1].y_image = 0;    	//y da imagem
				frames[3].squares[1].w = 4;          	//larguara do frame
				frames[3].squares[1].h = 4;          	//altura do frame
				frames[3].squares[1].bgPlane = BG_A;   //plano do frame

				frames[3].squares[2].x_plane = 50;    	//x do plano
				frames[3].squares[2].y_plane = 14;    	//y do plano
				frames[3].squares[2].x_image = 16;    	//x da imagem
				frames[3].squares[2].y_image = 0;    	//y da imagem
				frames[3].squares[2].w = 0;          	//larguara do frame
				frames[3].squares[2].h = 0;          	//altura do frame
				frames[3].squares[2].bgPlane = BG_A;   //plano do frame
				
			}
			else
			{
				
			}

		}
		else
		{
			
		}
		cenarioAnimation.frames = frames;

		tileset_size = tileset_size + omega_bgb.tileset->numTile;
	}else if (gBG_Choice==CENARIO_SPAIN)
	{
		cenarioAnimation.bgb = unpackTileMap(spain_bgb.tilemap, NULL);
		if(cenarioAnimation.bgb == NULL)
		{
			
		}
		cenarioAnimation.bga = unpackTileMap(spain_bga.tilemap, NULL);
		if(cenarioAnimation.bga == NULL)
		{
			
		}

		VDP_loadTileSet(spain_bga.tileset,0,DMA);
        tileset_size = spain_bga.tileset->numTile;
		VDP_loadTileSet(spain_bgb.tileset,tileset_size,DMA);
		//PAL_setColors(0, spain_bga.palette->data, 32, DMA_QUEUE);
		VDP_setTileMapEx(BG_A, cenarioAnimation.bga, TILE_ATTR_FULL(PAL0, FALSE,FALSE,FALSE, 0),0,0,0,0,64,28, DMA_QUEUE);
		VDP_setTileMapEx(BG_B, cenarioAnimation.bgb, TILE_ATTR_FULL(PAL0, FALSE,FALSE,FALSE, tileset_size),0,0,0,0,64,28, DMA_QUEUE);
		

		cenarioAnimation.tilesetIndexBga = 0;
		cenarioAnimation.tilesetIndexBgb = tileset_size;
		cenarioAnimation.AnimationNumber = 4;

		CenarioFrame *frames = malloc(sizeof(CenarioFrame)*cenarioAnimation.AnimationNumber);
 
		if(frames != NULL)
		{
			frames[0].squareNumber = 1;
			frames[0].squares = malloc(sizeof(CenarioFrameSquare)*frames[0].squareNumber);
			if(frames[0].squares != NULL)
			{
				frames[0].squares[0].x_plane = 17;    	//x do plano
				frames[0].squares[0].y_plane = 8;    	//y do plano
				frames[0].squares[0].x_image = 0;    	//x da imagem
				frames[0].squares[0].y_image = 20;    	//y da imagem
				frames[0].squares[0].w = 12;          	//larguara do frame
				frames[0].squares[0].h = 8;          	//altura do frame
				frames[0].squares[0].bgPlane = BG_B;   //plano do frame
			}
			else
			{
				
			}
			frames[1].squareNumber = 1;
			frames[1].squares = malloc(sizeof(CenarioFrameSquare)*frames[1].squareNumber);

			if(frames[1].squares != NULL)
			{
				frames[1].squares[0].x_plane = 17;    	//x do plano
				frames[1].squares[0].y_plane = 8;    	//y do plano
				frames[1].squares[0].x_image = 12;    	//x da imagem
				frames[1].squares[0].y_image = 20;    	//y da imagem
				frames[1].squares[0].w = 12;          	//larguara do frame
				frames[1].squares[0].h = 8;          	//altura do frame
				frames[1].squares[0].bgPlane = BG_B;   //plano do frame
				
			}
			else
			{
				
			}

			frames[2].squareNumber = 1;
			frames[2].squares = malloc(sizeof(CenarioFrameSquare)*frames[2].squareNumber);

			if(frames[2].squares != NULL)
			{
				frames[2].squares[0].x_plane = 17;    	//x do plano
				frames[2].squares[0].y_plane = 8;    	//y do plano
				frames[2].squares[0].x_image = 24;    	//x da imagem
				frames[2].squares[0].y_image = 20;    	//y da imagem
				frames[2].squares[0].w = 12;          	//larguara do frame
				frames[2].squares[0].h = 8;          	//altura do frame
				frames[2].squares[0].bgPlane = BG_B;   //plano do frame

				
			}
			else
			{
				
			}

			frames[3].squareNumber = 1;
			frames[3].squares = malloc(sizeof(CenarioFrameSquare)*frames[3].squareNumber);

			if(frames[3].squares != NULL)
			{
				frames[3].squares[0].x_plane = 17;    	//x do plano
				frames[3].squares[0].y_plane = 8;    	//y do plano
				frames[3].squares[0].x_image = 12;    	//x da imagem
				frames[3].squares[0].y_image = 20;    	//y da imagem
				frames[3].squares[0].w = 12;          	//larguara do frame
				frames[3].squares[0].h = 8;          	//altura do frame
				frames[3].squares[0].bgPlane = BG_B;   //plano do frame
			}
			else
			{
				
			}

		}
		else
		{
			
		}
		cenarioAnimation.frames = frames;

		tileset_size = tileset_size + spain_bgb.tileset->numTile;
	}
	else if (gBG_Choice==CENARIO_INCORPORADO)
	{
		cenarioAnimation.bgb = unpackTileMap(incorporado_bgb.tilemap, NULL);
		if(cenarioAnimation.bgb == NULL)
		{
			kprintf("fail to alocate bgb");
		}
		cenarioAnimation.bga = unpackTileMap(incorporado_bga.tilemap, NULL);
		if(cenarioAnimation.bga == NULL)
		{
			kprintf("fail to alocate bga");
		}

		VDP_loadTileSet(incorporado_bga.tileset,0,DMA);
        tileset_size = incorporado_bga.tileset->numTile;
		VDP_loadTileSet(incorporado_bgb.tileset,tileset_size,DMA);
		PAL_setColors(0, incorporado_bga.palette->data, 32, DMA_QUEUE);
		VDP_setTileMapEx(BG_A, cenarioAnimation.bga, TILE_ATTR_FULL(PAL0, FALSE,FALSE,FALSE, 0),0,0,0,0,64,28, DMA_QUEUE);
		VDP_setTileMapEx(BG_B, cenarioAnimation.bgb, TILE_ATTR_FULL(PAL0, FALSE,FALSE,FALSE, tileset_size),0,0,0,0,64,20, DMA_QUEUE);
		

		cenarioAnimation.tilesetIndexBga = 0;
		cenarioAnimation.tilesetIndexBgb = tileset_size;
		cenarioAnimation.AnimationNumber = 4;

		CenarioFrame *frames = malloc(sizeof(CenarioFrame)*cenarioAnimation.AnimationNumber);
 
		if(frames != NULL)
		{
			// frames[0].squareNumber = 1;
			// frames[0].squares = malloc(sizeof(CenarioFrameSquare)*frames[0].squareNumber);
			// if(frames[0].squares != NULL)
			// {
			// 	frames[0].squares[0].x_plane = 17;    	//x do plano
			// 	frames[0].squares[0].y_plane = 8;    	//y do plano
			// 	frames[0].squares[0].x_image = 0;    	//x da imagem
			// 	frames[0].squares[0].y_image = 20;    	//y da imagem
			// 	frames[0].squares[0].w = 12;          	//larguara do frame
			// 	frames[0].squares[0].h = 8;          	//altura do frame
			// 	frames[0].squares[0].bgPlane = BG_B;   //plano do frame
			// }
			// else
			// {
			// 	kprintf("fail to alocate squares");
			// }
			// frames[1].squareNumber = 1;
			// frames[1].squares = malloc(sizeof(CenarioFrameSquare)*frames[1].squareNumber);

			// if(frames[1].squares != NULL)
			// {
			// 	frames[1].squares[0].x_plane = 17;    	//x do plano
			// 	frames[1].squares[0].y_plane = 8;    	//y do plano
			// 	frames[1].squares[0].x_image = 12;    	//x da imagem
			// 	frames[1].squares[0].y_image = 20;    	//y da imagem
			// 	frames[1].squares[0].w = 12;          	//larguara do frame
			// 	frames[1].squares[0].h = 8;          	//altura do frame
			// 	frames[1].squares[0].bgPlane = BG_B;   //plano do frame
				
			// }
			// else
			// {
			// 	kprintf("fail to alocate squares");
			// }

			// frames[2].squareNumber = 1;
			// frames[2].squares = malloc(sizeof(CenarioFrameSquare)*frames[2].squareNumber);

			// if(frames[2].squares != NULL)
			// {
			// 	frames[2].squares[0].x_plane = 17;    	//x do plano
			// 	frames[2].squares[0].y_plane = 8;    	//y do plano
			// 	frames[2].squares[0].x_image = 24;    	//x da imagem
			// 	frames[2].squares[0].y_image = 20;    	//y da imagem
			// 	frames[2].squares[0].w = 12;          	//larguara do frame
			// 	frames[2].squares[0].h = 8;          	//altura do frame
			// 	frames[2].squares[0].bgPlane = BG_B;   //plano do frame

				
			// }
			// else
			// {
			// 	kprintf("fail to alocate squares");
			// }

			// frames[3].squareNumber = 1;
			// frames[3].squares = malloc(sizeof(CenarioFrameSquare)*frames[3].squareNumber);

			// if(frames[3].squares != NULL)
			// {
			// 	frames[3].squares[0].x_plane = 17;    	//x do plano
			// 	frames[3].squares[0].y_plane = 8;    	//y do plano
			// 	frames[3].squares[0].x_image = 12;    	//x da imagem
			// 	frames[3].squares[0].y_image = 20;    	//y da imagem
			// 	frames[3].squares[0].w = 12;          	//larguara do frame
			// 	frames[3].squares[0].h = 8;          	//altura do frame
			// 	frames[3].squares[0].bgPlane = BG_B;   //plano do frame
			// }
			// else
			// {
			// 	kprintf("fail to alocate squares");
			// }

		}
		else
		{
			kprintf("fail to alocate frames");
		}
		cenarioAnimation.frames = frames;

		tileset_size = tileset_size + incorporado_bgb.tileset->numTile;
	}
	else if (gBG_Choice==CENARIO_KOREA)
	{
		cenarioAnimation.bgb = unpackTileMap(korea_bgb.tilemap, NULL);
		if(cenarioAnimation.bgb == NULL)
		{
			kprintf("fail to alocate bgb");
		}
		cenarioAnimation.bga = unpackTileMap(korea_bga.tilemap, NULL);
		if(cenarioAnimation.bga == NULL)
		{
			kprintf("fail to alocate bga");
		}

		VDP_loadTileSet(korea_bga.tileset,0,DMA);
        tileset_size = korea_bga.tileset->numTile;
		VDP_loadTileSet(korea_bgb.tileset,tileset_size,DMA);
		PAL_setColors(0, korea_bga.palette->data, 32, DMA_QUEUE);
		VDP_setTileMapEx(BG_A, cenarioAnimation.bga, TILE_ATTR_FULL(PAL0, FALSE,FALSE,FALSE, 0),0,0,0,0,64,28, DMA_QUEUE);
		VDP_setTileMapEx(BG_B, cenarioAnimation.bgb, TILE_ATTR_FULL(PAL0, FALSE,FALSE,FALSE, tileset_size),0,0,0,0,64,28, DMA_QUEUE);
		

		cenarioAnimation.tilesetIndexBga = 0;
		cenarioAnimation.tilesetIndexBgb = tileset_size;
		cenarioAnimation.AnimationNumber = 4;

		CenarioFrame *frames = malloc(sizeof(CenarioFrame)*cenarioAnimation.AnimationNumber);
 
		if(frames != NULL)
		{
			// frames[0].squareNumber = 1;
			// frames[0].squares = malloc(sizeof(CenarioFrameSquare)*frames[0].squareNumber);
			// if(frames[0].squares != NULL)
			// {
			// 	frames[0].squares[0].x_plane = 17;    	//x do plano
			// 	frames[0].squares[0].y_plane = 8;    	//y do plano
			// 	frames[0].squares[0].x_image = 0;    	//x da imagem
			// 	frames[0].squares[0].y_image = 20;    	//y da imagem
			// 	frames[0].squares[0].w = 12;          	//larguara do frame
			// 	frames[0].squares[0].h = 8;          	//altura do frame
			// 	frames[0].squares[0].bgPlane = BG_B;   //plano do frame
			// }
			// else
			// {
			// 	kprintf("fail to alocate squares");
			// }
			// frames[1].squareNumber = 1;
			// frames[1].squares = malloc(sizeof(CenarioFrameSquare)*frames[1].squareNumber);

			// if(frames[1].squares != NULL)
			// {
			// 	frames[1].squares[0].x_plane = 17;    	//x do plano
			// 	frames[1].squares[0].y_plane = 8;    	//y do plano
			// 	frames[1].squares[0].x_image = 12;    	//x da imagem
			// 	frames[1].squares[0].y_image = 20;    	//y da imagem
			// 	frames[1].squares[0].w = 12;          	//larguara do frame
			// 	frames[1].squares[0].h = 8;          	//altura do frame
			// 	frames[1].squares[0].bgPlane = BG_B;   //plano do frame
				
			// }
			// else
			// {
			// 	kprintf("fail to alocate squares");
			// }

			// frames[2].squareNumber = 1;
			// frames[2].squares = malloc(sizeof(CenarioFrameSquare)*frames[2].squareNumber);

			// if(frames[2].squares != NULL)
			// {
			// 	frames[2].squares[0].x_plane = 17;    	//x do plano
			// 	frames[2].squares[0].y_plane = 8;    	//y do plano
			// 	frames[2].squares[0].x_image = 24;    	//x da imagem
			// 	frames[2].squares[0].y_image = 20;    	//y da imagem
			// 	frames[2].squares[0].w = 12;          	//larguara do frame
			// 	frames[2].squares[0].h = 8;          	//altura do frame
			// 	frames[2].squares[0].bgPlane = BG_B;   //plano do frame

				
			// }
			// else
			// {
			// 	kprintf("fail to alocate squares");
			// }

			// frames[3].squareNumber = 1;
			// frames[3].squares = malloc(sizeof(CenarioFrameSquare)*frames[3].squareNumber);

			// if(frames[3].squares != NULL)
			// {
			// 	frames[3].squares[0].x_plane = 17;    	//x do plano
			// 	frames[3].squares[0].y_plane = 8;    	//y do plano
			// 	frames[3].squares[0].x_image = 12;    	//x da imagem
			// 	frames[3].squares[0].y_image = 20;    	//y da imagem
			// 	frames[3].squares[0].w = 12;          	//larguara do frame
			// 	frames[3].squares[0].h = 8;          	//altura do frame
			// 	frames[3].squares[0].bgPlane = BG_B;   //plano do frame
			// }
			// else
			// {
			// 	kprintf("fail to alocate squares");
			// }

		}
		else
		{
			kprintf("fail to alocate frames");
		}
		cenarioAnimation.frames = frames;

		tileset_size = tileset_size + korea_bgb.tileset->numTile;
	}
	else if (gBG_Choice==CENARIO_BRASIL)
	{
		cenarioAnimation.bgb = unpackTileMap(brasil_bgb.tilemap, NULL);
		if(cenarioAnimation.bgb == NULL)
		{
			kprintf("fail to alocate bgb");
		}
		cenarioAnimation.bga = unpackTileMap(brasil_bga.tilemap, NULL);
		if(cenarioAnimation.bga == NULL)
		{
			kprintf("fail to alocate bga");
		}

		VDP_loadTileSet(brasil_bga.tileset,0,DMA);
        tileset_size = brasil_bga.tileset->numTile;
		VDP_loadTileSet(brasil_bgb.tileset,tileset_size,DMA);
		PAL_setColors(0, brasil_bga.palette->data, 32, DMA_QUEUE);
		VDP_setTileMapEx(BG_A, cenarioAnimation.bga, TILE_ATTR_FULL(PAL0, FALSE,FALSE,FALSE, 0),0,0,0,0,64,28, DMA_QUEUE);
		VDP_setTileMapEx(BG_B, cenarioAnimation.bgb, TILE_ATTR_FULL(PAL0, FALSE,FALSE,FALSE, tileset_size),0,0,0,0,64,22, DMA_QUEUE);
		//VDP_setTileMapEx(BG_B, cenarioAnimation.bgb, TILE_ATTR_FULL(PAL0, TRUE,FALSE,FALSE, tileset_size),0,24,0,24,64,5, DMA_QUEUE);
		

		cenarioAnimation.tilesetIndexBga = 0;
		cenarioAnimation.tilesetIndexBgb = tileset_size;
		cenarioAnimation.AnimationNumber = 4;

		CenarioFrame *frames = malloc(sizeof(CenarioFrame)*cenarioAnimation.AnimationNumber);
 
		if(frames != NULL)
		{
			// frames[0].squareNumber = 1;
			// frames[0].squares = malloc(sizeof(CenarioFrameSquare)*frames[0].squareNumber);
			// if(frames[0].squares != NULL)
			// {
			// 	frames[0].squares[0].x_plane = 17;    	//x do plano
			// 	frames[0].squares[0].y_plane = 8;    	//y do plano
			// 	frames[0].squares[0].x_image = 0;    	//x da imagem
			// 	frames[0].squares[0].y_image = 20;    	//y da imagem
			// 	frames[0].squares[0].w = 12;          	//larguara do frame
			// 	frames[0].squares[0].h = 8;          	//altura do frame
			// 	frames[0].squares[0].bgPlane = BG_B;   //plano do frame
			// }
			// else
			// {
			// 	kprintf("fail to alocate squares");
			// }
			// frames[1].squareNumber = 1;
			// frames[1].squares = malloc(sizeof(CenarioFrameSquare)*frames[1].squareNumber);

			// if(frames[1].squares != NULL)
			// {
			// 	frames[1].squares[0].x_plane = 17;    	//x do plano
			// 	frames[1].squares[0].y_plane = 8;    	//y do plano
			// 	frames[1].squares[0].x_image = 12;    	//x da imagem
			// 	frames[1].squares[0].y_image = 20;    	//y da imagem
			// 	frames[1].squares[0].w = 12;          	//larguara do frame
			// 	frames[1].squares[0].h = 8;          	//altura do frame
			// 	frames[1].squares[0].bgPlane = BG_B;   //plano do frame
				
			// }
			// else
			// {
			// 	kprintf("fail to alocate squares");
			// }

			// frames[2].squareNumber = 1;
			// frames[2].squares = malloc(sizeof(CenarioFrameSquare)*frames[2].squareNumber);

			// if(frames[2].squares != NULL)
			// {
			// 	frames[2].squares[0].x_plane = 17;    	//x do plano
			// 	frames[2].squares[0].y_plane = 8;    	//y do plano
			// 	frames[2].squares[0].x_image = 24;    	//x da imagem
			// 	frames[2].squares[0].y_image = 20;    	//y da imagem
			// 	frames[2].squares[0].w = 12;          	//larguara do frame
			// 	frames[2].squares[0].h = 8;          	//altura do frame
			// 	frames[2].squares[0].bgPlane = BG_B;   //plano do frame

				
			// }
			// else
			// {
			// 	kprintf("fail to alocate squares");
			// }

			// frames[3].squareNumber = 1;
			// frames[3].squares = malloc(sizeof(CenarioFrameSquare)*frames[3].squareNumber);

			// if(frames[3].squares != NULL)
			// {
			// 	frames[3].squares[0].x_plane = 17;    	//x do plano
			// 	frames[3].squares[0].y_plane = 8;    	//y do plano
			// 	frames[3].squares[0].x_image = 12;    	//x da imagem
			// 	frames[3].squares[0].y_image = 20;    	//y da imagem
			// 	frames[3].squares[0].w = 12;          	//larguara do frame
			// 	frames[3].squares[0].h = 8;          	//altura do frame
			// 	frames[3].squares[0].bgPlane = BG_B;   //plano do frame
			// }
			// else
			// {
			// 	kprintf("fail to alocate squares");
			// }

		}
		else
		{
			kprintf("fail to alocate frames");
		}
		cenarioAnimation.frames = frames;

		tileset_size = tileset_size + brasil_bgb.tileset->numTile;
	}
	
	

	KLog_S2("bgb escolhido: ", gBG_Choice, " total de tiles: ", tileset_size);

    return tileset_size;
}

void CEN_clearMemory()
{
	if(cenarioAnimation.bga != NULL)
	{
		free(cenarioAnimation.bga);
		cenarioAnimation.bga = NULL;
	}
	if(cenarioAnimation.bgb != NULL)
	{
		free(cenarioAnimation.bgb);
		cenarioAnimation.bgb = NULL;
	}
	for(int i = 0; i < cenarioAnimation.AnimationNumber; i++)
	{
		if (cenarioAnimation.frames[i].squares != NULL)
		{
			free(cenarioAnimation.frames[i].squares);
			cenarioAnimation.frames[i].squares = NULL;
		}
	}
	if (cenarioAnimation.frames != NULL)
	{
		free(cenarioAnimation.frames);
		cenarioAnimation.frames = NULL;
	}

	MEM_pack();
}
