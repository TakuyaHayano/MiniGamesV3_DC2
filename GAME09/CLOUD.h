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
        FRUITS::FRUITS_KINDS CurKind;
        VECTOR2 FruitsPos;
    public:
        CLOUD(class GAME* game);
        ~CLOUD();
        void create();
        void init();
        void update();
        void draw();
    };
}
