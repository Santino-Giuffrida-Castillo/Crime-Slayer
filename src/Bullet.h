#pragma once
struct Bullet
{
	float posX = 0;
	float posY = 0;
	bool isActive = false;
};

Bullet initBullet();
void moveBullet(Bullet& bullet);
