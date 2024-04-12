#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "CONTAINER.h"
#include "GAME09.h"
#include "TITLE.h"

namespace GAME09
{
	TITLE::TITLE(class GAME* game) :
		SCENE(game) {

	}
	TITLE::~TITLE() {

	}
	void TITLE::create() {
		Title = game()->container()->data().title;
	}
	void TITLE::draw() {
		fill(0);
		print("スイカゲーム");
	}
	void TITLE::nextScene() {

	}
}