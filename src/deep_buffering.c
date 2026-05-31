#include "include/deep_buffering.h"

ButtonBuffer btDirPress[2], btPress[2], btRelease[2], btDirRelease[2];
u16 btJustPress[2], btHold[2];
ComandCheck QCF[2], QCB[2], DP[2], RDP[2], HCF[2], HCB[2], QCF2[2], QCB2[2], FHCF[2], BHCB[2], FF[2], BB[2], QCFQCB[2], QCBQCF[2], CBF[2], CFB[2], CDU[2], QCFQCBsmp[2], QCBQCFsmp[2];

static void qcf_check(u16 joy);
static void qcb_check(u16 joy);
static void dp_check(u16 joy);
static void rdp_check(u16 joy);
static void hcf_check(u16 joy);
static void hcb_check(u16 joy);
static void qcf2_check(u16 joy);
static void qcb2_check(u16 joy);
static void fhcf_check(u16 joy);
static void bhcb_check(u16 joy);
static void ff_check(u16 joy);
static void bb_check(u16 joy);
static void qcfqcb_check(u16 joy);
static void qcfqcb_smp_check(u16 joy);
static void qcbqcf_check(u16 joy);
static void qcbqcf_smp_check(u16 joy);
static void cbf_check(u16 joy);
static void cfb_check(u16 joy);
static void cdu_check(u16 joy);

u32 fightInputSystem(u16 joy){
    u32 commands = 0;
    u16 joyRead = JOY_readJoypad(joy);
    btDirPress[joy].buffer = (btDirPress[joy].buffer << 16) | joyRead & BUTTON_DIR;
    btPress[joy].buffer = (btPress[joy].buffer << 16) | joyRead & BUTTON_BTN;
    btDirRelease[joy].buffer = (btDirRelease[joy].buffer << 16) | (~(btDirPress[joy].tick1 & btDirPress[joy].tick2) & btDirPress[joy].tick1);
    btRelease[joy].buffer = (btRelease[joy].buffer << 16) | (~(btPress[joy].tick1 & btPress[joy].tick2) & btPress[joy].tick2);

    btHold[joy] = btPress[joy].tick1 & btPress[joy].tick2;
    btJustPress[joy] = (btPress[joy].tick1 & ~btPress[joy].tick2);

    qcf_check(joy);
    qcb_check(joy);
    dp_check(joy);
    rdp_check(joy);
    hcf_check(joy);
    hcb_check(joy);
    qcf2_check(joy);
    qcb2_check(joy);
    fhcf_check(joy);
    bhcb_check(joy);
    ff_check(joy);
    bb_check(joy);
    qcfqcb_check(joy);
    qcfqcb_smp_check(joy);
    qcbqcf_check(joy);
    qcbqcf_smp_check(joy);
    cbf_check(joy);
    cfb_check(joy);
    cdu_check(joy);

    commands |= (QCF[joy].commandCheck == 3) ? CMD_QCF : 0;
    commands |= (QCB[joy].commandCheck == 3) ? CMD_QCB : 0;
    commands |= (DP[joy].commandCheck == 4) ? CMD_DP : 0;
    commands |= (RDP[joy].commandCheck == 4) ? CMD_RDP : 0;
    commands |= (HCF[joy].commandCheck == 4) ? CMD_HCF : 0;
    commands |= (HCB[joy].commandCheck == 4) ? CMD_HCB : 0;
    commands |= (QCF2[joy].commandCheck == 6) ? CMD_QCF2 : 0;
    commands |= (QCB2[joy].commandCheck == 6) ? CMD_QCB2 : 0;
    commands |= (FHCF[joy].commandCheck == 5) ? CMD_FHCF : 0;
    commands |= (BHCB[joy].commandCheck == 5) ? CMD_BHCB : 0;
    commands |= (FF[joy].commandCheck == 3) ? CMD_FF : 0;
    commands |= (BB[joy].commandCheck == 3) ? CMD_BB : 0;
    commands |= (QCFQCB[joy].commandCheck == 6) ? CMD_QCFQCB : 0;
    commands |= (QCFQCBsmp[joy].commandCheck == 5) ? CMD_QCFQCB : 0;
    commands |= (QCBQCF[joy].commandCheck == 6) ? CMD_QCBQCF : 0;
    commands |= (QCBQCFsmp[joy].commandCheck == 5) ? CMD_QCBQCF : 0;
    commands |= (CBF[joy].commandCheck == 3) ? CMD_CBF : 0;
    commands |= (CFB[joy].commandCheck == 3) ? CMD_CFB : 0;
    commands |= (CDU[joy].commandCheck == 3) ? CMD_CDU : 0;
    return commands;
}

static void qcf_check(u16 joy){
    if (QCF[joy].timer > 0)
    {
        QCF[joy].timer--;
    }else{
        QCF[joy].commandCheck = 0;
    }
    if((!QCF[joy].commandCheck) && (btDirPress[joy].tick1  == BUTTON_DOWN || (btDirPress[joy].tick2 == BUTTON_DOWN))){ //baixo
        QCF[joy].commandCheck =1;
        QCF[joy].timer = 9;
    }else if((QCF[joy].commandCheck == 1) && (btDirPress[joy].tick1 == (BUTTON_DOWN |BUTTON_RIGHT) || (btDirPress[joy].tick2 == (BUTTON_DOWN |BUTTON_RIGHT)))){ //diagonal pra baixo
        QCF[joy].commandCheck =2;
        QCF[joy].timer = 9;
    }else if((QCF[joy].commandCheck == 2) && (btDirPress[joy].tick1 == (BUTTON_RIGHT) || (btDirPress[joy].tick2 == (BUTTON_RIGHT)))){ //diagonal frente
        QCF[joy].commandCheck =3;
        QCF[joy].timer = 9;
    }
}

static void qcb_check(u16 joy){
    if (QCB[joy].timer > 0)
    {
        QCB[joy].timer--;
    }else{
        QCB[joy].commandCheck = 0;
    }
    if((!QCB[joy].commandCheck) && (btDirPress[joy].tick1 == BUTTON_DOWN || (btDirPress[joy].tick2 == BUTTON_DOWN))){ //baixo
        QCB[joy].commandCheck =1;
        QCB[joy].timer = 9;
    }else if((QCB[joy].commandCheck == 1) && (btDirPress[joy].tick1 == (BUTTON_DOWN |BUTTON_LEFT) || (btDirPress[joy].tick2 == (BUTTON_DOWN |BUTTON_LEFT)))){ //diagonal pra baixo
        QCB[joy].commandCheck =2;
        QCB[joy].timer = 9;
    }else if((QCB[joy].commandCheck == 2) && (btDirPress[joy].tick1 == (BUTTON_LEFT) || (btDirPress[joy].tick2 == (BUTTON_LEFT)))){ //diagonal frente
        QCB[joy].commandCheck =3;
        QCB[joy].timer = 9;
    }
}

static void dp_check(u16 joy){
    if (DP[joy].timer > 0)
    {
        DP[joy].timer--;
    }else{
        DP[joy].commandCheck = 0;
    }
    if((DP[joy].commandCheck==0) && (btDirPress[joy].tick1 == BUTTON_RIGHT || (btDirPress[joy].tick2 == BUTTON_RIGHT))){ //baixo
        DP[joy].commandCheck =1;
        DP[joy].timer = 9;
    }else if((DP[joy].commandCheck == 1) && (btDirPress[joy].tick1 == BUTTON_DOWN || (btDirPress[joy].tick2 == BUTTON_DOWN))){ //baixo
        DP[joy].commandCheck =2;
        DP[joy].timer = 9;
    }else if((DP[joy].commandCheck == 2) && (btDirPress[joy].tick1 == (BUTTON_DOWN |BUTTON_RIGHT) || (btDirPress[joy].tick2 == (BUTTON_DOWN |BUTTON_RIGHT)))){ //diagonal pra baixo
        DP[joy].commandCheck =3;
        DP[joy].timer = 9;
    }else if((DP[joy].commandCheck == 3) && (btDirPress[joy].tick1 == (BUTTON_RIGHT) || (btDirPress[joy].tick2 == (BUTTON_RIGHT)))){ //diagonal frente
        DP[joy].commandCheck =4;
        DP[joy].timer = 9;
    }
}

static void rdp_check(u16 joy){
    if (RDP[joy].timer > 0)
    {
        RDP[joy].timer--;
    }else{
        RDP[joy].commandCheck = 0;
    }
    if((RDP[joy].commandCheck==0) && (btDirPress[joy].tick1 == BUTTON_LEFT || (btDirPress[joy].tick2 == BUTTON_LEFT))){ //baixo
        RDP[joy].commandCheck =1;
        RDP[joy].timer = 9;
    }else if((RDP[joy].commandCheck == 1) && (btDirPress[joy].tick1 == BUTTON_DOWN || (btDirPress[joy].tick2 == BUTTON_DOWN))){ //baixo
        RDP[joy].commandCheck =2;
        RDP[joy].timer = 9;
    }else if((RDP[joy].commandCheck == 2) && (btDirPress[joy].tick1 == (BUTTON_DOWN |BUTTON_LEFT) || (btDirPress[joy].tick2 == (BUTTON_DOWN |BUTTON_LEFT)))){ //diagonal pra baixo
        RDP[joy].commandCheck =3;
        RDP[joy].timer = 9;
    }else if((RDP[joy].commandCheck == 3) && (btDirPress[joy].tick1 == (BUTTON_LEFT) || (btDirPress[joy].tick2 == (BUTTON_LEFT)))){ //diagonal frente
        RDP[joy].commandCheck =4;
        RDP[joy].timer = 9;
    }
}

static void hcf_check(u16 joy){
    if (HCF[joy].timer > 0)
    {
        HCF[joy].timer--;
    }else{
        HCF[joy].commandCheck = 0;
    }
    if((HCF[joy].commandCheck==0) && (btDirPress[joy].tick1 == BUTTON_LEFT || (btDirPress[joy].tick2 == BUTTON_LEFT))){ //baixo
        HCF[joy].commandCheck =1;
        HCF[joy].timer = 9;
    }else if((HCF[joy].commandCheck == 1) && (btDirPress[joy].tick1 == (BUTTON_DOWN | BUTTON_LEFT) || (btDirPress[joy].tick2 == (BUTTON_DOWN | BUTTON_LEFT)))){ //baixo
        HCF[joy].commandCheck =2;
        HCF[joy].timer = 9;
    }else if((HCF[joy].commandCheck == 2) && (btDirPress[joy].tick1 == (BUTTON_DOWN |BUTTON_RIGHT) || (btDirPress[joy].tick2 == (BUTTON_DOWN |BUTTON_RIGHT)))){
        HCF[joy].commandCheck =3;
        HCF[joy].timer = 9;
    }else if((HCF[joy].commandCheck == 3) && (btDirPress[joy].tick1 == (BUTTON_RIGHT) || (btDirPress[joy].tick2 == (BUTTON_RIGHT)))){
        HCF[joy].commandCheck =4;
        HCF[joy].timer = 9;
    }
}

static void hcb_check(u16 joy){
    if (HCB[joy].timer > 0)
    {
        HCB[joy].timer--;
    }else{
        HCB[joy].commandCheck = 0;
    }
    if((HCB[joy].commandCheck==0) && (btDirPress[joy].tick1 == BUTTON_RIGHT || (btDirPress[joy].tick2 == BUTTON_RIGHT))){ //baixo
        HCB[joy].commandCheck =1;
        HCB[joy].timer = 9;
    }else if((HCB[joy].commandCheck == 1) && (btDirPress[joy].tick1 == (BUTTON_DOWN |BUTTON_RIGHT) || (btDirPress[joy].tick2 == (BUTTON_DOWN |BUTTON_RIGHT)))){ //diagonal pra baixo
        HCB[joy].commandCheck =2;
        HCB[joy].timer = 9;
    }else if((HCB[joy].commandCheck == 2) && (btDirPress[joy].tick1 == (BUTTON_DOWN |BUTTON_LEFT) || (btDirPress[joy].tick2 == (BUTTON_DOWN |BUTTON_LEFT)))){
        HCB[joy].commandCheck =3;
        HCB[joy].timer = 9;
    }else if((HCB[joy].commandCheck == 3) && (btDirPress[joy].tick1 == (BUTTON_LEFT) || (btDirPress[joy].tick2 == (BUTTON_LEFT)))){
        HCB[joy].commandCheck =4;
        HCB[joy].timer = 9;
    }
}

static void qcf2_check(u16 joy){
    if (QCF2[joy].timer > 0)
    {
        QCF2[joy].timer--;
    }else{
        QCF2[joy].commandCheck = 0;
    }
    if((QCF2[joy].commandCheck == 0) && (btDirPress[joy].tick1 == BUTTON_DOWN || (btDirPress[joy].tick2 == BUTTON_DOWN))){ //baixo
        QCF2[joy].commandCheck =1;
        QCF2[joy].timer = 9;
    }else if((QCF2[joy].commandCheck == 1) && (btDirPress[joy].tick1 == (BUTTON_DOWN |BUTTON_RIGHT) || (btDirPress[joy].tick2 == (BUTTON_DOWN |BUTTON_RIGHT)))){ //diagonal pra baixo
        QCF2[joy].commandCheck =2;
        QCF2[joy].timer = 9;
    }else if((QCF2[joy].commandCheck == 2) && (btDirPress[joy].tick1 == (BUTTON_RIGHT) || (btDirPress[joy].tick2 == (BUTTON_RIGHT)))){ //diagonal frente
        QCF2[joy].commandCheck =3;
        QCF2[joy].timer = 9;
    }else if((QCF2[joy].commandCheck == 3) && (btDirPress[joy].tick1 == BUTTON_DOWN || (btDirPress[joy].tick2 == BUTTON_DOWN))){ //baixo
        QCF2[joy].commandCheck =4;
        QCF2[joy].timer = 9;
    }else if((QCF2[joy].commandCheck == 4) && (btDirPress[joy].tick1 == (BUTTON_RIGHT |BUTTON_DOWN) || (btDirPress[joy].tick2 == (BUTTON_RIGHT |BUTTON_DOWN)))){
        QCF2[joy].commandCheck =5;
        QCF2[joy].timer = 9;
    }else if((QCF2[joy].commandCheck == 5) && (btDirPress[joy].tick1 == (BUTTON_RIGHT) || (btDirPress[joy].tick2 == (BUTTON_RIGHT)))){
        QCF2[joy].commandCheck =6;
        QCF2[joy].timer = 9;
    }
}

static void qcb2_check(u16 joy){
    if (QCB2[joy].timer > 0)
    {
        QCB2[joy].timer--;
    }else{
        QCB2[joy].commandCheck = 0;
    }
    if((QCB2[joy].commandCheck == 0) && (btDirPress[joy].tick1 == BUTTON_DOWN || (btDirPress[joy].tick2 == BUTTON_DOWN))){ //baixo
        QCB2[joy].commandCheck =1;
        QCB2[joy].timer = 9;
    }else if((QCB2[joy].commandCheck == 1) && (btDirPress[joy].tick1 == (BUTTON_DOWN |BUTTON_LEFT) || (btDirPress[joy].tick2 == (BUTTON_DOWN |BUTTON_LEFT)))){ //diagonal pra baixo
        QCB2[joy].commandCheck =2;
        QCB2[joy].timer = 9;
    }else if((QCB2[joy].commandCheck == 2) && (btDirPress[joy].tick1 == (BUTTON_LEFT) || (btDirPress[joy].tick2 == (BUTTON_LEFT)))){ //diagonal frente
        QCB2[joy].commandCheck =3;
        QCB2[joy].timer = 9;
    }else if((QCB2[joy].commandCheck == 3) && (btDirPress[joy].tick1 == BUTTON_DOWN || (btDirPress[joy].tick2 == BUTTON_DOWN))){ //baixo
        QCB2[joy].commandCheck =4;
        QCB2[joy].timer = 9;
    }else if((QCB2[joy].commandCheck == 4) && (btDirPress[joy].tick1 == (BUTTON_LEFT |BUTTON_DOWN) || (btDirPress[joy].tick2 == (BUTTON_LEFT |BUTTON_DOWN)))){
        QCB2[joy].commandCheck =5;
        QCB2[joy].timer = 9;
    }else if((QCB2[joy].commandCheck == 5) && (btDirPress[joy].tick1 == (BUTTON_LEFT) || (btDirPress[joy].tick2 == (BUTTON_LEFT)))){
        QCB2[joy].commandCheck =6;
        QCB2[joy].timer = 9;
    }
}

static void fhcf_check(u16 joy){
    if (FHCF[joy].timer > 0)
    {
        FHCF[joy].timer--;
    }else{
        FHCF[joy].commandCheck = 0;
    }
    if((FHCF[joy].commandCheck==0) && (btDirPress[joy].tick1 == BUTTON_RIGHT || (btDirPress[joy].tick2 == BUTTON_RIGHT))){ //baixo
        FHCF[joy].commandCheck =1;
        FHCF[joy].timer = 9;
    }else if((FHCF[joy].commandCheck == 1) && (btDirPress[joy].tick1 == (BUTTON_LEFT) || (btDirPress[joy].tick2 == (BUTTON_LEFT)))){
        FHCF[joy].commandCheck =2;
        FHCF[joy].timer = 9;
    }else if((FHCF[joy].commandCheck == 2) && (btDirPress[joy].tick1 == (BUTTON_DOWN |BUTTON_LEFT) || (btDirPress[joy].tick2 == (BUTTON_DOWN |BUTTON_LEFT)))){
        FHCF[joy].commandCheck =3;
        FHCF[joy].timer = 9;
    }else if((FHCF[joy].commandCheck == 3) && (btDirPress[joy].tick1 == (BUTTON_DOWN |BUTTON_RIGHT) || (btDirPress[joy].tick2 == (BUTTON_DOWN |BUTTON_RIGHT)))){
        FHCF[joy].commandCheck =4;
        FHCF[joy].timer = 9;
    }else if((FHCF[joy].commandCheck == 4) && (btDirPress[joy].tick1 == (BUTTON_RIGHT) || (btDirPress[joy].tick2 == (BUTTON_RIGHT)))){
        FHCF[joy].commandCheck =5;
        FHCF[joy].timer = 9;
    }
}

static void bhcb_check(u16 joy){
    if (BHCB[joy].timer > 0)
    {
        BHCB[joy].timer--;
    }else{
        BHCB[joy].commandCheck = 0;
    }
    if((BHCB[joy].commandCheck==0) && (btDirPress[joy].tick1 == BUTTON_LEFT || (btDirPress[joy].tick2 == BUTTON_LEFT))){ //baixo
        BHCB[joy].commandCheck =1;
        BHCB[joy].timer = 9;
    }else if((BHCB[joy].commandCheck == 1) && (btDirPress[joy].tick1 == (BUTTON_RIGHT) || (btDirPress[joy].tick2 == (BUTTON_RIGHT)))){
        BHCB[joy].commandCheck =2;
        BHCB[joy].timer = 9;
    }else if((BHCB[joy].commandCheck == 2) && (btDirPress[joy].tick1 == (BUTTON_DOWN |BUTTON_RIGHT) || (btDirPress[joy].tick2 == (BUTTON_DOWN |BUTTON_RIGHT)))){
        BHCB[joy].commandCheck =3;
        BHCB[joy].timer = 9;
    }else if((BHCB[joy].commandCheck == 3) && (btDirPress[joy].tick1 == (BUTTON_DOWN |BUTTON_LEFT) || (btDirPress[joy].tick2 == (BUTTON_DOWN |BUTTON_LEFT)))){
        BHCB[joy].commandCheck =4;
        BHCB[joy].timer = 9;
    }else if((BHCB[joy].commandCheck == 4) && (btDirPress[joy].tick1 == (BUTTON_LEFT) || (btDirPress[joy].tick2 == (BUTTON_LEFT)))){
        BHCB[joy].commandCheck =5;
        BHCB[joy].timer = 9;
    }
}

static void ff_check(u16 joy){
    if (FF[joy].timer > 0)
    {
        FF[joy].timer--;
    }else{
        FF[joy].commandCheck = 0;
    }
    if((FF[joy].commandCheck==0) && (btDirPress[joy].tick1 == BUTTON_RIGHT || (btDirPress[joy].tick2 == BUTTON_RIGHT))){ //baixo
        FF[joy].commandCheck =1;
        FF[joy].timer = 3;
    }else if((FF[joy].commandCheck == 1) && (btDirPress[joy].tick1 == (0) || (btDirPress[joy].tick2 == (0)))){ //solto
        FF[joy].commandCheck =2;
        FF[joy].timer = 9;
    }else if((FF[joy].commandCheck == 2) && (btDirPress[joy].tick1 == (BUTTON_RIGHT) || (btDirPress[joy].tick2 == (BUTTON_RIGHT)))){
        FF[joy].commandCheck =3;
        FF[joy].timer = 9;
    }
}

static void bb_check(u16 joy){
    if (BB[joy].timer > 0)
    {
        BB[joy].timer--;
    }else{
        BB[joy].commandCheck = 0;
    }
    if((BB[joy].commandCheck==0) && (btDirPress[joy].tick1 == BUTTON_LEFT || (btDirPress[joy].tick2 == BUTTON_LEFT))){ //baixo
        BB[joy].commandCheck =1;
        BB[joy].timer = 3;
    }else if((BB[joy].commandCheck == 1) && (btDirPress[joy].tick1 == (0) || (btDirPress[joy].tick2 == (0)))){ //solto
        BB[joy].commandCheck =2;
        BB[joy].timer = 9;
    }else if((BB[joy].commandCheck == 2) && (btDirPress[joy].tick1 == (BUTTON_LEFT) || (btDirPress[joy].tick2 == (BUTTON_LEFT)))){
        BB[joy].commandCheck =3;
        BB[joy].timer = 9;
    }
}

static void qcfqcb_check(u16 joy){
    if (QCFQCB[joy].timer > 0)
    {
        QCFQCB[joy].timer--;
    }else{
        QCFQCB[joy].commandCheck = 0;
    }
    if((QCFQCB[joy].commandCheck == 0) && (btDirPress[joy].tick1 == BUTTON_DOWN || (btDirPress[joy].tick2 == BUTTON_DOWN))){ //baixo
        QCFQCB[joy].commandCheck =1;
        QCFQCB[joy].timer = 9;
    }else if((QCFQCB[joy].commandCheck == 1) && (btDirPress[joy].tick1 == (BUTTON_DOWN | BUTTON_RIGHT) || (btDirPress[joy].tick2 == (BUTTON_DOWN | BUTTON_RIGHT)))){ //diagonal baixo frente
        QCFQCB[joy].commandCheck =2;
        QCFQCB[joy].timer = 9;
    }else if((QCFQCB[joy].commandCheck == 2) && (btDirPress[joy].tick1 == (BUTTON_RIGHT) || (btDirPress[joy].tick2 == (BUTTON_RIGHT)))){ //frente
        QCFQCB[joy].commandCheck =3;
        QCFQCB[joy].timer = 9;
    }else if((QCFQCB[joy].commandCheck == 3) && (btDirPress[joy].tick1 == BUTTON_DOWN || (btDirPress[joy].tick2 == BUTTON_DOWN))){ //baixo
        QCFQCB[joy].commandCheck =4;
        QCFQCB[joy].timer = 9;
    }else if((QCFQCB[joy].commandCheck == 4) && (btDirPress[joy].tick1 == (BUTTON_DOWN | BUTTON_LEFT) || (btDirPress[joy].tick2 == (BUTTON_DOWN | BUTTON_LEFT)))){ //diagonal baixo tras
        QCFQCB[joy].commandCheck =5;
        QCFQCB[joy].timer = 9;
    }else if((QCFQCB[joy].commandCheck == 5) && (btDirPress[joy].tick1 == (BUTTON_LEFT) || (btDirPress[joy].tick2 == (BUTTON_LEFT)))){ //tras
        QCFQCB[joy].commandCheck =6;
        QCFQCB[joy].timer = 9;
    }
}

static void qcfqcb_smp_check(u16 joy){
    if (QCFQCBsmp[joy].timer > 0)
    {
        QCFQCBsmp[joy].timer--;
    }else{
        QCFQCBsmp[joy].commandCheck = 0;
    }
    if((QCFQCBsmp[joy].commandCheck == 0) && (btDirPress[joy].tick1 == BUTTON_DOWN || (btDirPress[joy].tick2 == BUTTON_DOWN))){ //baixo
        QCFQCBsmp[joy].commandCheck =1;
        QCFQCBsmp[joy].timer = 9;
    }else if((QCFQCBsmp[joy].commandCheck == 1) && (btDirPress[joy].tick1 == (BUTTON_DOWN | BUTTON_RIGHT) || (btDirPress[joy].tick2 == (BUTTON_DOWN | BUTTON_RIGHT)))){ //diagonal baixo frente
        QCFQCBsmp[joy].commandCheck =2;
        QCFQCBsmp[joy].timer = 9;
    }else if((QCFQCBsmp[joy].commandCheck == 2) && (btDirPress[joy].tick1 == (BUTTON_RIGHT) || (btDirPress[joy].tick2 == (BUTTON_RIGHT)))){ //frente
        QCFQCBsmp[joy].commandCheck =3;
        QCFQCBsmp[joy].timer = 9;
    }else if((QCFQCBsmp[joy].commandCheck == 3) && (btDirPress[joy].tick1 == BUTTON_DOWN || (btDirPress[joy].tick2 == BUTTON_DOWN))){ //baixo
        QCFQCBsmp[joy].commandCheck =4;
        QCFQCBsmp[joy].timer = 9;
    }else if((QCFQCBsmp[joy].commandCheck == 5) && (btDirPress[joy].tick1 == (BUTTON_LEFT) || (btDirPress[joy].tick2 == (BUTTON_LEFT)))){ //tras
        QCFQCBsmp[joy].commandCheck =5;
        QCFQCBsmp[joy].timer = 9;
    }
}

static void qcbqcf_check(u16 joy){
    if (QCBQCF[joy].timer > 0)
    {
        QCBQCF[joy].timer--;
    }else{
        QCBQCF[joy].commandCheck = 0;
    }
    if((QCBQCF[joy].commandCheck == 0) && (btDirPress[joy].tick1 == BUTTON_DOWN || (btDirPress[joy].tick2 == BUTTON_DOWN))){ //baixo
        QCBQCF[joy].commandCheck =1;
        QCBQCF[joy].timer = 9;
    }else if((QCBQCF[joy].commandCheck == 1) && (btDirPress[joy].tick1 == (BUTTON_DOWN | BUTTON_LEFT) || (btDirPress[joy].tick2 == (BUTTON_DOWN | BUTTON_LEFT)))){ //diagonal baixo frente
        QCBQCF[joy].commandCheck =2;
        QCBQCF[joy].timer = 9;
    }else if((QCBQCF[joy].commandCheck == 2) && (btDirPress[joy].tick1 == (BUTTON_LEFT) || (btDirPress[joy].tick2 == (BUTTON_LEFT)))){ //frente
        QCBQCF[joy].commandCheck =3;
        QCBQCF[joy].timer = 9;
    }else if((QCBQCF[joy].commandCheck == 3) && (btDirPress[joy].tick1 == BUTTON_DOWN || (btDirPress[joy].tick2 == BUTTON_DOWN))){ //baixo
        QCBQCF[joy].commandCheck =4;
        QCBQCF[joy].timer = 9;
    }else if((QCBQCF[joy].commandCheck == 4) && (btDirPress[joy].tick1 == (BUTTON_DOWN | BUTTON_RIGHT) || (btDirPress[joy].tick2 == (BUTTON_DOWN | BUTTON_RIGHT)))){ //diagonal baixo tras
        QCBQCF[joy].commandCheck =5;
        QCBQCF[joy].timer = 9;
    }else if((QCBQCF[joy].commandCheck == 5) && (btDirPress[joy].tick1 == (BUTTON_RIGHT) || (btDirPress[joy].tick2 == (BUTTON_RIGHT)))){ //tras
        QCBQCF[joy].commandCheck =6;
        QCBQCF[joy].timer = 9;
    }
}

static void qcbqcf_smp_check(u16 joy){
    if (QCBQCFsmp[joy].timer > 0)
    {
        QCBQCFsmp[joy].timer--;
    }else{
        QCBQCFsmp[joy].commandCheck = 0;
    }
    if((QCBQCFsmp[joy].commandCheck == 0) && (btDirPress[joy].tick1 == BUTTON_DOWN || (btDirPress[joy].tick2 == BUTTON_DOWN))){ //baixo
        QCBQCFsmp[joy].commandCheck =1;
        QCBQCFsmp[joy].timer = 9;
    }else if((QCBQCFsmp[joy].commandCheck == 1) && (btDirPress[joy].tick1 == (BUTTON_DOWN | BUTTON_LEFT) || (btDirPress[joy].tick2 == (BUTTON_DOWN | BUTTON_LEFT)))){ //diagonal baixo frente
        QCBQCFsmp[joy].commandCheck =2;
        QCBQCFsmp[joy].timer = 9;
    }else if((QCBQCFsmp[joy].commandCheck == 2) && (btDirPress[joy].tick1 == (BUTTON_LEFT) || (btDirPress[joy].tick2 == (BUTTON_LEFT)))){ //frente
        QCBQCFsmp[joy].commandCheck =3;
        QCBQCFsmp[joy].timer = 9;
    }else if((QCBQCFsmp[joy].commandCheck == 3) && (btDirPress[joy].tick1 == BUTTON_DOWN || (btDirPress[joy].tick2 == BUTTON_DOWN))){ //baixo
        QCBQCFsmp[joy].commandCheck =4;
        QCBQCFsmp[joy].timer = 9;
    }else if((QCBQCFsmp[joy].commandCheck == 5) && (btDirPress[joy].tick1 == (BUTTON_RIGHT) || (btDirPress[joy].tick2 == (BUTTON_RIGHT)))){ //tras
        QCBQCFsmp[joy].commandCheck =5;
        QCBQCFsmp[joy].timer = 9;
    }
}

static void cbf_check(u16 joy){
    if (CBF[joy].timer > 0)
    {
       if(CBF[joy].commandCheck != 1){
            CBF[joy].timer--;
        }
    }else{
        CBF[joy].commandCheck = 0;
    }

    if((CBF[joy].commandCheck==0) && ((btDirPress[joy].tick1 & BUTTON_LEFT) || ((btDirPress[joy].tick2 & BUTTON_LEFT)))){ //frente
        CBF[joy].commandCheck =1;
        CBF[joy].timer = 9;
    }else if(CBF[joy].commandCheck == 1){ //os dois ticks frente
        if ((btDirPress[joy].tick1 & BUTTON_LEFT) && ((btDirPress[joy].tick2 & BUTTON_LEFT)))
        {
            if (CBF[joy].timer < 9)
            {
                CBF[joy].timer = 10;
            }else{
                CBF[joy].timer++;
            }
        }else if (CBF[joy].timer > 69){
            CBF[joy].commandCheck = 2;
            CBF[joy].timer = 9;
        }else{
            CBF[joy].timer = 0;
        }
    }else if((CBF[joy].commandCheck == 2) && (btDirPress[joy].tick1 == (BUTTON_RIGHT) || (btDirPress[joy].tick2 == (BUTTON_RIGHT)))){
        CBF[joy].commandCheck =3;
        CBF[joy].timer = 9;
    }
}

static void cdu_check(u16 joy){
    if (CDU[joy].timer > 0)
    {
        if(CDU[joy].commandCheck != 1){
            CDU[joy].timer--;
        }
    }else{
        CDU[joy].commandCheck = 0;
    }

    if((CDU[joy].commandCheck==0) && ((btDirPress[joy].tick1 & BUTTON_DOWN) || ((btDirPress[joy].tick2 & BUTTON_DOWN)))){ //frente
        CDU[joy].commandCheck =1;
        CDU[joy].timer = 9;
    }else if(CDU[joy].commandCheck == 1){ //os dois ticks frente
        if ((btDirPress[joy].tick1 & BUTTON_DOWN) && ((btDirPress[joy].tick2 & BUTTON_DOWN)))
        {
            if (CDU[joy].timer < 9)
            {
                CDU[joy].timer = 10;
            }else{
                CDU[joy].timer++;
            }
        }else if (CDU[joy].timer > 69){
            CDU[joy].commandCheck = 2;
            CDU[joy].timer = 9;
        }else{
            CDU[joy].timer = 0;
        }
    }else if((CDU[joy].commandCheck == 2) && (btDirPress[joy].tick1 == (BUTTON_UP) || (btDirPress[joy].tick2 == (BUTTON_UP)))){
        CDU[joy].commandCheck =3;
        CDU[joy].timer = 9;
    }
}

static void cfb_check(u16 joy){
    if (CFB[joy].timer > 0)
    {
        if(CFB[joy].commandCheck != 1){
            CFB[joy].timer--;
        }
    }else{
        CFB[joy].commandCheck = 0;
    }

    if((CFB[joy].commandCheck==0) && ((btDirPress[joy].tick1 & BUTTON_RIGHT) || ((btDirPress[joy].tick2 & BUTTON_RIGHT)))){ //frente
        CFB[joy].commandCheck =1;
        CFB[joy].timer = 9;
    }else if(CFB[joy].commandCheck == 1){ //os dois ticks frente
        if ((btDirPress[joy].tick1 & BUTTON_RIGHT) && ((btDirPress[joy].tick2 & BUTTON_RIGHT)))
        {
            if (CFB[joy].timer < 9)
            {
                CFB[joy].timer = 10;
            }else{
                CFB[joy].timer++;
            }
        }else if (CFB[joy].timer > 69){
            CFB[joy].commandCheck = 2;
            CFB[joy].timer = 9;
        }else{
            CFB[joy].timer = 0;
        }
    }else if((CFB[joy].commandCheck == 2) && (btDirPress[joy].tick1 == (BUTTON_LEFT) || (btDirPress[joy].tick2 == (BUTTON_LEFT)))){
        CFB[joy].commandCheck =3;
        CFB[joy].timer = 9;
    }
}

