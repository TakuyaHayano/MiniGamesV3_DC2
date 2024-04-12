#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "TITLE.h"

namespace GAME09
{

	int GAME::create()
	{
		//new
		Container = new CONTAINER;
		Scenes[TITLE_ID] = new TITLE(this);

		//load
		Container->load();

		//create
		for (int i = 0; i < NUM_SCENES; i++) {
			if (Scenes[i] != nullptr) {
				Scenes[i]->create();
			}
		}

		//init
		CurSceneId = TITLE_ID;

		return 0;
	}

	void GAME::destroy()
	{
		for (int i = 0; i < NUM_SCENES; i++) {
			if (Scenes[i] != nullptr) {
				delete Scenes[i];
			}
		}
		delete Container;
	}

	void GAME::proc()
	{
		clear(128);
		Scenes[CurSceneId]->proc();
	}

	void GAME::changeScene(SCENE_ID sceneId) {
		CurSceneId = sceneId;
		Scenes[CurSceneId]->init();
	}
}