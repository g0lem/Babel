#ifndef SOUND_MANAGER_HPP
#define SOUND_MANAGER_HPP



#define MAX_SOUNDS 3
#define MAX_MUSIC 3


class SoundManager
{

	struct Sound{
		sf::SoundBuffer *buffer;
		sf::Sound *sound;


		char *name;
	};



	struct Music{
		sf::Music *music;

		char *name;
	};

	struct cPlay{
		bool playing;
		char *name;
	};

	enum Status{
		Stopped,
		Paused,
		Playing
	};

	Status m_status;

	cPlay s_playing, m_playing;

	int currentIndex;



	char** soundpath, **musicpath;





	std::vector<Sound*> *m_sounds;

	std::vector<Music*> *m_music;

public:

	inline SoundManager(){ this->Init(); }

	inline ~SoundManager(){ this->Clean(); }


	void Init(); 

	void Clean();

	// Load


	void loadSounds(char** path);

	void loadMusic(char** path);


	// Add


	void AddSound(char* p_sound, char* name);


	void AddMusic(char* p_music, char* name);



	// Play


	void PlaySound(char *p_sound);


	void PlayMusic(char *p_music);


	// getLoop

	bool getSoundLoop(char *name);

	bool getMusicLoop(char *name);


	// setLoop

	void setSoundLoop(char *name, bool value);

	void setMusicLoop(char *name, bool value);

	// getStatus

	int getSoundStatus(char *name);

	int getMusicStatus(char *name);

	// setStatus

	void setSoundStatus(char *name, Status status);

	void setMusicStatus(char *name, Status status);

	// getDuration

	float getSoundDuration(char *name);

	
	float getMusicDuration(char *name);


	// setPitch

	void setSoundPitch(char *name, float value);

	void setMusicPitch(char *name, float value);

	
	// setVolume

	void setSoundVolume(char *name, float value);


	void setMusicVolume(char *name, float value);

	// getVolume

	float getSoundVolume(char *name);

	float getMusicVolume(char *name);


	

	// Pause

	void PauseSound(char *name);



	void PauseMusic(char *name);

	// get PlayingOffset

	float getSoundOffset(char* name);

	float getMusicOffset(char* name);

	// SetOffset



	void SetSoundOffset(char *name, float value);


	void SetMusicOffset(char *name, float value);

	// Stop 



	void StopSound(char *name);


	void StopMusic(char *name);


	// GetIndex


	inline int GetSoundIndex(char *p_sound);

	inline int GetMusicIndex(char *p_music);



	// GetSource


	inline std::vector<Sound*> *GetSounds(){ return this->m_sounds; }


	inline std::vector<Music*> *GetMusic(){ return this->m_music; }


};





#endif