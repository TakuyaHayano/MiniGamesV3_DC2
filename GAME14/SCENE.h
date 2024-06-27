#pragma once
#include "GAME_OBJECT.h"
#include"../../libOne/inc/COLOR.h"
#include"../../libOne/inc/VECTOR2.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
namespace GAME14 {
    class SCENE :
        public GAME_OBJECT
    {
    public:
        SCENE(class GAME* game);
        virtual ~SCENE();
        virtual void create();
        virtual void init();
        virtual void proc();
        virtual void update();
        virtual void draw();
        virtual void nextScene();

    };
}

