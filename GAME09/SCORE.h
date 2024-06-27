#pragma once
#include "GAME_OBJECT.h"
#include "FRUITS.h"
#include "../../libOne/inc/VECTOR2.h"
#include <string>

namespace GAME09
{
    class SCORE :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            int strImg;
            VECTOR2 strOfst;
            int hiScoreStrImg;
            VECTOR2 hiScoreStrOfst;
            float bubbleSize;
            VECTOR2 bubblePos;
            int fruitsScores[FRUITS::NUM_FRUITS_KINDS];
            VECTOR2 scoreOfst;
            float scoreSize;
            VECTOR2 hiScoreOfst;
            float hiScoreSize;
            std::string fileName;
        };
    private:
        DATA Score;
        class BUBBLE* Bubble;
        int CurScore;
        int HiScore;

    public:
        SCORE(class GAME* game);
        ~SCORE();
        void create();
        void init();
        void update();
        void draw();

        void addScore(FRUITS::FRUITS_KINDS kinds);
        int getCurScore() { return CurScore; }
        int getHiScore() { return HiScore; }

        void loadHiScore();
        void setHiScore();
    };
}
