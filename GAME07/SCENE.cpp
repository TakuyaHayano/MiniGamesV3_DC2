//�S�ẴV�[���̊��N���X
#include "SCENE.h"
//���N���X�̃R���X�g���N�^�̌Ăяo����
SCENE::SCENE(class GAME_M* game):    //���N���X�̃R���X�g���N�^���Ăяo���ď���������
    GAME_OBJECT(game){
}
SCENE:: ~SCENE(){}
void SCENE::create(){}
void SCENE::init(){}
void SCENE::proc(){
    update();
    draw();
    nextScene();
}
void SCENE::update(){}
void SCENE::draw(){}
void SCENE::nextScene(){}