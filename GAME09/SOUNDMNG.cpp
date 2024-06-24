#include "SOUNDMNG.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/sound.h"

namespace GAME09
{
	SOUNDMNG::SOUNDMNG(GAME* game) :
		GAME_OBJECT(game) {

	}
	SOUNDMNG::~SOUNDMNG() {

	}

	void SOUNDMNG::create() {
		SoundMNG = game()->container()->data().soundMNG;
	}

	void SOUNDMNG::playSE(SOUND_EFFECT id) {
		playSound(SoundMNG.soundEffects[id]);
	}
}