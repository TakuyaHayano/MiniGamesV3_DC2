#pragma once
#include "../MAIN/GAME_BASE.h"
namespace GAME00
{
    class GAME :
        public GAME_BASE
    {
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void destroy();
    private:
        enum STATE { TITLE, PLAY,PLAY2,PLAY3, CLEAR, OVER };
        STATE State = TITLE;
        void Title();
        void proc();
        void Init();
        void Play();
        void Play2();
        void Play3();
        int Nikucollision();
        int Daifukucollision();
        int Purincollision();
        int Onigiricollision();
        int Kusuricollision();
        int Kusuri2collision();
        int Kusuri3collision();
        int Kusuri4collision();
        void Draw();
        void Draw2();
        void Draw3();
        void HpGauge();
        void Clear();

        bool CleatFlag = false;

        int purinImg = 0;
        int onigiriImg = 0;
        int nikuImg = 0;
        int daifukuImg = 0;
        int monsterImg = 0;
        int hakaImg = 0;
        int kusuriImg = 0;
        int syokujiSnd = 0;
        int sibouSnd = 0;
        int bgmSnd = 0;

        int daidokoroImg = 0;

        int Score = 0;
        int dame = 0;

        float HpMax = 0;
        
        float monsterHP = 0;
        
        float monsterX = 0;
        float monsterY = 0;
        float monsterW = 0;
        float monsterH = 0;

        float DaifukuX = 0;
        float DaifukuY = 0;
        float DaifukuW = 0;
        float DaifukuH = 0;

        float OnigiriX = 0;
        float OnigiriY = 0;
        float OnigiriW = 0;
        float OnigiriH = 0;

        float NikuX = 0;
        float NikuY = 0;
        float NikuW = 0;
        float NikuH = 0;

        float PurinX = 0;
        float PurinY = 0;
        float PurinW = 0;
        float PurinH = 0;

        float kusuriX = 0;
        float kusuriY = 0;
        float kusuriW = 0;
        float kusuriH = 0;

        float kusuri2X = 0;
        float kusuri2Y = 0;
        float kusuri2W = 0;
        float kusuri2H = 0;

        float kusuri3X = 0;
        float kusuri3Y = 0;
        float kusuri3W = 0;
        float kusuri3H = 0;

        float kusuri4X = 0;
        float kusuri4Y = 0;
        float kusuri4W = 0;
        float kusuri4H = 0;

        float hakaX = 0;
        float hakaY = 0;

        float angle = 0;
        float scale = 1;
    };
    

}
