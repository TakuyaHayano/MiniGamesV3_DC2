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
        //�s��J�E���g�p
        int row = 0;//�s
        int col = 0;//��
        int cnt = 0;
        int wallCnt = 0;
        int goalCnt = 0;
        //�Ǌ֘A
        int wallImg = 0;
        //�����蔻��p
        struct HITBOX {
            VECTOR2 Wup;
            VECTOR2 Wunder;
            VECTOR2 Wleft;
            VECTOR2 Wright;
            VECTOR2 Wcore;
            //�v���C���[�̕�
            VECTOR2 Pup;
            VECTOR2 Punder;
            VECTOR2 Pleft;
            VECTOR2 Pright;
            //�e���肩��̋���
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
        //goal�֘A
        int goalImg = 0;
        struct Map {
            //��ʊ֘A
            int Xsize = 192;
            int XharfSize = Xsize / 2;
            int Ysize = 216;
            int YharfSize = Ysize / 2;
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
            //���E
            float VisionAngle = 60;
            float length = 300;
            float radius = 50;
            float Hradius = radius / 2;
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
                void hitbox(int w);
            void draw();
        void destroy();
    };
}
