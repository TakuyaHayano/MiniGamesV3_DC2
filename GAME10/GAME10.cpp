#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME10.h"
namespace GAME10
{
	int GAME::create()
	{
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
			Wmap.px = Wmap.worldX + c * Wmap.size;
			for (int r = 0; r < row; r++) {
				Wmap.py = Wmap.worldY + r * Wmap.size;
				Wmap.mIdx = r * col + c;
				if (map[Wmap.mIdx] == 'a') {
					Wall[Wcnt].WaPx = Wmap.px;
					Wall[Wcnt].WaPy = Wmap.py;
					Wcnt++;
				}
				if (map[Wmap.mIdx] == 'g') {
					Goal[Gcnt].WaPx = Wmap.px;
					Goal[Gcnt].WaPy = Wmap.py;
					Gcnt++;
				}
				if (map[Wmap.mIdx] == 'p') {
					player.Cpx = Wmap.px + 100;
					player.Cpy = Wmap.py + 100;
				}
			}
		}

		fclose(fp);


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
		draw();
		move();
		stageChange();
		text("ENTER�L�[�Ń��j���[�ɖ߂�", 0, 1080);
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
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
			player.Cpx = Wmap.harfSize;
		}
		else if (player.Cpx < 0) {
			clear(0);
			Wmap.worldX += width;
			player.Cpx = width - Wmap.harfSize;
		}

		if (player.Cpy > height) {
			clear(0);
			Wmap.worldY -= height;
			player.Cpy += Wmap.harfSize;
		}
		else if (player.Cpy < 0) {
			clear(0);
			Wmap.worldY += height;
			player.Cpy = height;
		}
	}

	void GAME::collision() {
		for (int w = 0; w < wallCnt; w++) {
		}
		for (int g = 0; g < goalCnt; g++) {
		}
	}

	void GAME::draw() {
		rectMode(CORNER);
		clear(255);
		text(player.Cpx,600,700);
		//�����A���ꂼ��̍��W�ɃC���[�W����������ł��邾��
		for (int c = 0; c < col; c++) {
			Wmap.px = Wmap.worldX + c * Wmap.size;
			for (int r = 0; r < row; r++) {
				Wmap.py = Wmap.worldY + r * Wmap.size;
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
