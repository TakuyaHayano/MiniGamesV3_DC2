#pragma once
#include "CHARACTER.h"
namespace GAME14 {
    class SALMON :
        public CHARACTER
    {
    public:
        struct DATA {
            int img[2];
            VECTOR2 pos;//ÉTÅ[ÉÇÉìÇÕworldPosÇÕégÇÌÇ»Ç¢
            float imgSize;
            int animCunt;
            float animTime;
            float interval;
            bool appFlag = true;

        };
    private:
        DATA Salmon;
    public:
        SALMON(class GAME* game);
        void create();
        void init();
        void appear(float wx, float wy);
        void update();
        void draw();
    private:
        void Move();
    public:
        float offsetRight() { return Chara.offsetRight; }

    };
}

