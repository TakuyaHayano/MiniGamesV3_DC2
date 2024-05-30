#pragma once
#include"GAME_OBJECT.h"
#include"../../libOne/inc/COLOR.h"
#include"ANIMS.h"
namespace GAME03 {
	class CHARACTER : public GAME_OBJECT {
	public:
		struct DATA {
			class ANIMS* anims = nullptr;
			int animId = 0;
			class ANIM* anim = nullptr;
			ANIM_DATA animData;
			int img = 0;
			int shadowImg = 0;
			COLOR color;
			char charaId = 0;
			float wx = 0;
			float wy = 0;
			float vx = 0;
			float vy = 0;
			float speed = 0;
			float angle = 0;
			float scale = 1;
			int hp = 0;
			float offsetLeft = 0;
			float offsetTop = 0;
			float offsetRight = 0;
			float offsetBottom = 0;
		};
	protected:
		DATA Chara;
	public:
		CHARACTER(class GAME* game);
		virtual void create();
		virtual void init();
		virtual void appear(float wx, float ey, float vx, float vy);
		virtual void update();
		virtual void draw();
		int hp() { return Chara.hp; }
		char charaId() { return Chara.charaId; }
		float wLeft() { return Chara.wx + Chara.offsetLeft; }
		float wTop() { return Chara.wy + Chara.offsetTop; }
		float wRight() { return Chara.wx + Chara.offsetRight; }
		float wBottom() { return Chara.wy + Chara.offsetBottom; }
		void setImgidx(int i) { Chara.animData.imgIdx = i; }
	};
};

