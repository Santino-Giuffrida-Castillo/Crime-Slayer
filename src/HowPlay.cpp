#include "HowPlay.h"

#include <raylib.h>

#include "Button.h"

namespace asteroids
{
    void showHowPlay(Screen& actualScreen, Font font)
    {
        // Configura el boton para volver al menu principal.
        Button exitButton;

        exitButton.width = 200;
        exitButton.high = 50;
        exitButton.x = screenWidth / 2 - exitButton.width / 2;
        exitButton.y = (screenHigh / 4 - exitButton.high / 2) + (exitButton.high + buttonsOffset) * 3;
        exitButton.text = "SALIR";

        // Define las instrucciones del juego.
        const char* instruction1 = "Destruye los asteroides y sobrevive!";
        const char* instruction2 = "CLICK IZQUIERDO: Disparar";
        const char* instruction3 = "CLICK DERECHO: Moverse";
        const char* instruction4 = "CLICK DEL MEDIO: Pausa";

        // Define el tamano y el espaciado de la fuente.
        float instructionFontSize = 22.0f;
        float spacing = 1.0f;

        // Comprueba si se hizo clic en EXIT.
        if (onClick(exitButton))
        {
            actualScreen = Screen::MAIN_MENU;
        }

        // Dibuja el titulo de la pantalla.
        const char* title = "COMO JUGAR";
        float titleFontSize = 45.0f;

        Vector2 titleSize = MeasureTextEx(
            font,
            title,
            titleFontSize,
            spacing
        );

        DrawTextEx(
            font,
            title,
            {
                screenWidth / 2.0f - titleSize.x / 2.0f,
                50.0f
            },
            titleFontSize,
            spacing,
            RED
        );

        // Calcula el tamano de cada instruccion.
        Vector2 instruction1Size = MeasureTextEx(font, instruction1, instructionFontSize, spacing);
        Vector2 instruction2Size = MeasureTextEx(font, instruction2, instructionFontSize, spacing);
        Vector2 instruction3Size = MeasureTextEx(font, instruction3, instructionFontSize, spacing);
        Vector2 instruction4Size = MeasureTextEx(font, instruction4, instructionFontSize, spacing);

        // Dibuja la descripcion del objetivo.
        DrawTextEx(
            font,
            instruction1,
            { screenWidth / 2.0f - instruction1Size.x / 2.0f, 150.0f },
            instructionFontSize,
            spacing,
            RAYWHITE
        );

        // Dibuja el control para disparar.
        DrawTextEx(
            font,
            instruction2,
            { screenWidth / 2.0f - instruction2Size.x / 2.0f, 220.0f },
            instructionFontSize,
            spacing,
            RAYWHITE
        );

        // Dibuja el control para moverse.
        DrawTextEx(
            font,
            instruction3,
            { screenWidth / 2.0f - instruction3Size.x / 2.0f, 270.0f },
            instructionFontSize,
            spacing,
            RAYWHITE
        );

        // Dibuja el control para pausar.
        DrawTextEx(
            font,
            instruction4,
            { screenWidth / 2.0f - instruction4Size.x / 2.0f, 320.0f },
            instructionFontSize,
            spacing,
            RAYWHITE
        );

        // Dibuja el boton EXIT.
        DrawRectangle(
            exitButton.x,
            exitButton.y,
            exitButton.width,
            exitButton.high,
            RED
        );

        // Calcula el tamano del texto del boton.
        Vector2 exitTextSize = MeasureTextEx(
            font,
            exitButton.text.c_str(),
            (float)fontButtons,
            spacing
        );

        // Centra el texto dentro del boton.
        DrawTextEx(
            font,
            exitButton.text.c_str(),
            {
                exitButton.x + (exitButton.width - exitTextSize.x) / 2.0f,
                exitButton.y + (exitButton.high - exitTextSize.y) / 2.0f
            },
            (float)fontButtons,
            spacing,
            RAYWHITE
        );
    }
}