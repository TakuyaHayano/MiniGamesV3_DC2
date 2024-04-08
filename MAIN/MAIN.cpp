#include "../../libOne/inc/libOne.h"
#include "GAME_BASE.h"
#include "TRANSITION_EFFECT.h"
#include "MAIN.h"

MAIN::MAIN()
{
	window(1920, 1080, full);
	//�Q�[���t�@�N�g������
	GameFactory = new GAME_FACTORY(this);
	//�X�^�[�g���̃Q�[��(���j���[)����
	CurrentGameId = NextGameId = GAME_FACTORY::MENU_ID;
	GameBase = GameFactory->create(CurrentGameId);
	GameBase->create();
	//�؂�ւ����ʃI�u�W�F�N�g
	Transition = new TRANSITION_EFFECT;
}

MAIN::~MAIN()
{
	delete GameFactory;
	GameBase->destroy();
	delete GameBase;
	delete Transition;
}

void MAIN::run()
{
	initDeltaTime();
	//���C�����[�v
	while (notQuit) {
		//���C���v���V�[�W���[
		setDeltaTime();
		GameBase->proc();
		Transition->proc();
		//GameBase->proc()���ŃQ�[����؂�ւ��Ă��Ȃ�
		if (CurrentGameId == NextGameId) {
			continue;
		}
		//GameBase->proc()���ŃQ�[����؂�ւ����������ɗ���
		Transition->outStart();
		//��ʐ؂�ւ����ʏI����A���̃Q�[���ɐ؂�ւ�
		if (Transition->outEndFlag()) {
			//���݂̃Q�[�������
			GameBase->destroy();
			delete GameBase;
			//���̃Q�[���𐶐�
			CurrentGameId = NextGameId;
			GameBase = GameFactory->create(CurrentGameId);
			GameBase->create();
			//�؂�ւ����ʃX�^�[�g
			Transition->inStart();
		}
	}
}

//MAIN�I�u�W�F�N�g�J�n
void gmain()
{
	MAIN main;
	main.run();
}
