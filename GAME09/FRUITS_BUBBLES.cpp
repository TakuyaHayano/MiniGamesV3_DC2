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
		//ë»â~ÇÃâ~é¸ÇÃí∑Ç≥ÇéñëOÇ…ãÅÇﬂÇÈ
		angleMode(DEGREES);
		totalArcLength = 0;
		float prevX = FruitsBubbles.lenX;
		float prevY = 0;
		for (int i = 1; i <= totalSteps; i++) {
			float theta = (i / totalSteps) * 360;
			float x = FruitsBubbles.lenX * Cos(theta);
			float y = FruitsBubbles.lenY * Sin(theta);
			float dx = x - prevX;
			float dy = y - prevY;
			float segmentLength = Sqrt(dx * dx + dy * dy);
			totalArcLength += segmentLength;
			arcLengths.emplace_back(totalArcLength);
			prevX = x;
			prevY = y;
		}
	}

	void FRUITS_BUBBLES::init() {
		MoveDist = FruitsBubbles.initDist;
		for (int i = 0; i < FRUITS::NUM_FRUITS_KINDS; i++) {
			Bubbles[i]->init();
		}
	}

	void FRUITS_BUBBLES::update() {
		angleMode(DEGREES);
		MoveDist += FruitsBubbles.speed * delta;
		for (int i = 0; i < FRUITS::NUM_FRUITS_KINDS; i++) {
			float targetLength = ((float)i / FRUITS::NUM_FRUITS_KINDS) * totalArcLength + MoveDist;
			while (targetLength > totalArcLength) {
				targetLength -= totalArcLength;
			}
			int closestIndex = 0;

			for (int j = 0; j < arcLengths.size(); j++) {
				if (arcLengths[j] >= targetLength) {
					closestIndex = j;
					break;
				}
			}

			float theta = (closestIndex / totalSteps) * 360;
			VECTOR2 pos(width / 2, height / 2);
			pos += VECTOR2(Cos(theta) * FruitsBubbles.lenX, Sin(theta) * FruitsBubbles.lenY);
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