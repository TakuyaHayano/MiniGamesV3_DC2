#pragma once
#include "GAME_OBJECT.h"
#include"../../libOne/inc/COLOR.h"
#include"../../libOne/inc/VECTOR2.h"
namespace GAME14 {
    class CHARACTER :
        public GAME_OBJECT{
    public:
        struct DATA {
            COLOR color;
            char charaId;
            VECTOR2 worldPos;
            VECTOR2 vec;
            float speed;
            
            int hp = 0;
            //“–‚½‚è”»’è—p
            float offsetLeft;
            float offsetTop;
            float offsetRight;
            float offsetBottom;
        };
    protected:
        DATA Chara;
    public:
        CHARACTER(class GAME* game);
        virtual void create();
        virtual void init();
        virtual void appear(float wx,float wy);
        virtual void update();
        virtual void draw();
        char charaId() { return Chara.charaId; }
        int hp() { return Chara.hp; }
    };
}

