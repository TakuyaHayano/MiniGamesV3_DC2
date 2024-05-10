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
		class BACKGROUND* BackGround;
		class PHYSICS_ENGINE* Physics;
		class BOX* Box;
		class CLOUD* Cloud;
	public:
		class SCENE* getScene(SCENE_ID sceneId) { return Scenes[sceneId]; }
		class BACKGROUND* backGround() { return BackGround; }
		class PHYSICS_ENGINE* physics() { return Physics; }
		class BOX* box() { return Box; }
		class CLOUD* cloud() { return Cloud; }
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void proc();
        void destroy();
		void changeScene(SCENE_ID sceneId);

		void backToMenu();
    };
}
