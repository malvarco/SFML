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


    // ____________________
    // ::: Load texture :::

    // Create texture from PNG file
    sf::Texture texture;
    if (!texture.loadFromFile("sfml-icon-small.png"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }
    // Enable the smooth filter. The texture appears smoother so that pixels are less noticeable.
    texture.setSmooth(true);



    // _______________________________________
    // ::: Create sprite and apply texture :::

    // Create the sprite and apply the texture
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sf::FloatRect spriteSize=sprite.getGlobalBounds();
    sprite.setOrigin(spriteSize.width/2.,spriteSize.height/2.);


    // _________________
    // ::: Main loop :::

    sf::Clock timer;
    while (window.isOpen())
    {
        // Display fps
        std::cout << int(1./timer.restart().asSeconds()) << " fps" << std::endl;

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

        // Draw the sprite in the middle of the screen
        sprite.setPosition(window.getSize().x/2., window.getSize().y/2.);
        window.draw(sprite);

        // Update display and wait for vsync
        window.display();
    }
    return 0;
}

