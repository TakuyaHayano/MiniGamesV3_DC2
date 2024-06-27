#include "../../libOne/inc/libOne.h"
#include "STAGE.h"
STAGE::STAGE(class GAME_M* game) :
    SCENE(game) {
}
STAGE::~STAGE() {}
void STAGE::update() {
    game()->play()->update();
}
void STAGE::draw() {
    clear();
    game()->play()->draw();

}
void STAGE::nextScene() {
    if (isTrigger(KEY_A)) {
        game()->changeScene(GAME_M::GAME_CLEAR_ID);
    }
    else if (isTrigger(KEY_B)) {
        game()->changeScene(GAME_M::GAME_OVER_ID);
    }
	else if (isTrigger(KEY_C)) {
		game()->changeScene(GAME_M::GAME_OVER_ID);
	}
	else if (isTrigger(KEY_D)) {
		game()->changeScene(GAME_M::GAME_OVER_ID);
	}
}