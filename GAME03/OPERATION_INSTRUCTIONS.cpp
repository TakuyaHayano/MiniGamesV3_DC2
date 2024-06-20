#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
#include "../../libOne/inc/libOne.h"
#include"../MAIN/GAME_BASE.h"
#include "../MAIN/MAIN.h"
#include"GAME03.h"
#include"CONTAINER.h"
#include"FADE.h"
#include "OPERATION_INSTRUCTIONS.h"
namespace GAME03 {
	void OPERATION_INSTRUCTIONS::create() {
		OpInstructions = game()->container()->data().operationInstructions;
	}
	void OPERATION_INSTRUCTIONS::init() {
		game()->fade()->inTrigger();
		loopBgm = true;
	}
	void OPERATION_INSTRUCTIONS::draw() {
		if (loopBgm) {
			playLoopSound(game()->container()->data().volume.Snd_D);
			loopBgm = false;
		}
		clear(255);
		image(OpInstructions.backimg, 0, 0);
		for (int i = 0; i < 10; i++) {
			if (i == 8) {
				fill(255, 255, 255, 150);
				textSize(40);
				text("Enterキーでメニューに戻る", width / 1.5f - 2.0f, height / 1.00625f - (float)i * 1.0f - 0.1f);
			}
			else {
				textSize(40);
				fill(50.0f + (float)i * 10.0f, 30, 100, (float)i * 10.0f);
				text("Enterキーでメニューに戻る", width / 1.5f - 2.0f, height / 1.00625f - (float)i * 1.0f - 0.1f);
			}
		}
		game()->fade()->draw();
	}
	void OPERATION_INSTRUCTIONS::nextScene() {
		if (isTrigger(KEY_ENTER)) {
			stopSound(game()->container()->data().volume.Snd_D);
			game()->fade()->outTrigger();
		}
		if (game()->fade()->outEndFlag()) {
			game()->setCurScene(game()->title());
		}
	}
}