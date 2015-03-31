#include <common.hpp>



void Map::LoadSprites()
{




	this->m_sprite = new Sprite();



	char ** tex_str = new char*[9];
	tex_str[0] = "floor.png";
	tex_str[1] = "door-open.png";
	tex_str[2] = "door.png";
	tex_str[3] = "tablet.png";
	tex_str[4] = "health_potion.png";
	tex_str[5] = "wall0.png";
	tex_str[6] = "wall1.png";
	tex_str[7] = "wall2.png";
	tex_str[8] = "wall3.png";



	this->m_sprite->Load(9, "data/tiles/", tex_str);

}




void Map::AddRooms(GLuint expected_rooms)
{



	this->expected_rooms = expected_rooms;


	GLuint tries = 0;


	this->rooms = new 	std::vector < Room* >;


	while (this->rooms->size() < this->expected_rooms)
	{

		Room * temp = new Room();


		if (tries > 9)
		{
			this->expected_rooms--;
			tries = 0;
		}



		tries++;



		temp->Create(glm::vec2(Rand(this->tilemap->GetSize().x - 1 - MIN_ROOM_WIDTH), Rand(this->tilemap->GetSize().y - 1 - MIN_ROOM_HEIGHT)),
			Rand(MIN_ROOM_WIDTH, MAX_ROOM_WIDTH),
			Rand(MIN_ROOM_HEIGHT, MAX_ROOM_HEIGHT));


		if (temp->InsideMap(this->tilemap->GetSize().x, this->tilemap->GetSize().y))
		{

			GLboolean result = true;

			for (GLuint i = 0; i < this->rooms->size(); i++)
				if (temp->Intersects(this->rooms[0][i]))
				{
				result = false;
				break;
				}

			if (result)

			{



				this->TransformAndApplyRoomToTileMap(temp, this->tilemap, EMPTY_ROOM);


				this->rooms->push_back(temp);

			}


		}

	}





}