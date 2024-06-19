#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
#include "../../libOne/inc/libOne.h"
#include"../MAIN/GAME_BASE.h"
#include "../MAIN/MAIN.h"
#include"GAME03.h"
#include"CONTAINER.h"
#include"VOLUME.h"
#include"STAGE.h"
#include"FADE.h"
#include "TITLE.h"
namespace GAME03 {
	void TITLE::init() {
		game()->fade()->inTrigger();
		delibe = 0;
		//loopBgm = true;
	}
	void TITLE::draw() {
		clear();
		rectMode(CORNER);
		if (loopBgm) {
			int f1 = 0, f2 = 0;
			playLoopSound(game()->container()->data().volume.Snd_A);
			fopen_s(&fp, "assets/game03/data/volume.txt", "r");
			if (fp != NULL) {
				fscanf_s(fp, "%d\n%d\n", &f1, &f2);
				fclose(fp);
				setVolume(game()->container()->data().volume.Snd_A, -(100 - f1) * (100 - f1));
				setVolume(game()->container()->data().volume.Se_A, -(100 - f2) * (100 - f2));
				setVolume(game()->container()->data().volume.Se_B, -(100 - f2) * (100 - f2));
				setVolume(game()->container()->data().volume.Se_C, -(100 - f2) * (100 - f2));
			}
			loopBgm = false;
		}
		imageColor(240);
		image(game()->container()->data().stage.backImg, 0, 0);
		float size;
		font("UD デジタル 教科書体 NP-B");
		for (int i = 0; i < 10; i++) {
			size = 100;
			textSize(size);
			if (i == 8) {
				fill(255, 255, 255, 150);
				text("大迷路", width / 2.3f - 3.0f, height / 2.0f - (float)i * 1.0f - 1.0f);
				size = 40;
				textSize(size);
				text("press space key to start", width / 2.6f - 2.0f, height / 1.45f - (float)i * 1.0f - 0.1f);
				text("Ｏキー:オプション", width / 20.0f - 2.0f, height / 1.00625f - (float)i * 1.0f - 0.1f);
				text("Ｐキー:操作説明", width / 3.0f - 2.0f, height / 1.00625f - (float)i * 1.0f - 0.1f);
				text("Enterキーでメニューに戻る", width / 1.5f - 2.0f, height / 1.00625f - (float)i * 1.0f - 0.1f);
			}
			else {
				fill(50.0f + (float)i * 10.0f, 30, 100, (float)i * 10.0f);
				text("大迷路", width / 2.3f, height / 2.0f - (float)i * 1.0f);
				size = 40;
				textSize(size);
				text("press space key to start", width / 2.6f, height / 1.45f - (float)i * 1.0f);
				text("Ｏキー:オプション", width / 20.0f, height / 1.00625f - (float)i * 1.0f);
				text("Ｐキー:操作説明", width / 3.0f, height / 1.00625f - (float)i * 1.0f);
				text("Enterキーでメニューに戻る", width / 1.5f, height / 1.00625f - (float)i * 1.0f);
			}
		}
		game()->fade()->draw();
	}
	void TITLE::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->fade()->outTrigger();
			delibe = 1;
		}
		if (isTrigger(KEY_O)) {
			game()->fade()->outTrigger();
			delibe = 2;
		}
		if (isTrigger(KEY_P)) {
			game()->fade()->outTrigger();
			delibe = 3;
		}
		if (game()->fade()->outEndFlag() && (delibe == 1)) {
			game()->setCurScene(game()->stage());
		}
		if (game()->fade()->outEndFlag() && (delibe == 2)) {
			game()->setCurScene(game()->volume());
		}
		if (game()->fade()->outEndFlag() && (delibe == 3)) {
			game()->setCurScene(game()->operation());
		}
		if (isTrigger(KEY_ENTER)) {
			game()->backToMenu();
		}
	}
}