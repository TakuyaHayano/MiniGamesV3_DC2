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
		Data.title.titlePos = VECTOR2(width / 2, height / 2);
		Data.title.imgSize = 1;

		Data.backG.imgSize = 1.0f;
		Data.backG.pos = VECTOR2(width / 2, height / 2);

		Data.startButton.pos = VECTOR2(960, 540);
		Data.helpButton.pos = VECTOR2(960, 740);
		Data.endButton.pos = VECTOR2(960, 940);
	}
	void CONTAINER::loadGraphic() {
		Data.title.titleImg = loadImage("..\\main\\assets\\game09\\title.png");
		Data.backG.img = loadImage("..\\main\\assets\\game09\\back_ground.png");
		Data.startButton.selectedImg = loadImage("..\\main\\assets\\game09\\start_button.png");
		Data.startButton.notSelectedImg = loadImage("..\\main\\assets\\game09\\start_button_gray.png");
		Data.helpButton.selectedImg = loadImage("..\\main\\assets\\game09\\help_button.png");
		Data.helpButton.notSelectedImg = loadImage("..\\main\\assets\\game09\\help_button_gray.png");
		Data.endButton.selectedImg = loadImage("..\\main\\assets\\game09\\end_button.png");
		Data.endButton.notSelectedImg = loadImage("..\\main\\assets\\game09\\end_button_gray.png");
	}
}