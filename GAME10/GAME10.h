#pragma once
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
        //goal関連
        int goalImg = 0;
        struct Map {
            //画面関連
            int size = 192;
            int harfSize = size / 2;
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
            int size = 192;
            int harfSize = size / 2;
        };
        Map Wmap;
        wall* Wall;
        wall* Goal;
        struct character {
            float Cpx = 0;
            float Cpy = 0;
            float Mx = 5;
            float My = 5;
            float radius = 50;
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
            void draw();
        void destroy();
    };
}
