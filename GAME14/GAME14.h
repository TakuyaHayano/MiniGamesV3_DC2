#pragma once
#include "../MAIN/GAME_BASE.h"
namespace GAME14
{
    class GAME :
        public GAME_BASE
    {
    private:
        class CONTAINER* Container = nullptr;
    public:
        class CONTAINER* container() { return Container; }
    public:
        enum SCENE_ID {
            TITLE_ID,
            STAGE_ID,
            NUM_SCENES
        };
    private:
        //シーン
        class SCENE* Scenes[NUM_SCENES];
        SCENE_ID CurSceneId = TITLE_ID;
        class FADE* Fade = nullptr;
    public:
        class FADE* fade() { return Fade; }
        void changeScene(SCENE_ID scene);
    private:
        //キャラクタ
        class MAP* Map = nullptr;
        class CHARACTER_MANAGER* CharacterManager = nullptr;
    public:
        class MAP* map() { return Map; }
        class CHARACTER_MANAGER* characterManager() { return CharacterManager; }
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void proc();
        void destroy();
    };
}
