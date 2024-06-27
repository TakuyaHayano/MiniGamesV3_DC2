#include "BUTTON_BACK_RESULT.h"
#include "GAME09.h"
#include "CONTAINER.h"

namespace GAME09
{
	BUTTON_BACK_RESULT::BUTTON_BACK_RESULT(GAME* game)
		: BUTTON(game) {
	}
	BUTTON_BACK_RESULT::~BUTTON_BACK_RESULT()
	{
	}

	void BUTTON_BACK_RESULT::create()
	{
		Button = game()->container()->data().resultBackButton;
	}
}