#pragma once
#include "BUTTON.h"

namespace GAME09
{
    class BUTTON_CONTINUE :
        public BUTTON
    {
    public:
        BUTTON_CONTINUE(class GAME* game);
        ~BUTTON_CONTINUE();
        void create();
    };
}