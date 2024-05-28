#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "CONTAINER.h"
#include "GAME09.h"
#include "TITLE.h"
#include "BUTTON_START.h"
#include "BUTTON_HELP.h"
#include "BUTTON_END.h"

namespace GAME09
{
	TITLE::TITLE(class GAME* game) :
		SCENE(game) {

	}
	TITLE::~TITLE() {
		for (int i = 0; i < NUM_BUTTONS; i++) {
			delete Buttons[i];
		}
	}
	void TITLE::create() {
		Title = game()->container()->data().title;
		Buttons[START] = new BUTTON_START(game());
		Buttons[HELP] = new BUTTON_HELP(game());
		Buttons[END] = new BUTTON_END(game());
		for (int i = 0; i < NUM_BUTTONS; i++) {
			Buttons[i]->create();
		}
	}
	void TITLE::init() {
		for (int i = 0; i < NUM_BUTTONS; i++) {
			Buttons[i]->init();
		}
		SelectButton = START;
		Buttons[SelectButton]->setSelect(true, false);
	}
	void TITLE::update() {
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
	}
	void TITLE::draw() {
		clear(128);
		game()->backGround()->draw();
		for (int i = 0; i < NUM_BUTTONS; i++) {
			Buttons[i]->draw();
		}
		image(Title.titleImg, Title.titlePos.x, Title.titlePos.y, 0, Title.imgSize);
		if (!game()->transition()->inEndFlag()) {
			game()->transition()->draw();
		}
	}
	void TITLE::nextScene() {
		if (game()->transition()->inEndFlag()) {
			if (isTrigger(KEY_ENTER) || isTrigger(KEY_SPACE)) {
				switch (SelectButton)
				{
				case START:
					game()->transition()->start();
					break;
				case HELP:
					break;
				case END:
					game()->backToMenu();
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