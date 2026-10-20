#include "Asteroid.h"
#include <iostream>
#include <raymath.h>
BigAsteroid initAsteroid()
{
	BigAsteroid asteroid;
	asteroid.lookDir.x = 0;
	asteroid.lookDir.y = 0;
	asteroid.pos.x = 0;
	asteroid.pos.y = 0;
	asteroid.vel.x = 0;
	asteroid.vel.y = 0;
	asteroid.radius = 80;
	asteroid.isActive = false;
	return asteroid;
}

MidAsteroid initMidAsteroid(BigAsteroid& asteroid, int index)
{

	asteroid.midAsteroids[index].lookDir.x = asteroid.lookDir.x;
	asteroid.midAsteroids[index].lookDir.y = asteroid.lookDir.y;
	asteroid.midAsteroids[index].pos.x = asteroid.pos.x;
	asteroid.midAsteroids[index].pos.y = asteroid.pos.y;
	if (index % 2 == 0)
	{
		asteroid.midAsteroids[index].vel.x = -asteroid.pos.x;
		asteroid.midAsteroids[index].vel.y = asteroid.pos.y;
	}
	asteroid.midAsteroids[index].radius = 10;
	asteroid.midAsteroids[index].isActive = false;

	return asteroid.midAsteroids[index];
}
LittleAsteroid initLittleAsteroid(MidAsteroid& asteroid, int index)
{
	asteroid.littleAsteroids[index].lookDir.x = asteroid.lookDir.x;
	asteroid.littleAsteroids[index].lookDir.y = asteroid.lookDir.y;
	asteroid.littleAsteroids[index].pos.x = asteroid.pos.x;
	asteroid.littleAsteroids[index].pos.y = asteroid.pos.y;
	if (index % 2 == 0)
	{
		asteroid.littleAsteroids[index].vel.x = -asteroid.pos.x;
		asteroid.littleAsteroids[index].vel.y = asteroid.pos.y;
	}
	asteroid.littleAsteroids[index].radius = 10;
	asteroid.littleAsteroids[index].isActive = false;

	return asteroid.littleAsteroids[index];
}

void moveAsteroid(BigAsteroid asteroids[maxBullets])
{
	for (int i = 0; i < maxBullets; i++)
	{
		if (asteroids[i].isActive)
		{
			asteroids[i].lookDir = Vector2Normalize(asteroids[i].lookDir);
			asteroids[i].pos.x += asteroids[i].lookDir.x * bulletSpeed * GetFrameTime();
			asteroids[i].pos.y += asteroids[i].lookDir.y * bulletSpeed * GetFrameTime();
			for (int j = 0; j < 2; j++)
			{
				if (asteroids[i].midAsteroids[j].isActive)
				{
					moveAsteroid(asteroids[i].midAsteroids, j);
					moveAsteroid(asteroids[i].midAsteroids[j].littleAsteroids, j);
				}
			}
		}

	}
}


void moveAsteroid(MidAsteroid asteroids[2], int index)
{
	if (asteroids[index].isActive)
	{
		asteroids[index].lookDir = Vector2Normalize(asteroids[index].lookDir);
		asteroids[index].pos.x += asteroids[index].lookDir.x * bulletSpeed * GetFrameTime();
		asteroids[index].pos.y += asteroids[index].lookDir.y * bulletSpeed * GetFrameTime();
	}
}

void moveAsteroid(LittleAsteroid asteroids[2], int index)
{
	if (asteroids[index].isActive)
	{
		asteroids[index].lookDir = Vector2Normalize(asteroids[index].lookDir);
		asteroids[index].pos.x += asteroids[index].lookDir.x * bulletSpeed * GetFrameTime();
		asteroids[index].pos.y += asteroids[index].lookDir.y * bulletSpeed * GetFrameTime();
	}
}

void drawAsteroid(BigAsteroid asteroids[maxBullets])
{
	for (int i = 0; i < maxBullets; i++)
	{
		if (asteroids[i].isActive)
		{
			DrawCircleV(asteroids[i].pos, asteroids[i].radius, BLUE);
			for (int j = 0; j < 2; j++)
			{
				if (asteroids[i].midAsteroids[j].isActive)
				{
					drawAsteroid(asteroids[i].midAsteroids, j);

				}
				if (asteroids[i].midAsteroids[j].littleAsteroids[j].isActive)
				{
					drawAsteroid(asteroids[i].midAsteroids[j].littleAsteroids, j);
				}

			}
		}
	}
}

void drawAsteroid(MidAsteroid asteroids[2], int index)
{
	if (asteroids[index].isActive)
	{
		DrawCircleV(asteroids[index].pos, asteroids[index].radius, BLUE);
	}
}

void drawAsteroid(LittleAsteroid asteroids[2], int index)
{
	if (asteroids[index].isActive)
	{
		DrawCircleV(asteroids[index].pos, asteroids[index].radius, BLUE);
	}
}


void spawAsteroid(BigAsteroid asteroids[maxBullets], float& count)
{
	int countMax = 10;
	int asteroidsInTotal = 0;
	if (count >= countMax)
	{
		for (int i = 0; i < maxBullets; i++)
		{
			if (!asteroids[i].isActive)
			{
				asteroids[i].lookDir.x = static_cast<float>(rand() % 360);
				asteroids[i].lookDir.y = static_cast<float>(rand() % 360);
				asteroids[i].isActive = true;
				
				break;
			}
			else
			{
				asteroidsInTotal++;
			}
		
		}
		std::cout << asteroidsInTotal;
		count = 0;
	}
}

void spawMidAsteroid(MidAsteroid asteroids[2], int index)
{
	if (!asteroids[index].isActive)
	{
		asteroids[index].lookDir.x = static_cast<float>(rand() % 360);
		asteroids[index].lookDir.y = static_cast<float>(rand() % 360);
		asteroids[index].isActive = true;

	}

}
void spawLittleAsteroid(LittleAsteroid asteroids[2], int index)
{
	if (!asteroids[index].isActive)
	{
		asteroids[index].lookDir.x = static_cast<float>(rand() % 360);
		asteroids[index].lookDir.y = static_cast<float>(rand() % 360);
		asteroids[index].isActive = true;

	}

}