#include <SFML/Graphics.hpp>
//#include <cmath>
#include <fstream>
#include <iostream>
//#include <list>
#include <SFML/Window.hpp>
//#include <vector>
//#include <conio.h>
//#include <string>
// #include "store.cpp"
// #include "globalVars.cpp"
// #include "assets.cpp"
// #include "highScores.cpp"
// #include "game.h"
// #include "splashScreen.h"
//#include "menu.h"
// #include "inputName.h"

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;
std::string playerName = "";
int level = 1;
int scores;
std::string highScoresStr;

enum states
{
    menu_screen,
    input_name,
    start_game,
    // playing,
    // level_lost,
    // level_lost_modal,
    quit,
    high_scores,
    // level_passed
};

states gameState = menu_screen;
const int menuItemsNumber = 3;
int selectedMenuItem;
sf::Text menuItems[menuItemsNumber];

void returnPressedHandle()
{
    switch (selectedMenuItem)
    {
    case 0:
        gameState = input_name;
        break;
    case 1:
        gameState = high_scores;
        break;
    case 2:
        gameState = quit;
        break;
    }
}

void moveUp(sf::Text menuItems[])
{
    if (selectedMenuItem - 1 >= 0)
    {
        menuItems[selectedMenuItem].setFillColor(sf::Color::Yellow);
        menuItems[selectedMenuItem].setStyle(sf::Text::Regular);
        selectedMenuItem--;
        menuItems[selectedMenuItem].setFillColor(sf::Color::Red);

        menuItems[selectedMenuItem].setStyle(sf::Text::Bold | sf::Text::Underlined);
    }
}

void moveDown(sf::Text menuItems[])
{
    if (selectedMenuItem + 1 < menuItemsNumber)
    {
        menuItems[selectedMenuItem].setFillColor(sf::Color::Yellow);
        menuItems[selectedMenuItem].setStyle(sf::Text::Regular);
        selectedMenuItem++;
        menuItems[selectedMenuItem].setFillColor(sf::Color::Red);
        menuItems[selectedMenuItem].setStyle(sf::Text::Bold | sf::Text::Underlined);
    }
}

void drawMenuItems(sf::RenderWindow &window, sf::Text menuItems[])
{
    for (int i = 0; i < menuItemsNumber; i++)
    {
        window.draw(menuItems[i]);
    }
}

void createMenu(const float windowWidth, const float windowHeight)
{
    std::string menuItemsStrings[menuItemsNumber] = {"Игра", "Результаты", "Выход"};
    for (int i = 0; i < menuItemsNumber; i++)
    {
        menuItems[i].setFillColor(sf::Color::Yellow);
        //menuItems[i].setFont(getFont());
        menuItems[i].setString(menuItemsStrings[i]);
        menuItems[i].setPosition({x : windowWidth / 3, y : windowHeight / (menuItemsNumber + 1) * (i + 1)});
    }
    menuItems[0].setFillColor(sf::Color::Red);
    menuItems[0].setStyle(sf::Text::Bold | sf::Text::Underlined);
}

void menuPollEvents(sf::RenderWindow &window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::KeyReleased:
            switch (event.key.code)
            {
            case sf::Keyboard::Up:
                moveUp(menuItems);
                break;
            case sf::Keyboard::Down:
                moveDown(menuItems);
                break;
            case sf::Keyboard::Return:
                returnPressedHandle();
                break;
            }
            break;
        case sf::Event::Closed:
            gameState = quit;
            break;
        }
    }
}

void menu(sf::RenderWindow &window)
{
    //const float windowWidth = static_cast<float>(WINDOW_WIDTH);
    //const float windowHeight = static_cast<float>(WINDOW_HEIGHT);
    selectedMenuItem = 0;
    sf::Texture backgroundMenuTexture;
    backgroundMenuTexture.loadFromFile("game/images/backgrMenu.jpg");
    sf::Sprite background;
    background.setTexture(backgroundMenuTexture);
    createMenu(WINDOW_WIDTH, WINDOW_HEIGHT);

    while (window.isOpen())
    {
        menuPollEvents(window);
        window.clear();
        window.draw(background);
        drawMenuItems(window, menuItems);
        window.display();
        if (
            gameState == input_name ||
            gameState == high_scores ||
            gameState == quit)
            return;
    }
}

int main()
{
    //loadAssets();
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
            //getPlayerName(window);
            break;
        case start_game:
            //playGame(window);
            break;
        case high_scores:
            //showHighScores(window);
            break;
        case quit:
            game = !game;
            window.close();
        }
    }
}