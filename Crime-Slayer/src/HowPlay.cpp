#include "HowPlay.h"

#include <raylib.h>

#include "Button.h"
namespace asteroids
{
	void showHowPlay(Screen& actualScreen)
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


		DrawRectangle(exitButton.x, exitButton.y, exitButton.width, exitButton.high, RED);
		DrawText(exitButton.text.c_str(), exitButton.x + (exitButton.width - MeasureText(exitButton.text.c_str(), fontButtons)) / 2, exitButton.y + (exitButton.high - fontButtons) / 2, fontButtons, RAYWHITE);

	}
}