#include "../../libOne/inc/libOne.h"
#include"../MAIN/GAME_BASE.h"
#include "../MAIN/MAIN.h"
#include "TITLE.h"
#include "STAGE.h"
#include "FADE.h"
#include "MAP.h"
#include "VOLUME.h"
#include "CONTAINER.h"
#include "CHARACTER_MANAGER.h"
#include"GAME03.h"
namespace GAME03
{
	int GAME::create() {
		Container = new CONTAINER();
		Title = new TITLE(this);
		Stage = new STAGE(this);
		Fade = new FADE(this);
		Map = new MAP(this);
		Volume = new VOLUME(this);
		OpInstructions = new OPERATION_INSTRUCTIONS(this);
		CharacterManager = new CHARACTER_MANAGER(this);

		Container->load();
		Title->create();
		Stage->create();
		Fade->create();
		Map->create();
		Volume->create();
		OpInstructions->create();
		CharacterManager->create();

		CurScene = Title;
		CurScene->init();

		return 0;
	}

	void GAME::destroy() {
		delete CharacterManager;
		delete OpInstructions;
		delete Volume;
		delete Map;
		delete Fade;
		delete Stage;
		delete Title;
		delete Container;
	}

	void GAME::setCurScene(SCENE* scene) {
		CurScene = scene;
		CurScene->init();
	}

	void GAME::proc() {
		clear();
		CurScene->proc();
	}

	void GAME::backToMenu(){
		main()->backToMenu();
		stopSound(container()->data().volume.Snd_A);
	}
}
