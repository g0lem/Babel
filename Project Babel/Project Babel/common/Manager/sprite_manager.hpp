//Checked 1



#ifndef SPRITE_MANAGER_HPP
#define SPRITE_MANAGER_HPP




class SpriteManager : private Aaether2D
{


	Player * player;

	Map * map;


	EnemyManager * m_enemies;

	EffectsHandler *m_effects;

	Font *font;

	float alpha = 1.f;


	Combat * m_combat;

public:
	SplashScreen * s_screen;
	inline SpriteManager(GameObject * g_obj){ this->Init(g_obj); }


	inline ~SpriteManager(){ this->Clean(); }

	void Advance(GameObject * g_obj);


	void Init(GameObject * g_obj);


	void Clean();


	void Render(SoundManager * sm, Controller * ctrl, GameObject * g_obj);


};



#endif