#include "READYGO.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "BUBBLE.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/mathUtil.h"
#include "../../libOne/inc/rand.h"

namespace GAME09
{
	READYGO::READYGO(GAME* game) :
		GAME_OBJECT(game) {

	}
	READYGO::~READYGO() {

	}

	void READYGO::create() {
		ReadyGo = game()->container()->data().readyGo;
	}

	void READYGO::init() {
		ReadyGo.readyAnim.start();
	}

	void READYGO::update() {
		if (ReadyGo.readyAnim.isStart()) {
			ReadyGo.readyAnim.update();
		}
	}

	void READYGO::draw() {
		if (ReadyGo.readyAnim.isStart()) {
			image(ReadyGo.imgReady, ReadyGo.readyAnim.pos().x, ReadyGo.readyAnim.pos().y, 0, ReadyGo.readyAnim.size());
		}
	}
}