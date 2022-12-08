#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

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
		sf::SoundBuffer paddleBounce, wallBounce, brickDamage, brickDestroy, loseLife;
		sf::SoundBuffer normal_brick_sound, tough_brick_sound;

		sf::Sound sound;

	public:

		SoundManager();
		void play(std::string cue);
		void restart();
		void stop();
		~SoundManager();

	};
}

#endif

