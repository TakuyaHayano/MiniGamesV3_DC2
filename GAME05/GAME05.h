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
        enum STATE { TITLE, VOL, GACHA, PROB, MEAN, RESULT, RESULT2, RULE, PLAY, PLAY2, PLAY3, STAGE, LUCKY,LUCKYGAME, CLEAR, ALLCLEAR, LGCLEAR, LGCLEAR2, LGCLEAR3, FINISH, OVER };
        STATE State = TITLE;
        void Title();
        void Vol();
        void Gacha();
        void Prob();
        void Mean();
        void Result();
        void Result2();
        void Rule();
        void Play();
        void Play2();
        void Play3();
        void Init();
        void Init2();
        void Init3();
        void Init4();
        void Lucky();
        void LuckyGame();
        void Clear();
        void Allclear();
        void Lgclear();
        void Lgclear2();
        void Lgclear3();
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
        int adjustment = true;
        bool loopBgm = true;
        bool BHitFlag = false;

        int KizaruImg = 0;
        int EnelImg = 0;
        int LuffyImg = 0;
        int PunchImg = 0;
        int HitImg = 0;
        int BackImg = 0;
        int img = 0;
        int TamaImg = 0;
        int Tama2Img = 0;
        int TitleImg = 0;
        int BlockImg = 0;
        int GachaImg = 0;

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
        int ClickSnd = 0;
        int TitleSnd = 0;
        int LastSnd = 0;
        int ToppaSnd = 0;
        int WinSnd = 0;
        int OpenSnd = 0;
        int AtariSnd = 0;
        int HitSnd = 0;
        int ChoiceSnd = 0;
        int UseSnd = 0;

        float Point = 0;

        int StageCount = 0;

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

        float ClearPoint = 0;

        float ClearPoint2 = 0;

        float ClearPoint3 = 0;

        int CountDown = 0;

        int CountDown2 = 0;

        int CountDown3 = 0;

        int CountDown4 = 0;

        int FreamCount = 0;

        float LuckyNo = 0;

        int numBullets = 0;

        float PPx = 0, PPy = 0;
        float PVx = 0, PVy = 0;
        float PMx = 0, PMy = 0;
        float PhalfW = 0, PhalfH = 0;
        float PHp = 0;

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

        float BPx = 0, BPy = 0;
        float BhalfW = 0, BhalfH = 0;

        float HP = 0;
        float MaxHp = 0;
        float hpGaugeWidth = 0;

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

        float SpDire = 0;
        float Dire = 0;

        float volume1 = 70;
        float volume2 = 70;

        int cnt = 0;

        int num0 = 0;
        int num1 = 0;
        int num2 = 0;
        int num3 = 0;
        int num4 = 0;
        int num5 = 0;
        int num6 = 0;
        int num7 = 0;
        int num8 = 0;
        int num9 = 0;
        int num10 = 0;

        int gachaCnt = 0;

        int tamaCnt = 0;

        int LTcnt = 0;

        const char* star4[10] = {
            "’O‰H’·G",
            "¡ì‹`Œ³",
            "¼‰i‹vG",
            "Ö“¡“¹O",
            "óˆä’·­",
            "‘O“cŒcŸ",
            "ˆäˆÉ’¼•J",
            "ç —˜ ‹x",
            "“y•ûÎO",
            "‰«“c‘i"
        };
        
        const char* star5[9] = {
            "–{“c’‰Ÿ",
            "‘O“c—˜‰Æ",
            "–¾’qŒõG",
            "G‰ê‘·s",
            "“‡ ¶ ‹ß",
            "‰Á“¡´³",
            "‘å’J‹gŒp",
            "••””¼‘ ",
            "Š‹ü–kÖ"
        };

        const char* star6[7] = {
            "ˆÉ’B­@",
            "ã™ŒªM",
            "•“cMŒº",
            "^“cK‘º",
            "–Ñ—˜Œ³A",
            "X —– ŠÛ",
            "‹{–{•‘ "
        };

        const char* sstar6[6] = {
            "D“cM’·",
            "“¿ì‰ÆN",
            "–LbG‹g",
            "â–{—´”n",
            "¼‹½—²·",
            "¹“¿‘¾q"
        };

        int star4Total = 0;
        int star5Total = 0;
        int star6Total = 0;
        int sstar6Total = 0;

        int randomstar4num = 0;
        int randomstar5num = 0;
        int randomstar6num = 0;
        int randomsstar6num = 0;

        int randomstar4num1 = 0;
        int randomstar5num1 = 0;
        int randomstar6num1 = 0;
        int randomsstar6num1 = 0;

        int randomstar4num2 = 0;
        int randomstar5num2 = 0;
        int randomstar6num2 = 0;
        int randomsstar6num2 = 0;

        int randomstar4num3 = 0;
        int randomstar5num3 = 0;
        int randomstar6num3 = 0;
        int randomsstar6num3 = 0;

        int randomstar4num4 = 0;
        int randomstar5num4 = 0;
        int randomstar6num4 = 0;
        int randomsstar6num4 = 0;

        int randomstar4num5 = 0;
        int randomstar5num5 = 0;
        int randomstar6num5 = 0;
        int randomsstar6num5 = 0;

        int randomstar4num6 = 0;
        int randomstar5num6 = 0;
        int randomstar6num6 = 0;
        int randomsstar6num6 = 0;

        int randomstar4num7 = 0;
        int randomstar5num7 = 0;
        int randomstar6num7 = 0;
        int randomsstar6num7 = 0;

        int randomstar4num8 = 0;
        int randomstar5num8 = 0;
        int randomstar6num8 = 0;
        int randomsstar6num8 = 0;

        int randomstar4num9 = 0;
        int randomstar5num9 = 0;
        int randomstar6num9 = 0;
        int randomsstar6num9 = 0;

        int randomstar4num10 = 0;
        int randomstar5num10 = 0;
        int randomstar6num10 = 0;
        int randomsstar6num10 = 0;
    };
}