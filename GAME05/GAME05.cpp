#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME05.h"
namespace GAME05
{
	int GAME::create()
	{
		State = TITLE;
		KizaruImg = loadImage("..\\main\\assets\\game05\\kizaru.png");
		PunchImg = loadImage("..\\main\\assets\\game05\\punch.png");
		LuffyImg = loadImage("..\\main\\assets\\game05\\luffy.png");
		HitImg = loadImage("..\\main\\assets\\game05\\punch2.png");
		TamaImg = loadImage("..\\main\\assets\\game05\\tama.png");
		EnelImg = loadImage("..\\main\\assets\\game05\\enel.png");
		BackImg = loadImage("..\\main\\assets\\game05\\back.png");
		GetSnd = loadSound("..\\main\\assets\\game05\\get.wav");
		BgmSnd = loadSound("..\\main\\assets\\game05\\bgm.wav");
		OverSnd = loadSound("..\\main\\assets\\game05\\over.wav");
		PunchSnd = loadSound("..\\main\\assets\\game05\\ouda.wav");
		LuckySnd = loadSound("..\\main\\assets\\game05\\lucky.wav");
		ClearSnd = loadSound("..\\main\\assets\\game05\\clear.wav");
		LGClearSnd = loadSound("..\\main\\assets\\game05\\clear2.wav");
		LgSnd = loadSound("..\\main\\assets\\game05\\lg.wav");
		FinishSnd = loadSound("..\\main\\assets\\game05\\finish.wav");
		AttackSnd = loadSound("..\\main\\assets\\game05\\attack.wav");
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
		else if (State == LUCKY)Lucky();
		else if (State == LUCKYGAME)LuckyGame();
		else if (State == CLEAR)Clear();
		else if (State == BCLEAR)BClear();
		else if (State == FINISH)Finish();
		else if (State == OVER)Over();
		/*
		textSize(50);
		fill(255, 255, 0);
		text("GAME05", 0, 100);
		*/
	}

	void GAME::Title()
	{
		clear(60, 60, 60);
		fill(255, 255, 0);
		textSize(90);
		text("赤文字のポイントをピッタリ取ったらクリア", 50, 200);
		textSize(100);
		text("～操作説明～", 630, 400);
		text("A:左移動", 500, 600);
		text("D:右移動", 970, 600);
		text("W:上移動", 500, 800);
		text("S:下移動", 970, 800);
		text("左クリックで遊び方", 500, 1000);
		ShowCursor(0);
		if (isTrigger(MOUSE_LBUTTON)) {
			ShowCursor(0);
			State = RULE;
			return;
		}
		fill(255);
		textSize(50);
		text("ENTERキーでメニューに戻る", 0, 1080);
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}

	void GAME::Rule() {
		clear(60);
		fill(255, 255, 0);
		textSize(50);
		text("～遊び方～", 800, 50);
		textSize(80);
		text("左から敵がランダムに出てくる", 270, 150);
		text("下に書いてあるポイントの範囲内で", 270, 280);
		text("敵に触れたらそのポイント分ゲット！", 270, 370);
		text("右端は2～10Ptをランダムでゲットできる", 270, 520);
		text("赤文字のポイントをカウント以内に", 270, 670);
		text("ゲットできたらゲームクリア", 270, 800);
		text("カウントが0になったら、ゲームオーバー", 270, 890);
		text("左クリックでゲームスタート", 270, 1030);
		if (isTrigger(MOUSE_LBUTTON)) {
			Init();
			playLoopSound(BgmSnd);
			ShowCursor(0);
			State = PLAY;
			return;
		}

		if (isTrigger(KEY_B)) {
			playSound(LuckySnd);
			State = LUCKY;
			return;
		}
	}

	void GAME::Init()
	{
		PPx = width / 2;
		PPy = height / 2;
		PVx = 10.0f;
		PVy = 13.0f;
		PMx = 140.0f;
		PMy = 175.0f;
		PhalfW = 20.0f;
		PhalfH = 20.0f;

		EPx = -10;
		EPy = 150.0f;
		EVx = 30.0f;
		EVy = 10.0f;
		EMx = 140.0f;
		EhalfW = 20.0f;
		EhalfH = 20.0f;
		EHp = 1;

		GPR = 50;
		GPRx = 320;
		GPRy = 1080;

		GPY = 30;
		GPYx = 640;
		GPYy = 1080;

		GPB = 10;
		GPBx = 960;
		GPBy = 1080;

		GPG = 5;
		GPGx = 1280;
		GPGy = 1080;

		GPP = 1;
		GPPx = 1600;
		GPPy = 1080;

		GPr = random() % 9 + 2.0f;
		GPrx = 1920;
		GPry = 1080;

		Point = 0;

		CountDown = 2500;

		ClearPoint = random() % 100 + 1.0f;

		LuckyNo = random() % 5 + 1.0f;

		PointFlag = false;

		StageCount = 0;
	}

	void GAME::Init2()
	{
		Px = width / 2;
		Py = 930;
		halfW = 100;
		halfH = 200;
		Mx = 120;
		Vx = 10;
		HP = 50;
		MaxHp = HP;
		//プレイヤーの弾
		PBPx = Px;
		PBPy = Py;
		PBVy = -15;
		PBHp = 0;
		PBhalfW = 10;
		PBhalfH = 20;
		PBOfstY = -110;

		EPx = 100;
		EPy = 250;
		EhalfW = 100;
		EhalfH = 100;
		EVx = 15.0f;
		EHP = 500;

		//敵の弾
		EBPx = EPx;
		EBPy = EPy;
		EBVy = 30;
		EBHp = 0;
		EBhalfW = 10;
		EBhalfH = 20;
		OfstY = -110;
		
		HpX = 1600;
		HpY = 1060;

		EHpX = 970;
		EHpY = 80;
		EMaxHp = EHP;

		EhpGaugeOfsY = -180;

		EHpWarning = EHP * 0.3f;
		EHpDenger = EHP * 0.1f;

		HpWarning = EHP * 0.03f;
		HpDenger = EHP * 0.01f;

		img = PunchImg;

		CountDown = 1500;

		EHitFlag = false;

		PHitFlag = false;
	}

	void GAME::Play()
	{
		clear(200);
		if (isPress(KEY_D)) { PPx += PVx; }
		if (isPress(KEY_A)) { PPx += -PVx; }
		if (isPress(KEY_S)) { PPy += PVy; }
		if (isPress(KEY_W)) { PPy += -PVy; }

		if (PPx < PMx) {
			PPx = PMx;
		}
		if (PPx > width - PMx) {
			PPx = width - PMx;
		}
		if (PPy < PMy) {
			PPy = PMy;
		}
		if (PPy > height - PMy) {
			PPy = height - PMy;
		}

		EPx += EVx;
		if (EPx > 1980) {
			EPx = -10;
			EPy = random() % 780 + 150.0f;
		}

		if (EPx > width){
			PointFlag = false;
		}
		//各ポイントの範囲と獲得ポイント
		if (PointFlag == false) {
			if (collision() && EPx < GPRx && PPx < GPRx){
				playSound(GetSnd);
				Point += GPR;
				PointFlag = true;
			}
			if(collision() && EPx < GPYx && EPx > GPRx && PPx < GPYx && PPx > GPRx){
				playSound(GetSnd);
				Point += GPY;
				PointFlag = true;
			}
			if (collision() && EPx < GPBx && EPx > GPYx && PPx < GPBx && PPx > GPYx){
				playSound(GetSnd);
				Point += GPB;
				PointFlag = true;
			}
			if (collision() && EPx < GPGx && EPx > GPBx && PPx < GPGx && PPx > GPBx) {
				playSound(GetSnd);
				Point += GPG;
				PointFlag = true;
			}
			if (collision() && EPx < GPPx && EPx > GPGx && PPx < GPPx && PPx > GPGx) {
				playSound(GetSnd);
				Point += GPP;
				PointFlag = true;
			}
			if (collision() && EPx < GPrx && EPx > GPPx && PPx < GPrx && PPx > GPPx) {
				playSound(GetSnd);
				Point += GPr;
				PointFlag = true;
			}
		}
		//クリア、ゲームオーバー条件
		if (Point == ClearPoint && CountDown > 0 && LuckyNo != 1) {
			stopSound(GetSnd);
			stopSound(BgmSnd);
			playSound(ClearSnd);
			State = CLEAR;
		}
		if (Point == ClearPoint && CountDown > 0 && LuckyNo == 1) {
			stopSound(BgmSnd);
			stopSound(GetSnd);
			stopSound(ClearSnd);
			playSound(LuckySnd);
			ShowCursor(0);
			State = LUCKY;
		}
		if (Point > ClearPoint || CountDown <= 0) {
			stopSound(BgmSnd);
			stopSound(GetSnd);
			playSound(OverSnd);
			State = OVER;
		}
		//描画
		draw();

		if (CountDown > 0) {
			fill(0);
			CountDown -= 1.0f;
			textSize(100);
			text((let)CountDown, 0, 300);
		}

		if (isTrigger(KEY_R)) {
			stopSound(BgmSnd);
			State = RULE;
		}
	}

	void GAME::Lucky() {
		clear(255, 255, 88);
		fill(0);
		textSize(100);
		text("ラッキーゲーム！", 600, 140);
		text("～操作方法～", 650, 240);
		text("A:左移動", 750, 340);
		text("D:右移動", 750, 440);
		text("左クリックで弾発射", 400, 540);
		text("左クリックでゲーム画面に移行", 300, 740);
		if (isTrigger(MOUSE_LBUTTON)) {
			Init2();
			playLoopSound(LgSnd);
			State = LUCKYGAME;
			return;
		}
	}

	void GAME::LuckyGame() {
		if (isPress(KEY_D)) {
			Px += Vx;
		}
		if (isPress(KEY_A)) {
			Px += -Vx;
		}
		if (Px < Mx) {
			Px = Mx;
		}
		if (Px > width - Mx) {
			Px = width - Mx;
		}
		//パンチ
		if (isTrigger(MOUSE_LBUTTON)) {
			if (PBHp == 0) {
				PBHp = 1;
				PBPx = Px;
				PBPy = Py + PBOfstY;
			}
		}
		if (PBHp > 0) {
			PBPy += PBVy;
			if (PBPy < -PBH) {
				PBHp = 0;
			}
		}
		//敵の弾発射
		if (EBHp == 0) {
			EBPx = EPx;
			EBPy = EPy + EBOfstY;
			EBHp = 1;
		}
		if (EBHp > 0) {
			EBPy += EBVy;
			if (EBPy > height + EBhalfH) {
				EBHp = 0;
			}
		}

		//敵の移動
		EPx += EVx;
		if (EPx < EhalfW ||
			EPx > width - EhalfW) {
			EVx = -EVx;
		}
		
		if (PBHp == 0) {
			EHitFlag = false;
		}

		if (EHitFlag == false) {
			if (collision2()) {
				playSound(PunchSnd);
				img = HitImg;
				EHP -= 50;
				EHitFlag = true;
			}
		}
		else {
			img = PunchImg;
		}

		if (EBHp <= 0) {
			PHitFlag = false;
		}

		if (PHitFlag == false) {
			if (collision3()) {
				playSound(AttackSnd);
				HP -= 5;
				PHitFlag = true;
			}
		}

		if (EHP <= 0) {
			stopSound(LgSnd);
			stopSound(PunchSnd);
			playSound(LGClearSnd);
			State = BCLEAR;
		}

		if (HP <= 0 || CountDown <= 0) {
			stopSound(LgSnd);
			stopSound(PunchSnd);
			playSound(FinishSnd);
			State = FINISH;
		}
		//描画
		draw2();

		if (CountDown > 0) {
			fill(0);
			CountDown -= 1.0f;
			textSize(100);
			text((let)CountDown, 0, 300);
		}
	}

	void GAME::Clear()
	{
		clear(200, 0, 0);
		image(KizaruImg, EPx = width / 2, EPy = height / 2);
		fill(255);
		textSize(250);
		text("Game Clear", 400, 300);
		if (isTrigger(MOUSE_LBUTTON)) {
			stopSound(ClearSnd);
			State = TITLE;
			return;
		}
		fill(255);
		textSize(50);
		text("左クリックでタイトルに戻る", 0, 1080);
	}

	void GAME::BClear()
	{
		clear(255, 255, 88);
		image(LuffyImg, width / 2, height / 2);
		fill(255, 0, 0);
		textSize(250);
		text("LuckyGame Clear", 50, 300);
		if (isTrigger(MOUSE_LBUTTON)) {
			stopSound(LGClearSnd);
			State = TITLE;
			return;
		}
		fill(255);
		textSize(50);
		text("左クリックでタイトルに戻る", 0, 1080);

	}

	void GAME::Finish()
	{
		clear(0, 200, 255);
		image(LuffyImg, 600, height / 2);
		image(EnelImg, 1200, height / 2);
		fill(255);
		textSize(250);
		text("FINISH!", 500, 300);
		if (isTrigger(MOUSE_LBUTTON)) {
			State = TITLE;
			return;
		}
		fill(255);
		textSize(50);
		text("左クリックでタイトルに戻る", 0, 1080);
	}

	void GAME::Over()
	{
		clear(0);
		image(EnelImg, EPx = width / 2, EPy = height / 2);
		fill(255);
		textSize(200);
		text("Game Over", 500, 300);
		if (isTrigger(MOUSE_LBUTTON)) {
			stopSound(OverSnd);
			State = TITLE;
			return;
		}
		fill(255);
		textSize(50);
		text("左クリックでタイトルに戻る", 0, 1080);
	}

	int GAME::collision()
	{
		if (EHp > 0) {
			float cRight = PPx + PhalfW;
			float cLeft = PPx - PhalfW;
			float cTop = PPy - PhalfH;
			float cBottom = PPy + PhalfH;

			float eRight = EPx + EhalfW;
			float eLeft = EPx - EhalfW;
			float eTop = EPy - EhalfH;
			float eBottom = EPy + EhalfH;

			if (cRight < eLeft || eRight < cLeft ||
				eBottom < cTop || cBottom < eTop ) {
				return 0;
			}
			else {
				return 1;
			}
		}
		return 0;
	}

	int GAME::collision2()
	{
		if (PBHp > 0) {
			float PbRight = PBPx + PBhalfW;
			float PbLeft = PBPx - PBhalfW;
			float PbTop = PBPy - PBhalfH;
			float PbBottom = PBPy + PBhalfH;

			float eRight = EPx + EhalfW;
			float eLeft = EPx - EhalfW;
			float eTop = EPy - EhalfH;
			float eBottom = EPy + EhalfH;

			if (PbRight < eLeft || eRight < PbLeft ||
				eBottom < PbTop || PbBottom < eTop) {
				return 0;
			}
			else {
				return 1;
			}
		}
		return 0;
	}

	int GAME::collision3()
	{
		if (EBHp > 0) {
			float EbRight = EBPx + EBhalfW;
			float EbLeft = EBPx - EBhalfW;
			float EbTop = EBPy - EBhalfH;
			float EbBottom = EBPy + EBhalfH;

			float lRight = Px + halfW;
			float lLeft = Px - halfW;
			float lTop = Py - halfH;
			float lBottom = Py + halfH;

			if (EbRight < lLeft || lRight < EbLeft ||
				lBottom < EbTop || EbBottom < lTop) {
				return 0;
			}
			else {
				return 1;
			}
		}
		return 0;
	}

	void GAME::hpGauge()
	{
		strokeWeight(0);
		fill(128);
		rect(EHpX, EHpY + hpGaugeOfsY, EMaxHp * 2, 30);
		if (EHP > EHpWarning) {
			fill(0, 255, 0);
		}
		else if (EHP > EHpDenger) {
			fill(255, 255, 0);
		}
		else {
			fill(255, 0, 0);
		}
		rect(EHpX, EHpY + hpGaugeOfsY, EHP * 2, 30);
	}

	void GAME::hpGauge2()
	{
		strokeWeight(0);
		fill(128);
		rect(HpX, HpY, MaxHp * 10, 30);
		if (HP > HpWarning) {
			fill(0, 255, 0);
		}
		else if (HP > HpDenger) {
			fill(255, 255, 0);
		}
		else {
			fill(255, 0, 0);
		}
		rect(HpX, HpY, HP * 10, 30);
	}

	void GAME::draw()
	{
		clear();
		rectMode(CORNER);
		image(BackImg, 0, 0);

		strokeWeight(15);
		stroke(255, 0, 0);
		line(GPRx, 0, GPRx, GPRy);

		strokeWeight(15);
		stroke(255, 255, 0);
		line(GPYx, 0, GPYx, GPYy); 
		
		strokeWeight(15);
		stroke(0, 255, 255);
		line(GPBx, 0, GPBx, GPBy);

		strokeWeight(15);
		stroke(0, 180, 0);
		line(GPGx, 0, GPGx, GPGy);

		strokeWeight(15);
		stroke(255, 0, 255);
		line(GPPx, 0, GPPx, GPPy);

		rectMode(CENTER);
		image(KizaruImg, PPx, PPy);

		rectMode(CENTER);
		image(EnelImg, EPx, EPy);

		fill(255, 0 ,0);
		textSize(75);
		text((let)GPR + "Pt", 80, 1080);

		fill(255, 255, 0);
		textSize(75);
		text((let)GPY + "Pt", 400, 1080);

		fill(0, 255, 255);
		textSize(75);
		text((let)GPB + "Pt", 720, 1080);

		fill(0, 180, 0);
		textSize(75);
		text((let)GPG + "Pt", 1060, 1080);

		fill(255, 0, 255);
		textSize(75);
		text((let)GPP + "Pt", 1380, 1080);

		fill(0);
		textSize(75);
		text((let)GPr + "Pt", 1700, 1080);

		fill(0);
		textSize(100);
		text((let)Point + "Pt", 0, 100);

		fill(255, 0, 50);
		textSize(100);
		text((let)ClearPoint + "Pt", 0, 200);


		//当たり判定エリア
		fill(255, 255, 255, 128);
		rect(PPx, PPy, PhalfW * 1.5f, PhalfH * 1.5f);
		rect(EPx, EPy, EhalfW * 1.5f, EhalfH * 1.5f);
	}

	void GAME::draw2()
	{
		clear();
		rectMode(CORNER);
		image(BackImg, 0, 0);

		rectMode(CENTER);
		image(EnelImg, EPx, EPy);

		rectMode(CENTER);
		image(LuffyImg, Px, Py);

		fill(255);
		if (PBHp > 0) {
			image(PunchImg, PBPx, PBPy);
		}

		if (EBHp > 0) {
			image(TamaImg, EBPx, EBPy);
		}

		if (collision2()) {
			image(HitImg, PBPx, PBPy);
		}

		hpGauge();

		hpGauge2();

		//当たり判定エリア
		fill(255, 255, 255, 128);
		rect(Px, Py, halfW, halfH);
		rect(EPx, EPy, EhalfW * 1.5f, EhalfH * 1.5f);
	}
}
