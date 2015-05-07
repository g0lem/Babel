//Checked 1



#ifndef SPRITE_MANAGER_HPP
#define SPRITE_MANAGER_HPP




class SpriteManager : private Aaether2D
{


	Player * player;

	Map * map;

	int level;

	EnemyManager * m_enemies;

	EffectsHandler *m_effects;
	Sprite * test;
	Font *font;

	float alpha = 1.f;


	Combat * m_combat;

public:
	SplashScreen * s_screen;
	inline SpriteManager(GameObject * g_obj, Tooltip *t_tip){ this->Init(g_obj, t_tip); }


	inline ~SpriteManager(){ this->Clean(); }

	void Advance(GameObject * g_obj, Tooltip *t_tip);

	inline Player *GetPlayer(){ return this->player; }


	void Init(GameObject * g_obj, Tooltip *t_tip);


	void Clean();


	void Render(SoundManager * sm, Controller * ctrl, GameObject * g_obj, Tooltip *t_tip);


};



#endif