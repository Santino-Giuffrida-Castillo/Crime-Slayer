#include "Asteroid.h"

#include <iostream>

#include <raymath.h>

namespace asteroids
{
	Texture2D bigAsteroidTexture;
	Texture2D midAsteroidTexture;
	Texture2D littleAsteroidTexture;
	Sound explosionSound1;
	Sound explosionSound2;
	Sound explosionSound3;

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
		asteroid.texture = bigAsteroidTexture;
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
		asteroid.midAsteroids[index].texture = midAsteroidTexture;
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
		asteroid.littleAsteroids[index].texture = littleAsteroidTexture;
		return asteroid.littleAsteroids[index];
	}

	void moveAsteroid(BigAsteroid asteroids[MAX_ASTEROIDS])
	{
		for (int i = 0; i < MAX_ASTEROIDS; i++)
		{
			if (asteroids[i].isActive)
			{
				asteroids[i].lookDir = Vector2Normalize(asteroids[i].lookDir);
				asteroids[i].pos.x += asteroids[i].lookDir.x * ASTEROID_SPEED * GetFrameTime();
				asteroids[i].pos.y += asteroids[i].lookDir.y * ASTEROID_SPEED * GetFrameTime();
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
			asteroids[index].pos.x += asteroids[index].lookDir.x * ASTEROID_SPEED * GetFrameTime();
			asteroids[index].pos.y += asteroids[index].lookDir.y * ASTEROID_SPEED * GetFrameTime();
		}
	}

	void moveAsteroid(LittleAsteroid asteroids[2], int index)
	{
		if (asteroids[index].isActive)
		{
			asteroids[index].lookDir = Vector2Normalize(asteroids[index].lookDir);
			asteroids[index].pos.x += asteroids[index].lookDir.x * ASTEROID_SPEED * GetFrameTime();
			asteroids[index].pos.y += asteroids[index].lookDir.y * ASTEROID_SPEED * GetFrameTime();
		}
	}

	void drawAsteroid(BigAsteroid asteroids[MAX_ASTEROIDS])
	{


		for (int i = 0; i < MAX_ASTEROIDS; i++)
		{
			asteroids[i].source = { 0,0,static_cast<float>(asteroids[i].texture.width),static_cast<float>(asteroids[i].texture.height) };

			asteroids[i].dest = { asteroids[i].pos.x,asteroids[i].pos.y,asteroids[i].radius * 2,asteroids[i].radius * 2 };

			asteroids[i].origin = { asteroids[i].radius,	asteroids[i].radius };

			

			if (asteroids[i].isActive)
			{
				if (!asteroids[i].isHit)
				{
#ifdef _DEBUG	
					DrawCircleV(asteroids[i].pos, asteroids[i].radius, BLUE);
#endif 
					DrawTexturePro(asteroids[i].texture, asteroids[i].source, asteroids[i].dest, asteroids[i].origin, 0.0f, WHITE);
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
		asteroids[index].source = { 0,0,static_cast<float>(asteroids[index].texture.width),static_cast<float>(asteroids[index].texture.height) };

		asteroids[index].dest = { asteroids[index].pos.x,asteroids[index].pos.y,asteroids[index].radius * 2,asteroids[index].radius * 2 };

		asteroids[index].origin = { asteroids[index].radius,asteroids[index].radius };

		
		if (asteroids[index].isActive && !asteroids[index].isHit)
		{
#ifdef _DEBUG	
			DrawCircleV(asteroids[index].pos, asteroids[index].radius, BLUE);
#endif 
			DrawTexturePro(asteroids[index].texture, asteroids[index].source, asteroids[index].dest, asteroids[index].origin, 0.0f, WHITE);
		}
	}

	void drawAsteroid(LittleAsteroid asteroids[2], int index)
	{
		asteroids[index].source = { 0,0,static_cast<float>(asteroids[index].texture.width),static_cast<float>(asteroids[index].texture.height) };

		asteroids[index].dest = { asteroids[index].pos.x,asteroids[index].pos.y,asteroids[index].radius * 2,asteroids[index].radius * 2 };

		asteroids[index].origin = { asteroids[index].radius,asteroids[index].radius };

		if (asteroids[index].isActive && !asteroids[index].isHit)
		{

	#ifdef _DEBUG	
	DrawCircleV(asteroids[index].pos, asteroids[index].radius, BLUE);
	#endif 

		

			DrawTexturePro(asteroids[index].texture, asteroids[index].source, asteroids[index].dest, asteroids[index].origin, 0.0f, WHITE);
		}
	}


	void spawAsteroid(BigAsteroid asteroids[MAX_ASTEROIDS], float& count)
	{
		int countMax = 10;
		int asteroidsInTotal = 0;
		if (count >= countMax)
		{
			for (int i = 0; i < MAX_ASTEROIDS; i++)
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

	void loadAsteroidTextures()
	{
		bigAsteroidTexture = LoadTexture("res/asteroid1.png");
		midAsteroidTexture = LoadTexture("res/asteroid2.png");
		littleAsteroidTexture = LoadTexture("res/asteroid3.png");
		
	}

	void unloadAsteroidTextures()
	{
		UnloadTexture(bigAsteroidTexture);
		UnloadTexture(midAsteroidTexture);
		UnloadTexture(littleAsteroidTexture);
	}

	void loadAsteroidSounds()
	{
		explosionSound1 = LoadSound("res/boom1.wav");
		explosionSound2 = LoadSound("res/boom2.wav");
		explosionSound3 = LoadSound("res/boom3.wav");
	}

	void unloadAsteroidSounds()
	{
		UnloadSound(explosionSound1);
		UnloadSound(explosionSound2);
		UnloadSound(explosionSound3);
	}

	void playAsteroidExplosion(int num)
	{
		if (num == 1)
		{
			PlaySound(explosionSound1);

		}
		else if (num == 2)
		{
			PlaySound(explosionSound2);
		}
		else if (num == 3)
		{
			PlaySound(explosionSound3);
		}
		
		
	
	}

}

