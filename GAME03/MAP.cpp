#include"../../libOne/inc/window.h"
#include"../../libOne/inc/graphic.h"
#include"GAME03.h"
#include"CONTAINER.h"
#include"CHARACTER_MANAGER.h"
#include "MAP.h"
namespace GAME03 {
    MAP::MAP(class GAME* game) : GAME_OBJECT(game) {
    }
    MAP::~MAP() {
        if (Map.data) { delete[] Map.data; Map.data = 0; }
    }
    void MAP::create() {
        Map = game()->container()->data().map;
    }
    void MAP::init() {
        FILE* fp;
        fopen_s(&fp, Map.fileName, "rb");
        WARNING(fp == 0, "�}�b�v�f�[�^��ǂݍ��߂܂���", Map.fileName);
        fseek(fp, 0, SEEK_END);
        int fileSize = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        if (Map.data) { delete[] Map.data; Map.data = 0; }
        Map.data = new char[fileSize];
        fread(Map.data, sizeof(char), fileSize, fp);
        fclose(fp);
        Map.rows = 0;
        Map.cols = 0;
        int cnt = 0;
        for (int i = 0; i < fileSize; i++) {
            cnt++;
            if (Map.data[i] == '\n') {
                if (Map.rows == 0) {
                    Map.cols = cnt;
                }
                else if (Map.cols != cnt) {
                    WARNING(1, "�񐔂��s����", "");
                }
                Map.rows++;
                cnt = 0;
            }
        }
        if (fileSize % Map.cols != 0) {
            WARNING(1, "�Ō�̍s�����s���Ă��Ȃ�", "");
        }
        Map.dispCols = (int)width / Map.chipSize + 1;
        Map.worldWidth = (float)Map.chipSize * (Map.cols - 2);
        Map.endWorldX = Map.worldWidth - width;
        Map.wx = 0.0f;
    }
    void MAP::update() {
        Map.wx += game()->characterManager()->player()->overCenterVx();
        if (Map.wx > Map.endWorldX) {
            Map.wx = Map.endWorldX;
        }
    }
    void MAP::draw() {
        int startCol = (int)Map.wx / Map.chipSize;
        int endCol = startCol + Map.dispCols;
        for (int c = startCol; c < endCol; c++) {
            float wx = (float)Map.chipSize * c;
            for (int r = 0; r < Map.rows; r++) {
                float wy = (float)Map.chipSize * r;
                char charaId = Map.data[r * Map.cols + c];
                if (charaId >= '0' && charaId <= '9') {
                    float px = wx - Map.wx;
                    float py = wy - Map.wy;
                    if (charaId == '1')image(Map.blockImg, px, py);
                    else if (charaId == '2')image(Map.goalImg, px, py);
                }
                else if (charaId >= 'a' && charaId <= 'z') {
                    game()->characterManager()->appear(charaId, wx, wy);
                    Map.data[r * Map.cols + c] = '.';
                }
            }
        }
    }
    bool MAP::collisionCheck(float wx, float wy) const {
        int col = (int)wx / Map.chipSize;
        int row = (int)wy / Map.chipSize;
        if ((col < 0) || (col >= Map.cols) || (row < 0) || (row >= Map.rows)) {
            return false;
        }
        if (Map.data[col + row * Map.cols] == '1') {
            return true;
        }
        return false;
    }
    bool MAP::collisionCharaLeft(float wx, float wy) const {
        bool leftTop = collisionCheck(wx, wy);
        bool leftBottom = collisionCheck(wx, wy + Map.chipSize - 1);
        return leftTop || leftBottom;
    }
    bool MAP::collisionCharaRight(float wx, float wy) const {
        bool rightTop = collisionCheck(wx + Map.chipSize - 1, wy);
        bool rightBottom = collisionCheck(wx + Map.chipSize - 1, wy + Map.chipSize - 1);
        return rightTop || rightBottom;
    }
    bool MAP::collisionCharaTop(float wx, float wy) const {
        bool topLeft = collisionCheck(wx, wy);
        bool topRight = collisionCheck(wx + Map.chipSize - 1, wy);
        return topLeft || topRight;
    }
    bool MAP::collisionCharaBottom(float wx, float wy) const {
        bool bottomLeft = collisionCheck(wx, wy + Map.chipSize);
        bool bottomRight = collisionCheck(wx + Map.chipSize - 1, wy + Map.chipSize);
        return bottomLeft || bottomRight;
    }
    float MAP::wDispLeft() const {
        return Map.wx - Map.chipSize;
    }
    float MAP::wDispRight() const {
        return Map.wx + width;
    }
}
