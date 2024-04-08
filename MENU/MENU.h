#pragma once
#include <string>
#include <memory>
#include "../MAIN/GAME_BASE.h"
class MENU :
    public GAME_BASE
{
public:
    MENU(class MAIN* main) :GAME_BASE(main) {};
    ~MENU() {};
    int create();
    void proc();
    void destroy();
private:
    //�t�@�C���ǂݍ��� create()����Ăяo�����
    void LoadGameIndices();
    void LoadTitleNames();
    //�Q�[���C���f�b�N�X�̈ʒu���}�E�X�ŕς��� proc()����Ăяo�����
    void ChangeGameIndices();
    char* GameIndices=0; 
    int NumGameIndices=0;
    int TileIndexMouseHolding=0;
    int TileIndexMouseOver=0;
    //���j���[�`�� proc����Ăяo�����
    void Draw();
    int Rows=0, Cols=0;
    float TileH=0, TileW=0;
    float OfstX=0, OfstY=0;
    float DivHue=0;
    float SizeText=0;
    std::string* Titles=0;
};

