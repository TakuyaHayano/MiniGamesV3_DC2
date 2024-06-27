#pragma once
#include <vector>
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09 {
	class ANIM
	{
    public:
        struct MOVE_DATA {
            float animeTime = 0;
            VECTOR2 startPos;
            VECTOR2 endPos;
            float startAlpha = 255;
            float endAlpha = 255;
            float startSize = 1;
            float endSize = 1;
        };
    private:
        float Time = 0;
        int State = 0;
        std::vector<MOVE_DATA> Data;
        bool Start = false;

        VECTOR2 Pos;
        float Alpha;
        float Size;
    public:
        ANIM();
        ~ANIM();
        void update();
        void start();

        VECTOR2 pos() { return Pos; }
        float alpha() { return Alpha; }
        float size() { return Size; }
        bool isStart() { return Start; }
        std::vector<MOVE_DATA>& data() { return Data; }
	};
}
