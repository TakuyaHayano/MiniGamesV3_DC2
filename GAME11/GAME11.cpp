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
			sprintf_s(str, "..\\main\\assets\\game11\\Tramp‘fÞ\\H%d.png", i + 1);
			HImg[i] = loadImage(str);
			sprintf_s(str, "..\\main\\assets\\game11\\Tramp‘fÞ\\D%d.png", i + 1);
			DImg[i] = loadImage(str); 
			sprintf_s(str, "..\\main\\assets\\game11\\Tramp‘fÞ\\S%d.png", i + 1);
			SImg[i] = loadImage(str); 
			sprintf_s(str, "..\\main\\assets\\game11\\Tramp‘fÞ\\C%d.png", i + 1);
			CImg[i] = loadImage(str);
		}		
		TitleImg = loadImage("..\\main\\assets\\game11\\title.png");
		BackImg = loadImage("..\\main\\assets\\game11\\Tramp‘fÞ\\back.png");
		deleteImg = loadImage("..\\main\\assets\\game11\\Tramp‘fÞ\\delete.png");
		return 0;
	}

	void GAME::destroy()
	{
		delete sync;
	}

	void GAME::proc()
	{
		if (State == TITLE)Title();
		if (State == PLAY)Play(sync);
		if (State == CLEAR)Clear();
	}
	void GAME::Title() {
		clear(0, 171, 65);
		image(TitleImg, 0.0f, 0.0f);
		textSize(250);
		fill(0);
		text("ƒXƒs[ƒh", 460, 650);
		textSize(50);
		fill(0);
		text("ENTERƒL[‚Åƒƒjƒ…[‚É–ß‚é", 0, 1080);
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
		if (isTrigger(MOUSE_LBUTTON)) {
			Init();
			State = PLAY;
			return;
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
		ClearCnt = 0;

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
			ClearCnt++;
			FreamCnt = 60;
		}
		image(LfieldImg, LfieldPx, fieldPy);
		image(RfieldImg, RfieldPx, fieldPy);
		if (nextImg != sync->Deck[51].img) {
			image(BackImg, deckPx, fieldPy);
		}
		image(setImg[0], setPx1, ArraysetPy[0]);
		image(setImg[1], setPx2, ArraysetPy[1]);
		image(setImg[2], setPx3, ArraysetPy[2]);
		image(setImg[3], setPx4, ArraysetPy[3]);

		fill(255);
		
		text(RfieldNum, width / 2, height / 2 - 50);
		text(LfieldNum, width / 2, height / 2 + 50);
		for (int j = 0; j < 4; j++) {
			text(setImgNum[j], width / 2 + j * 50, 100);
		}
		text(FieldCheckCnt, width / 2, height / 2);
		text(ClearCnt, 10, height / 2);
		text(TrampCnt, 1850, 50);

		for (int i = 0; i < 4; i++) {
			text(setImgNum[i] + 1, 10, 100 + i * 50);
			text(setImgNum[i] - 1, 10, 800 + i * 50);
		}


		
		for (int i = 0; i < 4; i++) {
			if ((LfieldNum == setImgNum[i] + 1 || LfieldNum == setImgNum[i] - 1) || 
				(RfieldNum == setImgNum[i] + 1 || RfieldNum == setImgNum[i] - 1)) {
				FieldCheckCnt = 0;
			}
			else {
				FieldCheckCnt = 1;
			}
		}
		
		
		if (FieldCheckCnt == 1) {
			if (mouseX < deckPx + cX && mouseX > deckPx - cX &&
				mouseY < fieldPy + cY && mouseY > fieldPy - cY && 
				isTrigger(MOUSE_RBUTTON) ){
					LfieldImg = sync->Deck[TrampCnt + 6].img;
					LfieldNum = sync->Deck[TrampCnt + 6].num;
					RfieldImg = sync->Deck[TrampCnt + 7].img;
					RfieldNum = sync->Deck[TrampCnt + 7].num;
					TrampCnt = TrampCnt + 2;
					FieldCheckCnt = 0;
			}

		}

		if (mouseX < setPx1 + cX && mouseX > setPx1 - cX
			&& mouseY < setPy + cY && mouseY > setPy - cY) {
			if (setCnt[0] == 0) {
				if (isTrigger(MOUSE_LBUTTON)) {
					ArraysetPy[0] = PickPy;
					PickImg = setImg[0];
					JudgmentNum = setImgNum[0];
					setCnt[0]++;
					PickCnt++;
				}
			}
			else if (setCnt[0] == 1) {
				if (isTrigger(MOUSE_RBUTTON)) {
					ArraysetPy[0] = setPy;
					PickImg = 0;
					JudgmentNum = 0;
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
					PickImg = setImg[1];
					JudgmentNum = setImgNum[1];
					setCnt[1]++;
					PickCnt++;
				}
			}
			else if (setCnt[1] == 1) {
				if (isTrigger(MOUSE_RBUTTON)) {
					ArraysetPy[1] = setPy;
					PickImg = 0;
					JudgmentNum = 0;
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
					PickImg = setImg[2];
					JudgmentNum = setImgNum[2];
					setCnt[2]++;
					PickCnt++;
				}
			}
			else if (setCnt[2] == 1) {
				if (isTrigger(MOUSE_RBUTTON)) {
					ArraysetPy[2] = setPy;
					PickImg = 0;
					JudgmentNum = 0;
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
					PickImg = setImg[3];
					JudgmentNum = setImgNum[3];
					setCnt[3]++;
					PickCnt++;
				}
			}
			else if (setCnt[3] == 1) {
				if (isTrigger(MOUSE_RBUTTON)) {
					ArraysetPy[3] = setPy;
					PickImg = 0;
					JudgmentNum = 0;
					setCnt[3]--;
					PickCnt--;
				}
			}
		}

		if (ArraysetPy[0] == PickPy || ArraysetPy[1] == PickPy || ArraysetPy[2] == PickPy || ArraysetPy[3] == PickPy) {
			if (JudgmentNum == LfieldNum - 1 || JudgmentNum == LfieldNum + 1) {
				if (mouseX < LfieldPx + cX && mouseX > LfieldPx - cX &&
					mouseY < fieldPy + cY && mouseY > fieldPy - cY) {
					if (isTrigger(MOUSE_LBUTTON)) {
						for (int i = 0; i < 4; i++) {
							if (setCnt[i] == 1) {
								setImg[i] = deleteImg;
							}
						}
						if (TrampCnt != 47) {
							nextImg = sync->Deck[TrampCnt + 6].img;
							setNextImgNum = sync->Deck[TrampCnt + 6].num;
						}

						TrampCnt++;

						LfieldImg = PickImg;
						LfieldNum = JudgmentNum;
						JudgmentNum = 0;
						BackImg = nextImg;

					}
				}
			}


			if (JudgmentNum == RfieldNum + 1 || JudgmentNum == RfieldNum - 1) {
				if (mouseX < RfieldPx + cX && mouseX > RfieldPx - cX &&
					mouseY < fieldPy + cY && mouseY > fieldPy - cY) {
					if (isTrigger(MOUSE_LBUTTON)) {
						for (int i = 0; i < 4; i++) {
							if (setCnt[i] == 1) {
								setImg[i] = deleteImg;
							}
						}

						nextImg = sync->Deck[TrampCnt + 5].img;
						setNextImgNum = sync->Deck[TrampCnt + 5].num;

						TrampCnt++;

						RfieldImg = PickImg;
						RfieldNum = JudgmentNum;
						JudgmentNum = 0;
						BackImg = nextImg;
					}
				}
			}

			if (mouseX < deckPx + cX && mouseX > deckPx - cX &&
				mouseY < fieldPy + cY && mouseY > fieldPy - cY) {
				if (isTrigger(MOUSE_LBUTTON)) {
					for (int i = 0; i < 4; i++) {
						if (setCnt[i] == 1) {
							setImg[i] = BackImg;
							setImgNum[i] = setNextImgNum;
							JudgmentNum = 0;
							BackImg = loadImage("..\\main\\assets\\game11\\Tramp‘fÞ\\back.png");
							ArraysetPy[i] = ofstPy;
							setCnt[i]--;
							PickCnt--;
						}
					}
				}
			}
		}

		if (isTrigger(KEY_SPACE)) {
			State = CLEAR;
		}
	}
	
	void GAME::Clear() {
		clear();
		textSize(200);
		text(ClearCnt, width / 2, height / 2);
		if (isTrigger(KEY_ENTER)) {
			State = TITLE;
		}
	}
	
}
