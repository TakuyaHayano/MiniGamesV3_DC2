#include "../../libOne/inc/libOne.h"
#include "GAME_M.h"
#include "GAME_OVER.h"
GAME_OVER::GAME_OVER(class GAME_M* game) :
    SCENE(game) {
}
GAME_OVER::~GAME_OVER() {}
void GAME_OVER::draw() {
    clear(255, 192, 203);
    fill(255, 255, 255);
    textSize(200);
    text("Game Over", width / 2 - 450, height / 2);
    textSize(50);
    text("Enter‚Åƒ^ƒCƒgƒ‹‚Ö", width / 2 - 225, height / 2 + 400);
}
void GAME_OVER::nextScene() {
    if (isTrigger(KEY_ENTER)) {
        game()->changeScene(GAME_M::TITLE_ID);
    }
}