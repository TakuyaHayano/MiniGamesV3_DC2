#include "BUTTON_END.h"
#include "GAME09.h"
#include "CONTAINER.h"

namespace GAME09
{
	BUTTON_END::BUTTON_END(GAME* game)
		: BUTTON(game) {
	}
	BUTTON_END::~BUTTON_END()
	{
	}

	void BUTTON_END::create()
	{
		Button = game()->container()->data().endButton;
	}
}