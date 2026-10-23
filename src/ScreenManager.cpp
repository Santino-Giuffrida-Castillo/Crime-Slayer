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
		Font font = LoadFont("res/font.ttf");
		Player player;
		Bullet bullets[maxBullets];
		BigAsteroid asteroids[MAX_ASTEROIDS];
		float count = 0;
		InitAudioDevice();
		Music menuMusic = LoadMusicStream("res/menu.wav");
		Music gameplayMusic = LoadMusicStream("res/gameplay.wav");

		SetMusicVolume(menuMusic, 0.4f);
		SetMusicVolume(gameplayMusic, 0.3f);
		Texture2D background = LoadTexture("res/background.png");

		loadPlayerAssets();
		loadAsteroidTextures();
		loadAsteroidSounds();
		Screen previousScreen = Screen::EXIT;

		initGame(player, bullets, asteroids);

		while (!WindowShouldClose() && inGame)
		{
			if (actualScreen != previousScreen)
			{
				StopMusicStream(menuMusic);
				StopMusicStream(gameplayMusic);

				if (actualScreen == Screen::MAIN_MENU)
				{
					PlayMusicStream(menuMusic);
				}
				else if (actualScreen == Screen::PLAY)
				{
					PlayMusicStream(gameplayMusic);
				}

				previousScreen = actualScreen;
			}

			BeginDrawing();
			if (actualScreen == Screen::MAIN_MENU)
			{
				if (actualScreen == Screen::MAIN_MENU)
				{
					UpdateMusicStream(menuMusic);
				}
				else if (actualScreen == Screen::PLAY)
				{
					UpdateMusicStream(gameplayMusic);
				}

				ClearBackground(BLACK);
				initGame(player, bullets, asteroids);
				showMainMenu(actualScreen, font);
			}
			else if (actualScreen == Screen::PLAY)
			{
				if (actualScreen == Screen::MAIN_MENU)
				{
					UpdateMusicStream(menuMusic);
				}
				else if (actualScreen == Screen::PLAY)
				{
					UpdateMusicStream(gameplayMusic);
				}

				playGame(player, bullets, asteroids, count, actualScreen, background);
				count += GetFrameTime();
			}
			else if (actualScreen == Screen::HOW_PLAY)
			{
				if (actualScreen == Screen::MAIN_MENU)
				{
					UpdateMusicStream(menuMusic);
				}
				else if (actualScreen == Screen::PLAY)
				{
					UpdateMusicStream(gameplayMusic);
				}

				ClearBackground(BLACK);
				showHowPlay(actualScreen, font);
			}
			else if (actualScreen == Screen::CREDITS)
			{
				if (actualScreen == Screen::MAIN_MENU)
				{
					UpdateMusicStream(menuMusic);
				}
				else if (actualScreen == Screen::PLAY)
				{
					UpdateMusicStream(gameplayMusic);
				}

				ClearBackground(BLACK);
				showCredits(actualScreen, font);
			}
			else if (actualScreen == Screen::EXIT)
			{
				inGame = false;
			}
			else if (actualScreen == Screen::LOOSE)
			{
				if (actualScreen == Screen::MAIN_MENU)
				{
					UpdateMusicStream(menuMusic);
				}
				else if (actualScreen == Screen::PLAY)
				{
					UpdateMusicStream(gameplayMusic);
				}
				ClearBackground(BLACK);
				showLoseScreen(actualScreen, player, font);

			}
			else if (actualScreen == Screen::PAUSE)
			{
				if (actualScreen == Screen::MAIN_MENU)
				{
					UpdateMusicStream(menuMusic);
				}
				else if (actualScreen == Screen::PLAY)
				{
					UpdateMusicStream(gameplayMusic);
				}

				ClearBackground(BLACK);
				showPauseMenu(actualScreen, font);
			}
			EndDrawing();
		}

		unloadAsteroidSounds();
		unloadPlayerAssets();
		unloadAsteroidTextures();
		UnloadTexture(background);
		UnloadMusicStream(menuMusic);
		UnloadMusicStream(gameplayMusic);
		UnloadFont(font);
		CloseAudioDevice();
		CloseWindow();
	}
}