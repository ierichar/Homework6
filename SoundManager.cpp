#include "SoundManager.h"

using namespace gm;
using namespace sf;

gm::SoundManager::SoundManager()
{
	sound.setVolume(MASTER_VOLUME);

	paddleBounce.loadFromFile("Assets/BGM.wav");
	sound.setBuffer(paddleBounce);
}

void gm::SoundManager::play(std::string cue)
{
	if (cue == "bgm") {
		sound.setBuffer(paddleBounce);
		sound.play();
	}
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
