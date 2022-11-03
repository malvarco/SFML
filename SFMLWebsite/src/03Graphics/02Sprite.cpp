/*

Sprite example:
Notice you need SFML/Graphics library to have access to Font function.

*/

#include <SFML/Graphics.hpp>

int wWinMain()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "My window");

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

    /* Sprite SFML lib*/
    sf::Texture texture;
    texture.loadFromFile("castle.png", sf::IntRect(0,32,640,432));

    // option: create an empty 200x200 texture to update later
    // texture.create(200, 200);

    // Options: update texture
    // option: update a texture from an array of pixels
    // sf::Uint8* pixels = new sf::Uint8[width * height * 4]; // * 4 because pixels have 4 components (RGBA)
    //   texture.update(pixels);

    // option: update a texture from a sf::Image
     sf::Image image;
       texture.update(image);

    // option: update the texture from the current contents of the window
    // sf::RenderWindow window;
    //    texture.update(window);

       sf::Sprite sprite;
       sprite.setTexture(texture);

       sprite.setColor(sf::Color(255, 255, 255, 108));

       sprite.setPosition(sf::Vector2f(0.f, 50.f)); // absolute position

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
            /*
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.create(sf::VideoMode(640, 480), "My window", sf::Style::Default);
           
            if (event.type == sf::Event::Resized)
                window.create(sf::VideoMode(640, 480), "My window", sf::Style::Fullscreen);
 */

        }

        // inside the main loop, between window.clear() and window.display()
        // Display sequence : clear screen, draw circle and update display
        // window object HAS TO BE CREATED with sf::RenderWindow
        window.clear(sf::Color::White);
        window.draw(sprite);
        window.display();

    }

    return 0;
}