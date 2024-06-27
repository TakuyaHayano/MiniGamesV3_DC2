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
            TUTORIAL,
            OPERATER,
            PLAY,
            RESULT
        };
        int STATE;
        struct button {
            VECTOR2 core;
            float radius = 100;
            float Hradius = radius / 2;
            bool SelectFlag = false;
        };
        struct button TutorialButton;
        struct button ProductionButton;
        struct button OperationButton;
        int buttonCnt = 0;
        enum ButtonState {
            STutorial,
            SProduction,
            SOperation,
            SButtonSum
        };
        //�{�ԗp�}�b�v
        const char* fileName;
        FILE* fp;
        int fileSize;
        char* map;
        //�`���[�g���A���p
        const char* CfileName;
        FILE* Cfp;
        int CfileSize;
        char* Tmap;
        //�s��J�E���g�p�i�{�ԗp�j
        struct matrix {
        int row = 0;//�s
        int col = 0;//��
        int cnt = 0;
        int WallCnt = 0;
        int GoalCnt = 0;
        int InvisibleWallCnt = 0;
        int EnemyCnt = 0;
        int KeyCnt = 0;
        int FlagCnt = 0;
        };
        matrix Production;
        matrix Tutorial;
        //�摜
            //�^�C�g����ʁE���U���g���
            int TitleImg = 0;
            int TutorialClearImg = 0;
            int PageCnt = 0;
            int PageImg[2] = {0,0};
            int TutorialPage[2] = { 0,0 };
            const int PageSum = 2;
            int ClearImg = 0;
            int OverImg = 0;
            //button�֘A
            int TButtonImg = 0;
            int PbuttonImg = 0;
            int ObuttonImg = 0;
            //�A�ɉB�ꂽ�摜
            int STButtonImg = 0;
            int SPbuttonImg = 0;
            int SObuttonImg = 0;
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
            //�S�[���֘A
            int goalImg = 0;
            int LockImg = 0;
            int KeyImg = 0;
            //�t���b�O
            int FlagImg = 0;
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
            bool LockFlag = false;
        };
        struct Item {
            VECTOR2 ItemCore;
            float Iradius = 30;
            int ItemKind = 0;
            bool Substance = false;
        };
        bool pauseFlag = true;
        int GetFlagCnt = 0;
        const int GetFlagLimit = 5;
        bool TutorialClearFlag = false;
        int Ftemp = 0;
        //�����蔻��֌W
        HITBOX HitBox;
        HITBOX WallBox;
        HITBOX PlayerBox;
        HITBOX EnemyBox;
        DISTANCE PDist;
        DISTANCE EDist;
        int Cmx = 0;//���������Ă����ꍇ�A�����߂��l�i���j
        int Cmy = 0;//���������Ă����ꍇ�A�����߂��l�i���j
        //goal�֘A
        bool GoalFlag = false;
        struct character {
            //�ړ��֘A
            float Cpx = 0;
            float Cpy = 0;
            float Mx = 5;
            float My = 5;
            //���E(�G�݂̂��g�p)
            float length = 300;
            float radius = 50;
            float Hradius = radius / 2;
            int View;
            //���E�͈�
            float ViewUp;
            float  ViewUnder;
            float  ViewRight;
            float  ViewLeft;
            float ViewLen;
            //�G�̓����̎��
            int Mkind = 0;
            //�v���C���[�̂ݎg�p����
            bool KeyFlag = false;
            //�G���ǂɂԂ�������
            bool WallHitFlag = false;
            int Frieze = 0;
            int FindLen = 400;
            int WarningLen = 500;
        };
        //���Ă���ʒu�̎��
        enum {
                Up,
                Right,
                Under,
                Left
            };
        int FriezeTime = 1500;
        enum  {
            UpDown,
            RightLeft,
            NoMove
        };
        //�����֘A
        bool FindFlag = false;
        //���I�m�ۗp�̕ϐ�
        struct STAGE {
            Map Wmap;
            wall* Wall;
            wall* WallCorner;
            wall* Goal;
            Item* Flag;
            Item* Key;
        };
        //���I�m�ۂ���ϐ��̃X�e�[�W���
        STAGE ProductionMap;
        STAGE TutorialMap;
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
        void buttonCol();
        void init();
        void tutorial();
        void operater();
        void play();
        void result();
            void Pmove();
            void Emove();
            void stageChange();
            void collision();
            void viewCollision(int e);
                void hitbox(int w);//�v���C���[�ƕ�
                void hitbox(int w, int e);//�G�ƕ�
                void wallHitBox(int w);
                    void playerHitBox();
                    void enemyHitBox(int e);
            void draw();
        void destroy();
    };
}
