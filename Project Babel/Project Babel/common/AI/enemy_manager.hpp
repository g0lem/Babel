#ifndef ENEMY_MANAGER_HPP
#define ENEMY_MANAGER_HPP







class EnemyManager
{
	


	std::vector<Enemy*>*m_enemies;



	void CheckEnemiesState(SoundManager *sm, GameObject * g_obj, Map *map, int type);


	void Kill(GameObject * g_obj, GLuint enemy_id, Map *map, int type);



	int type;



public:

	void Render(SoundManager *sm, Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj, Map *map, int type);

	int GetType(){ return this->type; }

	void EnemyManager::AddEnemies(Map * map, GameObject * g_obj, int type, glm::vec2 position);
	void Render(SoundManager *sm, Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj, int type);
	inline EnemyManager(GLuint num, Map *map, GameObject *g_obj, int type){ this->Init(num, map, g_obj, type); }
	void Init(GLuint num, Map * map, GameObject * g_obj, int type);
	void AddEnemies(GLuint num, Map * map, GameObject * g_obj, int type);
	inline std::vector<Enemy*>*GetEnemiesPointer(){ return this->m_enemies; }



};




#endif



