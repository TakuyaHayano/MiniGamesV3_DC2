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
        Time = Button.startTime;
        Select = false;
        StandbyMotion = Button.initStandbyMotion;
        SelectMotion = Button.initSelectMotion;
    }
    void BUTTON::update() {
        if (StandbyMotion) {
            Time += delta;
            if (Time > Button.standbyAnimeCycleTime) {
                Time -= Button.standbyAnimeCycleTime;
            }
        }
        if (AnimeTime < Button.selectAnimeTime) {
            AnimeTime += delta;
            if (AnimeTime > Button.selectAnimeTime) AnimeTime = Button.selectAnimeTime;
        }
    }
    void BUTTON::draw() {
        angleMode(DEGREES);
        rectMode(CENTER);
        VECTOR2 pos = Button.pos;
        if (StandbyMotion) {
            if (Time < Button.standbyAnimeTime) {
                float ratio = Time / Button.standbyAnimeTime;
                pos.y += Sin(180 * ratio) * Button.standbyAnimeOfstY;
            }
        }
        if (Select) {
            image(Button.selectedImg, pos.x, pos.y, 0, Button.imgSize);
        }
        else {
            image(Button.notSelectedImg, pos.x, pos.y, 0, Button.imgSize);
        }
        fill(0);
    }
    void BUTTON::setSelect(bool select, bool anime){
        Select = select;
        if (select && anime) {
            AnimeTime = 0;
        }
    }
}