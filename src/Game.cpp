#include "Game.h"
#include "Screen.h"
#include "Const.h"
void initGame(Player& player, Bullet& bullet)
{
	player = initPlayer();
	bullet = initBullet();

}

void playGame(Player& player, Bullet& bullet)
{

	movePlayer(player);
	moveBullet(bullet);
	checkIfPlayerOutScreen(player);
	shoot(bullet, player);


	BeginDrawing();

	drawPlayer(player);
	drawBullet(bullet);

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