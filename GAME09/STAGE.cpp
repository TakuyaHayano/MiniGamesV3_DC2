#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "../../libOne/inc/window.h"
#include "CONTAINER.h"
#include "GAME09.h"
#include "STAGE.h"

namespace GAME09
{
	STAGE::STAGE(class GAME* game) :
		SCENE(game) {

	}
	STAGE::~STAGE() {

	}
	void STAGE::create() {
		Stage = game()->container()->data().stage;
	}
	void STAGE::init() {
		game()->next()->init();  //ã
		game()->cloud()->init(); //‰º@‚±‚ê‚ð“ü‚ê‘Ö‚¦‚é‚Æ‚Ü‚¸‚¢
		game()->physics()->init();
		game()->score()->init();
		AnimeTime = 0;
		State = PLAY;
	}
	void STAGE::update() {
		if (State == PLAY) {
			game()->cloud()->update();
			game()->physics()->update();
			game()->next()->update();
			game()->score()->update();
			if (!game()->transition()->inEndFlag()) {
				game()->transition()->update();
			}
			if (game()->physics()->gameOverJudge()) {
				game()->cloud()->setFruitsPos();
				State = VIBE;
				game()->physics()->setVibe(true);
			}
		}
		else if (State == VIBE) {
			AnimeTime += delta;
			game()->physics()->update();
			game()->next()->update();
			game()->score()->update();
			if (AnimeTime > Stage.vibeTime) {
				AnimeTime = 0;
				State = WAIT;
				game()->physics()->setVibe(false);
			}
		}
		else if (State = WAIT) {
			AnimeTime += delta;
			game()->next()->update();
			game()->score()->update();
		}
	}
	void STAGE::draw() {
		//clear(128);
		game()->backGround()->draw();
		game()->box()->draw();
		game()->cloud()->draw();
		game()->physics()->draw();
		game()->box()->drawFront();
		game()->next()->draw();
		game()->score()->draw();
		game()->eCircle()->draw();
		image(Stage.operationImg, Stage.operationImgPos.x, Stage.operationImgPos.y, 0, Stage.operationImgSize);
	}
	void STAGE::nextScene() {
		if (State == WAIT && AnimeTime > Stage.waitTime) {
			game()->score()->setHiScore();
			game()->changeScene(GAME::RESULT_ID);
		}
		if (State == PLAY && game()->transition()->inEndFlag()) {
			if (isTrigger(KEY_X)) {
				game()->changeScene(GAME::PAUSE_ID);
			}
		}
	}
}