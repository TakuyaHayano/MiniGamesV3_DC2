#pragma once
#include "SCENE.h"
namespace GAME14 {
    class STAGE :
        public SCENE{
    public:
        struct DATA {
            const char* str1P;
            const char* str2P;
            COLOR strColor;
            VECTOR2 str1Pos;
            VECTOR2 str2Pos;
            float str1Size;
            float str2Size;

            int img;
            float imgSize;
            VECTOR2 imgPos;
            COLOR textColor;
            float textSize;
            VECTOR2 salmonText;

            COLOR undercoatColor;
            VECTOR2 undercoatPos;
            VECTOR2 undercoatSize;

        };
    private:
        DATA Stage;
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

