#include "EVOLUTIONARY_CIRCLE.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/input.h"

namespace GAME09
{
	EVOLUTIONARY_CIRCLE::EVOLUTIONARY_CIRCLE(GAME* game) :
		GAME_OBJECT(game) {

	}
	EVOLUTIONARY_CIRCLE::~EVOLUTIONARY_CIRCLE() {

	}

	void EVOLUTIONARY_CIRCLE::create() {
		ECircle = game()->container()->data().eCircle;
	}

	void EVOLUTIONARY_CIRCLE::update() {

	}

	void EVOLUTIONARY_CIRCLE::draw() {
		rectMode(CENTER);
		image(ECircle.img, ECircle.pos.x, ECircle.pos.y, 0, ECircle.imgSize);
	}
}