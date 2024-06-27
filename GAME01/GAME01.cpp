#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME01.h"
namespace GAME01
{

	int GAME::create()
	{
		State = TITLE;

		//サウンド
		gekihaSnd = loadSound("..\\main\\assets\\game01\\wap.wav");
		playSnd = loadSound("..\\main\\assets\\game01\\play.wav");
		 overSnd = loadSound("..\\main\\assets\\game01\\over.wav");
		clearSnd = loadSound("..\\main\\assets\\game01\\clear.wav");


		//画像
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
		text("クリックゲーム", 700,540);
		fill(255,255,0);

		text("ENTERキーでメニューに戻る", 0, 1080);

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
		text("左クリックで左からの出てくる敵を倒せ",450,540);
		text("制限時間は５０秒", 450, 600);
		text("敵を5体倒すと難易度が１上がる。levelは１０まであります", 450, 660);


		text("左クリックでPLAY", 0, 1080);

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

		//制限時間

		timer -= delta;

		if (timer <= 0) {
			OverFlag = true;
		}

		
		//難易度を増加させるスコア

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
			print("　敵を右クリックで倒せ");

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

	//ゲームオーバー
	void GAME::Over() {
		clear(0, 0, 255);
		rectMode(CENTER);
		image(overImg, 960, 540);
		fill(255, 255, 0);
		text("　クリックで再プレイ", 0, 1080);
		if (isTrigger(MOUSE_LBUTTON)) {
			State = TITLE;
		}
	}

     //クリア
	void GAME::Clear() {
		clear(0, 0, 255);
		rectMode(CENTER);
		image(clearImg, 960, 540);
		fill(255, 255, 0);
		textSize(50);
		text("　クリックで再プレイ",0,1080);
		if (isTrigger(MOUSE_LBUTTON)) {
			State = TITLE;
		}
	}


}




