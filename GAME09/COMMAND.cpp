#include "COMMAND.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/input.h"
#include <string>

namespace GAME09
{
	COMMAND::COMMAND(GAME* game) :
		GAME_OBJECT(game) {

	}
	COMMAND::~COMMAND() {

	}

	void COMMAND::create() {
		Command = game()->container()->data().command;
		CommandLen = Command.command.size();
	}

	void COMMAND::init() {
		Inputs.clear();
		for (int i = 0; i < CommandLen; i++) {
			Inputs.emplace_back(KEY_NONE);
		}
		Complete = false;
	}

	void COMMAND::update() {
		if (Complete) return;
		for (int i = (int)KEY_A; i < (int)KEY_SPACE; i++) {
			if (isTrigger((INPUT_CODE)i)) {
				Inputs.erase(Inputs.begin());
				Inputs.emplace_back((INPUT_CODE)i);
			}
		}
		Complete = true;
		for (int i = 0; i < CommandLen; i++) {
			if (Command.command[i] != Inputs[i]) {
				Complete = false;
				break;
			}
		}
	}

	void COMMAND::draw() {
		//if (Complete) {
		//	fill(255, 0, 0);
		//}
		//else {
		//	fill(0);
		//}
		//for (int i = 0; i < CommandLen; i++) {
		//	std::string temp = ButtonName[Command.command[i]];
		//	temp += ButtonName[Inputs[i]];
		//	print(temp.c_str());
		//}
	}
}