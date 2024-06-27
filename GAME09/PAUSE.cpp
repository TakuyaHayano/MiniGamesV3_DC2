#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "../../libOne/inc/mathUtil.h"
#include "CONTAINER.h"
#include "GAME09.h"
#include "PAUSE.h"
#include "BUTTON_CONTINUE.h"
#include "BUTTON_RETRY_PAUSE.h"
#include "BUTTON_BACK_PAUSE.h"

namespace GAME09
{
	PAUSE::PAUSE(class GAME* game) :
		SCENE(game) {

	}
	PAUSE::~PAUSE() {
		for (int i = 0; i < NUM_BUTTONS; i++) {
			delete Buttons[i];
		}
	}
	void PAUSE::create() {
		Pause = game()->container()->data().pause;
		Buttons[CONTINUE] = new BUTTON_CONTINUE(game());
		Buttons[RETRY] = new BUTTON_RETRY_PAUSE(game());
		Buttons[RETURN] = new BUTTON_BACK_PAUSE(game());
		for (int i = 0; i < NUM_BUTTONS; i++) {
			Buttons[i]->create();
		}
	}
	void PAUSE::init() {
		for (int i = 0; i < NUM_BUTTONS; i++) {
			Buttons[i]->init();
		}
		SelectButton = CONTINUE;
		Buttons[SelectButton]->setSelect(true, false);
		State = START;
		AnimeTime = 0;
	}
	void PAUSE::update() {
		if (!game()->transition()->inEndFlag()) {
			game()->transition()->update();
			return;
		}
		if (State == NORMAL) {
			OfstY = 0;
			if (isTrigger(KEY_W) || isTrigger(KEY_UP)) {
				if (SelectButton > 0) {
					Buttons[SelectButton]->setSelect(false);
					SelectButton = (BUTTON_KINDS)(SelectButton - 1);
					Buttons[SelectButton]->setSelect(true);
					game()->soundMNG()->playSE(SOUNDMNG::STICK);
				}
			}
			else if (isTrigger(KEY_S) || isTrigger(KEY_DOWN)) {
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
		}
		else {
			angleMode(DEGREES);
			AnimeTime += delta;
			if (AnimeTime > Pause.moveDatas[State].animeTime) {
				AnimeTime -= Pause.moveDatas[State].animeTime;
				State = (STATE)(State + 1);
			}
			float ratio = AnimeTime / Pause.moveDatas[State].animeTime;
			ratio = (Cos(ratio * 180) - 1) / -2.0f;
			OfstY = Pause.moveDatas[State].startOfst * (1 - ratio) + Pause.moveDatas[State].endOfst * ratio;
		}
	}
	void PAUSE::draw() {
		clear(128);
		rectMode(CENTER);
		game()->getScene(GAME::STAGE_ID)->draw();
		fill(0, 0, 0, 70);
		noStroke();
		rect(width / 2, height / 2, width, height);
		setCornerPos(VECTOR2(0, OfstY));
		image(Pause.pauseImg, Pause.imgPos.x, Pause.imgPos.y, 0, Pause.imgSize);
		for (int i = 0; i < NUM_BUTTONS; i++) {
			Buttons[i]->draw();
		}
		setCornerPos(VECTOR2(0, 0));
	}
	void PAUSE::nextScene() {
		if (game()->transition()->inEndFlag()) {
			if (State == NORMAL) {
				if (isTrigger(KEY_ENTER) || isTrigger(KEY_SPACE)) {
					switch (SelectButton)
					{
					case CONTINUE:
						game()->returnScene(GAME::STAGE_ID);
						break;
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