#include "FRUITS.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/input.h"
#include "../../libOne/inc/mathUtil.h"

namespace GAME09
{
	FRUITS::FRUITS(GAME* game, VECTOR2 pos) :
		GAME_OBJECT(game) {
		Pos_current = pos;
		Pos_old = pos;
	}
	FRUITS::~FRUITS() {

	}

	void FRUITS::create() {
		Fruits = game()->container()->data().fruits;
	}

	void FRUITS::init() {
		Acc = VECTOR2(0, 0);
		Omega = 0;
		Theta = 0;
		Radius = 50;
	}

	void FRUITS::update(float dt) {
		VECTOR2 Vel = Pos_current - Pos_old;
		if (Touch) {
			Vel *= Fruits.attenuationRate;
			Omega = Vel.mag() / Radius;
			if (Vel.x == 0) Omega *= 0;
			if (Vel.x < 0) Omega *= -1;
		}
		Pos_old = Pos_current;
		Pos_current = Pos_current + Vel + Acc * dt * dt;
		Theta += Omega;
		Acc *= 0;
		Touch = false;
	}
	void FRUITS::accelerate(VECTOR2 acc) {
		Acc += acc;
	}
	void FRUITS::draw() {
		strokeWeight(Fruits.sw);
		stroke(0);
		fill(255, 255, 255, 0);
		angleMode(RADIANS);
		circle(Pos_current.x, Pos_current.y, Radius * 2);
		line(Pos_current.x, Pos_current.y, Pos_current.x + Radius * cos(Theta), Pos_current.y + Radius * sin(Theta));
	}
}