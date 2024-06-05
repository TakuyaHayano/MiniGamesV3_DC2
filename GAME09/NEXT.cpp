#include "NEXT.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "BUBBLE.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/mathUtil.h"
#include "../../libOne/inc/rand.h"

#define new new( _CLIENT_BLOCK, __FILE__, __LINE__)

namespace GAME09
{
	NEXT::NEXT(GAME* game) :
		GAME_OBJECT(game) {

	}
	NEXT::~NEXT() {
		delete Bubble;
		delete Fruits;
	}

	void NEXT::create() {
		Next = game()->container()->data().next;
		Bubble = new BUBBLE(game());
		Bubble->create();
	}

	void NEXT::init() {
		delete Fruits;
		Bubble->init();
		Bubble->setSize(Next.bubbleSize);
		Bubble->setPos(Next.bubblePos);
		if (((TITLE*)game()->getScene(GAME::TITLE_ID))->secretMode()) {
			UseFruitsNum = Next.useFruitsNumSecret;
		}
		else {
			UseFruitsNum = Next.useFruitsNum;
		}
		CreateFruits();
	}

	void NEXT::update() {
		Bubble->update();
		Fruits->setPosC(Bubble->getPos());
		Fruits->setPosO(Bubble->getPos());
	}

	void NEXT::draw() {
		rectMode(CENTER);
		Bubble->draw();
		Fruits->draw();
		VECTOR2 pos = Bubble->getPos() + Next.strOfst;
		float size = game()->container()->data().bubble.imgSize * Next.bubbleSize;
		image(Next.strImg, pos.x, pos.y, 0, size);
	}

	class FRUITS* NEXT::getNextFruits(){
		Fruits->setTheta();
		class FRUITS* f = Fruits;
		CreateFruits();
		return f;
	}

	void NEXT::CreateFruits() {
		Fruits = new FRUITS(game(), Bubble->getPos(), (FRUITS::FRUITS_KINDS)random(0, UseFruitsNum));
		Fruits->create();
		Fruits->init();
	}
}