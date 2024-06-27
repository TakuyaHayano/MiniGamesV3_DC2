#pragma once
#include "GAME_OBJECT.h"
#define NUM 28
#define N_LONG 12
#define CHOICE 48
class PLAY :
    public GAME_OBJECT
{
public:
    struct DATA {
        int img[NUM];
        VECTOR2 pos;
        char name[NUM][N_LONG];
        float angle;
        float limitH;
        float scale;
        VECTOR2 t_pos;
        COLOR textColor;
        int textSize;
        char str[CHOICE];
        VECTOR2 r_pos;
        COLOR rectColor;
        float range;
        float elevation;
        float decSpeed;
    };
private:
    DATA Play;
public:
    PLAY(class GAME_M* game);
    void create();
    void init();
    void update();
    void draw();
};