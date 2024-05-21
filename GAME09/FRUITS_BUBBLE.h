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
        };
    private:
        DATA FruitsBubble;
        class BUBBLE* Bubble;
        FRUITS::FRUITS_KINDS Kinds;
        float ImgSize;
    public:
        FRUITS_BUBBLE(class GAME* game);
        ~FRUITS_BUBBLE();
        void create();
        void init();
        void update();
        void draw();

        void setKinds(FRUITS::FRUITS_KINDS kinds) { Kinds = kinds; }
    };
}
