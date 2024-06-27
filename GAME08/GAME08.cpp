#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME08.h"
namespace GAME08
{
	int GAME::create()
	{
		TitleBackImg = loadImage("..\\main\\assets\\game08\\TitleBack.png");
		TitleImg = loadImage("..\\main\\assets\\game08\\Title.png");
		TitleItemImg = loadImage("..\\main\\assets\\game08\\TitleItemImg.png");

		ConfigBackImg = loadImage("..\\main\\assets\\game08\\ConfigBack.png");
		KumoPurpleImg = loadImage("..\\main\\assets\\game08\\KumoPurple.png");
		ConfigsImg = loadImage("..\\main\\assets\\game08\\Configs.png");

		PlayBackImg = loadImage("..\\main\\assets\\game08\\PlayBack.png");

		Item.Img[0] = loadImage("..\\main\\assets\\game08\\Orange.png");
		Item.Img[1] = loadImage("..\\main\\assets\\game08\\Yashi.png");
		Item.Img[2] = loadImage("..\\main\\assets\\game08\\Nashi.png");
		Item.Img[3] = loadImage("..\\main\\assets\\game08\\Sakuranbo.png");
		Item.Img[4] = loadImage("..\\main\\assets\\game08\\Ringo.png");
		Item.Img[5] = loadImage("..\\main\\assets\\game08\\Momo.png");

		Player.Img[0] = loadImage("..\\main\\assets\\game08\\AnimalL.png");
		Player.Img[1] = loadImage("..\\main\\assets\\game08\\AnimalR.png");

		KumoPinkImg = loadImage("..\\main\\assets\\game08\\KumoPink.png");
		FPinkImg = loadImage("..\\main\\assets\\game08\\FPink.png");

		SImg = loadImage("..\\main\\assets\\game08\\S.png");
		AImg = loadImage("..\\main\\assets\\game08\\A.png");
		BImg = loadImage("..\\main\\assets\\game08\\B.png");
		CImg = loadImage("..\\main\\assets\\game08\\C.png");
		

		ClearBackImg = loadImage("..\\main\\assets\\game08\\ClearBack.png");
		GClearImg = loadImage("..\\main\\assets\\game08\\GClear.png");


		OverBackImg = loadImage("..\\main\\assets\\game08\\OverBack.png");
		GOverImg = loadImage("..\\main\\assets\\game08\\GOver.png");
		KumoBlueImg = loadImage("..\\main\\assets\\game08\\KumoBlue.png");



		return 0;
	}

	void GAME::destroy()
	{
		
	}

	void GAME::proc()
	{
		clear(0, 0, 64);

		

		if (STATE == TITLE) { title(); }
		else if (STATE == PLAY) { play(); }
		else if (STATE == RESULT) { result(); } //確定

		

		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		} //いじらない
	}

	void GAME::title() {

		draw();
		rectMode(CENTER);
		image(TitleBackImg, width / 2, height / 2);
		image(TitleImg, width / 2, height / 2);
		image(TitleItemImg, width / 2, height / 2);
		
		if (isTrigger (KEY_A)) {
			IsConfig = true;
		}
		if (isTrigger(KEY_F)) {
			IsConfig = false;
		}
		if (IsConfig) {
			image(ConfigBackImg, width / 2, height / 2);
			image(ConfigsImg, width / 2, height / 2);
			image(KumoPurpleImg, width / 2, height / 2);
			if (isTrigger(KEY_SPACE)) {
				IsConfig = false;
			}

			
		}

		if (isTrigger(KEY_SPACE)) {
			init();
			STATE = PLAY;
		}

	}

	void GAME::init() {
		//Player
		Player.Px = width / 2;
		Player.Py = height / 2 + 365;
		Player.Speed = 0.5f; 


		//Item
		Item.Px = random(LE, RE);
		Item.Py = 0;
		Item.FallSpeed = 8.0f;


		//square
		ap.x = Player.Px; ap.y = Player.Py; ap.w = 200; ap.h = 250;
		bc.x = Item.Px;
		bc.y = Item.Py; bc.w = 40; bc.h = 40;

		//ItemSpeed
		ap.Speed = Player.Speed;

		
		Player.Life = 100;
		Item.Hp = 10;


		Ps.Score = 0;
		Is.Score = 5;

		//当たり判定
		ap.left = ap.x - ap.w / 2;
		ap.right = ap.x + ap.w / 2;
		ap.top = ap.y - ap.h / 2;
		ap.bottom = ap.y + ap.h / 2;

		bc.left = bc.x - bc.w / 2;
		bc.right = bc.x + bc.w / 2;
		bc.top = bc.y - bc.h / 2;
		bc.bottom = bc.y + bc.h / 2;

	}

	void GAME::play() {
		//if (isTrigger(KEY_SPACE)) { STATE = RESULT; }
		draw();
		if (isTrigger(KEY_F)) {
			init();
			STATE = TITLE;
		}


		

		if (isPress(KEY_A)) {
			Player.Px -= Player.Speed;
			ap.x = Player.Px; 
		} //左
		if (isPress(KEY_D)) {
			Player.Px += Player.Speed;
			ap.x = Player.Px;
		} //右


		//Item
 		Item.Py += Item.FallSpeed;
		bc.y = Item.Py;


		//移動制限
		if (Player.Px < LE ) {
			Player.Px = LE;
		}
		if (Player.Px > RE) {
			Player.Px = RE;
		}

		ap.x = Player.Px;

		rect(bc.x, bc.y, bc.w, bc.h);
		rect(ap.x, ap.y, ap.w, ap.h);

		//当たり判定
		ap.left = ap.x - ap.w / 2;
		ap.right = ap.x + ap.w / 2;
		ap.top = ap.y - ap.h / 2;
		ap.bottom = ap.y + ap.h / 2;

		bc.left = bc.x - bc.w / 2;
		bc.right = bc.x + bc.w / 2;
		bc.top = bc.y - bc.h / 2;
		bc.bottom = bc.y + bc.h / 2;



		if (Item.Py >= 1080) { //したについたら
			Player.Life -= Item.Hp;
			Item.Object = random() % 6;
			Item.Px = random(LE,RE);
			bc.x = Item.Px;
			Item.Py = 0;
			bc.y = 0;
		}

		//プレイヤーと当たったら

		if (ap.right < bc.left || bc.right < ap.left || 
			ap.bottom < bc.top || bc.bottom < ap.top) { 
		}
		else {
			Ps.Score += Is.Score;
			Item.Object = random() % 6;
			Item.Px = random(LE, RE);
			bc.x = Item.Px;
			Item.Py = 0;
			bc.y = 0;
		}

		if (Ps.Score == 100 && Player.Life > 0) {
			STATE = RESULT;
		}
		else {
			if (Player.Life == 0)
				STATE = RESULT;
		}

	}
	
	void GAME::draw() {
		clear(180);

		if (STATE == TITLE) {
			rectMode(CENTER);
			clear(250, 250, 250);
			image(TitleBackImg, width / 2, height / 2);
			image(TitleImg, width / 2, height / 2);
			image(TitleItemImg, width / 2, height / 2);
			image(ConfigBackImg, width / 2, height / 2);
			image(ConfigsImg, width / 2, height / 2);
			image(KumoPurpleImg, width / 2, height / 2);
		}

		if (STATE == PLAY) {
			clear(128,128,128);
			image(PlayBackImg, width / 2, height / 2);
			image(Item.Img[Item.Object], Item.Px, Item.Py, Item.FallSpeed);

			if (isPress(KEY_A)) {
				image(Player.Img[0], Player.Px, Player.Py);
			}
			else if (isPress(KEY_D)) {
				image(Player.Img[1], Player.Px, Player.Py);
			}


			image(KumoPinkImg, width / 2, height / 2);
			image(FPinkImg, width / 2, height / 2 + 425);

			rectMode(CORNER);
			fill(255);
			rect(Player.Px - 50, Player.Py - 200, 100, 20);
			if (Player.Life < 50) {
			fill(255, 120, 203);
			}
			else {
				fill(215, 160, 227);
			}
			rect(Player.Px-50, Player.Py-200, Player.Life, 20);
			rectMode(CENTER);


			rectMode(CORNER);
			fill(255);
			rect(width / 2 + 150, 20, 100, 50);
			rectMode(CENTER);
			if (Ps.Score <= 25) {
				image(CImg, width / 2 - 250, 0, 0, 1.75f);
			fill(178,207,242);
			}
			else if (Ps.Score <= 50) {
				image(BImg, width / 2 - 250, 0, 0, 1.75f);
				fill(215, 160, 227);
			}
			else if (Ps.Score <= 75) {
				image(AImg, width / 2 - 250, 0, 0, 1.75f);
				fill(255, 196, 218);
			}
			else {
				image(SImg, width / 2 - 250, 0, 0, 1.75f);
				fill(255, 120, 203);

			}
			rectMode(CORNER);
			rect(width / 2 + 150, 20, Ps.Score, 50);
			rectMode(CENTER);

			if (ap.right < bc.left || bc.right < ap.left ||
				ap.bottom < bc.top || bc.bottom < ap.top) {
				fill(0, 0, 0, 0);

			}
			else {
				fill(0, 0, 0, 0);

			}
		}
		

		if (STATE == RESULT) {
			clear(250, 250, 250);
			imageColor(255);
			if (Ps.Score = 100 && Player.Life > 0) {
			image(ClearBackImg, width / 2, height / 2);
			image(GClearImg, width / 2, height / 2);
			image(KumoPinkImg, width / 2, height / 2);
				
			}
			else {
				if (Player.Life == 0)
				image(OverBackImg, width / 2, height / 2);			
				image(GOverImg, width / 2, height / 2);
				image(KumoBlueImg, width / 2, height / 2);
			}
		}

	}

	void GAME::result() {
		clear(0, 0, 255);
		draw();
		if (Ps.Score = 100 && Player.Life > 0) {

		}
		else {
			if (Player.Life == 0) {
			}
		}

		if (isTrigger(KEY_SPACE)) {
			init();
			STATE = PLAY;
		}

		if (isTrigger(KEY_F)) {
			STATE = TITLE;
		}

	}
	

}
