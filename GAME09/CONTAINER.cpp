#include "CONTAINER.h"
#include <string>
#include "../../libOne/inc/graphic.h"

namespace GAME09
{
	void CONTAINER::load() {
		setData();
		loadGraphic();
	}
	void CONTAINER::setData() {
		Data.title.titlePos = VECTOR2(width / 2, height / 2);
		Data.title.imgSize = 1;

		Data.backG.imgSize = 1.0f;
		Data.backG.pos = VECTOR2(width / 2, height / 2);

		Data.startButton.pos = VECTOR2(960, 540);
		Data.startButton.initStandbyMotion = true;
		Data.startButton.startTime = 0.15f;
		Data.helpButton.pos = VECTOR2(960, 730);
		Data.helpButton.initStandbyMotion = true;
		Data.helpButton.startTime = 0.075f;
		Data.endButton.pos = VECTOR2(960, 920);
		Data.endButton.initStandbyMotion = true;
		Data.endButton.startTime = 0.0f;

		Data.physics.gravity = VECTOR2(0.0f, 1800.0f);

		Data.box.pos = VECTOR2(width / 2, height / 2);
		Data.box.imgSize = 1;
		Data.box.left = -338;
		Data.box.right = 335;
		Data.box.under = 472;

		Data.fruits.sw = 2;
		Data.fruits.attenuationRate = 0.998f;
		Data.fruits.cherryRadius = 24;
		Data.fruits.cherryImgSize = 0.062f;
		Data.fruits.nextFruitsSizeRate = 1.232f;
		Data.fruits.inflateMaxTime = 0.1f;
		Data.fruits.initValue = 0.5f;

		Data.cloud.fruitsInitPos = VECTOR2(width / 2, 100);
		Data.cloud.fruitsImgSize = 1;
		Data.cloud.cloudPosOfst = VECTOR2(100, -50);
		Data.cloud.cloudImgSize = 0.45f;
		Data.cloud.left = 660;
		Data.cloud.right = 1260;
		Data.cloud.moveSpeed = 200;
	}
	void CONTAINER::loadGraphic() {
		Data.title.titleImg = loadImage("..\\main\\assets\\game09\\title.png");
		Data.backG.img = loadImage("..\\main\\assets\\game09\\back_ground.png");
		Data.startButton.selectedImg = loadImage("..\\main\\assets\\game09\\start_button.png");
		Data.startButton.notSelectedImg = loadImage("..\\main\\assets\\game09\\start_button_gray.png");
		Data.helpButton.selectedImg = loadImage("..\\main\\assets\\game09\\help_button.png");
		Data.helpButton.notSelectedImg = loadImage("..\\main\\assets\\game09\\help_button_gray.png");
		Data.endButton.selectedImg = loadImage("..\\main\\assets\\game09\\end_button.png");
		Data.endButton.notSelectedImg = loadImage("..\\main\\assets\\game09\\end_button_gray.png");
		Data.box.img = loadImage("..\\main\\assets\\game09\\box.png");
		for (int i = 0; i < FRUITS::NUM_FRUITS_KINDS; i++) {
			std::string path = "..\\main\\assets\\game09\\";
			path += std::to_string(i);
			path += ".png";
			Data.fruits.imgs[i] = loadImage(path.c_str());
		}
		Data.cloud.cloudImg = loadImage("..\\main\\assets\\game09\\cloud.png");
	}
}