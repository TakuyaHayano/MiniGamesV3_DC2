#include "FRUITS_BUBBLES.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "BUBBLE.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/mathUtil.h"
#include "../../libOne/inc/rand.h"

namespace GAME09
{
	FRUITS_BUBBLES::FRUITS_BUBBLES(GAME* game) :
		GAME_OBJECT(game) {

	}
	FRUITS_BUBBLES::~FRUITS_BUBBLES() {
		for (int i = 0; i < FRUITS::NUM_FRUITS_KINDS; i++) {
			delete Bubbles[i];
		}
	}

	void FRUITS_BUBBLES::create() {
		FruitsBubbles = game()->container()->data().fruitsBubbles;
		for (int i = 0; i < FRUITS::NUM_FRUITS_KINDS; i++) {
			Bubbles[i] = new FRUITS_BUBBLE(game());
			Bubbles[i]->create();
			Bubbles[i]->setKinds(FruitsBubbles.order[i]);
		}
	}

	void FRUITS_BUBBLES::init() {
		Angle = FruitsBubbles.initAngle;
		for (int i = 0; i < FRUITS::NUM_FRUITS_KINDS; i++) {
			Bubbles[i]->init();
		}
	}

	void FRUITS_BUBBLES::update() {
		angleMode(DEGREES);
		Angle += FruitsBubbles.angSpeed * delta;
		for (int i = 0; i < FRUITS::NUM_FRUITS_KINDS; i++) {
			float angle = Angle + (float)i / FRUITS::NUM_FRUITS_KINDS * 360;
			VECTOR2 pos(width / 2, height / 2);
			pos += VECTOR2(Cos(angle) * FruitsBubbles.lenX, Sin(angle) * FruitsBubbles.lenY);
			Bubbles[i]->setPos(pos);
			Bubbles[i]->update();
		}
	}

	void FRUITS_BUBBLES::draw() {
		for (int i = 0; i < FRUITS::NUM_FRUITS_KINDS; i++) {
			Bubbles[i]->draw();
		}
	}
}