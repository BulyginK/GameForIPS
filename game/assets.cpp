sf::Texture platformTexture;
sf::Texture brickTexture;
sf::Texture ballTexture;
sf::Texture playerTexture;
sf::Texture highScoresTexture;
sf::Texture trophyTexture;
sf::Texture backgroundMainTexture;
sf::Texture backgroundMenuTexture;
sf::Texture expandPlatformTexture;
sf::Texture slowBallDownTexture;
sf::Texture accelerateBallTexture;
sf::Texture extraLifeTexture;
sf::Texture portalDoorTexture;
sf::Texture stickyBallTexture;
sf::Texture sapphireTexture;
sf::Texture rubyTexture;
sf::Texture stoneCrackedTexture;
sf::Font font;

void loadAssets()
{
    platformTexture.loadFromFile("images/platform.png");
    ballTexture.loadFromFile("images/ball.png");
    brickTexture.loadFromFile("images/brick.png");
    playerTexture.loadFromFile("images/player.png");
    highScoresTexture.loadFromFile("images/high-score.png");
    backgroundMainTexture.loadFromFile("images/backgroundMain.png");
    backgroundMenuTexture.loadFromFile("images/backgrMenu.png");
    expandPlatformTexture.loadFromFile("images/expand.png");
    slowBallDownTexture.loadFromFile("images/snail.png");
    accelerateBallTexture.loadFromFile("images/acceleration.png");
    extraLifeTexture.loadFromFile("images/heart.png");
    portalDoorTexture.loadFromFile("images/door.png");
    stickyBallTexture.loadFromFile("images/duct-tape.png");
    sapphireTexture.loadFromFile("images/sapphire.png");
    stoneCrackedTexture.loadFromFile("images/emerald_cracked.png");
    rubyTexture.loadFromFile("images/ruby.png");
    font.loadFromFile("game/Brownwoodnf.ttf");
}

sf::Texture &getPlatformTexture()
{
    return platformTexture;
}

sf::Texture &getBrickTexture()
{
    return brickTexture;
}

sf::Texture &getBallTexture()
{
    return ballTexture;
}

sf::Texture &getPlayerTexture()
{
    return playerTexture;
}

sf::Texture &getHighScoresTexture()
{
    return highScoresTexture;
}

sf::Texture &getBackgroundMainTexture()
{
    return backgroundMainTexture;
}

sf::Texture &getBackgroundMenuTexture()
{
    return backgroundMenuTexture;
}

sf::Texture &getExpandPlatformTexture()
{
    return expandPlatformTexture;
}

sf::Texture &getSlowBallDownTexture()
{
    return slowBallDownTexture;
}

sf::Texture &getAccelerateBallTexture()
{
    return accelerateBallTexture;
}

sf::Texture &getExtraLifeTexture()
{
    return extraLifeTexture;
}

sf::Texture &getPortalDoorTexture()
{
    return portalDoorTexture;
}

sf::Texture &getStickyBallTexture()
{
    return stickyBallTexture;
}

sf::Texture &getSapphireTexture()
{
    return sapphireTexture;
}

sf::Texture &getRubyTexture()
{
    return rubyTexture;
}

sf::Texture &getStoneCrackedTexture()
{
    return stoneCrackedTexture;
}

sf::Font &getFont()
{
    return font;
}

sf::Texture &getPrizeSpriteTexture(PrizeType prizeType)
{
    switch (prizeType)
    {
    case expand_platform:
        return expandPlatformTexture;
    case slow_ball_down:
        return slowBallDownTexture;
    case accelerate_ball:
        return accelerateBallTexture;
    case extra_life:
        return extraLifeTexture;
    case portal_door:
        return portalDoorTexture;
    case sticky_ball:
        return stickyBallTexture;
    }
}

PrizeType getPrizeType(const sf::Texture *texture)
{
    if (texture == &expandPlatformTexture)
        return expand_platform;
    if (texture == &slowBallDownTexture)
        return slow_ball_down;
    if (texture == &accelerateBallTexture)
        return accelerate_ball;
    if (texture == &extraLifeTexture)
        return extra_life;
    if (texture == &portalDoorTexture)
        return portal_door;
    if (texture == &stickyBallTexture)
        return sticky_ball;
}