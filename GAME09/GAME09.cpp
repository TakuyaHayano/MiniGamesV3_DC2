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
		Scenes[PAUSE_ID] = new PAUSE(this);
		Scenes[RESULT_ID] = new RESULT(this);
		Scenes[HELP_ID] = new HELP(this);
		BackGround = new BACKGROUND(this);
		Physics = new PHYSICS_ENGINE(this);
		Box = new BOX(this);
		Cloud = new CLOUD(this);
		Next = new NEXT(this);
		Score = new SCORE(this);
		DrawNum = new DRAW_NUM(this);
		FruitsBubbles = new FRUITS_BUBBLES(this);
		Curtain = new CURTAIN(this);
		Transition = new TRANSITION(this);
		Command = new COMMAND(this);
		ECircle = new EVOLUTIONARY_CIRCLE(this);
		ReadyGo = new READYGO(this);
		Cracker = new CRACKER(this);

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
		DrawNum->create();
		FruitsBubbles->create();
		Curtain->create();
		Transition->create();
		Command->create();
		ECircle->create();
		ReadyGo->create();
		Cracker->create();

		//init
		changeScene(TITLE_ID);
		changeScene(STAGE_ID);
		changeScene(RESULT_ID);

		return 0;
	}

	void GAME::destroy()
	{
		delete Cracker;
		delete ReadyGo;
		delete ECircle;
		delete Command;
		delete Transition;
		delete Curtain;
		delete FruitsBubbles;
		delete DrawNum;
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

	void GAME::proc(){
		clear();
		Scenes[CurSceneId]->proc();
		if (!Transition->inEndFlag()) {
			Transition->draw();
		}
	}

	void GAME::changeScene(SCENE_ID sceneId) {
		CurSceneId = sceneId;
		Scenes[CurSceneId]->init();
	}

	void GAME::returnScene(SCENE_ID sceneId) {
		CurSceneId = sceneId;
	}

	void GAME::backToMenu() {
		main()->backToMenu();
	}
}