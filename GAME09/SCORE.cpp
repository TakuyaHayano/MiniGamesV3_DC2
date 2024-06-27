#include "SCORE.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "BUBBLE.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/mathUtil.h"
#include "../../libOne/inc/rand.h"
#include <fstream>

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
		loadHiScore();
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
		VECTOR2 pos = Bubble->getPos() + Score.strOfst;
		float size = game()->container()->data().bubble.imgSize * Score.bubbleSize;
		image(Score.strImg, pos.x, pos.y, 0, size);
		game()->drawNum()->draw(HiScore, Bubble->getPos() + Score.hiScoreOfst, Score.hiScoreSize);
		pos = Bubble->getPos() + Score.hiScoreStrOfst;
		image(Score.hiScoreStrImg, pos.x, pos.y, 0, size);
	}

	void SCORE::addScore(FRUITS::FRUITS_KINDS kinds){
		CurScore += Score.fruitsScores[kinds];
	}

	void SCORE::loadHiScore(){
		std::ifstream ifs(Score.fileName);
		std::string buf;
		std::getline(ifs, buf);
		HiScore = atoi(buf.c_str());
		ifs.close();
	}
	void SCORE::setHiScore(){
		if (CurScore > HiScore) {
			HiScore = CurScore;
			std::ofstream ofs(Score.fileName);
			ofs << HiScore;
			ofs.close();
		}
	}
}