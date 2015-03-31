//Checked 1




#ifndef PLAYER_HPP
#define PLAYER_HPP



#define NO_TARGET -1
#define MIN_DISTANCE 2.0






class EnemiesNear
{


	GLint counter;


public:


	inline EnemiesNear(){ this->Init(); }
	inline void Init(){ this->counter = 0; }
	inline void Add(){ this->counter++; }
	inline void Remove(){ this->counter--; }
	inline GLboolean HasFriends(){ return this->counter > 0; }



};





class Player
{


	Direction * m_dir;
	AutoPath * a_path;
	Sprite ** m_sprite;
	Animation *walk_animation;
	EventHandler *h_event;
	fog_of_war *fog;


	PhysicalAttributes * attributes;
	Stats * m_stats;
	GLboolean attacking;
	GLint target;

	sf::Clock *t_clock;



	glm::vec2 last_wanted_position;
	Item **items;
	EnemiesNear * e_near;

	


	void HandleAutoPath(Controller * ctrl, GameObject * g_obj, Map *current_map);
	GLboolean CheckAdvance(Controller * ctrl, GameObject * g_obj);



	void LoadSprites();
	void LoadPhysicalAttributes(Map * current_tilemap);
	void LoadStats();
	void LoadItems(GameObject * g_obj);



	void UpdateUI(GameObject * g_obj);


public:




	void Load(GameObject * g_obj, Map * current_tilemap);
	void Render(Controller * ctrl, ScreenUniformData *u_data, GameObject * g_obj, Map * current_map);
	inline GLboolean GetAttackingState(){ return this->attacking; }
	inline void SetAttackingState(GLboolean attacking){ this->attacking = attacking; }
	inline GLint GetTarget(){ return this->target; }
	inline void SetTarget(GLint target){ this->target = target; }
	inline EnemiesNear * GetEnemiesNear(){ return this->e_near; }
	inline PhysicalAttributes*GetPAttributes(){ return this->attributes; }
	inline Stats * GetStats(){ return this->m_stats; }
	inline Item**GetItems(){ return this->items; }
	inline Direction * GetDirection(){ return this->m_dir; }


};







#endif



