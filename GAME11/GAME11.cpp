#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME11.h"

#define TRAMP_NUM (ONETYPE_NUM  * TRAMP_TYPE)
#define ONETYPE_NUM 13
#define TRAMP_TYPE 4
namespace GAME11
{
	int GAME::create()
	{
		sync = new TrampSync;

		State = TITLE;
		char str[100];
		for (int i = 0; i <= 12; ++i) {
			sprintf_s(str, "..\\main\\assets\\game11\\Tramp素材\\H%d.png", i + 1);
			HImg[i] = loadImage(str);
			sprintf_s(str, "..\\main\\assets\\game11\\Tramp素材\\D%d.png", i + 1);
			DImg[i] = loadImage(str); 
			sprintf_s(str, "..\\main\\assets\\game11\\Tramp素材\\S%d.png", i + 1);
			SImg[i] = loadImage(str); 
			sprintf_s(str, "..\\main\\assets\\game11\\Tramp素材\\C%d.png", i + 1);
			CImg[i] = loadImage(str);
		}		
		TitleImg = loadImage("..\\main\\assets\\game11\\title.png");
		BackImg = loadImage("..\\main\\assets\\game11\\Tramp素材\\back.png");
		DeleteImg = loadImage("..\\main\\assets\\game11\\Tramp素材\\delete.png");
		GameclearImg = loadImage("..\\main\\assets\\game11\\Tramp素材\\GameClear.png");
		RitireImg = loadImage("..\\main\\assets\\game11\\Tramp素材\\Ritire.png");
		GameOverImg = loadImage("..\\main\\assets\\game11\\Tramp素材\\GameOver.png");

		EasyImg = loadImage("..\\main\\assets\\game11\\Tramp素材\\Easy.png");//560*280
		NormalImg = loadImage("..\\main\\assets\\game11\\Tramp素材\\Normal.png");//770*260
		HardImg = loadImage("..\\main\\assets\\game11\\Tramp素材\\Hard.png");//570*260
		ExpertImg = loadImage("..\\main\\assets\\game11\\Tramp素材\\Expert.png");//710*280

		return 0;
	}

	void GAME::destroy()
	{
		delete sync;
	}

	void GAME::proc()
	{
		if (State == TITLE)Title();
		if (State == OPERATION)Operation();
		if (State == LEVEL)Level();
		if (State == PLAY)Play(sync);
		if (State == CLEAR)Clear();
		if (State == OVER)Over();
	}
	void GAME::Title() {
		rectMode(CENTER);
		clear(0, 171, 65);
		image(TitleImg, width/2, height/2);
		textSize(250);
		fill(0);
		text("スピード", 460, 650);
		textSize(50);
		fill(0);
		text("Q：操作説明", 500, 1020);
		text("SPACE:モード選択", 1000, 1020);
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
		if (isTrigger(KEY_SPACE)) {
			Init();
			State = LEVEL;
			return;
		}
		if (isTrigger(KEY_Q)) {
			State = OPERATION;
			return;
		}
	}
	void GAME::Operation() {
		clear(0,171,65);
		textSize(50);
		fill(0);
		text("・下４枚のカードの上で左クリックして選択、",50,100);
		text("上にあるカードの置きたい方の上でもう一度左クリックでカードを置ける", 50, 125 * 1 + 100);
		text("・カードを間違えて選択した場合は、選んだカードの上で右クリックで戻せる。", 50, 150 * 2 + 100);
		text("・カードを置いた後は、デッキの上で左クリックすることでカードを補充できる。", 50, 150 * 3 + 100);
		text("・制限時間内にデッキを0枚にしたらゲームクリア。", 50, 150 * 4 + 100);
		text("・難易度Expertは制限時間内にデッキとカードを0枚にしたらゲームクリア。", 50, 150 * 5 + 100);
		text("・ゲームプレイ中は、Xキーを押すとリタイアできる。", 50, 150 * 6 + 100);
		text("B：タイトル", 1400, 1040);

		if (isTrigger(KEY_B)) {
			State = TITLE;
			return;
		}
	}
	void GAME::Level() {
		textSize(100);
		fill(0);
		clear(0, 171, 65);
		image(EasyImg, 480, 225);
		text("120秒", 400, 500);
		image(NormalImg, 1440, 225);
		text("90秒", 1400, 500);
		image(HardImg, 480, 735);
		text("60秒", 400, 980);
		image(ExpertImg, 1440, 735);
		text("90秒", 1400, 980);

		if (mouseX > 480 - 300 && mouseX < 480 + 300 && mouseY > 225 - 150 && mouseY < 225 + 150) {//EASY
			if (isTrigger(MOUSE_LBUTTON)) {
				Init();
				CountDownCnt = 120;
				State = PLAY;
				return;
			}
		}
		if (mouseX > 1440 - 400 && mouseX < 1440 + 400 && mouseY > 225 - 140 && mouseY < 225 + 140) {//Noraml
			if (isTrigger(MOUSE_LBUTTON)) {
				Init();
				CountDownCnt = 90;
				State = PLAY;
				return;
			}
		}
		if (mouseX > 480 - 300 && mouseX < 480 + 300 && mouseY > 735 - 140 && mouseY < 735 + 140) {//Hard
			if (isTrigger(MOUSE_LBUTTON)) {
				Init();
				CountDownCnt = 60;
				State = PLAY;
				return;
			}
		}
		if (mouseX > 1440 - 375 && mouseX < 1440 + 375 && mouseY > 735 - 150 && mouseY < 735 + 150) {//Expert
			if (isTrigger(MOUSE_LBUTTON)) {
				Init();
				CountDownCnt = 90;
				LevelFlag = 1;
				State = PLAY;
				return;
			}
		}
		
	}
	void GAME::initializeDeck(TrampSync* sync) {
		int index = 0;
		for (int number = 1; number <= 13; ++number) {
			sync->Deck[index].num = number;
			sync->Deck[index].suit = 'H';
			sync->Deck[index].img = HImg[number - 1];
			++index;
		}
		for (int number = 1; number <= 13; ++number) {
			sync->Deck[index].num = number;
			sync->Deck[index].suit = 'D';
			sync->Deck[index].img = DImg[number - 1];
			++index;
		}
		for (int number = 1; number <= 13; ++number) {
			sync->Deck[index].num = number;
			sync->Deck[index].suit = 'S';
			sync->Deck[index].img = SImg[number - 1];
			++index;
		}
		for (int number = 1; number <= 13; ++number) {
			sync->Deck[index].num = number;
			sync->Deck[index].suit = 'C';
			sync->Deck[index].img = CImg[number - 1];
			++index;
		}
	}
	void GAME::shuffleDeck(TrampSync *sync) {
		srand(time(NULL));
		for (int i = 0; i < 52; ++i) {
			int j = rand() % 52;

			struct TRAMP temp = sync-> Deck[i];
			sync->Deck[i] = sync->Deck[j];
			sync->Deck[j] = temp;
		}
	}

	void GAME::Init() {
		deckPx = 1620.0f;
		ofstPy = 900.0f;
		setPy = 900.0f;
		ArraysetPy[0] = 900.0f;
		ArraysetPy[1] = 900.0f;
		ArraysetPy[2] = 900.0f;
		ArraysetPy[3] = 900.0f;
		setPx1 = 300.0f;
		setPx2 = 740.0f;
		setPx3 = 1180.0f;
		setPx4 = 1620.0f;
		LfieldPx = 520.0f;
		RfieldPx = 960.0f;
		fieldPy = 300.0f;

		cX = 125.0f;
		cY = 175.0f;
		PickPy = 800.0f;

		initializeDeck(sync);
		shuffleDeck(sync);


		setImg[0] = sync->Deck[2].img;
		setImg[1] = sync->Deck[3].img;
		setImg[2] = sync->Deck[4].img;
		setImg[3] = sync->Deck[5].img;

		setImgNum[0] = sync->Deck[2].num;
		setImgNum[1] = sync->Deck[3].num;
		setImgNum[2] = sync->Deck[4].num;
		setImgNum[3] = sync->Deck[5].num;


		LfieldImg = sync->Deck[0].img;
		RfieldImg = sync->Deck[1].img;

		LfieldNum = sync->Deck[0].num;
		RfieldNum = sync->Deck[1].num;

		FreamCnt = 60;
		CountDownCnt = 0;
		LevelFlag = 0;
		RitireFlag = 0;
		TrampCnt = 0;

		LfieldClearCnt = 0;
		RfieldClearCnt = 0;
	}
	int GAME::CheckField(int LNum, int RNum,int setINum[4]) {
		for (int i = 0; i < 4; i++) {
			if ((LfieldNum == setImgNum[i] + 1 || LfieldNum == setImgNum[i] - 1) ||
				(RfieldNum == setImgNum[i] + 1 || RfieldNum == setImgNum[i] - 1)) {
				FieldCheckCnt++;
			}
		}
		return FieldCheckCnt;
	}
	void GAME::Play(TrampSync* sync) {
		rectMode(CENTER);

		clear(0, 171, 65);

		FreamCnt--;
		if (FreamCnt == 0) {
			CountDownCnt--;
			FreamCnt = 60;
		}
		image(LfieldImg, LfieldPx, fieldPy);
		image(RfieldImg, RfieldPx, fieldPy);
		if (DeckPrintCnt < 46) {
			image(BackImg, deckPx, fieldPy);
		}
		
		image(setImg[0], setPx1, ArraysetPy[0]);
		image(setImg[1], setPx2, ArraysetPy[1]);
		image(setImg[2], setPx3, ArraysetPy[2]);
		image(setImg[3], setPx4, ArraysetPy[3]);

		fill(0);
		
		textSize(100);
		text(CountDownCnt, 30, height / 2);

		/*動作確認
		text(RfieldNum, width / 2, height / 2 - 50);
		text(LfieldNum, width / 2, height / 2 + 50);
		for (int j = 0; j < 4; j++) {
			//text(setImgNum[j], width / 2 + j * 50, 100);
		}
		text(FieldCheckCnt, width / 2, height / 2);
		text(TrampCnt, 1850, 50);

		for (int i = 0; i < 4; i++) {
			//text(setImgNum[i] + 1, 10, 100 + i * 50);
			//text(setImgNum[i] - 1, 10, 800 + i * 50);
		}
		*/

		
		
		for (int i = 0; i < 4; i++) {//場のカードの判定
			if ((LfieldNum == setImgNum[i] + 1 || LfieldNum == setImgNum[i] - 1) || (RfieldNum == setImgNum[i] + 1 || RfieldNum == setImgNum[i] - 1) ||
				((LfieldNum == 13 && PickNum == 1) || (LfieldNum == 1 && PickNum == 13)) ||
				((RfieldNum == 13 && PickNum == 1) || (RfieldNum == 1 && PickNum == 13))) {
				FieldCheckCnt = 0;
			}
			else {
				FieldCheckCnt = 1;
			}
		}
		
		if (TrampCnt < 45) {
			if (FieldCheckCnt == 1) {//上の判定でフラッグが立ってたらデッキを右クリックすると場のカードを二枚デッキから置く
				if (mouseX < deckPx + cX && mouseX > deckPx - cX &&
					mouseY < fieldPy + cY && mouseY > fieldPy - cY &&
					isTrigger(MOUSE_RBUTTON)) {
					LfieldImg = sync->Deck[TrampCnt + 6].img;
					LfieldNum = sync->Deck[TrampCnt + 6].num;
					RfieldImg = sync->Deck[TrampCnt + 7].img;
					RfieldNum = sync->Deck[TrampCnt + 7].num;
					LfieldClearCnt++;
					RfieldClearCnt++;
					TrampCnt = TrampCnt + 2;
					DeckPrintCnt = TrampCnt;
					FieldCheckCnt = 0;
				}

			}
		}

		if (mouseX < setPx1 + cX && mouseX > setPx1 - cX
			&& mouseY < setPy + cY && mouseY > setPy - cY) {
			if (setCnt[0] == 0) {
				if (isTrigger(MOUSE_LBUTTON)) {
					ArraysetPy[0] = PickPy;
					PickImage = setImg[0];
					PickNum = setImgNum[0];
					setCnt[0]++;
					PickCnt++;
				}
			}
			else if (setCnt[0] == 1) {
				if (isTrigger(MOUSE_RBUTTON)) {
					ArraysetPy[0] = setPy;
					PickImage = 0;
					PickNum = 0;
					setCnt[0]--;
					PickCnt--;
				}
			}

		}
		else if (mouseX <setPx2 + cX && mouseX > setPx2 - cX
			&& mouseY < setPy + cY && mouseY > setPy - cY) {
			if (setCnt[1] == 0) {
				if (isTrigger(MOUSE_LBUTTON)) {
					ArraysetPy[1] = PickPy;
					PickImage = setImg[1];
					PickNum = setImgNum[1];
					setCnt[1]++;
					PickCnt++;
				}
			}
			else if (setCnt[1] == 1) {
				if (isTrigger(MOUSE_RBUTTON)) {
					ArraysetPy[1] = setPy;
					PickImage = 0;
					PickNum = 0;
					setCnt[1]--;
					PickCnt--;
				}
			}
		}
		else if (mouseX <setPx3 + cX && mouseX > setPx3 - cX
			&& mouseY <setPy + cY && mouseY > setPy - cY) {
			if (setCnt[2] == 0) {
				if (isTrigger(MOUSE_LBUTTON)) {
					ArraysetPy[2] = PickPy;
					PickImage = setImg[2];
					PickNum = setImgNum[2];
					setCnt[2]++;
					PickCnt++;
				}
			}
			else if (setCnt[2] == 1) {
				if (isTrigger(MOUSE_RBUTTON)) {
					ArraysetPy[2] = setPy;
					PickImage = 0;
					PickNum = 0;
					setCnt[2]--;
					PickCnt--;
				}
			}

		}
		else if (mouseX <setPx4 + cX && mouseX > setPx4 - cX
			&& mouseY <setPy + cY && mouseY > setPy - cY) {
			if (setCnt[3] == 0) {
				if (isTrigger(MOUSE_LBUTTON)) {
					ArraysetPy[3] = PickPy;
					PickImage = setImg[3];
					PickNum = setImgNum[3];
					setCnt[3]++;
					PickCnt++;
				}
			}
			else if (setCnt[3] == 1) {
				if (isTrigger(MOUSE_RBUTTON)) {
					ArraysetPy[3] = setPy;
					PickImage = 0;
					PickNum = 0;
					setCnt[3]--;
					PickCnt--;
				}
			}
		}

		if (ArraysetPy[0] == PickPy || ArraysetPy[1] == PickPy || ArraysetPy[2] == PickPy || ArraysetPy[3] == PickPy) {
			if (PickNum == LfieldNum - 1 || PickNum == LfieldNum + 1 ||
				((LfieldNum == 13 && PickNum == 1) || (LfieldNum == 1 && PickNum == 13))) {
				if (mouseX < LfieldPx + cX && mouseX > LfieldPx - cX &&
					mouseY < fieldPy + cY && mouseY > fieldPy - cY) {
					if (isTrigger(MOUSE_LBUTTON)) {
						for (int i = 0; i < 4; i++) {
							if (setCnt[i] == 1) {
								setImg[i] = DeleteImg;
							}
						}

						if (TrampCnt < 46) {
							nextImage = sync->Deck[TrampCnt + 6].img;
							setNextImgNum = sync->Deck[TrampCnt + 6].num;
						}

						LfieldImg = PickImage;
						LfieldNum = PickNum;
						PickNum = 0;
						BackImg = nextImage;

						TrampCnt++;
					}
				}
			}

			if (PickNum == RfieldNum + 1 || PickNum == RfieldNum - 1 || 
				((RfieldNum == 13 && PickNum == 1) || (RfieldNum == 1 && PickNum == 13))) {
				if (mouseX < RfieldPx + cX && mouseX > RfieldPx - cX &&
					mouseY < fieldPy + cY && mouseY > fieldPy - cY) {
					if (isTrigger(MOUSE_LBUTTON)) {
						for (int i = 0; i < 4; i++) {
							if (setCnt[i] == 1) {
								setImg[i] = DeleteImg;
							}
						}

						if (TrampCnt < 46) {
							nextImage = sync->Deck[TrampCnt + 6].img;
							setNextImgNum = sync->Deck[TrampCnt + 6].num;

						}

						RfieldImg = PickImage;
						RfieldNum = PickNum;
						PickNum = 0;
						BackImg = nextImage;

						TrampCnt++;
					}
				}
			}
			if (TrampCnt < 46) {
				if (mouseX < deckPx + cX && mouseX > deckPx - cX &&
					mouseY < fieldPy + cY && mouseY > fieldPy - cY) {
					if (isTrigger(MOUSE_LBUTTON)) {
						DeckPrintCnt = TrampCnt;
						for (int i = 0; i < 4; i++) {
							if (setCnt[i] == 1) {
								setImg[i] = BackImg;
								setImgNum[i] = setNextImgNum;
								PickNum = 0;
								BackImg = loadImage("..\\main\\assets\\game11\\Tramp素材\\back.png");
								ArraysetPy[i] = ofstPy;
								setCnt[i]--;
								PickCnt--;
							}
						}
					}
				}
			}
		}
		if (LevelFlag == 0) {
			if (DeckPrintCnt == 46) {
				State = CLEAR;
			}
		}
		if (LevelFlag == 1) {
			if (LfieldClearCnt + RfieldClearCnt + 2 == 51) {
				State == CLEAR;
			}
		}
		if (isTrigger(KEY_X)) {
			RitireFlag = 1;
			State = OVER;
		}
		if (CountDownCnt == 0) {
			State = OVER;
		}
	}
	
	void GAME::Clear() {
		clear(0,0,200);
		fill(255, 215, 0);
		textSize(50);
		text("ENTERキーを押してタイトルに戻る", 20, 1050);
		textSize(200);
		image(GameclearImg, width / 2, height / 2);
		if (isTrigger(KEY_ENTER)) {
			State = TITLE;
		}
	}
	
	void GAME::Over() {
		clear();
		fill(255, 0, 0);
		textSize(50);
		text("ENTERキーを押してタイトルに戻る", 20, 1050);
		textSize(200);
		if (RitireFlag == 1) {
			image(RitireImg, width / 2, height / 2);
		}
		else {
			image(GameOverImg, width / 2, height / 2);
		}

		if (isTrigger(KEY_ENTER)) {
			State = TITLE;
		}
	}
}
