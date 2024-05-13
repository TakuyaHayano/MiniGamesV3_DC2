#pragma once
#include "../../libOne/inc/libOne.h"
#include "../MAIN/GAME_BASE.h"
namespace GAME10
{
    class GAME :
        public GAME_BASE
    {
    private:
        enum {
            TITLE,
            PLAY,
            RESULT
        };
        int STATE;
        const char* fileName;
        FILE* fp;
        int fileSize;
        char* map;
        //行列カウント用
        int row = 0;//行
        int col = 0;//列
        int cnt = 0;
        int WallCnt = 0;
        int GoalCnt = 0;
        int InvisibleWallCnt = 0;
        int EnemyCnt = 0;
        //壁関連
        int WallImg = 0;
        int WallLeftImg = 0;
        int WallRightImg = 0;
        int WallUpImg = 0;
        int WallUnderImg = 0;
        int WallUpLeftCornerImg = 0;
        int WallUnderLeftCornerImg = 0;
        int WallUpRightCornerImg = 0;
        int WallUnderRightCornerImg = 0;
        //当たり判定用
        struct HITBOX {
            VECTOR2 Wup;
            VECTOR2 Wunder;
            VECTOR2 Wleft;
            VECTOR2 Wright;
            VECTOR2 Wcore;
            //プレイヤーの壁
            VECTOR2 Pup;
            VECTOR2 Punder;
            VECTOR2 Pleft;
            VECTOR2 Pright;
            //各判定からの距離
            float UpDist;
            float UnderDist;
            float RightDist;
            float LeftDist;
            int PointFlag;
            enum {
                Up,
                Under,
                Left,
                Right
            };
        };
        struct Map {
            //画面関連
            int Xsize = 192;
            int XharfSize = Xsize / 2;
            int Ysize = 216;
            int YharfSize = Ysize / 2;
            int mIdx = 0;
            //マップの座標
            float px = 0;
            float py = 0;
            float worldX = 0;
            float worldY = 0;
        };
        struct wall {
            //壁関連のデータ
            float WaPx = 0;
            float WaPy = 0;
            int Xsize = 192;
            int XharfSize = Xsize / 2;
            int Ysize = 216;
            int YharfSize = Ysize / 2;
        };
        struct Item {
            VECTOR2 ItemCore;
            float Iradius = 20;
            float HIradius = Iradius / 2;
            int ItemKind;
        };
        //当たり判定関係
        HITBOX HitBox;
        //アイテム関連
        Item Gun;
        Item Key;
        //goal関連
        int goalImg = 0;
        struct character {
            float Cpx = 0;
            float Cpy = 0;
            float Mx = 5;
            float My = 5;
            //視界(敵のみが使用)
            float length = 300;
            float radius = 50;
            float Hradius = radius / 2;
            //敵の動きの種類
            char Mkind;
            //プレイヤーのみ使用する変数
            bool GunFlag = false;
            bool KeyFlag = false;
        };
        enum  {
            UpDown,
            RightLeft,
            NoMove
        };
        //動的確保用の変数
        Map Wmap;
        wall* Wall;
        wall* WallCorner;
        wall* Goal;
        //敵
        character* Enemys;
        int Ecnt = 0;
        //プレイヤー
        character player;
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void proc();
        void title();
        void init();
        void play();
        void result();
            void Pmove();
            void Emove();
            void stageChange();
            void collision();
                void hitbox(int w);
                    void playerHitBox();
            void draw();
        void destroy();
    };
}
