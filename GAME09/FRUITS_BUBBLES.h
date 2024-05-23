#pragma once
#include "GAME_OBJECT.h"
#include "FRUITS.h"
#include "../../libOne/inc/VECTOR2.h"
#include <vector>

namespace GAME09
{
    class FRUITS_BUBBLES :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            std::vector<FRUITS::FRUITS_KINDS> order;
            float lenX;
            float lenY;
            float initDist;
            float speed;
        };
    private:
        DATA FruitsBubbles;
        class FRUITS_BUBBLE* Bubbles[FRUITS::NUM_FRUITS_KINDS];
        float MoveDist;
        std::vector<float> arcLengths;
        float totalArcLength = 0;
        const float totalSteps = 10000; // ï™äÑÇÃç◊Ç©Ç≥
    public:
        FRUITS_BUBBLES(class GAME* game);
        ~FRUITS_BUBBLES();
        void create();
        void init();
        void update();
        void draw();
    };
}
