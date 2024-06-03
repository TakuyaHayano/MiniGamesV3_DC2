#pragma once
#include "SCENE.h"
#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09
{
    class STAGE :
        public SCENE
    {
    public:
        enum STATE {
            PLAY,
            VIBE,
            WAIT
        };
        struct DATA {
            float vibeTime;
            float waitTime;
        };
    private:
        DATA Stage;
        STATE State;
        float AnimeTime = 0;
    public:
        STAGE(class GAME* game);
        ~STAGE();
        void create();
        void init();
        void update();
        void draw();
        void nextScene();
    };
}