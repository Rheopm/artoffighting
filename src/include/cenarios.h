/**
 * @file cenarios.h
 * @author Paulo Linhares 
 * @version 0.1
 * @date 2022-06-03
 * 
 * @copyright Copyright (c) 2023
 * 
 * 
 * Para utilizar essa biblioteca você deve criar as imagens dos cenarios
 * com os frames sobrepostos entao se o cenario tiver 512x240 e dois frames
 * a imagem ficara com tamanho 512x480.
 */

#ifndef __CENARIOS_H__
#define __CENARIOS_H__

#include <genesis.h>


/**
 * @brief lista de cenarios
 * 
 */
enum CENARIOS{
    CENARIO_JAPAO,
    CENARIO_OMEGA,
    CENARIO_KOREA,
    CENARIO_BRASIL,
    CENARIO_INCORPORADO,
    CENARIO_SPAIN,
    CENARIO_PARKING,
    CENARIO_SUBWAY,
    CENARIO_PALACE,
    CENARIO_TOTAL,
};


typedef struct 
{
    s16 x_plane;    //x do plano
    s16 y_plane;    //y do plano
    s16 x_image;    //x da imagem
    s16 y_image;    //y da imagem
    s16 w;          //larguara do frame
    s16 h;          //altura do frame

    VDPPlane bgPlane;   //plano da animação
}CenarioFrameSquare;

typedef struct 
{
    CenarioFrameSquare *squares; //frames da animacao
    u8 squareNumber; // numero total de frames de animação
}CenarioFrame;

typedef struct 
{
    TileMap *bga;  // tilemap do BGA
    TileMap *bgb;  // tilemap do BGB

    u16 tilesetIndexBga;
    u16 tilesetIndexBgb;

    u8 AnimationNumber; //numero de frames unicos;
    CenarioFrame *frames;
}CenarioAnimation;


/**
 * @brief Anima o cenario escolhido
 * 
 * @param gBG_Choice cemario escolhido 
 * @param ping se ping == 9 então muda o frame do cenario
 */
void CEN_Anima(enum CENARIOS gBG_Choice, u8 ping);

/**
 * @brief Anima o cenario
 * 
 * @param x posição x do plano
 * @param y posição y do plano
 * @param x_len compimento no eixo x
 * @param y_len comprimento no eixo y
 * @param frames_num numéro de frames da animação
 */
void CEN_AnimaEx(u16 x, u16 y, u16 x_len, u16 y_len, u8 frames_num);

/**
 * @brief inicia a animação do cenario
 * 
 * @param gBG_Choice cenário escolhido
 * @return u16 total de tiles do cenario 
 */
u16 CEN_init( enum CENARIOS gBG_Choice);

/**
 * @brief libera todos os sprites usados no cenário
 * 
 */
void CEN_clearMemory();

#endif