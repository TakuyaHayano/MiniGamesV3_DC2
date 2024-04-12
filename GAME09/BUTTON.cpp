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
    }
    void BUTTON::update() {
        if (AnimeTime < Button.selectAnimeTime) {
            AnimeTime += delta;
            if (AnimeTime > Button.selectAnimeTime) AnimeTime = Button.selectAnimeTime;
        }
    }
    void BUTTON::draw() {
        angleMode(DEGREES);
        float ratio = AnimeTime / Button.selectAnimeTime;
    }
    void BUTTON::setSelect(bool select)
    {
        Select = select;
        if (select) {
            AnimeTime = 0;
        }
    }
}