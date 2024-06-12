#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"
#include <vector>

namespace GAME09
{
    class READYGO :
        public GAME_OBJECT
    {
    public:
        struct MOVE_DATA {
            float animeTime = 0;
            VECTOR2 startPos;
            VECTOR2 endPos;
            float startAlpha = 255;
            float endAlpha = 255;
            float startSize = 1;
            float endSize = 1;
        };
        struct ANIMATION {
            float time = 0;
            int state = 0;
            std::vector<MOVE_DATA> data;
        };
        struct DATA {
            int imgReady;
            int imgGo;
            VECTOR2 imgPos;
            float imgSize;
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
