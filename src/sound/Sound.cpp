// /*
// ** EPITECH PROJECT, 2024
// ** Global-Game-Jam
// ** File description:
// ** Sound
// */

#include "Sound.hpp"

#include <thread>

void Sound::playSoundThreaded() {
    _sound.play();
    sf::sleep(sf::milliseconds(_delay));
}

void Sound::playSound() {
    std::thread t(&Sound::playSound, this);
    t.detach();
}
