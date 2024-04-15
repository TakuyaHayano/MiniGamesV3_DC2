#pragma once
#include "TITLE.h"
//#include "TRANSITION.h"
#include "BACKGROUND.h"
#include "BUTTON.h"

namespace GAME09
{
	class CONTAINER
	{
		struct DATA {
			TITLE::DATA title;
			BACKGROUND::DATA backG;
			BUTTON::DATA startButton;
			BUTTON::DATA helpButton;
			BUTTON::DATA endButton;
		};
		DATA Data;
	public:
		void load();
		void setData();
		void loadGraphic();
		const DATA& data() {
			return Data;
		}
	};
}