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
        Data.stage.time = 0;
        time(&Data.stage.s_time);
        Data.stage.e_time = Data.stage.s_time + 100;
        time(&Data.stage.n_time);

        Data.fade.color = COLOR(60, 60, 60);
        Data.fade.speed = 255 * 2;

        Data.map.fileName = "..\\main\\assets\\game03\\data\\map.txt";
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
        Data.player.e_time = Data.player.s_time + 100;
        time(&Data.player.n_time);

        Data.charaMng.numPlayers = 1;

        Data.volume.backColor = COLOR(255);

        Data.operationInstructions.backColor = COLOR(255, 255, 255, 255);

    }
    void CONTAINER::LoadGraphics() {
        Data.stage.backImg = loadImage("..\\main\\assets\\game03\\data\\back_wide.png");
        Data.stage.stageClearImg = loadImage("..\\main\\assets\\game03\\data\\StageClear.png");
        Data.stage.gameOverImg = loadImage("..\\main\\assets\\game03\\data\\GameOver.png");

        Data.map.blockImg = loadImage("..\\main\\assets\\game03\\data\\block.png");
        Data.map.goalImg = loadImage("..\\main\\assets\\game03\\data\\goal.png");

        Data.playerChara.anims = new ANIMS("..\\main\\assets\\game03\\data\\player");
        Data.playerChara.shadowImg = loadImage("..\\main\\assets\\game03\\data\\shadow.png");
        Data.playerChara.animData.interval = 0.1f;

        //Data.volume.backImg = loadImage("..\\main\\assets\\game03\\data\\.png");
        
        Data.operationInstructions.backimg = loadImage("..\\main\\assets\\game03\\data\\ëÄçÏê‡ñæ.png");
    }

    void CONTAINER::LoadBgms() {
        Data.volume.Snd_A = loadSound("..\\main\\assets\\game03\\sounds\\BGM_A.wav");
        Data.volume.Snd_B = loadSound("..\\main\\assets\\game03\\sounds\\BGM_B.wav");
        Data.volume.Snd_C = loadSound("..\\main\\assets\\game03\\sounds\\BGM_C.wav");
        Data.volume.Snd_D = loadSound("..\\main\\assets\\game03\\sounds\\BGM_D.wav");
        Data.volume.Se_A = loadSound("..\\main\\assets\\game03\\sounds\\ÉWÉÉÉìÉv.wav");
        Data.volume.Se_B = loadSound("..\\main\\assets\\game03\\sounds\\äΩê∫Ç∆îèéË.wav");
        Data.volume.Se_C = loadSound("..\\main\\assets\\game03\\sounds\\ä‘î≤ÇØ7.wav");
        Data.volume.volume1 = 80.0f;
        Data.volume.volume2 = 80.0f;
        setVolume(Data.volume.Snd_A, -(100 - (int)Data.volume.volume1) * (100 - (int)Data.volume.volume1));
        setVolume(Data.volume.Snd_B, -(100 - (int)Data.volume.volume1) * (100 - (int)Data.volume.volume1));
        setVolume(Data.volume.Snd_C, -(100 - (int)Data.volume.volume1) * (100 - (int)Data.volume.volume1));
        setVolume(Data.volume.Se_A, -(100 - (int)Data.volume.volume2) * (100 - (int)Data.volume.volume2));
        setVolume(Data.volume.Se_B, -(100 - (int)Data.volume.volume2) * (100 - (int)Data.volume.volume2));
        setVolume(Data.volume.Se_C, -(100 - (int)Data.volume.volume2) * (100 - (int)Data.volume.volume2));
    }
}