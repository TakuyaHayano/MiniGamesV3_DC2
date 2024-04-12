#pragma once
#include "TITLE.h"
//#include "TRANSITION.h"
#include "BACKGROUND.h"

namespace GAME09
{
	class CONTAINER
	{
		struct DATA {
			TITLE::DATA title;
			BACKGROUND::DATA backG;
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