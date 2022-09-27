/*!
 * \file    main.cpp
 * \brief   start SFML in full screen and display a sprite (http://www.lucidarme.me/?p=6127)
 * \author  Philippe Lucidarme
 * \version 1.0
 * \date    12/18/2016
 */

// SFML libraries
#include <SFML/Graphics.hpp>
#include <iostream>

int wWinMain()
{
    // _____________________
    // ::: Create window :::

    // Create a window with the same pixel depth as the desktop
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

    sf::RenderWindow window(sf::VideoMode(  desktopMode.width,
                                            desktopMode.height,
                                            desktopMode.bitsPerPixel),
                            "SFML part 3",
                            sf::Style::Fullscreen);


    // Enable vertical sync. (vsync)
    window.setVerticalSyncEnabled (true);

    // _________________
    // ::: Load font :::

    sf::Font font;
    if (!font.loadFromFile("example_font.ttf"))
    {
        std::cerr << ".Error while loading font" << std::endl;
        return -1;
    }

    sf::Text text;
    text.setFont(font); // font est un sf::Font
    text.setString(L"www.lucidarme.me");
    text.setCharacterSize(60); // exprimée en pixels, pas en points !
    text.setFillColor(sf::Color::Black);
    text.setOrigin(text.getLocalBounds().width/2. , text.getLocalBounds().height/2.);

    std::cout << text.getLocalBounds().width << "\t" << text.getLocalBounds().height;
    // _________________
    // ::: Main loop :::

    sf::Clock timer;
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close the window if a key is pressed or if requested
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::KeyPressed) window.close();
        }

        // Clear the window and apply grey background
        window.clear( sf::Color(127,127,127));
        text.setPosition(window.getSize().x/2. , window.getSize().y/2.);
        window.draw(text);
        // Update display and wait for vsync
        window.display();
    }
    return 0;
}

