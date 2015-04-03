#pragma once




class GameRender
{


	SpriteManager * s_manager;


	FontManager * f_manager;



public:




	inline GameRender(GameObject * g_obj){ this->Init(g_obj); }



	inline ~GameRender(){ this->Clean(); }



	void Clean(){ delete this->s_manager; delete this->f_manager; }



	void Init(GameObject * g_obj);


	bool GetDrawCode(){ return this->s_manager->s_screen->Update(); }

	void Render(SoundManager * sm, Controller * ctrl, GameObject * g_obj);



};