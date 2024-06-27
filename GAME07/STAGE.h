//ÉvÉåÉCä÷êîÇ›ÇΩÇ¢Ç»Ç‡ÇÃ
#pragma once
#include "TIME.h"
#include "GAME_M.h"
#include "PLAY.h"
#include "SCENE.h"
class STAGE :
    public SCENE
{
public:
    STAGE(class GAME_M* game);
    ~STAGE();
    void update();
    void draw();
    void nextScene();
};