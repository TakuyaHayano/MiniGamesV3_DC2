//全てのシーンの基底クラス
#include "SCENE.h"
//基底クラスのコンストラクタの呼び出し方
SCENE::SCENE(class GAME_M* game):    //基底クラスのコンストラクタを呼び出して初期化する
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