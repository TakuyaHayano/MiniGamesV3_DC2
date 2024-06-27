#include "CLOUD.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "SOUNDMNG.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/input.h"
#include "../../libOne/inc/rand.h"

namespace GAME09
{
	CLOUD::CLOUD(GAME* game) :
		GAME_OBJECT(game) {

	}
	CLOUD::~CLOUD() {
		delete Fruits;
	}

	void CLOUD::create() {
		Cloud = game()->container()->data().cloud;
	}

	void CLOUD::init() {
		delete Fruits;
		FruitsPos = Cloud.fruitsInitPos;
		CreateFruits();
	}

	void CLOUD::CreateFruits() {
		Fruits = game()->next()->getNextFruits();
		setFruitsPos();
		State = MOVE;
	}

	void CLOUD::update() {
		if (isPress(KEY_LEFT) || isPress(KEY_A)) {
			FruitsPos.x -= Cloud.moveSpeed * delta;
			if (FruitsPos.x < Cloud.left) {
				FruitsPos.x = Cloud.left;
			}
		}
		if (isPress(KEY_RIGHT) || isPress(KEY_D)) {
			FruitsPos.x += Cloud.moveSpeed * delta;
			if (FruitsPos.x > Cloud.right) {
				FruitsPos.x = Cloud.right;
			}
		}
		if (State == MOVE) {
			setFruitsPos();
			if (isTrigger(KEY_SPACE) || isTrigger(KEY_ENTER)) {
				game()->physics()->addFruits(Fruits);
				game()->soundMNG()->playSE(SOUNDMNG::DROP);
				Fruits = nullptr;
				State = FALL;
			}
		}
	}

	void CLOUD::draw() {
		rectMode(CENTER);
		VECTOR2 pos = FruitsPos + Cloud.cloudPosOfst;
		image(Cloud.cloudImg, pos.x, pos.y, 0, Cloud.cloudImgSize);
		if (State == MOVE) {
			strokeWeight(Cloud.lineWidth);
			stroke(255);
			line(FruitsPos.x, FruitsPos.y, FruitsPos.x, game()->box()->under());
			Fruits->draw();
		}
	}
	void CLOUD::setFruitsPos() {
		Fruits->setPosC(FruitsPos);
		Fruits->setPosO(FruitsPos);
	}
	void CLOUD::setMove() {
		CreateFruits();
		State = MOVE;
	}
}