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
		enum STATE { TITLE,RULE, PLAY, CLEAR, OVER };
		STATE State = TITLE;
		void Title();
		void Rule();
		void Init();
		void Play();
		void Clear();
		void Over();

	
		bool ClearFlag = false;
		bool OverFlag = false;

		float CR = 0;
		float CX = 0, CY = 0;
		float CVx = 0, CVy = 0;

		int score;
		int level = 0;
		int nextLevelScore = 0;
		float timer = 0;

		char scoreText[50];
		char levelText[32];
		char timerText[32];
		//‰æ‘œ
		int bonImg = 0;
		int haikeiImg = 0;
		int clearImg = 0;
		int overImg = 0;
		//ƒTƒEƒ“ƒh
		int gekihaSnd = 0;
		int playSnd = 0;
		int clearSnd = 0;
		int overSnd = 0;
		int bgmSnd = 0;


	};
}
