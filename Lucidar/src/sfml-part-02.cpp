/*!
 * \file    main.cpp
 * \brief   Display the list of available video mode (http://www.lucidarme.me/?p=6127)
 * \author  Philippe Lucidarme (from official SFML tutorial)
 * \version 1.0
 * \date    12/18/2016
 * 
 * Compiled using MS VS Console App ***
 * 
 */

// SFML libraries
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{

    // Display the list of all the video modes available for fullscreen
    std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();

    // Display each mode
    for (std::size_t i = 0; i < modes.size(); ++i)
    {
        sf::VideoMode mode = modes[i];
        std::cout << "Mode #" << i << "\t"
                  << mode.width << "x" << mode.height << " \t "
                  << mode.bitsPerPixel << " bpp" << std::endl;
    }

    // Get and display desktop mode
    sf::VideoMode mode = sf::VideoMode::getDesktopMode();
    std::cout << "Desktop"  << "\t"
              << mode.width << "x" << mode.height << " \t "
              << mode.bitsPerPixel << " bpp" << std::endl;

    // End of application
    return 0;
}
