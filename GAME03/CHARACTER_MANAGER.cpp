#include"GAME03.h"
#include"CONTAINER.h"
#include"CHARACTER.h"
#include"PLAYER.h"
#include "CHARACTER_MANAGER.h"
namespace GAME03 {
	CHARACTER_MANAGER::CHARACTER_MANAGER(class GAME* game) : GAME_OBJECT(game) {
	}
	CHARACTER_MANAGER::~CHARACTER_MANAGER() {
		for (int i = 0; i < Total; i++) {
			delete Characters[i];
		}
		delete[] Characters;
		Player = nullptr;
	}
	void CHARACTER_MANAGER::init() {
		for (int i = 0; i < Total; i++) {
			Characters[i]->init();
		}
	}
	void CHARACTER_MANAGER::create() {
		CharaMng = game()->container()->data().charaMng;

		Total = 0;
		Total += CharaMng.numPlayers;
		Characters = new CHARACTER * [Total];

		Player = new PLAYER(game());
		int i, j = 0;
		for (i = 0; i < CharaMng.numPlayers; i++)Characters[j++] = Player;
		for (int k = 0; k < Total; k++) {
			Characters[k]->create();
		}
	}
	void CHARACTER_MANAGER::appear(char charaId, float wx, float wy, float vx, float vy) {
		for (int i = 0; i < Total; i++) {
			if (Characters[i]->charaId() == charaId) {
				if (Characters[i]->hp() <= 0) {
					Characters[i]->appear(wx, wy, vx, vy);
					break;
				}
			}
		}
	}
	void CHARACTER_MANAGER::update() {
		for (int i = 0; i < Total; i++) {
			if (Characters[i]->hp() > 0) {
				Characters[i]->update();
			}
		}
		for (int i = 0; i < Total - 1; i++) {
			if (Characters[i]->hp() == 0) {
				continue;
			}
			for (int j = i + 1; j < Total; j++) {
				if (Characters[j]->hp() == 0) {
					continue;
				}
			}
		}
	}
	void CHARACTER_MANAGER::draw() {
		for (int i = 0; i < Total; i++) {
			if (Characters[i]->hp() > 0) {
				Characters[i]->draw();
			}
		}
	}
}
