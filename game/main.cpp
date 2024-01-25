//cmake -G "MinGW Makefiles" .
//cmake --build .
//game\game.exe
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <SFML/Window.hpp>
#include "store.cpp"
#include "assets.cpp"
#include "highScores.cpp"
#include "game.h"
#include "menu.h"
#include "inputPlayerName.h"

int main()
{
    loadAssets();
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Game", sf::Style::Default, settings);

    bool game = true;
    while (game)
    {
        switch (gameState)
        {
        case menu_screen:
            menu(window);
            break;
        case input_name:
            getPlayerName(window);
            break;
        case high_scores:
            showHighScores(window);
            break;
        case start_game:
            playGame(window);
            break;
        case quit:
            game = !game;
            window.close();
        }
    }
}