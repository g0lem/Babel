#include <common.hpp>



void Map::AddTunnel(glm::ivec2 point_a, glm::ivec2 point_b)
{




	glm::ivec2 begin_limit = glm::min(point_a, point_b);


	glm::ivec2 end_limit = glm::max(point_a, point_b);


	GLuint values[4] = { 2, 1, 1, 1 };


	for (GLuint j = begin_limit.y; j <= end_limit.y; j++)
	{


		if (this->tilemap->GetTiles()[point_a.x - 1][j] == NO_BLOCK)
			this->tilemap->GetTiles()[point_a.x - 1][j] = Dice::Get(values, 4, 5) + SOLID_LIMIT;


		this->tilemap->GetTiles()[point_a.x][j] = FLOOR_BLOCK;


		if (this->tilemap->GetTiles()[point_a.x + 1][j] == NO_BLOCK)
			this->tilemap->GetTiles()[point_a.x + 1][j] = Dice::Get(values, 4, 5) + SOLID_LIMIT;




	}




	for (GLuint i = begin_limit.x; i <= end_limit.x; i++)
	{


		if (this->tilemap->GetTiles()[i][point_b.y - 1] == NO_BLOCK)
			this->tilemap->GetTiles()[i][point_b.y - 1] = STONE_BLOCK;


		this->tilemap->GetTiles()[i][point_b.y] = FLOOR_BLOCK;


		if (this->tilemap->GetTiles()[i][point_b.y + 1] == NO_BLOCK)
			this->tilemap->GetTiles()[i][point_b.y + 1] = STONE_BLOCK;




	}






	glm::ivec2 intersection_point;


	if (glm::ivec2(point_a.x, begin_limit.y) == point_a)
		intersection_point = glm::ivec2(point_a.x, end_limit.y);
	else
		intersection_point = glm::ivec2(point_a.x, begin_limit.y);




	

	if (this->tilemap->GetTiles()[intersection_point.x - 1][intersection_point.y - 1] == NO_BLOCK)
		this->tilemap->GetTiles()[intersection_point.x - 1][intersection_point.y - 1] = STONE_BLOCK;

	if (this->tilemap->GetTiles()[intersection_point.x + 1][intersection_point.y - 1] == NO_BLOCK)
		this->tilemap->GetTiles()[intersection_point.x + 1][intersection_point.y - 1] = STONE_BLOCK;

	if (this->tilemap->GetTiles()[intersection_point.x - 1][intersection_point.y + 1] == NO_BLOCK)
		this->tilemap->GetTiles()[intersection_point.x - 1][intersection_point.y + 1] = STONE_BLOCK;

	if (this->tilemap->GetTiles()[intersection_point.x + 1][intersection_point.y + 1] == NO_BLOCK)
		this->tilemap->GetTiles()[intersection_point.x + 1][intersection_point.y + 1] = STONE_BLOCK;





}



void Map::AddDoors()
{


	for (GLuint k = 0; k < rooms->size(); k++)
	{


		Room * room = rooms[0][k];


		for (GLuint i = 0; i < room->GetWidth(); i++)
		{


			GLuint door_x = i + room->GetOffset().x;
			GLuint door_y = room->GetOffset().y;


			if  (this->tilemap->GetTiles()[door_x][door_y] == FLOOR_BLOCK &&
				(
				
				
				
				(this->tilemap->GetTiles()[door_x - 1][door_y] >= SOLID_LIMIT &&
				this->tilemap->GetTiles()[door_x + 1][door_y] >= SOLID_LIMIT)



				||
				
				
				(this->tilemap->GetTiles()[door_x][door_y - 1] >= SOLID_LIMIT &&
				this->tilemap->GetTiles()[door_x][door_y + 1] >= SOLID_LIMIT)


				)
				)


			{


				this->tilemap->GetTiles()[door_x][door_y] = DOOR_BLOCK;


			}




			if (this->tilemap->GetTiles()[door_x][door_y + room->GetHeight() - 1] == FLOOR_BLOCK &&
			   (




				(this->tilemap->GetTiles()[door_x - 1][door_y + room->GetHeight() - 1] >= SOLID_LIMIT &&
				this->tilemap->GetTiles()[door_x + 1][door_y + room->GetHeight() - 1] >= SOLID_LIMIT)



				||


				(this->tilemap->GetTiles()[door_x][door_y + room->GetHeight() - 1 - 1] >= SOLID_LIMIT &&
				this->tilemap->GetTiles()[door_x][door_y + room->GetHeight() - 1 + 1] >= SOLID_LIMIT)



				)
				)




			{


				this->tilemap->GetTiles()[door_x][door_y + room->GetHeight() - 1] = DOOR_BLOCK;


			}





		}


		for (GLuint j = 0; j < room->GetWidth(); j++)
		{


			GLuint door_x = room->GetOffset().x;
			GLuint door_y = j + room->GetOffset().y;


			if (this->tilemap->GetTiles()[door_x][door_y] == FLOOR_BLOCK &&
			   (




				(this->tilemap->GetTiles()[door_x - 1][door_y] >= SOLID_LIMIT &&
				this->tilemap->GetTiles()[door_x + 1][door_y] >= SOLID_LIMIT)



				||


				(this->tilemap->GetTiles()[door_x][door_y - 1] >= SOLID_LIMIT &&
				this->tilemap->GetTiles()[door_x][door_y + 1] >= SOLID_LIMIT)


				)
				)


			{


				this->tilemap->GetTiles()[door_x][door_y] = DOOR_BLOCK;

				
			}



			
			if (this->tilemap->GetTiles()[door_x + room->GetWidth() - 1][door_y] == FLOOR_BLOCK &&
			   (



				(this->tilemap->GetTiles()[door_x + room->GetWidth() - 1 - 1][door_y] >= SOLID_LIMIT &&
				this->tilemap->GetTiles()[door_x + room->GetWidth() - 1 + 1][door_y] >= SOLID_LIMIT)



				||


				(this->tilemap->GetTiles()[door_x + room->GetWidth() - 1][door_y - 1] >= SOLID_LIMIT && 
				this->tilemap->GetTiles()[door_x + room->GetWidth() - 1][door_y + 1] >= SOLID_LIMIT)


				)
				)




			{


				this->tilemap->GetTiles()[door_x + room->GetWidth() - 1][door_y] = DOOR_BLOCK;


			}





		}





	}




	for (GLuint j = 0; j < this->tilemap->GetSize().y; j++)
	{


		for (GLuint i = 0; i < this->tilemap->GetSize().x; i++)


		{


			if (this->tilemap->GetTiles()[i][j] == DOOR_BLOCK)
			{


				if (this->tilemap->GetTiles()[i - 1][j] == DOOR_BLOCK)
					this->tilemap->GetTiles()[i - 1][j] = FLOOR_BLOCK;


				if (this->tilemap->GetTiles()[i + 1][j] == DOOR_BLOCK)
					this->tilemap->GetTiles()[i + 1][j] = FLOOR_BLOCK;


				if (this->tilemap->GetTiles()[i][j - 1] == DOOR_BLOCK)
					this->tilemap->GetTiles()[i][j - 1] = FLOOR_BLOCK;


				if (this->tilemap->GetTiles()[i][j + 1] == DOOR_BLOCK)
					this->tilemap->GetTiles()[i][j + 1] = FLOOR_BLOCK;



              

			}


		}



	}



	//this->AddPotions();

}


void Map::AddTablets(GameObject *g_obj)
{
	int x, y;
	int tablets_added=0;
	while (tablets_added < 1)
	{
		x = rand() % (tilemap->GetSize().x);
		y = rand() % (tilemap->GetSize().y);
		if (this->tilemap->GetTiles()[x][y] == 0)
		{
			g_obj->GetItemList()->SpawnObject(TABLET_ID, glm::vec2(x, y));
			tablets_added++;
		}
	}
}

void Map::AddStairs(GameObject *g_obj)
{
	int x, y;
	int tablets_added = 0;
	while (tablets_added < 1)
	{
		x = rand() % (tilemap->GetSize().x);
		y = rand() % (tilemap->GetSize().y);
		if (this->tilemap->GetTiles()[x][y] == 0)
		{
			g_obj->GetItemList()->SpawnObject(STAIRS_ID, (glm::vec2)(this->GetRoomsPointer()[0][1]->GetInternalCenter()));
			tablets_added++;
		}
	}
	
}

void Map::AddSpikes(GameObject *g_obj)
{
	int x, y;
	int tablets_added = 0;
	while (tablets_added < 20)
	{
		x = rand() % (tilemap->GetSize().x);
		y = rand() % (tilemap->GetSize().y);
		if (this->tilemap->GetTiles()[x][y] == 0)
		{
			g_obj->GetItemList()->SpawnObject(SPIKES_ID, glm::vec2(x, y));
			tablets_added++;
		}
	}
}



/*
void Map::AddPotions()
{
	int x, y;
	int potions_added=0, potions = rand()%2+1;
	while (potions_added <= potions)
	{
		x = rand() % (tilemap->GetSize().x);
		y = rand() % (tilemap->GetSize().y);
		if (this->tilemap->GetTiles()[x][y] == 0)
		{
			ItemList::AddDroppedItem(TABLET_ID, glm::vec2(x, y));
			potions_added++;
		}
	}
}

*/


