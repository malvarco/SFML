/*

Simple Text font example:
Notice you need SFML/Graphics library to have access to Font function.

*/

#include <SFML/Graphics.hpp>

int wWinMain()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "My window",sf::Style::Fullscreen);

    // change the position of the window (relatively to the desktop)
    // window.setPosition(sf::Vector2i(10, 50));
    window.setPosition(sf::Vector2i(0, 0));

    // change the size of the window
    window.setSize(sf::Vector2u(640, 480));

    // change the title of the window
    window.setTitle("SFML window");

    // get the size of the window
    sf::Vector2u size = window.getSize();
    unsigned int width = size.x;
    unsigned int height = size.y;

    // check whether the window has the focus
    bool focus = window.hasFocus();
    
     sf::Font font;
     font.loadFromFile("pressstart.ttf");

     sf::Text text;
     // select the font
     text.setFont(font);
     text.setPosition(50.f, 10.f);
     // set the string to display
     text.setString("\n\n\n\nPress ESC to restore window\n\nPresione ESC para restaurar la ventana");
     // set the character size
     text.setCharacterSize(10);     // in pixels, no points.
     // set the color
     text.setFillColor(sf::Color::Red);
     // set the text style
    // text.setStyle(sf::Text::Bold | sf::Text::Underlined); // Bold se ve mal con Presstart font
     text.setStyle(sf::Text::Underlined);
    // run the program as long as the window is open
    while (window.isOpen())
    {
        /** SET FRAME RATES NEVER USE BOTH AT THE SAME TIME **/
        window.setVerticalSyncEnabled(true); // call it once, after creating the window

        // window.setFramerateLimit(60); // call it once, after creating the window

        /** END OF SET FRAME RATES NEVER USE BOTH AT THE SAME TIME **/

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            //if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.create(sf::VideoMode(640, 480), "My window", sf::Style::Default);
            if (event.type == sf::Event::Resized)
                window.create(sf::VideoMode(640, 480), "My window", sf::Style::Fullscreen);
        }

        // inside the main loop, between window.clear() and window.display()
        // Display sequence : clear screen, draw circle and update display
        // window object HAS TO BE CREATED with sf::RenderWindow
        window.clear(sf::Color::White);
        window.draw(text);
        window.display();
        
    }

    return 0;
}