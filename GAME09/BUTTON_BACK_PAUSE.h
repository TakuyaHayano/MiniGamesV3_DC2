#pragma once
#include "BUTTON.h"

namespace GAME09
{
    class BUTTON_BACK_PAUSE :
        public BUTTON
    {
    public:
        BUTTON_BACK_PAUSE(class GAME* game);
        ~BUTTON_BACK_PAUSE();
        void create();
    };
}