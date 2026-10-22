#pragma once

#include <raylib.h>
namespace asteroids
{
	const int bulletSpeed = 300;
	const int maxBullets = 30;
	struct Bullet
	{
		Vector2 lookDir;
		Vector2 pos;
		Vector2 vel;
		float radius;
		bool isActive = false;
	};

	Bullet initBullet();
	void moveBullet(Bullet bullet[maxBullets]);
	void drawBullet(Bullet bullet[maxBullets]);
}