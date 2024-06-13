#include "ANIM.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/mathUtil.h"

namespace GAME09
{
	ANIM::ANIM()
	{
	}
	ANIM::~ANIM()
	{
	}
	void ANIM::update()
	{
		if (!Start)return;
		Time += delta;
		while (Time > Data[State].animeTime) {
			Time -= Data[State].animeTime;
			State++;
			if (State >= Data.size()) {
				Start = false;
				return;
			}
		}
		float ratio = Time / Data[State].animeTime;
		ratio = (Cos(ratio * 180) - 1) / -2.0f;
		
		Pos = Data[State].startPos * (1 - ratio) + Data[State].endPos * ratio;
		Alpha = Data[State].startAlpha * (1 - ratio) + Data[State].endAlpha * ratio;
		Size = Data[State].startSize * (1 - ratio) + Data[State].endSize * ratio;
	}
	void ANIM::start()
	{
		Start = true;
		Time = 0;
		State = 0;
	}
}