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
		loopBgm = true;
	}
	void TITLE::draw() {
		clear();
		rectMode(CORNER);
		if (loopBgm) {
			playLoopSound(game()->container()->data().volume.Snd_A);
			fopen_s(&fp, "assets/game03/data/volume.txt", "r");
			if (fp != NULL) {
				fscanf_s(fp, "%d\n%d\n", &f1, &f2);
				fclose(fp);
				setVolume(game()->container()->data().volume.Snd_A, -(100 - f1) * (100 - f1));
				setVolume(game()->container()->data().volume.Snd_B, -(100 - f1) * (100 - f1));
				setVolume(game()->container()->data().volume.Snd_C, -(100 - f1) * (100 - f1));
				setVolume(game()->container()->data().volume.Snd_D, -(100 - f1) * (100 - f1));
				setVolume(game()->container()->data().volume.Se_A, -(100 - f2) * (100 - f2));
				setVolume(game()->container()->data().volume.Se_B, -(100 - f2) * (100 - f2));
				setVolume(game()->container()->data().volume.Se_C, -(100 - f2) * (100 - f2));
			}
			loopBgm = false;
		}
		fopen_s(&fp, "assets/game03/data/score.txt", "r");
		if (fp != NULL) {
			fscanf_s(fp, "%d", &f3);
			fclose(fp);
		}
		if (reset == false) {
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
					text("high score " + (let)f3, width / 2.5f - 2.0f, height / 1.35f - (float)i * 1.0f - 0.1f);
					text("press space key to start", width / 2.6f - 2.0f, height / 1.45f - (float)i * 1.0f - 0.1f);
					text("Ｏキー:オプション", width / 20.0f - 2.0f, height / 1.00625f - (float)i * 1.0f - 0.1f);
					text("Ｒキー:リセット", width / 3.5f - 2.0f, height / 1.00625f - (float)i * 1.0f - 0.1f);
					text("Ｐキー:操作説明", width / 2.0f - 2.0f, height / 1.00625f - (float)i * 1.0f - 0.1f);
					text("Enterキーでメニューに戻る", width / 1.5f - 2.0f, height / 1.00625f - (float)i * 1.0f - 0.1f);
				}
				else {
					fill(50.0f + (float)i * 10.0f, 100, 30, (float)i * 10.0f);
					text("大迷路", width / 2.3f, height / 2.0f - (float)i * 1.0f);
					size = 40;
					textSize(size);
					text("high score " + (let)f3, width / 2.5f, height / 1.35f - (float)i * 1.0f);
					text("press space key to start", width / 2.6f, height / 1.45f - (float)i * 1.0f);
					text("Ｏキー:オプション", width / 20.0f, height / 1.00625f - (float)i * 1.0f);
					text("Ｒキー:リセット", width / 3.5f, height / 1.00625f - (float)i * 1.0f);
					text("Ｐキー:操作説明", width / 2.0f, height / 1.00625f - (float)i * 1.0f);
					text("Enterキーでメニューに戻る", width / 1.5f, height / 1.00625f - (float)i * 1.0f);
				}
			}
		}
		if (isTrigger(KEY_R)) {
			reset = true;
		}
		if (reset) {
			image(game()->container()->data().stage.backImg, 0, 0);
			fill(100);
			textSize(100);
			text("本当にリセットしますか？Y / N", width / 5.0f - 20.0f, height / 2.0f);
			if (isTrigger(KEY_Y)) {
				fopen_s(&fp,"assets/game03/data/score.txt", "w");
				if (fp != NULL) {
					fprintf_s(fp,"0");
					fclose(fp);
				}
				reset = false;
			}
			else if (isTrigger(KEY_N)) {
				reset = false;
			}
		}
		game()->fade()->draw();
	}
	void TITLE::nextScene() {
		if (reset == false) {
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
			if (isTrigger(KEY_ENTER) && (delibe == 0)) {
				game()->backToMenu();
			}
			if (game()->fade()->outEndFlag() && (delibe == 1)) {
				stopSound(game()->container()->data().volume.Snd_A);
				game()->setCurScene(game()->stage());
			}
			if (game()->fade()->outEndFlag() && (delibe == 2)) {
				stopSound(game()->container()->data().volume.Snd_A);
				game()->setCurScene(game()->volume());
			}
			if (game()->fade()->outEndFlag() && (delibe == 3)) {
				stopSound(game()->container()->data().volume.Snd_A);
				game()->setCurScene(game()->operation());
			}
		}
	}
}