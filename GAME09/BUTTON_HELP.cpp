#include "BUTTON_HELP.h"
#include "GAME09.h"
#include "CONTAINER.h"

namespace GAME09
{
	BUTTON_HELP::BUTTON_HELP(GAME* game)
		: BUTTON(game) {
	}
	BUTTON_HELP::~BUTTON_HELP()
	{
	}

	void BUTTON_HELP::create()
	{
		Button = game()->container()->data().helpButton;
	}
}