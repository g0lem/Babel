#ifndef MEDIA_PLAYER_HPP
#define MEDIA_PLAYER_HPP


class MediaPlayer : private Controller
{

	SoundManager* s_manager;

	FontManager* f_manager;

	SpriteManager *sprite_m;

	GameObject *g_object;


public:


	inline MediaPlayer(){ this->Init(); }

	inline ~MediaPlayer(){ this->Terminate(); }



	void Init();



	void Render();
	


	void Run();



	void Terminate();





};

#endif