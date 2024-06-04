#include "canvasResize.h"

#undef image
#undef line

namespace GAME09 {
	VECTOR2 cornerPos = VECTOR2(0, 0);
	float magnification = 1.0f;

	void drawCanvasImage(int idx, float x, float y, float angle, float size) {
		float X = cornerPos.x + x * magnification;
		float Y = cornerPos.y + y * magnification;
		float Size = size * magnification;
		image(idx, X, Y, angle, Size);
	}

	void drawCanvasLine(float sx, float sy, float ex, float ey) {

		float Sx = cornerPos.x + sx * magnification;
		float Sy = cornerPos.y + sy * magnification;
		float Ex = cornerPos.x + ex * magnification;
		float Ey = cornerPos.y + ey * magnification;
		line(Sx, Sy, Ex, Ey);
	}

	void setCornerPos(VECTOR2 pos) {
		cornerPos = pos;
	}
	void addCornerPos(VECTOR2 ofst) {
		cornerPos += ofst;
	}
	void setMagnification(float value) {
		magnification = value;
	}
}

#define image drawCanvasImage
#define line drawCanvasLine