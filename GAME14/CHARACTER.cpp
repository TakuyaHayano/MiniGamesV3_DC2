#include "CHARACTER.h"
namespace GAME14 {
    CHARACTER::CHARACTER(class GAME* game):
        GAME_OBJECT(game){}
    void CHARACTER::create(){}
    void CHARACTER::init(){
        Chara.hp = 0;
    }
    void CHARACTER::appear(float wx,float wy){
        Chara.worldPos.x = wx;
        Chara.worldPos.y = wy;
        Chara.hp = 1;
    }
    void CHARACTER::update(){
        
    }
    void CHARACTER::draw(){
    }

}