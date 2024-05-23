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
            VECTOR2 up;
            VECTOR2 under;
            VECTOR2 left;
            VECTOR2 right;
            VECTOR2 core;
        };
        struct DISTANCE {
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
            int ItemKind = 0;
        };
        //当たり判定関係
        HITBOX HitBox;
        HITBOX WallBox;
        HITBOX PlayerBox;
        HITBOX EnemyBox;
        DISTANCE PDist;
        DISTANCE EDist;
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
            //見ている位置の種類
            enum {
                Up,
                Under,
                Right,
                Left
            };
            int View;
            //敵の動きの種類
            int Mkind = 0;
            //プレイヤーのみ使用する(アイテムの保持)
            bool KeyFlag = false;
            //敵が壁にぶつかったか
            bool WallHitFlag = false;
            int Frieze = 0;
        };
        const int FriezeTime = 1500;
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
        const int FrieseTime = 240;
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
                void hitbox(int w);//プレイヤーと壁
                void hitbox(int w, int e);//敵と壁
                void wallHitBox(int w);
                    void playerHitBox();
                    void enemyHitBox(int e);
            void draw();
        void destroy();
    };
}
