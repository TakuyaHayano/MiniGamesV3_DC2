#pragma once
class GAME_OBJECT
{
private:
	class GAME_M* Game = 0;    //GAMEクラスのポインタ
public:
	GAME_OBJECT(class GAME_M* game);
	virtual ~GAME_OBJECT();    //基底クラスのデストラクタはvirtualをつける
	class GAME_M* game(){    //ゲッターというGameのポインタをゲットするためだけの関数
		return Game;
	}
};