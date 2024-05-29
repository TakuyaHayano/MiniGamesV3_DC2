#include "TRANSITION.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"

namespace GAME09
{
	TRANSITION::TRANSITION(GAME* game) :
		GAME_OBJECT(game) {

	}
	TRANSITION::~TRANSITION() {

	}

	void TRANSITION::create() {
		Transition = game()->container()->data().transition;
		State = IN_END;
	}

	void TRANSITION::update() {
		if (State != IN_END) {
			Time += delta;
			if (State == OUT_NOW) {
				if (Time > Transition.outTime) {
					Time -= Transition.outTime;
					State = OUT_END;
				}
			}
			if (State == IN_NOW) {
				if (Time > Transition.inTime) {
					State = IN_END;
				}
			}
			game()->curtain()->update();
			game()->fruitsBubbles()->update();
		}
	}

	void TRANSITION::draw() {
		if (State != IN_END) {
			//imageColor(255, 255, 255, 100);
			game()->curtain()->draw();
			game()->fruitsBubbles()->draw();
			//imageColor(255);
		}
	}

	void TRANSITION::start() {
		State = OUT_NOW;
		Time = 0;
		game()->curtain()->init();
		game()->fruitsBubbles()->init();
	}

	bool TRANSITION::inEndFlag() {
		return State == IN_END;
	}
	bool TRANSITION::outEndFlag() {
		if (State == OUT_END) {
			State = IN_NOW;
			return true;
		}
		else {
			return false;
		}
	}
}