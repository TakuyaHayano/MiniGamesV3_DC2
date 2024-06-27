#include "../../libOne/inc/libOne.h"
#include "GAME_M.h"
#include "CONTAINER.h"
#include "TITLE.h"
#include "PLAY.h"
#include "STAGE.h"
#include "GAME_CLEAR.h"
#include "GAME_OVER.h"
GAME_M::GAME_M() 
{

    Container = new CONTAINER;

    Scenes[TITLE_ID] = new TITLE(this);
    Scenes[STAGE_ID] = new STAGE(this);
    Scenes[GAME_CLEAR_ID] = new GAME_CLEAR(this);
    Scenes[GAME_OVER_ID] = new GAME_OVER(this);
    CurSceneId = TITLE_ID;

    Play = new PLAY(this);
}
GAME_M::~GAME_M() {
    delete Play;
    for (int i = 0; i < NUM_SCENES; i++) {
        delete Scenes[i];
    }
}
void GAME_M::run() {    //gmain‚Ý‚½‚¢‚È–ðŠ„
    window(1920, 1080, full);

    Container->load();
    Scenes[TITLE_ID]->create();
    Play->create();
    
    while (notQuit) {
        Scenes[CurSceneId]->proc();    //update,draw,nextScene‚ðŒJ‚è•Ô‚·
    }
}
void GAME_M::changeScene(SCENE_ID sceneId) {
    CurSceneId = sceneId;
}