#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME02.h"
namespace GAME02
{
	int GAME::create()
	{
		png[0]  = loadImage("..\\MAIN\\assets\\game02\\scs00.png");
		png[1]  = loadImage("..\\MAIN\\assets\\game02\\scs01.png");
		png[2]  = loadImage("..\\MAIN\\assets\\game02\\scs02.png");
		png[3]  = loadImage("..\\MAIN\\assets\\game02\\scs03.png");
		png[4]  = loadImage("..\\MAIN\\assets\\game02\\scs04.png");
		png[5]  = loadImage("..\\MAIN\\assets\\game02\\scs05.png");
		png[6]  = loadImage("..\\MAIN\\assets\\game02\\scs06.png");
		png[7]  = loadImage("..\\MAIN\\assets\\game02\\scs07.png");
		png[8]  = loadImage("..\\MAIN\\assets\\game02\\scs08.png");
		png[9]  = loadImage("..\\MAIN\\assets\\game02\\scs09.png");
		png[10] = loadImage("..\\MAIN\\assets\\game02\\scs10.png");
		png[11] = loadImage("..\\MAIN\\assets\\game02\\scs11.png");
		png[12] = loadImage("..\\MAIN\\assets\\game02\\scs12.png");
		png[13] = loadImage("..\\MAIN\\assets\\game02\\scs13.png");
		png[14] = loadImage("..\\MAIN\\assets\\game02\\scs14.png");
		png[15] = loadImage("..\\MAIN\\assets\\game02\\scs15.png");

		snd[0] = loadSound("..\\MAIN\\assets\\game02\\peaceMove.wav");
		snd[1] = loadSound("..\\MAIN\\assets\\game02\\GOD.wav");
		snd[2] = loadSound("..\\MAIN\\assets\\game02\\さざ波.wav");
		return 0;
	}

	void GAME::destroy()
	{

	}

	void GAME::shuffle() {
		struct TEMP {
			float Px;
			float Py;
		};
		TEMP temp;
		for (int i = 0; i < 16; i++) {
			int rand = random() % 4;
			if (rand == 0) {
				if (peace[15].Px - peace[i].Px == peaceSize &&
					peace[15].Py == peace[i].Py)
				{
					temp.Px = peace[15].Px;
					peace[15].Px = peace[i].Px;
					peace[i].Px = temp.Px;

					temp.Py = peace[15].Py;
					peace[15].Py = peace[i].Py;
					peace[i].Py = temp.Py;
				}
			}

			if (rand == 1) {
				if (peace[i].Px - peace[15].Px == peaceSize &&
					peace[15].Py == peace[i].Py)
				{
					temp.Px = peace[15].Px;
					peace[15].Px = peace[i].Px;
					peace[i].Px = temp.Px;

					temp.Py = peace[15].Py;
					peace[15].Py = peace[i].Py;
					peace[i].Py = temp.Py;
				}
			}

			if (rand == 2) {
				if (peace[15].Py - peace[i].Py == peaceSize &&
					peace[15].Px == peace[i].Px)
				{
					temp.Px = peace[15].Px;
					peace[15].Px = peace[i].Px;
					peace[i].Px = temp.Px;

					temp.Py = peace[15].Py;
					peace[15].Py = peace[i].Py;
					peace[i].Py = temp.Py;
				}
			}

			if (rand == 3) {
				if (peace[i].Py - peace[15].Py == peaceSize &&
					peace[15].Px == peace[i].Px)
				{
					temp.Px = peace[15].Px;
					peace[15].Px = peace[i].Px;
					peace[i].Px = temp.Px;

					temp.Py = peace[15].Py;
					peace[15].Py = peace[i].Py;
					peace[i].Py = temp.Py;
				}
			}
		}
	}

	void GAME::init() {
		initflag = 1;
		peaceSize = 196.0f;

		for (int i = 0; i < 16; i++) {

			if (i % 4 == 0) {
				frame[i].Px = width / 2.0f - peaceSize * 2.0f;
			}
			if (i % 4 == 1) {
				frame[i].Px = width / 2.0f - peaceSize;
			}
			if (i % 4 == 2) {
				frame[i].Px = width / 2.0f;
			}
			if (i % 4 == 3) {
				frame[i].Px = width / 2.0f + peaceSize;
			}

			if (i / 4 == 0) {
				frame[i].Py = height / 2.0f - peaceSize * 2.0f;
			}
			if (i / 4 == 1) {
				frame[i].Py = height / 2.0f - peaceSize;
			}
			if (i / 4 == 2) {
				frame[i].Py = height / 2.0f;
			}
			if (i / 4 == 3) {
				frame[i].Py = height / 2.0f + peaceSize;
			}

		}
		
		for (int i = 0; i < 16; i++) {
			peace[i].Px = frame[i].Px;
			peace[i].Py = frame[i].Py;
		}

		selectframe.Px = frame[0].Px;
		selectframe.Py = frame[0].Py;
	}

	void GAME::draw() {

		stroke(0);
		strokeWeight(7);

		for (int i = 0; i < 16; i++) {
			rect(frame[i].Px, frame[i].Py, peaceSize, peaceSize);
		}

		for (int i = 0; i < 15; i++) {
			image(png[i], peace[i].Px, peace[i].Py);
		}
		for (int i = 0; i < 15; i++) {
			text((let)+(i + 1), peace[i].Px, peace[i].Py + 50);
		}
		stroke(255, 0, 0);
		fill(0, 0, 0, 0);
		rect(selectframe.Px, selectframe.Py, peaceSize, peaceSize);
		stroke(0);
	}

	void GAME::keyprocessing() {
		if (isTrigger(KEY_D) && selectframe.Px != frame[3].Px && selectframe.Px != frame[7].Px &&
								selectframe.Px != frame[11].Px && selectframe.Px != frame[15].Px) {
			selectframe.Px += peaceSize;
		}

		if (isTrigger(KEY_A) && selectframe.Px != frame[0].Px && selectframe.Px != frame[4].Px &&
								selectframe.Px != frame[8].Px && selectframe.Px != frame[12].Px) {
			selectframe.Px -= peaceSize;
		}

		if (isTrigger(KEY_W) && selectframe.Py != frame[0].Py && selectframe.Py != frame[1].Py &&
								selectframe.Py != frame[2].Py && selectframe.Py != frame[3].Py) {
			selectframe.Py -= peaceSize;
		}

		if (isTrigger(KEY_S) && selectframe.Py != frame[12].Py && selectframe.Py != frame[13].Py &&
								selectframe.Py != frame[14].Py && selectframe.Py != frame[15].Py) {
			selectframe.Py += peaceSize;
		}

		if (isPress(KEY_SPACE)) {
			peacemove();
		}
	}

	void GAME::peacemove() {
		struct TEMP {
			float Px;
			float Py;
		};
		TEMP temp;
		for (int i = 0; i < 16; i++) {
			if (selectframe.Px == peace[i].Px && selectframe.Py == peace[i].Py) {
				if (peace[15].Px - peace[i].Px == peaceSize &&
					peace[15].Py == peace[i].Py) {
					temp.Px = peace[15].Px;
					peace[15].Px = peace[i].Px;
					peace[i].Px = temp.Px;

					temp.Py = peace[15].Py;
					peace[15].Py = peace[i].Py;
					peace[i].Py = temp.Py;
					playSound(snd[0]);
					step++;
				}

				else if (peace[i].Px - peace[15].Px == peaceSize &&
					peace[15].Py == peace[i].Py) {
					temp.Px = peace[15].Px;
					peace[15].Px = peace[i].Px;
					peace[i].Px = temp.Px;

					temp.Py = peace[15].Py;
					peace[15].Py = peace[i].Py;
					peace[i].Py = temp.Py;
					playSound(snd[0]);
					step++;
				}

				else if (peace[15].Py - peace[i].Py == peaceSize &&
					peace[15].Px == peace[i].Px) {
					temp.Px = peace[15].Px;
					peace[15].Px = peace[i].Px;
					peace[i].Px = temp.Px;

					temp.Py = peace[15].Py;
					peace[15].Py = peace[i].Py;
					peace[i].Py = temp.Py;
					playSound(snd[0]);
					step++;
				}

				else if (peace[i].Py - peace[15].Py == peaceSize &&
					peace[15].Px == peace[i].Px) {
					temp.Px = peace[15].Px;
					peace[15].Px = peace[i].Px;
					peace[i].Px = temp.Px;

					temp.Py = peace[15].Py;
					peace[15].Py = peace[i].Py;
					peace[i].Py = temp.Py;
					playSound(snd[0]);
					step++;
				}
			}
		}
	}

	void GAME::clearCheck() {
		for (int i = 0; i < 16; i++) {
			if (peace[i].Px == frame[i].Px && peace[i].Py == frame[i].Py) {
				peaceSameP[i] = 1;
			}
			else {
				peaceSameP[i] = 0;
			}
		}
		if (peaceSameP[0] == 1 &&
			peaceSameP[1] == 1 &&
			peaceSameP[2] == 1 &&
			peaceSameP[3] == 1 &&
			peaceSameP[4] == 1 &&
			peaceSameP[5] == 1 &&
			peaceSameP[6] == 1 &&
			peaceSameP[7] == 1 &&
			peaceSameP[8] == 1 &&
			peaceSameP[9] == 1 &&
			peaceSameP[10] == 1 &&
			peaceSameP[11] == 1 &&
			peaceSameP[12] == 1 &&
			peaceSameP[13] == 1 &&
			peaceSameP[14] == 1 &&
			peaceSameP[15] == 1) {
			State = CLEAR;
			//playSound(snd[1]);
		}
	}

	void GAME::title() {
		clear(153, 204, 255);
		text("WASDキーでマスを選びSPACEキーで移動", width / 2 - 480, height / 2);
		text("Zキーでスタート", width / 2 - 240, height / 2 + 90);
		if (isTrigger(KEY_Z)) {
			State = PLAY;
		}
	}

	void GAME::play() {
		if (initflag == 0) {
			init();
			for (int i = 0; i < 500; i++)shuffle();;
		}

		if (BGMflag == 0) {
			playLoopSound(snd[2]);
			BGMflag++;
		}

		clear(153, 204, 255);
		
		draw();

		keyprocessing();

		clearCheck();
	}

	void GAME::gameClear() {
		clear(153, 204, 255);
		for (int i = 0; i < 16; i++) {
			rect(frame[i].Px, frame[i].Py, peaceSize, peaceSize);
		}
		for (int i = 0; i < 16; i++) {
			image(png[i], peace[i].Px, peace[i].Py);
		}
		text("Zキーでタイトルに戻る", width / 2 - 240, height - 90);
		if (isTrigger(KEY_Z)) {
			State = TITLE;
			initflag = 0;
			stopSound(snd[2]);
			BGMflag = 0;
		}
	}

	void GAME::proc()
	{
		textSize(50);
		fill(255);

		if (State == TITLE)title();
		else if (State == PLAY)play();
		else if (State == CLEAR)gameClear();

		text("ENTERキーでメニューに戻る", 0, 1080);
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}

	}
}
