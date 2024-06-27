#include "../../libOne/inc/libOne.h"
#include "GAME_M.h"
#include "CONTAINER.h"
#include "TITLE.h"
TITLE::TITLE(class GAME_M* game) :
    SCENE(game) {
}
TITLE::~TITLE() {}
void TITLE::create() {
    Title = game()->container()->title();
}
void TITLE::draw(){
    clear(Title.backColor);
    fill(Title.textColor);
    textSize(Title.textSize0);
    text(Title.str0, Title.pos[0].x, Title.pos[0].y);
    textSize(Title.textSize1);
    text(Title.str1, Title.pos[1].x, Title.pos[1].y);
}
void TITLE::nextScene(){
    if (isTrigger(KEY_ENTER)) {
        game()->changeScene(GAME_M::STAGE_ID);
    }
}