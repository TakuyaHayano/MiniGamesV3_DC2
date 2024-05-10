#include "CLOUD.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/input.h"

namespace GAME09
{
	CLOUD::CLOUD(GAME* game) :
		GAME_OBJECT(game) {

	}
	CLOUD::~CLOUD() {

	}

	void CLOUD::create() {
		Cloud = game()->container()->data().cloud;
	}

	void CLOUD::init() {
		FruitsPos = Cloud.fruitsInitPos;
	}

	void CLOUD::update() {

	}

	void CLOUD::draw() {
		rectMode(CENTER);
		VECTOR2 pos = FruitsPos + Cloud.cloudPosOfst;
		image(Cloud.cloudImg, pos.x, pos.y, 0, Cloud.cloudImgSize);
	}
}