#pragma once
#include <raylib.h>
struct Bullet
{
	Vector2 lookDir;
	Vector2 pos;
	Vector2 vel;
	float radius;
	bool isActive = false;
};

Bullet initBullet();
void moveBullet(Bullet& bullet);
void drawBullet(Bullet& bullet);
