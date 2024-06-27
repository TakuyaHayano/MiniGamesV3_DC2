#pragma once
class GAME_M{
//コンテナ
private:
	class CONTAINER* Container;
public:
	class CONTAINER* container() { return Container; }
//シーン
public:
	enum SCENE_ID {
		TITLE_ID, 
		STAGE_ID, 
		GAME_CLEAR_ID, 
		GAME_OVER_ID, 
		NUM_SCENES
	};
private:
	class SCENE* Scenes[NUM_SCENES];
	SCENE_ID CurSceneId;    //現在のシーンを判別するために列挙型を用意する
public:
	void changeScene(SCENE_ID sceneId);
//プレイ
private:
	class PLAY* Play;
public:
	class PLAY* play() { return Play; }
public:
	GAME_M();
	~GAME_M();
	void run();    //実行しろという関数
};