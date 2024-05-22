#pragma once
#include "TITLE.h"
#include "STAGE.h"
//#include "TRANSITION.h"
#include "BACKGROUND.h"
#include "BUTTON.h"
#include "PHYSICS_ENGINE.h"
#include "BOX.h"
#include "FRUITS.h"
#include "CLOUD.h"
#include "BUBBLE.h"
#include "NEXT.h"
#include "SCORE.h"
#include "DRAW_NUM.h"
#include "FRUITS_BUBBLE.h"
#include "FRUITS_BUBBLES.h"

namespace GAME09
{
	class CONTAINER
	{
		struct DATA {
			TITLE::DATA title;
			STAGE::DATA stage;
			BACKGROUND::DATA backG;
			BUTTON::DATA startButton;
			BUTTON::DATA helpButton;
			BUTTON::DATA endButton;
			PHYSICS_ENGINE::DATA physics;
			BOX::DATA box;
			FRUITS::DATA fruits;
			CLOUD::DATA cloud;
			BUBBLE::DATA bubble;
			NEXT::DATA next;
			SCORE::DATA score;
			DRAW_NUM::DATA drawNum;
			FRUITS_BUBBLE::DATA fruitsBubble;
			FRUITS_BUBBLES::DATA fruitsBubbles;
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