// /*
// ** EPITECH PROJECT, 2024
// ** Global-Game-Jam
// ** File description:
// ** Sound
// */

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include <SFML/Audio.hpp>
#include <iostream>

class Sound {
    public:
        Sound(const std::string& path, int volume, int delay) : _path(path), _volume(volume), _delay(delay) {

            if (!_buffer.loadFromFile(path)) {
                std::cerr << "Error cannot find sound path." << std::endl;
            }

            _sound.setBuffer(_buffer);
            _sound.setVolume(_volume);
        }

        void playSound();
        void playSoundThreaded();

    private:
        sf::SoundBuffer _buffer;
        sf::Sound _sound;
        std::string _path;
        int _volume;
        int _delay;
};

#endif /* !SOUND_HPP_ */
