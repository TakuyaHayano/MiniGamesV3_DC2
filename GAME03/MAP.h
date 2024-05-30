#pragma once
#include"GAME_OBJECT.h"
namespace GAME03 {
    class MAP :public GAME_OBJECT {
    public:
        struct DATA {
            const char* fileName = 0;
            int blockImg = 0;
            int goalImg = 0;
            int chipSize = 0;//�����`�}�b�v�`�b�v�摜�̈�ӂ̃h�b�g��
            char* data = 0;  //�f�[�^�z��̃|�C���^
            int cols = 0;    //�f�[�^�̗�
            int rows = 0;    //�f�[�^�̍s��
            int dispCols = 0;
            int dispRows = 0;
            float wx = 0;    //world position x
            float wy = 0;    //world position y
            float worldWidth = 0;
            float worldHeight = 0;
            float endWorldX = 0;
            float endWorldY = 0;
            float centerX = 0;
        };
        enum CHARA_ID {
            PLAYER_ID = 'a',
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
        float wx() { return Map.wx; }
        float wy() { return Map.wy; }
        int chipSize() { return Map.chipSize; }
        bool collisionCheck(float wx, float wy);
        bool collisionCharaLeft(float wx, float wy);
        bool collisionCharaRight(float wx, float wy);
        bool collisionCharaTop(float wx, float wy);
        bool collisionCharaBottom(float wx, float wy);
        float wDispLeft();
        float wDispRight();
    };
}

