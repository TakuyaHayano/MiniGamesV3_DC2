#include "SCORE.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "BUBBLE.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/mathUtil.h"
#include "../../libOne/inc/rand.h"

namespace GAME09
{
	SCORE::SCORE(GAME* game) :
		GAME_OBJECT(game) {

	}
	SCORE::~SCORE() {
		delete Bubble;
	}

	void SCORE::create() {
		Score = game()->container()->data().score;
		Bubble = new BUBBLE(game());
		Bubble->create();
	}

	void SCORE::init() {
		Bubble->init();
		Bubble->setSize(Score.bubbleSize);
		Bubble->setPos(Score.bubblePos);
		CurScore = 0;
	}

	void SCORE::update() {
		Bubble->update();
	}

	void SCORE::draw() {
		rectMode(CENTER);
		Bubble->draw();
		game()->drawNum()->draw(CurScore, Bubble->getPos() + Score.scoreOfst, Score.scoreSize);
	}

	void SCORE::addScore(FRUITS::FRUITS_KINDS kinds){
		CurScore += Score.fruitsScores[kinds];
	}
}