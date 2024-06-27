#include "DRAW_NUM.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "BUBBLE.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/mathUtil.h"
#include <string>

namespace GAME09
{
	DRAW_NUM::DRAW_NUM(GAME* game) :
		GAME_OBJECT(game) {

	}
	DRAW_NUM::~DRAW_NUM() {

	}

	void DRAW_NUM::create() {
		DrawNum = game()->container()->data().drawNum;
	}

	void DRAW_NUM::init() {

	}

	void DRAW_NUM::update() {
		
	}

	void DRAW_NUM::draw(int num, VECTOR2 pos, float ratio) {
		std::string numStr = std::to_string(num);
		int numDigit = numStr.size();
		VECTOR2 cPos = pos;
		cPos.x -= DrawNum.digitSpace * (numDigit - 1) / 2.0f * ratio;
		float size = DrawNum.numSize * ratio;
		for (int i = 0; i < numDigit; i++) {
			int n = (int)numStr[i] - '0';
			image(DrawNum.numImgs[n], cPos.x + DrawNum.digitSpace * i * ratio, cPos.y, 0, size);
		}
	}
}