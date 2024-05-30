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
			playLoopSound(game()->container()->data().volume.Snd_A);
			loopBgm = false;
		}
		imageColor(240);
		image(game()->container()->data().stage.backImg, 0, 0);
		float size;
		font("UD デジタル 教科書体 NP-B");
		size = 100;
		textSize(size);
		fill(0);
		text("大迷路", width / 2.3f, height / 2.0f);
		size = 40;
		textSize(size);
		text("press space key to start", width / 2.6f, height / 1.45f);
		text("Ｏキー:オプション", width / 20.0f, height / 1.00625f);
		text("Ｐキー:操作説明", width / 3.0f, height / 1.00625f);
		fill(0);
		textSize(size);
		text("Enterキーでメニューに戻る", width / 1.5f, height / 1.00625f);
		game()->fade()->draw();
	}
	void TITLE::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->fade()->outTrigger();
			delibe = 1;
		}
		if (game()->fade()->outEndFlag() && (delibe == 1)) {
			game()->setCurScene(game()->stage());
		}
		if (isTrigger(KEY_O)) {
			game()->fade()->outTrigger();
			delibe = 2;
		}
		if (game()->fade()->outEndFlag() && (delibe == 2)) {
			game()->setCurScene(game()->volume());
		}
		if (isTrigger(KEY_P)) {
			game()->fade()->outTrigger();
			delibe = 3;
		}
		if (game()->fade()->outEndFlag() && (delibe == 3)) {
			game()->setCurScene(game()->operation());
		}
		if (isTrigger(KEY_ENTER)) {
			game()->backToMenu();
		}
	}
}