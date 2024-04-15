#pragma once
#include "BUTTON.h"

namespace GAME09
{
    class BUTTON_END :
        public BUTTON
    {
    public:
        BUTTON_END(class GAME* game);
        ~BUTTON_END();
        void create();
    };
}