#pragma once
#include "BUTTON.h"

namespace GAME09
{
    class BUTTON_HELP :
        public BUTTON
    {
    public:
        BUTTON_HELP(class GAME* game);
        ~BUTTON_HELP();
        void create();
    };
}