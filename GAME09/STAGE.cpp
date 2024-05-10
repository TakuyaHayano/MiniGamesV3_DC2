#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
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
		game()->cloud()->init();
	}
	void STAGE::update() {
		game()->physics()->update();
	}
	void STAGE::draw() {
		clear(128);
		game()->backGround()->draw();
		game()->box()->draw();
		game()->cloud()->draw();
		game()->physics()->draw();
	}
	void STAGE::nextScene() {

	}
}