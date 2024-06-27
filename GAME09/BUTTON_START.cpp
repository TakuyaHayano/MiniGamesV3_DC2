#include "BUTTON_START.h"
#include "GAME09.h"
#include "CONTAINER.h"

namespace GAME09
{
	BUTTON_START::BUTTON_START(GAME* game)
		: BUTTON(game) {
	}
	BUTTON_START::~BUTTON_START()
	{
	}

	void BUTTON_START::create()
	{
		Button = game()->container()->data().startButton;
	}
}