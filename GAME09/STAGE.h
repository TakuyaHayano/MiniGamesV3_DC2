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
        struct DATA {
            int a;
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