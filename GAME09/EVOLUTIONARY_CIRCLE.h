#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09
{
    class EVOLUTIONARY_CIRCLE :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            int img;
            float imgSize;
            VECTOR2 pos;
        };
    private:
        DATA ECircle;
    public:
        EVOLUTIONARY_CIRCLE(class GAME* game);
        ~EVOLUTIONARY_CIRCLE();
        void create();
        void update();
        void draw();
    };
}
