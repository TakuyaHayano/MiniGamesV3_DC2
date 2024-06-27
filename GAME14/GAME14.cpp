#include "../MAIN/MAIN.h"
#include"TITLE.h"
#include"STAGE.h"
#include"MAP.h"
#include"CONTAINER.h"
#include"CHARACTER_MANAGER.h"
#include "GAME14.h"
namespace GAME14
{
	int GAME::create()
	{
		Container = new CONTAINER();

		Scenes[TITLE_ID] = new TITLE(this);
		Scenes[STAGE_ID] = new STAGE(this);
		Map = new MAP(this);
		CharacterManager = new CHARACTER_MANAGER(this);
		Container->load();
		for (int i = 0; i < NUM_SCENES; i++) {
			Scenes[i]->create();
		}
		Map->create();
		CharacterManager->create();
		changeScene(CurSceneId);
		return 0;
	}

	void GAME::destroy()
	{
		delete CharacterManager;
		delete Map;
		for (int i = 0; i < NUM_SCENES; i++) {
			delete Scenes[i];
		}
		delete Container;
	}

	void GAME::proc()
	{
		Scenes[CurSceneId]->proc();
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}
	void GAME::changeScene(SCENE_ID sceneId) {
		CurSceneId = sceneId;
		Scenes[CurSceneId]->init();
	}

}
