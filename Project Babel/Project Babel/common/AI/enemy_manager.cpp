//Checked 2



#include <common.hpp>



void EnemyManager::Render(SoundManager *sm, Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj, Map *map, int type)
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

			if (ctrl->GetKey(GLFW_KEY_Y))
			{
				m_enemies[0][i]->fall += 1;
			}

			if (m_enemies[0][i]->GetPAttributes()->scale.x - m_enemies[0][i]->fall <= 0)
                 m_enemies[0][i]->GetStats()->GetHp()->hp = 0;

			glm::ivec2 e_pos = glm::ivec2(this->m_enemies[0][i]->GetPAttributes()->position);
			if (map->GetFogofWar()->GetFogMartix()[(int)(e_pos.x)][(int)(e_pos.y)] < 0.50f)
			{
				u_data->SetAmbientLight(glm::vec4(1.f, 1.f, 1.f, 1.f));
				this->m_enemies[0][i]->Render(ctrl, u_data, g_obj, map);
				this->m_enemies[0][i]->GetPAttributes()->visible = true;
			}
			else
			{
				u_data->SetAmbientLight(glm::vec4(1.f, 1.f, 1.f, 0.f));
				this->m_enemies[0][i]->Render(ctrl, u_data, g_obj, map);
				this->m_enemies[0][i]->GetPAttributes()->visible = false;
			}



		}

	}




	this->CheckEnemiesState(sm, g_obj, map, type);




}



void EnemyManager::Init(GLuint num, Map * map, GameObject * g_obj, int type)
{

	Enemy *temp;
	EnemyData *temp_data;

	this->m_enemies = new std::vector<Enemy*>();

	temp_data = g_obj->GetEnemyLoader()->GetData()[0][type];
	


	while (this->m_enemies[0].size() < num)
	{
		temp = new Enemy(temp_data);
		this->type = type;
		temp->SetRandomPosition(map);
		temp->Update(g_obj, 0);
		glm::vec2 t_pos = temp->GetPAttributes()->position;
		GLboolean ok = true;
		for (GLuint i = 0; i < this->m_enemies[0].size(); i++)
			if (t_pos == this->m_enemies[0][i]->GetPAttributes()->position)
			{
		//	this->Kill(g_obj, num_e, map, type);
			delete temp;
			ok = false;
			break;
			}

		if (glm::distance(glm::vec2(map->GetRoomsPointer()[0][0]->GetInternalCenter()), t_pos) < 6.0f)
			ok = false;
		if (ok)
		{
			
			this->m_enemies[0].push_back(temp);
		}
	}

	this->num_enemies_max = num;

}


void EnemyManager::AddEnemies(GLuint num, Map * map, GameObject * g_obj, int type)
{

	Enemy *temp;
	EnemyData *temp_data;
	int target = this->m_enemies[0].size() + num;

	temp_data = g_obj->GetEnemyLoader()->GetData()[0][type];



	while (this->m_enemies[0].size() < target)
	{
		temp = new Enemy(temp_data);
		this->type = type;
		temp->SetRandomPosition(map);
		temp->Update(g_obj, 0);
		glm::vec2 t_pos = temp->GetPAttributes()->position;
		GLboolean ok = true;
		for (GLuint i = 0; i < this->m_enemies[0].size(); i++)
			if (t_pos == this->m_enemies[0][i]->GetPAttributes()->position)
			{
			//	this->Kill(g_obj, num_e, map, type);
			delete temp;
			ok = false;
			break;
			}

		if (glm::distance(glm::vec2(map->GetRoomsPointer()[0][0]->GetInternalCenter()), t_pos) < 6.0f)
			ok = false;

		if (g_obj->GetCollisionMap()->AcquirePoland()[(int)(t_pos.x)][(int)(t_pos.y)] == true)
			ok = false;


		if (ok)
		{
			g_obj->GetCollisionMap()->AcquirePoland()[(int)(t_pos.x)][(int)(t_pos.y)] = true;
			this->m_enemies[0].push_back(temp);
		}
	}


}


void EnemyManager::AddEnemies(Map * map, GameObject * g_obj, int type, glm::vec2 position)
{
	Enemy *temp;
	EnemyData *temp_data;
	int target = this->m_enemies[0].size() + 1;

	temp_data = g_obj->GetEnemyLoader()->GetData()[0][type];



	
		temp = new Enemy(temp_data);
		this->type = type;
		temp->SetRandomPosition(map);
		temp->Update(g_obj, 0);
		temp->GetPAttributes()->position = position;
		temp->GetPAttributes()->target = position;
		
		


		
		

			this->m_enemies[0].push_back(temp);
		
	


}




void EnemyManager::CheckEnemiesState(SoundManager *sm, GameObject * g_obj, Map *map, int type)
{
	int random_damage;

	for (GLuint i = 0; i < this->m_enemies->size(); i++)
	{
		for (GLuint j = 0; j < g_obj->GetItemList()->GetTraps().size(); j++)
		{
			if (this->m_enemies[0][i]->GetPAttributes()->position == g_obj->GetItemList()->GetTraps()[j]->position  && g_obj->GetItemList()->GetTraps()[j]->item->id == SPIKES_ID)
			{
				
				random_damage = Rand(g_obj->GetItemList()->GetTraps()[j]->item->attack.x, g_obj->GetItemList()->GetTraps()[j]->item->attack.y);
				if (this->m_enemies[0][i]->GetStats()->GetHp()->hp > random_damage)
				{
					this->m_enemies[0][i]->GetStats()->GetHp()->hp -= random_damage;
				}
				else
				{

					this->Kill(g_obj, i, map, type);
					//sm->PlaySound(SCORPIONDIE);
				
				}

				g_obj->GetItemList()->GetTraps()[j]->item->id = SPIKES_FIRED_ID;
			}
		}


		if (this->m_enemies[0][i]->GetStats()->GetHp()->hp == 0)
		{


			this->Kill(g_obj, i, map, type);
			//sm->PlaySound(SCORPIONDIE);

		}



	}


}



void EnemyManager::Kill(GameObject * g_obj, GLuint enemy_id, Map *map, int type)
{


		glm::vec2 last_position = this->m_enemies[0][enemy_id]->GetLastPosition();
		g_obj->GetCollisionMap()->GetTiles()[GLuint(last_position.x)][GLuint(last_position.y)] = 0;
		this->m_enemies->erase(this->m_enemies->begin() + enemy_id);



}