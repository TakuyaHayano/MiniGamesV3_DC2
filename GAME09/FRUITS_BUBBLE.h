#pragma once
#include "GAME_OBJECT.h"
#include "FRUITS.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09
{
    class FRUITS_BUBBLE :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            int* imgs;
            float cherryImgSize;
            float nextFruitsSizeRate;
            float maxImgSize;

            float bubbleSize;
            VECTOR2 bubblePos;

            float maxMoveDist;
            float maxMoveTime;
            float minMoveTime;
            float maxSize;
            float minSize;
        };
    private:
        DATA FruitsBubble;
        class BUBBLE* Bubble;
        FRUITS::FRUITS_KINDS Kinds;
        float ImgSize;
        float Size;

        float AnimeTime;
        float MoveTime;
        VECTOR2 Pos;
        VECTOR2 BeforeOfst;
        VECTOR2 CurOfst;
        VECTOR2 AfterOfst;

        void SetRandMove();
    public:
        FRUITS_BUBBLE(class GAME* game);
        ~FRUITS_BUBBLE();
        void create();
        void init();
        void update();
        void draw();

        void setKinds(FRUITS::FRUITS_KINDS kinds) { Kinds = kinds; }
        void setPos(VECTOR2 pos) { Pos = pos; }
    };
}
