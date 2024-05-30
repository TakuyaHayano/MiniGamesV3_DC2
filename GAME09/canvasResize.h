#pragma once
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/VECTOR2.h"

static VECTOR2 cornerPos(0,0);
static float magnification = 0.5f;

inline void drawCanvas(int idx, float x, float y, float angle = 0, float size = 1) {
	float X = cornerPos.x + x * magnification;
	float Y = cornerPos.y + y * magnification;
	float Size = size * magnification;
	image(idx, X, Y, angle, Size);
}

inline void setCornerPos(VECTOR2 pos) {
	cornerPos = pos;
}
inline void setMagnification(float value) {
	magnification = value;
}

#define image drawCanvas