#pragma once
#include"../../libOne/inc/COLOR.h"
#include"../../libOne/inc/VECTOR2.h"
#include"GAME_OBJECT.h"
namespace GAME14 {
	class JUMP_POW:
		public GAME_OBJECT
	{
		enum DIRECTION {
			X_DIRECTION,
			Y_DIRECTION
		};
	public:
		struct DATA {
			//�Q�[�W
			float gaugeSizeH;
			float gaugeSizeW;
			COLOR gaugeColor;
			COLOR curGaugeColor;

			//�Q�[�W�̈ʒu
			float offsetX;
			float offsetY;

			//������
			COLOR yardstickColor;
			float yardstickSize;
			int numEqual;
			//�p���[
			float curPowX = 0;
			float curPowY = 0;
			float powSpeed;
			float limitPow;

			float curTime = 0;
			float startDirectionTime;
			bool endFlag = false;
		};
	private:
		DATA JumpPow;
		DIRECTION CurState = X_DIRECTION;
	public:
		JUMP_POW(class GAME* game);
		~JUMP_POW();
		void create();
		void init();
		void draw(VECTOR2 playerPos,float offsetRight,float vecX);
		void update();
		bool endDirection() { return JumpPow.endFlag; }
		float curPowX() { return JumpPow.curPowX; }
		float curPowY() { return JumpPow.curPowY; }
	};
}

