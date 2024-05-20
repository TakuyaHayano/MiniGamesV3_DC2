#pragma once
#include "GAME_OBJECT.h"
#include "FRUITS.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09
{
    class SCORE :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            int strImg;
            VECTOR2 strOfst;
            float bubbleSize;
            VECTOR2 bubblePos;
            int fruitsScores[FRUITS::NUM_FRUITS_KINDS];
        };
    private:
        DATA Score;
        class BUBBLE* Bubble;
        int CurScore;
    public:
        SCORE(class GAME* game);
        ~SCORE();
        void create();
        void init();
        void update();
        void draw();

        void addScore(FRUITS::FRUITS_KINDS kinds);
    };
}
