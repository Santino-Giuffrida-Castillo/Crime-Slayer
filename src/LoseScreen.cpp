#include "LoseScreen.h"

#include <raylib.h>

#include "Button.h"

namespace asteroids
{
    void showLoseScreen(Screen& actualScreen, Player& player, Font font)
    {
        // Configura el boton para volver al menu principal.
        Button exitButton;

        exitButton.width = 200;
        exitButton.high = 50;
        exitButton.x = screenWidth / 2 - exitButton.width / 2;
        exitButton.y = (screenHigh / 4 - exitButton.high / 2) + (exitButton.high + buttonsOffset) * 3;
        exitButton.text = "EXIT";

        // Define el espaciado de la fuente.
        float spacing = 1.0f;

        // Define el titulo de la pantalla de derrota.
        const char* loseTitle = "PERDISTE";
        float loseTitleFontSize = 100.0f;

        // Calcula el tamano del titulo.
        Vector2 loseTitleSize = MeasureTextEx(
            font,
            loseTitle,
            loseTitleFontSize,
            spacing
        );

        // Dibuja el titulo centrado.
        DrawTextEx(
            font,
            loseTitle,
            {
                screenWidth / 2.0f - loseTitleSize.x / 2.0f,
                screenHigh / 4.0f
            },
            loseTitleFontSize,
            spacing,
            WHITE
        );

        // Comprueba si se hizo clic en EXIT.
        if (onClick(exitButton))
        {
            actualScreen = Screen::MAIN_MENU;
        }

        // Prepara el texto del record del jugador.
        const char* highScoreText;

        if (player.points > player.highScore)
        {
            highScoreText = TextFormat("NEW HIGHSCORE: %i", player.points);
        }
        else
        {
            highScoreText = TextFormat("HIGHSCORE: %i", player.highScore);
        }

        // Define el tamano del texto del record.
        float highScoreFontSize = 40.0f;

        // Calcula el tamano real del texto del record.
        Vector2 highScoreTextSize = MeasureTextEx(
            font,
            highScoreText,
            highScoreFontSize,
            spacing
        );

        // Dibuja el record centrado.
        DrawTextEx(
            font,
            highScoreText,
            {
                screenWidth / 2.0f - highScoreTextSize.x / 2.0f,
                screenHigh / 3.0f + 20.0f
            },
            highScoreFontSize,
            spacing,
            WHITE
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