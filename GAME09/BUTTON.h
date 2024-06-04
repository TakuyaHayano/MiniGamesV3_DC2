#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09
{
    class BUTTON :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            int notSelectedImg;
            int selectedImg;
            float imgSize = 1;
            VECTOR2 pos;
            float selectAnimeTime = 0.1f;
            float selectAnimeOfstY = 10;
            float startTime = 0;
            float standbyAnimeCycleTime = 1.1f;
            float standbyAnimeTime = 0.6f;
            float standbyAnimeOfstY = 8;
            bool initStandbyMotion = false;
            bool initSelectMotion = false;
        };
    protected:
        DATA Button;
        bool Select = false;
        float Time;
        float AnimeTime;
        bool StandbyMotion;
        bool SelectMotion;
    public:
        BUTTON(class GAME* game);
        ~BUTTON();
        virtual void create();
        virtual void init();
        virtual void update();
        virtual void draw();
        virtual void setSelect(bool select, bool anime = true);
    };
}