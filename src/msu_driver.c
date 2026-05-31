#include "include/msu_driver.h"

u16 msu_drv();

vu16 *mcd_cmd = (vu16 *) 0xA12010;
vu32 *mcd_arg = (vu32 *) 0xA12012;
vu8 *mcd_cmd_ck = (vu8 *) 0xA1201F;
vu8 *mcd_stat = (vu8 *) 0xA12020;

void MSU_init()
{
    u16 resp = msu_drv();
    do {
        VDP_drawText("Aguardando MCD Hardware",0,0);
    }while (resp);

    VDP_drawText("ok  ", 0,2);
    VDP_drawText("init driver..          ", 0,3);
    while (*mcd_stat != 1);
    VDP_drawText("waiting...",0,4 );
    while (*mcd_stat == 1); //wait till sub cpu finis initialization
    VDP_drawText("ok", 0,5);
    VDP_clearTextArea(0,0,40,6);
}

void MSU_play(u16 track, u8 loop, u16 loop_offset)
{
    if( track)
    {
        u16 play_cmd = loop ? (loop_offset ? 0x1A00 : 0x1200) : 0x1100;
        *mcd_cmd = play_cmd | track;
        if(loop_offset)
        {
            *mcd_arg = loop_offset * 75; //loop offset (12 sec in this sample). Used only for cmd 0x1A00
        }
        *mcd_cmd_ck = *mcd_cmd_ck + 1;
    }
}

void MSU_pause(u16 faidingTime)
{
    *mcd_cmd = 0x1300 | 75 * faidingTime;
    *mcd_cmd_ck = *mcd_cmd_ck + 1;
}

void MSU_resume()
{
    *mcd_cmd = 0x1400;
    *mcd_cmd_ck = *mcd_cmd_ck + 1;
}
