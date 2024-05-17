#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09
{
    class BUBBLE :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            int img;
            VECTOR2 pos;
            float   imgSize;
            VECTOR2 maxMoveOfst;
            float   animeTime;
        };
    private:
        DATA Bubble;
        VECTOR2 OPos;
        VECTOR2 CPos;
        float AnimeTime;
        float Size;
    public:
        BUBBLE(class GAME* game);
        ~BUBBLE();
        void create();
        void init();
        void update();
        void draw();

        void setPos(VECTOR2 pos);
        void setSize(float size) { Size = size; }
        VECTOR2 getPos() { return CPos; }
    };
}
