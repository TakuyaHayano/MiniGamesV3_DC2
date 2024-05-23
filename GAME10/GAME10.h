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
        //�s��J�E���g�p
        int row = 0;//�s
        int col = 0;//��
        int cnt = 0;
        int WallCnt = 0;
        int GoalCnt = 0;
        int InvisibleWallCnt = 0;
        int EnemyCnt = 0;
        //�Ǌ֘A
        int WallImg = 0;
        int WallLeftImg = 0;
        int WallRightImg = 0;
        int WallUpImg = 0;
        int WallUnderImg = 0;
        int WallUpLeftCornerImg = 0;
        int WallUnderLeftCornerImg = 0;
        int WallUpRightCornerImg = 0;
        int WallUnderRightCornerImg = 0;
        //�����蔻��p
        struct HITBOX {
            VECTOR2 up;
            VECTOR2 under;
            VECTOR2 left;
            VECTOR2 right;
            VECTOR2 core;
        };
        struct DISTANCE {
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
        struct Item {
            VECTOR2 ItemCore;
            float Iradius = 20;
            float HIradius = Iradius / 2;
            int ItemKind = 0;
        };
        //�����蔻��֌W
        HITBOX HitBox;
        HITBOX WallBox;
        HITBOX PlayerBox;
        HITBOX EnemyBox;
        DISTANCE PDist;
        DISTANCE EDist;
        //�A�C�e���֘A
        Item Gun;
        Item Key;
        //goal�֘A
        int goalImg = 0;
        struct character {
            float Cpx = 0;
            float Cpy = 0;
            float Mx = 5;
            float My = 5;
            //���E(�G�݂̂��g�p)
            float length = 300;
            float radius = 50;
            float Hradius = radius / 2;
            //���Ă���ʒu�̎��
            enum {
                Up,
                Under,
                Right,
                Left
            };
            int View;
            //�G�̓����̎��
            int Mkind = 0;
            //�v���C���[�̂ݎg�p����(�A�C�e���̕ێ�)
            bool KeyFlag = false;
            //�G���ǂɂԂ�������
            bool WallHitFlag = false;
            int Frieze = 0;
        };
        const int FriezeTime = 1500;
        enum  {
            UpDown,
            RightLeft,
            NoMove
        };
        //���I�m�ۗp�̕ϐ�
        Map Wmap;
        wall* Wall;
        wall* WallCorner;
        wall* Goal;
        //�G
        character* Enemys;
        int Ecnt = 0;
        const int FrieseTime = 240;
        //�v���C���[
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
                void hitbox(int w);//�v���C���[�ƕ�
                void hitbox(int w, int e);//�G�ƕ�
                void wallHitBox(int w);
                    void playerHitBox();
                    void enemyHitBox(int e);
            void draw();
        void destroy();
    };
}
