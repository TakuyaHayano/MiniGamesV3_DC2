#include "BUTTON_RETRY_PAUSE.h"
#include "GAME09.h"
#include "CONTAINER.h"

namespace GAME09
{
	BUTTON_RETRY_PAUSE::BUTTON_RETRY_PAUSE(GAME* game)
		: BUTTON(game) {
	}
	BUTTON_RETRY_PAUSE::~BUTTON_RETRY_PAUSE()
	{
	}

	void BUTTON_RETRY_PAUSE::create()
	{
		Button = game()->container()->data().pauseRetryButton;
	}
}