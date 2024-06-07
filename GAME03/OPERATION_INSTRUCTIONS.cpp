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
	}
	void OPERATION_INSTRUCTIONS::draw() {
		clear(255);
		//image(OpInstructions.backimg, 0, 0);
		//textSize(90);
		//fill(0);
		//text("操作説明", width / 2.3f, height / 1.5f);
		textSize(40);
		fill(0);
		text("Enterキーでタイトルに戻る", width / 1.5f, height / 1.00625f);
		game()->fade()->draw();
	}
	void OPERATION_INSTRUCTIONS::nextScene() {
		if (isTrigger(KEY_ENTER)) {
			game()->fade()->outTrigger();
		}
		if (game()->fade()->outEndFlag()) {
			game()->setCurScene(game()->title());
		}
	}
}