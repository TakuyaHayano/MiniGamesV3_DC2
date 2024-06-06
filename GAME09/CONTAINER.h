#pragma once
#include "TITLE.h"
#include "STAGE.h"
#include "PAUSE.h"
#include "RESULT.h"
#include "TRANSITION.h"
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
#include "CURTAIN.h"
#include "COMMAND.h"
#include "EVOLUTIONARY_CIRCLE.h"

namespace GAME09
{
	class CONTAINER
	{
		struct DATA {
			TITLE::DATA title;
			STAGE::DATA stage;
			PAUSE::DATA pause;
			RESULT::DATA result;
			BACKGROUND::DATA backG;
			BUTTON::DATA startButton;
			BUTTON::DATA helpButton;
			BUTTON::DATA endButton;
			BUTTON::DATA resultRetryButton;
			BUTTON::DATA resultBackButton;
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
			CURTAIN::DATA curtain;
			TRANSITION::DATA transition;
			COMMAND::DATA command;
			EVOLUTIONARY_CIRCLE::DATA eCircle;
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