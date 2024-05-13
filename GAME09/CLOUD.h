#pragma once
#include "GAME_OBJECT.h"
#include "FRUITS.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09
{
    class CLOUD :
        public GAME_OBJECT
    {
    public:
        enum STATE {
            MOVE,
            FALL
        };
        struct DATA {
            VECTOR2 fruitsInitPos;
            float   fruitsImgSize;
            VECTOR2 cloudPosOfst;
            int     cloudImg;
            float   cloudImgSize;
            float   left;
            float   right;
            float   moveSpeed;
        };
    private:
        DATA Cloud;
        class FRUITS* Fruits;
        VECTOR2 FruitsPos;
        STATE State;

        void CreateFruits();
    public:
        CLOUD(class GAME* game);
        ~CLOUD();
        void create();
        void init();
        void update();
        void draw();

        void setMove();
    };
}
