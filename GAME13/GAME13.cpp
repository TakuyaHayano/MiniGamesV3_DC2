#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME13.h"

namespace GAME13
{
	
	const int PLAYER_SPEED = 10; // �v���C���[�̈ړ����x
	const int BULLET_SPEED = 12; // �e�̑��x
	const int MAX_BULLETS = 100000; // �����ɉ�ʂɕ\������e�̍ő吔
	const int ENEMY_SPEED = 13; // �G�̈ړ����x
	const int ENEMY_HEALTH = 115; // �G�̗̑�

	bool shooting = false; // �ˌ�
	int playerX = 640; // �v���C���[��X���W
	int playerY = 800; // �v���C���[��Y���W
	int bulletX[MAX_BULLETS]; // �e��X���W
	int bulletY[MAX_BULLETS]; // �e��Y���W
	int bulletCount = 0; // ���݂̒e�̐�
	
	int enemyX = 640; // �G��X���W
	int enemyY = 250; // �G��Y���W
	int enemyDirection = 1; // �G�̈ړ������i1: �E, -1: ���j
	int enemyHealth = ENEMY_HEALTH; // �G�̗̑�

	int GAME::create()
	{
		Img = loadImage("..\\main\\assets\\game13\\haikei.png");
		State = TITLE;
		return 0;
	}

	void GAME::destroy()
	{

	}

	void GAME::proc()
	{
		//�V�[���؂�ւ�
		if (State == TITLE) Title();
		else if (State == PLAY) Play();
		else if (State == CLEAR) Clear();
	}

	void GAME::Title()
	{
		clear(0, 0, 64);
		image(Img,0,0);
		textSize(50);
		fill(255, 255, 0);
		print("�N���b�N�ŃQ�[���X�^�[�g");
		fill(255);
		text("ENTER�L�[�Ń��j���[�ɖ߂�", 0, 1080);

		if (isTrigger(KEY_ENTER))
		{
			main()->backToMenu();
		}
		if (isTrigger(MOUSE_LBUTTON))
		{
			State = PLAY;
		}
		Init();
	}



	void GAME::Init()
	{
		// �Q�[���̊e�ϐ�������������
		
		playerX = 640;
		playerY = 800;
		bulletCount = 0;
		enemyX = 640;
		enemyY = 250;
		enemyDirection = 1;
		enemyHealth = ENEMY_HEALTH;
	}

	void GAME::Play()
	{
		clear(0, 0, 64);
		image(Img, 0, 0);
		textSize(50);
		fill(255, 255, 0);
		print("�X�y�[�X�Ŏˌ�");
		print("A�ō�");
		print("D�ŉE");
		fill(255);
		text("ENTER�L�[�Ń��j���[�ɖ߂�", 0, 1080);
		
		// �v���C���[�̕`��
		fill(255);
		rect(playerX - 25, playerY - 25, 50, 50);

		// �G�̕`��
		fill(175, 223, 228);
		circle(enemyX, enemyY, 50);

		// �G�̗̑̓Q�[�W�̕`��
		fill(0, 255, 0);
		rect(enemyX - 50, enemyY - 100, (enemyHealth * 100) / ENEMY_HEALTH, 10);

		// �v���C���[�̈ړ�
		if (isPress(KEY_D) && playerX < 1880) {
			playerX += PLAYER_SPEED;
		}
		if (isPress(KEY_A) && playerX > 25) {
			playerX -= PLAYER_SPEED;
		}

		// �X�y�[�X�L�[�������ꂽ��ˌ�
		if (isPress(KEY_SPACE))
		{
			shooting = true;
			bulletX[bulletCount] = playerX; // �v���C���[��X���W��
			bulletY[bulletCount] = playerY; // �v���C���[��Y���W��
			bulletCount++; // �e�̐��𑝂₷
			if (bulletCount >= MAX_BULLETS) // �e�̐����ő吔�ɒB������
				bulletCount = 0; // �e�̐������Z�b�g
		}

		// �ˌ����s���Ă���ꍇ�A�ˌ��̕`��
		for (int i = 0; i < bulletCount; i++)
		{
			fill(255);
			circle(bulletX[i], bulletY[i], 10); // �e�̕`��
			bulletY[i] -= BULLET_SPEED; // �e����Ɉړ�
		}

		// �G�̈ړ�
		enemyX += enemyDirection * ENEMY_SPEED;
		if (enemyX <= 50) // �G����ʍ��[�ɓ��B������
		{
			enemyDirection = 1; // �ړ��������E�ɐݒ�
		}
		else if (enemyX >= 1880) // �G����ʉE�[�ɓ��B������
		{
			enemyDirection = -1; // �ړ����������ɐݒ�
		}

		// �e�ƓG�̏Փ˔���
		for (int i = 0; i < bulletCount; i++)
		{
			if (sqrt(pow(bulletX[i] - enemyX, 2) + pow(bulletY[i] - enemyY, 2)) < 50)
			{
				// �e���G�ɓ���������G�̗̑͂����炷
				enemyHealth--;
				// ���������e����������
				bulletX[i] = bulletX[bulletCount - 1];
				bulletY[i] = bulletY[bulletCount - 1];
				bulletCount--;
				i--;
			}
		}

		// �G�̗̑͂�0�ȉ��ɂȂ�����
		if (enemyHealth <= 0)
		{
			// �N���A��ʈڍs
			State = CLEAR;
		}

		if (isTrigger(KEY_ENTER))
		{
			main()->backToMenu();
		}
	}

	void GAME::Clear()
	{
		clear(0, 0, 64);
		image(Img, 0, 0);
		textSize(50);
		fill(255, 255, 0);
		text("CLEAR!", 0, 100);
		fill(255);
		text("ENTER�L�[�Ń��j���[�ɖ߂�", 0, 1080);

		if (isTrigger(KEY_ENTER))
		{
			Init();
			State = TITLE;
		}
	}

}
