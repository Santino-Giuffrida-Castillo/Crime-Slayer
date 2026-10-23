#pragma once
#include "Bullet.h"

#include <raylib.h>
namespace asteroids
{
	const float maxPlayerSpeed = 300;
	struct Player
	{
		Vector2 lookDir;
		Vector2 pos;
		Vector2 vel;
		float angle;
		float radius;
		int lives;
		int points;
		int highScore = 0;
		Texture2D texture;
		Rectangle source;
		Rectangle dest;
		Vector2 origin;
		Sound shootSound;
		Sound deadSound;

	};
	Player initPlayer();
	void movePlayer(Player& player);
	void drawPlayer(Player player);
	void shoot(Bullet bullet[maxBullets], Player player);
	void showPlayerInfo(Player player);
	void loadPlayerAssets();
	void unloadPlayerAssets();
}