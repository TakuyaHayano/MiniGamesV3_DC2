#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "../../libOne/inc/mathUtil.h"
#include "CONTAINER.h"
#include "GAME09.h"
#include "RESULT.h"
#include "BUTTON_RETRY_RESULT.h"
#include "BUTTON_BACK_RESULT.h"

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
		Buttons[RETURN] = new BUTTON_BACK_RESULT(game());
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
		State = START;
		AnimeTime = 0;
		game()->cracker()->init();
	}
	void RESULT::update() {
		if (!game()->transition()->inEndFlag()) {
			game()->transition()->update();
			return;
		}
		if (State == NORMAL) {
			OfstY = 0;
			if (isTrigger(KEY_A) || isTrigger(KEY_LEFT)) {
				if (SelectButton > 0) {
					Buttons[SelectButton]->setSelect(false);
					SelectButton = (BUTTON_KINDS)(SelectButton - 1);
					Buttons[SelectButton]->setSelect(true);
					game()->soundMNG()->playSE(SOUNDMNG::STICK);
				}
			}
			else if (isTrigger(KEY_D) || isTrigger(KEY_RIGHT)) {
				if (SelectButton < NUM_BUTTONS - 1) {
					Buttons[SelectButton]->setSelect(false);
					SelectButton = (BUTTON_KINDS)(SelectButton + 1);
					Buttons[SelectButton]->setSelect(true);
					game()->soundMNG()->playSE(SOUNDMNG::STICK);
				}
			}
			for (int i = 0; i < NUM_BUTTONS; i++) {
				Buttons[i]->update();
			}
			game()->cracker()->update();
		}
		else {
			angleMode(DEGREES);
			AnimeTime += delta;
			if (AnimeTime > Result.moveDatas[State].animeTime) {
				AnimeTime -= Result.moveDatas[State].animeTime;
				State = (STATE)(State + 1);
			}
			float ratio = AnimeTime / Result.moveDatas[State].animeTime;
			ratio = (Cos(ratio * 180) - 1) / -2.0f;
			OfstY = Result.moveDatas[State].startOfst * (1 - ratio) + Result.moveDatas[State].endOfst * ratio;
		}
	}
	void RESULT::draw() {
		clear(128);
		rectMode(CENTER);
		game()->getScene(GAME::STAGE_ID)->draw();
		fill(0, 0, 0, 150);
		noStroke();
		rect(width / 2, height / 2, width, height);
		setCornerPos(VECTOR2(0, OfstY));
		image(Result.resultImg, Result.imgPos.x, Result.imgPos.y, 0, Result.imgSize);
		for (int i = 0; i < NUM_BUTTONS; i++) {
			Buttons[i]->draw();
		}
		game()->drawNum()->draw(game()->score()->getCurScore(), Result.scorePos, Result.scoreSize);
		image(Result.resultHiScoreImg, Result.hiScoreImgPos.x, Result.hiScoreImgPos.y, 0, Result.hiScoreImgSize);
		game()->drawNum()->draw(game()->score()->getHiScore(), Result.hiScorePos, Result.hiScoreSize);
		game()->cracker()->draw();
		image(Result.resultScoreImg, Result.imgPos.x, Result.imgPos.y, 0, Result.imgSize);
		addCornerPos(Result.finalFieldPos);
		setMagnification(Result.finalFieldSize);
		game()->getScene(GAME::STAGE_ID)->draw();
		setCornerPos(VECTOR2(0,0));
		setMagnification(1);
		image(Result.operationImg, Result.operationImgPos.x, Result.operationImgPos.y, 0, Result.operationImgSize);
	}
	void RESULT::nextScene() {
		if (game()->transition()->inEndFlag()) {
			if (State == NORMAL) {
				if (isTrigger(KEY_ENTER) || isTrigger(KEY_SPACE)) {
					switch (SelectButton)
					{
					case RETRY:
						game()->transition()->start();
						break;
					case RETURN:
						game()->changeScene(GAME::TITLE_ID);
						break;
					default:
						break;
					}
					game()->soundMNG()->playSE(SOUNDMNG::DROP);
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