#include "CONTAINER.h"
#include <string>
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/sound.h"

namespace GAME09
{
	void CONTAINER::load() {
		setData();
		loadGraphic();
		loadSounds();
	}
	void CONTAINER::setData() {
		Data.title.titlePos = VECTOR2(width / 2, height / 2);
		Data.title.imgSize = 1;
		Data.title.hueSpeed = 360;

		Data.stage.vibeTime = 0.83f;
		Data.stage.waitTime = 1.3f;
		Data.stage.operationImgPos = VECTOR2(width / 2, height / 2);
		Data.stage.operationImgSize = 1;

		Data.pause.imgPos = VECTOR2(width / 2, height / 2);
		Data.pause.imgSize = 1.5f;
		Data.pause.moveDatas[PAUSE::START].animeTime = 0.25f;
		Data.pause.moveDatas[PAUSE::START].startOfst = -height;
		Data.pause.moveDatas[PAUSE::START].endOfst = 100;
		Data.pause.moveDatas[PAUSE::BACK].animeTime = 0.1f;
		Data.pause.moveDatas[PAUSE::BACK].startOfst = 100;
		Data.pause.moveDatas[PAUSE::BACK].endOfst = 0;
		Data.pause.moveDatas[PAUSE::NORMAL].animeTime = 0.1f;
		Data.pause.moveDatas[PAUSE::NORMAL].startOfst = 0;
		Data.pause.moveDatas[PAUSE::NORMAL].endOfst = 0;

		Data.result.imgPos = VECTOR2(width / 2, height / 2);
		Data.result.imgSize = 1.5f;
		Data.result.hiScoreImgPos = VECTOR2(1550, 650);
		Data.result.hiScoreImgSize = 0.6f;
		Data.result.finalFieldPos = VECTOR2(130, 280);
		Data.result.finalFieldSize = 0.477f;
		Data.result.scorePos = VECTOR2(1550, 420);
		Data.result.scoreSize = 0.9f;
		Data.result.hiScorePos = VECTOR2(1550, 750);
		Data.result.hiScoreSize = 0.7f;
		Data.result.moveDatas[RESULT::START].animeTime = 0.3f;
		Data.result.moveDatas[RESULT::START].startOfst = -height;
		Data.result.moveDatas[RESULT::START].endOfst = 100;
		Data.result.moveDatas[RESULT::BACK].animeTime = 0.1f;
		Data.result.moveDatas[RESULT::BACK].startOfst = 100;
		Data.result.moveDatas[RESULT::BACK].endOfst = 0;
		Data.result.moveDatas[RESULT::NORMAL].animeTime = 0.1f;
		Data.result.moveDatas[RESULT::NORMAL].startOfst = 0;
		Data.result.moveDatas[RESULT::NORMAL].endOfst = 0;
		Data.result.operationImgPos = VECTOR2(width / 2, height / 2);
		Data.result.operationImgSize = 1;

		Data.help.imgPos = VECTOR2(width / 2, height / 2);
		Data.help.imgSize = 1;
		Data.help.operationImgPos = VECTOR2(width / 2, height / 2);
		Data.help.operationImgSize = 1;

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
		Data.resultRetryButton.pos = VECTOR2(330, 950);
		Data.resultRetryButton.imgSize = 0.83f;
		Data.resultRetryButton.initSelectMotion = true;
		Data.resultBackButton.pos = VECTOR2(887, 950);
		Data.resultBackButton.imgSize = 0.83f;
		Data.resultBackButton.initSelectMotion = true;

		Data.continueButton.pos = VECTOR2(960, 440);
		Data.continueButton.imgSize = 0.65f;
		Data.continueButton.initSelectMotion = true;
		Data.pauseRetryButton.pos = VECTOR2(960, 590);
		Data.pauseRetryButton.imgSize = 0.65f;
		Data.pauseRetryButton.initSelectMotion = true;
		Data.pauseBackButton.pos = VECTOR2(960, 740);
		Data.pauseBackButton.imgSize = 0.65f;
		Data.pauseBackButton.initSelectMotion = true;

		Data.physics.gravity = VECTOR2(0.0f, 1800.0f);

		Data.box.pos = VECTOR2(width / 2, height / 2);
		Data.box.imgSize = 1;
		Data.box.left = -338;
		Data.box.right = 335;
		Data.box.under = 472;
		Data.box.up = -380;

		Data.fruits.sw = 2;
		Data.fruits.attenuationRate = 0.998f;
		Data.fruits.initTheta = -0.7854f;
		Data.fruits.cherryRadius = 24;
		Data.fruits.cherryImgSize = 0.062f;
		Data.fruits.nextFruitsSizeRate = 1.232f;
		Data.fruits.inflateMaxTime = 0.1f;
		Data.fruits.initValue = 0.5f;
		Data.fruits.vibeMaxDist = 1.8f;
		Data.fruits.vibeSpeed = 60;

		Data.cloud.fruitsInitPos = VECTOR2(width / 2, 136);
		Data.cloud.fruitsImgSize = 1;
		Data.cloud.cloudPosOfst = VECTOR2(73, -51);
		Data.cloud.cloudImgSize = 0.51f;
		Data.cloud.left = 672;
		Data.cloud.right = 1228;
		Data.cloud.moveSpeed = 340;
		Data.cloud.lineWidth = 4;

		Data.bubble.pos = VECTOR2(width / 2, height / 2);
		Data.bubble.imgSize = 0.33f;
		Data.bubble.maxMoveOfst = VECTOR2(0, 20);
		Data.bubble.animeTime = 2.0f;
		
		Data.next.strOfst = VECTOR2(0, -125);
		Data.next.bubbleSize = 0.7f;
		Data.next.bubblePos = VECTOR2(1620, 270);
		Data.next.useFruitsNum = 4;
		Data.next.useFruitsNumSecret = 10;

		Data.score.strOfst = VECTOR2(0, -160);
		Data.score.hiScoreStrOfst = VECTOR2(0, 40);
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
		Data.score.scoreOfst = VECTOR2(0, -20);
		Data.score.scoreSize = 0.6f;
		Data.score.hiScoreOfst = VECTOR2(0, 80);
		Data.score.hiScoreSize = 0.4f;
		Data.score.fileName = "..\\main\\assets\\game09\\hi_score.txt";

		Data.drawNum.numSize = 0.31f;
		Data.drawNum.digitSpace = 80;

		Data.fruitsBubble.bubblePos = VECTOR2(500, 500);
		Data.fruitsBubble.bubbleSize = 0.75f;
		Data.fruitsBubble.cherryImgSize = 0.062f;
		Data.fruitsBubble.nextFruitsSizeRate = 1.232f;
		Data.fruitsBubble.maxImgSize = 0.18f;
		Data.fruitsBubble.maxMoveDist = 50;
		Data.fruitsBubble.maxMoveTime = 1;
		Data.fruitsBubble.minMoveTime = 0.5f;
		Data.fruitsBubble.maxSize = 0.95f;
		Data.fruitsBubble.minSize = 0.75f;

		Data.fruitsBubbles.order.emplace_back(FRUITS::STRAWBERRY);
		Data.fruitsBubbles.order.emplace_back(FRUITS::WATERMELON);
		Data.fruitsBubbles.order.emplace_back(FRUITS::PEAR);
		Data.fruitsBubbles.order.emplace_back(FRUITS::CHERRY);
		Data.fruitsBubbles.order.emplace_back(FRUITS::PINEAPPLE);
		Data.fruitsBubbles.order.emplace_back(FRUITS::PERSIMMON);
		Data.fruitsBubbles.order.emplace_back(FRUITS::MELON);
		Data.fruitsBubbles.order.emplace_back(FRUITS::PEACH);
		Data.fruitsBubbles.order.emplace_back(FRUITS::DEKOPON);
		Data.fruitsBubbles.order.emplace_back(FRUITS::GRAPE);
		Data.fruitsBubbles.order.emplace_back(FRUITS::APPLE);
		Data.fruitsBubbles.lenX = 700;
		Data.fruitsBubbles.lenY = 360;
		Data.fruitsBubbles.initDist = 0.0f;
		Data.fruitsBubbles.speed = 100.0f;
		Data.fruitsBubbles.moveDatas[FRUITS_BUBBLES::START].animeTime = 0.33f;
		Data.fruitsBubbles.moveDatas[FRUITS_BUBBLES::START].startMag = 3.0f;
		Data.fruitsBubbles.moveDatas[FRUITS_BUBBLES::START].endMag = 1.0f;
		Data.fruitsBubbles.moveDatas[FRUITS_BUBBLES::STAY].animeTime = 1.0f;
		Data.fruitsBubbles.moveDatas[FRUITS_BUBBLES::STAY].startMag = 1.0f;
		Data.fruitsBubbles.moveDatas[FRUITS_BUBBLES::STAY].endMag = 1.0f;
		Data.fruitsBubbles.moveDatas[FRUITS_BUBBLES::PULL].animeTime = 0.33f;
		Data.fruitsBubbles.moveDatas[FRUITS_BUBBLES::PULL].startMag = 1.0f;
		Data.fruitsBubbles.moveDatas[FRUITS_BUBBLES::PULL].endMag = 0.8f;
		Data.fruitsBubbles.moveDatas[FRUITS_BUBBLES::END].animeTime = 0.33f;
		Data.fruitsBubbles.moveDatas[FRUITS_BUBBLES::END].startMag = 0.8f;
		Data.fruitsBubbles.moveDatas[FRUITS_BUBBLES::END].endMag = 3.0f;

		Data.curtain.moveTimes[CURTAIN::START] = 0.33f;
		Data.curtain.moveTimes[CURTAIN::STAY] = 1.5f;
		Data.curtain.moveTimes[CURTAIN::END] = 0.25f;
		Data.curtain.imgPos = VECTOR2(width / 2, height / 2);
		Data.curtain.openOfst = VECTOR2(width / 2, 0);
		Data.curtain.imgSize = 1.5f;

		Data.transition.outTime = 1.8f;
		Data.transition.inTime = 0.28f;

		Data.command.command.emplace_back(KEY_UP);
		Data.command.command.emplace_back(KEY_UP);
		Data.command.command.emplace_back(KEY_DOWN);
		Data.command.command.emplace_back(KEY_DOWN);
		Data.command.command.emplace_back(KEY_LEFT);
		Data.command.command.emplace_back(KEY_RIGHT);
		Data.command.command.emplace_back(KEY_LEFT);
		Data.command.command.emplace_back(KEY_RIGHT);
		Data.command.command.emplace_back(KEY_B);
		Data.command.command.emplace_back(KEY_A);

		Data.eCircle.imgSize = 0.37f;
		Data.eCircle.pos = VECTOR2(1630, 750);

		Data.readyGo.readyAnim.data().emplace_back(ANIM::MOVE_DATA{ 0.33f, VECTOR2(0, 0), VECTOR2(0, 0), 0, 0 });
		Data.readyGo.readyAnim.data().emplace_back(ANIM::MOVE_DATA{ 0.166f, VECTOR2(960, 460), VECTOR2(960, 540), 0, 255 });
		Data.readyGo.readyAnim.data().emplace_back(ANIM::MOVE_DATA{ 0.083f, VECTOR2(960, 540), VECTOR2(960, 500) });
		Data.readyGo.readyAnim.data().emplace_back(ANIM::MOVE_DATA{ 0.083f, VECTOR2(960, 500), VECTOR2(960, 540) });
		Data.readyGo.readyAnim.data().emplace_back(ANIM::MOVE_DATA{ 0.66f, VECTOR2(960, 540), VECTOR2(960, 540) });
		Data.readyGo.readyAnim.data().emplace_back(ANIM::MOVE_DATA{ 0.083f, VECTOR2(960, 540), VECTOR2(960, 540), 255, 0 });
		Data.readyGo.goAnim.data().emplace_back(ANIM::MOVE_DATA{ 1.42f, VECTOR2(0, 0), VECTOR2(0, 0), 0, 0 });
		Data.readyGo.goAnim.data().emplace_back(ANIM::MOVE_DATA{ 0.166f, VECTOR2(960, 460), VECTOR2(960, 540), 0, 255 });
		Data.readyGo.goAnim.data().emplace_back(ANIM::MOVE_DATA{ 0.4f, VECTOR2(960, 540), VECTOR2(960, 540) });
		Data.readyGo.goAnim.data().emplace_back(ANIM::MOVE_DATA{ 0.2f, VECTOR2(960, 540), VECTOR2(960, 540), 255, 0 });
		Data.readyGo.effectAnim.data().emplace_back(ANIM::MOVE_DATA{ 1.586f, VECTOR2(0, 0), VECTOR2(0, 0), 0, 0 });
		Data.readyGo.effectAnim.data().emplace_back(ANIM::MOVE_DATA{ 0.166f, VECTOR2(960, 540), VECTOR2(960, 540), 200, 0, 1, 1.3f });
		Data.readyGo.effectAnim.data().emplace_back(ANIM::MOVE_DATA{ 0.2f, VECTOR2(960, 540), VECTOR2(960, 540), 200, 0, 1, 1.5f });

		Data.cracker.pos = VECTOR2(1550, 150);
		Data.cracker.startWidth = 500;
		Data.cracker.size = VECTOR2(12, 12);
		Data.cracker.speed = 650;
		Data.cracker.colors[CRACKER::SKY]    = COLOR(0, 255, 255);
		Data.cracker.colors[CRACKER::PURPLE] = COLOR(255, 0, 255);
		Data.cracker.colors[CRACKER::RED]    = COLOR(255, 0, 0);
		Data.cracker.colors[CRACKER::GREEN]  = COLOR(0, 255, 0);
		Data.cracker.colors[CRACKER::YELLOW] = COLOR(255, 255, 0);
		Data.cracker.interval = 0.06f;
		Data.cracker.angSpeed = 160;
	}
	void CONTAINER::loadGraphic() {
		Data.title.titleImg = loadImage("..\\main\\assets\\game09\\title.png");
		Data.stage.operationImg = loadImage("..\\main\\assets\\game09\\operation_stage.png");
		Data.pause.pauseImg = loadImage("..\\main\\assets\\game09\\pause_back.png");
		Data.result.resultImg = loadImage("..\\main\\assets\\game09\\result_back.png");
		Data.result.resultScoreImg = loadImage("..\\main\\assets\\game09\\result_score.png");
		Data.result.resultHiScoreImg = loadImage("..\\main\\assets\\game09\\hi_score_str.png");
		Data.result.operationImg = loadImage("..\\main\\assets\\game09\\operation_result.png");
		Data.help.Imgs[HELP::OPERATION] = loadImage("..\\main\\assets\\game09\\help_operation.png");
		Data.help.Imgs[HELP::RULE] = loadImage("..\\main\\assets\\game09\\help_rule.png");
		Data.help.Imgs[HELP::KINDS] = loadImage("..\\main\\assets\\game09\\help_kinds.png");
		Data.help.operationImg = loadImage("..\\main\\assets\\game09\\operation_help.png");
		Data.backG.img = loadImage("..\\main\\assets\\game09\\back_ground.png");
		Data.startButton.selectedImg = loadImage("..\\main\\assets\\game09\\start_button.png");
		Data.startButton.notSelectedImg = loadImage("..\\main\\assets\\game09\\start_button_gray.png");
		Data.helpButton.selectedImg = loadImage("..\\main\\assets\\game09\\help_button.png");
		Data.helpButton.notSelectedImg = loadImage("..\\main\\assets\\game09\\help_button_gray.png");
		Data.endButton.selectedImg = loadImage("..\\main\\assets\\game09\\end_button.png");
		Data.endButton.notSelectedImg = loadImage("..\\main\\assets\\game09\\end_button_gray.png");
		Data.resultRetryButton.selectedImg = loadImage("..\\main\\assets\\game09\\retry_button.png");
		Data.resultRetryButton.notSelectedImg = loadImage("..\\main\\assets\\game09\\retry_button_gray.png");
		Data.resultBackButton.selectedImg = loadImage("..\\main\\assets\\game09\\back_button.png");
		Data.resultBackButton.notSelectedImg = loadImage("..\\main\\assets\\game09\\back_button_gray.png");
		Data.continueButton.selectedImg = loadImage("..\\main\\assets\\game09\\continue_button.png");
		Data.continueButton.notSelectedImg = loadImage("..\\main\\assets\\game09\\continue_button_gray.png");
		Data.pauseRetryButton.selectedImg = loadImage("..\\main\\assets\\game09\\retry_button.png");
		Data.pauseRetryButton.notSelectedImg = loadImage("..\\main\\assets\\game09\\retry_button_gray.png");
		Data.pauseBackButton.selectedImg = loadImage("..\\main\\assets\\game09\\back_button.png");
		Data.pauseBackButton.notSelectedImg = loadImage("..\\main\\assets\\game09\\back_button_gray.png");
		Data.box.img = loadImage("..\\main\\assets\\game09\\box.png");
		Data.box.frontImg = loadImage("..\\main\\assets\\game09\\box_front.png");
		for (int i = 0; i < FRUITS::NUM_FRUITS_KINDS; i++) {
			std::string path = "..\\main\\assets\\game09\\";
			path += std::to_string(i);
			path += ".png";
			Data.fruits.imgs[i] = loadImage(path.c_str());
		}
		Data.cloud.cloudImg = loadImage("..\\main\\assets\\game09\\cloud.png");
		Data.bubble.img = loadImage("..\\main\\assets\\game09\\bubble.png");
		Data.next.strImg = loadImage("..\\main\\assets\\game09\\next_str.png");
		Data.score.strImg = loadImage("..\\main\\assets\\game09\\score_str.png");
		Data.score.hiScoreStrImg = loadImage("..\\main\\assets\\game09\\hi_score_str.png");
		Data.drawNum.numImg = loadImage("..\\main\\assets\\game09\\num.png");
		divideImage(Data.drawNum.numImg, 10, 1, 260, 512, Data.drawNum.numImgs);
		Data.fruitsBubble.imgs = Data.fruits.imgs;
		Data.curtain.imgL = loadImage("..\\main\\assets\\game09\\curtain_L.png");
		Data.curtain.imgR = loadImage("..\\main\\assets\\game09\\curtain_R.png");
		Data.curtain.imgClose = loadImage("..\\main\\assets\\game09\\curtain_close.png");
		Data.eCircle.img = loadImage("..\\main\\assets\\game09\\evolutionary_circle.png");
		Data.readyGo.imgReady = loadImage("..\\main\\assets\\game09\\ready.png");
		Data.readyGo.imgGo = loadImage("..\\main\\assets\\game09\\go.png");
	}
	void CONTAINER::loadSounds() {
		Data.soundMNG.soundEffects[SOUNDMNG::DROP] = loadSound("..\\main\\assets\\game09\\drop.wav");
		Data.soundMNG.soundEffects[SOUNDMNG::STICK] = loadSound("..\\main\\assets\\game09\\stick.wav");
		Data.soundMNG.bgm = loadSound("..\\main\\assets\\game09\\BGM.wav");
	}
}