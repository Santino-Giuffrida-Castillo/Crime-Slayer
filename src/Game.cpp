#include "Game.h"
#include "Screen.h"

void initGame(Player& player, Bullet bullet[maxBullets], BigAsteroid asteroids[maxBullets])
{
	player = initPlayer();
	for (int i = 0; i < maxBullets; i++)
	{
		bullet[i] = initBullet();
	}
	for (int i = 0; i < maxBullets; i++)
	{
		asteroids[i] = initAsteroid();
		for (int j = 0; j < 2; j++)
		{
			asteroids[i].midAsteroids[j] = initMidAsteroid(asteroids[i], j);
			asteroids[i].midAsteroids[j].littleAsteroids[j] = initLittleAsteroid(asteroids[i].midAsteroids[j], j);
		}
	}


}

void playGame(Player& player, Bullet bullet[maxBullets], BigAsteroid asteroids[maxBullets], float& count)
{

	movePlayer(player);
	moveBullet(bullet);
	moveAsteroid(asteroids);


	checkIfPlayerOutScreen(player);
	checkIfBulletOutScreen(bullet);
	checkIfBigAsteroidOutScreen(asteroids);


	shoot(bullet, player);
	spawAsteroid(asteroids, count);

	BeginDrawing();

	drawPlayer(player);
	drawBullet(bullet);
	drawAsteroid(asteroids);

	EndDrawing();


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

void checkIfBulletOutScreen(Bullet bullet[maxBullets])
{
	for (int i = 0; i < maxBullets; i++)
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

void checkIfBigAsteroidOutScreen(BigAsteroid asteroids[maxBullets])
{
	for (int i = 0; i < maxBullets; i++)
	{
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
			checkIfLittleAsteroidOutScreen(asteroids[i].midAsteroids[j].littleAsteroids, j);
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


