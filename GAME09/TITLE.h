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
        struct DATA {
            int titleImg;
        };
    private:
        DATA Title;
    public:
        TITLE(class GAME* game);
        ~TITLE();
        void create();
        void draw();
        void nextScene();
    };
}