#include "CRACKER.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/input.h"
#include "../../libOne/inc/rand.h"
#include "../../libOne/inc/mathUtil.h"

namespace GAME09
{
	CRACKER::CRACKER(GAME* game) :
		GAME_OBJECT(game) {

	}
	CRACKER::~CRACKER() {

	}

	void CRACKER::create() {
		Cracker = game()->container()->data().cracker;
	}

	void CRACKER::init() {
		Papers.clear();
		Time = 0;
	}

	void CRACKER::update() {
		Time += delta;
		if (Time > Cracker.interval) {
			appear();
			Time -= Cracker.interval;
		}
		for (auto it = Papers.begin(); it != Papers.end();) {
			(*it).pPos.y += Cracker.speed * delta;
			(*it).angle += Cracker.angSpeed * delta;
			if ((*it).pPos.y > height) {
				it = Papers.erase(it);
			}
			else {
				it++;
			}
		}
	}

	void CRACKER::draw() {
		rectMode(CENTER);
		angleMode(DEGREES);
		for (auto it = Papers.begin(); it != Papers.end(); it++) {
			fill((*it).color);
			float ratio = Abs(Cos((*it).angle));
			rect((*it).pPos.x, (*it).pPos.y, Cracker.size.x, Cracker.size.y * ratio);
		}
	}

	void CRACKER::appear() {
		VECTOR2 pos = Cracker.pos;
		pos.x += random(-Cracker.startWidth / 2.0f, Cracker.startWidth / 2.0f);
		COLOR c = Cracker.colors[random(0, NUM_COLORS - 1)];
		Papers.emplace_back(PAPER{ pos, c });
	}
}