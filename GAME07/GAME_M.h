#pragma once
class GAME_M{
//�R���e�i
private:
	class CONTAINER* Container;
public:
	class CONTAINER* container() { return Container; }
//�V�[��
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
	SCENE_ID CurSceneId;    //���݂̃V�[���𔻕ʂ��邽�߂ɗ񋓌^��p�ӂ���
public:
	void changeScene(SCENE_ID sceneId);
//�v���C
private:
	class PLAY* Play;
public:
	class PLAY* play() { return Play; }
public:
	GAME_M();
	~GAME_M();
	void run();    //���s����Ƃ����֐�
};