#include "../../libOne/inc/libOne.h"
#include "CONTAINER.h"
#include "GAME_M.h"
#include "PLAY.h"
PLAY::PLAY(class GAME_M* game):
	GAME_OBJECT(game){
}
void PLAY::create(){
	Play = game()->container()->play();
}
void PLAY::init(){
}
void PLAY::update() {
	if (isTrigger(KEY_SPACE)) {
		Play.elevation -= Play.decSpeed;
	}
}
void PLAY::draw(){
	rectMode(CENTER);
	angleMode(DEGREES);
	image(Play.img[0], Play.pos.x, Play.pos.y, Play.angle, Play.scale);
	fill(Play.textColor);
	text(Play.str, Play.t_pos.x, Play.t_pos.y);
	text("Space�Ŏʐ^��������悤�ɂȂ��Ă���", Play.t_pos.x + 100, Play.t_pos.y + 50);
	fill(Play.rectColor);
	rect(Play.r_pos.x, Play.r_pos.y, Play.range, Play.elevation);
}