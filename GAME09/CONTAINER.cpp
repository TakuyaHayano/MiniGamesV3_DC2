#include "CONTAINER.h"
#include <string.h>
#include "../../libOne/inc/graphic.h"

namespace GAME09
{
	void CONTAINER::load() {
		setData();
		loadGraphic();
	}
	void CONTAINER::setData() {
		Data.backG.imgSize = 1.0f;
		Data.backG.pos = VECTOR2(width / 2, height / 2);
	}
	void CONTAINER::loadGraphic() {
		Data.backG.img = loadImage("..\\main\\assets\\game09\\back_ground.jpg");
	}
}