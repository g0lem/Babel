#include <common.hpp>


void SoundManager::Init()
{

	m_playing.playing = false;


	s_playing.playing = false;


	this->soundpath = new char*[1];

	this->musicpath = new char*[MAX_MUSIC];


	this->m_sounds = new std::vector<Sound*>;


	this->m_music = new std::vector<Music*> ;



	loadSounds(this->soundpath);


	loadMusic(this->musicpath);

}



void SoundManager::loadSounds(char** path)
{


	path[0] = "data/media/sounds/ambience1.flac";
	path[1] = "data/media/sounds/ambience2.wav";
	path[2] = "data/media/sounds/ambience3.flag";
	path[3] = "data/media/sounds/ambience4.wav";
	path[4] = "data/media/sounds/attack1.wav";
	path[5] = "data/media/sounds/attack2.wav";
	path[6] = "data/media/sounds/attack3.wav";
	path[7] = "data/media/sounds/equipitem.wav";
	path[8] = "data/media/sounds/menupressbutton.wav";
	path[9] = "data/media/sounds/opendoor.wav";
	path[10] = "data/media/sounds/openinventory.wav";
	path[11] = "data/media/sounds/scorpionattack.wav";
	path[12] = "data/media/sounds/scorpiondie.wav";
	path[13] = "data/media/sounds/walksound.ogg";


	AddSound(path[0], "Ambience1");
	AddSound(path[1], "Ambience2");
	AddSound(path[2], "Ambience3");
	AddSound(path[3], "Ambience1");
	AddSound(path[4], "Attack1");
	AddSound(path[5], "Attack2");
	AddSound(path[6], "Attack3");
	AddSound(path[7], "Equip Item");
	AddSound(path[8], "Menu press button");
	AddSound(path[9], "Open Door");
	AddSound(path[10], "Open Inventory");
	AddSound(path[11], "Scorpion Attack");
	AddSound(path[12], "Scorpion Die");
	AddSound(path[13], "Walksound");

}


void SoundManager::loadMusic(char** path)
{



	path[0] = "data/media/sounds/attack2.wav";




	AddMusic(path[0], "attack");




}

void SoundManager::Clean()
{


	delete this->m_sounds;

	delete this->m_music;


}

void SoundManager::AddSound(char* p_sound, char *name)
{
	Sound *t_sound = new Sound;

	sf::SoundBuffer *buffer = new sf::SoundBuffer;



	if (!buffer->loadFromFile(p_sound))
		printf("ERROR: Couldn't load sound buffer from %d \n\n", p_sound);




	sf::Sound *sound = new sf::Sound;




	t_sound->buffer = buffer;


	sound->setBuffer(*t_sound->buffer);


	t_sound->sound = sound;


	t_sound->name = name;






	this->m_sounds->push_back(t_sound);




}


void SoundManager::AddMusic(char* p_music, char* name)
{
	
	Music *t_music = new Music;



	sf::Music * music = new sf::Music;


	if (!music->openFromFile(p_music))
		printf("ERROR: Couldn't load music from %d \n\n", p_music);


	t_music->music = music;


	t_music->name = name;



	this->m_music->push_back(t_music);

}


inline int SoundManager::GetSoundIndex(char *p_sound)
{
	for (int i = 0; i < this->m_sounds->size(); i++)
		if (strcmp(p_sound, this->m_sounds->at(i)->name) == 0)
			return i;
}


inline int SoundManager::GetMusicIndex(char *p_music)
{
	for (int i = 0; i < this->m_music->size(); i++)
		if (strcmp(p_music, this->m_music->at(i)->name) == 0)
			return i;

}



void SoundManager::PlaySound(char* p_sound)
{
	if (!s_playing.playing)
	{

		this->m_sounds->at(GetSoundIndex(p_sound))->sound->play();

		s_playing.playing = true;

	}
	else
	{

		printf("%c, is currently playing, switching to %c\n", this->m_sounds->at(GetSoundIndex(s_playing.name))->name,p_sound);


		setSoundStatus(s_playing.name, Paused);

		this->m_sounds->at(GetSoundIndex(p_sound))->sound->play();


		s_playing.name = p_sound;


	}


}

void SoundManager::PlaySound(int index)
{
	if (!s_playing.playing)
	{

		this->m_sounds->at(index)->sound->play();

		s_playing.playing = true;

	}
	else
	{

		//printf("%c, is currently playing, switching to %c\n", this->m_sounds->at(GetSoundIndex(s_playing.name))->name, p_sound);


		//setSoundStatus(s_playing.name, Paused);

		this->m_sounds->at(index)->sound->play();


		//s_playing.name = p_sound;


	}
}



void SoundManager::PlayMusic(char *p_music)
{
	if (!m_playing.playing)
	{

		this->m_music->at(GetMusicIndex(p_music))->music->play();

		m_playing.playing = true;
	}
	else
	{
		printf("%c, is currently playing, switching to %c\n", this->m_music->at(GetMusicIndex(m_playing.name))->name, p_music);


		setMusicStatus(m_playing.name, Paused);


		this->m_music->at(GetMusicIndex(p_music))->music->play();

		m_playing.name = p_music;

	}

}

void SoundManager::StopSound(char *name)
{


	this->m_sounds->at(GetSoundIndex(name))->sound->stop();


}


void SoundManager::StopMusic(char* name)
{

	this->m_music->at(GetMusicIndex(name))->music->stop();

}


void SoundManager::PauseSound(char *name)
{


	this->m_sounds->at(GetSoundIndex(name))->sound->pause();


}

void SoundManager::PauseMusic(char *name)
{


	this->m_music->at(GetMusicIndex(name))->music->pause();

}

bool SoundManager::getSoundLoop(char *name)
{

	return this->m_sounds->at(GetSoundIndex(name))->sound->getLoop();

}


bool SoundManager::getMusicLoop(char *name)
{


	return this->m_music->at(GetMusicIndex(name))->music->getLoop();

}


void SoundManager::setSoundLoop(char *name, bool value)
{

	this->PlaySound(name);


	this->m_sounds->at(GetSoundIndex(name))->sound->setLoop(value);

}

void SoundManager::setMusicLoop(char *name, bool value)
{

	this->PlayMusic(name);


	this->m_music->at(GetMusicIndex(name))->music->setLoop(value);

}

int SoundManager::getSoundStatus(char* name)
{

	return this->m_sounds->at(GetSoundIndex(name))->sound->getStatus();

}

int SoundManager::getMusicStatus(char* name)
{



	return this->m_music->at(GetMusicIndex(name))->music->getStatus();


}

void SoundManager::setSoundStatus(char* name, Status status)
{
	switch (status)
	{
	case Stopped:
		this->m_sounds->at(GetSoundIndex(name))->sound->stop();
		break;
	case Paused:
		this->m_sounds->at(GetSoundIndex(name))->sound->pause();
		break;
	case Playing:
		this->m_sounds->at(GetSoundIndex(name))->sound->play();
		break;
	default:
		break;
	}


}

void SoundManager::setMusicStatus(char* name, Status status)
{
	switch (status)
	{
	case Stopped:
		this->m_music->at(GetMusicIndex(name))->music->stop();
		break;
	case Paused:
		this->m_music->at(GetMusicIndex(name))->music->pause();
		break;
	case Playing:
		this->m_music->at(GetMusicIndex(name))->music->play();
		break;
	default:
		break;
	}

}


float SoundManager::getSoundDuration(char* name)
{


	return this->m_sounds->at(GetSoundIndex(name))->buffer->getDuration().asSeconds();


}


float SoundManager::getMusicDuration(char *name)
{


	return this->m_music->at(GetMusicIndex(name))->music->getDuration().asSeconds();


}

void SoundManager::setSoundPitch(char *name, float value)
{


	this->m_sounds->at(GetSoundIndex(name))->sound->setPitch(value);


}

void SoundManager::setMusicPitch(char *name, float value)
{


	this->m_music->at(GetMusicIndex(name))->music->setPitch(value);


}

void SoundManager::setSoundVolume(char *name, float value)
{


	this->m_sounds->at(GetSoundIndex(name))->sound->setVolume(value);


}

void SoundManager::setMusicVolume(char *name, float value)
{



	this->m_music->at(GetMusicIndex(name))->music->setVolume(value);



}


float SoundManager::getSoundVolume(char *name)
{


	return this->m_sounds->at(GetSoundIndex(name))->sound->getVolume();


}

float SoundManager::getMusicVolume(char *name)
{


	return this->m_music->at(GetMusicIndex(name))->music->getVolume();


}


void SoundManager::SetSoundOffset(char* name, float value)
{

	sf::Time time;

	time = sf::seconds(value);


	this->m_sounds->at(GetSoundIndex(name))->sound->setPlayingOffset(time);


}


void SoundManager::SetMusicOffset(char *name, float value)
{

	sf::Time time;

	time = sf::seconds(value);


	this->m_music->at(GetMusicIndex(name))->music->setPlayingOffset(time);


}


float SoundManager::getSoundOffset(char *name)
{


	return this->m_sounds->at(GetSoundIndex(name))->sound->getPlayingOffset().asSeconds();



}

float SoundManager::getMusicOffset(char *name)
{


	return this->m_music->at(GetMusicIndex(name))->music->getPlayingOffset().asSeconds();



}