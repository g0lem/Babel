//Checked 2



#include <common.hpp>



void EnemyManager::Render(SoundManager *sm, Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj, Map *map)
{

	std::vector<glm::ivec2>list = g_obj->GetCollisionMap()->GetList();
	for (GLuint i = 0; i < list.size(); i++)
		g_obj->GetCollisionMap()->GetTiles()[list[i].x][list[i].y] = 0;
	g_obj->GetCollisionMap()->ResetList();


	for (GLuint i = 0; i < this->m_enemies->size(); i++)
	{


		if (compare_vec2(this->m_enemies[0][i]->GetPAttributes()->position, glm::vec2(g_obj->GetScroller()->GetBeginLimit())) == V_GREATER
			&& compare_vec2(this->m_enemies[0][i]->GetPAttributes()->position, glm::vec2(g_obj->GetScroller()->GetEndLimit())) == V_LESSER)
		{





			glm::ivec2 e_pos = glm::ivec2(this->m_enemies[0][i]->GetPAttributes()->position);
			if (map->GetFogofWar()->GetFogMartix()[(int)(e_pos.x)][(int)(e_pos.y)] <= 0.75f)
				this->m_enemies[0][i]->Render(ctrl, u_data, g_obj, map); 




		}

	}




	this->CheckEnemiesState(sm, g_obj, map);




}



void EnemyManager::Init(GLuint num, Map * map, GameObject * g_obj)
{



	this->m_enemies = new std::vector<Enemy*>();
	this->m_enemies->resize(num);


	GLint num_e = 0;


	while (num_e < num)
	{

		this->m_enemies[0][num_e] = new Enemy(g_obj->GetEnemyLoader()->GetData()[0][0]);
		this->m_enemies[0][num_e]->SetRandomPosition(map);
		this->m_enemies[0][num_e]->Update(g_obj, 0);
		glm::vec2 t_pos = this->m_enemies[0][num_e]->GetPAttributes()->position;
		GLboolean ok = true;
		for (GLuint i = 0; i < num_e; i++)
			if (t_pos == this->m_enemies[0][i]->GetPAttributes()->position)
			{
			this->Kill(g_obj, num_e, map);
			ok = false;
			break;
			}

		if (glm::distance(glm::vec2(map->GetRoomsPointer()[0][0]->GetInternalCenter()), t_pos) < 6.0f)
			ok = false;
		if (ok)
			num_e++;


	}


	
	
}



void EnemyManager::CheckEnemiesState(SoundManager *sm, GameObject * g_obj, Map *map)
{


	for (GLuint i = 0; i < this->m_enemies->size(); i++)
	{


		if (this->m_enemies[0][i]->GetStats()->GetHp()->hp == 0)
		{


			this->Kill(g_obj, i, map);
			sm->PlaySound(SCORPIONDIE);

		}



	}


}



void EnemyManager::Kill(GameObject * g_obj, GLuint enemy_id, Map *map)
{


		glm::vec2 last_position = this->m_enemies[0][enemy_id]->GetLastPosition();
		g_obj->GetCollisionMap()->GetTiles()[GLuint(last_position.x)][GLuint(last_position.y)] = 0;
		this->m_enemies->erase(this->m_enemies->begin() + enemy_id);



}