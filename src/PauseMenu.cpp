#include "PauseMenu.h"
#include "Button.h"
#include "Const.h"
#include <raylib.h>

namespace asteroids
{
	void showPauseMenu(Screen& actualScreen, Player& player)
	{
		Button exitButton;

		exitButton.width = 200;
		exitButton.high = 50;
		exitButton.x = screenWidth / 2 - exitButton.width / 2;
		exitButton.y = (screenHigh / 4 - exitButton.high / 2) + (exitButton.high + buttonsOffset) * 3;
		exitButton.text = "EXIT";

		if (onClick(exitButton))
		{
			actualScreen = Screen::MAIN_MENU;
		}
		if (player.points > player.highScore)
		{
			DrawText(TextFormat("NEW HIGHSCORE: %i", player.highScore), screenWidth / 2 - MeasureText("PERDISTE", 50) / 2, screenHigh / 3 + 20, 50, WHITE);
		}
		else
		{
			DrawText(TextFormat("HIGHSCORE: %i", player.highScore), screenWidth / 2 - MeasureText("PERDISTE", 50) / 2, screenHigh / 3 + 20, 50, WHITE);
		}


		BeginDrawing();

		DrawRectangle(exitButton.x, exitButton.y, exitButton.width, exitButton.high, RED);
		DrawText(exitButton.text.c_str(), exitButton.x + (exitButton.width - MeasureText(exitButton.text.c_str(), fontButtons)) / 2, exitButton.y + (exitButton.high - fontButtons) / 2, fontButtons, RAYWHITE);

		EndDrawing();
	}
}