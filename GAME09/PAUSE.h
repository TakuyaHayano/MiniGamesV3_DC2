#pragma once
#include "SCENE.h"
#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09
{
    class PAUSE :
        public SCENE
    {
    public:
        enum BUTTON_KINDS {
            CONTINUE,
            RETRY,
            RETURN,
            NUM_BUTTONS
        };
        enum STATE {
            START,
            BACK,
            NORMAL,
            NUM_STATE
        };
        struct STATE_MOVE_DATA {
            float animeTime;
            float startOfst;
            float endOfst;
        };
        struct DATA {
            int pauseImg;
            VECTOR2 imgPos;
            float imgSize;
            STATE_MOVE_DATA moveDatas[NUM_STATE];
        };
    private:
        DATA Pause;
        class BUTTON* Buttons[NUM_BUTTONS];
        BUTTON_KINDS SelectButton;
        STATE State;
        float AnimeTime;
        float OfstY;
    public:
        PAUSE(class GAME* game);
        ~PAUSE();
        void create();
        void init();
        void update();
        void draw();
        void nextScene();
    };
}