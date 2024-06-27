#pragma once
#include "BUTTON.h"

namespace GAME09
{
    class BUTTON_BACK_RESULT :
        public BUTTON
    {
    public:
        BUTTON_BACK_RESULT(class GAME* game);
        ~BUTTON_BACK_RESULT();
        void create();
    };
}