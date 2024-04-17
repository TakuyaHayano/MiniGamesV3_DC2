#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "TITLE.h"
#include "STAGE.h"
#include "PHYSICS_ENGINE.h"

namespace GAME09
{

	int GAME::create()
	{
		//new
		Container = new CONTAINER;
		Scenes[TITLE_ID] = new TITLE(this);
		Scenes[STAGE_ID] = new STAGE(this);
		BackGround = new BACKGROUND(this);
		Physics = new PHYSICS_ENGINE(this);

		//load
		Container->load();

		//create
		for (int i = 0; i < NUM_SCENES; i++) {
			if (Scenes[i] != nullptr) {
				Scenes[i]->create();
			}
		}
		BackGround->create();
		Physics->create();

		//init
		CurSceneId = TITLE_ID;
		Scenes[CurSceneId]->init();

		return 0;
	}

	void GAME::destroy()
	{
		delete Physics;
		delete BackGround;
		for (int i = 0; i < NUM_SCENES; i++) {
			if (Scenes[i] != nullptr) {
				delete Scenes[i];
			}
		}
		delete Container;
	}

	void GAME::proc()
	{
		Scenes[CurSceneId]->proc();
	}

	void GAME::changeScene(SCENE_ID sceneId) {
		CurSceneId = sceneId;
		Scenes[CurSceneId]->init();
	}

	void GAME::backToMenu() {
		main()->backToMenu();
	}
}