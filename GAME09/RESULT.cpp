#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "../../libOne/inc/mathUtil.h"
#include "CONTAINER.h"
#include "GAME09.h"
#include "RESULT.h"
#include "BUTTON_RETRY_RESULT.h"
#include "BUTTON_HELP.h"

namespace GAME09
{
	RESULT::RESULT(class GAME* game) :
		SCENE(game) {

	}
	RESULT::~RESULT() {
		for (int i = 0; i < NUM_BUTTONS; i++) {
			delete Buttons[i];
		}
	}
	void RESULT::create() {
		Result = game()->container()->data().result;
		Buttons[RETRY] = new BUTTON_RETRY_RESULT(game());
		Buttons[BACK] = new BUTTON_HELP(game());
		for (int i = 0; i < NUM_BUTTONS; i++) {
			Buttons[i]->create();
		}
	}
	void RESULT::init() {
		for (int i = 0; i < NUM_BUTTONS; i++) {
			Buttons[i]->init();
		}
		SelectButton = RETRY;
		Buttons[SelectButton]->setSelect(true, false);
	}
	void RESULT::update() {
		if (!game()->transition()->inEndFlag()) {
			game()->transition()->update();
			return;
		}
		if (isTrigger(KEY_W) || isTrigger(KEY_UP)) {
			if (SelectButton > 0) {
				Buttons[SelectButton]->setSelect(false);
				SelectButton = (BUTTON_KINDS)(SelectButton - 1);
				Buttons[SelectButton]->setSelect(true);
			}
		}
		else if (isTrigger(KEY_S) || isTrigger(KEY_DOWN)) {
			if (SelectButton < NUM_BUTTONS - 1) {
				Buttons[SelectButton]->setSelect(false);
				SelectButton = (BUTTON_KINDS)(SelectButton + 1);
				Buttons[SelectButton]->setSelect(true);
			}
		}
		for (int i = 0; i < NUM_BUTTONS; i++) {
			Buttons[i]->update();
		}
		if (isTrigger(KEY_R)) game()->getScene(GAME::STAGE_ID)->update();
	}
	void RESULT::draw() {
		clear(128);
		rectMode(CENTER);
		game()->getScene(GAME::STAGE_ID)->draw();
		fill(0, 0, 0, 100);
		noStroke();
		rect(width / 2, height / 2, width, height);
		image(Result.resultImg, Result.imgPos.x, Result.imgPos.y, 0, Result.imgSize);
		for (int i = 0; i < NUM_BUTTONS; i++) {
			Buttons[i]->draw();
		}
		if (!game()->transition()->inEndFlag()) {
			game()->transition()->draw();
		}
	}
	void RESULT::nextScene() {
		if (game()->transition()->inEndFlag()) {
			if (isTrigger(KEY_ENTER) || isTrigger(KEY_SPACE)) {
				switch (SelectButton)
				{
				case RETRY:
					game()->transition()->start();
					break;
				case BACK:
					game()->changeScene(GAME::TITLE_ID);
					break;
				default:
					break;
				}
			}
		}
		else {
			if (game()->transition()->outEndFlag()) {
				game()->changeScene(GAME::STAGE_ID);
			}
		}
	}
}