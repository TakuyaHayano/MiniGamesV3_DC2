#pragma once
#include "../../libOne/inc/libOne.h"
#include "GAME_M.h"
#include "SCENE.h"
class TITLE :
    public SCENE
{
public:
    //�e�L�X�g��\�����邽�߂̍\����
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
    void create();    //�f�[�^�����ꏊ
    void draw();    //�p��
    void nextScene();    //�p��
};