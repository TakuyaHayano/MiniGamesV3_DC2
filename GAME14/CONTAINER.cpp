#include "CONTAINER.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/sound.h"

namespace GAME14 {
	void CONTAINER::load() {
		setData();
		setImage();
		setBgm();
	}
	void CONTAINER::setData(){
		Data.map.fileName = "../GAME14\\assets\\map1.txt";
		Data.map.backPosX = (width - 1500) / 2;
		Data.map.backPosOffsetY = 765.0f;
		Data.map.blockSizeX = 120.0f;
		Data.map.blockSizeY = 90.0f;
		Data.map.ofset = 240.0f;
		Data.map.salmonOffsetTime = 10;
		Data.map.salmonLimitTime = 15;
		Data.map.salmonAppAreaEndX = 390;
		Data.map.salmonAppAreaStartX = 610;

		Data.title.backColor = COLOR(69, 254, 240);
		Data.title.titleNameSize = 120.0f;
		Data.title.titleName1 = "�ނ���������";
		Data.title.titleName2 = "�T�[�����W�����v!!";
		Data.title.titleNameColor = COLOR(253, 70, 202);
		Data.title.titleName1Pos = VECTOR2(300, 200);
		Data.title.titleName2Pos = VECTOR2(600, 400);
		Data.title.stateChangeMsSize = 50.0f;
		Data.title.stateChangeMs = "click to START...";
		Data.title.stateChangeMsColor = COLOR(32, 61, 208);
		Data.title.stateChangeMsPos = VECTOR2((width - Data.title.stateChangeMsSize*17/2)/2 ,
											  height - Data.title.stateChangeMsSize * 2);
		Data.title.controlTextSize = 80.0f;
		Data.title.controlText1 = "���N���b�N�ŃW�����v�Q�[�W�̊J�n�E��~";
		Data.title.controlText2 = "�}�E�X�J�[�\���ŕ�������";
		Data.title.controlText1Pos = VECTOR2((width - Data.title.controlTextSize * strlen(Data.title.controlText1) / 2) / 2, height *0.6);
		Data.title.controlText2Pos = VECTOR2((width - Data.title.controlTextSize * strlen(Data.title.controlText2) / 2) / 2, height *0.6 + 100);
		Data.title.bgmNameSize = 30.0f;
		Data.title.bgmName = "BGM:�A���̃_�C�������h�_�X�g";
		Data.title.featName = "��:�t���I�@projectof:�k���X���";
		Data.title.bgmNameColor = COLOR(32, 61, 208);
		Data.title.bgmNamePos = VECTOR2(width - Data.title.bgmNameSize * 18, height - Data.title.bgmNameSize * 2);
		Data.title.undercortClor = COLOR(80, 80, 80, 80);
		Data.title.undercortPos = VECTOR2(Data.title.bgmNamePos.x, Data.title.bgmNamePos.y - Data.title.bgmNameSize);
		Data.title.undercortSize = VECTOR2(Data.title.bgmNameSize * 16, Data.title.bgmNameSize * 2);



		Data.stage.str1P = "GAME CLEAR";
		Data.stage.str2P = "click to TITLE...";
		Data.stage.strColor = COLOR(255, 252, 104);
		Data.stage.str1Size = 150.0f;
		Data.stage.str2Size = 50.0f;
		Data.stage.str1Pos = VECTOR2((width - Data.stage.str1Size * 5) / 2, height / 2);
		Data.stage.str2Pos = VECTOR2((width - Data.stage.str2Size * 18 / 2) / 2, Data.stage.str1Pos.y + 60);
		Data.stage.textSize = 90;
		Data.stage.textColor = COLOR(255, 255, 255);
		Data.stage.salmonText = VECTOR2(width - Data.map.ofset-Data.stage.textSize, Data.stage.textSize);
		Data.stage.undercoatColor = COLOR(0, 0, 0, 80);
		Data.stage.undercoatPos = VECTOR2(width-Data.map.ofset-300, 0);
		Data.stage.undercoatSize = VECTOR2(300, 100);
		Data.stage.imgSize = 0.1f;
		Data.stage.imgPos = Data.stage.undercoatPos+VECTOR2(40,0);

		Data.playerChara.charaId = MAP::PLAYER_ID;
		Data.playerChara.hp = 0;
		Data.playerChara.color = COLOR(255, 0, 0);
		Data.playerChara.offsetLeft = 0.0f;
		Data.playerChara.offsetTop = 360.0f;
		Data.playerChara.offsetRight = 120.0f;
		Data.playerChara.offsetBottom = 0.0f;
		Data.player.imgSize = 0.4f;
		Data.player.gravity = 9.8f;
		Data.player.jumpSpeed.x = 400.0f;
		Data.player.jumpSpeed.y = 700.0f;
		Data.player.imgOffsetY = 270.0f;
		Data.player.imgOffsetX = 120.0f;
		Data.player.offsetTop = 90;

		Data.salmonChara.charaId = MAP::SALMON_ID;
		Data.salmonChara.hp = 0;
		Data.salmonChara.color = COLOR(255, 170, 233);
		Data.salmonChara.speed = 200.0f;
		Data.salmonChara.offsetLeft = 0.0f;
		Data.salmonChara.offsetTop = 0.0f;
		Data.salmonChara.offsetRight = 90.0f;
		Data.salmonChara.offsetBottom = 180.0f;
		Data.salmon.imgSize = 0.2f;
		Data.salmon.animCunt = 0;
		Data.salmon.animTime = 0.0f;
		Data.salmon.interval = 0.157f;

		Data.jumpPow.gaugeSizeW = 200.0f;
		Data.jumpPow.gaugeSizeH = 20.0f;
		Data.jumpPow.gaugeColor = COLOR(0, 0, 0, 80);
		Data.jumpPow.curGaugeColor = COLOR(255, 0, 0);
		Data.jumpPow.offsetX = 10.0f;
		Data.jumpPow.offsetY = 90.0f;
		Data.jumpPow.yardstickColor = COLOR(255, 255, 255);
		Data.jumpPow.yardstickSize = 1.0f;
		Data.jumpPow.numEqual = 5;
		Data.jumpPow.powSpeed = 1.15f*delta;
		Data.jumpPow.startDirectionTime = 0.1f;
		Data.jumpPow.limitPow = 1;


		Data.charaMng.numPlayers = 1;
		Data.charaMng.numSalmons = 1;
	}
	void CONTAINER::setImage(){
		Data.map.blockImg = loadImage("../GAME14\\assets\\jimen.png");
		Data.map.goalImg = loadImage("../GAME14\\assets\\goal.png");
		Data.map.backImg = loadImage("../GAME14\\assets\\haikei.png");
		Data.stage.img = loadImage("../GAME14\\assets\\sakuramasu_0.png");
		Data.player.img[0] = loadImage("../GAME14\\assets\\mukuge_0.png");
		Data.player.img[1] = loadImage("../GAME14\\assets\\mukuge_1.png");
		Data.player.img[2] = loadImage("../GAME14\\assets\\mukuge_2.png");
		Data.player.img[3] = loadImage("../GAME14\\assets\\mukuge_3.png");
		Data.player.img[4] = loadImage("../GAME14\\assets\\mukuge_4.png");
		Data.player.img[5] = loadImage("../GAME14\\assets\\mukuge_5.png");
		Data.salmon.img[0] = Data.stage.img;
		Data.salmon.img[1] = loadImage("../GAME14\\assets\\sakuramasu_1.png");
	}
	void CONTAINER::setBgm() {
		Data.title.bgm = loadSound("../GAME14\\assets\\bgm.wav");
	}
}