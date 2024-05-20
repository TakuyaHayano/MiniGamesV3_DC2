#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "TITLE.h"
#include "STAGE.h"

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
		Box = new BOX(this);
		Cloud = new CLOUD(this);
		Next = new NEXT(this);
		Score = new SCORE(this);

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
		Box->create();
		Cloud->create();
		Next->create();
		Score->create();

		//init
		CurSceneId = TITLE_ID;
		Scenes[CurSceneId]->init();

		return 0;
	}

	void GAME::destroy()
	{
		delete Score;
		delete Next;
		delete Cloud;
		delete Box;
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