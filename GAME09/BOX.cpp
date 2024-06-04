#include "BOX.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/input.h"

namespace GAME09
{
	BOX::BOX(GAME* game) :
		GAME_OBJECT(game) {

	}
	BOX::~BOX() {

	}

	void BOX::create() {
		Box = game()->container()->data().box;
	}

	void BOX::init() {

	}

	void BOX::update() {

	}

	void BOX::draw() {
		rectMode(CENTER);
		image(Box.img, Box.pos.x, Box.pos.y, 0, Box.imgSize);
		//strokeWeight(3);
		//stroke(0);
		//line(Box.left + Box.pos.x, 0, Box.left + Box.pos.x, height);
		//line(Box.right + Box.pos.x, 0, Box.right + Box.pos.x, height);
		//line(0, Box.under + Box.pos.y, width, Box.under + Box.pos.y);
		//line(0, up(), width, up());
	}

	void BOX::drawFront() {
		rectMode(CENTER);
		image(Box.frontImg, Box.pos.x, Box.pos.y, 0, Box.imgSize);
	}

	float BOX::left(){
		return Box.left + Box.pos.x;
	}
	float BOX::right(){
		return Box.right + Box.pos.x;
	}
	float BOX::under(){
		return Box.under + Box.pos.y;
	}
	float BOX::up() {
		return Box.up + Box.pos.y;
	}
}