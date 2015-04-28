//Checked 1




#ifndef PLAYER_HPP
#define PLAYER_HPP



#define NO_TARGET -1
#define MIN_DISTANCE 2.0






class Player
{

	Spell *m_spell;
	SpellManager *mm_spell;
	Direction * m_dir;
	AutoPath * a_path;
	Sprite ** m_sprite;
	Animation *walk_animation;
	EventHandler *h_event;


	PhysicalAttributes * attributes;
	Stats * m_stats;
	GLint target;

	sf::Clock *t_clock;


	ActionHandler * a_handler;
	glm::vec2 last_wanted_position;
	GLboolean able_to_move;
	Item **items;
	bool created;
	


	void HandleAutoPath(SoundManager *sm, Controller * ctrl, GameObject * g_obj, Map *current_map);
	GLboolean CheckAdvance(Controller * ctrl, GameObject * g_obj);



	void LoadSprites();
	void LoadPhysicalAttributes(Map * current_tilemap);
	void LoadStats();
	void LoadItems(GameObject * g_obj);
	


	void UpdateUI(GameObject * g_obj);


public:



	void SetPosition(glm::vec2 position){ this->attributes->position = position; }
	void Load(GameObject * g_obj, Map * current_tilemap);
	void Advance(GameObject * g_obj, Map * current_tilemap);
	void Render(SoundManager *sm, Controller * ctrl, ScreenUniformData *u_data, GameObject * g_obj, Map * current_map);
	inline GLint GetTarget(){ return this->target; }
	inline void SetTarget(GLint target){ this->target = target; }
	inline PhysicalAttributes*GetPAttributes(){ return this->attributes; }
	inline Stats * GetStats(){ return this->m_stats; }
	inline Item**GetItems(){ return this->items; }
	inline Direction * GetDirection(){ return this->m_dir; }
	inline ActionHandler * GetActionHandler(){ return this->a_handler; }
	inline EventHandler* GetEventHandler(){ return this->h_event; }
	inline GLboolean GetMoveAbility(){ return this->able_to_move; }
	inline void SetMoveAbility(GLboolean able_to_move){ this->able_to_move = able_to_move; }


};







#endif



