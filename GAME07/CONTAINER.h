#pragma once
#include "TITLE.h"
#include "PLAY.h"
#include <TIME.h>
class CONTAINER
{
	struct DATA {
		TITLE::DATA title;
		PLAY::DATA play;
	};
	DATA Data;
public:
	int k = 0;
	int l = 0;
	int tmp = 0;
public:
	void load();
	void setData();
	void loadGraphic();
	void init();
	const TITLE::DATA& title() { return Data.title; }
	const PLAY::DATA& play() { return Data.play; }
};