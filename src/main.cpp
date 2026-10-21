#include <raylib.h>
#include "ScreenManager.h"
#include <iostream>
#include <time.h>
using namespace asteroids;
int main()
{
	srand(static_cast<unsigned int>(time(0)));
	Screen actualScreen = Screen::MAIN_MENU;
	bool inGame = true;

	showScreen(actualScreen,inGame);

	return 0;
}