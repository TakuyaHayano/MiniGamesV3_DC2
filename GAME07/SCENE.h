#pragma once
#include "GAME_OBJECT.h"    //SCENEもGAMEクラスのポインタを持っているということになる
class SCENE :
    public GAME_OBJECT
{
public:
    SCENE(class GAME_M* game);
    virtual ~SCENE();
    virtual void create();    //画像の番号を設定する関数
    virtual void init();
    virtual void proc();    //処理の意味、これを何回も呼び出して処理していく
    virtual void update();
    virtual void draw();
    virtual void nextScene();    //シーンを変える関数
};