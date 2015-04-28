#ifndef ENEMY_HPP
#define ENEMY_HPP





class TurnLogic
{


	GLint counter;


public:


	inline TurnLogic(){ this->Init(); }
	inline void Init(){ this->counter = 0; }
	inline GLboolean IsUseless(){ return this->counter == 0; }
	inline void Advance(){ this->counter++; }
	inline void Reset(){ this->counter = 0; }



};




class Enemy
{


	Stats * m_stats;
	PhysicalAttributes * p_attributes;
    Sprite ** m_sprites;
	Animation ** animations;
	AutoPath * a_path;
	Direction * m_dir;
	glm::vec4 color;


	TurnLogic * t_logic;
	glm::vec2 last_position;
	glm::vec2 target_position;
	GLint target;
	TurnSystem * turn_system;
	ActionHandler * a_handler;


	void LoadSprites(EnemyData * data);
	void LoadStats(EnemyData*data);
	void LoadPhysicalAttributes();


	void RenderMisc(ScreenUniformData * u_data, GameObject * g_obj);
	void RenderHpBar(ScreenUniformData * u_data, GameObject * g_obj);



public:



	inline GLint GetTarget(){ return this->target; }
	inline void SetTarget(GLint target){ this->target = target; }


	inline glm::vec2 GetLastPosition(){ return this->last_position; }
	inline glm::vec2 GetTargetPosition(){ return this->target_position; }
	inline void SetTargetPosition(glm::vec2 target_position){ this->target_position = target_position; }
	inline TurnLogic *GetTurnLogic(){ return this->t_logic; }



	inline Stats*GetStats(){ return this->m_stats; }
	inline PhysicalAttributes*GetPAttributes(){ return this->p_attributes; }
	inline TurnSystem * GetTurnSystem(){ return this->turn_system; }
	inline AutoPath*GetAutoPath(){ return this->a_path; }
	inline Direction * GetDirection(){ return this->m_dir; }
	inline ActionHandler * GetActionHandler(){return this->a_handler;}


	inline Enemy(EnemyData * data){ this->Init(data); }
	void Init(EnemyData * data);

	inline void SetPosition(glm::vec2 position);


	void Render(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj, Map *map);
	void SetRandomPosition(Map * map);
	void Update(GameObject * g_obj, GLfloat delta);


};




#endif