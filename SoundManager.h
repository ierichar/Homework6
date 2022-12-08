#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

namespace gm {
	const float MASTER_VOLUME = 7.0f;

	class SoundManager
	{
	private:
		sf::Sound sound;

	public:

		SoundManager();
		void playSFX(sf::SoundBuffer* cue);
		void restart();
		void stop();
		~SoundManager();

	};
}

#endif

