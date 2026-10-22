#pragma once
namespace asteroids
{
	const int screenWidth = 1024;
	const int screenHigh = 768;
	enum class Screen
	{
		none = 0,
		MAIN_MENU,
		PLAY,
		HOW_PLAY,
		CREDITS,
		LOOSE,
		PAUSE,
		EXIT
	};
}