#include <fstream>
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "../../libOne/inc/mathUtil.h"
#include "../MAIN/GAME_FACTORY.h"
#include "../MAIN/MAIN.h"
#include "MENU.h"

int MENU::create()
{
	//�e�ϐ�������
	//�^�C���̐�
	Rows = 4;//�s
	Cols = 4;//��
	//�^�C���̑傫��
	TileW = 160*2;
	TileH = 90*2;
	//����̌��_�����炷�l
	OfstX = (width - TileW * Cols) / 2;
	OfstY = (height - TileH * Rows) / 2;
	//�^�C���̐F�����肷�邽�߂̕������ꂽ�p�xHue
	DivHue = 360.0f / (Cols * Rows);
	//�^�C���̏�ɕ\������e�Q�[���̃^�C�g���̑傫��
	SizeText = 40;
	//�}�E�X�ŉE�N���b�N���ꂽ�^�C���̃C���f�b�N�X�B�Ƃ肠����-1�Ŗ����ɂ��Ă����B
	TileIndexMouseHolding = -1;

	LoadGameIndices();
	LoadTitleNames();

	return 0;
}

void MENU::LoadGameIndices()
{
	//���j���[�ɕ��ׂ�Q�[���̃C���f�b�N�X�ԍ��̔z��m��
	NumGameIndices = Rows * Cols;
	GameIndices = new char[NumGameIndices] {};
	//���j���[�ɕ��ׂ�Q�[���̃C���f�b�N�X�ԍ��t�@�C����GameIndices�z��ɓǂݍ���
	const char* fileName = "../MAIN/assets/menu/indices.bin";
	std::ifstream ifs(fileName, std::ios::binary);
	if (ifs) {
		//��C�ɓǂݍ��ށB
		ifs.read(GameIndices, NumGameIndices);
		ifs.close();
	}
	else {
		//�t�@�C����������ΘA�Ԃ�ݒ�
		for (int i = 0; i < NumGameIndices; i++) {
			GameIndices[i] = i;
		}
	}
}

void MENU::LoadTitleNames()
{
	//�^�C���ɕ\������Q�[���^�C�g���̃e�L�X�g��ǂݍ��ޔz��m��
	Titles = new std::string[NumGameIndices];
	//�^�C���ɕ\������Q�[���^�C�g���̃e�L�X�g���t�@�C������ǂݍ���
	std::ifstream ifs;
	char buf[128];
	for (int i = 0; i < NumGameIndices; i++) {
		sprintf_s(buf, "../MAIN/assets/game%02d/title.txt", i);
		ifs.open(buf);
		std::getline(ifs, Titles[i]);
		ifs.close();
	}
}

void MENU::destroy()
{
	//���݂̃C���f�b�N�X�̕��т��t�@�C���ɏ�������
	const char* fileName = "../MAIN/assets/menu/indices.bin";
	std::ofstream ofs(fileName, std::ios::binary);
	ofs.write(GameIndices, NumGameIndices);

	delete[] Titles;
	delete[] GameIndices;
}

void MENU::proc()
{
	//�X�V--------------------------------------------------
	ChangeGameIndices();
	//�`��--------------------------------------------------
	Draw();
	//���N���b�N�őI�������Q�[���ɐ؂�ւ�-----------------------
	if (isTrigger(MOUSE_LBUTTON)) {
		if (TileIndexMouseOver >= 0) {
			int index = GameIndices[TileIndexMouseOver];
			main()->setNextGameId((GAME_FACTORY::GAME_ID)index);
		}
	}
}

//�}�E�X�E�{�^���ɂ��h���b�O�A���h�h���b�v�ŃQ�[���̏�������ѕς���
void MENU::ChangeGameIndices()
{
	//�}�E�X������Ă���^�C���̃C���f�b�N�X�B
	//���[�v���Ƃɒ��ׂ邽�ߖ���(-1)�ɂ��Ă���
	TileIndexMouseOver = -1;

	//�}�E�X���S�^�C���̊O�ɂ��鎞�͂��̊֐��𔲂���
	if (mouseX<OfstX || mouseX > OfstX + TileW * Cols ||
		mouseY<OfstY || mouseY > OfstY + TileH * Rows) {
		//�͂�ł���C���f�b�N�X�𖳌��ɂ���
		TileIndexMouseHolding = -1;
		return;
	}

	//�������牺�̓^�C����Ƀ}�E�X������-------------------------
	
	//�}�E�X�̈ʒu�����ԍ��ƍs�ԍ��ɕϊ�
	int mouseCol = int((mouseX - OfstX) / TileW);
	int mouseRow = int((mouseY - OfstY) / TileH);
	//�P�����z��GameIndices[]�̃C���f�b�N�X�ɕϊ�
	TileIndexMouseOver = Cols * mouseRow + mouseCol;

	//�u�͂ށI�v�E�N���b�N���ꂽ�^�C���̃C���f�b�N�X������Ă���
	if (isTrigger(MOUSE_RBUTTON)) {
		TileIndexMouseHolding = TileIndexMouseOver;
	}

	//�u�����I�v�E�{�^���𗣂����ʒu�ɁA�Ƃ��Ă������C���f�b�N�X��}��
	if (isRelease(MOUSE_RBUTTON) &&
		TileIndexMouseHolding != -1) {
		//�͂�ł���u�Q�[���̃C���f�b�N�X�v������Ă���
		int workIndex = GameIndices[TileIndexMouseHolding];
		//����̃C���f�b�N�X��O���Ƀh���b�O�A���h�h���b�v�������A���ɂ��炷���đ}���ʒu���󂯂�
		if (TileIndexMouseOver < TileIndexMouseHolding)	{
			for (int i = TileIndexMouseHolding; i > TileIndexMouseOver; i--) {
				GameIndices[i] = GameIndices[i - 1];
			}
		}
		//�O���̃C���f�b�N�X������Ƀh���b�O�A���h�h���b�v�������A�O�ɂ��炷���đ}���ʒu���󂯂�
		else if (TileIndexMouseOver > TileIndexMouseHolding) {
			for (int i = TileIndexMouseHolding; i < TileIndexMouseOver; i++) {
				GameIndices[i] = GameIndices[i + 1];
			}
		}
		//���炷���Ƃɂ��}���ꏊ���ł����̂œ����
		GameIndices[TileIndexMouseOver] = workIndex;
		//�����ɂ���
		TileIndexMouseHolding = -1;
	}
}

void MENU::Draw()
{
	//�J���[���[�h�A�g�̐F�A�g�̕��A��ʃN���A
	colorMode(HSV);
	angleMode(DEGREES);
	stroke(0, 0, 0);
	strokeWeight(5);
	clear(0, 0, 0);
	//Menu�����`��
	textMode(BOTTOM);
	textSize(SizeText);
	fill(0, 0, 255);
	text("Menu", OfstX, OfstY);
	//�^�C���`��
	for (int r = 0; r < Rows; r++)
	{
		for (int c = 0; c < Cols; c++)
		{
			//�^�C���̐F������
			int index = Cols * r + c;
			float hue = DivHue * index;
			float saturation = 255;
			float value = 160;
			//�}�E�X����ɂ���^�C���͖��邭
			if (index == TileIndexMouseOver) {
				saturation = 128;
				value = 255;
			}
			fill(hue, saturation, value);
			//�^�C���̈ʒu
			float px = TileW * c + OfstX;
			float py = TileH * r + OfstY;
			rect(px, py, TileW, TileH);
			//�^�C�g������
			textSize(SizeText);
			fill(0);
			textMode(BOTTOM);
			text(Titles[GameIndices[index]].c_str(), px + 10, py + 10 + SizeText);
		}
	}
	//�ړ����̃^�C�g��������`��
	if (TileIndexMouseHolding >= 0) {
		fill(128);
		textMode(BCENTER);
		text(Titles[GameIndices[TileIndexMouseHolding]].c_str(), mouseX, mouseY);
	}
}