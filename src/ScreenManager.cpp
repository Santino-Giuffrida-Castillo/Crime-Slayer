#include "ScreenManager.h"
#include <raylib.h>
#include "MainMenu.h"
#include "HowPlay.h"
#include "Credits.h"
#include "Game.h"
#include "Const.h"
#include "Asteroid.h"

void showScreen(Screen& actualScreen, bool& inGame)
{
	InitWindow(screenWidth, screenHigh, "Crime-Slayer");
	Player player;
	Bullet bullets[maxBullets];
	BigAsteroid asteroids[maxBullets];
	float count = 0;

	initGame(player, bullets, asteroids);

	while (!WindowShouldClose() && inGame)
	{

		if (actualScreen == Screen::MAIN_MENU)
		{
			ClearBackground(BLACK);
			showMainMenu(actualScreen);
		}
		else if (actualScreen == Screen::PLAY)
		{
			ClearBackground(BLACK);
			playGame(player, bullets, asteroids, count);
			count += GetFrameTime();
		}
		else if (actualScreen == Screen::HOW_PLAY)
		{
			ClearBackground(BLACK);
			showHowPlay(actualScreen);
		}
		else if (actualScreen == Screen::CREDITS)
		{
			ClearBackground(BLACK);
			showCredits(actualScreen);
		}
		else if (actualScreen == Screen::EXIT)
		{
			inGame = false;
		}
	}
	CloseWindow();
}