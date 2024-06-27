#include "TITLE.h"
#include"CONTAINER.h"
#include"../../libOne/inc/sound.h"
#include"GAME14.h"

namespace GAME14 {
    TITLE::TITLE(class GAME* game):
        SCENE(game){}
    TITLE::~TITLE(){}
    void TITLE::create(){
        Title = game()->container()->data().title;
        Title.bgm = game()->container()->data().title.bgm;
        Title.bgmFlag = false;

    }
    void TITLE::init(){
        Title.bgmFlag = false;
         if (!Title.bgmFlag) {
             setVolume(Title.bgm, 0);
            playLoopSound(Title.bgm);
            Title.bgmFlag = true;
        }
    }
    void TITLE::update(){

    }
    void TITLE::draw(){
       clear(Title.backColor);
        textSize(Title.titleNameSize);
        fill(Title.titleNameColor);
        text(Title.titleName1, Title.titleName1Pos.x, Title.titleName1Pos.y);
        text(Title.titleName2, Title.titleName2Pos.x, Title.titleName2Pos.y);
        textSize(Title.stateChangeMsSize);
        fill(Title.stateChangeMsColor);
        text(Title.stateChangeMs, Title.stateChangeMsPos.x, Title.stateChangeMsPos.y);
        textSize(Title.controlTextSize);
        text(Title.controlText1, Title.controlText1Pos.x, Title.controlText1Pos.y);
        text(Title.controlText2, Title.controlText2Pos.x, Title.controlText2Pos.y);
        fill(Title.undercortClor);
        rect(Title.undercortPos.x, Title.undercortPos.y, Title.undercortSize.x, Title.undercortSize.y);
        textSize(Title.bgmNameSize);
        fill(Title.bgmNameColor);
        text(Title.bgmName, Title.bgmNamePos.x, Title.bgmNamePos.y);
        text(Title.featName, Title.bgmNamePos.x, Title.bgmNamePos.y+Title.bgmNameSize);
        print(Title.bgm);

    }
    void TITLE::nextScene(){
        if (isTrigger(MOUSE_LBUTTON)) {
            game()->changeScene(GAME::STAGE_ID);
            stopSound(Title.bgm);
        }
    }

}