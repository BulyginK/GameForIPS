#include <string>

void getPlayerName(sf::RenderWindow &window)
{

    if (!playerName.empty())
    {
        gameState = start_game;
        return;
    }
    bool hover = false;
    const int maxNameLength = 10;
    std::string str;

    sf::Text label;
    label.setPosition({x : 230, y : 250});
    label.setFont(getFont());
    label.setFillColor(sf::Color(198, 171, 66));
    label.setString("Enter your name");

    sf::Text plName;
    plName.setPosition({x : 245, y : 315});
    plName.setFont(getFont());
    plName.setFillColor(sf::Color::Black);
    plName.setString("");

    sf::RectangleShape inputFieldBorder;
    inputFieldBorder.setSize(sf::Vector2f(330, 70));
    inputFieldBorder.setPosition(230, 300);
    inputFieldBorder.setFillColor(sf::Color(198, 171, 66));

    sf::RectangleShape inputField;
    inputField.setSize(sf::Vector2f(324, 64));
    inputField.setPosition(233, 303);
    inputField.setFillColor(sf::Color::White);

    sf::RectangleShape playButtonBorder;
    playButtonBorder.setSize(sf::Vector2f(121, 56));
    playButtonBorder.setPosition(337, 397);
    playButtonBorder.setFillColor(sf::Color::Red);

    sf::RectangleShape playButton;
    playButton.setSize(sf::Vector2f(115, 50));
    playButton.setPosition(340, 400);
    playButton.setFillColor(sf::Color::White);

    sf::Text playText;
    playText.setPosition({x : 347, y : 405});
    playText.setFont(getFont());
    playText.setFillColor(sf::Color::Black);
    playText.setString("PLAY!");

    sf::Sprite background;
    background.setTexture(getBackgroundMenuTexture());

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::TextEntered:
                if (event.key.code == 8) // backspace
                {
                    if (str.size() > 0)
                    {
                        str.resize(str.size() - 1);
                    }
                    plName.setString(str);
                }
                else if (event.key.code == 13 && !plName.getString().isEmpty()) //enter
                {
                    gameState = start_game;
                    playerName = plName.getString();
                    return;
                }
                else if (event.key.code < 128 && event.key.code != 13) //any other symbol
                {
                    if (str.size() < maxNameLength)
                    {
                        str += static_cast<char>(event.text.unicode);
                    }
                    plName.setString(str);
                }
                break;
            case sf::Event::Closed:
                gameState = quit;
                playerName = plName.getString();
                return;
            }
            (sf::IntRect(350, 400, 115, 50).contains(sf::Mouse::getPosition(window))) ? hover = true : hover = false;
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hover && !plName.getString().isEmpty())
            {
                gameState = start_game;
                playerName = plName.getString();
                return;
            }
        }
        window.clear();
        window.draw(background);
        window.draw(label);
        window.draw(inputFieldBorder);
        window.draw(inputField);
        window.draw(plName);
        if (hover)
        {
            window.draw(playButtonBorder);
        }
        window.draw(playButton);
        window.draw(playText);
        window.display();
    }
}