#pragma once
#include "SCENE.h"
#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09
{
    class TITLE :
        public SCENE
    {
    public:
        enum BUTTON_KINDS {
            START,
            HELP,
            END,
            NUM_BUTTONS
        };
        struct DATA {
            int titleImg;
            VECTOR2 titlePos;
            float imgSize;
            float hueSpeed;
        };
    private:
        DATA Title;
        class BUTTON* Buttons[NUM_BUTTONS];
        BUTTON_KINDS SelectButton;
        bool SecretMode;
        float Hue;
    public:
        TITLE(class GAME* game);
        ~TITLE();
        void create();
        void init();
        void update();
        void draw();
        void nextScene();

        bool secretMode() { return SecretMode; }
    };
}