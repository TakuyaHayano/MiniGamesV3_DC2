#pragma once
#include "GAME_OBJECT.h"
namespace GAME14 {
    class MAP :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            const char* fileName ;
            int blockImg ;
            int goalImg;
            int backImg;
            float backPosX = 0;
            float backPosOffsetY = 0;
            float  blockSizeX;
            float  blockSizeY;
            char* data = 0;
            int cols = 0;//�񐔁i������Ȃ�j
            int dispCols = 0;//�\������
            int rows = 0;//�s��
            int dispRows = 0;//�\������
            float wx = 0;//�}�b�v�S�̂ł̕\�����錻�ݍ��W
            float wy = 0;
            float worldWidth = 0;//�}�b�v�̕�
            float worldHeight = 0;//�}�b�v�̍���
            float worldEndY = 0;
            float ofset;//�v���C�̈�̈ړ�

            float salmonTime =0;
            int salmonOffsetTime;//���̃T�[�������o��܂ł̍Œ᎞��
            int salmonLimitTime;//���̃T�[�������o��܂ł̍ō�����
            int salmonAppAreaStartX;
            int salmonAppAreaEndX;
            int salmonAppTime = 0;//�T�[�����̏o������
        };
        enum CHARA_ID {
            PLAYER_ID = 'p',
            BLOCK_ID = '1',
            GOAL_ID = '2',
            SALMON_ID = 1
        };
    private:
        DATA Map;
    public:
        MAP(class GAME* game);
        ~MAP();
        void create();
        void init();
        void update();
        void draw();
        void timeCunt();
        float wx() { return Map.wx; }
        float wy() { return Map.wy; }
        int blockSizeX() { return Map.blockSizeX; }
        int blockSizeY() { return Map.blockSizeY; }
        float worldWidht() { return Map.worldWidth; }
        float worldHeight() { return Map.worldHeight; }
        float ofset() { return Map.ofset; }
        float salmonAppTime() { return Map.salmonAppTime; }
        float salmonTime() { return Map.salmonTime; }

        bool collisionCheck(float wx, float wy);
        bool collisionGoalCheck(float wx, float wy);

        bool collisionCharaLeft(float wx, float wy,float top);
        bool collisionCharaTop(float wx, float wy,float top,float right);
        bool collisionCharaRight(float wx, float wy,float top,float right);
        bool collisionCharaBottom(float wx, float wy,float right);
        bool collisionGoalBottom(float wx, float wy, float right);

    };
}

