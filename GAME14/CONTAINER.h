#pragma once
#include"TITLE.h"
#include"STAGE.h"
#include"MAP.h"
#include"PLAYER.h"
#include"CHARACTER_MANAGER.h"
#include"JUMP_POW.h"
#include"SALMON.h"
#include"GAME14.h"
#include"../../libOne/inc/window.h"
namespace GAME14 {
	class CONTAINER
	{
	private:
		struct DATA {
			GAME14::TITLE::DATA title;
			GAME14::STAGE::DATA stage;
			GAME14:: MAP::DATA map;
			GAME14::CHARACTER::DATA playerChara;
			GAME14::CHARACTER::DATA salmonChara;
			GAME14::PLAYER::DATA player;
			GAME14::SALMON::DATA salmon;
			GAME14::CHARACTER_MANAGER::DATA charaMng;
			GAME14::JUMP_POW::DATA jumpPow;
		};
		DATA Data;
		void setData();
		void setImage();
		void setBgm();
	public:
		void load();
		const DATA& data() { return Data; }
	};
}

