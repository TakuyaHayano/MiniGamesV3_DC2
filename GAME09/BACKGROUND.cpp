#include "BACKGROUND.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/input.h"

namespace GAME09
{
	BACKGROUND::BACKGROUND(GAME* game) :
		GAME_OBJECT(game) {

	}
	BACKGROUND::~BACKGROUND() {

	}

	void BACKGROUND::create() {
		BackG = game()->container()->data().backG;
	}

	void BACKGROUND::update() {

	}

	void BACKGROUND::draw() {
		rectMode(CENTER);
		image(BackG.img, BackG.pos.x, BackG.pos.y, 0, BackG.imgSize);
	}
}