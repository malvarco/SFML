/*!
 * \file    main.cpp
 * \brief   First example of SFML (https://www.lucidar.me/en/sfml/sfml-part-1-installation-and-first-program/)
 * \author  Philippe Lucidarme (from official SFML tutorial)
 * \version 1.0
 * \date    10/07/2018
 */

// SFML libraries
#include <SFML/Graphics.hpp>

int wWinMain()
{
    // Create a new 200x200 pixels window with a title
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML tutorial : part 1");

    // Create a green circle with a radius of 100. pixels
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);


    // Main loop, while the window is open
    while (window.isOpen())
    {
        // Event loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // If close is requested by user, close the window
            if (event.type == sf::Event::Closed) window.close();
        }

        // Display sequence : clear screen, draw circle and update display
        window.clear();
        window.draw(shape);
        window.display();
    }

    // End of application
    return 0;
}
