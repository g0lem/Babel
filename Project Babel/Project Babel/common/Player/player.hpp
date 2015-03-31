//Checked 1




#ifndef PLAYER_HPP
#define PLAYER_HPP



#define NO_TARGET -1
#define MIN_DISTANCE 2.0




#define NO_ACTION -1
#define MOVING 0
#define ATTACKING 1




class ActionHandler
{


	GLfloat timer;
	GLint action;


public:


	inline ActionHandler(){ this->Init(); }
	inline void Init(){ this->timer = 0.0f; this->action = NO_ACTION; }
	inline void Start(){ this->timer = glfwGetTime(); }
	inline void Stop(){ this->timer = 0.0f; }
	inline GLboolean HasReachedLifetime(GLfloat life_time){ return glfwGetTime() - this->timer > life_time; }
	inline GLboolean IsStopped(){ return this->timer == 0.0f; }
	inline void SetAction(GLuint action){ this->action = action; }
	inline GLuint GetAction(){ return this->action; }



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
	GLint target;

	sf::Clock *t_clock;


	ActionHandler * a_handler;
	glm::vec2 last_wanted_position;
	Item **items;

	


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
	inline GLint GetTarget(){ return this->target; }
	inline void SetTarget(GLint target){ this->target = target; }
	inline PhysicalAttributes*GetPAttributes(){ return this->attributes; }
	inline Stats * GetStats(){ return this->m_stats; }
	inline Item**GetItems(){ return this->items; }
	inline Direction * GetDirection(){ return this->m_dir; }
	inline ActionHandler * GetActionHandler(){ return this->a_handler; }


};







#endif



