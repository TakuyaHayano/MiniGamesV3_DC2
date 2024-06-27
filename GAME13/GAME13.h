#pragma once
#include "../MAIN/GAME_BASE.h"
namespace GAME13
{
    class GAME :
        public GAME_BASE
    {
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void proc();
        void destroy();
          
    private:
        //ÉVÅ[ÉìëJà⁄
        enum STATE { TITLE, PLAY, CLEAR};
        STATE State = TITLE;
        void Title();
        void Init();
        void Play();
        void Clear();
        int Img = 0;
          
    };
}
