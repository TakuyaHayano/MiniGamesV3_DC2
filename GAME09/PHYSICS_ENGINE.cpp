#include "PHYSICS_ENGINE.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "BOX.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/input.h"
#include "../../libOne/inc/rand.h"

namespace GAME09
{
	PHYSICS_ENGINE::PHYSICS_ENGINE(GAME* game) :
		GAME_OBJECT(game) {

	}
	PHYSICS_ENGINE::~PHYSICS_ENGINE() {

	}

	void PHYSICS_ENGINE::create() {
		Physics = game()->container()->data().physics;
	}

	void PHYSICS_ENGINE::init() {

	}

	void PHYSICS_ENGINE::update() {
		//フルーツを増やす処理
		//if (isTrigger(MOUSE_LBUTTON)) {
		//	Fruits.emplace_back(new FRUITS(game(), VECTOR2(mouseX, mouseY), (FRUITS::FRUITS_KINDS)random(0, 4)));
		//	Fruits.back()->create();
		//	Fruits.back()->init();
		//}

		//物理演算
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
		for (auto it = Fruits.begin(); it != Fruits.end(); it++) {
			(*it)->draw();
			fill(0);
			print((*it)->getPosC().x);
			print((*it)->getPosC().y);
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
			applyConstraintIndividual(*it);
		}
	}

	void PHYSICS_ENGINE::addFruits(FRUITS* fruits){
		Fruits.emplace_back(fruits);
	}

	void PHYSICS_ENGINE::applyConstraintIndividual(class FRUITS* fruits){
		if (fruits->getPosC().y + fruits->getRadius() > game()->box()->under()) {
			fruits->setPosC(VECTOR2(fruits->getPosC().x, game()->box()->under() - fruits->getRadius()));
			fruits->setPosO(VECTOR2(fruits->getPosO().x, game()->box()->under() - fruits->getRadius()));
			fruits->setTouch(true);
		}
		if (fruits->getPosC().x + fruits->getRadius() > game()->box()->right()) {
			fruits->setPosC(VECTOR2(game()->box()->right() - fruits->getRadius() - 0.01f, fruits->getPosC().y));
			fruits->setPosO(VECTOR2(game()->box()->right() - fruits->getRadius() - 0.01f, fruits->getPosO().y));
			//fruits->setTouch(true);
		}
		if (fruits->getPosC().x - fruits->getRadius() < game()->box()->left()) {
			fruits->setPosC(VECTOR2(game()->box()->left() + fruits->getRadius() + 0.01f, fruits->getPosC().y));
			fruits->setPosO(VECTOR2(game()->box()->left() + fruits->getRadius() + 0.01f, fruits->getPosO().y));
			//fruits->setTouch(true);
		}
	}

	void PHYSICS_ENGINE::solveCollisions() {
		std::vector<FRUITS*> TempEvolution;
		for (auto it = Fruits.begin(); it != Fruits.end();) {
			FRUITS*& fruits1 = *it;
			bool erase = false;
			for (auto it2 = it + 1; it2 != Fruits.end(); it2++) {
				FRUITS*& fruits2 = *it2;
				const VECTOR2 colliAxis = fruits1->getPosC() - fruits2->getPosC();
				const float dist = colliAxis.mag();
				const float distR = fruits1->getRadius() + fruits2->getRadius();
				//衝突してるなら
				if (dist < distR) {
					//同じフルーツなら消す
					if (fruits1->getKinds() == fruits2->getKinds()) {
						//スイカじゃなければ進化した奴を生成
						if (fruits1->getKinds() != FRUITS::WATERMELON) {
							VECTOR2 pos = (fruits1->getPosC() + fruits2->getPosC()) / 2;
							TempEvolution.emplace_back(new FRUITS(game(), pos, (FRUITS::FRUITS_KINDS)(fruits1->getKinds() + 1), true));
						}
						Fruits.erase(it2);
						it = Fruits.erase(it);
						erase = true;
						break;
					}
					else {
						const VECTOR2 n = colliAxis / dist;
						const float solveV = (distR - dist);
						const float ratio = pow(fruits1->getRadius(), 1) / (pow(fruits1->getRadius(), 1) + pow(fruits2->getRadius(), 1));
						fruits1->setPosC(fruits1->getPosC() + (solveV * n * (1 - ratio)));
						fruits2->setPosC(fruits2->getPosC() - (solveV * n * ratio));
						fruits1->setTouch(true);
						fruits2->setTouch(true);
					}
				}
			}
			if (!erase) {
				it++;
			}
		}
		if (TempEvolution.size() != 0) {
			for (auto it = TempEvolution.begin(); it != TempEvolution.end();) {
				Fruits.emplace_back(*it);
				Fruits.back()->create();
				Fruits.back()->init();
				it = TempEvolution.erase(it);
			}
		}
	}
}