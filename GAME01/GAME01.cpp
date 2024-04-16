#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME01.h"
namespace GAME01
{
	int GAME::create()
	{
		State = TITLE;


		return 0;
	}

	void GAME::destroy()
	{

	}


	void GAME::proc()
	{
		if (State == TITLE)Title();
		else if (State == PLAY)Play();
		else if (State == CLEAR)Clear();
	}

	void GAME::Title() {




		clear(0, 0, 64);
		fill(255, 255, 0);
		textSize(50);
		text("GAME01", 0, 100);
		fill(255);
		text("ENTERキーでメニューに戻る", 0, 1080);
		print("title");


		if (isTrigger(MOUSE_LBUTTON)) {
			Init();
			State = PLAY;
			return;
		}

		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}

	}

	void GAME::Init() {


		ClearFlag = false;
	}

	void GAME::Play() {

		clear(0, 0, 255);
		fill(255);

		fill(255, 255, 255);
		print("play");
		print(" クリックでクリア");

		if (ClearFlag) {
			State = CLEAR;
		}

	}

	void GAME::Clear() {

		clear(0, 0, 255);
		fill(255, 255, 255);
		print("GAME CLEAR");
		print("　クリックでタイトルに戻る");
		if (isTrigger(MOUSE_LBUTTON)) {
			State = TITLE;
		}
	}



}
