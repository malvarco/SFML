/*!
 */

#define RAYWHITE   245, 245, 245, 255

 //#include <windows.h>
 // SFML libraries
#include <SFML/Graphics.hpp>

int wWinMain()
{


    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    const float shapeWidth = 50.f;

    // Create a new 200x200 pixels window with a title
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFML: Input Keys");


    // Create a green circle with a radius of 100. pixels
    sf::CircleShape shape(shapeWidth);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(((float)screenWidth / 2) - shapeWidth, ((float)screenHeight / 2) - shapeWidth);

    // Main loop, while the window is open
    while (window.isOpen())
    {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) shape.move(0.1f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) shape.move(-0.1f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) shape.move(0.f, -0.1f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) shape.move(0.f, 0.1f);

        // Event loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // If close is requested by user, close the window
            if (event.type == sf::Event::Closed) window.close();
        }

        // Display sequence : clear screen, draw circle and update display
        window.clear(sf::Color(RAYWHITE));
        window.draw(shape);
        window.display();
    }

    // End of application
    return 0;
}
