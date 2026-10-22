#include "ScreenManager.h"

#include <raylib.h>

#include "MainMenu.h"
#include "HowPlay.h"
#include "Credits.h"
#include "Game.h"
#include "Asteroid.h"
#include "LoseScreen.h"
#include "PauseMenu.h"

namespace asteroids
{

	void showScreen(Screen& actualScreen, bool& inGame)
	{
		InitWindow(screenWidth, screenHigh, "Crime-Slayer");
		Player player;
		Bullet bullets[maxBullets];
		BigAsteroid asteroids[MAX_ASTEROIDS];
		float count = 0;

		initGame(player, bullets, asteroids);

		while (!WindowShouldClose() && inGame)
		{

			if (actualScreen == Screen::MAIN_MENU)
			{
				ClearBackground(BLACK);
				if (player.lives <= 0)
				{
					initGame(player, bullets, asteroids);
				}

				showMainMenu(actualScreen);
			}
			else if (actualScreen == Screen::PLAY)
			{
				playGame(player, bullets, asteroids, count, actualScreen);
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
			else if (actualScreen == Screen::LOOSE)
			{
				ClearBackground(BLACK);
				showLoseScreen(actualScreen, player);

			}
			else if (actualScreen == Screen::PAUSE)
			{
				ClearBackground(BLACK);
				showPauseMenu(actualScreen, player);
			}
		}
		CloseWindow();
	}
}