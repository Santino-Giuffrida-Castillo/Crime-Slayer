#include "PauseMenu.h"

#include <raylib.h>

#include "Button.h"
#include "Screen.h"

namespace asteroids
{
    void showPauseMenu(Screen& actualScreen, Font font)
    {
        // Crea los botones del menu de pausa.
        Button exitButton;
        Button continueButton;

        // Configura el boton EXIT.
        exitButton.width = 200;
        exitButton.high = 50;
        exitButton.x = screenWidth / 2 - exitButton.width / 2;
        exitButton.y = (screenHigh / 4 - exitButton.high / 2) + (exitButton.high + buttonsOffset) * 3;
        exitButton.text = "SALIR";

        // Configura el boton CONTINUE.
        continueButton.width = 200;
        continueButton.high = 50;
        continueButton.x = screenWidth / 2 - continueButton.width / 2;
        continueButton.y = (screenHigh / 4 - continueButton.high / 2) + (continueButton.high + buttonsOffset) * 2;
        continueButton.text = "CONTINUAR";

        // Comprueba si se presiono EXIT.
        if (onClick(exitButton))
        {
            actualScreen = Screen::MAIN_MENU;
        }

        // Comprueba si se presiono CONTINUE.
        if (onClick(continueButton))
        {
            actualScreen = Screen::PLAY;
        }

        // Define el tamano y el espaciado de la fuente.
        float fontSize = (float)fontButtons;
        float spacing = 1.0f;

        // Dibuja el boton EXIT.
        DrawRectangle(
            exitButton.x,
            exitButton.y,
            exitButton.width,
            exitButton.high,
            RED
        );

        // Calcula el tamano del texto EXIT usando la fuente personalizada.
        Vector2 exitTextSize = MeasureTextEx(
            font,
            exitButton.text.c_str(),
            fontSize,
            spacing
        );

        // Centra el texto EXIT dentro del boton.
        DrawTextEx(
            font,
            exitButton.text.c_str(),
            {
                exitButton.x + (exitButton.width - exitTextSize.x) / 2,
                exitButton.y + (exitButton.high - exitTextSize.y) / 2
            },
            fontSize,
            spacing,
            RAYWHITE
        );

        // Dibuja el boton CONTINUE.
        DrawRectangle(
            continueButton.x,
            continueButton.y,
            continueButton.width,
            continueButton.high,
            RED
        );

        // Calcula el tamano del texto CONTINUE usando la fuente personalizada.
        Vector2 continueTextSize = MeasureTextEx(
            font,
            continueButton.text.c_str(),
            fontSize,
            spacing
        );

        // Centra el texto CONTINUE dentro del boton.
        DrawTextEx(
            font,
            continueButton.text.c_str(),
            {
                continueButton.x + (continueButton.width - continueTextSize.x) / 2,
                continueButton.y + (continueButton.high - continueTextSize.y) / 2
            },
            fontSize,
            spacing,
            RAYWHITE
        );
    }
}