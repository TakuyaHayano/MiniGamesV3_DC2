#pragma once
#include "../MAIN/GAME_BASE.h"
namespace GAME08
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
        void title();
        void play();
        void result();
        void init();
        void draw();

    private:
        enum {
            TITLE,
            PLAY,
            RESULT
        };
        int hp;

        int TitleBackImg, TitleImg,TitleItemImg, ConfigBackImg , ConfigsImg;

        int FPinkImg;

        bool IsConfig = false;

        int PlayBackImg , KumoPinkImg , KumoBlueImg, KumoPurpleImg;

        int SImg, AImg, BImg, CImg;

        int GClearImg , GOverImg;

        int ClearBackImg, OverBackImg;

        struct CHARACTER {
            int Character;
            int Img[2];
            float Px, Py, Speed;
            int Life;
        };

        struct OBJECT {
            int Object;
            int Img[6];
            float Px, Py, Angle, FallSpeed;
            int Hp;
        };


        struct SQUARE {
            float x, y, w, h, Speed;
            float left, right, top, bottom;
        };

        struct SCORE {
            int Score;
        };

        struct OBJECTS {
            int Objects;
            int Squares;
        };

        float LE = 793.0;
        float RE = 1126.5;

        int STATE = TITLE;

        struct CHARACTER Player;
        struct OBJECT Item;

        struct SQUARE ap;
        struct SQUARE bc;

        struct SCORE Ps;
        struct SCORE Is;

        struct OBJECTS Items[3];



    };
}
