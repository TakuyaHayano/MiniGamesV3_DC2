#include"../../libOne/inc/libOne.h"
#include"GAME_M.h"
#include "GAME_CLEAR.h"
GAME_CLEAR::GAME_CLEAR(class GAME_M* game) :
    SCENE(game) {
}
GAME_CLEAR::~GAME_CLEAR() {}
void GAME_CLEAR::draw() {
    clear(255, 192, 203);
    fill(255, 255, 255);
    textSize(200);
    text("Game Clear", width / 2 - 475, height / 2);
    textSize(50);
    text("Enter‚Åƒ^ƒCƒgƒ‹‚Ö", width / 2 - 225, height / 2 + 400);
}
void GAME_CLEAR::nextScene() {
    if (isTrigger(KEY_ENTER)) {
        game()->changeScene(GAME_M::TITLE_ID);
    }
}