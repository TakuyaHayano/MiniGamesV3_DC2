#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
#include "../../libOne/inc/libOne.h"
#include"../MAIN/GAME_BASE.h"
#include "../MAIN/MAIN.h"
#include"GAME03.h"
#include"CONTAINER.h"
#include"FADE.h"
#include "VOLUME.h"
namespace GAME03 {
	void VOLUME::create() {
		Volume = game()->container()->data().volume;
	}
	void VOLUME::init() {
		game()->fade()->inTrigger();
		Volume.select = true;
		Volume.cntVolume = 0;
	}
	void VOLUME::draw() {

		clear(255);
		fill(0);
		textSize(50);
		text("‚a‚f‚l", width / 5.0f, height / 3.0f);
		text("‚r‚d", width / 4.5f, height / 1.6f);

		if (isTrigger(KEY_W)) {
			Volume.select = true;
			Volume.cntVolume = 0;
		}
		if (isTrigger(KEY_S)) {
			Volume.select = false;
			Volume.cntVolume = 0;
		}

		strokeWeight(5.0);
		stroke(100);
		fill(255);

		line(width / 3.5f, height / 3.15f, width / 3.5f + 800.0f, height / 3.15f);
		line(width / 3.5f, height / 1.65f, width / 3.5f + 800.0f, height / 1.65f);

		fill(0);
		text((let)(int)Volume.volume1, width / 1.4f, height / 3.0f);
		text((let)(int)Volume.volume2, width / 1.4f, height / 1.6f);

		if (Volume.select) {
			Volume.cntVolume++;
			if (Volume.cntVolume % 4 == 0) {
				if (Volume.volume1 >= 0 && Volume.volume1 <= 100) {
					if (isPress(KEY_A)) {
						Volume.volume1 += -(3.4f * 60) * delta;
						if (Volume.volume1 < 0) {
							Volume.volume1 = 0;
						}
					}
					if (isPress(KEY_D)) {
						Volume.volume1 += 3.4f * 60 * delta;
						if (Volume.volume1 > 100) {
							Volume.volume1 = 100;
						}

					}
				}
				Volume.cntVolume = 0;
			}
			fill(255);
			circle(width / 3.5f + Volume.volume2 * 8.0f, height / 1.65f, 25.0f);
			fill(255, 0, 0);
			circle(width / 3.5f + Volume.volume1 * 8.0f, height / 3.15f, 25.0f);
		}

		else {
			Volume.cntVolume++;
			if (Volume.cntVolume % 4 == 0) {
				if (Volume.volume2 >= 0 && Volume.volume2 <= 100) {
					if (isPress(KEY_A)) {
						Volume.volume2 += -(3.4f * 60) * delta;
						if (Volume.volume2 < 0) {
							Volume.volume2 = 0;
						}
					}
					if (isPress(KEY_D)) {
						Volume.volume2 += 3.4f * 60 * delta;
						if (Volume.volume2 > 100) {
							Volume.volume2 = 100;
						}
					}
				}
				Volume.cntVolume = 0;
			}
			fill(255);
			circle(width / 3.5f + Volume.volume1 * 8.0f, height / 3.15f, 25.0f);
			fill(255, 0, 0);
			circle(width / 3.5f + Volume.volume2 * 8.0f, height / 1.65f, 25.0f);
		}

		fill(0);
		text("‰ŠúÝ’è", width / 2.2f, height / 1.1f);

		if (isPress(KEY_SPACE)) {
			fill(255, 0, 0);
			text("‰ŠúÝ’è", width / 2.2f, height / 1.1f);
			Volume.volume1 = 80;
			Volume.volume2 = 80;
		}

		setVolume(Volume.Snd_A, -(100 - (int)Volume.volume1) * (100 - (int)Volume.volume1));
		setVolume(Volume.Se_A, -(100 - (int)Volume.volume2) * (100 - (int)Volume.volume2));
		setVolume(Volume.Se_B, -(100 - (int)Volume.volume2) * (100 - (int)Volume.volume2));
		setVolume(Volume.Se_C, -(100 - (int)Volume.volume2) * (100 - (int)Volume.volume2));

		fill(0);
		textSize(40);
		text("EnterƒL[‚Åƒ^ƒCƒgƒ‹‚É–ß‚é", width / 1.5f, height / 1.00625f);
		game()->fade()->draw();
	}
	void VOLUME::BackGround() {
		clear();
		rectMode(CORNER);
		imageColor(Volume.backColor);
		image(Volume.backImg, 0, 0);
	}
	void VOLUME::nextScene() {
		if (isTrigger(KEY_ENTER)) {
			game()->fade()->outTrigger();
		}
		if (game()->fade()->outEndFlag()) {
			game()->setCurScene(game()->title());
		}
	}
}