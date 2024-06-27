#pragma once
#include "CHARACTER.h"
namespace GAME14 {
    class PLAYER :
        public CHARACTER
    {
        enum ACTION_STATE {
            WAIT,
            CROUCH,
            JUMP,
            CLEAR
        };
        enum IMG_ID {
            WAIT_R,
            WAIT_L,
            CROUCH_R,
            CROUCH_L,
            JUMP_R,
            JUMP_L,
            NUM_IMG
        };
    public:
        struct DATA {
            int img[NUM_IMG];
            float imgSize = 0;
            //�\�������p
            float imgOffsetX = 0;
            float imgOffsetY = 0;
            float gravity = 0;
            //�����蔻��p
            float offsetTop;
            VECTOR2 jumpSpeed ;

            int curImg;
            bool jumpFlag;
            VECTOR2 pos;//��ʏ�̍��W
            VECTOR2 curPos;
            float vecX = 0;
            VECTOR2 jumpPow = 0;
            VECTOR2 curSpeed = 0;

            bool clearFlag = false;
            int numSalmon = 0;
       };
    private:
        DATA Player;
        class JUMP_POW* JumpPow = nullptr;
        ACTION_STATE ActState = WAIT;
        IMG_ID ImgState = WAIT_R;
    public:
        PLAYER(class GAME* game);
        ~PLAYER();
        void init();
        void create();
        void deleteFanc();
        void appear(float wx,float wy);
        void update();
        void draw();
    private:
        void Move();
        void CollisionWithMap();
        void ChangeActState();
        void ChangeImg();
        void DirectionX();
    public:
        void countSalmon() { Player.numSalmon++; }
        int stacSalmon() { return Player.numSalmon; }
        float overWindowCenter();
        float overWindowBottom();
        bool clearFlag() { return Player.clearFlag; }
        float Right() { return Player.pos.x + Chara.offsetRight; }
        float Left() { return Player.pos.x + Chara.offsetLeft; }
        float Top() { return Player.pos.y - Player.imgOffsetY; }
        float Bottom() { return Player.pos.y - Player.imgOffsetY + Chara.offsetTop; }

    };
}

