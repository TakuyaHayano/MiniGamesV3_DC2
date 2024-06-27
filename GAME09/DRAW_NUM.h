#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09
{
    class DRAW_NUM :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            int numImg;
            int numImgs[10];
            float numSize;
            float digitSpace;
        };
    private:
        DATA DrawNum;
    public:
        DRAW_NUM(class GAME* game);
        ~DRAW_NUM();
        void create();
        void init();
        void update();
        void draw(int num, VECTOR2 pos, float ratio = 1.0f);
    };
}
