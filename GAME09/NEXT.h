#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09
{
    class NEXT :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            int strImg;
            VECTOR2 strOfst;
            float bubbleSize;
            VECTOR2 bubblePos;
        };
    private:
        DATA Next;
        class BUBBLE* Bubble;
        class FRUITS* Fruits;

        void CreateFruits();
    public:
        NEXT(class GAME* game);
        ~NEXT();
        void create();
        void init();
        void update();
        void draw();

        class FRUITS* getNextFruits();
    };
}
