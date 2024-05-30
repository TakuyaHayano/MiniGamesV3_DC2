#pragma once
#include"SCENE.h"
namespace GAME03 {
	class VOLUME:public SCENE{
	public:
		struct DATA {
			int backImg = 0;
			int Snd_A = 0;
			int Snd_B = 0;
			int Se_A = 0;
			int Se_B = 0;
			int volume1 = 0;
			int volume2 = 0;
			int cntVolume = 0;
			float select = true;
			COLOR backColor;
		};
	private:
		DATA Volume;
		void BackGround();
	public:
		VOLUME(class GAME* game) : SCENE(game){}
		void create();
		void init();
		void draw();
		void nextScene();
	};
}

