#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/sound.h"
#include"GAME_BASE.h"
GAME_BASE::GAME_BASE(class MAIN* main) 
	:Main(main) 
{
	//�����t�@�C�����Đ�����B
	//��������Ă����Ȃ��ƂȂ����A�P���ڂ̍Đ����x������B
	playSound(loadSound("../main/assets/silence.wav"));
}
GAME_BASE::~GAME_BASE()
{
	refreshCntnr();
	releaseAllSound();
}
