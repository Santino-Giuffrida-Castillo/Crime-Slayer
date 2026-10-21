#include "Bullet.h"
#include <raymath.h>
#include <iostream>
namespace asteroids
{
	Bullet initBullet()
	{
		Bullet bullet;
		bullet.lookDir.x = 0;
		bullet.lookDir.y = 0;
		bullet.pos.x = 0;
		bullet.pos.y = 0;
		bullet.vel.x = 0;
		bullet.vel.y = 0;
		bullet.radius = 5;
		bullet.isActive = false;
		return bullet;
	}

	void moveBullet(Bullet bullet[maxBullets])
	{
		for (int i = 0; i < maxBullets; i++)
		{
			if (bullet[i].isActive)
			{
				bullet[i].pos.x += bullet[i].lookDir.x * bulletSpeed * GetFrameTime();
				bullet[i].pos.y += bullet[i].lookDir.y * bulletSpeed * GetFrameTime();
			}

		}


	}

	void drawBullet(Bullet bullet[maxBullets])
	{
		for (int i = 0; i < maxBullets; i++)
		{

			if (bullet[i].isActive)
			{
				DrawCircleV(bullet[i].pos, bullet[i].radius, BLUE);
			}
		}

	}
}