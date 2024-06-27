#include"GAME14.h"
#include"CONTAINER.h"
#include"MAP.h"
#include"CHARACTER_MANAGER.h"
#include "STAGE.h"
namespace GAME14 {
	STAGE::STAGE(class GAME* game):
		SCENE(game){}
	STAGE::~STAGE(){}
	void STAGE::create(){
		Stage = game()->container()->data().stage;
	}
	void STAGE::init(){
		game()->map()->init();
		game()->characterManager()->init();
	}
	void STAGE::update(){
		if (isTrigger(KEY_R)) init();
		game()->map()->update();
		game()->characterManager()->update();
		game()->map()->timeCunt();
	}
	void STAGE::draw(){
		clear(255);
		game()->map()->draw();
		fill(103, 237, 255);
		rect(0, 0, game()->map()->ofset(), height);
		rect(game()->map()->worldWidht() + game()->map()->ofset(), 0, game()->map()->ofset(), height);
		game()->characterManager()->draw();
		fill(Stage.undercoatColor);
		rect(Stage.undercoatPos.x, Stage.undercoatPos.y, Stage.undercoatSize.x, Stage.undercoatSize.y);
		image(Stage.img, Stage.imgPos.x,Stage.imgPos.y, 0, Stage.imgSize);
		fill(Stage.textColor);
		textSize(Stage.textSize);
		int numSalmon = game()->characterManager()->player()->stacSalmon();
		text("~", Stage.imgPos.x+50, Stage.imgPos.y+Stage.textSize);
		text(numSalmon,Stage.salmonText.x - (Stage.textSize * (numSalmon / 10)) / 2, Stage.salmonText.y);
		if (game()->characterManager()->player()->clearFlag()) {
			fill(0,0,0,80);
			rect(game()->map()->ofset(), Stage.str1Pos.y - Stage.str1Size , game()->map()->worldWidht(), Stage.str1Size + Stage.str2Size+20);
			fill(Stage.strColor);
			textSize(Stage.str1Size);
			text(Stage.str1P, Stage.str1Pos.x, Stage.str1Pos.y);
			textSize(Stage.str2Size);
			text(Stage.str2P, Stage.str2Pos.x, Stage.str2Pos.y);

		}
	}
	void STAGE::nextScene(){
		if (isTrigger(KEY_Z)||(game()->characterManager()->player()->clearFlag()&&isTrigger(MOUSE_LBUTTON)))
			game()->changeScene(GAME::TITLE_ID);

	}
}