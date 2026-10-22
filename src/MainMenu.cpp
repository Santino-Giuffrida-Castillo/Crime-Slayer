#include "MainMenu.h"

#include <iostream>

#include <raylib.h>

#include "Button.h"


namespace asteroids
{
	void showMainMenu(Screen& actualScreen)
	{
		Button playButton;
		Button howPlayButton;
		Button creditsButton;
		Button exitButton;


		playButton.width = 200;
		playButton.high = 50;
		playButton.x = screenWidth / 2 - playButton.width / 2;
		playButton.y = screenHigh / 4 - playButton.high / 2;
		playButton.text = "PLAY";

		howPlayButton.width = 200;
		howPlayButton.high = 50;
		howPlayButton.x = screenWidth / 2 - howPlayButton.width / 2;
		howPlayButton.y = (screenHigh / 4 - howPlayButton.high / 2) + playButton.high + buttonsOffset;
		howPlayButton.text = "HOW PLAY?";

		creditsButton.width = 200;
		creditsButton.high = 50;
		creditsButton.x = screenWidth / 2 - creditsButton.width / 2;
		creditsButton.y = (screenHigh / 4 - creditsButton.high / 2) + (playButton.high + buttonsOffset) * 2;
		creditsButton.text = "CREDITS";

		exitButton.width = 200;
		exitButton.high = 50;
		exitButton.x = screenWidth / 2 - exitButton.width / 2;
		exitButton.y = (screenHigh / 4 - exitButton.high / 2) + (playButton.high + buttonsOffset) * 3;
		exitButton.text = "EXIT";

		if (onClick(playButton))
		{
			actualScreen = Screen::PLAY;
		}
		else if (onClick(howPlayButton))
		{
			actualScreen = Screen::HOW_PLAY;
		}
		else if (onClick(creditsButton))
		{
			actualScreen = Screen::CREDITS;
		}
		else if (onClick(exitButton))
		{
			actualScreen = Screen::EXIT;
		}
		BeginDrawing();

		DrawRectangle(playButton.x, playButton.y, playButton.width, playButton.high, RED);
		DrawText(playButton.text.c_str(), playButton.x + (playButton.width - MeasureText(playButton.text.c_str(), fontButtons)) / 2, playButton.y + (playButton.high - fontButtons) / 2, fontButtons, RAYWHITE);

		DrawRectangle(howPlayButton.x, howPlayButton.y, howPlayButton.width, howPlayButton.high, RED);
		DrawText(howPlayButton.text.c_str(), howPlayButton.x + (howPlayButton.width - MeasureText(howPlayButton.text.c_str(), fontButtons)) / 2, howPlayButton.y + (howPlayButton.high - fontButtons) / 2, fontButtons, RAYWHITE);

		DrawRectangle(creditsButton.x, creditsButton.y, creditsButton.width, creditsButton.high, RED);
		DrawText(creditsButton.text.c_str(), creditsButton.x + (creditsButton.width - MeasureText(creditsButton.text.c_str(), fontButtons)) / 2, creditsButton.y + (creditsButton.high - fontButtons) / 2, fontButtons, RAYWHITE);

		DrawRectangle(exitButton.x, exitButton.y, exitButton.width, exitButton.high, RED);
		DrawText(exitButton.text.c_str(), exitButton.x + (exitButton.width - MeasureText(exitButton.text.c_str(), fontButtons)) / 2, exitButton.y + (exitButton.high - fontButtons) / 2, fontButtons, RAYWHITE);
		EndDrawing();

	}
}