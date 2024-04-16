#pragma once
#include "../MAIN/GAME_BASE.h"
namespace GAME01
{
	class GAME :
		public GAME_BASE
	{
	public:
		GAME(class MAIN* main) :GAME_BASE(main) {};
		~GAME() {};
		int create();
		void proc();
		void destroy();
	private:
		enum STATE { TITLE, PLAY, CLEAR, OVER };
		STATE State = TITLE;
		void Title();
		void Init();
		void Play();
		void Clear();
		bool ClearFlag = false;

	};
}
