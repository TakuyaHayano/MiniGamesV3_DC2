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
            int useFruitsNum;
            int useFruitsNumSecret;
        };
    private:
        DATA Next;
        class BUBBLE* Bubble;
        class FRUITS* Fruits;
        int UseFruitsNum;

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
