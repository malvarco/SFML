/*

Controlling the framerate

Sometimes, when your application runs fast, you may notice visual artifacts such as tearing.
The reason is that your application's refresh rate is not synchronized with the vertical frequency
of the monitor, and as a result, the bottom of the previous frame is mixed with the top of the next
one.
The solution to this problem is to activate vertical synchronization. It is automatically handled by
the graphics card, and can easily be switched on and off with the setVerticalSyncEnabled function:

window.setVerticalSyncEnabled(true); // call it once, after creating the window

After this call, your application will run at the same frequency as the monitor's refresh rate.

Sometimes setVerticalSyncEnabled will have no effect: this is most likely because vertical synchronization
is forced to "off" in your graphics driver's settings. It should be set to "controlled by application" instead.

In other situations, you may also want your application to run at a given framerate, instead of
the monitor's frequency. This can be done by calling setFramerateLimit:

window.setFramerateLimit(60); // call it once, after creating the window

Unlike setVerticalSyncEnabled, this feature is implemented by SFML itself, using a combination of sf::Clock and sf::sleep.
An important consequence is that it is not 100% reliable, especially for high framerates: sf::sleep's resolution depends on
the underlying operating system and hardware, and can be as high as 10 or 15 milliseconds.
Don't rely on this feature to implement precise timing.

Never use both setVerticalSyncEnabled and setFramerateLimit at the same time! They would badly mix and make things worse.

*/

#include <SFML/Window.hpp>

int wWinMain()
{
    sf::Window window(sf::VideoMode(800, 600), "My window");



    // change the position of the window (relatively to the desktop)
    window.setPosition(sf::Vector2i(10, 50));

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
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}