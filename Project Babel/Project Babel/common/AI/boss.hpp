#pragma once



class Boss
{
	Stats *m_stats;
	PhysicalAttributes * p_attrib;
	Sprite * m_sprite;
	Direction *m_dir;

	glm::vec4 color;
	TurnLogic * t_logic;
	glm::vec2 target_position;
	int target;
	TurnSystem * turn_sys;
	ActionHandler * a_handler;

	void LoadSprites(EnemyData *data);
	void LoadStats(EnemyData* data);
	void LoadAttrib();

	void RenderHPBar(ScreenUniformData *u_data, GameObject *g_obj);



public:


	inline Boss(EnemyData *data){ this->Init(data); }
	void Init(EnemyData* data);

	void Render(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj, Map *map);
	void SetPosition(glm::vec2 pos);
	void Update(GameObject *g_obj, float delta);

	int *chances, *items;
	int num_drop;
	bool ranged;

	void SetChances(EnemyData *data);

};

