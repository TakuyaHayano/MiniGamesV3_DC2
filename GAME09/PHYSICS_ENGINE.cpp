#include "PHYSICS_ENGINE.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "BOX.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/input.h"

namespace GAME09
{
	PHYSICS_ENGINE::PHYSICS_ENGINE(GAME* game) :
		GAME_OBJECT(game) {

	}
	PHYSICS_ENGINE::~PHYSICS_ENGINE() {
		delete Box;
	}

	void PHYSICS_ENGINE::create() {
		Physics = game()->container()->data().physics;
		Box = new BOX(game());

		Box->create();
	}

	void PHYSICS_ENGINE::init() {

	}

	void PHYSICS_ENGINE::update() {
		//ƒtƒ‹[ƒc‚ğ‘‚â‚·ˆ—
		if (isTrigger(MOUSE_LBUTTON)) {
			Fruits.emplace_back(new FRUITS(game(), VECTOR2(mouseX, mouseY)));
			Fruits.back()->create();
			Fruits.back()->init();
		}

		//•¨—‰‰Z
		const int subSteps = 8;
		const float subDt = delta / (float)subSteps;
		for (int i = 0; i < subSteps; i++) {
			applyGravity();
			updatePos(subDt);
			solveCollisions();
			applyConstraint();
		}
	}

	void PHYSICS_ENGINE::draw() {
		rectMode(CENTER);
		Box->draw();
		for (auto it = Fruits.begin(); it != Fruits.end(); it++) {
			(*it)->draw();
		}
	}

	void PHYSICS_ENGINE::updatePos(float dt) {
		for (auto it = Fruits.begin(); it != Fruits.end(); it++) {
			(*it)->update(dt);
		}
	}

	void PHYSICS_ENGINE::applyGravity() {
		for (auto it = Fruits.begin(); it != Fruits.end(); it++) {
			(*it)->accelerate(Physics.gravity);
		}
	}

	void PHYSICS_ENGINE::applyConstraint() {

		for (auto it = Fruits.begin(); it != Fruits.end(); it++) {
			if ((*it)->getPosC().y + (*it)->getRadius() > Box->under()) {
				(*it)->setPosC(VECTOR2((*it)->getPosC().x, Box->under() - (*it)->getRadius()));
				(*it)->setTouch(true);
			}
			if ((*it)->getPosC().x + (*it)->getRadius() > Box->right()) {
				(*it)->setPosC(VECTOR2(Box->right() - (*it)->getRadius() - 0.01f, (*it)->getPosC().y));
				//(*it)->setTouch(true);
			}
			if ((*it)->getPosC().x - (*it)->getRadius() < Box->left()) {
				(*it)->setPosC(VECTOR2(Box->left() + (*it)->getRadius() + 0.01f, (*it)->getPosC().y));
				//(*it)->setTouch(true);
			}
		}
	}

	void PHYSICS_ENGINE::solveCollisions() {
		const int fruitsNum = Fruits.size();
		for (auto it = Fruits.begin(); it != Fruits.end(); it++) {
			FRUITS*& fruits1 = *it;
			for (auto it2 = it + 1; it2 != Fruits.end(); it2++) {
				FRUITS*& fruits2 = *it2;
				const VECTOR2 colliAxis = fruits1->getPosC() - fruits2->getPosC();
				const float dist = colliAxis.mag();
				const float distR = fruits1->getRadius() + fruits2->getRadius();
				if (dist < distR) {
					const VECTOR2 n = colliAxis / dist;
					const float solveV = distR - dist;
					const float ratio = pow(fruits1->getRadius(), 2) / (pow(fruits1->getRadius(), 2) + pow(fruits2->getRadius(), 2));
					fruits1->setPosC(fruits1->getPosC() + (solveV * n * (1 - ratio)));
					fruits2->setPosC(fruits2->getPosC() - (solveV * n * ratio));
					fruits1->setTouch(true);
					fruits2->setTouch(true);
				}
			}
		}
	}
}