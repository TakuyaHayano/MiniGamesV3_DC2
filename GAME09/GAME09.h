#pragma once
#include "../MAIN/GAME_BASE.h"
namespace GAME09
{
    class GAME :
        public GAME_BASE
    {
	//ƒRƒ“ƒeƒi
	private:
		class CONTAINER* Container;
	public:
		class CONTAINER* container() {
			return Container;
		}
	public:
		enum SCENE_ID {
			TITLE_ID,
			STAGE_ID,
			RESULT_ID,
			NUM_SCENES
		};
	private:
		class SCENE* Scenes[NUM_SCENES];
		SCENE_ID CurSceneId;
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void proc();
        void destroy();
		void changeScene(SCENE_ID sceneId);
    };
}
