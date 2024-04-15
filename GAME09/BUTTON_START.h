#pragma once
#include "BUTTON.h"

namespace GAME09
{
    class BUTTON_START :
        public BUTTON
    {
    public:
        BUTTON_START(class GAME* game);
        ~BUTTON_START();
        void create();
    };
}