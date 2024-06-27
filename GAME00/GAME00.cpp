#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "../../libOne/inc/sound.h"
#include "../../libOne/inc/input.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/rand.h"
#include "GAME00.h"
namespace GAME00
{
	int GAME::create()
	{

		purinImg = loadImage("..\\main\\assets\\game00\\purin.png");
		onigiriImg = loadImage("..\\main\\assets\\game00\\onigiri.png");
		nikuImg = loadImage("..\\main\\assets\\game00\\niku.png");
		daifukuImg = loadImage("..\\main\\assets\\game00\\daifuku.png");
		monsterImg = loadImage("..\\main\\assets\\game00\\monster.png");
		hakaImg = loadImage("..\\main\\assets\\game00\\haka.png");
		daidokoroImg = loadImage("..\\main\\assets\\game00\\daidokoro.jpg");
		kusuriImg = loadImage("..\\main\\assets\\game00\\kusuri.png");
		syokujiSnd = loadSound("..\\main\\assets\\game00\\syokuji.wav");
		sibouSnd = loadSound("..\\main\\assets\\game00\\sibou.wav");
		bgmSnd = loadSound("..\\main\\assets\\game00\\bgm.wav");

		return 0;
	}

	void GAME::destroy()
	{

	}

	void GAME::proc()
	{
		if (State == TITLE)Title();
		else if (State == PLAY)Play();
		else if (State == PLAY2)Play2();
		else if (State == PLAY3)Play3();
		else if (State == CLEAR)Clear();
	}
	void GAME::Title()
	{

		clear(0, 0, 128);

		fill(255, 255, 255);
		textSize(80);
		print("クリックでゲームスタート");
		print("Enterでメニューに戻る");
		print("プレイヤーはゴキブリ");
		print("殺虫剤を取ると大ダメージ");
		print("操作方法");
		print("Wで上に動く");
		print("Sで下に動く");
		print("Dで右に動く");
		print("Aで左に動く");

		fill(240);
		textSize(50);
		textMode(BCENTER);
		text("ハラヘッタ",780,520);
		image(monsterImg, 780, 540);

		if (isTrigger(MOUSE_LBUTTON)) {
			Init();
			State = PLAY;
			return;
		}
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}
	void GAME::Init()
	{
		Score = 0;
		dame = 0;

		HpMax = 2500;
		monsterHP = 2500;
		monsterX = random() % 1520;
		monsterY = random() % 900;
		monsterW = 100;
		monsterH = 100;
		
		DaifukuX = random() % 1520;
		DaifukuY = random() % 900;
		DaifukuW = 100;
		DaifukuH = 100;

		NikuX = random() % 1520;
		NikuY = random() % 900;
		NikuW = 100;
		NikuH = 100;

		PurinX = random() % 1520;
		PurinY = random() % 900;
		PurinW = 100;
		PurinH = 100;

		OnigiriX = random() % 1520;
		OnigiriY = random() % 900;
		OnigiriW = 100;
		OnigiriH = 100;

		kusuriX = random() % 1520;
		kusuriY = random() % 900;
		kusuriW = 100;
		kusuriH = 100;

		kusuri2X = random() % 1520;
		kusuri2Y = random() % 900;
		kusuri2W = 100;
		kusuri2H = 100;

		kusuri3X = random() % 1520;
		kusuri3Y = random() % 900;
		kusuri3W = 100;
		kusuri3H = 100;

		kusuri4X = random() % 1520;
		kusuri4Y = random() % 900;
		kusuri4W = 100;
		kusuri4H = 100;

		hakaX = 540;
		hakaY = 540;

		playSound(bgmSnd);
	}
	int GAME::Nikucollision() {
		if (monsterHP > 0) {
			float NikuLeft = NikuX;
			float NikuRight = NikuX + NikuW;
			float NikuTop = NikuY;
			float NikuBottom = NikuY + NikuH;
			float MonsterLeft = monsterX;
			float MonsterRight = monsterX + monsterW;
			float MonsterTop = monsterY;
			float MonsterBottom = monsterY + monsterH;

			if (NikuRight < MonsterLeft ||
				MonsterRight < NikuLeft ||
				MonsterBottom < NikuTop ||
				NikuBottom < MonsterTop) {
				return 0;
			}
			else {
				return 1;
			}
		}
		return 0;
	}
	int GAME::Onigiricollision() {
		if (monsterHP > 0) {
			float OnigiriLeft = OnigiriX;
			float OnigiriRight = OnigiriX + OnigiriW;
			float OnigiriTop = OnigiriY;
			float OnigiriBottom = OnigiriY + OnigiriH;
			float MonsterLeft = monsterX;
			float MonsterRight = monsterX + monsterW;
			float MonsterTop = monsterY;
			float MonsterBottom = monsterY + monsterH;

			if (OnigiriRight < MonsterLeft ||
				MonsterRight < OnigiriLeft ||
				MonsterBottom < OnigiriTop ||
				OnigiriBottom < MonsterTop) {
				return 0;
			}
			else {
				return 1;
			}
		}
		return 0;
	}
	int GAME::Purincollision() {
		if (monsterHP > 0) {
			float PurinLeft = PurinX;
			float PurinRight = PurinX + PurinW;
			float PurinTop = PurinY;
			float PurinBottom = PurinY + PurinH;
			float MonsterLeft = monsterX;
			float MonsterRight = monsterX + monsterW;
			float MonsterTop = monsterY;
			float MonsterBottom = monsterY + monsterH;

			if (PurinRight < MonsterLeft ||
				MonsterRight < PurinLeft ||
				MonsterBottom < PurinTop ||
				PurinBottom < MonsterTop) {
				return 0;
			}
			else {
				return 1;
			}
		}
		return 0;
	}
	int GAME::Daifukucollision() {
		if (monsterHP > 0) {
			float DaifukuLeft = DaifukuX;
			float DaifukuRight = DaifukuX + DaifukuW;
			float DaifukuTop = DaifukuY;
			float DaifukuBottom = DaifukuY + DaifukuH;
			float MonsterLeft = monsterX;
			float MonsterRight = monsterX + monsterW;
			float MonsterTop = monsterY;
			float MonsterBottom = monsterY + monsterH;

			if (DaifukuRight < MonsterLeft ||
				MonsterRight < DaifukuLeft ||
				MonsterBottom < DaifukuTop ||
				DaifukuBottom < MonsterTop) {
				return 0;
			}
			else {
				return 1;
			}
		}
		return 0;
	}
	int GAME::Kusuricollision() {
		if (monsterHP > 0) {
			float KusuriLeft = kusuriX;
			float KusuriRight = kusuriX + kusuriW;
			float KusuriTop = kusuriY;
			float KusuriBottom = kusuriY + kusuriH;
			float MonsterLeft = monsterX;
			float MonsterRight = monsterX + monsterW;
			float MonsterTop = monsterY;
			float MonsterBottom = monsterY + monsterH;

			if (KusuriRight < MonsterLeft ||
				MonsterRight < KusuriLeft ||
				MonsterBottom < KusuriTop ||
				KusuriBottom < MonsterTop) {
				return 0;
			}
			else {
				return 1;
			}
		}
		return 0;
	}
	int GAME::Kusuri2collision() {
		if (monsterHP > 0) {
			float Kusuri2Left = kusuri2X;
			float Kusuri2Right = kusuri2X + kusuri2W;
			float Kusuri2Top = kusuri2Y;
			float Kusuri2Bottom = kusuri2Y + kusuri2H;
			float MonsterLeft = monsterX;
			float MonsterRight = monsterX + monsterW;
			float MonsterTop = monsterY;
			float MonsterBottom = monsterY + monsterH;

			if (Kusuri2Right < MonsterLeft ||
				MonsterRight < Kusuri2Left ||
				MonsterBottom < Kusuri2Top ||
				Kusuri2Bottom < MonsterTop) {
				return 0;
			}
			else {
				return 1;
			}
		}
		return 0;
	}
	int GAME::Kusuri3collision() {
		if (monsterHP > 0) {
			float Kusuri3Left = kusuri3X;
			float Kusuri3Right = kusuri3X + kusuri3W;
			float Kusuri3Top = kusuri3Y;
			float Kusuri3Bottom = kusuri3Y + kusuri3H;
			float MonsterLeft = monsterX;
			float MonsterRight = monsterX + monsterW;
			float MonsterTop = monsterY;
			float MonsterBottom = monsterY + monsterH;

			if (Kusuri3Right < MonsterLeft ||
				MonsterRight < Kusuri3Left ||
				MonsterBottom < Kusuri3Top ||
				Kusuri3Bottom < MonsterTop) {
				return 0;
			}
			else {
				return 1;
			}
		}
		return 0;
	}
	int GAME::Kusuri4collision() {
		if (monsterHP > 0) {
			float Kusuri4Left = kusuri4X;
			float Kusuri4Right = kusuri4X + kusuri4W;
			float Kusuri4Top = kusuri4Y;
			float Kusuri4Bottom = kusuri4Y + kusuri4H;
			float MonsterLeft = monsterX;
			float MonsterRight = monsterX + monsterW;
			float MonsterTop = monsterY;
			float MonsterBottom = monsterY + monsterH;

			if (Kusuri4Right < MonsterLeft ||
				MonsterRight < Kusuri4Left ||
				MonsterBottom < Kusuri4Top ||
				Kusuri4Bottom < MonsterTop) {
				return 0;
			}
			else {
				return 1;
			}
		}
		return 0;
	}
	void GAME::Play()
	{
		if (monsterHP > HpMax) {
			monsterHP += -700;
		}

		float limA = 910;
		float limB = 0;
		float limC = 1820;
		if (isPress(KEY_W)) {
			monsterHP += -10;
			if (monsterY > limB) {
				monsterY += -30;
			}
			if (DaifukuX > limB) {
				DaifukuX += -2;
			}
			if (PurinY < limA) {
				PurinY += 2;
			}
			if (OnigiriX < limC) {
				OnigiriX += 2;
			}
			if (NikuY > limB) {
				NikuY += -2;
			}
		}
		if (isPress(KEY_S)) {
			monsterHP += -10;
			if (monsterY < limA) {
				monsterY += 30;
			}
			if (DaifukuY <limA) {
				DaifukuY += 2;
			}
			if (PurinX < limC) {
				PurinX += 2;
			}
			if (OnigiriY < limB) {
				OnigiriY += -2;
			}
			if (NikuX < limB) {
				NikuX += -2;
			}
		}
		if (isPress(KEY_D)) {
			monsterHP += -10;
			if (monsterX < limC) {
				monsterX += 30;
			}
			if (DaifukuX > limB) {
				DaifukuX += -2;
			}
			if (PurinY < limB) {
				PurinY += -2;
			}
			if (OnigiriX < limA) {
				OnigiriX += 2;
			}
			if (NikuX > limC) {
				NikuX += 2;
			}
		}
		if (isPress(KEY_A)) {
			monsterHP += -10;
			if (monsterX > limB) {
				monsterX += -30;
			}
			if (DaifukuX < limC) {
				DaifukuX += 2;
			}
			if (PurinX > limB) {
				PurinX += -2;
			}
			if (OnigiriY < limB) {
				OnigiriY += 2;
			}
			if (NikuY > limA) {
			    NikuY += 2;
			}
		}
		if (Nikucollision()) {
			playSound(syokujiSnd);
			Score += 1;
			scale += 0.03;
			hakaY -= 0.5;
			monsterHP += 250;
			NikuX = random() % 1820;
			NikuY = random() % 930;
			kusuriX = random() % 1820;
			kusuriY = random() % 930;
		}

		if (Daifukucollision()) {
			playSound(syokujiSnd);
			Score += 1;
			scale += 0.03;
			hakaY -= 0.5;
			monsterHP += 250;
			DaifukuX = random() % 1820;
			DaifukuY = random() % 930;
			kusuriX = random() % 1820;
			kusuriY = random() % 930;
		}

		if (Purincollision()) {
			playSound(syokujiSnd);
			Score += 1;
			scale += 0.03;
			hakaY -= 0.5;
			monsterHP += 250;
			PurinX = random() % 1820;
			PurinY = random() % 930;
			kusuriX = random() % 1820;
			kusuriY = random() % 930;
		}

		if (Onigiricollision()) {
			playSound(syokujiSnd);
			Score += 1;
			scale += 0.03;
			hakaY -= 0.5;
			monsterHP += 250;
			OnigiriX = random() % 1820;
			OnigiriY = random() % 930;
			kusuriX = random() % 1820;
			kusuriY = random() % 930;
		}

		if (Kusuricollision()) {
			playSound(syokujiSnd);
			dame += 1;
			monsterHP += -500;
			kusuriX = random() % 1820;
			kusuriY = random() % 930;
		}
		
		if (Score == 30) {
			State = PLAY2;
		}

		if (monsterHP <= 0) {
		    playSound(sibouSnd);
			State = CLEAR;
		}
		Draw();

		fill(240,255,16);
		textSize(100);
		textMode(BCENTER);
		text(Score, 60, 60);

		fill(255, 0, 0);
		textSize(100);
		textMode(BCENTER);
		text(dame, 60, 160);

	}

	void GAME::Play2()
	{
		if (monsterHP > HpMax) {
			monsterHP += -700;
		}

		float limA = 910;
		float limB = 0;
		float limC = 1820;
		if (isPress(KEY_W)) {
			monsterHP += -10;
			if (monsterY > limB) {
				monsterY += -30;
			}
			if (DaifukuX > limB) {
				DaifukuX += -2;
			}
			if (PurinY < limA) {
				PurinY += 2;
			}
			if (OnigiriX < limC) {
				OnigiriX += 2;
			}
			if (NikuY > limB) {
				NikuY += -2;
			}
		}
		if (isPress(KEY_S)) {
			monsterHP += -10;
			if (monsterY < limA) {
				monsterY += 30;
			}
			if (DaifukuY < limA) {
				DaifukuY += 2;
			}
			if (PurinX < limC) {
				PurinX += 2;
			}
			if (OnigiriY < limB) {
				OnigiriY += -2;
			}
			if (NikuX < limB) {
				NikuX += -2;
			}
		}
		if (isPress(KEY_D)) {
			monsterHP += -10;
			if (monsterX < limC) {
				monsterX += 30;
			}
			if (DaifukuX > limB) {
				DaifukuX += -2;
			}
			if (PurinY < limB) {
				PurinY += -2;
			}
			if (OnigiriX < limA) {
				OnigiriX += 2;
			}
			if (NikuX > limC) {
				NikuX += 2;
			}
		}
		if (isPress(KEY_A)) {
			monsterHP += -10;
			if (monsterX > limB) {
				monsterX += -30;
			}
			if (DaifukuX < limC) {
				DaifukuX += 2;
			}
			if (PurinX > limB) {
				PurinX += -2;
			}
			if (OnigiriY < limB) {
				OnigiriY += 2;
			}
			if (NikuY > limA) {
				NikuY += 2;
			}
		}
		if (Nikucollision()) {
			playSound(syokujiSnd);
			Score += 1;
			scale += 0.03;
			hakaY -= 0.5;
			monsterHP += 250;
			NikuX = random() % 1820;
			NikuY = random() % 930;
			kusuriX = random() % 1820;
			kusuriY = random() % 930;
			kusuri2X = random() % 1820;
			kusuri2Y = random() % 930;
		}

		if (Daifukucollision()) {
			playSound(syokujiSnd);
			Score += 1;
			scale += 0.03;
			hakaY -= 0.5;
			monsterHP += 250;
			DaifukuX = random() % 1820;
			DaifukuY = random() % 930;
			kusuriX = random() % 1820;
			kusuriY = random() % 930;
			kusuri2X = random() % 1820;
			kusuri2Y = random() % 930;
		}

		if (Purincollision()) {
			playSound(syokujiSnd);
			Score += 1;
			scale += 0.03;
			hakaY -= 0.5;
			monsterHP += 250;
			PurinX = random() % 1820;
			PurinY = random() % 930;
			kusuriX = random() % 1820;
			kusuriY = random() % 930;
			kusuri2X = random() % 1820;
			kusuri2Y = random() % 930;
		}

		if (Onigiricollision()) {
			playSound(syokujiSnd);
			Score += 1;
			scale += 0.03;
			hakaY -= 0.5;
			monsterHP += 250;
			OnigiriX = random() % 1820;
			OnigiriY = random() % 930;
			kusuriX = random() % 1820;
			kusuriY = random() % 930;
			kusuri2X = random() % 1820;
			kusuri2Y = random() % 930;
		}

		if (Kusuricollision()) {
			playSound(syokujiSnd);
			dame += 1;
			monsterHP += -500;
			kusuriX = random() % 1820;
			kusuriY = random() % 930;
		}

		if (Kusuri2collision()) {
			playSound(syokujiSnd);
			dame += 1;
			monsterHP += -500;
			kusuri2X = random() % 1820;
			kusuri2Y = random() % 930;
		}

		if (Score == 80) {
			State = PLAY3;
		}
		
		if (monsterHP <= 0) {
			playSound(sibouSnd);
			State = CLEAR;
		}
		Draw2();

		fill(240, 255, 16);
		textSize(100);
		textMode(BCENTER);
		text(Score, 60, 60);

		fill(255, 0, 0);
		textSize(100);
		textMode(BCENTER);
		text(dame, 60, 160);

	}

	void GAME::Play3()
	{
		if (monsterHP > HpMax) {
			monsterHP += -700;
		}

		float limA = 910;
		float limB = 0;
		float limC = 1820;
		if (isPress(KEY_W)) {
			monsterHP += -10;
			if (monsterY > limB) {
				monsterY += -30;
			}
			if (DaifukuX > limB) {
				DaifukuX += -2;
			}
			if (PurinY < limA) {
				PurinY += 2;
			}
			if (OnigiriX < limC) {
				OnigiriX += 2;
			}
			if (NikuY > limB) {
				NikuY += -2;
			}
		}
		if (isPress(KEY_S)) {
			monsterHP += -10;
			if (monsterY < limA) {
				monsterY += 30;
			}
			if (DaifukuY < limA) {
				DaifukuY += 2;
			}
			if (PurinX < limC) {
				PurinX += 2;
			}
			if (OnigiriY < limB) {
				OnigiriY += -2;
			}
			if (NikuX < limB) {
				NikuX += -2;
			}
		}
		if (isPress(KEY_D)) {
			monsterHP += -10;
			if (monsterX < limC) {
				monsterX += 30;
			}
			if (DaifukuX > limB) {
				DaifukuX += -2;
			}
			if (PurinY < limB) {
				PurinY += -2;
			}
			if (OnigiriX < limA) {
				OnigiriX += 2;
			}
			if (NikuX > limC) {
				NikuX += 2;
			}
		}
		if (isPress(KEY_A)) {
			monsterHP += -10;
			if (monsterX > limB) {
				monsterX += -30;
			}
			if (DaifukuX < limC) {
				DaifukuX += 2;
			}
			if (PurinX > limB) {
				PurinX += -2;
			}
			if (OnigiriY < limB) {
				OnigiriY += 2;
			}
			if (NikuY > limA) {
				NikuY += 2;
			}
		}
		if (Nikucollision()) {
			playSound(syokujiSnd);
			Score += 1;
			scale += 0.03;
			hakaY -= 0.5;
			monsterHP += 250;
			NikuX = random() % 1820;
			NikuY = random() % 930;
			kusuriX = random() % 1820;
			kusuriY = random() % 930;
			kusuri2X = random() % 1820;
			kusuri2Y = random() % 930;
			kusuri3X = random() % 1820;
			kusuri3Y = random() % 930;
			kusuri4X = random() % 1820;
			kusuri4Y = random() % 930;
		}

		if (Daifukucollision()) {
			playSound(syokujiSnd);
			Score += 1;
			scale += 0.03;
			hakaY -= 0.5;
			monsterHP += 250;
			DaifukuX = random() % 1820;
			DaifukuY = random() % 930;
			kusuriX = random() % 1820;
			kusuriY = random() % 930;
			kusuri2X = random() % 1820;
			kusuri2Y = random() % 930;
			kusuri3X = random() % 1820;
			kusuri3Y = random() % 930;
			kusuri4X = random() % 1820;
			kusuri4Y = random() % 930;
		}

		if (Purincollision()) {
			playSound(syokujiSnd);
			Score += 1;
			scale += 0.03;
			hakaY -= 0.5;
			monsterHP += 250;
			PurinX = random() % 1820;
			PurinY = random() % 930;
			kusuriX = random() % 1820;
			kusuriY = random() % 930;
			kusuri2X = random() % 1820;
			kusuri2Y = random() % 930;
			kusuri3X = random() % 1820;
			kusuri3Y = random() % 930;
			kusuri4X = random() % 1820;
			kusuri4Y = random() % 930;
		}

		if (Onigiricollision()) {
			playSound(syokujiSnd);
			Score += 1;
			scale += 0.03;
			hakaY -= 0.5;
			monsterHP += 250;
			OnigiriX = random() % 1820;
			OnigiriY = random() % 930;
			kusuriX = random() % 1820;
			kusuriY = random() % 930;
			kusuri2X = random() % 1820;
			kusuri2Y = random() % 930;
			kusuri3X = random() % 1820;
			kusuri3Y = random() % 930;
			kusuri4X = random() % 1820;
			kusuri4Y = random() % 930;
		}

		if (Kusuricollision()) {
			playSound(syokujiSnd);
			dame += 1;
			monsterHP += -500;
			kusuriX = random() % 1820;
			kusuriY = random() % 930;
		}

		if (Kusuri2collision()) {
			playSound(syokujiSnd);
			dame += 1;
			monsterHP += -500;
			kusuri2X = random() % 1820;
			kusuri2Y = random() % 930;
		}
		if (Kusuri3collision()) {
			playSound(syokujiSnd);
			dame += 1;
			monsterHP += -500;
			kusuri3X = random() % 1820;
			kusuri3Y = random() % 930;
		}
		if (Kusuri4collision()) {
			playSound(syokujiSnd);
			dame += 1;
			monsterHP += -500;
			kusuri4X = random() % 1820;
			kusuri4Y = random() % 930;
		}


		if (monsterHP <= 0) {
			playSound(sibouSnd);
			State = CLEAR;
		}
		Draw3();

		fill(240, 255, 16);
		textSize(100);
		textMode(BCENTER);
		text(Score, 60, 60);

		fill(255, 0, 0);
		textSize(100);
		textMode(BCENTER);
		text(dame, 60, 160);

	}
	
	void GAME::Draw()
	{
		clear(0, 0, 255);
	
		rectMode(CORNER);
		image(daidokoroImg, 0, 0);
		fill(0,0,0,0);
		rect(monsterX, monsterY, monsterW, monsterH);

		fill(0, 0, 0,0);
		rect(NikuX, NikuY, NikuW, NikuH);
		rect(DaifukuX, DaifukuY, DaifukuW, DaifukuH);
		rect(OnigiriX, OnigiriY, OnigiriW, OnigiriH);
		rect(PurinX, PurinY, PurinW, PurinH);
		rect(kusuriX, kusuriY, kusuriW, kusuriH);

		image(nikuImg, NikuX-40, NikuY-38);
		image(daifukuImg, DaifukuX-30, DaifukuY-40);
		image(onigiriImg, OnigiriX-35, OnigiriY-20);
		image(purinImg, PurinX-40, PurinY-30);
		image(monsterImg, monsterX-25, monsterY-40);
		image(kusuriImg, kusuriX-42, kusuriY-30);

		fill(255,0,0);
		textSize(50);
		textMode(BCENTER);
		text("YOU", monsterX+40, monsterY+130);

		HpGauge();
	}
	void GAME::Draw2()
	{
		clear(0, 0, 255);

		rectMode(CORNER);
		image(daidokoroImg, 0, 0);
		fill(0, 0, 0, 0);
		rect(monsterX, monsterY, monsterW, monsterH);

		fill(0, 0, 0, 0);
		rect(NikuX, NikuY, NikuW, NikuH);
		rect(DaifukuX, DaifukuY, DaifukuW, DaifukuH);
		rect(OnigiriX, OnigiriY, OnigiriW, OnigiriH);
		rect(PurinX, PurinY, PurinW, PurinH);
		rect(kusuriX, kusuriY, kusuriW, kusuriH);
		rect(kusuri2X, kusuri2Y, kusuri2W, kusuri2H);

		image(nikuImg, NikuX - 40, NikuY - 38);
		image(daifukuImg, DaifukuX - 30, DaifukuY - 40);
		image(onigiriImg, OnigiriX - 35, OnigiriY - 20);
		image(purinImg, PurinX - 40, PurinY - 30);
		image(monsterImg, monsterX - 25, monsterY - 40);
		image(kusuriImg, kusuriX - 42, kusuriY - 30);
		image(kusuriImg, kusuri2X - 42, kusuri2Y - 30);

		fill(255, 0, 0);
		textSize(50);
		textMode(BCENTER);
		text("YOU", monsterX + 40, monsterY + 130);

		HpGauge();
	}
	void GAME::Draw3()
	{
		clear(0, 0, 255);

		rectMode(CORNER);
		image(daidokoroImg, 0, 0);
		fill(0, 0, 0, 0);
		rect(monsterX, monsterY, monsterW, monsterH);

		fill(0, 0, 0, 0);
		rect(NikuX, NikuY, NikuW, NikuH);
		rect(DaifukuX, DaifukuY, DaifukuW, DaifukuH);
		rect(OnigiriX, OnigiriY, OnigiriW, OnigiriH);
		rect(PurinX, PurinY, PurinW, PurinH);
		rect(kusuriX, kusuriY, kusuriW, kusuriH);
		rect(kusuri2X, kusuri2Y, kusuri2W, kusuri2H);
		rect(kusuri3X, kusuri3Y, kusuri3W, kusuri3H);
		rect(kusuri4X, kusuri4Y, kusuri4W, kusuri4H);

		image(nikuImg, NikuX - 40, NikuY - 38);
		image(daifukuImg, DaifukuX - 30, DaifukuY - 40);
		image(onigiriImg, OnigiriX - 35, OnigiriY - 20);
		image(purinImg, PurinX - 40, PurinY - 30);
		image(monsterImg, monsterX - 25, monsterY - 40);
		image(kusuriImg, kusuriX - 42, kusuriY - 30);
		image(kusuriImg, kusuri2X - 42, kusuri2Y - 30);
		image(kusuriImg, kusuri3X - 42, kusuri3Y - 30);
		image(kusuriImg, kusuri4X - 42, kusuri4Y - 30);

		fill(255, 0, 0);
		textSize(50);
		textMode(BCENTER);
		text("YOU", monsterX + 40, monsterY + 130);

		HpGauge();
	}
	void GAME::HpGauge()
	{
		strokeWeight(0);
		if (monsterHP > 300) {
			fill(0, 255, 0);
		}
		else {
			fill(255, 0, 0);
		}
		rect(0, 1030, monsterHP, 50);

	}
	void GAME::Clear()
	{
		clear(0, 0, 128);
		textSize(100);
		textMode(BCENTER);
		text(Score, 500, 540);

		textSize(100);
		textMode(BCENTER);
		text(dame, 500, 650);

		fill(255, 255, 255);
		print("GAME OVER");
		print("クリックでタイトルに戻る");

		if (Score >= 200) {
			print("評価　S");
		}
		else if (Score >= 150) {
			print("評価　A");
		}
		else if (Score >= 100) {
			print("評価　B");
		}
		else if(Score >= 50) {
			print("評価　C");
		}
		else if (Score >= 0) {
			print("評価　D");
		}
		
		if (isTrigger(MOUSE_LBUTTON)) {
			State = TITLE;
		}
		image(hakaImg, hakaX, hakaY);
	}
}
