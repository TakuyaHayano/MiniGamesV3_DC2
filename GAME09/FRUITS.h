#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09
{
    class FRUITS :
        public GAME_OBJECT
    {
    public:
        enum FRUITS_KINDS {
            CHERRY,
            STRAWBERRY,
            GRAPE,
            DEKOPON,
            PERSIMMON,
            APPLE,
            PEAR,
            PEACH,
            PINEAPPLE,
            MELON,
            WATERMELON,
            NUM_FRUITS_KINDS
        };
        struct DATA {
            float sw;
            float attenuationRate; //�^���ʂ̌�����(�n�ʂœ����^��������̂�����邽��)

            float cherrySize;
        };
    private:
        DATA Fruits;
        FRUITS_KINDS Kinds;

        VECTOR2 Pos_current;
        VECTOR2 Pos_old;
        VECTOR2 Acc;
        bool Touch; //���̃I�u�W�F�N�g�ƐG��Ă��邩�ǂ���
        float Omega; //�p���x
        float Theta; //�p�x(���W�A��)

        float Radius;
    public:
        FRUITS(class GAME* game, VECTOR2 pos);
        ~FRUITS();
        void create();
        void init();
        void update(float dt);
        void accelerate(VECTOR2 acc);
        void draw();

        const VECTOR2& getPosC() { return Pos_current; }
        float getRadius() { return Radius; }

        void setPosC(const VECTOR2& newPos) { Pos_current = newPos; }
        void setTouch(bool touch) { Touch = touch; }
    };
}
