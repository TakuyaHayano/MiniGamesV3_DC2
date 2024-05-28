#include "CURTAIN.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "BUBBLE.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/mathUtil.h"
#include "../../libOne/inc/rand.h"

namespace GAME09
{
	CURTAIN::CURTAIN(GAME* game) :
		GAME_OBJECT(game) {

	}
	CURTAIN::~CURTAIN() {
		
	}

	void CURTAIN::create() {
		Curtain = game()->container()->data().curtain;
	}

	void CURTAIN::init() {
		AnimeTime = 0;
		State = START;
	}

	void CURTAIN::update() {
		if (State != NUM_STATE) {
			AnimeTime += delta;
			if (AnimeTime > Curtain.moveTimes[State]) {
				AnimeTime -= Curtain.moveTimes[State];
				State = (STATE)(State + 1);
			}
		}
	}

	void CURTAIN::draw() {
		angleMode(DEGREES);
		float ratio = AnimeTime / Curtain.moveTimes[State];
		ratio = (Cos(ratio * 180) + 1) / 2.0f;
		VECTOR2 pos;
		if (State == START) {
			pos = Curtain.imgPos + Curtain.openOfst * ratio;
			image(Curtain.imgR, pos.x, pos.y, 0, Curtain.imgSize);
			pos = Curtain.imgPos - Curtain.openOfst * ratio;
			image(Curtain.imgL, pos.x, pos.y, 0, Curtain.imgSize);
		}
		else if (State == STAY) {
			pos = Curtain.imgPos;
			image(Curtain.imgClose, pos.x, pos.y, 0, Curtain.imgSize);
		}
		else if (State == END) {
			pos = Curtain.imgPos + Curtain.openOfst * (1 - ratio);
			image(Curtain.imgR, pos.x, pos.y, 0, Curtain.imgSize);
			pos = Curtain.imgPos - Curtain.openOfst * (1 - ratio);
			image(Curtain.imgL, pos.x, pos.y, 0, Curtain.imgSize);
		}
	}
}