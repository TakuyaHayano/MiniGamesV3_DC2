#pragma once
#include "GAME_OBJECT.h"    //SCENE��GAME�N���X�̃|�C���^�������Ă���Ƃ������ƂɂȂ�
class SCENE :
    public GAME_OBJECT
{
public:
    SCENE(class GAME_M* game);
    virtual ~SCENE();
    virtual void create();    //�摜�̔ԍ���ݒ肷��֐�
    virtual void init();
    virtual void proc();    //�����̈Ӗ��A�����������Ăяo���ď������Ă���
    virtual void update();
    virtual void draw();
    virtual void nextScene();    //�V�[����ς���֐�
};