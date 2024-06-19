#pragma once
#include"../../libOne/inc/COLOR.h"
#include"SCENE.h"
#include"../MAIN/GAME_BASE.h"
#include"../MAIN/MAIN.h"
namespace GAME03 {
	class TITLE :public SCENE {
	private:
		FILE* fp{};
	public:
		TITLE(class GAME* game) :SCENE(game) {}
		void init();
		void draw();
		void nextScene();
		int loopBgm = true;
		int delibe = 0;
	};
}
