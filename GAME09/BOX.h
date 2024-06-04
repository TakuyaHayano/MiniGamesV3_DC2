#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09
{
    class BOX :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            int img;
            int frontImg;
            VECTOR2 pos;
            float imgSize;
            float left;
            float right;
            float under;
            float up;
        };
    private:
        DATA Box;
    public:
        BOX(class GAME* game);
        ~BOX();
        void create();
        void init();
        void update();
        void draw();
        void drawFront();

        float left();
        float right();
        float under();
        float up();
    };
}
