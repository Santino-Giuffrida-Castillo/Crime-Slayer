#include <raylib.h>
#include "ScreenManager.h"

int main()
{
	Screen actualScreen = Screen::MAIN_MENU;
	bool inGame = true;

	showScreen(actualScreen,inGame);

	return 0;
}