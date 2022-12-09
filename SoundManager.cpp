#include "SoundManager.h"

using namespace gm;
using namespace sf;

gm::SoundManager::SoundManager()
{
	sound.setVolume(MASTER_VOLUME);

	//paddleBounce.loadFromFile("Assets/BGM.wav");
	//sound.setBuffer(paddleBounce);
}

void gm::SoundManager::playSFX(sf::SoundBuffer* cue)
{
	sound.setBuffer(*cue);
	sound.play();
}

void gm::SoundManager::restart()
{
	sound.resetBuffer();
}

void gm::SoundManager::stop()
{
	sound.stop();
}

gm::SoundManager::~SoundManager()
{

}
