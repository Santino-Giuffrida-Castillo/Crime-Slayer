#pragma once
#include "Bullet.h"
#include <raylib.h>
struct Player
{
	Vector2 lookDir;
	Vector2 pos;
	Vector2 vel;
	float angle;
	float radius;
	int lives;
};
Player initPlayer();
void movePlayer(Player& player);
void drawPlayer(Player player);
void shoot(Bullet& bullet, Player player);