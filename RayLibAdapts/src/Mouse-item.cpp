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
    shape.setFillColor(sf::Color::Blue);
    window.setMouseCursorVisible(false);

    // Main loop, while the window is open
    while (window.isOpen())
    {
        // get global mouse position
           sf::Vector2i position = sf::Mouse::getPosition(window);
           shape.setPosition(position.x-shapeWidth,position.y-shapeWidth);
        
           if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) shape.setFillColor(sf::Color::Color(190, 33, 55));
           else if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))shape.setFillColor(sf::Color::Green);
           else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))shape.setFillColor(sf::Color::Blue);
           
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
