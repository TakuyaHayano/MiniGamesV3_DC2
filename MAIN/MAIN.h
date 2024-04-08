#pragma once
#include "GAME_FACTORY.h"
class MAIN
{
public:
	MAIN();
	~MAIN();
	void run();
	void setNextGameId(GAME_FACTORY::GAME_ID nextGameId) { 
		NextGameId = nextGameId; 
	}
	void backToMenu() {
		NextGameId = GAME_FACTORY::MENU_ID;
	}
private:
	//�Q�[���̃V���v���t�@�N�g���I�u�W�F�N�g
	class GAME_FACTORY* GameFactory = nullptr;
	//���ݎ��s���̃Q�[��ID
	GAME_FACTORY::GAME_ID CurrentGameId;
	//���Ɏ��s�\��̃Q�[��ID
	GAME_FACTORY::GAME_ID NextGameId;
	//���s���̃Q�[���I�u�W�F�N�g
	class GAME_BASE* GameBase = nullptr;
	//�؂�ւ����ʃI�u�W�F�N�g
	class TRANSITION_EFFECT* Transition = nullptr;
};
