#pragma once
#include "../MAIN/GAME_BASE.h"
namespace GAME05
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
        enum STATE { TITLE, RULE, PLAY, STAGE, LUCKY,LUCKYGAME, CLEAR, BCLEAR, FINISH, OVER };
        STATE State = TITLE;
        void Title();
        void Init();
        void Init2();
        void Rule();
        void Play();
        void Lucky();
        void LuckyGame();
        void Clear();
        void BClear();
        void Finish();
        void Over();
        int collision();
        int collision2();
        int collision3();
        void hpGauge();
        void hpGauge2();
        void draw();
        void draw2();

        bool PointFlag = false;
        bool EHitFlag = false;
        bool PHitFlag = false;

        int KizaruImg = 0;
        int EnelImg = 0;
        int LuffyImg = 0;
        int PunchImg = 0;
        int HitImg = 0;
        int BackImg = 0;
        int img = 0;
        int TamaImg = 0;

        int GetSnd = 0;
        int PunchSnd = 0;
        int ClearSnd = 0;
        int BgmSnd = 0;
        int OverSnd = 0;
        int LuckySnd = 0;
        int LGClearSnd = 0;
        int LgSnd = 0;
        int FinishSnd = 0;
        int AttackSnd = 0;

        float Point = 0;

        float StageCount = 0;
        float MinStageCount = 0;

        float GPRx = 0;
        float GPRy = 0;
        float GPR = 0;

        float GPYx = 0;
        float GPYy = 0;
        float GPY = 0;

        float GPB = 0;
        float GPBx = 0;
        float GPBy = 0;

        float GPG = 0;
        float GPGx = 0;
        float GPGy = 0;

        float GPP = 0;
        float GPPx = 0;
        float GPPy = 0;

        float GPr = 0;
        float GPrx = 0;
        float GPry = 0;

        float ClearPoint = 0;

        float LuckyPoint = 0;

        float CountDown = 0;

        float LuckyNo = 0;

        int numBullets = 0;

        float PPx = 0, PPy = 0;
        float PVx = 0, PVy = 0;
        float PMx = 0, PMy = 0;
        float PhalfW = 0, PhalfH = 0;

        float EPx = 0, EPy = 0;
        float EVx = 0, EVy = 0;
        float EW = 0;
        float EMx = 0;
        float EhalfW = 0, EhalfH = 0;
        float EHp = 0, EHP = 0;
        float EMaxHp = 0;
        float EhpGaugeOfsY = 0;
        float EHpWarning = 0;
        float EHpDenger = 0;

        float EBPx = 0, EBPy = 0;
        float EBVy = 0;
        float EBW = 0, EBH = 0;
        float EBhalfW = 0, EBhalfH = 0;
        float EBHp = 0;
        float EBOfstY = 0;

        float HP = 0;
        float MaxHp = 0;

        float hpGaugeOfsY = 0;
        float HpWarning = 0;
        float HpDenger = 0;

        float Px = 0, Py = 0;
        float Vx = 0;
        float halfW = 0, halfH = 0;
        float Mx = 0;
        float OfstY = 0;

        float PBPx = 0, PBPy = 0;
        float PBVy = 0;
        float PBW = 0, PBH = 0;
        float PBhalfW = 0, PBhalfH = 0;
        float PBHp = 0;
        float PBOfstY = 0;

        float HpX = 0, HpY = 0;
        float EHpX = 0, EHpY = 0;
        /*
        float CircleRadius = 0;
        float CircleX = 0, CircleY = 0;
        float CircleVx = 0, CircleVy = 0;
        int ExplosionImg = 0;
        */
    };
}