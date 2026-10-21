#pragma once
#include <iostream>
namespace asteroids
{
	struct Button
	{
		int x;
		int y;
		int width;
		int high;
		std::string text;
	};

	bool onClick(Button button);
}