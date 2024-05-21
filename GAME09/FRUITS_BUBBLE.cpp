#include "FRUITS_BUBBLE.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "BUBBLE.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/mathUtil.h"

namespace GAME09
{
	FRUITS_BUBBLE::FRUITS_BUBBLE(GAME* game) :
		GAME_OBJECT(game) {

	}
	FRUITS_BUBBLE::~FRUITS_BUBBLE() {
		delete Bubble;
	}

	void FRUITS_BUBBLE::create() {
		FruitsBubble = game()->container()->data().fruitsBubble;
		Bubble = new BUBBLE(game());
		Bubble->create();
	}

	void FRUITS_BUBBLE::init() {
		Bubble->init();
		Bubble->setSize(FruitsBubble.bubbleSize);
		Bubble->setPos(FruitsBubble.bubblePos);
		float rate = Pow(FruitsBubble.nextFruitsSizeRate, Kinds);
		ImgSize = FruitsBubble.cherryImgSize * rate;
		if (ImgSize > FruitsBubble.maxImgSize) ImgSize = FruitsBubble.maxImgSize;
	}

	void FRUITS_BUBBLE::update() {

	}

	void FRUITS_BUBBLE::draw() {
		rectMode(CENTER);
		Bubble->draw();
		image(FruitsBubble.imgs[Kinds], Bubble->getPos().x, Bubble->getPos().y, 0, ImgSize);
	}
}