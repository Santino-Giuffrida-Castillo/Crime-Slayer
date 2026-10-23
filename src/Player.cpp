#include <Player.h>

#include <raymath.h>

#include "Screen.h"
namespace asteroids
{
	static Texture2D playerTexture;
	static Sound shootSound;
	static Sound deadSound;

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
		player.points = 0;
		player.texture = playerTexture;
		player.shootSound = shootSound;
		player.deadSound = deadSound;
		return player;
	}

	void movePlayer(Player& player)
	{
		Vector2 mousePos = GetMousePosition();
		player.lookDir = Vector2Subtract(mousePos, player.pos);
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

		if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
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
#ifdef _DEBUG
		DrawCircleV(player.pos, player.radius, RED);
#endif 


		Rectangle source = {0,0,static_cast<float>(player.texture.width),static_cast<float>(player.texture.height)};

		Rectangle dest = {player.pos.x,player.pos.y,player.radius * 2,player.radius * 2};

		Vector2 origin = {player.radius,	player.radius};

		DrawTexturePro(player.texture,source,dest,origin,player.angle,	WHITE);
	}

	void shoot(Bullet bullet[maxBullets], Player player)
	{
		Vector2 mousePos;
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			PlaySound(player.shootSound);
			mousePos = GetMousePosition();
			for (int i = 0; i < maxBullets; i++)
			{
				if (!bullet[i].isActive)
				{
					bullet[i].pos.x = player.pos.x;
					bullet[i].pos.y = player.pos.y;
					bullet[i].lookDir = Vector2Subtract(mousePos, bullet[i].pos);
					bullet[i].lookDir = Vector2Normalize(bullet[i].lookDir);
					bullet[i].isActive = true;

					break;
				}

			}

		}
	}
	void showPlayerInfo(Player player)
	{
		DrawText(TextFormat("Puntos: %i", player.points), 10, 10, 30, WHITE);
		DrawText(TextFormat("Vidas: %i", player.lives), 200, 10, 30, WHITE);
	}



	void loadPlayerAssets()
	{
		playerTexture = LoadTexture("res/player.png");
		shootSound = LoadSound("res/shoot.wav");
		deadSound = LoadSound("res/death.wav");
	}

	void unloadPlayerAssets()
	{
		UnloadTexture(playerTexture);
		UnloadSound(shootSound);
		UnloadSound(deadSound);
	}
}
