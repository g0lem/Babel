#include "common.hpp"





void EventHandler::Init(Map *current_map, GameObject *g_obj)
{
	e_map = new int*[current_map->GetTilemap()->GetSize().x];
	for (int i = 0; i < current_map->GetTilemap()->GetSize().x; i++)
		e_map[i] = new int[current_map->GetTilemap()->GetSize().y];

	for (int i = 0; i < current_map->GetTilemap()->GetSize().x; i++)
		for (int j = 0; j < current_map->GetTilemap()->GetSize().y; j++)
			e_map[i][j] = 0;
	Load(current_map, g_obj);



}

void EventHandler::Load(Map *current_map, GameObject *g_obj)
{
	for (int i = 0; i < current_map->GetTilemap()->GetSize().x; i++)
		for (int j = 0; j < current_map->GetTilemap()->GetSize().y; j++)
		{
		if (current_map->GetTilemap()->GetTiles()[i][j] == DOOR_BLOCK)
			e_map[i][j] = 1;

		}

	for (int i = 0; i < g_obj->GetItemList()->GetDroppedItems().size(); i++)
		if (g_obj->GetItemList()->GetDroppedItems()[i]->position.x >= 0 && g_obj->GetItemList()->GetDroppedItems()[i]->position.y >=0)
			e_map[(int)(g_obj->GetItemList()->GetDroppedItems()[i]->position.x)][(int) (g_obj->GetItemList()->GetDroppedItems()[i]->position.y)] = 5;

	//std::cout << "Marimea: " << g_obj->GetItemList()->GetObjects().size()<<"\n";

	for (int i = 0; i < g_obj->GetItemList()->GetObjects().size(); i++)
	{
		if (g_obj->GetItemList()->GetObjects()[i]->item->id == TABLET_ID)
		e_map[(int)(g_obj->GetItemList()->GetObjects()[i]->position.x)][(int)(g_obj->GetItemList()->GetObjects()[i]->position.y)] = 2;

		if (g_obj->GetItemList()->GetObjects()[i]->item->id == STAIRS_ID)
			e_map[(int)(g_obj->GetItemList()->GetObjects()[i]->position.x)][(int)(g_obj->GetItemList()->GetObjects()[i]->position.y)] = 3;

		if (g_obj->GetItemList()->GetObjects()[i]->item->id == SPIKES_ID)
			e_map[(int)(g_obj->GetItemList()->GetObjects()[i]->position.x)][(int)(g_obj->GetItemList()->GetObjects()[i]->position.y)] = 4;

		if (g_obj->GetItemList()->GetObjects()[i]->item->id == CHEST_ID)
			e_map[(int)(g_obj->GetItemList()->GetObjects()[i]->position.x)][(int)(g_obj->GetItemList()->GetObjects()[i]->position.y)] = 6;

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
			g_obj->GetCollisionMap()->GetVisibleTiles()[(int)(position.x) - 1][(int)(position.y)] = false;
			break;

		}
		if (e_map[(int)(position.x) + 1][(int)(position.y)] == 1)
		{
			e_map[(int)(position.x) + 1][(int)(position.y)] = 4;
			current_map->GetTilemap()->GetTiles()[(int)(position.x) + 1][(int)(position.y)] = OPENED_DOOR_BLOCK;
			g_obj->GetCollisionMap()->GetTiles()[(int)(position.x) + 1][(int)(position.y)] = false;
			g_obj->GetCollisionMap()->GetVisibleTiles()[(int)(position.x) + 1][(int)(position.y)] = false;
			break;
		}
		if (e_map[(int)(position.x)][(int)(position.y) - 1] == 1)
		{
			e_map[(int)(position.x)][(int)(position.y) - 1] = 4;
			current_map->GetTilemap()->GetTiles()[(int)(position.x)][(int)(position.y) - 1] = OPENED_DOOR_BLOCK;
			g_obj->GetCollisionMap()->GetTiles()[(int)(position.x)][(int)(position.y) - 1] = false;
			g_obj->GetCollisionMap()->GetVisibleTiles()[(int)(position.x)][(int)(position.y) - 1] = false;
			break;
		}
		if (e_map[(int)(position.x)][(int)(position.y) + 1] == 1)
		{
			e_map[(int)(position.x)][(int)(position.y) + 1] = 4;
			current_map->GetTilemap()->GetTiles()[(int)(position.x)][(int)(position.y) + 1] = OPENED_DOOR_BLOCK;
			g_obj->GetCollisionMap()->GetTiles()[(int)(position.x)][(int)(position.y) + 1] = false;
			g_obj->GetCollisionMap()->GetVisibleTiles()[(int)(position.x)][(int)(position.y) + 1] = false;
			break;
		}






		//close doors
		if (e_map[(int)(position.x) - 1][(int)(position.y)] == 4)
		{
			e_map[(int)(position.x) - 1][(int)(position.y)] = 1;
			current_map->GetTilemap()->GetTiles()[(int)(position.x) - 1][(int)(position.y)] = DOOR_BLOCK;
			g_obj->GetCollisionMap()->GetTiles()[(int)(position.x) - 1][(int)(position.y)] = true;
			g_obj->GetCollisionMap()->GetVisibleTiles()[(int)(position.x) - 1][(int)(position.y)] = true;
			break;
		

		}
		if (e_map[(int)(position.x) + 1][(int)(position.y)] == 4)
		{
			e_map[(int)(position.x) + 1][(int)(position.y)] = 1;
			current_map->GetTilemap()->GetTiles()[(int)(position.x) + 1][(int)(position.y)] = DOOR_BLOCK;
			g_obj->GetCollisionMap()->GetTiles()[(int)(position.x) + 1][(int)(position.y)] = true;
			g_obj->GetCollisionMap()->GetVisibleTiles()[(int)(position.x) + 1][(int)(position.y)] = true;
			break;
			
		}
		if (e_map[(int)(position.x)][(int)(position.y) - 1] == 4)
		{
			e_map[(int)(position.x)][(int)(position.y) - 1] = 1;
			current_map->GetTilemap()->GetTiles()[(int)(position.x)][(int)(position.y) - 1] = DOOR_BLOCK;
			g_obj->GetCollisionMap()->GetTiles()[(int)(position.x)][(int)(position.y) - 1] = true;
			g_obj->GetCollisionMap()->GetVisibleTiles()[(int)(position.x)][(int)(position.y) - 1] = true;
			break;
			
		}
		if (e_map[(int)(position.x)][(int)(position.y) + 1] == 4)
		{
			e_map[(int)(position.x)][(int)(position.y) + 1] = 1;
			current_map->GetTilemap()->GetTiles()[(int)(position.x)][(int)(position.y) + 1] = DOOR_BLOCK;
			g_obj->GetCollisionMap()->GetTiles()[(int)(position.x)][(int)(position.y) + 1] = true;
			g_obj->GetCollisionMap()->GetVisibleTiles()[(int)(position.x)][(int)(position.y) + 1] = true;
			break;
			
		}



	}
}


 void EventHandler::AutomaticallyOpenDoor(glm::vec2 position, Map *current_map, GameObject *g_obj, glm::vec2 &door_pos)
{
	if (current_map->GetTilemap()->GetTiles()[(int)(position.x)][(int)(position.y)] == DOOR_BLOCK)
	{
		current_map->GetTilemap()->GetTiles()[(int)(position.x)][(int)(position.y)] = OPENED_DOOR_BLOCK;
		g_obj->GetCollisionMap()->GetTiles()[(int)(position.x)][(int)(position.y)] = false;
		g_obj->GetCollisionMap()->GetVisibleTiles()[(int)(position.x)][(int)(position.y)] = false;
		door_pos = position;
	}
	else if (current_map->GetTilemap()->GetTiles()[(int)(position.x)][(int)(position.y)] == OPENED_DOOR_BLOCK)
	{
		current_map->GetTilemap()->GetTiles()[(int)(position.x)][(int)(position.y)] = DOOR_BLOCK;
		g_obj->GetCollisionMap()->GetTiles()[(int)(position.x)][(int)(position.y)] = true;
		g_obj->GetCollisionMap()->GetVisibleTiles()[(int)(position.x)][(int)(position.y)] = true;	
		door_pos = vec2_0;
	}
	


}

 void EventHandler::DestroyDoor(glm::vec2 position, Map *&current_map, GameObject *g_obj)
 {
	 if (current_map->GetTilemap()->GetTiles()[(int)(position.x)][(int)(position.y)] == DOOR_BLOCK)
	 {
		 current_map->GetTilemap()->GetTiles()[(int)(position.x)][(int)(position.y)] = BROKEN_DOOR;
		 g_obj->GetCollisionMap()->GetTiles()[(int)(position.x)][(int)(position.y)] = false;
		 g_obj->GetCollisionMap()->GetVisibleTiles()[(int)(position.x)][(int)(position.y)] = false;	
	 }
 }






void EventHandler::Health(glm::vec2 position, Map *current_map, Stats *m_stats, GameObject *g_obj)
{
	if (e_map[(int)(position.x)][(int)(position.y)] == 3)
	{
		m_stats->GetHp()->Heal(10);
		current_map->GetTilemap()->GetTiles()[(int)(position.x)][(int)(position.y)] = FLOOR_BLOCK;
		e_map[(int)(position.x)][(int)(position.y)] = 0;
		std::cout << "You drank the health potion\n";
	}
}


void EventHandler::PickUp(glm::vec2 position, Map *current_map, GameObject *g_obj)
{
	if (e_map[(int)(position.x)][(int)(position.y)] == 5)
	{

		for (int i = 0; i < g_obj->GetItemList()->GetDroppedItems().size(); i++)
		{
			
			if (g_obj->GetItemList()->GetInventory().size() < 16 && g_obj->GetItemList()->GetDroppedItems()[i]->position.x == position.x && g_obj->GetItemList()->GetDroppedItems()[i]->position.y == position.y)
			{
				g_obj->GetItemList()->AddtoInventory(g_obj->GetItemList()->GetDroppedItems()[i]->item);
				
				g_obj->GetItemList()->DeleteFromDroppedList(i);
			
			}
		}
		e_map[(int)(position.x)][(int)(position.y)] = 0;
		
	}
}

void EventHandler::NextLvl(glm::vec2 position, Map *current_map, GameObject *g_obj)
{
	for (int i = 0; i < g_obj->GetItemList()->GetObjects().size(); i++)
	{
		if (g_obj->GetItemList()->GetObjects()[i]->position == position && g_obj->GetItemList()->GetObjects()[i]->item->id == STAIRS_ID)
		{
			//std::cout << "YAY, STAIRS\n";
			g_obj->rebuild = true;
		}
			
	}
}

void EventHandler::OpenChest(glm::vec2 position, Map *current_map, GameObject *g_obj)
{
	Item *item;
	item = g_obj->GetItemList()->GetList()[rand() % g_obj->GetItemList()->GetList().size()];
	for (int i = 0; i < g_obj->GetItemList()->GetObjects().size();i++)
		if (g_obj->GetItemList()->GetObjects()[i]->position == position && g_obj->GetItemList()->GetObjects()[i]->item->id==CHEST_ID)
	{
		g_obj->GetItemList()->DeleteFromObjects(i);
		g_obj->GetItemList()->AddDroppedItem((int)(position.x), (int)(position.y), item);
		//g_obj->GetItemList()->GetObjects()[i]->item->id = OPENED_CHEST;
		this->Init(current_map, g_obj);
	}

}


void EventHandler::TriggerEvent(glm::vec2 position, Map *current_map, GameObject *g_obj, Stats *m_stats)
{
	//in g_obj e item_list-ul
	this->Init(current_map, g_obj);


	this->Door(position, current_map, g_obj);
	this->Health(position, current_map, m_stats, g_obj);
	this->OpenChest(position, current_map, g_obj);
	this->PickUp(position, current_map, g_obj);
	this->NextLvl(position, current_map, g_obj);


	if (e_map[(int)(position.x)][(int)(position.y)] == 2)
	{
		n_check = false;
		for (int i = 0; i < g_obj->GetTablets()->size(); i++)
		{
			if (g_obj->GetTablets()->at(i)->pos == position)
				n_check = true;
		}

		if (n_check == false)
		{
			untablet *u_t = new untablet;
			g_obj->unlockedtablets++;

			u_t->frameCon = g_obj->unlockedtablets;
			u_t->frameText = g_obj->unlockedtablets;
			u_t->id = g_obj->unlockedtablets;
			u_t->state = 1;
			u_t->pos = position;

			g_obj->GetTablets()->push_back(u_t);

		}

		for (int i = 0; i < g_obj->GetItemList()->GetObjects().size(); i++)
		{
			if (g_obj->GetItemList()->GetObjects()[i]->position == position && g_obj->GetItemList()->GetObjects()[i]->item->id == TABLET_ID)
			{
				g_obj->GetItemList()->DeleteFromObjects(i);
				break;
			}
		}


	}


}


void EventHandler::DisplayTablet(int id)
{
	
}