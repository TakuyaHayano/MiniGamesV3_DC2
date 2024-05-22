#include "FRUITS_BUBBLE.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "BUBBLE.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/mathUtil.h"
#include "../../libOne/inc/rand.h"

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
		Pos = FruitsBubble.bubblePos;
		float rate = Pow(FruitsBubble.nextFruitsSizeRate, Kinds);
		ImgSize = FruitsBubble.cherryImgSize * rate;
		if (ImgSize > FruitsBubble.maxImgSize) ImgSize = FruitsBubble.maxImgSize;
		BeforeOfst = VECTOR2(0, 0);
		CurOfst = VECTOR2(0, 0);
		AfterOfst = VECTOR2(0, 0);
		SetRandMove();
	}

	void FRUITS_BUBBLE::SetRandMove() {
		BeforeOfst = AfterOfst;
		float len = random(0.0f, FruitsBubble.maxMoveDist);
		float angle = random(1, 360);
		AfterOfst = VECTOR2(len * Cos(angle), len * Sin(angle));
		AnimeTime = 0;
		MoveTime = random(FruitsBubble.minMoveTime, FruitsBubble.maxMoveTime);
	}

	void FRUITS_BUBBLE::update() {
		angleMode(DEGREES);
		AnimeTime += delta;
		if (AnimeTime > MoveTime) {
			SetRandMove();
		}
		float ratio = AnimeTime / MoveTime;
		ratio = Cos(ratio * 180) / -2 + 0.5f;
		CurOfst = BeforeOfst * (1 - ratio) + AfterOfst * ratio;
		Bubble->setPos(Pos + CurOfst);
	}

	void FRUITS_BUBBLE::draw() {
		rectMode(CENTER);
		Bubble->draw();
		image(FruitsBubble.imgs[Kinds], Bubble->getPos().x, Bubble->getPos().y, 0, ImgSize);
	}
}