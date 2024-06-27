#pragma once
#include "../../libOne/inc/libOne.h"
#include "GAME_M.h"
#include "SCENE.h"
class TITLE :
    public SCENE
{
public:
    //テキストを表示するための構造体
    struct DATA {
        COLOR backColor;
        COLOR textColor;
        float textSize0;
        float textSize1;
        VECTOR2 pos[2];
        char str0[16];
        char str1[56];
    };
private:
    DATA Title;
public:
    TITLE(class GAME_M* game);
    ~TITLE();
    void create();    //データを作る場所
    void draw();    //継承
    void nextScene();    //継承
};