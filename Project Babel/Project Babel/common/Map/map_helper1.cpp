#include <common.hpp>



void Map::LoadSprites()
{




	this->m_sprite = new Sprite();



	char ** tex_str = new char*[24];
	tex_str[FLOOR_BLOCK] = "floor.png";
	tex_str[FLOOR_BLOCK1] = "floor-2.png";
	tex_str[FLOOR_BLOCK2] = "floor-3.png";
	tex_str[FLOOR_BLOCK3] = "floor-4.png";
	tex_str[FLOOR_BLOCK_LAST] = "floor-5.png";
	tex_str[OPENED_DOOR_BLOCK] = "door-open.png";
	tex_str[DOOR_BLOCK] = "door.png";

	tex_str[LEFT_STONE_BLOCK] = "left.png";
	tex_str[UP_STONE_BLOCK] = "up.png";
	tex_str[RIGHT_STONE_BLOCK] = "right.png";
	tex_str[DOWN_STONE_BLOCK] = "down.png";


	tex_str[CORNER_NE_BLOCK] = "corner-NE.png";
	tex_str[CORNER_NW_BLOCK] = "corner-NW.png";
	tex_str[CORNER_SW_BLOCK] = "corner-SW.png";
	tex_str[CORNER_SE_BLOCK] = "corner-SE.png";


	tex_str[NE_BLOCK] = "ne.png";
	tex_str[NW_BLOCK] = "nw.png";
	tex_str[SW_BLOCK] = "sw.png";
	tex_str[SE_BLOCK] = "se.png";


	tex_str[DOOR_UP] = "door-up.png";
	tex_str[DOOR_DOWN] = "door-down.png";
	tex_str[DOOR_RIGHT] = "door-right.png";
	tex_str[DOOR_LEFT] = "door-left.png";

	tex_str[BROKEN_DOOR] = "broken-door.png";

	//tex_str[18] = "wall.png";


	this->m_sprite->Load(24, "data/tiles/", tex_str);


	

}

void Map::BossSprites()
{




	//this->m_sprite = new Sprite();



	//char ** tex_str = new char*[7];
	//tex_str[0] = "floor.png";
	//tex_str[1] = "door-open.png";
	//tex_str[2] = "door.png";
	//tex_str[3] = "wall.png";
	//tex_str[4] = "wall-cracked-1.png";
	//tex_str[5] = "wall-cracked-2.png";
	//tex_str[6] = "wall-cracked-3.png";



	//this->m_sprite->Load(7, "data/tiles/boss/", tex_str);
	////this->m_sprite->Load(7, "data/tiles/", tex_str);


	this->m_sprite = new Sprite();



	char ** tex_str = new char*[24];
	tex_str[FLOOR_BLOCK] = "floor.png";
	tex_str[FLOOR_BLOCK1] = "floor-2.png";
	tex_str[FLOOR_BLOCK2] = "floor-3.png";
	tex_str[FLOOR_BLOCK3] = "floor-4.png";
	tex_str[FLOOR_BLOCK_LAST] = "floor-5.png";
	tex_str[OPENED_DOOR_BLOCK] = "door-open.png";
	tex_str[DOOR_BLOCK] = "door.png";

	tex_str[LEFT_STONE_BLOCK] = "left.png";
	tex_str[UP_STONE_BLOCK] = "up.png";
	tex_str[RIGHT_STONE_BLOCK] = "right.png";
	tex_str[DOWN_STONE_BLOCK] = "down.png";


	tex_str[CORNER_NE_BLOCK] = "corner-NE.png";
	tex_str[CORNER_NW_BLOCK] = "corner-NW.png";
	tex_str[CORNER_SW_BLOCK] = "corner-SW.png";
	tex_str[CORNER_SE_BLOCK] = "corner-SE.png";


	tex_str[NE_BLOCK] = "ne.png";
	tex_str[NW_BLOCK] = "nw.png";
	tex_str[SW_BLOCK] = "sw.png";
	tex_str[SE_BLOCK] = "se.png";


	tex_str[DOOR_UP] = "door-up.png";
	tex_str[DOOR_DOWN] = "door-down.png";
	tex_str[DOOR_RIGHT] = "door-right.png";
	tex_str[DOOR_LEFT] = "door-left.png";

	tex_str[BROKEN_DOOR] = "broken-door.png";

	//tex_str[18] = "wall.png";


	this->m_sprite->Load(24, "data/tiles/", tex_str);



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


void Map::AddBossRoom()
{



	this->expected_rooms = 1;


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

		temp->CreateBossRoom();

		/*temp->Create(glm::vec2(Rand(this->tilemap->GetSize().x - 1 - MIN_ROOM_WIDTH), Rand(this->tilemap->GetSize().y - 1 - MIN_ROOM_HEIGHT)),
			Rand(MIN_ROOM_WIDTH, MAX_ROOM_WIDTH),
			Rand(MIN_ROOM_HEIGHT, MAX_ROOM_HEIGHT));
			*/

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