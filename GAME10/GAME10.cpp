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
		WallImg = loadImage("..\\main\\assets\\game10\\wall.png");
		goalImg = loadImage("..\\main\\assets\\game10\\goal.png");
		WallUpImg = loadImage("..\\main\\assets\\game10\\up.png");
		WallUnderImg = loadImage("..\\main\\assets\\game10\\under.png");
		WallRightImg = loadImage("..\\main\\assets\\game10\\right.png");
		WallLeftImg = loadImage("..\\main\\assets\\game10\\left.png");
		WallUpLeftCornerImg = loadImage("..\\main\\assets\\game10\\upLeftCorner.png");
		WallUnderLeftCornerImg = loadImage("..\\main\\assets\\game10\\underLeftCorner.png");
		WallUpRightCornerImg = loadImage("..\\main\\assets\\game10\\upRightCorner.png");
		WallUnderRightCornerImg = loadImage("..\\main\\assets\\game10\\underRightCorner.png");
		fopen_s(&fp, fileName, "rb");
		fseek(fp,0,SEEK_END);
		fileSize = ftell(fp);
		fseek(fp, 0, SEEK_SET);

		map = new char[fileSize];
		fread(map,sizeof(char),fileSize,fp);

		fclose(fp);

		//�s��̌v�Z�E�}�b�v�̋L���̐�
		for (int i = 0; i < fileSize; i++) {
			cnt++;
			if (map[i] == 'g') {
				GoalCnt ++;
			}
			else if (map[i] == 'a') {
				WallCnt++;
			}
			else if (map[i] == '1') {
				InvisibleWallCnt++;
			}
			else if (map[i] == '2') {
				InvisibleWallCnt++;
			}
			else if (map[i] == '3') {
				InvisibleWallCnt++;
			}
			else if (map[i] == '4') {
				InvisibleWallCnt++;
			}
			else if (map[i] == '5') {
				InvisibleWallCnt++;
			}
			else if (map[i] == '6') {
				InvisibleWallCnt++;
			}
			else if (map[i] == '7') {
				InvisibleWallCnt++;
			}
			else if (map[i] == '8') {
				InvisibleWallCnt++;
			}
			else if (map[i] == 's' || map[i] == 'h' || map[i] == 'e') {
				EnemyCnt++;
			}
			else if (map[i] == '\n') {
				if (row == 0) {
					col = cnt;
				}
				row++;
			}
		}

		//�ǁEgoal�E�����Ȃ��ǁE�G�̓��I�m��
		Wall = new wall[WallCnt];
		WallCorner = new wall[InvisibleWallCnt];
		Goal = new wall[GoalCnt ];
		Enemys = new character[EnemyCnt];
		return 0;
	}

	void GAME::destroy()
	{
		delete[] map;
		delete[] Wall;
		delete[] WallCorner;
		delete[] Goal;
		delete[] Enemys;
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
			init();
 			STATE = PLAY;
		}
	}

	void GAME::init() {
		//�z��̐���}�����邽�߂̐�
		int Wcnt = 0;
		int Gcnt = 0;
		int WCcnt = 0;
		Wmap.worldX = 0;
		Wmap.worldY = 0;
		Ecnt = 0;
		//�v���C���[�ƓG�̏����ʒu�ݒ�E�ǂ̏��̕ۑ�
		for (int c = 0; c < col; c++) {
			Wmap.px = c * Wmap.Xsize;
			for (int r = 0; r < row; r++) {
				Wmap.py =r * Wmap.Ysize;
				Wmap.mIdx = r * col + c;
				//��
				if (map[Wmap.mIdx] == 'a') {
					Wall[Wcnt].WaPx = Wmap.px;//���ۂɂ̓I�[�o�[�������Ă��Ȃ�
					Wall[Wcnt].WaPy = Wmap.py;
					Wcnt++;
				}
				else if (map[Wmap.mIdx] == '1') {
					WallCorner[WCcnt].WaPx = Wmap.px;
					WallCorner[WCcnt].WaPy = Wmap.py;
					WCcnt++;
				}
				else if (map[Wmap.mIdx] == '2') {
					WallCorner[WCcnt].WaPx = Wmap.px;
					WallCorner[WCcnt].WaPy = Wmap.py;
					WCcnt++;
				}
				else if (map[Wmap.mIdx] == '3') {
					WallCorner[WCcnt].WaPx = Wmap.px;
					WallCorner[WCcnt].WaPy = Wmap.py;
					WCcnt++;
				}
				else if (map[Wmap.mIdx] == '4') {
					WallCorner[WCcnt].WaPx = Wmap.px;
					WallCorner[WCcnt].WaPy = Wmap.py;
					WCcnt++;
				}
				else if (map[Wmap.mIdx] == '5') {
					WallCorner[WCcnt].WaPx = Wmap.px;
					WallCorner[WCcnt].WaPy = Wmap.py;
					WCcnt++;
				}
				else if (map[Wmap.mIdx] == '6') {
					WallCorner[WCcnt].WaPx = Wmap.px;
					WallCorner[WCcnt].WaPy = Wmap.py;
					WCcnt++;
				}
				else if (map[Wmap.mIdx] == '7') {
					WallCorner[WCcnt].WaPx = Wmap.px;
					WallCorner[WCcnt].WaPy = Wmap.py;
					WCcnt++;
				}
				else if (map[Wmap.mIdx] == '8') {
					WallCorner[WCcnt].WaPx = Wmap.px;
					WallCorner[WCcnt].WaPy = Wmap.py;
					WCcnt++;
				}
				//�S�[��
				else if (map[Wmap.mIdx] == 'g') {
					Goal[Gcnt].WaPx = Wmap.px;//���ۂɂ̓I�[�o�[�������Ă��Ȃ�
					Goal[Gcnt].WaPy = Wmap.py;
					Gcnt++;
				}
				//�v���C���[
				else if (map[Wmap.mIdx] == 'p') {
					player.Cpx = Wmap.px + Wmap.XharfSize;
					player.Cpy = Wmap.py + Wmap.YharfSize;
				}
				//�G
				else if (map[Wmap.mIdx] == 's'|| map[Wmap.mIdx] == 'h' || map[Wmap.mIdx] == 'e') {
					Enemys[Ecnt].Cpx = Wmap.px + Wmap.XharfSize;;
					Enemys[Ecnt].Cpy = Wmap.py + Wmap.YharfSize;
					//�����̎�ނ�����
					if (map[Wmap.mIdx] == 's') {
						Enemys[Ecnt].Mkind = RightLeft;
					}
					else if (map[Wmap.mIdx] == 'h'){
						Enemys[Ecnt].Mkind = UpDown;
					}
					else if (map[Wmap.mIdx] == 'e') {
						Enemys[Ecnt].Mkind = NoMove;
						Enemys[Ecnt].View = random() % 4;
					}
					Enemys[Ecnt].Frieze = 0;
					Ecnt++;
				}
				//��
				else if (map[Wmap.mIdx] == 'k') {
					Key.ItemCore.x = Wmap.px + Wmap.XharfSize;
					Key.ItemCore.y = Wmap.py + Wmap.YharfSize;
				}
			}
		}

		//�G�l�~�[�̓��������߂�
		for (int e = 0; e < EnemyCnt; e++) {
			switch (Enemys[e].Mkind)
			{
				case RightLeft:
					if (random() % 2) {
						Enemys[e].Mx *= -1;
						Enemys[e].View = Enemys[e].Left;
					}
					else {
						Enemys[e].View = Enemys[e].Right;
					}
				break;
				case UpDown:
					if (random() % 2) {
						Enemys[e].My *= -1;
						Enemys[e].View = Enemys[e].Under;
					}
					else {
						Enemys[e].View = Enemys[e].Up;
					}
				break;
				case NoMove:
					Enemys[e].View = random() % 4;
				break;
			}
		}
		//�����\���ʒu���v���C���[�ɕύX
		while (player.Cpy + Wmap.worldY > height) {
			Wmap.worldY -= height;
		}
		while (player.Cpx + Wmap.worldX > width) {
			Wmap.worldX -= width;
		}
		player.Cpy += Wmap.worldY;
		player.Cpx += Wmap.worldX;
		//���擾�̏�����
		player.KeyFlag = false;
	}

	void GAME::play() {
		draw();
		Pmove();
		Emove();
		collision();
		stageChange();
	}

	void GAME::result() {
		clear(0);
		if (isTrigger(KEY_SPACE)) {
			STATE = TITLE;
		}
	}

	void GAME::Pmove() {
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

	void GAME::Emove() {
		for (int enemy = 0; enemy < EnemyCnt; enemy++) {
			if (Enemys[enemy].Cpx + Wmap.worldX > 0
				&& Enemys[enemy].Cpx + Wmap.worldX < width
				&& Enemys[enemy].Cpy + Wmap.worldY > 0
				&& Enemys[enemy].Cpy + Wmap.worldY < height) {
				switch (Enemys[enemy].Mkind) {
				case RightLeft:
					if (Enemys[enemy].WallHitFlag == false) {
						Enemys[enemy].Cpx += Enemys[enemy].Mx;
					}
					break;
				case UpDown:
					if (Enemys[enemy].WallHitFlag == false) {
						Enemys[enemy].Cpy += Enemys[enemy].My;
					}
					break;
				case NoMove:
					if (Enemys[enemy].Frieze == FrieseTime) {
						Enemys[enemy].View = (Enemys[enemy].View + 1) % 4;
						Enemys[enemy].Frieze = 0;
					}
					else {
						Enemys[enemy].Frieze++;
					}
					break;
				}
			}
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

		for (int w = 0; w < WallCnt; w++) {
			if (Wall[w].WaPx + Wmap.worldX >= -Wmap.Xsize
				&& Wall[w].WaPx + Wmap.worldX < width + Wmap.Xsize 
				&& Wall[w].WaPy + Wmap.worldY >= -Wmap.Ysize
				&& Wall[w].WaPy + Wmap.worldY < height + Wmap.Ysize) {
				hitbox(w);
				//�G�ƕǂ̓����蔻��
				for (int e = 0; e < EnemyCnt; e++) {
					if (Enemys[e].Cpx + Wmap.worldX >= 0
						&& Enemys[e].Cpx + Wmap.worldX <= width
						&& Enemys[e].Cpy + Wmap.worldY >= 0
						&& Enemys[e].Cpy + Wmap.worldY <= height) {
						hitbox(w, e);
						if (Enemys[e].WallHitFlag == true && Enemys[e].Frieze == FriezeTime) {
							Enemys[e].WallHitFlag = false;
							Enemys[e].Frieze = 0;
						}
						else if (Enemys[e].WallHitFlag == true) {
							Enemys[e].Frieze++;
						}
					}
				}
			}

		}
		for (int g = 0; g < GoalCnt ; g++) {
			if (Goal[g].WaPx + Wmap.worldX >= 0
				&& Goal[g].WaPx + Wmap.worldX < width
				&& Goal[g].WaPy + Wmap.worldY >= 0
				&& Goal[g].WaPy + Wmap.worldY < height) { 
				playerHitBox();
				if (PlayerBox.under.y >= Goal[g].WaPy + Wmap.worldY
					&& PlayerBox.under.y <= Goal[g].WaPy + Wmap.worldY + Wmap.Ysize
					&& PlayerBox.left.x <= Goal[g].WaPx + Wmap.worldX + Wmap.Xsize
					&& PlayerBox.right.x >= Goal[g].WaPx + Wmap.worldX) {
					STATE = RESULT;
				}
			}
		}
	}

	void GAME::hitbox(int w) {
		wallHitBox(w);
		playerHitBox();
		PDist.UpDist = Sqrt(Abs((WallBox.core.x - PlayerBox.under.x) * (WallBox.core.x - PlayerBox.under.x)) + Abs((WallBox.core.y - PlayerBox.under.y) * (WallBox.core.y - PlayerBox.under.y)));
		PDist.UnderDist = Sqrt(Abs((WallBox.core.x - PlayerBox.up.x) * (WallBox.core.x - PlayerBox.up.x)) + Abs((WallBox.core.y - PlayerBox.up.y) * (WallBox.core.y - PlayerBox.up.y)));
		PDist.LeftDist = Sqrt(Abs((WallBox.core.x - PlayerBox.right.x) * (WallBox.core.x - PlayerBox.right.x)) + Abs((WallBox.core.y - PlayerBox.right.y) * (WallBox.core.y - PlayerBox.right.y)));
		PDist.RightDist = Sqrt(Abs((WallBox.core.x - PlayerBox.left.x) * (WallBox.core.x - PlayerBox.left.x)) + Abs((WallBox.core.y - PlayerBox.left.y) * (WallBox.core.y - PlayerBox.left.y)));
		if (PDist.UpDist < PDist.LeftDist && PDist.UpDist < PDist.RightDist && PDist.UpDist < PDist.UnderDist) {
			PDist.PointFlag = PDist.Up;
		}
		else if (PDist.UnderDist < PDist.UpDist && PDist.UnderDist < PDist.RightDist && PDist.UnderDist < PDist.LeftDist) {
			PDist.PointFlag = PDist.Under;
		}
		else if (PDist.LeftDist < PDist.UpDist && PDist.LeftDist < PDist.RightDist && PDist.LeftDist < PDist.UnderDist) {
			PDist.PointFlag = PDist.Left;
		}
		else if (PDist.RightDist < PDist.UpDist && PDist.RightDist < PDist.LeftDist && PDist.RightDist < PDist.UnderDist) {
			PDist.PointFlag = PDist.Right;
		}
		switch (PDist.PointFlag) {
		case PDist.Up://�ǂ��猩�ď㑤�̔���
			if (WallBox.up.y <= PlayerBox.under.y
				&& WallBox.under.y >= PlayerBox.under.y
				&& WallBox.right.x >= PlayerBox.left.x
				&& WallBox.left.x <= PlayerBox.right.x) {
				player.Cpy -= player.My;
			}
			break;
		case PDist.Under://�ǂ��猩�ĉ����̔���
			if (WallBox.under.y >= PlayerBox.up.y
				&& WallBox.up.y <= PlayerBox.up.y
				&& WallBox.right.x >= PlayerBox.left.x
				&& WallBox.left.x <= PlayerBox.right.x) {
				player.Cpy += player.My;
			}
			break;
		case PDist.Left://�ǂ��猩�č����̔���
			if (WallBox.left.x <= PlayerBox.right.x
				&& WallBox.right.x >= PlayerBox.right.x
				&& WallBox.up.y <= PlayerBox.under.y
				&& WallBox.under.y >= PlayerBox.up.y) {
				player.Cpx -= player.Mx;
			}
			break;
		case PDist.Right://�ǂ��猩�ĉE���̔���
			if (WallBox.left.x <= PlayerBox.left.x
				&& WallBox.right.x >= PlayerBox.left.x
				&& WallBox.up.y <= PlayerBox.under.y
				&& WallBox.under.y >= PlayerBox.up.y) {
				player.Cpx += player.Mx;
			}
			break;
		}
	}

	void GAME::hitbox(int w, int e) {
		wallHitBox(w);
		enemyHitBox(e);
		EDist.PointFlag = -1;//���Z�b�g
		EDist.UpDist = Sqrt(Abs((WallBox.core.x - EnemyBox.under.x) * (WallBox.core.x - EnemyBox.under.x)) + Abs((WallBox.core.y - EnemyBox.under.y) * (WallBox.core.y - EnemyBox.under.y)));
		EDist.UnderDist = Sqrt(Abs((WallBox.core.x - EnemyBox.up.x) * (WallBox.core.x - EnemyBox.up.x)) + Abs((WallBox.core.y - EnemyBox.up.y) * (WallBox.core.y - EnemyBox.up.y)));
		EDist.LeftDist = Sqrt(Abs((WallBox.core.x - EnemyBox.right.x) * (WallBox.core.x - EnemyBox.right.x)) + Abs((WallBox.core.y - EnemyBox.right.y) * (WallBox.core.y - EnemyBox.right.y)));
		EDist.RightDist = Sqrt(Abs((WallBox.core.x - EnemyBox.left.x) * (WallBox.core.x - EnemyBox.left.x)) + Abs((WallBox.core.y - EnemyBox.left.y) * (WallBox.core.y - EnemyBox.left.y)));

		if (Enemys[e].Mkind == UpDown) {
			if (EDist.UpDist < EDist.LeftDist && EDist.UpDist < EDist.RightDist && EDist.UpDist < EDist.UnderDist) {
				EDist.PointFlag = EDist.Up;
			}
			else if (EDist.UnderDist < EDist.UpDist && EDist.UnderDist < EDist.RightDist && EDist.UnderDist < EDist.LeftDist) {
				EDist.PointFlag = EDist.Under;
			}
		}
		else if (Enemys[e].Mkind == RightLeft) {
			if (EDist.LeftDist < EDist.UpDist && EDist.LeftDist < EDist.RightDist && EDist.LeftDist < EDist.UnderDist) {
				EDist.PointFlag = EDist.Left;
			}
			else if (EDist.RightDist < EDist.UpDist && EDist.RightDist < EDist.LeftDist && EDist.RightDist < EDist.UnderDist) {
				EDist.PointFlag = EDist.Right;
			}
		}

			switch (EDist.PointFlag) {
			case EDist.Up://�ǂ��猩�ď㑤�̔���
				if (WallBox.up.y <= EnemyBox.under.y + Wall[w].YharfSize
					&& WallBox.under.y >= EnemyBox.under.y + Wall[w].YharfSize
					&& WallBox.right.x >= EnemyBox.left.x
					&& WallBox.left.x <= EnemyBox.right.x) {
					Enemys[e].My *= -1;
					Enemys[e].Cpy += Enemys[e].My;
					Enemys[e].WallHitFlag = true;
				}
				break;
			case EDist.Under://�ǂ��猩�ĉ����̔���
				if (WallBox.under.y >= EnemyBox.up.y - Wall[w].YharfSize
					&& WallBox.up.y <= EnemyBox.up.y - Wall[w].YharfSize
					&& WallBox.right.x >= EnemyBox.left.x
					&& WallBox.left.x <= EnemyBox.right.x) {
					Enemys[e].My *= -1;
					Enemys[e].Cpy += Enemys[e].My;
					Enemys[e].WallHitFlag = true;
				}
				break;
			case EDist.Left://�ǂ��猩�č����̔���
				if (WallBox.left.x <= EnemyBox.right.x + Wall[e].XharfSize
					&& WallBox.right.x >= EnemyBox.right.x + Wall[e].XharfSize
					&& WallBox.up.y <= EnemyBox.under.y
					&& WallBox.under.y >= EnemyBox.up.y) {
					Enemys[e].Mx *= -1;
					Enemys[e].Cpx += Enemys[e].Mx;
					Enemys[e].WallHitFlag = true;
				}
				break;
			case EDist.Right://�ǂ��猩�ĉE���̔���
				if (WallBox.left.x <= EnemyBox.left.x - Wall[e].XharfSize
					&& WallBox.right.x >= EnemyBox.left.x - Wall[e].XharfSize
					&& WallBox.up.y <= EnemyBox.under.y
					&& WallBox.under.y >= EnemyBox.up.y) {
					Enemys[e].Mx *= -1;
					Enemys[e].Cpx += Enemys[e].Mx;
					Enemys[e].WallHitFlag = true;
				}
				break;
			}
	}

	void GAME::wallHitBox(int w) {
		//�ǂ̃R�A
		WallBox.core.x = Wall[w].WaPx + Wmap.XharfSize + Wmap.worldX;
		WallBox.core.y = Wall[w].WaPy + Wmap.YharfSize + Wmap.worldY;
		//�ǂ̏㉺���E�̓����蔻��
		WallBox.up.x = Wall[w].WaPx + Wmap.worldX;
		WallBox.up.y = Wall[w].WaPy + Wmap.worldY;

		WallBox.under.x = Wall[w].WaPx + Wmap.worldX;
		WallBox.under.y = Wall[w].WaPy + Wall[w].Ysize + Wmap.worldY;

		WallBox.left.x = Wall[w].WaPx + Wmap.worldX;
		WallBox.left.y = Wall[w].WaPy + Wmap.worldY;

		WallBox.right.x = Wall[w].WaPx + Wall[w].Xsize + Wmap.worldX;
		WallBox.right.y = Wall[w].WaPy + Wmap.worldY;
	}

	void GAME::playerHitBox() {
		//�v���C���[�̏㉺���E�̓����蔻��
		PlayerBox.up.x = player.Cpx;
		PlayerBox.up.y = player.Cpy - player.Hradius;

		PlayerBox.under.x = player.Cpx;
		PlayerBox.under.y = player.Cpy + player.Hradius;

		PlayerBox.left.x = player.Cpx - player.Hradius;
		PlayerBox.left.y = player.Cpy;

		PlayerBox.right.x = player.Cpx + player.Hradius;
		PlayerBox.right.y = player.Cpy;
	}

	void GAME::enemyHitBox(int e) {
		EnemyBox.up.x = Enemys[e].Cpx + Wmap.worldX;
		EnemyBox.up.y = Enemys[e].Cpy - Enemys[e].Hradius + Wmap.worldY;

		EnemyBox.under.x = Enemys[e].Cpx + Wmap.worldX;
		EnemyBox.under.y = Enemys[e].Cpy + Enemys[e].Hradius + Wmap.worldY;

		EnemyBox.left.x = Enemys[e].Cpx - Enemys[e].Hradius + Wmap.worldX;
		EnemyBox.left.y = Enemys[e].Cpy + Wmap.worldY;

		EnemyBox.right.x = Enemys[e].Cpx + Enemys[e].Hradius + Wmap.worldX;
		EnemyBox.right.y = Enemys[e].Cpy + Wmap.worldY;
	}

	void GAME::draw() {
		rectMode(CORNER);
		clear(255);
		fill(0);
		text(Wmap.worldY,600,700);
		text(Key.ItemCore.x + Wmap.worldX, 600, 800);
		text(Key.ItemCore.y + Wmap.worldY, 600, 900);
		//���ꂼ��̍��W�ɃC���[�W����������ł��邾��
		for (int c = 0; c < col; c++) {
			Wmap.px = Wmap.worldX + c * Wmap.Xsize;
			for (int r = 0; r < row; r++) {
				Wmap.py = Wmap.worldY + r * Wmap.Ysize;
				Wmap.mIdx = r * col + c;
				if (map[Wmap.mIdx] == 'a') {
					image(WallImg, Wmap.px, Wmap.py);
				}
				else if (map[Wmap.mIdx] == '1' || map[Wmap.mIdx] == 'p') {
					image(WallUpImg, Wmap.px, Wmap.py);
				}
				else if (map[Wmap.mIdx] == '2') {
					image(WallUnderImg, Wmap.px, Wmap.py);
				}
				else if (map[Wmap.mIdx] == '3') {
					image(WallLeftImg, Wmap.px, Wmap.py);
				}
				else if (map[Wmap.mIdx] == '4') {
					image(WallRightImg, Wmap.px, Wmap.py);
				}
				else if (map[Wmap.mIdx] == '5') {
					image(WallUpLeftCornerImg, Wmap.px, Wmap.py);
				}
				else if (map[Wmap.mIdx] == '6') {
					image(WallUnderLeftCornerImg, Wmap.px, Wmap.py);
				}
				else if (map[Wmap.mIdx] == '7') {
					image(WallUnderRightCornerImg, Wmap.px, Wmap.py);
				}
				else if (map[Wmap.mIdx] == '8') {
					image(WallUpRightCornerImg, Wmap.px, Wmap.py);

				}
				else if (map[Wmap.mIdx] == 'g') {
					image(goalImg, Wmap.px, Wmap.py);
				}
			}
		}
		fill(0);
		circle(player.Cpx, player.Cpy, player.radius);
		for (int enemy = 0; enemy < Ecnt; enemy++) {
			fill(255, 0, 0);
			circle(Enemys[enemy].Cpx + Wmap.worldX, Enemys[enemy].Cpy + Wmap.worldY, Enemys[enemy].radius);
		}
		fill(255,0,0);
		circle(Key.ItemCore.x + Wmap.worldX, Key.ItemCore.y + Wmap.worldY, Key.Iradius);
	}
}
