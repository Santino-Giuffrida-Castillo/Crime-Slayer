#include "PauseMenu.h"

#include <raylib.h>

#include "Button.h"
#include "Screen.h"

namespace asteroids
{
	void showPauseMenu(Screen& actualScreen)
	{
		Button exitButton;
		Button continueButton;

		exitButton.width = 200;
		exitButton.high = 50;
		exitButton.x = screenWidth / 2 - exitButton.width / 2;
		exitButton.y = (screenHigh / 4 - exitButton.high / 2) + (exitButton.high + buttonsOffset) * 3;
		exitButton.text = "EXIT";

		continueButton.width = 200;
		continueButton.high = 50;
		continueButton.x = screenWidth / 2 - exitButton.width / 2;
		continueButton.y = (screenHigh / 4 - exitButton.high / 2) + (exitButton.high + buttonsOffset) * 2;
		continueButton.text = "CONTINUE";

		if (onClick(exitButton))
		{
			actualScreen = Screen::MAIN_MENU;
		}

		if (onClick(continueButton))
		{
			actualScreen = Screen::PLAY;
		}





		DrawRectangle(exitButton.x, exitButton.y, exitButton.width, exitButton.high, RED);
		DrawText(exitButton.text.c_str(), exitButton.x + (exitButton.width - MeasureText(exitButton.text.c_str(), fontButtons)) / 2, exitButton.y + (exitButton.high - fontButtons) / 2, fontButtons, RAYWHITE);

		DrawRectangle(continueButton.x, continueButton.y, continueButton.width, continueButton.high, RED);
		DrawText(continueButton.text.c_str(), continueButton.x + (continueButton.width - MeasureText(continueButton.text.c_str(), fontButtons)) / 2, continueButton.y + (continueButton.high - fontButtons) / 2, fontButtons, RAYWHITE);


	}
}