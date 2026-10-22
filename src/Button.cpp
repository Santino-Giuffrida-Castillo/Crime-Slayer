#include "Button.h"

#include <raylib.h>
namespace asteroids
{
	bool onClick(Button button)
	{
		int mouseX = 0;
		int mouseY = 0;
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			mouseX = GetMouseX();
			mouseY = GetMouseY();
			if (mouseX >= (button.x) && mouseX <= (button.x + button.width))
			{
				if (mouseY >= (button.y) && mouseY <= (button.y + button.high))
				{
					return true;
				}
			}
		}
		return false;
	}
}