#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME13.h"

namespace GAME13
{
	
	const int PLAYER_SPEED = 10; // プレイヤーの移動速度
	const int BULLET_SPEED = 12; // 弾の速度
	const int MAX_BULLETS = 100000; // 同時に画面に表示する弾の最大数
	const int ENEMY_SPEED = 13; // 敵の移動速度
	const int ENEMY_HEALTH = 115; // 敵の体力

	bool shooting = false; // 射撃
	int playerX = 640; // プレイヤーのX座標
	int playerY = 800; // プレイヤーのY座標
	int bulletX[MAX_BULLETS]; // 弾のX座標
	int bulletY[MAX_BULLETS]; // 弾のY座標
	int bulletCount = 0; // 現在の弾の数
	
	int enemyX = 640; // 敵のX座標
	int enemyY = 250; // 敵のY座標
	int enemyDirection = 1; // 敵の移動方向（1: 右, -1: 左）
	int enemyHealth = ENEMY_HEALTH; // 敵の体力

	int GAME::create()
	{
		Img = loadImage("..\\main\\assets\\game13\\haikei.png");
		State = TITLE;
		return 0;
	}

	void GAME::destroy()
	{

	}

	void GAME::proc()
	{
		//シーン切り替え
		if (State == TITLE) Title();
		else if (State == PLAY) Play();
		else if (State == CLEAR) Clear();
	}

	void GAME::Title()
	{
		clear(0, 0, 64);
		image(Img,0,0);
		textSize(50);
		fill(255, 255, 0);
		print("クリックでゲームスタート");
		fill(255);
		text("ENTERキーでメニューに戻る", 0, 1080);

		if (isTrigger(KEY_ENTER))
		{
			main()->backToMenu();
		}
		if (isTrigger(MOUSE_LBUTTON))
		{
			State = PLAY;
		}
		Init();
	}



	void GAME::Init()
	{
		// ゲームの各変数を初期化する
		
		playerX = 640;
		playerY = 800;
		bulletCount = 0;
		enemyX = 640;
		enemyY = 250;
		enemyDirection = 1;
		enemyHealth = ENEMY_HEALTH;
	}

	void GAME::Play()
	{
		clear(0, 0, 64);
		image(Img, 0, 0);
		textSize(50);
		fill(255, 255, 0);
		print("スペースで射撃");
		print("Aで左");
		print("Dで右");
		fill(255);
		text("ENTERキーでメニューに戻る", 0, 1080);
		
		// プレイヤーの描画
		fill(255);
		rect(playerX - 25, playerY - 25, 50, 50);

		// 敵の描画
		fill(175, 223, 228);
		circle(enemyX, enemyY, 50);

		// 敵の体力ゲージの描画
		fill(0, 255, 0);
		rect(enemyX - 50, enemyY - 100, (enemyHealth * 100) / ENEMY_HEALTH, 10);

		// プレイヤーの移動
		if (isPress(KEY_D) && playerX < 1880) {
			playerX += PLAYER_SPEED;
		}
		if (isPress(KEY_A) && playerX > 25) {
			playerX -= PLAYER_SPEED;
		}

		// スペースキーが押されたら射撃
		if (isPress(KEY_SPACE))
		{
			shooting = true;
			bulletX[bulletCount] = playerX; // プレイヤーのX座標に
			bulletY[bulletCount] = playerY; // プレイヤーのY座標に
			bulletCount++; // 弾の数を増やす
			if (bulletCount >= MAX_BULLETS) // 弾の数が最大数に達したら
				bulletCount = 0; // 弾の数をリセット
		}

		// 射撃が行われている場合、射撃の描画
		for (int i = 0; i < bulletCount; i++)
		{
			fill(255);
			circle(bulletX[i], bulletY[i], 10); // 弾の描画
			bulletY[i] -= BULLET_SPEED; // 弾を上に移動
		}

		// 敵の移動
		enemyX += enemyDirection * ENEMY_SPEED;
		if (enemyX <= 50) // 敵が画面左端に到達したら
		{
			enemyDirection = 1; // 移動方向を右に設定
		}
		else if (enemyX >= 1880) // 敵が画面右端に到達したら
		{
			enemyDirection = -1; // 移動方向を左に設定
		}

		// 弾と敵の衝突判定
		for (int i = 0; i < bulletCount; i++)
		{
			if (sqrt(pow(bulletX[i] - enemyX, 2) + pow(bulletY[i] - enemyY, 2)) < 50)
			{
				// 弾が敵に当たったら敵の体力を減らす
				enemyHealth--;
				// 当たった弾を消去する
				bulletX[i] = bulletX[bulletCount - 1];
				bulletY[i] = bulletY[bulletCount - 1];
				bulletCount--;
				i--;
			}
		}

		// 敵の体力が0以下になったら
		if (enemyHealth <= 0)
		{
			// クリア画面移行
			State = CLEAR;
		}

		if (isTrigger(KEY_ENTER))
		{
			main()->backToMenu();
		}
	}

	void GAME::Clear()
	{
		clear(0, 0, 64);
		image(Img, 0, 0);
		textSize(50);
		fill(255, 255, 0);
		text("CLEAR!", 0, 100);
		fill(255);
		text("ENTERキーでメニューに戻る", 0, 1080);

		if (isTrigger(KEY_ENTER))
		{
			Init();
			State = TITLE;
		}
	}

}
