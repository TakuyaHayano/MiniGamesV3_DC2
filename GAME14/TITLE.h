#pragma once
#include "SCENE.h"
namespace GAME14 {
    class TITLE :
        public SCENE{
    public:
        struct DATA {
            COLOR backColor;

            int bgm;
            bool bgmFlag = false;
            const char* titleName1;
            const char* titleName2;
            const char* stateChangeMs;
            const char* controlText1;
            const char* controlText2;
            const char* bgmName;
            const char* featName;
            float titleNameSize;
            float stateChangeMsSize;
            float controlTextSize;
            float bgmNameSize;
            COLOR titleNameColor;
            COLOR stateChangeMsColor;
            COLOR controlTextColor;
            COLOR bgmNameColor;
            COLOR undercortClor;
            VECTOR2 titleName1Pos;
            VECTOR2 titleName2Pos;
            VECTOR2 stateChangeMsPos;
            VECTOR2 controlText1Pos;
            VECTOR2 controlText2Pos;
            VECTOR2 bgmNamePos;
            VECTOR2 undercortPos;
            VECTOR2 undercortSize;

        };
    private:
        DATA Title;
    public:
        TITLE(class GAME* game);
        ~TITLE();
        void create();
        void init();
        void update();
        void draw();
        void nextScene();
    };
}

