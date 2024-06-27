#pragma once
#include"SCENE.h"
namespace GAME03 {
	class OPERATION_INSTRUCTIONS: public SCENE{
	public:
		struct DATA {
			int backimg = 0;
			COLOR backColor;
		};
	private:
		DATA OpInstructions;
	public:
		OPERATION_INSTRUCTIONS(class GAME* game) :SCENE(game) {}
		void create();
		void init();
		void draw();
		void nextScene();
		int loopBgm = true;
	};
}

