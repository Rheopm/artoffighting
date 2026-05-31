#ifndef __MSU_DRIVER_H__
#define __MSU_DRIVER_H__

#include <genesis.h>

enum MUSICAS{
    MUSICA_TERRY = 1,
    MUSICA_MAI,
    MUSICA_JIN,
    MUSICA_GEESE,
    MUSICA_BLUEMARY,
    MUSICA_STAFF,
    MUSICA_SELECT,
    MUSICA_JOE
};

/**
 * @brief init msu driver and wait hardware connection
 * 
 */
void MSU_init();

/**
 * @brief play msu music
 * 
 * @param track track number
 * @param loop enable loop
 * @param loop_offset loop offset in seconds
 */
void MSU_play(u16 track, u8 loop, u16 loop_offset);
/**
 * @brief pause msu music
 * 
 * @param faidingTime fading time in seconds
 */
void MSU_pause(u16 faidingTime);

/**
 * @brief resume msu music
 * 
 */
void MSU_resume();


#endif