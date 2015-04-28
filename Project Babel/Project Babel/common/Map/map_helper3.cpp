#include <common.hpp>



void Map::AddTunnel(glm::ivec2 point_a, glm::ivec2 point_b)
{




	glm::ivec2 begin_limit = glm::min(point_a, point_b);


	glm::ivec2 end_limit = glm::max(point_a, point_b);


	GLuint values[4] = { 2, 1, 1, 1 };
	GLuint values2[4] = { 8, 8, 2, 1 };

	/*this->wall_list.push_back(new Wall(glm::vec2(point_a.x - 1, begin_limit.y-1), WALL_SE));
	this->wall_list.push_back(new Wall(glm::vec2(point_a.x + 1, begin_limit.y-1), WALL_SE));*/


	if (this->tilemap->GetTiles()[point_a.x - 1][begin_limit.y - 1] == NO_BLOCK)
		this->tilemap->GetTiles()[point_a.x - 1][begin_limit.y - 1] = VISIBLE_WALL;

	if (this->tilemap->GetTiles()[point_a.x + 1][begin_limit.y - 1] == NO_BLOCK)
		this->tilemap->GetTiles()[point_a.x + 1][begin_limit.y - 1] = VISIBLE_WALL;


	for (GLuint j = begin_limit.y; j <= end_limit.y; j++)
	{

		/*this->wall_list.push_back(new Wall(glm::vec2(point_a.x - 1, j + 1), WALL_NE));
		this->wall_list.push_back(new Wall(glm::vec2(point_a.x + 1, j + 1), WALL_NW));*/

		if (this->tilemap->GetTiles()[point_a.x - 1][j+1] == NO_BLOCK)
			this->tilemap->GetTiles()[point_a.x - 1][j + 1] = VISIBLE_WALL;

		if (this->tilemap->GetTiles()[point_a.x + 1][j + 1] == NO_BLOCK)
			this->tilemap->GetTiles()[point_a.x + 1][j + 1] = VISIBLE_WALL;

		if (this->tilemap->GetTiles()[point_a.x - 1][j] == NO_BLOCK)
		{
			this->tilemap->GetTiles()[point_a.x - 1][j] = VISIBLE_WALL;
			
		}

		//this->wall_list.push_back(new Wall(glm::vec2(point_a.x - 1, j), WALL_RIGHT));
		
		this->tilemap->GetTiles()[point_a.x][j] = FLOOR_BLOCK;


		if (this->tilemap->GetTiles()[point_a.x + 1][j] == NO_BLOCK)
		{
			this->tilemap->GetTiles()[point_a.x + 1][j] = VISIBLE_WALL;
		
		}

		/*this->wall_list.push_back(new Wall(glm::vec2(point_a.x + 1, j), WALL_LEFT));*/


	}
	

	/*this->wall_list.push_back(new Wall(glm::vec2(begin_limit.x, point_b.y - 1), WALL_SW));
	this->wall_list.push_back(new Wall(glm::vec2(begin_limit.x, point_b.y + 1), WALL_NW));*/

	if (this->tilemap->GetTiles()[begin_limit.x][point_b.y - 1] == NO_BLOCK)
		this->tilemap->GetTiles()[begin_limit.x][point_b.y - 1] = VISIBLE_WALL;
	if (this->tilemap->GetTiles()[begin_limit.x][point_b.y + 1] == NO_BLOCK)
		this->tilemap->GetTiles()[begin_limit.x][point_b.y + 1] = VISIBLE_WALL;


	for (GLuint i = begin_limit.x; i <= end_limit.x; i++)
	{
		/*this->wall_list.push_back(new Wall(glm::vec2(i + 1, point_b.y - 1), WALL_SW));
		this->wall_list.push_back(new Wall(glm::vec2(i + 1, point_b.y + 1), WALL_NW));*/

		if (this->tilemap->GetTiles()[i + 1][point_b.y - 1] == NO_BLOCK)
		{
			this->tilemap->GetTiles()[i + 1][point_b.y - 1] = VISIBLE_WALL;
		}
		if (this->tilemap->GetTiles()[i][point_b.y + 1] == NO_BLOCK)
		{
			this->tilemap->GetTiles()[i + 1][point_b.y + 1] = VISIBLE_WALL;
		}
		if (this->tilemap->GetTiles()[i][point_b.y - 1] == NO_BLOCK)
		{
			this->tilemap->GetTiles()[i][point_b.y - 1] = VISIBLE_WALL;
		
		}
	/*this->wall_list.push_back(new Wall(glm::vec2(i , point_b.y - 1), WALL_UP));*/
		this->tilemap->GetTiles()[i][point_b.y] = FLOOR_BLOCK;


		if (this->tilemap->GetTiles()[i][point_b.y + 1] == NO_BLOCK)
		{
			this->tilemap->GetTiles()[i][point_b.y + 1] = VISIBLE_WALL;
	
		}

		/*this->wall_list.push_back(new Wall(glm::vec2(i, point_b.y + 1), WALL_DOWN));*/

	

	}
	




	glm::ivec2 intersection_point;


	if (glm::ivec2(point_a.x, begin_limit.y) == point_a)
		intersection_point = glm::ivec2(point_a.x, end_limit.y);
	else
		intersection_point = glm::ivec2(point_a.x, begin_limit.y);




	

	if (this->tilemap->GetTiles()[intersection_point.x - 1][intersection_point.y - 1] == NO_BLOCK)
		this->tilemap->GetTiles()[intersection_point.x - 1][intersection_point.y - 1] = VISIBLE_WALL;

	if (this->tilemap->GetTiles()[intersection_point.x + 1][intersection_point.y - 1] == NO_BLOCK)
		this->tilemap->GetTiles()[intersection_point.x + 1][intersection_point.y - 1] = VISIBLE_WALL;

	if (this->tilemap->GetTiles()[intersection_point.x - 1][intersection_point.y + 1] == NO_BLOCK)
		this->tilemap->GetTiles()[intersection_point.x - 1][intersection_point.y + 1] = VISIBLE_WALL;

	if (this->tilemap->GetTiles()[intersection_point.x + 1][intersection_point.y + 1] == NO_BLOCK)
		this->tilemap->GetTiles()[intersection_point.x + 1][intersection_point.y + 1] = VISIBLE_WALL;





}



void Map::AddDoors()
{

	srand(time(NULL));

	GLuint values[4] = { 8, 8, 2, 1 };


	int add = 0;

	for (GLuint k = 0; k < rooms->size(); k++)
	{


		Room * room = rooms[0][k];


		for (GLuint i = 0; i < room->GetWidth(); i++)
		{


			GLuint door_x = i + room->GetOffset().x;
			GLuint door_y = room->GetOffset().y;


			if (this->tilemap->GetTiles()[door_x][door_y] == FLOOR_BLOCK  &&
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


			if (this->tilemap->GetTiles()[door_x][door_y] == FLOOR_BLOCK  &&
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
					this->tilemap->GetTiles()[i - 1][j] = FLOOR_BLOCK ;


				if (this->tilemap->GetTiles()[i + 1][j] == DOOR_BLOCK)
					this->tilemap->GetTiles()[i + 1][j] = FLOOR_BLOCK ;


				if (this->tilemap->GetTiles()[i][j - 1] == DOOR_BLOCK)
					this->tilemap->GetTiles()[i][j - 1] = FLOOR_BLOCK ;


				if (this->tilemap->GetTiles()[i][j + 1] == DOOR_BLOCK)
					this->tilemap->GetTiles()[i][j + 1] = FLOOR_BLOCK ;



              

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

void Map::AddChests(GameObject *g_obj)
{
	int x, y, random;
	int tablets_added = 0;
	
	while (tablets_added < 10) //10 is the number of chests
	{
		random = Rand(this->rooms->size());
		x = Rand(this->rooms->at(random)->GetOffset().x + 1, this->rooms->at(random)->GetEndOffset().x - 2);
		y = Rand(this->rooms->at(random)->GetOffset().y + 1, this->rooms->at(random)->GetEndOffset().y - 2);
		if (this->tilemap->GetTiles()[x][y] == 0)
		{
			g_obj->GetItemList()->SpawnObject(CHEST_ID, glm::vec2(x, y));
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

void Map::Decorate(GameObject *g_obj)
{
	

	for (int i = 0; i < this->GetRoomsPointer()[0].size(); i++)
	{
		if (this->GetRoomsPointer()[0][i]->GetHeight() == this->GetRoomsPointer()[0][i]->GetWidth() && this->GetRoomsPointer()[0][i]->GetWidth() % 2 == 1 && this->GetRoomsPointer()[0][i]->GetHeight()>=7)
		{
		
			if (rand() % 2 == 0)
			{


				g_obj->SpawnSolidObject(PILLAR_ID, glm::vec2(this->GetRoomsPointer()[0][i]->GetOffset() + 2));

				g_obj->SpawnSolidObject(PILLAR_ID, glm::vec2(this->GetRoomsPointer()[0][i]->GetOffset().x + 2, this->GetRoomsPointer()[0][i]->GetEndOffset().y - 3));

				g_obj->SpawnSolidObject(PILLAR_ID, glm::vec2(this->GetRoomsPointer()[0][i]->GetEndOffset().x - 3, this->GetRoomsPointer()[0][i]->GetOffset().y + 2));

				g_obj->SpawnSolidObject(PILLAR_ID, glm::vec2(this->GetRoomsPointer()[0][i]->GetEndOffset() - 3));
			}
			else 
			{
				g_obj->SpawnSolidObject(PILLAR_ID, glm::vec2(this->GetRoomsPointer()[0][i]->GetInternalCenter()));

				g_obj->SpawnSolidObject(STATUE_ID, glm::vec2(this->GetRoomsPointer()[0][i]->GetInternalCenter().x - 1, this->GetRoomsPointer()[0][i]->GetInternalCenter().y));

				g_obj->SpawnSolidObject(STATUE_ID, glm::vec2(this->GetRoomsPointer()[0][i]->GetInternalCenter().x + 1, this->GetRoomsPointer()[0][i]->GetInternalCenter().y));

				g_obj->SpawnSolidObject(STATUE_ID, glm::vec2(this->GetRoomsPointer()[0][i]->GetInternalCenter().x, this->GetRoomsPointer()[0][i]->GetInternalCenter().y + 1));

				g_obj->SpawnSolidObject(STATUE_ID, glm::vec2(this->GetRoomsPointer()[0][i]->GetInternalCenter().x, this->GetRoomsPointer()[0][i]->GetInternalCenter().y - 1));

			}
		}
		else
			if (this->GetRoomsPointer()[0][i]->GetWidth() % 2 == 1 && this->GetRoomsPointer()[0][i]->GetHeight() % 2 == 1 && this->GetRoomsPointer()[0][i]->GetHeight() >= 7 && this->GetRoomsPointer()[0][i]->GetWidth() >= 7)
			{

			//g_obj->SpawnSolidObject(PILLAR_ID, glm::vec2(this->GetRoomsPointer()[0][i]->GetInternalCenter())); -- chest coords

			g_obj->GetItemList()->SpawnObject(CHEST_ID, glm::vec2(this->GetRoomsPointer()[0][i]->GetInternalCenter()));

			g_obj->SpawnSolidObject(PILLAR_ID, glm::vec2(this->GetRoomsPointer()[0][i]->GetInternalCenter().x - 1, this->GetRoomsPointer()[0][i]->GetInternalCenter().y));

			g_obj->SpawnSolidObject(PILLAR_ID, glm::vec2(this->GetRoomsPointer()[0][i]->GetInternalCenter().x + 1, this->GetRoomsPointer()[0][i]->GetInternalCenter().y));

			//g_obj->SpawnSolidObject(PILLAR_ID, glm::vec2(this->GetRoomsPointer()[0][i]->GetInternalCenter().x, this->GetRoomsPointer()[0][i]->GetInternalCenter().y + 1));

			g_obj->SpawnSolidObject(PILLAR_ID, glm::vec2(this->GetRoomsPointer()[0][i]->GetInternalCenter().x, this->GetRoomsPointer()[0][i]->GetInternalCenter().y - 1));


			}

		if (this->tilemap->GetTiles()[(int)(this->GetRoomsPointer()[0][i]->GetInternalCenter().x)][(int)(this->GetRoomsPointer()[0][i]->GetOffset().y)] == DOOR_BLOCK &&
			this->tilemap->GetTiles()[(int)(this->GetRoomsPointer()[0][i]->GetOffset().x)][(int)(this->GetRoomsPointer()[0][i]->GetInternalCenter().y)] == DOOR_BLOCK &&
			this->tilemap->GetTiles()[(int)(this->GetRoomsPointer()[0][i]->GetInternalCenter().x)][(int)(this->GetRoomsPointer()[0][i]->GetEndOffset().y - 1)] == DOOR_BLOCK &&
			this->tilemap->GetTiles()[(int)(this->GetRoomsPointer()[0][i]->GetEndOffset().x - 1)][(int)(this->GetRoomsPointer()[0][i]->GetInternalCenter().y)] == DOOR_BLOCK)
		{
			

			g_obj->SpawnSolidObject(STATUE_ID, glm::vec2(this->GetRoomsPointer()[0][i]->GetInternalCenter().x - 1, this->GetRoomsPointer()[0][i]->GetOffset().y + 1));
			g_obj->SpawnSolidObject(STATUE_ID, glm::vec2(this->GetRoomsPointer()[0][i]->GetInternalCenter().x + 1, this->GetRoomsPointer()[0][i]->GetOffset().y + 1));

			g_obj->SpawnSolidObject(STATUE_ID, glm::vec2(this->GetRoomsPointer()[0][i]->GetOffset().x + 1, this->GetRoomsPointer()[0][i]->GetInternalCenter().y + 1));
			g_obj->SpawnSolidObject(STATUE_ID, glm::vec2(this->GetRoomsPointer()[0][i]->GetOffset().x + 1, this->GetRoomsPointer()[0][i]->GetInternalCenter().y - 1));

			g_obj->SpawnSolidObject(STATUE_ID, glm::vec2(this->GetRoomsPointer()[0][i]->GetInternalCenter().x - 1, this->GetRoomsPointer()[0][i]->GetEndOffset().y - 2));
			g_obj->SpawnSolidObject(STATUE_ID, glm::vec2(this->GetRoomsPointer()[0][i]->GetInternalCenter().x + 1, this->GetRoomsPointer()[0][i]->GetEndOffset().y - 2));

			g_obj->SpawnSolidObject(STATUE_ID, glm::vec2(this->GetRoomsPointer()[0][i]->GetEndOffset().x - 2, this->GetRoomsPointer()[0][i]->GetInternalCenter().y + 1));
			g_obj->SpawnSolidObject(STATUE_ID, glm::vec2(this->GetRoomsPointer()[0][i]->GetEndOffset().x - 2, this->GetRoomsPointer()[0][i]->GetInternalCenter().y - 1));
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


