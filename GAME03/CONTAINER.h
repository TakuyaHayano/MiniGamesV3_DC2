#pragma once
#include"TITLE.h"
#include"STAGE.h"
#include"FADE.h"
#include"MAP.h"
#include"PLAYER.h"
#include"VOLUME.h"
#include"OPERATION_INSTRUCTIONS.h"
#include"CHARACTER_MANAGER.h"
namespace GAME03 {
	class CONTAINER
	{
    private:
        struct DATA {
            STAGE::DATA stage;
            FADE::DATA fade;
            MAP::DATA map;
            CHARACTER::DATA playerChara;
            PLAYER::DATA player;
            VOLUME::DATA volume;
            OPERATION_INSTRUCTIONS::DATA operationInstructions;
            CHARACTER_MANAGER::DATA charaMng;
        };
        DATA Data;
        void CreateData();
        void LoadGraphics();
        void LoadBgms();
    public:
        ~CONTAINER();
        void load();
        const DATA& data() { return Data; }
	};
}
