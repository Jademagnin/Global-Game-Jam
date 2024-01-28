// /*
// ** EPITECH PROJECT, 2024
// ** Global-Game-Jam
// ** File description:
// ** Sound
// */

#include "Sound.hpp"


void Sound::playSound() {
        _sound.play();
    sf::sleep(sf::milliseconds(_delay));
}
