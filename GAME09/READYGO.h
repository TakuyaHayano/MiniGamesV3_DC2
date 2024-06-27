#pragma once
#include "GAME_OBJECT.h"
#include "ANIM.h"
#include "../../libOne/inc/VECTOR2.h"
#include <vector>

namespace GAME09
{
    class READYGO :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            int imgReady;
            int imgGo;
            ANIM readyAnim;
            ANIM goAnim;
            ANIM effectAnim;
        };
    private:
        DATA ReadyGo;
    public:
        READYGO(class GAME* game);
        ~READYGO();
        void create();
        void init();
        void update();
        void draw();
    };
}
