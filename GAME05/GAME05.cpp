#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include<stdlib.h>
#include<string.h>
#include "GAME05.h"
namespace GAME05
{
	int GAME::create(){
		KizaruImg = loadImage("..\\main\\assets\\game05\\kizaru.png");
		GachaImg = loadImage("..\\main\\assets\\game05\\gacha.png");
		TitleImg = loadImage("..\\main\\assets\\game05\\title.png");
		PunchImg = loadImage("..\\main\\assets\\game05\\punch.png");
		LuffyImg = loadImage("..\\main\\assets\\game05\\luffy.png");
		BlockImg = loadImage("..\\main\\assets\\game05\\block.png");
		Tama2Img = loadImage("..\\main\\assets\\game05\\tama2.png");
		HitImg = loadImage("..\\main\\assets\\game05\\punch2.png");
		TamaImg = loadImage("..\\main\\assets\\game05\\tama.png");
		EnelImg = loadImage("..\\main\\assets\\game05\\enel.png");
		BackImg = loadImage("..\\main\\assets\\game05\\back.png");
		
		LgSnd = loadSound("..\\main\\assets\\game05\\w006.wav");
		GetSnd = loadSound("..\\main\\assets\\game05\\get.wav");
		BgmSnd = loadSound("..\\main\\assets\\game05\\bgm.wav");
		HitSnd = loadSound("..\\main\\assets\\game05\\hit1.wav");
		LastSnd = loadSound("..\\main\\assets\\game05\\w005.wav");
		OverSnd = loadSound("..\\main\\assets\\game05\\over.wav");
		PunchSnd = loadSound("..\\main\\assets\\game05\\ouda.wav");
		WinSnd = loadSound("..\\main\\assets\\game05\\YouWin.wav");
		TitleSnd = loadSound("..\\main\\assets\\game05\\y014.wav");
		ClickSnd = loadSound("..\\main\\assets\\game05\\click.wav");
		LuckySnd = loadSound("..\\main\\assets\\game05\\lucky.wav");
		ClearSnd = loadSound("..\\main\\assets\\game05\\clear.wav");
		UseSnd = loadSound("..\\main\\assets\\game05\\���z�\��.wav");
		FinishSnd = loadSound("..\\main\\assets\\game05\\finish.wav");
		AttackSnd = loadSound("..\\main\\assets\\game05\\attack.wav");
		LGClearSnd = loadSound("..\\main\\assets\\game05\\clear2.wav");
		OpenSnd = loadSound("..\\main\\assets\\game05\\�󔠂��J����.wav");
		AtariSnd = loadSound("..\\main\\assets\\game05\\�W���W���[��.wav");
		ToppaSnd = loadSound("..\\main\\assets\\game05\\�C���b�z�[�I.wav");
		ChoiceSnd = loadSound("..\\main\\assets\\game05\\�I�����Ă�������.wav");
		
		return 0;
	}

	void GAME::destroy(){
	}

	void GAME::proc(){
		if (State == TITLE)Title();
		else if (State == RULE)Rule();
		else if (State == VOL)Vol();
		else if (State == GACHA)Gacha();
		else if (State == PROB)Prob();
		else if (State == MEAN)Mean();
		else if (State == RESULT)Result();
		else if (State == RESULT2)Result2();
		else if (State == PLAY)Play();
		else if (State == PLAY2)Play2();
		else if (State == PLAY3)Play3();
		else if (State == LUCKY)Lucky();
		else if (State == LUCKYGAME)LuckyGame();
		else if (State == CLEAR)Clear();
		else if (State == ALLCLEAR)Allclear();
		else if (State == LGCLEAR)Lgclear();
		else if (State == LGCLEAR2)Lgclear2();
		else if (State == LGCLEAR3)Lgclear3();
		else if (State == FINISH)Finish();
		else if (State == OVER)Over();
		/*
		textSize(50);
		fill(255, 255, 0);
		text("GAME05", 0, 100);
		*/
	}

	void GAME::Title(){
		clear(0);
		rectMode(CORNER);
		image(TitleImg, 0, 0);
		fill(255, 0, 0);
		textSize(90);
		text("��", 50, 200);
		fill(0);
		text("�����̃|�C���g���s�b�^���������N���A", 150, 200);
		fill(255, 200, 0);
		textSize(100);
		text("�`��������`", 630, 400);
		text("A:���ړ�", 500, 600);
		text("D:�E�ړ�", 970, 600);
		text("W:��ړ�", 500, 800);
		text("S:���ړ�", 970, 800);
		fill(0);
		text("���N���b�N�ŗV�ѕ�", 500, 1000);

		if (loopBgm) {
			playLoopSound(TitleSnd);
			loopBgm = false;
		}

		if (isTrigger(MOUSE_LBUTTON)) {
			ShowCursor(0);
			State = RULE;
			return;
		}
		setVolume(GetSnd, -(100 - volume2) * (100 - volume2));
		setVolume(PunchSnd, -(100 - volume2) * (100 - volume2));
		setVolume(ClearSnd, -(100 - volume1) * (100 - volume1));
		setVolume(BgmSnd, -(100 - volume1) * (100 - volume1));
		setVolume(OverSnd, -(100 - volume1) * (100 - volume1));
		setVolume(LuckySnd, -(100 - volume2) * (100 - volume2));
		setVolume(LGClearSnd, -(100 - volume1) * (100 - volume1));
		setVolume(LgSnd, -(100 - volume1) * (100 - volume1));
		setVolume(FinishSnd, -(100 - volume2) * (100 - volume2));
		setVolume(AttackSnd, -(100 - volume2) * (100 - volume2));
		setVolume(ClickSnd, -(100 - volume2) * (100 - volume2));
		setVolume(TitleSnd, -(100 - volume1) * (100 - volume1));
		setVolume(ToppaSnd, -(100 - volume2) * (100 - volume2));

		fill(255);
		textSize(50);
		text("S�L�[:���ʒ���", 0, 980);
		if (isTrigger(KEY_S)) {
			Init3();
			State = VOL;
		}

		text("G�L�[:�K�`��", 0, 880);
		if (isTrigger(KEY_G)) {
			playSound(ChoiceSnd);
			State = GACHA;
		}

		text("ENTER�L�[�Ń��j���[�ɖ߂�", 0, 1080);
		if (isTrigger(KEY_ENTER)) {
			showCursor();
			main()->backToMenu();
		}
	}

	void GAME::Vol(){
		clear(255);
		fill(50);
		textSize(50);
		text("BGM", width / 5.0, height / 3.0);
		text("S E", width / 5.0, height / 2.0);


		if (isTrigger(KEY_B)) {
			adjustment = true;
			cnt = 0;
		}
		if (isTrigger(KEY_S)) {
			adjustment = false;
			cnt = 0;
		}

		strokeWeight(5.0);
		stroke(100);
		fill(0);
		line(width / 3.5, height / 3.15, width / 3.5 + 800, height / 3.15);
		line(width / 3.5, height / 2.05, width / 3.5 + 800, height / 2.05);
		circle(width / 3.5 + volume1 * 8.0, height / 3.15, 25);
		circle(width / 3.5 + volume2 * 8.0, height / 2.05, 25);

		fill(0);
		text((let)volume1, width / 1.4, height / 3.0);
		text((let)volume2, width / 1.4, height / 2.0);
		text("B�L�[:BGM�ɓ_���ڂ�", 150, 700);
		text("S�L�[:SE�ɓ_���ڂ�", 1050, 700);
		text("U�L�[:BGM�܂���SE�̉��ʂ��グ��", 150, 850);
		text("D�L�[:BGM�܂���SE�̉��ʂ�������", 1050, 850);

		if (adjustment == true) {
			cnt++;
			if (cnt % 3 == 0) {
				if (volume1 >= 0 && volume1 <= 100) {
					if (isPress(KEY_D)) {
						volume1--;
						if (volume1 < 0) {
							volume1 = 0;
						}
					}
					if (isPress(KEY_U)) {
						volume1++;
						if (volume1 > 100) {
							volume1 = 100;
						}
					}
				}
				cnt = 0;
			}
			fill(255, 0, 255);
			circle(width / 3.5 + volume1 * 8.0, height / 3.15, 25);
		}

		if (adjustment == false) {
			cnt++;
			if (cnt % 3 == 0) {
				if (volume2 >= 0 && volume2 <= 100) {
					if (isPress(KEY_D)) {
						volume2--;
						if (volume2 < 0) {
							volume2 = 0;
						}
					}
					if (isPress(KEY_U)) {
						volume2++;
						if (volume2 > 100) {
							volume2 = 100;
						}
					}
				}
				cnt = 0;
			}
			fill(255, 0, 255);
			circle(width / 3.5 + volume2 * 8.0, height / 2.05, 25);
		}
		setVolume(GetSnd, -(100 - volume2) * (100 - volume2));
		setVolume(PunchSnd, -(100 - volume2) * (100 - volume2));
		setVolume(ClearSnd, -(100 - volume1) * (100 - volume1));
		setVolume(BgmSnd, -(100 - volume1) *(100 - volume1));
		setVolume(OverSnd, -(100 - volume1) * (100 - volume1));
		setVolume(LuckySnd, -(100 - volume2) * (100 - volume2));
		setVolume(LGClearSnd, -(100 - volume1) * (100 - volume1));
		setVolume(LgSnd, -(100 - volume1) * (100 - volume1));
		setVolume(FinishSnd, -(100 - volume2) * (100 - volume2));
		setVolume(AttackSnd, -(100 - volume2) * (100 - volume2));
		setVolume(ClickSnd, -(100 - volume2) * (100 - volume2));
		setVolume(TitleSnd, -(100 - volume1) * (100 - volume1));
		setVolume(ToppaSnd, -(100 - volume2) * (100 - volume2));

		fill(0);
		textSize(50);
		text("A�L�[�ŉ���炷", 700, 1080);
		if (isTrigger(KEY_A)) {
			playSound(ClickSnd);
		}

		fill(0);
		textSize(50);
		text("ENTER�L�[�Ń^�C�g���ɖ߂�", 0, 1080);
		if (isTrigger(KEY_ENTER)) {
			State = TITLE;
		}
	}

	void GAME::Rule() {
		clear(0);
		rectMode(CORNER);
		image(TitleImg, 0, 0);
		fill(255, 200, 0);
		textSize(50);
		text("�`�V�ѕ��`", 800, 50);
		textSize(80);
		text("������G�������_���ɏo�Ă���", 270, 150);
		text("���ɏ����Ă���|�C���g�͈͓̔���", 270, 280);
		text("�G�ɐG�ꂽ�炻�̃|�C���g���Q�b�g�I", 270, 370);
		fill(255, 0, 0);
		text("��", 270, 520);
		fill(255, 200, 0);
		text("�����̃|�C���g���J�E���g�ȓ���", 350, 520);
		text("�Q�b�g�ł�����Q�[���N���A", 270, 620);
		text("�J�E���g��0�ɂȂ邩", 270, 780);
		fill(255, 0, 0);
		text("��", 1030, 780);
		fill(255, 200, 0);
		text("�����̃|�C���g���", 1110, 780);
		text("�����������Q�[���I�[�o�[", 270, 880);
		text("���N���b�N�ŃQ�[���X�^�[�g", 270, 1030);
		if (isTrigger(MOUSE_LBUTTON)) {
			Init();
			Init3();
			stopSound(TitleSnd);
			playLoopSound(BgmSnd);
			ShowCursor(0);
			State = PLAY;
			return;
		}

		if (isTrigger(KEY_B)) {
			stopSound(TitleSnd);
			playSound(LuckySnd);
			State = LUCKY;
			return;
		}

		fill(255);
		textSize(50);
		text("ENTER�L�[:�^�C�g���ɖ߂�", 0, 1080);
		if (isTrigger(KEY_ENTER)) {
			State = TITLE;
		}
	}

	void GAME::Init(){
		PPx = width / 2;
		PPy = height / 2;
		PVx = 20.0f;
		PVy = 20.0f;
		PMx = 140.0f;
		PMy = 175.0f;
		PhalfW = 20.0f;
		PhalfH = 20.0f;

		EPx = -10;
		EPy = 150.0f;
		EVx = 30.0f;
		EMx = 140.0f;
		EhalfW = 20.0f;
		EhalfH = 20.0f;
		EHp = 1;

		GPR = 50;
		GPRx = 384;
		GPRy = 1080;

		GPY = 30;
		GPYx = 768;
		GPYy = 1080;

		GPB = 10;
		GPBx = 1152;
		GPBy = 1080;

		GPG = 5;
		GPGx = 1536;
		GPGy = 1080;

		GPP = 1;
		GPPx = 1920;
		GPPy = 1080;

		Point = 0;

		CountDown = 60 * 60;

		CountDown3 = 50 * 60;

		CountDown4 = 45 * 60;

		ClearPoint = random() % 100 + 1.0f;

		ClearPoint2 = random() % 70 + 1.0f;

		ClearPoint3 = random() % 50 + 1.0f;

		LuckyNo = random() % 5 + 1.0f;

		PointFlag = false;

		adjustment = true;
	}

	void GAME::Init2(){
		//�v���C���[���
		Px = width / 2;
		Py = 930;
		halfW = 100;
		halfH = 200;
		Mx = 120;
		Vx = 15;
		HP = 50;
		MaxHp = HP;

		//�v���C���[�̒e
		PBPx = Px;
		PBPy = Py;
		PBVy = -25;
		PBHp = 0;
		PBhalfW = 10;
		PBhalfH = 20;
		PBOfstY = -110;

		//�G���
		EPx = 100;
		EPy = 250;
		EhalfW = 100;
		EhalfH = 100;
		EVx = 23.0f;
		EHP = 500;

		//�G�̒e
		EBPx = EPx;
		EBPy = EPy;
		EBVy = 30;
		EBHp = 0;
		EBhalfW = 10;
		EBhalfH = 20;
		OfstY = -110;
		
		//�v���C���[�A�G��HP���
		HpX = 1400;
		HpY = 1030;

		EHpX = 970;
		EHpY = 80;
		EMaxHp = EHP;

		EhpGaugeOfsY = -180;

		hpGaugeWidth = 30;

		EHpWarning = EHP * 0.3f;
		EHpDenger = EHP * 0.1f;

		HpWarning = EHP * 0.03f;
		HpDenger = EHP * 0.01f;

		SpDire = HP * 0.7;

		Dire = HP * 0.6;

		img = PunchImg;

		CountDown = 40 * 60;

		EHitFlag = false;

		PHitFlag = false;

		adjustment = true;
	}

	void GAME::Init3(){
		cnt = 0;
		adjustment = true;
	}

	void GAME::Init4()
	{
		num0 = random() % 100 + 1;
		num1 = random() % 100 + 1;
		num2 = random() % 100 + 1;
		num3 = random() % 100 + 1;
		num4 = random() % 100 + 1;
		num5 = random() % 100 + 1;
		num6 = random() % 100 + 1;
		num7 = random() % 100 + 1;
		num8 = random() % 100 + 1;
		num9 = random() % 100 + 1;
		num10 = random() % 100 + 1;

		LTcnt = random() % 7 + 1;
		gachaCnt = 0;

		star4Total = 10;
		star5Total = 9;
		star6Total = 7;
		sstar6Total = 6;

		randomsstar6num = random() % sstar6Total;
		randomstar6num = random() % star6Total;
		randomstar5num = random() % star5Total;
		randomstar4num = random() % star4Total;

		randomsstar6num1 = random() % sstar6Total;
		randomstar6num1 = random() % star6Total;
		randomstar5num1 = random() % star5Total;
		randomstar4num1 = random() % star4Total;

		randomsstar6num2 = random() % sstar6Total;
		randomstar6num2 = random() % star6Total;
		randomstar5num2 = random() % star5Total;
		randomstar4num2 = random() % star4Total;

		randomsstar6num3 = random() % sstar6Total;
		randomstar6num3 = random() % star6Total;
		randomstar5num3 = random() % star5Total;
		randomstar4num3 = random() % star4Total;

		randomsstar6num4 = random() % sstar6Total;
		randomstar6num4 = random() % star6Total;
		randomstar5num4 = random() % star5Total;
		randomstar4num4 = random() % star4Total;

		randomsstar6num5 = random() % sstar6Total;
		randomstar6num5 = random() % star6Total;
		randomstar5num5 = random() % star5Total;
		randomstar4num5 = random() % star4Total;

		randomsstar6num6 = random() % sstar6Total;
		randomstar6num6 = random() % star6Total;
		randomstar5num6 = random() % star5Total;
		randomstar4num6 = random() % star4Total;

		randomsstar6num7 = random() % sstar6Total;
		randomstar6num7 = random() % star6Total;
		randomstar5num7 = random() % star5Total;
		randomstar4num7 = random() % star4Total;

		randomsstar6num8 = random() % sstar6Total;
		randomstar6num8 = random() % star6Total;
		randomstar5num8 = random() % star5Total;
		randomstar4num8 = random() % star4Total;

		randomsstar6num9 = random() % sstar6Total;
		randomstar6num9 = random() % star6Total;
		randomstar5num9 = random() % star5Total;
		randomstar4num9 = random() % star4Total;

		randomsstar6num10 = random() % sstar6Total;
		randomstar6num10 = random() % star6Total;
		randomstar5num10 = random() % star5Total;
		randomstar4num10 = random() % star4Total;
	}

	void GAME::Play(){
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
		//�e�|�C���g�͈̔͂Ɗl���|�C���g
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
		}
		//�N���A�A�Q�[���I�[�o�[����
		if (Point == ClearPoint && CountDown > 0) {
			stopSound(GetSnd);
			stopSound(BgmSnd);
			playSound(ToppaSnd);
			StageCount++;// = StageCount += 1;
			State = CLEAR;
		}
		if (Point > ClearPoint || CountDown <= 0) {
			stopSound(BgmSnd);
			stopSound(GetSnd);
			playSound(OverSnd);
			State = OVER;
		}
		//�`��
		draw();

		if (CountDown > 0) {
			fill(0);
			CountDown -= delta;
			textSize(100);
			text(CountDown / 60, 0, 300);
		}

		if (isTrigger(KEY_R)) {
			stopSound(BgmSnd);
			State = RULE;
		}
	}

	void GAME::Play2(){
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

		if (EPx > width) {
			PointFlag = false;
		}
		//�e�|�C���g�͈̔͂Ɗl���|�C���g
		if (PointFlag == false) {
			if (collision() && EPx < GPRx && PPx < GPRx) {
				playSound(GetSnd);
				Point += GPR;
				PointFlag = true;
			}
			if (collision() && EPx < GPYx && EPx > GPRx && PPx < GPYx && PPx > GPRx) {
				playSound(GetSnd);
				Point += GPY;
				PointFlag = true;
			}
			if (collision() && EPx < GPBx && EPx > GPYx && PPx < GPBx && PPx > GPYx) {
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
		}

		//�N���A�A�Q�[���I�[�o�[����
		if (Point == ClearPoint2 && CountDown3 > 0) {
			stopSound(GetSnd);
			stopSound(BgmSnd);
			playSound(ToppaSnd);
			State = CLEAR;
		}
		if (Point > ClearPoint2 || CountDown3 == 0) {
			stopSound(BgmSnd);
			stopSound(GetSnd);
			playSound(OverSnd);
			State = OVER;
		}
		//�`��
		draw();

		if (CountDown3 > 0) {
			fill(0);
			CountDown3 -= delta;
			textSize(100);
			text(CountDown3 / 60, 0, 300);
		}

		if (isTrigger(KEY_R)) {
			stopSound(BgmSnd);
			State = RULE;
		}
	}

	void GAME::Play3(){
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

		if (EPx > width) {
			PointFlag = false;
		}
		//�e�|�C���g�͈̔͂Ɗl���|�C���g
		if (PointFlag == false) {
			if (collision() && EPx < GPRx && PPx < GPRx) {
				playSound(GetSnd);
				Point += GPR;
				PointFlag = true;
			}
			if (collision() && EPx < GPYx && EPx > GPRx && PPx < GPYx && PPx > GPRx) {
				playSound(GetSnd);
				Point += GPY;
				PointFlag = true;
			}
			if (collision() && EPx < GPBx && EPx > GPYx && PPx < GPBx && PPx > GPYx) {
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
		}

		//�N���A�A�Q�[���I�[�o�[, ���b�L�[�Q�[���o������
		if (Point == ClearPoint3 && CountDown4 > 0) {
			stopSound(GetSnd);
			stopSound(BgmSnd);
			playSound(ToppaSnd);
			State = CLEAR;
		}
		if (Point == ClearPoint3 && CountDown4 > 0 && LuckyNo != 1) {
			stopSound(GetSnd);
			stopSound(ToppaSnd);
			stopSound(BgmSnd);
			playSound(ClearSnd);
			tamaCnt += 3;
			State = ALLCLEAR;
		}
		if (Point == ClearPoint3 && CountDown4 > 0 && LuckyNo == 1) {
			stopSound(BgmSnd);
			stopSound(TitleSnd);
			stopSound(GetSnd);
			stopSound(ToppaSnd);
			playSound(LuckySnd);
			tamaCnt += 3;
			ShowCursor(0);
			Init3();
			State = LUCKY;
		}
		if (Point > ClearPoint3 || CountDown4 == 0) {
			stopSound(BgmSnd);
			stopSound(GetSnd);
			playSound(OverSnd);
			State = OVER;
		}
		//�`��
		draw();

		if (CountDown4 > 0) {
			fill(0);
			CountDown4 -= delta;
			textSize(100);
			text(CountDown4 / 60, 0, 300);
		}

		if (isTrigger(KEY_R)) {
			stopSound(BgmSnd);
			State = RULE;
		}
	}

	void GAME::Clear(){
		if (StageCount == 1) {
			clear(35, 253, 59);
			fill(255);
			textSize(100);
			text("1�X�e�[�W�ڃN���A", 560, 300);
			text("���N���b�N��2ndStage��", 420, 500);
			text("�G�Ǝ����̃X�s�[�h���A�b�v", 340, 700);
			textSize(50);
			text("�K�`����1�Q�b�g!", 0, 1080);
			if (isTrigger(MOUSE_LBUTTON)) {
				Init();
				StageCount++;
				PVx += 5.0f;
				PVy += 5.0f;
				EVx += 10.0f;
				ClearPoint = ClearPoint2;
				playLoopSound(BgmSnd);
				stopSound(ToppaSnd);
				tamaCnt += 1;
				State = PLAY2;
			}
		}
		else if (StageCount == 2) {
			clear(252, 230, 50);
			fill(255);
			textSize(100);
			text("2�X�e�[�W�ڃN���A", 560, 300);
			text("���N���b�N��LastStage��", 400, 500);
			text("�G�Ǝ����̃X�s�[�h���X�ɃA�b�v", 250, 700);
			textSize(50);
			text("�K�`����2�Q�b�g!", 0, 1080);
			if (isTrigger(MOUSE_LBUTTON)) {
				Init();
				StageCount++;
				PVx += 10.0f;
				PVy += 10.0f;
				EVx += 15.0f;
				ClearPoint = ClearPoint3;
				playLoopSound(BgmSnd);
				stopSound(ToppaSnd);
				tamaCnt += 2;
				State = PLAY3;
			}
		}
	}

	void GAME::Allclear(){
		clear(255);
		fill(255, 0, 0);
		textSize(300);
		text("A", 200, 600);
		fill(253, 135, 35);
		text("L", 400, 600);
		fill(252, 253, 35);
		text("L", 600, 600);
		fill(164, 253, 35);
		text("C", 850, 600);
		fill(35, 253, 59);
		text("L", 1050, 600);
		fill(35, 253, 205);
		text("E", 1250, 600);
		fill(35, 74, 253);
		text("A", 1450, 600);
		fill(209, 35, 253);
		text("R", 1650, 600);
		textSize(100);
		fill(213, 202, 112);
		text("Congratulations", 600, 800);
		textSize(50);
		fill(0);
		text("���N���b�N�Ń^�C�g���ɖ߂�܂�", 0, 1080);
		text("�K�`����3�Q�b�g!", 0, 980);
		if (isTrigger(MOUSE_LBUTTON)) {
			stopSound(ClearSnd);
			playLoopSound(TitleSnd);
			StageCount = 0;
			State = TITLE;
			return;
		}
	}

	void GAME::Lucky() {
		clear(236, 215, 98);
		fill(0);
		textSize(100);
		text("�Q�[���N���A!", 630, 100);
		text("���b�L�[�Q�[���I", 600, 200);
		text("�p���`�𓖂Ă�", 600,300);
		text("���ԓ��ɓG��|����!", 500, 400);
		text("�`������@�`", 650, 600);
		text("A:���ړ�", 500, 700);
		text("D:�E�ړ�", 1000, 700);
		text("���N���b�N�Œe����", 500, 800);
		text("���N���b�N�������Ŏ�������", 320, 900);
		text("���N���b�N�ŃQ�[����ʂɈڍs", 300, 1000);
		textSize(50);
		text("�K�`����3�Q�b�g!", 0, 1080);

		if (isTrigger(MOUSE_LBUTTON)) {
			Init2();
			Init3();
			Init4();
			CountDown2 -= delta;
			text(CountDown, width / 2, height / 2);
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
		//�p���`
		if (isPress(MOUSE_LBUTTON)) {
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
		//�G�̒e����
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

		//�G�̈ړ�
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
				EHP -= 25;
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
				HP -= 3;
				PHitFlag = true;
			}
		}

		if (EHP <= 0 && HP >= SpDire && LTcnt != 1) {
			stopSound(LgSnd);
			stopSound(PunchSnd);
			stopSound(AttackSnd);
			playSound(LGClearSnd);
			tamaCnt += 15;
			State = LGCLEAR;
		}

		if (EHP <= 0 && HP >= SpDire && LTcnt == 1) {
			stopSound(LgSnd);
			stopSound(PunchSnd);
			stopSound(AttackSnd);
			playSound(LGClearSnd);
			tamaCnt += 50;
			State = LGCLEAR3;
		}

		if (EHP <= 0 && HP <= Dire) {
			stopSound(LgSnd);
			stopSound(AttackSnd);
			stopSound(PunchSnd);
			stopSound(LGClearSnd);
			playSound(WinSnd);
			tamaCnt += 10;
			State = LGCLEAR2;
		}


		if (HP <= 0 || CountDown <= 0) {
			stopSound(LgSnd);
			stopSound(PunchSnd);
			stopSound(AttackSnd);
			playSound(FinishSnd);
			State = FINISH;
		}
		//�`��
		draw2();

		if (CountDown > 0) {
			fill(0);
			CountDown -= delta;
			textSize(100);
			text(CountDown / 60, 0, 300);
		}
	}

	void GAME::Lgclear(){
		clear(255, 255, 255);
		textSize(250);
		fill(255, 72, 72);
		text("L", 50, height / 2);
		fill(255, 161, 72);
		text("U", 150, height / 2);
		fill(255, 203, 72);
		text("C", 260, height / 2);
		fill(250, 255, 72);
		text("K", 370, height / 2); 
		fill(200, 255, 72);
		text("Y", 490, height / 2); 
		fill(100, 255, 72);
		text("G", 590, height / 2);
		fill(100, 255, 72);
		text("A", 710, height / 2);
		fill(72, 255, 185);
		text("M", 830, height / 2);
		fill(72, 255, 250);
		text("E", 950, height / 2); 
		fill(72, 200, 255);
		text("C", 1270, height / 2);
		fill(72, 190, 255);
		text("L", 1390, height / 2); 
		fill(72, 100, 255);
		text("E", 1510, height / 2); 
		fill(130, 72, 255);
		text("A", 1630, height / 2); 
		fill(220, 72, 255);
		text("R", 1750, height / 2);
		textSize(50);
		text("�K�`����15�Q�b�g!", 0, 980);
		if (isTrigger(MOUSE_LBUTTON)) {
			stopSound(LGClearSnd);
			playLoopSound(TitleSnd);
			StageCount = 0;
			State = TITLE;
			return;
		}
		fill(0);
		textSize(50);
		text("���N���b�N�Ń^�C�g���ɖ߂�", 0, 1080);
	}

	void GAME::Lgclear2()
	{
		clear(255, 255, 255);
		textSize(250);
		fill(255, 0, 0);
		text("LUCKYGAME CLEAR", 50, height / 2);
		fill(0);
		textSize(50);
		text("���N���b�N�Ń^�C�g���ɖ߂�", 0, 1080);
		text("�K�`����10�Q�b�g!", 0, 980);
		if (isTrigger(MOUSE_LBUTTON)) {
			stopSound(WinSnd);
			playLoopSound(TitleSnd);
			StageCount = 0;
			State = TITLE;
			return;
		}
	}

	void GAME::Lgclear3()
	{
		clear(255, 255, 255);
		image(LuffyImg, width / 2, height / 2);
		textSize(250);
		fill(255, 72, 72);
		text("L", 50, 300);
		fill(255, 161, 72);
		text("U", 150, 300);
		fill(255, 203, 72);
		text("C", 260, 300);
		fill(250, 255, 72);
		text("K", 370, 300);
		fill(200, 255, 72);
		text("Y", 490, 300);
		fill(100, 255, 72);
		text("G", 590, 300);
		fill(100, 255, 72);
		text("A", 710, 300);
		fill(72, 255, 185);
		text("M", 830, 300);
		fill(72, 255, 250);
		text("E", 950, 300);
		fill(72, 200, 255);
		text("C", 1270, 300);
		fill(72, 190, 255);
		text("L", 1390, 300);
		fill(72, 100, 255);
		text("E", 1510, 300);
		fill(130, 72, 255);
		text("A", 1630, 300);
		fill(220, 72, 255);
		text("R", 1750, 300);
		textSize(50);
		fill(213, 202, 112);
		text("�K�`����50�Q�b�g!", 0, 980);
		if (isTrigger(MOUSE_LBUTTON)) {
			stopSound(LGClearSnd);
			playLoopSound(TitleSnd);
			StageCount = 0;
			State = TITLE;
			return;
		}
		fill(0);
		textSize(50);
		text("���N���b�N�Ń^�C�g���ɖ߂�", 0, 1080);
	}

	void GAME::Finish(){
		clear(0, 200, 255);
		image(LuffyImg, 600, height / 2);
		image(EnelImg, 1200, height / 2);
		fill(255);
		textSize(250);
		text("FINISH!", 500, 300);
		if (isTrigger(MOUSE_LBUTTON)) {
			playLoopSound(TitleSnd);
			StageCount = 0;
			State = TITLE;
			return;
		}
		fill(255);
		textSize(50);
		text("���N���b�N�Ń^�C�g���ɖ߂�", 0, 1080);
	}

	void GAME::Over(){
		clear(0);
		image(EnelImg, EPx = width / 2, EPy = height / 2);
		fill(255);
		textSize(200);
		text("Game Over", 500, 300);
		fill(255);
		textSize(50);
		text("���N���b�N�Ń^�C�g���ɖ߂�", 0, 1080);
		if (isTrigger(MOUSE_LBUTTON)) {
			playLoopSound(TitleSnd);
			stopSound(OverSnd);
			StageCount = 0;
			State = TITLE;
		}
	}

	void GAME::Gacha(){
		clear();
		rectMode(CORNER);
		image(GachaImg, 0, 0);
		rectMode(CENTER);
		image(Tama2Img, 1700, 100);
		if (tamaCnt >= 99999) {
			text("99999+", 1730, 120);
		}
		else {
			text((let)tamaCnt, 1730, 120);
		}
		textSize(100);
		fill(0);
		text("S�L�[:�V���O���K�`�� 5����", 300, 300);
		text("R�L�[:10�A�K�`�� 50����", 300, 500);
		text("(�V���O���K�`����O�L�[�A10�A�K�`����", 80, 700);
		text("A, S, D, F, G, H, J, K, L, P�L�[��", 80, 800);
		text("������1�����ʂ��o�܂�)", 80, 900);

		if (isTrigger(KEY_S) && tamaCnt >= 5) {
			Init4();
			playSound(UseSnd);
			tamaCnt -= 5;
			clear(255);
			FreamCount = 120;
			State = RESULT;
		}

		if (isTrigger(KEY_R) && tamaCnt >= 50) {
			Init4();
			playSound(UseSnd);
			tamaCnt -= 50;
			clear(255);
			FreamCount = 1320;
			State = RESULT2;
		}

		textSize(50);
		text("���N���b�N:�^�C�g���ɖ߂�", 0, 100);
		if (isTrigger(MOUSE_LBUTTON)) {
			State = TITLE;
		}
		text("K�L�[:�o���m��", 0, 980);
		if (isTrigger(KEY_K)) {
			State = PROB;
		}
		text("M�L�[:�K�`���ʂ̓�����@", 1300, 980);
		if (isTrigger(KEY_M)) {
			State = MEAN;
		}
	}

	void GAME::Prob()
	{
		clear(255);
		fill(0);
		textSize(60);
		text("��4:10��:53%", 50, 150);
		textSize(60);
		text("�O�H���G:5.3%", 50, 260);
		text("����`��:5.3%", 50, 340);
		text("���i�v�G:5.3%", 50, 420);
		text("�֓����O:5.3%", 50, 500);
		text("��䒷��:5.3%", 50, 580);
		text("�O�c�c��:5.3%", 50, 660);
		text("��ɒ��J:5.3%", 50, 740);
		text("�� �� �x:5.3%", 50, 820);
		text("�y���ΎO:5.3%", 50, 900);
		text("���c���i:5.3%", 50, 980);

		text("��5:9��:27%", 490, 150);
		textSize(60);
		text("�{�c����:3.0%", 490, 260);
		text("�O�c����:3.0%", 490, 340);
		text("���q���G:3.0%", 490, 420);
		text("�G�ꑷ�s:3.0%", 490, 500);
		text("�� �� ��:3.0%", 490, 580);
		text("��������:3.0%", 490, 660);
		text("��J�g�p:3.0%", 490, 740);
		text("��������:3.0%", 490, 820);
		text("�����k��:3.0%", 490, 900);

		text("��6:7��:14%",930, 150);
		textSize(60);
		text("�ɒB���@:2.0%", 930, 260);
		text("�㐙���M:2.0%", 930, 340);
		text("���c�M��:2.0%", 930, 420);
		text("�^�c�K��:2.0%", 930, 500);
		text("�ї����A:2.0%", 930, 580);
		text("�X �� ��:2.0%", 930, 660);
		text("�{�{����:2.0%", 930, 740);

		fill(213, 202, 112);
		text("��6", 1370, 150);
		fill(0);
		text(":6��:6%", 1460, 150);
		textSize(60);
		text("�D�c�M��:1.0%", 1370, 260);
		text("����ƍN:1.0%", 1370, 340);
		text("�L�b�G�g:1.0%", 1370, 420);
		text("��{���n:1.0%", 1370, 500);
		text("��������:1.0%", 1370, 580);
		text("�������q:1.0%", 1370, 660);

		textSize(50);
		text("���N���b�N:�K�`����ʂɖ߂�", 0, 1080);
		text("������2�ʈȉ��͏ȗ�", 700, 1080);
		if (isTrigger(MOUSE_LBUTTON)) {
			State = GACHA;
		}
	}

	void GAME::Mean()
	{
		clear(255);
		fill(0);
		textSize(80);
		text("�K�`���ʂ̓�����@�ƌ�", 450, 100);
		text("�@�ʏ�̃Q�[���v���C:6��", 450, 200);
		text("�X�e�[�W1�˔j:1��", 550, 300);
		text("�X�e�[�W2�˔j:2��", 550, 400);
		text("���X�g�X�e�[�W�˔j:3��", 450, 500);
		text("�A���b�L�[�Q�[��:15�� or 10��", 350, 700);
		text("HP��35�ȏ�c���ď���:15��", 550, 800);
		text("����:10��", 550, 900);
		textSize(50);
		text("���N���b�N:�K�`���I����ʂɖ߂�", 0, 1080);
		if (isTrigger(MOUSE_LBUTTON)) {
			State = GACHA;
		}
	}

	void GAME::Result() {
		textSize(50);
		text("���ʂ��o�Ė�2�b��ɃK�`���I����ʂɖ߂�", 0, 1080);
		textSize(250);
		while (notQuit) {
			if (gachaCnt == 1) {
				break;
			}
			if (isTrigger(KEY_O)) {
				playSound(OpenSnd);
				gachaCnt++;
				if (num0 > 94) {
					playSound(AtariSnd);
					fill(213, 202, 112);
					text("��6:", 100, 560);
					fill(0);
					text((let)sstar6[randomsstar6num], 600, 560);
				}
				else if (num0 > 80) {
					playSound(HitSnd);
					text("��6:", 100, 560);
					text((let)star6[randomstar6num], 600, 560);
				}
				else if (num0 > 53) {
					text("��5:", 100, 560);
					text((let)star5[randomstar5num], 600, 560);
				}
				else{
					text("��4:", 100, 560);
					text((let)star4[randomstar4num], 600, 560);
				}
			}
		}
		FreamCount -= 2;
		if (FreamCount == 0) {
			State = GACHA;
		}
	}

	void GAME::Result2() {
		textSize(50);
		fill(0);
		text("���ׂĂ̌��ʂ��o�Ė�3�b��ɃK�`���I����ʂɖ߂�", 0, 1080);
		textSize(100);
		while (notQuit) {
			if (gachaCnt >= 10) {
				break;
			}
			//1
			if (isTrigger(KEY_A)) {
				gachaCnt++;
				playSound(OpenSnd);
				if (num1 > 94) {
					playSound(AtariSnd);
					fill(213, 202, 112);
					text("��6:", 10, 220);
					fill(0);
					text((let)sstar6[randomsstar6num1], 200, 220);
				}
				else if (num1 > 80) {
					playSound(HitSnd);
					fill(0);
					textSize(100);
					text("��6:", 10, 220);
					text((let)star6[randomstar6num1], 200, 220);
				}
				else if (num1 > 53) {
					fill(0);
					text("��5:", 10, 220);
					text((let)star5[randomstar5num1], 200, 220);
				}
				else {
					fill(0);
					text("��4:", 10, 220);
					text((let)star4[randomstar4num1], 200, 220);
				}
			}
			//2
			if (isTrigger(KEY_S)) {
				gachaCnt++;
				playSound(OpenSnd);
				if (num2 > 94) {
					playSound(AtariSnd);
					fill(213, 202, 112);
					text("��6:", 650, 220);
					fill(0);
					text((let)sstar6[randomsstar6num2], 850, 220);
				}
				else if (num2 > 80) {
					playSound(HitSnd);
					fill(0);
					text("��6:", 650, 220);
					text((let)star6[randomstar6num2], 850, 220);
				}
				else if (num2 > 53) {
					fill(0);
					text("��5:", 650, 220);
					text((let)star5[randomstar5num2], 850, 220);
				}
				else {
					fill(0);
					text("��4:", 650, 220);
					text((let)star4[randomstar4num2], 850, 220);
				}
			}
			//3
			if (isTrigger(KEY_D)) {
				gachaCnt++;
				playSound(OpenSnd);
				if (num3 > 94) {
					playSound(AtariSnd);
					fill(213, 202, 112);
					text("��6:", 1300, 220);
					fill(0);
					text((let)sstar6[randomsstar6num3], 1500, 220);
				}
				else if (num3 > 80) {
					playSound(HitSnd);
					fill(0);
					text("��6:", 1300, 220);
					text((let)star6[randomstar6num3], 1500, 220);
				}
				else if (num3 > 53) {
					fill(0);
					text("��5:", 1300, 220);
					text((let)star5[randomstar5num3], 1500, 220);
				}
				else {
					fill(0);
					text("��4:", 1300, 220);
					text((let)star4[randomstar4num3], 1500, 220);
				}
			}
			//4
			if (isTrigger(KEY_F)) {
				gachaCnt++;
				playSound(OpenSnd);
				if (num4 > 94) {
					playSound(AtariSnd);
					fill(213, 202, 112);
					text("��6:", 10, 420);
					fill(0);
					text((let)sstar6[randomsstar6num4], 200, 420);
				}
				else if (num4 > 80) {
					playSound(HitSnd);
					fill(0);
					text("��6:", 10, 420);
					text((let)star6[randomstar6num4], 200, 420);
				}
				else if (num4 > 53) {
					fill(0);
					text("��5:", 10, 420);
					text((let)star5[randomstar5num4], 200, 420);
				}
				else {
					fill(0);
					text("��4:", 10, 420);
					text((let)star4[randomstar4num4], 200, 420);
				}
			}
			//5
			if (isTrigger(KEY_G)) {
				gachaCnt++;
				playSound(OpenSnd);
				if (num5 > 94) {
					playSound(AtariSnd);
					fill(213, 202, 112);
					text("��6:", 650, 420);
					fill(0);
					text((let)sstar6[randomsstar6num5], 850, 420);
				}
				else if (num5 > 80) {
					playSound(HitSnd);
					fill(0);
					text("��6:", 650, 420);
					text((let)star6[randomstar6num5], 850, 420);
				}
				else if (num5 > 53) {
					fill(0);
					text("��5:", 650, 420);
					text((let)star5[randomstar5num5], 850, 420);
				}
				else {
					fill(0);
					text("��4:", 650, 420);
					text((let)star4[randomstar4num5], 850, 420);
				}
			}
			//6
			if (isTrigger(KEY_H)) {
				gachaCnt++;
				playSound(OpenSnd);
				if (num6 > 94) {
					playSound(AtariSnd);
					fill(213, 202, 112);
					text("��6:", 1300, 420);
					fill(0);
					text((let)sstar6[randomsstar6num6], 1500, 420);
				}
				else if (num6 > 80) {
					playSound(HitSnd);
					fill(0);
					text("��6:", 1300, 420);
					text((let)star6[randomstar6num6], 1500, 420);
				}
				else if (num6 > 53) {
					fill(0);
					text("��5:", 1300, 420);
					text((let)star5[randomstar5num6], 1500, 420);
				}
				else {
					fill(0);
					text("��4:", 1300, 420);
					text((let)star4[randomstar4num6], 1500, 420);
				}
			}
			//7
			if (isTrigger(KEY_J)) {
				gachaCnt++;
				playSound(OpenSnd);
				if (num7 > 94) {
					playSound(AtariSnd);
					fill(213, 202, 112);
					text("��6:", 10, 620);
					fill(0);
					text((let)sstar6[randomsstar6num7], 200, 620);
				}
				else if (num7 > 80) {
					playSound(HitSnd);
					fill(0);
					text("��6:", 10, 620);
					text((let)star6[randomstar6num7], 200, 620);
				}
				else if (num7 > 53) {
					fill(0);
					text("��5:", 10, 620);
					text((let)star5[randomstar5num7], 200, 620);
				}
				else {
					fill(0);
					text("��4:", 10, 620);
					text((let)star4[randomstar4num7], 200, 620);
				}
			}
			//8
			if (isTrigger(KEY_K)) {
				gachaCnt++;
				playSound(OpenSnd);
				if (num8 > 94) {
					playSound(AtariSnd);
					fill(213, 202, 112);
					text("��6:", 650, 620);
					fill(0);
					text((let)sstar6[randomsstar6num8], 850, 620);
				}
				else if (num8 > 80) {
					playSound(HitSnd);
					fill(0);
					text("��6:", 650, 620);
					text((let)star6[randomstar6num8], 850, 620);
				}
				else if (num8 > 53) {
					fill(0);
					text("��5:", 650, 620);
					text((let)star5[randomstar5num8], 850, 620);
				}
				else {
					fill(0);
					text("��4:", 650, 620);
					text((let)star4[randomstar4num8], 850, 620);
				}
			}
			//9
			if (isTrigger(KEY_L)) {
				gachaCnt++;
				playSound(OpenSnd);
				if (num9 > 94) {
					playSound(AtariSnd);
					fill(213, 202, 112);
					text("��6:", 1300, 620);
					fill(0);
					text((let)sstar6[randomsstar6num9], 1500, 620);
				}
				else if (num9 > 80) {
					playSound(HitSnd);
					fill(0);
					text("��6:", 1300, 620);
					text((let)star6[randomstar6num9], 1500, 620);
				}
				else if (num9 > 53) {
					fill(0);
					text("��5:", 1300, 620);
					text((let)star5[randomstar5num9], 1500, 620);
				}
				else {
					fill(0);
					text("��4:", 1300, 620);
					text((let)star4[randomstar4num9], 1500, 620);
				}
			}
			//10
			if (isTrigger(KEY_P)) {
				gachaCnt++;
				playSound(OpenSnd);
				if (num10 > 94) {
					playSound(AtariSnd);
					fill(213, 202, 112);
					text("��6:", 650, 820);
					fill(0);
					text((let)sstar6[randomsstar6num10], 850, 820);
				}
				else if (num10 > 80) {
					playSound(HitSnd);
					fill(0);
					text("��6:", 650, 820);
					text((let)star6[randomstar6num10], 850, 820);
				}
				else if (num10 > 53) {
					fill(0);
					text("��5:", 650, 820);
					text((let)star5[randomstar5num10], 850, 820);
				}
				else {
					fill(0);
					text("��4:", 650, 820);
					text((let)star4[randomstar4num10], 850, 820);
				}
			}
		}
		FreamCount -= 15;
		if (FreamCount == 0) {
			State = GACHA;
		}
	}

	int GAME::collision(){
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

	int GAME::collision2(){
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

	int GAME::collision3(){
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

	void GAME::hpGauge(){
		strokeWeight(0);
		fill(128);
		rectMode(CORNER);
		rect(500, EHpY + hpGaugeOfsY, EMaxHp * 2, hpGaugeWidth);
		if (EHP > EHpWarning) {
			fill(0, 255, 0);
		}
		else if (EHP > EHpDenger) {
			fill(255, 255, 0);
		}
		else {
			fill(255, 0, 0);
		}
		rect(500, EHpY + hpGaugeOfsY, EHP * 2, hpGaugeWidth);
		rectMode(CENTER);

		textSize(50);
		fill(0);
		text((let)EHP, EHpX, 120);
	}

	void GAME::hpGauge2(){
		strokeWeight(0);
		fill(128);
		rectMode(CORNER);
		rect(HpX, HpY, MaxHp * 10, hpGaugeWidth);
		if (HP > HpWarning) {
			fill(0, 255, 0);
		}
		else if (HP > HpDenger) {
			fill(255, 255, 0);
		}
		else {
			fill(255, 0, 0);
		}
		rect(HpX, HpY, HP * 10, hpGaugeWidth);
		rectMode(CENTER);

		textSize(50);
		fill(0);
		text((let)HP, 1630, 1070);
	}

	void GAME::draw(){
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
		
		rectMode(CENTER);
		image(KizaruImg, PPx, PPy);
		image(EnelImg, EPx, EPy);

		fill(255, 0 ,0);
		textSize(75);
		text((let)GPR + "Pt", 90, 1080);

		fill(255, 255, 0);
		textSize(75);
		text((let)GPY + "Pt", 500, 1080);

		fill(0, 255, 255);
		textSize(75);
		text((let)GPB + "Pt", 880, 1080);

		fill(0, 180, 0);
		textSize(75);
		text((let)GPG + "Pt", 1280, 1080);

		fill(255, 0, 255);
		textSize(75);
		text((let)GPP + "Pt", 1670, 1080);

		fill(0);
		textSize(100);
		text((let)Point + "Pt", 0, 100);

		fill(255, 0, 50);
		textSize(100);
		text((let)ClearPoint + "Pt", 0, 200);


		if (StageCount == 3) {
			textSize(100);
			fill(0);
			text("Last", 0, 400);
		}
		else {
			textSize(100);
			fill(0);
			text((let)StageCount, 0, 400);
		}

		//�����蔻��G���A
		fill(255, 255, 255, 128);
		rect(PPx, PPy, PhalfW * 1.5f, PhalfH * 1.5f);
		rect(EPx, EPy, EhalfW * 1.5f, EhalfH * 1.5f);
	}

	void GAME::draw2(){
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

		//�����蔻��G���A
		fill(255, 255, 255, 128);
		rect(Px, Py, halfW, halfH);
		rect(EPx, EPy, EhalfW * 2.0f, EhalfH * 2.0f);
	}
}