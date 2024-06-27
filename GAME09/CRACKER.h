#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"
#include "../../libOne/inc/COLOR.h"
#include <vector>

namespace GAME09
{
    class CRACKER :
        public GAME_OBJECT
    {
    public:
        struct PAPER {
            VECTOR2 pPos;
            COLOR color;
            float angle = 0;
        };
        enum COLORS {
            SKY,
            PURPLE,
            RED,
            GREEN,
            YELLOW,
            NUM_COLORS
        };
        struct DATA {
            VECTOR2 pos;
            float startWidth;
            VECTOR2 size;
            float speed;
            COLOR colors[NUM_COLORS];
            float interval;
            float angSpeed;
        };
    private:
        DATA Cracker;
        std::vector<struct PAPER> Papers;
        float Time;

    public:
        CRACKER(class GAME* game);
        ~CRACKER();
        void create();
        void init();
        void update();
        void draw();
        void appear();
    };
}
