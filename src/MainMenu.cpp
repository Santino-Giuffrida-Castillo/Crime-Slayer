#include "MainMenu.h"

#include <raylib.h>

#include "Button.h"

namespace asteroids
{
    void showMainMenu(Screen& actualScreen, Font font)
    {
        // Crea los botones del menu principal.
        Button playButton;
        Button howPlayButton;
        Button creditsButton;
        Button exitButton;

        // Define el titulo del juego.
        const char* title = "CRIME-SLAYER";
        float titleFontSize = 60.0f;
        float spacing = 1.0f;

        // Calcula el tamano del titulo usando la fuente personalizada.
        Vector2 titleSize = MeasureTextEx(
            font,
            title,
            titleFontSize,
            spacing
        );

        // Calcula la posicion para centrar el titulo.
        float titleX = screenWidth / 2.0f - titleSize.x / 2.0f;
        float titleY = 50.0f;

        // Configura el boton PLAY.
        playButton.width = 200;
        playButton.high = 50;
        playButton.x = screenWidth / 2 - playButton.width / 2;
        playButton.y = screenHigh / 4 - playButton.high / 2;
        playButton.text = "JUGAR";

        // Configura el boton HOW PLAY.
        howPlayButton.width = 200;
        howPlayButton.high = 50;
        howPlayButton.x = screenWidth / 2 - howPlayButton.width / 2;
        howPlayButton.y = (screenHigh / 4 - howPlayButton.high / 2) + playButton.high + buttonsOffset;
        howPlayButton.text = "COMO JUGAR?";

        // Configura el boton CREDITS.
        creditsButton.width = 200;
        creditsButton.high = 50;
        creditsButton.x = screenWidth / 2 - creditsButton.width / 2;
        creditsButton.y = (screenHigh / 4 - creditsButton.high / 2) + (playButton.high + buttonsOffset) * 2;
        creditsButton.text = "CREDITOS";

        // Configura el boton EXIT.
        exitButton.width = 200;
        exitButton.high = 50;
        exitButton.x = screenWidth / 2 - exitButton.width / 2;
        exitButton.y = (screenHigh / 4 - exitButton.high / 2) + (playButton.high + buttonsOffset) * 3;
        exitButton.text = "SALIR";

        // Comprueba si se hizo clic en alguno de los botones.
        if (onClick(playButton))
        {
            actualScreen = Screen::PLAY;
        }
        else if (onClick(howPlayButton))
        {
            actualScreen = Screen::HOW_PLAY;
        }
        else if (onClick(creditsButton))
        {
            actualScreen = Screen::CREDITS;
        }
        else if (onClick(exitButton))
        {
            actualScreen = Screen::EXIT;
        }

        // Define el tamano de los textos de los botones.
        float buttonFontSize = (float)fontButtons;

        // Dibuja el boton PLAY.
        DrawRectangle(
            playButton.x,
            playButton.y,
            playButton.width,
            playButton.high,
            RED
        );

        // Calcula y centra el texto PLAY.
        Vector2 playTextSize = MeasureTextEx(font, playButton.text.c_str(), buttonFontSize, spacing);

        DrawTextEx(
            font,
            playButton.text.c_str(),
            {
                playButton.x + (playButton.width - playTextSize.x) / 2.0f,
                playButton.y + (playButton.high - playTextSize.y) / 2.0f
            },
            buttonFontSize,
            spacing,
            RAYWHITE
        );

        // Dibuja el boton HOW PLAY.
        DrawRectangle(
            howPlayButton.x,
            howPlayButton.y,
            howPlayButton.width,
            howPlayButton.high,
            RED
        );

        // Calcula y centra el texto HOW PLAY.
        Vector2 howPlayTextSize = MeasureTextEx(font, howPlayButton.text.c_str(), buttonFontSize, spacing);

        DrawTextEx(
            font,
            howPlayButton.text.c_str(),
            {
                howPlayButton.x + (howPlayButton.width - howPlayTextSize.x) / 2.0f,
                howPlayButton.y + (howPlayButton.high - howPlayTextSize.y) / 2.0f
            },
            buttonFontSize,
            spacing,
            RAYWHITE
        );

        // Dibuja el boton CREDITS.
        DrawRectangle(
            creditsButton.x,
            creditsButton.y,
            creditsButton.width,
            creditsButton.high,
            RED
        );

        // Calcula y centra el texto CREDITS.
        Vector2 creditsTextSize = MeasureTextEx(font, creditsButton.text.c_str(), buttonFontSize, spacing);

        DrawTextEx(
            font,
            creditsButton.text.c_str(),
            {
                creditsButton.x + (creditsButton.width - creditsTextSize.x) / 2.0f,
                creditsButton.y + (creditsButton.high - creditsTextSize.y) / 2.0f
            },
            buttonFontSize,
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

        // Calcula y centra el texto EXIT.
        Vector2 exitTextSize = MeasureTextEx(font, exitButton.text.c_str(), buttonFontSize, spacing);

        DrawTextEx(
            font,
            exitButton.text.c_str(),
            {
                exitButton.x + (exitButton.width - exitTextSize.x) / 2.0f,
                exitButton.y + (exitButton.high - exitTextSize.y) / 2.0f
            },
            buttonFontSize,
            spacing,
            RAYWHITE
        );

        // Dibuja el titulo del juego.
        DrawTextEx(
            font,
            title,
            { titleX, titleY },
            titleFontSize,
            spacing,
            RED
        );
    }
}