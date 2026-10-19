#include <Player.h>
#include <raymath.h>
#include "Const.h"
Player initPlayer()
{
	Player player;
	player.pos.x = screenWidth / 2;
	player.pos.y = screenHigh / 2;
	player.vel.x = 0;
	player.vel.y = 0;
	player.radius = 30;
	player.angle = 0;
	player.lives = 3;
	return player;
}

void movePlayer(Player& player)
{
	Vector2 mousePos = GetMousePosition();
	player.lookDir = Vector2Subtract(mousePos,player.pos);
	//tiene entre 90 y -90 grados (ahora esta en radianes)
	player.angle = static_cast<float>(atan(player.lookDir.y / player.lookDir.x));
	player.angle *= RAD2DEG;
	if (mousePos.x > player.pos.x && mousePos.y > player.pos.y)
	{
		//Cuadrante 1
	}
	else if (mousePos.x < player.pos.x && mousePos.y > player.pos.y)
	{
		player.angle += 180;
	}
	else if (mousePos.x < player.pos.x && mousePos.y < player.pos.y)
	{
		player.angle += 180;
	}
	else if (mousePos.x > player.pos.x && mousePos.y < player.pos.y)
	{
		player.angle += 360;
	}

	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		if (Vector2Length(player.vel) > maxPlayerSpeed)
		{
			player.vel = Vector2Normalize(player.vel);
			player.vel.x *= maxPlayerSpeed;
			player.vel.y *= maxPlayerSpeed;
		}
		else
		{
			player.lookDir = Vector2Normalize(player.lookDir);
			player.vel.x += player.lookDir.x * GetFrameTime() * maxPlayerSpeed;
			player.vel.y += player.lookDir.y * GetFrameTime() * maxPlayerSpeed;
		}

		

	}
	player.pos.x += player.vel.x * GetFrameTime();
	player.pos.y += player.vel.y * GetFrameTime();
}

void drawPlayer(Player player)
{
	DrawCircleV(player.pos, player.radius, RED);
}

void shoot(Bullet& bullet, Player player)
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
	{
		bullet.posX = player.pos.x;
		bullet.posY = player.pos.y;
		bullet.isActive = true;
	}
}