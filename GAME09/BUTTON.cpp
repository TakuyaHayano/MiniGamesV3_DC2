#include "BUTTON.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/mathUtil.h"

namespace GAME09
{
    BUTTON::BUTTON(class GAME* game) :
        GAME_OBJECT(game) {

    }
    BUTTON::~BUTTON() {

    }
    void BUTTON::create() {

    }
    void BUTTON::init() {
        AnimeTime = Button.selectAnimeTime;
        Select = false;
    }
    void BUTTON::update() {
        if (AnimeTime < Button.selectAnimeTime) {
            AnimeTime += delta;
            if (AnimeTime > Button.selectAnimeTime) AnimeTime = Button.selectAnimeTime;
        }
    }
    void BUTTON::draw() {
        angleMode(DEGREES);
        rectMode(CENTER);
        float ratio = AnimeTime / Button.selectAnimeTime;
        if (Select) {
            image(Button.selectedImg, Button.pos.x, Button.pos.y, 0, Button.imgSize);
        }
        else {
            image(Button.notSelectedImg, Button.pos.x, Button.pos.y, 0, Button.imgSize);
        }
        print(Select);
    }
    void BUTTON::setSelect(bool select, bool anime){
        Select = select;
        if (select && anime) {
            AnimeTime = 0;
        }
    }
}