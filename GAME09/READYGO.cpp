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
		ReadyGo.goAnim.start();
		ReadyGo.effectAnim.start();
	}

	void READYGO::update() {
		ReadyGo.readyAnim.update();
		ReadyGo.goAnim.update();
		ReadyGo.effectAnim.update();
	}

	void READYGO::draw() {
		if (ReadyGo.readyAnim.isStart()) {
			imageColor(255, 255, 255, ReadyGo.readyAnim.alpha());
			image(ReadyGo.imgReady, ReadyGo.readyAnim.pos().x, ReadyGo.readyAnim.pos().y, 0, ReadyGo.readyAnim.size());
		}
		if (ReadyGo.goAnim.isStart()) {
			imageColor(255, 255, 255, ReadyGo.goAnim.alpha());
			image(ReadyGo.imgGo, ReadyGo.goAnim.pos().x, ReadyGo.goAnim.pos().y, 0, ReadyGo.goAnim.size());
		}
		if (ReadyGo.effectAnim.isStart()) {
			imageColor(255, 255, 255, ReadyGo.effectAnim.alpha());
			image(ReadyGo.imgGo, ReadyGo.effectAnim.pos().x, ReadyGo.effectAnim.pos().y, 0, ReadyGo.effectAnim.size());
		}
		imageColor(255);
	}
}