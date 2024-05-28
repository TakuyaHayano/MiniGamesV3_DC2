#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09
{
    class CURTAIN :
        public GAME_OBJECT
    {
    public:
        enum STATE {
            START,
            STAY,
            END,
            NUM_STATE
        };
        struct DATA {
            int imgR;
            int imgL;
            int imgClose;
            VECTOR2 imgPos;
            VECTOR2 openOfst;
            float imgSize;
            float moveTimes[NUM_STATE];
        };
    private:
        DATA Curtain;
        STATE State;
        float AnimeTime;
    public:
        CURTAIN(class GAME* game);
        ~CURTAIN();
        void create();
        void init();
        void update();
        void draw();
    };
}
