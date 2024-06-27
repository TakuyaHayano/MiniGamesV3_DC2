#include "BUBBLE.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/mathUtil.h"

namespace GAME09
{
	BUBBLE::BUBBLE(GAME* game) :
		GAME_OBJECT(game) {

	}
	BUBBLE::~BUBBLE() {

	}

	void BUBBLE::create() {
		Bubble = game()->container()->data().bubble;
	}

	void BUBBLE::init() {
		setPos(Bubble.pos);
		setSize(1);
		AnimeTime = 0;
	}

	void BUBBLE::update() {
		angleMode(DEGREES);
		AnimeTime += delta;
		AnimeTime -= (int)(AnimeTime / Bubble.animeTime) * Bubble.animeTime;
		float ratio = AnimeTime / Bubble.animeTime;
		CPos = OPos + Bubble.maxMoveOfst * Sin(ratio * 360.0f);
	}

	void BUBBLE::draw() {
		rectMode(CENTER);
		image(Bubble.img, CPos.x, CPos.y, 0, Bubble.imgSize * Size);
	}

	void BUBBLE::setPos(VECTOR2 pos) {
		OPos = pos;
		CPos = pos;
	}
}