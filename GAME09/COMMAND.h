#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"
#include "../../libOne/inc/input.h"
#include <vector>

namespace GAME09
{
    class COMMAND :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            std::vector<INPUT_CODE> command;
        };
    private:
        DATA Command;
        int CommandLen;
        std::vector<INPUT_CODE> Inputs;
        bool Complete;
    public:
        COMMAND(class GAME* game);
        ~COMMAND();
        void create();
        void init();
        void update();
        void draw();

        bool complete() { return Complete; }
    };
}
