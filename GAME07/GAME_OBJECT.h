#pragma once
class GAME_OBJECT
{
private:
	class GAME_M* Game = 0;    //GAME�N���X�̃|�C���^
public:
	GAME_OBJECT(class GAME_M* game);
	virtual ~GAME_OBJECT();    //���N���X�̃f�X�g���N�^��virtual������
	class GAME_M* game(){    //�Q�b�^�[�Ƃ���Game�̃|�C���^���Q�b�g���邽�߂����̊֐�
		return Game;
	}
};