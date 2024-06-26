#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "MYCLASS001.h"
#include "GAME15.h"
namespace GAME15
{
	int GAME::create()
	{
		MyClass001 = new MYCLASS001;
		return 0;
	}

	void GAME::destroy()
	{
		delete MyClass001;
	}

	void GAME::proc()
	{
		clear(0, 0, 64);
		MyClass001->drawName();
		fill(255);
		text("ENTERキーでメニューに戻る", 0, 1080);
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}
}
