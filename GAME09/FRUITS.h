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
            float attenuationRate; //運動量の減衰率(地面で等速運動をするのを避けるため)

            int imgs[NUM_FRUITS_KINDS];
            float cherryImgSize;
            float cherryRadius;
            float nextFruitsSizeRate;

            float inflateMaxTime;
            float initValue;
        };
    private:
        DATA Fruits;
        FRUITS_KINDS Kinds;

        VECTOR2 Pos_current;
        VECTOR2 Pos_old;
        VECTOR2 Acc;
        bool Touch; //他のオブジェクトと触れているかどうか
        float Omega; //角速度
        float Theta; //角度(ラジアン)

        float Radius;
        float ImgSize;
        float InflateTime;
        float MaxRadius;
        bool Inflate;
    public:
        FRUITS(class GAME* game, VECTOR2 pos, FRUITS_KINDS kinds, bool inflate = false);
        ~FRUITS();
        void create();
        void init();
        void update(float dt);
        void accelerate(VECTOR2 acc);
        void draw();

        const VECTOR2& getPosC() { return Pos_current; }
        const VECTOR2& getPosO() { return Pos_old; }
        float getRadius() { return Radius; }
        FRUITS_KINDS getKinds() { return Kinds; }

        void setPosC(const VECTOR2& newPos) { Pos_current = newPos; }
        void setPosO(const VECTOR2& newPos) { Pos_old = newPos; }
        void setTouch(bool touch) { Touch = touch; }
    };
}
