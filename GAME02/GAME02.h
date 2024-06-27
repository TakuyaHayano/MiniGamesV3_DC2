#pragma once
#include "../MAIN/GAME_BASE.h"
namespace GAME02
{
    class GAME :
        public GAME_BASE
    {
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void init();
        void proc();
        void destroy();
        void shuffle();
        void draw();
        void keyprocessing();
        void peacemove();
        void clearCheck();
        void play();
        void title();
        void gameClear();

    private:
        enum STATE { TITLE, PLAY, CLEAR };
        STATE State = TITLE;

        int initflag = 0;
        int clearflag = 0;
        int BGMflag = 0;
        int png[16] = { 0 };
        int snd[3] = { 0 };
        int step = 0;
        int peaceSameP[16] = { 0 };
        float peaceSize = 0;

        struct FRAME {
            float Px = 0;
            float Py = 0;
        };

        struct PEACE {
            float Px = 0;
            float Py = 0;
        };

        struct SELECTFRAME {
            float Px = 0;
            float Py = 0;
        };
        FRAME frame[16];
        PEACE peace[16];
        SELECTFRAME selectframe;
    };
}