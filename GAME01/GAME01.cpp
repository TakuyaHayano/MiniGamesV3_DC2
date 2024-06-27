#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME01.h"
namespace GAME01
{

	int GAME::create()
	{
		State = TITLE;

		//�T�E���h
		gekihaSnd = loadSound("..\\main\\assets\\game01\\wap.wav");
		playSnd = loadSound("..\\main\\assets\\game01\\play.wav");
		 overSnd = loadSound("..\\main\\assets\\game01\\over.wav");
		clearSnd = loadSound("..\\main\\assets\\game01\\clear.wav");


		//�摜
		  bonImg = loadImage("..\\main\\assets\\game01\\teki.png");
		  haikeiImg = loadImage("..\\main\\assets\\game01\\haikei3.jpg");
		  clearImg = loadImage("..\\main\\assets\\game01\\clear.jpg");
		  overImg = loadImage("..\\main\\assets\\game01\\over.jpg");
		




		return 0;
	}

	void GAME::destroy()
	{

	}


	void GAME::proc()
	{
		if (State == TITLE)Title();
		else if (State == RULE)Rule();
		else if (State == PLAY)Play();
		else if (State == CLEAR)Clear();
		else if (State == OVER)Over();
	}


	void GAME::Title() {
		clear(0, 0, 64);

		rectMode(CENTER);
		image(haikeiImg,960,540);

		fill(255,200,0);
		textSize(50);
		text("�N���b�N�Q�[��", 700,540);
		fill(255,255,0);

		text("ENTER�L�[�Ń��j���[�ɖ߂�", 0, 1080);

		if (isTrigger(MOUSE_LBUTTON)) {
			Init();
			playSound(playSnd);
			State = RULE;
			return;
		}

		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}

	}
	void GAME::Rule() {
		clear(0, 0, 255);
		fill(255, 200, 0);
		textSize(50);
		text("���N���b�N�ō�����̏o�Ă���G��|��",450,540);
		text("�������Ԃ͂T�O�b", 450, 600);
		text("�G��5�̓|���Ɠ�Փx���P�オ��Blevel�͂P�O�܂ł���܂�", 450, 660);


		text("���N���b�N��PLAY", 0, 1080);

		if (isTrigger(MOUSE_LBUTTON)) {
			Init();
			playSound(playSnd);
			State = PLAY;
			return;
		}
	}


	void GAME::Init() {

		CR = 50;
		CY = -CR;
		CX = random() % 1000 + 500.0f;
		CVx = 500;

		score = 0;
		level = 1;
		nextLevelScore = 5;
		timer =50.0f;
		
		ClearFlag = false;
		OverFlag = false;
		
	}


	void GAME::Play() {

		//��������

		timer -= delta;

		if (timer <= 0) {
			OverFlag = true;
		}

		
		//��Փx�𑝉�������X�R�A

		if ( score >= nextLevelScore) {
			level++;
			nextLevelScore += 5;
			CVx *= 1.3f;        

			if (level >= 5) {
				ClearFlag = true;
			}
		}

		CX += CVx * delta;
		if (CX > width + CR) {
			CY = random() % 1000 + 100.0f;
			CX = -CR;
		}



		if ( isTrigger(MOUSE_LBUTTON)) {
			float dx = CX - mouseX;
			float dy = CY - mouseY;
			if (dx * dx + dy * dy < CR * CR) {
				score++;

				playSound(gekihaSnd);

				
				CY = rand() % 1000 + 100.0f;
				CX = -CR;
			}

			if (score >= 1) {   
				ClearFlag = true;

			}
		}

			clear(0, 0, 0);
		    rectMode(CENTER);
			image(bonImg, CX, CY);
			fill(255, 255, 255);


			print("Play");
			print("�@�G���E�N���b�N�œ|��");

			sprintf_s(scoreText, "Score: %d", score);
			print(scoreText);

			sprintf_s(levelText, "Level: %d", level);
			print(levelText);

			sprintf_s(timerText, "Time: %.1f", timer);
			print(timerText);
			
			 if (ClearFlag) {
				State = CLEAR;
				playSound(clearSnd);
			 }

			 if (OverFlag) {
				 State = OVER;
				 playSound(overSnd);
			 }

	}

	//�Q�[���I�[�o�[
	void GAME::Over() {
		clear(0, 0, 255);
		rectMode(CENTER);
		image(overImg, 960, 540);
		fill(255, 255, 0);
		text("�@�N���b�N�ōăv���C", 0, 1080);
		if (isTrigger(MOUSE_LBUTTON)) {
			State = TITLE;
		}
	}

     //�N���A
	void GAME::Clear() {
		clear(0, 0, 255);
		rectMode(CENTER);
		image(clearImg, 960, 540);
		fill(255, 255, 0);
		textSize(50);
		text("�@�N���b�N�ōăv���C",0,1080);
		if (isTrigger(MOUSE_LBUTTON)) {
			State = TITLE;
		}
	}


}




