#ifndef __DEEP_BUFFERING_H__
#define __DEEP_BUFFERING_H__
#include <genesis.h>

#define CMD_QCF     0x00000001 //meia lua pra frente
#define CMD_QCB     0x00000002 //meia lua pra tras
#define CMD_DP      0x00000004 //shoris pra frente
#define CMD_RDP     0x00000008 //shoris pra tras
#define CMD_HCF     0x00000010 //meia lua completa frente
#define CMD_HCB     0x00000020 //meia lua completa tras
#define CMD_QCF2    0x00000040 //meia lua pra frente 2x 
#define CMD_QCB2    0x00000080 //meia lua pra tras 2x 
#define CMD_FHCF    0x00000100 //frente meia lua pra frente
#define CMD_BHCB    0x00000200 //tras meia lua pra tras
#define CMD_FF      0x00000400 //frente frente
#define CMD_BB      0x00000800 //tras tras
#define CMD_QCFQCB  0x00001000 //meia lua pra frente meia lua pra tras
#define CMD_QCBQCF  0x00002000 //meia lua pra tras meia lua pra frente
#define CMD_CBF     0x00004000 //segura tras depois frente
#define CMD_CFB     0x00008000 //segura frente depois tras
#define CMD_CDU     0x00010000 //segura baixo depois cima


#define DB_BUTTON_DOWN (BUTTON_DOWN | (BUTTON_DOWN << 16))
#define DB_BUTTON_UP (BUTTON_UP | (BUTTON_UP << 16))
#define DB_BUTTON_LEFT (BUTTON_LEFT | (BUTTON_LEFT << 16))
#define DB_BUTTON_RIGHT (BUTTON_RIGHT | (BUTTON_RIGHT << 16))

#define DB_BUTTON_A (BUTTON_A | (BUTTON_A << 16))
#define DB_BUTTON_B (BUTTON_B | (BUTTON_B << 16))
#define DB_BUTTON_C (BUTTON_C | (BUTTON_C << 16))
#define DB_BUTTON_C (BUTTON_C | (BUTTON_C << 16))
#define DB_BUTTON_X (BUTTON_X | (BUTTON_X << 16))
#define DB_BUTTON_Y (BUTTON_Y | (BUTTON_Y << 16))
#define DB_BUTTON_Z (BUTTON_Z | (BUTTON_Z << 16))

typedef union
{
    u32 buffer;
    struct 
    {
        u16 tick2;
        u16 tick1;
    };
}ButtonBuffer;


typedef struct 
{
    u8 timer;
    u16 commandCheck;
}ComandCheck;


extern ButtonBuffer btPress[2], btRelease[2], btDirPress[2], btDirRelease[2];
extern u16 btJustPress[2], btHold[2]; 

u32 fightInputSystem(u16 joy);
void initDebug();


#endif