#pragma once
#include "../../libOne/inc/libOne.h"
#include "../MAIN/GAME_BASE.h"
namespace GAME10
{
    class GAME :
        public GAME_BASE
    {
    private:
        const char* fileName;
        FILE* fp;
        int fileSize;
        char* map;
        //行列カウント用
        int row = 0;//行
        int col = 0;//列
        int cnt = 0;
        int wallCnt = 0;
        int goalCnt = 0;
        //壁関連
        int wallImg = 0;
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
        //goal関連
        int goalImg = 0;
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
        Map Wmap;
        HITBOX HitBox;
        wall* Wall;
        wall* Goal;
        struct character {
            float Cpx = 0;
            float Cpy = 0;
            float Mx = 5;
            float My = 5;
            //視界
            float VisionAngle = 60;
            float length = 300;
            float radius = 50;
            float Hradius = radius / 2;
        };
        //プレイヤー
        character player;
        //エネミー関連
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void proc();
            void move();
            void stageChange();
            void collision();
                void hitbox(int w);
            void draw();
        void destroy();
    };
}
