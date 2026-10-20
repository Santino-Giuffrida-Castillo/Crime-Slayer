#include "Bullet.h"
#include <raymath.h>
#include "Const.h"
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

void moveBullet(Bullet& bullet)
{

	bullet.pos.x += bullet.lookDir.x * bulletSpeed * GetFrameTime();
	bullet.pos.y += bullet.lookDir.y * bulletSpeed * GetFrameTime();

}

void drawBullet(Bullet& bullet)
{
	if (bullet.isActive)
	{
		DrawCircleV(bullet.pos, bullet.radius, BLUE);
	}
}