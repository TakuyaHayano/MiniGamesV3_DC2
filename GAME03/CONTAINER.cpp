#include"../../libOne/inc/graphic.h"
#include "../../libOne/inc/sound.h"
#include "CONTAINER.h"
#include"ANIMS.h"
#include<time.h>
namespace GAME03 {
    CONTAINER::~CONTAINER() {
        delete Data.playerChara.anims;
    }
    void CONTAINER::load() {
        CreateData();
        LoadGraphics();
        LoadBgms();
    }
    void CONTAINER::CreateData() {

        Data.stage.backColor = COLOR(255, 255, 255, 255);
        Data.stage.gameOverColor = COLOR(255, 0, 0);
        Data.stage.stageClearColor = COLOR(255, 255, 0);
        Data.stage.logoPx = (width - 800) / 2;
        Data.stage.logoPy = 220;
        Data.stage.backToTitleTime = 2;
        Data.stage.time = 0.0f;
        time(&Data.stage.s_time);
        Data.stage.e_time = Data.stage.s_time + 100;
        time(&Data.stage.n_time);

        Data.fade.color = COLOR(60, 60, 60);
        Data.fade.speed = 255 * 2;

        Data.map.fileName = "..\\main\\assets\\game03\\map.txt";
        Data.map.chipSize = 50;
        Data.map.centerX = width / 2.0f - Data.map.chipSize / 2.0f;

        Data.playerChara.charaId = MAP::PLAYER_ID;
        Data.playerChara.hp = 1;
        Data.playerChara.speed = 3.4f * 60;
        Data.playerChara.offsetLeft = 10.0f;
        Data.playerChara.offsetTop = 1.0f;
        Data.playerChara.offsetRight = 40.0f;
        Data.playerChara.offsetBottom = 49.0f;
        Data.player.rightAnimId = 0;
        Data.player.leftAnimId = 1;
        Data.player.jumpFlag = 0;
        Data.player.initVecUp = -16.0f;
        Data.player.initVecDown = 3.0f;
        Data.player.gravity = 48;
        time(&Data.player.s_time);
        Data.player.e_time = Data.player.s_time + 500;
        time(&Data.player.n_time);

        Data.charaMng.numPlayers = 1;

        Data.operationInstructions.backColor = COLOR(255, 255, 255, 255);
        //Data.operationInstructions.backimg = loadImage("..\\main\\assets\\game03\\.png");

    }
    void CONTAINER::LoadGraphics() {
        Data.stage.backImg = loadImage("..\\main\\assets\\game03\\back_wide.png");
        Data.stage.stageClearImg = loadImage("..\\main\\assets\\game03\\StageClear.png");
        Data.stage.gameOverImg = loadImage("..\\main\\assets\\game03\\GameOver.png");

        Data.map.blockImg = loadImage("..\\main\\assets\\game03\\block.png");
        Data.map.goalImg = loadImage("..\\main\\assets\\game03\\goal.png");

        Data.playerChara.anims = new ANIMS("..\\main\\assets\\game03\\player");
        Data.playerChara.shadowImg = loadImage("..\\main\\assets\\game03\\shadow.png");
        Data.playerChara.animData.interval = 0.1f;
    }

    void CONTAINER::LoadBgms() {
        Data.volume.Snd_A = loadSound("..\\main\\assets\\game03\\BGM_A.wav");
        //Data.volume.Snd_B = loadSound("..\\main\\assets\\game03\\BGM_B.wav");
        Data.volume.Se_A = loadSound("..\\main\\assets\\game03\\ƒWƒƒƒ“ƒv.wav");
        //Data.volume.backImg = loadImage("..\\main\\assets\\game03\\.png");
        Data.volume.volume1 = 80;
        Data.volume.volume2 = 80;
        setVolume(Data.volume.Snd_A, -(100 - Data.volume.volume1) * (100 - Data.volume.volume1));
        setVolume(Data.volume.Se_A, -(100 - Data.volume.volume2) * (100 - Data.volume.volume2));
    }
}