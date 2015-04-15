#pragma once




class GameRender
{


	SpriteManager * s_manager;

	struct save
	{
		GameRender *g_rend;
		GameObject *g_obj;

		inline save(GameRender *g_rend,
			GameObject *g_obj)
		{
			this->g_rend = g_rend;
			this->g_obj = g_obj;
		}
	};


	std::vector<save*> level_list;


public:




	inline GameRender(GameObject * g_obj){ this->Init(g_obj); }



	inline ~GameRender(){ this->Clean(); }



	void Clean(){ delete this->s_manager;  }



	void Init(GameObject * g_obj);


	bool GetDrawCode(){ return this->s_manager->s_screen->Update(); }

	void Render(SoundManager * sm, Controller * ctrl, GameObject * g_obj);

	inline SpriteManager *GetSpriteManager(){ return this->s_manager; }



};