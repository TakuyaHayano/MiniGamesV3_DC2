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
            float selectAnimeTime = 0.15f;
            float selectAnimeOfstY = -30;
        };
    protected:
        DATA Button;
        bool Select = false;
        float AnimeTime;
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