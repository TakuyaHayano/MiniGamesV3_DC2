#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09
{
    class TRANSITION :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            float inTime;
            float outTime;
        };
        enum STATE {
            OUT_NOW,OUT_END,IN_NOW,IN_END
        };
    private:
        DATA Transition;
        float Time;
        STATE State;
    public:
        TRANSITION(class GAME* game);
        ~TRANSITION();
        void create();
        void update();
        void draw();

        void start();
        bool inEndFlag();
        bool outEndFlag();
    };
}