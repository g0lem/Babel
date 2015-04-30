#include <common.hpp>



void CollisionMap::Init()
{



	this->tiles = 0;


	this->size = vec2_0;


}



void CollisionMap::CreateOutOfMap(Tilemap * map)
{



	this->size = map->GetSize();


	this->tiles = new GLboolean*[this->size.x];
	for (GLuint i = 0; i < this->size.x; i++)
		this->tiles[i] = new GLboolean[this->size.y];



	for (GLuint j = 0; j < this->size.y; j++)
	{


		for (GLuint i = 0; i < this->size.x; i++)


		{


			this->tiles[i][j] = (map->GetTiles()[i][j] >= SOLID_LIMIT || map->GetTiles()[i][j]==DOOR_BLOCK);


		}



	}

	this->size = map->GetSize();


	this->player_tiles = new GLboolean*[this->size.x];
	for (GLuint i = 0; i < this->size.x; i++)
		this->player_tiles[i] = new GLboolean[this->size.y];



	for (GLuint j = 0; j < this->size.y; j++)
	{


		for (GLuint i = 0; i < this->size.x; i++)


		{


			this->player_tiles[i][j] = (map->GetTiles()[i][j] >= SOLID_LIMIT);
			if (map->GetTiles()[i][j] == DOOR_BLOCK)
				this->player_tiles[i][j] = 0;

		}



	}


	this->visible_tiles = new GLboolean*[this->size.x];
	for (GLuint i = 0; i < this->size.x; i++)
		this->visible_tiles[i] = new GLboolean[this->size.y];



	for (GLuint j = 0; j < this->size.y; j++)
	{


		for (GLuint i = 0; i < this->size.x; i++)


		{


			this->visible_tiles[i][j] = (map->GetTiles()[i][j] >= SOLID_LIMIT || map->GetTiles()[i][j] == DOOR_BLOCK);


		}



	}




}


void CollisionMap::AddSolid(glm::vec2 position)
{
	
		this->tiles[(int)(position.x)][(int)(position.y)] = true;
		this->player_tiles[(int)(position.x)][(int)(position.y)] = true;
	
}