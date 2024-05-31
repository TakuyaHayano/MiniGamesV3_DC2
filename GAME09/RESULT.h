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
            BACK,
            NUM_BUTTONS
        };
        struct DATA {
            int resultImg;
            VECTOR2 imgPos;
            float imgSize;
            VECTOR2 finalFieldPos;
            float finalFieldSize;
            VECTOR2 scorePos;
            float scoreSize;
        };
    private:
        DATA Result;
        class BUTTON* Buttons[NUM_BUTTONS];
        BUTTON_KINDS SelectButton;
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