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



}