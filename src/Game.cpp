#include "Game.h"

#include <iostream>

#include <raymath.h>

#include "Screen.h"
namespace asteroids
{
	void initGame(Player& player, Bullet bullet[maxBullets], BigAsteroid asteroids[MAX_ASTEROIDS])
	{
		player = initPlayer();
		for (int i = 0; i < maxBullets; i++)
		{
			bullet[i] = initBullet();
		}
		for (int i = 0; i < MAX_ASTEROIDS; i++)
		{
			asteroids[i] = initAsteroid();
			for (int j = 0; j < 2; j++)
			{
				asteroids[i].midAsteroids[j] = initMidAsteroid(asteroids[i], j);
				for (int k = 0; k < 2; k++)
				{
					asteroids[i].midAsteroids[j].littleAsteroids[k] = initLittleAsteroid(asteroids[i].midAsteroids[j], k);
				}


			}
		}


	}

	void playGame(Player& player, Bullet bullet[maxBullets], BigAsteroid asteroids[maxBullets], float& count, Screen& actualScreen, Texture2D background)
	{

		movePlayer(player);
		moveBullet(bullet);
		moveAsteroid(asteroids);


		checkIfPlayerOutScreen(player);
		checkIfBulletOutScreen(bullet);
		checkIfBigAsteroidOutScreen(asteroids);
		checkOneBigAsteroidCollisions(player, bullet, asteroids);

		shoot(bullet, player);
		spawAsteroid(asteroids, count);
		checkIfPlayerIsLosing(player, actualScreen);
		checkIfPlayerPaused(actualScreen);

		ClearBackground(BLACK);
		
		DrawTexturePro(
			background,
			{ 0, 0, (float)background.width, (float)background.height },
			{ 0, 0, (float)screenWidth, (float)screenHigh },
			{ 0, 0 },
			0.0f,
			WHITE
		);


		drawPlayer(player);
		drawBullet(bullet);
		drawAsteroid(asteroids);
		showPlayerInfo(player);




	}

	void checkIfPlayerOutScreen(Player& player)
	{

		if ((player.pos.x - player.radius) > screenWidth)
		{
			player.pos.x = 0 + player.radius;
		}
		else if ((player.pos.x + player.radius) < 0)
		{
			player.pos.x += screenWidth - player.radius;
		}
		if ((player.pos.y - player.radius) > screenHigh)
		{
			player.pos.y = 0 + player.radius;
		}
		else if ((player.pos.y + player.radius) < 0)
		{
			player.pos.y = screenHigh - player.radius;
		}

	}

	void checkIfBulletOutScreen(Bullet bullet[MAX_ASTEROIDS])
	{
		for (int i = 0; i < MAX_ASTEROIDS; i++)
		{
			if ((bullet[i].pos.x - bullet[i].radius) > screenWidth)
			{
				bullet[i].isActive = false;
			}
			else if ((bullet[i].pos.x + bullet[i].radius) < 0)
			{
				bullet[i].isActive = false;
			}
			if ((bullet[i].pos.y - bullet[i].radius) > screenHigh)
			{
				bullet[i].isActive = false;
			}
			else if ((bullet[i].pos.y + bullet[i].radius) < 0)
			{
				bullet[i].isActive = false;
			}

		}

	}

	void checkIfBigAsteroidOutScreen(BigAsteroid asteroids[MAX_ASTEROIDS])
	{
		for (int i = 0; i < MAX_ASTEROIDS; i++)
		{
			if (!asteroids[i].isActive)
			{
				continue;
			}
			if ((asteroids[i].pos.x - asteroids[i].radius) > screenWidth)
			{
				asteroids[i].pos.x = 0 + asteroids[i].radius;
			}
			else if ((asteroids[i].pos.x + asteroids[i].radius) < 0)
			{
				asteroids[i].pos.x += screenWidth - asteroids[i].radius;
			}
			if ((asteroids[i].pos.y - asteroids[i].radius) > screenHigh)
			{
				asteroids[i].pos.y = 0 + asteroids[i].radius;
			}
			else if ((asteroids[i].pos.y + asteroids[i].radius) < 0)
			{
				asteroids[i].pos.y = screenHigh - asteroids[i].radius;
			}

			for (int j = 0; j < 2; j++)
			{
				checkIfMidAsteroidOutScreen(asteroids[i].midAsteroids, j);
				for (int k = 0; k < 2; k++)
				{
					checkIfLittleAsteroidOutScreen(asteroids[i].midAsteroids[j].littleAsteroids, k);
				}

			}
		}
	}

	void checkIfMidAsteroidOutScreen(MidAsteroid asteroids[2], int index)
	{
		if ((asteroids[index].pos.x - asteroids[index].radius) > screenWidth)
		{
			asteroids[index].pos.x = 0 + asteroids[index].radius;
		}
		else if ((asteroids[index].pos.x + asteroids[index].radius) < 0)
		{
			asteroids[index].pos.x += screenWidth - asteroids[index].radius;
		}
		if ((asteroids[index].pos.y - asteroids[index].radius) > screenHigh)
		{
			asteroids[index].pos.y = 0 + asteroids[index].radius;
		}
		else if ((asteroids[index].pos.y + asteroids[index].radius) < 0)
		{
			asteroids[index].pos.y = screenHigh - asteroids[index].radius;
		}
	}

	void checkIfLittleAsteroidOutScreen(LittleAsteroid asteroids[2], int index)
	{
		if ((asteroids[index].pos.x - asteroids[index].radius) > screenWidth)
		{
			asteroids[index].pos.x = 0 + asteroids[index].radius;
		}
		else if ((asteroids[index].pos.x + asteroids[index].radius) < 0)
		{
			asteroids[index].pos.x += screenWidth - asteroids[index].radius;
		}
		if ((asteroids[index].pos.y - asteroids[index].radius) > screenHigh)
		{
			asteroids[index].pos.y = 0 + asteroids[index].radius;
		}
		else if ((asteroids[index].pos.y + asteroids[index].radius) < 0)
		{
			asteroids[index].pos.y = screenHigh - asteroids[index].radius;
		}
	}

	void checkOneBigAsteroidCollisions(Player& player, Bullet bullets[maxBullets], BigAsteroid asteroid[maxBullets])
	{
		//primero el jugador
		float distance = 0;
		for (int i = 0; i < maxBullets; i++)
		{
			distance = Vector2Distance(player.pos, asteroid[i].pos);

			if (asteroid[i].isActive && !asteroid[i].isHit)
			{

				if (distance <= player.radius + asteroid[i].radius)
				{
					PlaySound(player.deadSound);
					player.lives--;
					asteroid[i] = initAsteroid();
				}


			}
			for (int j = 0; j < 2; j++)
			{
				distance = Vector2Distance(player.pos, asteroid[i].midAsteroids[j].pos);

				if (asteroid[i].midAsteroids[j].isActive && !asteroid[i].midAsteroids[j].isHit)
				{

					if (distance <= player.radius + asteroid[i].midAsteroids[j].radius)
					{
						PlaySound(player.deadSound);
						player.lives--;
						asteroid[i].midAsteroids[j] = initMidAsteroid(asteroid[i], j);
					}


				}

				for (int k = 0; k < 2; k++)
				{
					distance = Vector2Distance(player.pos, asteroid[i].midAsteroids[j].littleAsteroids[k].pos);

					if (asteroid[i].midAsteroids[j].littleAsteroids[k].isActive && !asteroid[i].midAsteroids[j].littleAsteroids[k].isHit)
					{

						if (distance <= player.radius + asteroid[i].midAsteroids[j].littleAsteroids[k].radius)
						{
							PlaySound(player.deadSound);
							player.lives--;
							asteroid[i].midAsteroids[j].littleAsteroids[k] = initLittleAsteroid(asteroid[i].midAsteroids[j], k);
						}


					}
				}
			}
		}
		//ahora bala con asteroide grande

		for (int i = 0; i < MAX_ASTEROIDS; i++)
		{
			if (asteroid[i].isActive && !asteroid[i].isHit)
			{
				for (int j = 0; j < maxBullets; j++)
				{
					distance = Vector2Distance(bullets[j].pos, asteroid[i].pos);
					if (bullets[j].isActive && distance <= bullets[j].radius + asteroid[i].radius)
					{
						asteroid[i].isHit = true;
						playAsteroidExplosion(1);
						for (int k = 0; k < 2; k++)
						{
							asteroid[i].midAsteroids[k] = initMidAsteroid(asteroid[i], k);
							asteroid[i].midAsteroids[k].isHit = false;
						}
						bullets[j].isActive = false;
						player.points += 10;
					}
				}
			}
		}
		//chequeo medianos
		for (int i = 0; i < MAX_ASTEROIDS; i++)
		{
			if (asteroid[i].isActive && asteroid[i].isHit)
			{

				for (int j = 0; j < maxBullets; j++)
				{
					for (int k = 0; k < 2; k++)
					{
						if (asteroid[i].midAsteroids[k].isActive && !asteroid[i].midAsteroids[k].isHit)
						{
							distance = Vector2Distance(bullets[j].pos, asteroid[i].midAsteroids[k].pos);

							if (bullets[j].isActive && distance <= bullets[j].radius + asteroid[i].midAsteroids[k].radius)
							{
								asteroid[i].midAsteroids[k].isHit = true;
								playAsteroidExplosion(2);
								for (int l = 0; l < 2; l++)
								{
									asteroid[i].midAsteroids[k].littleAsteroids[l] = initLittleAsteroid(asteroid[i].midAsteroids[k], l);
									asteroid[i].midAsteroids[k].littleAsteroids[l].isHit = false;
								}
								bullets[j].isActive = false;
								player.points += 20;
							}
						}
					}
				}
			}

		}
		//chequeo chiquitos
		for (int i = 0; i < MAX_ASTEROIDS; i++)
		{

			if (asteroid[i].isActive && asteroid[i].isHit)
			{

				for (int j = 0; j < maxBullets; j++)
				{
					for (int k = 0; k < 2; k++)
					{
						if (asteroid[i].midAsteroids[k].isActive && asteroid[i].midAsteroids[k].isHit)
						{

							for (int l = 0; l < 2; l++)
							{
								distance = Vector2Distance(bullets[j].pos, asteroid[i].midAsteroids[k].littleAsteroids[l].pos);

								if (bullets[j].isActive && distance <= bullets[j].radius + asteroid[i].midAsteroids[k].littleAsteroids[l].radius && !asteroid[i].midAsteroids[k].littleAsteroids[l].isHit)
								{
									asteroid[i].midAsteroids[k].littleAsteroids[l].isHit = true;
									playAsteroidExplosion(3);
									player.points += 30;
									bullets[j].isActive = false;
								}
							}
						}

					}
				}
			}
		}


	}

	void checkIfPlayerIsLosing(Player& player, Screen& actualScreen)
	{
		if (player.lives <= 0)
		{
			player.lives = 0;
			actualScreen = Screen::LOOSE;
			player.highScore = player.points;
		}
	}


	void checkIfPlayerPaused(Screen& actualScreen)
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE))
		{
			actualScreen = Screen::PAUSE;
		}
	}
}
