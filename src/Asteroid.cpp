#include "Asteroid.h"
#include <iostream>
#include <raymath.h>

namespace asteroids
{
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
		asteroid.isHit = false;
		return asteroid;
	}

	MidAsteroid initMidAsteroid(BigAsteroid& asteroid, int index)
	{


		asteroid.midAsteroids[index].lookDir.y = asteroid.lookDir.y;

		if (index % 2 == 0)
		{
			asteroid.midAsteroids[index].lookDir.x = -asteroid.lookDir.x;
			asteroid.midAsteroids[index].pos.x = asteroid.pos.x;
			asteroid.midAsteroids[index].pos.y = asteroid.pos.y;
			asteroid.midAsteroids[index].vel.x = -asteroid.vel.x;
			asteroid.midAsteroids[index].vel.y = asteroid.vel.y;
		}
		else
		{
			asteroid.midAsteroids[index].lookDir.x = asteroid.lookDir.x;
			asteroid.midAsteroids[index].pos.x = asteroid.pos.x + asteroid.midAsteroids[index].radius;
			asteroid.midAsteroids[index].pos.y = asteroid.pos.y + asteroid.midAsteroids[index].radius;
			asteroid.midAsteroids[index].vel.x = asteroid.vel.x;
			asteroid.midAsteroids[index].vel.y = asteroid.vel.y;
		}

		asteroid.midAsteroids[index].radius = 40;
		asteroid.midAsteroids[index].isActive = true;
		asteroid.midAsteroids[index].isHit = true;

		return asteroid.midAsteroids[index];
	}
	LittleAsteroid initLittleAsteroid(MidAsteroid& asteroid, int index)
	{

		asteroid.littleAsteroids[index].lookDir.y = asteroid.lookDir.y;

		if (index % 2 == 0)
		{
			asteroid.littleAsteroids[index].lookDir.x = -asteroid.lookDir.x;
			asteroid.littleAsteroids[index].pos.x = asteroid.pos.x;
			asteroid.littleAsteroids[index].pos.y = asteroid.pos.y;
			asteroid.littleAsteroids[index].vel.x = -asteroid.vel.x;
			asteroid.littleAsteroids[index].vel.y = asteroid.vel.y;
		}
		else
		{
			asteroid.littleAsteroids[index].lookDir.x = asteroid.lookDir.x;
			asteroid.littleAsteroids[index].pos.x = asteroid.pos.x + asteroid.littleAsteroids[index].radius;
			asteroid.littleAsteroids[index].pos.y = asteroid.pos.y + asteroid.littleAsteroids[index].radius;
			asteroid.littleAsteroids[index].vel.x = asteroid.vel.x;
			asteroid.littleAsteroids[index].vel.y = asteroid.vel.y;
		}
		asteroid.littleAsteroids[index].radius = 20;
		asteroid.littleAsteroids[index].isActive = true;
		asteroid.littleAsteroids[index].isHit = true;

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
						for (int k = 0; k < 2; k++)
						{
							moveAsteroid(asteroids[i].midAsteroids[j].littleAsteroids, k);
						}

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
				if (!asteroids[i].isHit)
				{
					DrawCircleV(asteroids[i].pos, asteroids[i].radius, BLUE);
				}

				for (int j = 0; j < 2; j++)
				{
					if (asteroids[i].midAsteroids[j].isActive)
					{
						drawAsteroid(asteroids[i].midAsteroids, j);

					}

					for (int k = 0; k < 2; k++)
					{
						if (asteroids[i].midAsteroids[j].littleAsteroids[j].isActive)
						{
							drawAsteroid(asteroids[i].midAsteroids[j].littleAsteroids, k);
						}
					}


				}
			}
		}
	}

	void drawAsteroid(MidAsteroid asteroids[2], int index)
	{
		if (asteroids[index].isActive && !asteroids[index].isHit)
		{
			DrawCircleV(asteroids[index].pos, asteroids[index].radius, BLUE);
		}
	}

	void drawAsteroid(LittleAsteroid asteroids[2], int index)
	{
		if (asteroids[index].isActive && !asteroids[index].isHit)
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
					asteroids[i].isHit = false;

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

}

