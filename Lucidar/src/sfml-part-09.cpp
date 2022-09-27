/*!
 * \file    main.cpp
 * \brief   Music and sound examples (http://www.lucidarme.me/?p=6127)
 * \author  Philippe Lucidarme
 * \version 1.0
 * \date    12/20/2016
 */

#include <SFML/Audio.hpp>
#include <iostream>

// Wait for ms milliseconds
void delay_ms(int ms)
{
    sf::Clock Timer;
    while (Timer.getElapsedTime().asMilliseconds()<ms);
}

int wWinMain()
{
    // _____________________________
    // ::: load background music :::

    sf::Music music;
    if (!music.openFromFile("music.ogg"))
    {
        std::cerr << "Error while loading background music file" << std::endl;
        return -1;
    }



    // __________________
    // ::: Load sound :::

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("birds.wav"))
    {
        std::cerr << "Error while loading sound file" << std::endl;
        return -1;
    }

    // ____________________
    // :::  Play sounds :::

    // Play music
    std::cout << "Start background music" << std::endl;
    music.play();
    delay_ms(1500);

    // Play wav sound over the music
    std::cout << "Play wav sound" << std::endl;
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    delay_ms(1500);

    // Increase pitch
    std::cout << "Increase pitch" << std::endl;
    music.setPitch(1.4);
    delay_ms(1500);

    // Reset pitch
    std::cout << "Reset pitch" << std::endl;
    music.setPitch(1.);
    delay_ms(1500);


    // Modify volume
    std::cout << "Fade out" << std::endl;
    for (int vol=100;vol>5;vol--)
    {
        music.setVolume(vol);
        delay_ms(50);
    }

    // Stop music
    std::cout << "Stop music" << std::endl;
    music.stop();
    return 0;
}
