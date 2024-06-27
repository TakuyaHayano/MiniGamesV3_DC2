#include "BUTTON_BACK_PAUSE.h"
#include "GAME09.h"
#include "CONTAINER.h"

namespace GAME09
{
	BUTTON_BACK_PAUSE::BUTTON_BACK_PAUSE(GAME* game)
		: BUTTON(game) {
	}
	BUTTON_BACK_PAUSE::~BUTTON_BACK_PAUSE()
	{
	}

	void BUTTON_BACK_PAUSE::create()
	{
		Button = game()->container()->data().pauseBackButton;
	}
}