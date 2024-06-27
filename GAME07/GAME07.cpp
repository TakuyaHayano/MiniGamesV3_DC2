#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME07.h"
#include "GAME_M.h"
#include "CONTAINER.h"
#include "TITLE.h"
#include "PLAY.h"
#include "STAGE.h"
#include "GAME_CLEAR.h"
#include "GAME_OVER.h"
namespace GAME07
{
	int GAME::create()
	{
		return 0;
	}

	void GAME::destroy()
	{
	}

	void GAME::proc()
	{
		/*clear(0, 0, 64);
		textSize(50);
		fill(255, 255, 0);
		text("Who Is This?", 0, 100);
		fill(255);
		text("SPACEキーでメニューに戻る、ENTERキーでゲームへ", 0, 1080);
		if (isTrigger(KEY_SPACE)) {
			main()->backToMenu();
		}
		if (isTrigger(KEY_ENTER)) {
			GAME_M game;

			game.run();
		}*/
		GAME_M game;

		game.run();
	}
}
