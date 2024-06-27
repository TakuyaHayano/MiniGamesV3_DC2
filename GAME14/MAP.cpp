#include "MAP.h"
#include"GAME14.h"
#include"CONTAINER.h"
#include"CHARACTER_MANAGER.h"
#include"../../libOne/inc/rand.h"
namespace GAME14 {
    MAP::MAP(class GAME* game):
        GAME_OBJECT(game){}
    MAP::~MAP(){
        if (Map.data) { delete[] Map.data; Map.data = 0; }
    }
    void MAP::create(){
        Map = game()->container()->data().map;
        Map.salmonAppTime = rand() % (Map.salmonLimitTime - Map.salmonOffsetTime + 1) + Map.salmonOffsetTime;

    }
    void MAP::init(){

        FILE* fp;
        fopen_s(&fp, Map.fileName, "rb");
        
        WARNING(!fp, "�t�@�C���J���Ȃ�", "");
        fseek(fp, 0, SEEK_END);
        int fileSize = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        if (Map.data) { delete[] Map.data; Map.data = 0; }
        Map.data = new char[fileSize];
        fread(Map.data, sizeof(char), fileSize, fp);
        fclose(fp);
        Map.cols = 0;
        Map.rows = 0;
        int cnt = 0;
        for (int i = 0; i < fileSize; i++) {
            cnt++; 
            if (Map.data[i] == '\n') {
                if (!Map.rows) {
                    Map.cols = cnt;
                }
                else if (Map.cols != cnt) {
                    WARNING(1, "�񐔂��s����", "");
                }
                Map.rows++;
                cnt = 0;
            }
        }
        if (fileSize % Map.cols) {
            WARNING(1, "�Ō�̉��s�����Ă��Ȃ�", "");
        }
        Map.dispRows = (int)height / Map.blockSizeY + 1;//13
        Map.worldHeight = (float)Map.blockSizeY * Map.rows;
        Map.worldWidth = (float)Map.blockSizeX * (Map.cols-2);
        Map.worldEndY = height;
        Map.wy = Map.worldHeight;//�\�����Ă���}�b�v�S�̂ł̍���

        Map.salmonAppTime = random(Map.salmonOffsetTime, Map.salmonLimitTime);
        Map.salmonTime = 0;
    }
    void MAP::update(){
        Map.wy += game()->characterManager()->player()->overWindowCenter() -
            game()->characterManager()->player()->overWindowBottom();
        if (Map.wy <= Map.worldEndY) {
            Map.wy = Map.worldEndY;
        }
    }
    void MAP::draw(){
        int numImg = Map.worldHeight / Map.backPosOffsetY + 1;
        for (int i = 0; i < numImg; i++) {
            image(Map.backImg, Map.backPosX, height - (Map.backPosOffsetY*(i+1)-(Map.worldHeight-Map.wy)), 0, 1);
            fill(255,0,0);
        }
        int startRow = (int)Map.wy / Map.blockSizeY;//�\���J�n�s 14
        int endRow = startRow-Map.dispRows;//�\���I���s 1
        int cunt = 0;
        for (int r = startRow; r >= endRow; r--) {
            float wy = (float)Map.blockSizeY * r;
            for (int c = 0; c < Map.cols; c++) {
                float wx = (float)Map.blockSizeX * c;
                char charaId = Map.data[r * Map.cols + c];
                float py = wy - Map.wy +height;
                float px = wx - Map.wx;
                if (charaId >='0'&&charaId<='9') {
                    if (charaId == BLOCK_ID) { image(Map.blockImg, px + Map.ofset, py, 0, 1); }
                    if (charaId == GOAL_ID) { image(Map.goalImg, px + Map.ofset-(1200*0.2f/2) + Map.blockSizeX / 2, py-(Map.blockSizeY-5), 0, 0.2f); }
                }
                else if (charaId >= 'a' && charaId <= 'z') {
                    game()->characterManager()->apperar(charaId, wx, wy);
                }
            }
        }
        
        if (Map.salmonTime >= Map.salmonAppTime) {
            int randX = rand() % (Map.salmonAppAreaEndX + 1) + Map.salmonAppAreaStartX;
            game()->characterManager()->apperar(SALMON_ID, Map.ofset+randX, height);
            Map.salmonAppTime = rand() % (Map.salmonLimitTime - Map.salmonOffsetTime + 1) + Map.salmonOffsetTime;
            Map.salmonTime = 0;
        }
    }
    void MAP::timeCunt() {
        Map.salmonTime += delta;
    }
    bool MAP::collisionCheck(float wx, float wy){
        //�n���ꂽ���W�����s����ɂ��邩
        int row = (int)wy / Map.blockSizeY;
        int col = (int)wx / Map.blockSizeX;
        //�O������Ƃ��Ă��̏ꏊ���}�b�v���ł��邩
        if ((col < 0 || col >= Map.cols) || (row<0 || row>Map.rows)) {
            return false;
        }
        //���̏ꏊ�Ƀu���b�N�����邩
        if (Map.data[row * Map.cols + col] == '1') {
            return true;
        }
        return false;
    }
    bool MAP::collisionGoalCheck(float wx, float wy){
        int row = (int)wy / Map.blockSizeY;
        int col = (int)wx / Map.blockSizeX;
        if ((col < 0 || col >= Map.cols) || (row<0 || row>Map.rows)) {
            return false;
        }
        if (Map.data[row * Map.cols + col] == '2') {
            return true;
        }
        return false;

    }
    //�L�����̉E�ӂ�ry(
    bool MAP::collisionCharaRight(float wx, float wy,float top,float right){ 
        bool RightTop = collisionCheck(wx + right, wy - top+Map.blockSizeY);
        bool RightBottm = collisionCheck(wx + right, wy+Map.blockSizeY-1);
        
        return RightTop||
            RightBottm;
    }

    //�L�����̍��ӂ��u���b�N�ɏd�Ȃ��Ă邩
    bool MAP::collisionCharaLeft(float wx, float wy,float top) {
        bool LeftTop = collisionCheck(wx, wy - top+Map.blockSizeY);
        bool LeftBottm = collisionCheck(wx, wy+Map.blockSizeY-1);
        
        return LeftTop  || LeftBottm  ;
    }
    //�L�����̏�ӂ�ry(
    bool MAP::collisionCharaTop(float wx, float wy,float top,float right){ 
        bool TopLeft = collisionCheck(wx+7, wy - top+Map.blockSizeY);
        bool TopRight = collisionCheck(wx + right-7, wy - top+Map.blockSizeY);
        return TopLeft || TopRight;
    }
    //�L�����̉��ӂ�ry(
    bool MAP::collisionCharaBottom(float wx, float wy,float right){
        bool BottomLeft = collisionCheck(wx+7, wy+Map.blockSizeY-1);
        bool BottomRight = collisionCheck(wx + right-7 , wy+Map.blockSizeY-1);
        return BottomLeft|| BottomRight  ;
    }
    //�L�����̉��ӂ��S�[���u���b�N�ɏd�Ȃ��Ă邩
    bool MAP::collisionGoalBottom(float wx, float wy, float right) {
        bool BottomLeft = collisionGoalCheck(wx + 7, wy + Map.blockSizeY - 1);
        bool BottomRight = collisionGoalCheck(wx + right - 7, wy + Map.blockSizeY - 1);
        return BottomLeft || BottomRight;

    }
}