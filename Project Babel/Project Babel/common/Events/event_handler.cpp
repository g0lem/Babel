#include "common.hpp"

void EventHandler::Init(Map *current_map)
{
	e_map = new int*[current_map->GetTilemap()->GetSize().x];
	for (int i = 0; i < current_map->GetTilemap()->GetSize().x; i++)
		e_map[i] = new int[current_map->GetTilemap()->GetSize().y];

	for (int i = 0; i < current_map->GetTilemap()->GetSize().x; i++)
		for (int j = 0; j < current_map->GetTilemap()->GetSize().y; j++)
			e_map[i][j] = 0;
	Load(current_map);
}

void EventHandler::Load(Map *current_map)
{
	for (int i = 0; i < current_map->GetTilemap()->GetSize().x; i++)
		for (int j = 0; j < current_map->GetTilemap()->GetSize().y; j++)
		{
		if (current_map->GetTilemap()->GetTiles()[i][j] == DOOR_BLOCK)
			e_map[i][j] = 1;

		if (current_map->GetTilemap()->GetTiles()[i][j] == TABLET)
			e_map[i][j] = 2;

		if (current_map->GetTilemap()->GetTiles()[i][j] == HEALTH_POTION)
			e_map[i][j] = 3;
		}
}

void EventHandler::Door(glm::vec2 position, Map *current_map, GameObject *g_obj)
{
	
	int di[] = { -1, 1, 0, 0 };
	int dj[] = { 0, 0, -1, 1 };
	for (int k = 0; k < 4; k++)
	{

		//open doors
		if (e_map[(int)(position.x) - 1][(int)(position.y)] == 1)
		{
			e_map[(int)(position.x) - 1][(int)(position.y)] = 4;
			current_map->GetTilemap()->GetTiles()[(int)(position.x) - 1][(int)(position.y)] = OPENED_DOOR_BLOCK;
			g_obj->GetCollisionMap()->GetTiles()[(int)(position.x) - 1][(int)(position.y)] = false;
			break;

		}
		if (e_map[(int)(position.x) + 1][(int)(position.y)] == 1)
		{
			e_map[(int)(position.x) + 1][(int)(position.y)] = 4;
			current_map->GetTilemap()->GetTiles()[(int)(position.x) + 1][(int)(position.y)] = OPENED_DOOR_BLOCK;
			g_obj->GetCollisionMap()->GetTiles()[(int)(position.x) + 1][(int)(position.y)] = false;
			break;
		}
		if (e_map[(int)(position.x)][(int)(position.y) - 1] == 1)
		{
			e_map[(int)(position.x)][(int)(position.y) - 1] = 4;
			current_map->GetTilemap()->GetTiles()[(int)(position.x)][(int)(position.y) - 1] = OPENED_DOOR_BLOCK;
			g_obj->GetCollisionMap()->GetTiles()[(int)(position.x)][(int)(position.y) - 1] = false;
			break;
		}
		if (e_map[(int)(position.x)][(int)(position.y) + 1] == 1)
		{
			e_map[(int)(position.x)][(int)(position.y) + 1] = 4;
			current_map->GetTilemap()->GetTiles()[(int)(position.x)][(int)(position.y) + 1] = OPENED_DOOR_BLOCK;
			g_obj->GetCollisionMap()->GetTiles()[(int)(position.x)][(int)(position.y) + 1] = false;
			break;
		}






		//close doors
		if (e_map[(int)(position.x) - 1][(int)(position.y)] == 4)
		{
			e_map[(int)(position.x) - 1][(int)(position.y)] = 1;
			current_map->GetTilemap()->GetTiles()[(int)(position.x) - 1][(int)(position.y)] = DOOR_BLOCK;
			g_obj->GetCollisionMap()->GetTiles()[(int)(position.x) - 1][(int)(position.y)] = true;
			break;
		

		}
		if (e_map[(int)(position.x) + 1][(int)(position.y)] == 4)
		{
			e_map[(int)(position.x) + 1][(int)(position.y)] = 1;
			current_map->GetTilemap()->GetTiles()[(int)(position.x) + 1][(int)(position.y)] = DOOR_BLOCK;
			g_obj->GetCollisionMap()->GetTiles()[(int)(position.x) + 1][(int)(position.y)] = true;
			break;
			
		}
		if (e_map[(int)(position.x)][(int)(position.y) - 1] == 4)
		{
			e_map[(int)(position.x)][(int)(position.y) - 1] = 1;
			current_map->GetTilemap()->GetTiles()[(int)(position.x)][(int)(position.y) - 1] = DOOR_BLOCK;
			g_obj->GetCollisionMap()->GetTiles()[(int)(position.x)][(int)(position.y) - 1] = true;
			break;
			
		}
		if (e_map[(int)(position.x)][(int)(position.y) + 1] == 4)
		{
			e_map[(int)(position.x)][(int)(position.y) + 1] = 1;
			current_map->GetTilemap()->GetTiles()[(int)(position.x)][(int)(position.y) + 1] = DOOR_BLOCK;
			g_obj->GetCollisionMap()->GetTiles()[(int)(position.x)][(int)(position.y) + 1] = true;
			break;
			
		}



	}
}

void EventHandler::Health(glm::vec2 position, Map *current_map, Stats *m_stats)
{
	if (e_map[(int)(position.x)][(int)(position.y)] == 3)
	{
		m_stats->GetHp()->Heal(10);
		current_map->GetTilemap()->GetTiles()[(int)(position.x)][(int)(position.y)] = FLOOR_BLOCK;
		e_map[(int)(position.x)][(int)(position.y)] = 0;
		std::cout << "You drank the health potion\n";
	}
}




void EventHandler::TriggerEvent(glm::vec2 position, Map *current_map, GameObject *g_obj, Stats *m_stats)
{
	this->Door(position, current_map, g_obj);
	this->Health(position, current_map, m_stats);


	if (e_map[(int)(position.x)][(int)(position.y)] == 2) //sa pui tool tip-ul Bursucului
		std::cout << "YOU MUST SEEK GOD!\n";


}


void EventHandler::DisplayTablet(int id)
{
	
}