#include "Credits.h"

#include <raylib.h>

#include "Button.h"

namespace asteroids
{
    void showCredits(Screen& actualScreen, Font font)
    {
        // Define el tamano y el espaciado de la fuente.
        float spacing = 1.0f;

        // Configura el boton para volver al menu principal.
        Button exitButton;

        exitButton.width = 200;
        exitButton.high = 50;
        exitButton.x = screenWidth / 2 - exitButton.width / 2 - 110;
        exitButton.y = screenHigh - 90;
        exitButton.text = "SALIR";

        // Configura el boton para visitar itch.io.
        Button itchButton;

        itchButton.width = 200;
        itchButton.high = 50;
        itchButton.x = screenWidth / 2 - itchButton.width / 2 + 110;
        itchButton.y = screenHigh - 90;
        itchButton.text = "MI ITCH.IO";

        // Comprueba si se hizo clic en EXIT.
        if (onClick(exitButton))
        {
            actualScreen = Screen::MAIN_MENU;
        }

        // Obtiene la posicion actual del cursor.
        Vector2 mousePosition = GetMousePosition();

        // Define el area clickeable del boton de itch.io.
        Rectangle itchRectangle = {
            (float)itchButton.x,
            (float)itchButton.y,
            (float)itchButton.width,
            (float)itchButton.high
        };

        // Abre itch.io al hacer clic en el boton.
        if (CheckCollisionPointRec(mousePosition, itchRectangle) &&
            IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            OpenURL("https://santinogiuffrida.itch.io/");
        }

        // Dibuja el titulo de los creditos.
        const char* title = "CREDITOS";
        float titleFontSize = 45.0f;
        Vector2 titleSize = MeasureTextEx(font, title, titleFontSize, spacing);

        DrawTextEx(
            font,
            title,
            { screenWidth / 2.0f - titleSize.x / 2.0f, 30.0f },
            titleFontSize,
            spacing,
            RED
        );

        // Muestra el nombre del programador.
        const char* programmerTitle = "PROGRAMADOR";
        const char* programmerName = "Santino Giuffrida Castillo";

        float sectionFontSize = 24.0f;
        float normalFontSize = 22.0f;

        Vector2 programmerTitleSize = MeasureTextEx(font, programmerTitle, sectionFontSize, spacing);
        Vector2 programmerNameSize = MeasureTextEx(font, programmerName, normalFontSize, spacing);

        DrawTextEx(
            font,
            programmerTitle,
            { screenWidth / 2.0f - programmerTitleSize.x / 2.0f, 110.0f },
            sectionFontSize,
            spacing,
            RED
        );

        DrawTextEx(
            font,
            programmerName,
            { screenWidth / 2.0f - programmerNameSize.x / 2.0f, 145.0f },
            normalFontSize,
            spacing,
            RAYWHITE
        );

        // Muestra la informacion sobre la inteligencia artificial.
        const char* aiTitle = "IMAGENES";
        const char* aiDescription = "Imagenes creadas a base de AI";
        const char* aiModel = "ChatGPT - GPT-6";

        Vector2 aiTitleSize = MeasureTextEx(font, aiTitle, sectionFontSize, spacing);
        Vector2 aiDescriptionSize = MeasureTextEx(font, aiDescription, 18.0f, spacing);
        Vector2 aiModelSize = MeasureTextEx(font, aiModel, 18.0f, spacing);

        DrawTextEx(
            font,
            aiTitle,
            { screenWidth / 2.0f - aiTitleSize.x / 2.0f, 205.0f },
            sectionFontSize,
            spacing,
            RED
        );

        DrawTextEx(
            font,
            aiDescription,
            { screenWidth / 2.0f - aiDescriptionSize.x / 2.0f, 240.0f },
            18.0f,
            spacing,
            RAYWHITE
        );

        DrawTextEx(
            font,
            aiModel,
            { screenWidth / 2.0f - aiModelSize.x / 2.0f, 267.0f },
            18.0f,
            spacing,
            RAYWHITE
        );

        // Muestra la fuente de los efectos de sonido.
        const char* soundTitle = "EFECTOS DE SONIDO";
        const char* soundDescription = "Se uso Bfxr";
        const char* soundLink = "https://www.bfxr.net/";

        Vector2 soundTitleSize = MeasureTextEx(font, soundTitle, sectionFontSize, spacing);
        Vector2 soundDescriptionSize = MeasureTextEx(font, soundDescription, 18.0f, spacing);
        Vector2 soundLinkSize = MeasureTextEx(font, soundLink, 18.0f, spacing);

        DrawTextEx(
            font,
            soundTitle,
            { screenWidth / 2.0f - soundTitleSize.x / 2.0f, 315.0f },
            sectionFontSize,
            spacing,
            RED
        );

        DrawTextEx(
            font,
            soundDescription,
            { screenWidth / 2.0f - soundDescriptionSize.x / 2.0f, 350.0f },
            18.0f,
            spacing,
            RAYWHITE
        );

        // Calcula la posicion del enlace de Bfxr.
        float soundLinkX = screenWidth / 2.0f - soundLinkSize.x / 2.0f;
        float soundLinkY = 375.0f;

        // Dibuja el enlace de Bfxr.
        DrawTextEx(
            font,
            soundLink,
            { soundLinkX, soundLinkY },
            18.0f,
            spacing,
            SKYBLUE
        );

        // Dibuja una linea debajo del enlace.
        DrawLine(
            (int)soundLinkX,
            (int)(soundLinkY + soundLinkSize.y),
            (int)(soundLinkX + soundLinkSize.x),
            (int)(soundLinkY + soundLinkSize.y),
            SKYBLUE
        );

        // Define el area clickeable del enlace de Bfxr.
        Rectangle soundLinkRectangle = {
            soundLinkX,
            soundLinkY,
            soundLinkSize.x,
            soundLinkSize.y
        };

        // Abre Bfxr al hacer clic en el enlace.
        if (CheckCollisionPointRec(mousePosition, soundLinkRectangle) &&
            IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            OpenURL("https://www.bfxr.net/");
        }

        // Cambia el cursor al pasar sobre los enlaces.
        if (CheckCollisionPointRec(mousePosition, itchRectangle) ||
            CheckCollisionPointRec(mousePosition, soundLinkRectangle))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        }
        else
        {
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        }

        // Dibuja el boton EXIT.
        DrawRectangle(
            exitButton.x,
            exitButton.y,
            exitButton.width,
            exitButton.high,
            RED
        );

        // Calcula y centra el texto del boton EXIT.
        Vector2 exitTextSize = MeasureTextEx(
            font,
            exitButton.text.c_str(),
            (float)fontButtons,
            spacing
        );

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

        // Dibuja el boton MY ITCH.IO.
        DrawRectangle(
            itchButton.x,
            itchButton.y,
            itchButton.width,
            itchButton.high,
            RED
        );

        // Calcula y centra el texto del boton MY ITCH.IO.
        Vector2 itchTextSize = MeasureTextEx(
            font,
            itchButton.text.c_str(),
            (float)fontButtons,
            spacing
        );

        DrawTextEx(
            font,
            itchButton.text.c_str(),
            {
                itchButton.x + (itchButton.width - itchTextSize.x) / 2.0f,
                itchButton.y + (itchButton.high - itchTextSize.y) / 2.0f
            },
            (float)fontButtons,
            spacing,
            RAYWHITE
        );
    }
}