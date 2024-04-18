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
        //�s��J�E���g�p
        int row = 0;//�s
        int col = 0;//��
        int cnt = 0;
        int wallCnt = 0;
        int goalCnt = 0;
        //�Ǌ֘A
        int wallImg = 0;
        //goal�֘A
        int goalImg = 0;
        struct Map {
            //��ʊ֘A
            int size = 192;
            int harfSize = size / 2;
            int mIdx = 0;
            //�}�b�v�̍��W
            float px = 0;
            float py = 0;
            float worldX = 0;
            float worldY = 0;
        };
        struct wall {
            //�Ǌ֘A�̃f�[�^
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
        //�v���C���[
        character player;
        //�G�l�~�[�֘A
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
