#include"CONTAINER.h"
#include"GAME14.h"
#include "PLAYER.h"
#include"JUMP_POW.h"
namespace GAME14 {
    PLAYER::PLAYER(class GAME* game):
        CHARACTER(game){}
    PLAYER::~PLAYER() {
    }
    void PLAYER::create(){
        Chara = game()->container()->data().playerChara;
        Player = game()->container()->data().player;
        JumpPow = new JUMP_POW(game());
        JumpPow->create();
    }
    void PLAYER::deleteFanc() {
        delete JumpPow;

    }
    void PLAYER::init() {
        JumpPow->init();
        ActState = WAIT;
        Chara.hp = 0;
        Player.pos = VECTOR2(0, 0);
        Player.vecX = 0;
        Chara.worldPos = VECTOR2(0, 0);
        Player.jumpFlag = false;
        Player.curSpeed = 0;
        Player.numSalmon = 0;
        ChangeImg();
    }

    void PLAYER::appear(float wx,float wy){
        Chara.hp = 1;
        Chara.worldPos = VECTOR2(wx, wy);
        Player.pos = Chara.worldPos;
        Player.numSalmon = 0;
    }
    void PLAYER::update(){
        Move();
        CollisionWithMap();
    }
    void PLAYER::draw(){
        MAP* map = game()->map();
        //�f�B�X�v���C��̈ʒu
        Player.pos = VECTOR2(Chara.worldPos.x+map->ofset(),height + (Chara.worldPos.y - map->wy()));
        fill(Chara.color.r, Chara.color.g, Chara.color.b);

        //rect(Chara.worldPos.x+map->ofset(), Chara.worldPos.y, Chara.offsetRight, -Chara.offsetTop);
        //rect(Player.pos.x, Player.pos.y - Player.imgOffsetY, Chara.offsetRight, Chara.offsetTop);
        image(Player.curImg, Player.pos.x-Player.imgOffsetX, Player.pos.y - Player.imgOffsetY, 0, Player.imgSize);
        if (ActState >= CROUCH) {
            JumpPow->draw(Player.pos,Chara.offsetRight,Player.vecX);
        }
    }
    void PLAYER::Move(){
            Player.curPos = Chara.worldPos;
            if (isTrigger(MOUSE_LBUTTON) && ActState != JUMP) {
                ChangeActState();
            }
            switch (ActState) {
            case WAIT:
                DirectionX();
                ChangeImg();
                break;
            case CROUCH:
                JumpPow->update();

                break;
            case JUMP:
                Player.curSpeed.y -= Player.gravity;
                Chara.worldPos.y -= Player.curSpeed.y * delta;
                Chara.worldPos.x += Player.vecX * Player.curSpeed.x * delta;
                break;
            }
           // if (isPress(KEY_D)) { Chara.worldPos.x += Player.jumpSpeed.x * delta; }
           // if (isPress(KEY_S)) { Chara.worldPos.y += Player.jumpSpeed.y * delta; }
           // if (isPress(KEY_W)) { Chara.worldPos.y -= Player.jumpSpeed.y * delta; }
           // if (isPress(KEY_A)) { Chara.worldPos.x -= Player.jumpSpeed.x * delta; }
    }
    void PLAYER::CollisionWithMap(){
        MAP* map = game()->map();
        float posX = Chara.worldPos.x;// -map->ofset();//�u���b�N�Ƃ̏Փ˔���p
        int blockX;
        int blockY;
        if (Player.vecX > 0) {
            //�E��
            for (int i = 0; i < Chara.offsetTop / Player.offsetTop; i++) {
                if (map->collisionCharaRight(Chara.worldPos.x, Chara.worldPos.y, Player.offsetTop * (i + 1), Chara.offsetRight) ||
                    Chara.worldPos.x + Chara.offsetRight > map->worldWidht()) {
                    if (i < Chara.offsetTop/ Player.offsetTop-1&&i>0) {//��ӂƉ��ӂɂȂ��_�Ȃ�
                        blockX = ((int)Chara.worldPos.x + (int)Chara.offsetRight) / map->blockSizeX() * map->blockSizeX();
                        Chara.worldPos.x -= (Chara.worldPos.x + Chara.offsetRight) - blockX + 1;
                        Player.curSpeed.x = 0;
                        break;
                    }
                    Chara.worldPos.x = Player.curPos.x;
                    break;
                }
            }
        }
        else {
            //����
            for (int i = 0; i < Chara.offsetTop / Player.offsetTop; i++) {
                if (map->collisionCharaLeft(Chara.worldPos.x, Chara.worldPos.y, Player.offsetTop * (i + 1))
                    ) {
                    if (i < Chara.offsetTop / Player.offsetTop-1&&i>0) {//��ӂƉ��ӂɂȂ��_�Ȃ�
                        blockX = (int)Chara.worldPos.x / map->blockSizeX() * map->blockSizeX();
                        Chara.worldPos.x += (blockX + map->blockSizeX()) - Chara.worldPos.x;
                        Player.curSpeed.x = 0;
                        break;
                    }
                    Chara.worldPos.x = Player.curPos.x;
                    break;
                }
            }
            if (Chara.worldPos.x < 0) {
                Chara.worldPos.x = 0;
            }
        }
        //���
        if (map->collisionCharaTop(Chara.worldPos.x, Chara.worldPos.y, Chara.offsetTop, Chara.offsetRight)) {
            blockY = ((int)Chara.worldPos.y+map->blockSizeY())/ map->blockSizeY() * map->blockSizeY();
            Chara.worldPos.y += blockY-(Chara.worldPos.y-Chara.offsetBottom);

            Player.curSpeed.y = Player.gravity;

        }
        //if ((Chara.worldPos.y - Chara.offsetTop <= 0)) {
        //    Chara.worldPos.y = Player.curPos.y;
        //    Player.curSpeed.y = Player.gravity;

        //}
        //����
        if(map->collisionCharaBottom(Chara.worldPos.x,Chara.worldPos.y,Chara.offsetRight)||
            (Chara.worldPos.y>map->wy())){
            blockY = (int)Chara.worldPos.y  / map->blockSizeY() * map->blockSizeY();
            Chara.worldPos.y = blockY;
            Chara.worldPos.x = Player.curPos.x;
            Player.curSpeed.x = 0;
            if(ActState==JUMP){
                ActState = WAIT;
            }
        }
        if (ActState == WAIT) {
            if (map->collisionGoalBottom(posX, Chara.worldPos.y, Chara.offsetRight)) {
                ActState == CLEAR;
                Player.clearFlag = true;
            }
        }
        
    }
    void PLAYER::ChangeActState(){
            switch (ActState) {
            case WAIT:
                    ActState = CROUCH;
                    JumpPow->init();
                    ChangeImg();
                break;
            case CROUCH:
                if (JumpPow->endDirection()) {
                    ActState = JUMP;
                    Player.curSpeed.x = Player.jumpSpeed.x * JumpPow->curPowX();
                    Player.curSpeed.y = Player.jumpSpeed.y * JumpPow->curPowY();
                }
                ChangeImg();
                break;
            case JUMP:
                ActState = WAIT;
                break;
            }
    }
    void PLAYER::ChangeImg() { 
        if (Player.vecX+1) {
            Player.curImg = Player.img[(const int)Player.vecX * ActState + ActState];
        }
        else {
            Player.curImg = Player.img[(const int)Player.vecX * -1 + ActState * 2];
        }
    }
    void PLAYER::DirectionX() {
        Player.vecX = mouseX - (Player.pos.x + Chara.offsetRight / 2);
        if (Player.vecX>=0) {
            Player.vecX = 1;
        }
        else {
            Player.vecX = -1;
        }
    }
    float PLAYER::overWindowCenter() {
        float centerPy = height / 2 - game()->map()->blockSizeY() / 2;
        float overCenter = (Player.pos.y - Chara.offsetTop / 2) - centerPy;
        if (overCenter > 0||Chara.hp ==0) overCenter = 0;
        return overCenter;
    }
    float PLAYER::overWindowBottom() {
        float bottomPy = height - game()->map()->blockSizeY()*2;
        float overBottom = bottomPy - Player.pos.y;
        if (overBottom > 0 || Chara.hp == 0) overBottom = 0;
        return overBottom;
    }

}