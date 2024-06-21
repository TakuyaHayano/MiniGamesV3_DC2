#pragma once
#include "SCENE.h"
#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09
{
    class RESULT :
        public SCENE
    {
    public:
        enum BUTTON_KINDS {
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
            int resultImg;
            int resultScoreImg;
            int resultHiScoreImg;
            VECTOR2 imgPos;
            float imgSize;
            VECTOR2 hiScoreImgPos;
            float hiScoreImgSize;
            VECTOR2 finalFieldPos;
            float finalFieldSize;
            VECTOR2 scorePos;
            float scoreSize;
            VECTOR2 hiScorePos;
            float hiScoreSize;
            STATE_MOVE_DATA moveDatas[NUM_STATE];

            int operationImg;
            VECTOR2 operationImgPos;
            float operationImgSize;
        };
    private:
        DATA Result;
        class BUTTON* Buttons[NUM_BUTTONS];
        BUTTON_KINDS SelectButton;
        STATE State;
        float AnimeTime;
        float OfstY;
    public:
        RESULT(class GAME* game);
        ~RESULT();
        void create();
        void init();
        void update();
        void draw();
        void nextScene();
    };
}