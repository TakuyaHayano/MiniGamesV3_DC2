#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME10.h"
namespace GAME10
{
	int GAME::create()
	{
		STATE = TITLE;
		//file�X�L����
		fileName = "..\\main\\assets\\game10\\map.txt";
		wallImg = loadImage("..\\main\\assets\\game10\\wall.png");
		goalImg = loadImage("..\\main\\assets\\game10\\goal.png");
		fopen_s(&fp, fileName, "rb");
		fseek(fp,0,SEEK_END);
		fileSize = ftell(fp);
		fseek(fp, 0, SEEK_SET);

		map = new char[fileSize];
		fread(map,sizeof(char),fileSize,fp);

		//�s��̌v�Z
		for (int i = 0; i < fileSize; i++) {
			cnt++;
			if (map[i] == 'g') {
				goalCnt++;
			}
			if (map[i] == 'a') {
				wallCnt++;
			}
			if (map[i] == '\n') {
				if (row == 0) {
					col = cnt;
				}
				row++;
			}
		}

		//�ǁEgoal�̓��I�m��
		Wall = new wall[wallCnt];
		Goal = new wall[goalCnt];

		//�z��̐���}�����邽�߂̐�
		int Wcnt = 0;
		int Gcnt = 0;
		//�v���C���[�ƓG�̏����ʒu�ݒ�E�ǂ̏��̕ۑ�
		for (int c = 0; c < col; c++) {
			Wmap.px = Wmap.worldX + c * Wmap.Xsize;
			for (int r = 0; r < row; r++) {
				Wmap.py = Wmap.worldY + r * Wmap.Ysize;
				Wmap.mIdx = r * col + c;
				//��
				if (map[Wmap.mIdx] == 'a') {
					Wall[Wcnt].WaPx = Wmap.px;//���ۂɂ̓I�[�o�[�������Ă��Ȃ�
					Wall[Wcnt].WaPy = Wmap.py;
					Wcnt++;
				}
				//�S�[��
				if (map[Wmap.mIdx] == 'g') {
					Goal[Gcnt].WaPx = Wmap.px;//���ۂɂ̓I�[�o�[�������Ă��Ȃ�
					Goal[Gcnt].WaPy = Wmap.py;
					Gcnt++;
				}
				//�v���C���[
				if (map[Wmap.mIdx] == 'p') {
					player.Cpx = Wmap.px + Wmap.XharfSize;
					player.Cpy = Wmap.py + Wmap.YharfSize;
				}
			}
		}

		fclose(fp);

		//�����\���ʒu���v���C���[�ɕύX
		while (player.Cpy + Wmap.worldY > height) {
			Wmap.worldY -= height;
		}
		player.Cpy += Wmap.worldY;
		return 0;
	}

	void GAME::destroy()
	{
		delete map;
		delete Wall;
		delete Goal;
	}

	void GAME::proc()
	{	
		if (STATE == TITLE) { title(); }
		else if (STATE == PLAY) { play(); }
		else if (STATE == RESULT) { result(); }

	}

	void GAME::title() {
		clear(0);
		text("ENTER�L�[�Ń��j���[�ɖ߂�", 0, 1080);
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
		if (isTrigger(KEY_K)) {
 			STATE = PLAY;
		}
	}

	void GAME::play() {
		draw();
		move();
		collision();
		stageChange();
	}

	void GAME::result() {
		clear(0);
		if (isTrigger(KEY_SPACE)) {
			STATE = TITLE;
		}
	}

	void GAME::move() {
		if (isPress(KEY_D)) {
			player.Cpx += player.Mx;
		}
		if (isPress(KEY_A)) {
			player.Cpx -= player.Mx;
		}
		if (isPress(KEY_S)) {
			player.Cpy += player.My;
		}
		if (isPress(KEY_W)) {
			player.Cpy -= player.My;
		}
	}

	void GAME::stageChange() {
		if (player.Cpx > width) {
			clear(0);
			Wmap.worldX -= width;
			player.Cpx = Wmap.YharfSize;
		}
		if (player.Cpx < 0) {
			clear(0);
			Wmap.worldX += width;
			player.Cpx = width - Wmap.YharfSize;
		}

		if (player.Cpy > height) {
			clear(0);
			Wmap.worldY -= height;
			player.Cpy = Wmap.YharfSize;
		}
		if (player.Cpy < 0) {
			clear(0);
			Wmap.worldY += height;
			player.Cpy = height;
		}
	}

	void GAME::collision() {
		//�ǂ̓����蔻��

		for (int w = 0; w < wallCnt; w++) {
			if (Wall[w].WaPx + Wmap.worldX >= -Wmap.Xsize
				&& Wall[w].WaPx + Wmap.worldX < width + Wmap.Xsize 
				&& Wall[w].WaPy + Wmap.worldY >= -Wmap.Ysize
				&& Wall[w].WaPy + Wmap.worldY < height + Wmap.Ysize) {
				hitbox(w);
				switch (HitBox.PointFlag) {
				case HitBox.Up://�ǂ��猩�ď㑤�̔���
					if (HitBox.Wup.y <= HitBox.Punder.y
						&& HitBox.Wunder.y >= HitBox.Punder.y
						&& HitBox.Wright.x >= HitBox.Pleft.x
						&& HitBox.Wleft.x <= HitBox.Pright.x) {
						player.Cpy -= player.My;
					}
				break;
				case HitBox.Under://�ǂ��猩�ĉ����̔���
					if (HitBox.Wunder.y >= HitBox.Pup.y
						&& HitBox.Wup.y <= HitBox.Pup.y
						&& HitBox.Wright.x >= HitBox.Pleft.x
						&& HitBox.Wleft.x <= HitBox.Pright.x) {
						player.Cpy += player.My;
					}
				break;
				case HitBox.Left://�ǂ��猩�č����̔���
					if (HitBox.Wleft.x <= HitBox.Pright.x
						&& HitBox.Wright.x >= HitBox.Pright.x
						&& HitBox.Wup.y <= HitBox.Punder.y
						&& HitBox.Wunder.y >= HitBox.Pup.y) {
						player.Cpx -= player.Mx;
					}
				break;
				case HitBox.Right://�ǂ��猩�ĉE���̔���
					if (HitBox.Wleft.x <= HitBox.Pleft.x
						&& HitBox.Wright.x >= HitBox.Pleft.x
						&& HitBox.Wup.y <= HitBox.Punder.y
						&& HitBox.Wunder.y >= HitBox.Pup.y) {
						player.Cpx += player.Mx;
					}
				break;
				}
			}

		}
		for (int g = 0; g < goalCnt; g++) {
			if (Goal[g].WaPx + Wmap.worldX >= 0
				&& Goal[g].WaPx + Wmap.worldX < width
				&& Goal[g].WaPy + Wmap.worldY >= 0
				&& Goal[g].WaPy + Wmap.worldY < height) { 
				playerHitBox();
				if (HitBox.Punder.y >= Goal[g].WaPy + Wmap.worldY
					&& HitBox.Punder.y <= Goal[g].WaPy + Wmap.worldY + Wmap.Ysize
					&& HitBox.Pleft.x <= Goal[g].WaPx + Wmap.worldX + Wmap.Xsize
					&& HitBox.Pright.x >= Goal[g].WaPx + Wmap.worldX) {
					STATE = RESULT;
				}
			}
		}
	}

	void GAME::hitbox(int w) {

		//�ǂ̃R�A
		HitBox.Wcore.x = Wall[w].WaPx + Wmap.XharfSize + Wmap.worldX;
		HitBox.Wcore.y = Wall[w].WaPy + Wmap.YharfSize + Wmap.worldY;
		//�ǂ̏㉺���E�̓����蔻��
		HitBox.Wup.x = Wall[w].WaPx + Wmap.worldX;
		HitBox.Wup.y = Wall[w].WaPy + Wmap.worldY;

		HitBox.Wunder.x = Wall[w].WaPx + Wmap.worldX;
		HitBox.Wunder.y = Wall[w].WaPy + Wall[w].Ysize + Wmap.worldY;

		HitBox.Wleft.x = Wall[w].WaPx + Wmap.worldX;
		HitBox.Wleft.y = Wall[w].WaPy + Wmap.worldY;

		HitBox.Wright.x = Wall[w].WaPx + Wall[w].Xsize + Wmap.worldX;
		HitBox.Wright.y = Wall[w].WaPy + Wmap.worldY;
		playerHitBox();
		HitBox.UpDist = Sqrt(Abs((HitBox.Wcore.x - HitBox.Punder.x) * (HitBox.Wcore.x - HitBox.Punder.x)) + Abs((HitBox.Wcore.y - HitBox.Punder.y) * (HitBox.Wcore.y - HitBox.Punder.y)));
		HitBox.UnderDist = Sqrt(Abs((HitBox.Wcore.x - HitBox.Pup.x) * (HitBox.Wcore.x - HitBox.Pup.x)) + Abs((HitBox.Wcore.y - HitBox.Pup.y) * (HitBox.Wcore.y - HitBox.Pup.y)));
		HitBox.LeftDist = Sqrt(Abs((HitBox.Wcore.x - HitBox.Pright.x) * (HitBox.Wcore.x - HitBox.Pright.x)) + Abs((HitBox.Wcore.y - HitBox.Pright.y) * (HitBox.Wcore.y - HitBox.Pright.y)));
		HitBox.RightDist = Sqrt(Abs((HitBox.Wcore.x - HitBox.Pleft.x) * (HitBox.Wcore.x - HitBox.Pleft.x)) + Abs((HitBox.Wcore.y - HitBox.Pleft.y) * (HitBox.Wcore.y - HitBox.Pleft.y)));
		if (HitBox.UpDist < HitBox.LeftDist && HitBox.UpDist < HitBox.RightDist && HitBox.UpDist < HitBox.UnderDist) {
			HitBox.PointFlag = HitBox.Up;
		}
		else if (HitBox.UnderDist < HitBox.UpDist && HitBox.UnderDist < HitBox.RightDist && HitBox.UnderDist < HitBox.LeftDist) {
			HitBox.PointFlag = HitBox.Under;
		}
		else if (HitBox.LeftDist < HitBox.UpDist && HitBox.LeftDist < HitBox.RightDist && HitBox.LeftDist < HitBox.UnderDist) {
			HitBox.PointFlag = HitBox.Left;
		}
		else if (HitBox.RightDist < HitBox.UpDist && HitBox.RightDist < HitBox.LeftDist && HitBox.RightDist < HitBox.UnderDist) {
			HitBox.PointFlag = HitBox.Right;
		}
	}

	void GAME::playerHitBox() {
		//�v���C���[�̏㉺���E�̓����蔻��
		HitBox.Pup.x = player.Cpx;
		HitBox.Pup.y = player.Cpy - player.Hradius;

		HitBox.Punder.x = player.Cpx;
		HitBox.Punder.y = player.Cpy + player.Hradius;

		HitBox.Pleft.x = player.Cpx - player.Hradius;
		HitBox.Pleft.y = player.Cpy;

		HitBox.Pright.x = player.Cpx + player.Hradius;
		HitBox.Pright.y = player.Cpy;
	}

	void GAME::draw() {
		rectMode(CORNER);
		clear(255);
		text(Wmap.worldY,600,700);
		text(player.Cpx, 600, 800);
		text(player.Cpy, 600, 900);
		//���ꂼ��̍��W�ɃC���[�W����������ł��邾��
		for (int c = 0; c < col; c++) {
			Wmap.px = Wmap.worldX + c * Wmap.Xsize;
			for (int r = 0; r < row; r++) {
				Wmap.py = Wmap.worldY + r * Wmap.Ysize;
				Wmap.mIdx = r * col + c;
				if (map[Wmap.mIdx] == 'a') {
					image(wallImg, Wmap.px, Wmap.py);
				}
				if (map[Wmap.mIdx] == 'g') {
					image(goalImg, Wmap.px, Wmap.py);
				}
			}
		}
		fill(0);
		circle(player.Cpx, player.Cpy, player.radius);
	}
}
