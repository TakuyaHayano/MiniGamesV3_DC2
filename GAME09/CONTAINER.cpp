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

		Data.cloud.fruitsInitPos = VECTOR2(width / 2, 150);
		Data.cloud.fruitsImgSize = 1;
		Data.cloud.cloudPosOfst = VECTOR2(50, -50);
		Data.cloud.cloudImgSize = 0.45f;
		Data.cloud.left = 672;
		Data.cloud.right = 1228;
		Data.cloud.moveSpeed = 340;
		Data.cloud.lineWidth = 4;

		Data.bubble.pos = VECTOR2(width / 2, height / 2);
		Data.bubble.imgSize = 0.33f;
		Data.bubble.maxMoveOfst = VECTOR2(0, 20);
		Data.bubble.animeTime = 2.0f;
		
		Data.next.strOfst = VECTOR2(0, -70);
		Data.next.bubbleSize = 0.7f;
		Data.next.bubblePos = VECTOR2(1620, 270);

		Data.score.strOfst = VECTOR2(0, -70);
		Data.score.bubbleSize = 0.9f;
		Data.score.bubblePos = VECTOR2(290, 240);
		Data.score.fruitsScores[FRUITS::CHERRY]     = 1;
		Data.score.fruitsScores[FRUITS::STRAWBERRY] = 3;
		Data.score.fruitsScores[FRUITS::GRAPE]      = 6;
		Data.score.fruitsScores[FRUITS::DEKOPON]    = 10;
		Data.score.fruitsScores[FRUITS::PERSIMMON]  = 15;
		Data.score.fruitsScores[FRUITS::APPLE]      = 21;
		Data.score.fruitsScores[FRUITS::PEAR]       = 28;
		Data.score.fruitsScores[FRUITS::PEACH]      = 36;
		Data.score.fruitsScores[FRUITS::PINEAPPLE]  = 45;
		Data.score.fruitsScores[FRUITS::MELON]      = 55;
		Data.score.fruitsScores[FRUITS::WATERMELON] = 66;

		Data.drawNum.numSize = 0.31f;
		Data.drawNum.digitSpace = 80;
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
		Data.bubble.img = loadImage("..\\main\\assets\\game09\\bubble.png");
		Data.drawNum.numImg = loadImage("..\\main\\assets\\game09\\num.png");
		divideImage(Data.drawNum.numImg, 10, 1, 260, 512, Data.drawNum.numImgs);
	}
}