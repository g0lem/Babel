//Checked 1



#include <common.hpp>




void Map::Init(GameObject *g_obj)
{


	this->LoadSprites();

	

	this->GenerateContent(g_obj);




}


void Map::InitBoss(GameObject *g_obj)
{


	this->BossSprites();



	this->GenerateBossRoom(g_obj);




}




void Map::GenerateContent(GameObject *g_obj)
{


	this->tilemap = new Tilemap();

	this->tilemap->Init();


	this->wall_score = new int**[this->tilemap->GetSize().x];
	for (int i = 0; i < this->tilemap->GetSize().x; i++)
	{
		this->wall_score[i] = new int*[this->tilemap->GetSize().y];
		for (int j = 0; j < this->tilemap->GetSize().y; j++)
		{
			//std::cout << i << " " << j << std::endl;
			this->wall_score[i][j] = new int[4];

			this->wall_score[i][j][0] = 0;
			this->wall_score[i][j][1] = 0;
			this->wall_score[i][j][2] = 0;
			this->wall_score[i][j][3] = 0;

		}
	}



	this->GenerateScore();

	this->AddRooms(15);
	

	this->m_graph = new Graph(this->rooms->size());


	this->FirstTunnelPass();


	this->SecondTunnelPass();


	this->AddDoors();


	this->AddTablets(g_obj);
	this->AddStairs(g_obj);
	this->Decorate(g_obj);
	this->AddChests(g_obj);

	g_obj->GetCollisionMap()->CreateOutOfMap(this->GetTilemap());


	this->fog = new fog_of_war();
	fog->Init(g_obj);
	


}

void Map::GenerateBossRoom(GameObject *g_obj)
{
	this->tilemap = new Tilemap();

	this->tilemap->Init();

	//this->AddRooms(1);
	this->AddBossRoom();
	

	
	this->tilemap->GenerateBossRoom();



	g_obj->GetCollisionMap()->CreateOutOfMap(this->GetTilemap());


	this->fog = new fog_of_war();
	fog->Init(g_obj);
	



	/*this->tilemap = new Tilemap();

	this->tilemap->Init();


	this->AddRooms(2);


	this->m_graph = new Graph(this->rooms->size());


	this->FirstTunnelPass();


	this->SecondTunnelPass();


	this->AddDoors();


	this->AddTablets(g_obj);
	this->AddStairs(g_obj);


	g_obj->GetCollisionMap()->CreateOutOfMap(this->GetTilemap());


	this->fog = new fog_of_war();
	fog->Init(g_obj);
	*/

}





void Map::Render(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj, glm::vec2 position)
{
	
	//this->fog->Render(ctrl, u_data, glm::vec2((g_obj->GetScroller()->GetBeginLimit() + g_obj->GetScroller()->GetEndLimit())/2), g_obj);


	fog->MakeTexture(g_obj, glm::ivec2(position));


	this->Render(ctrl, u_data, this->m_sprite,
		g_obj->GetScroller()->GetBeginLimit(),
		g_obj->GetScroller()->GetEndLimit(),
		g_obj->GetScroller()->GetOffset(),
		fog->GetTexture(), 
		fog->GetFOW(g_obj,glm::ivec2(position)),
		g_obj->GetItemList());




	//this->tilemap->SmootherFOW(fog->GetFOW(g_obj, glm::ivec2(position)), glm::ivec2(position), u_data);



}

void Map::GenerateScore()
{
	

	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };
	int walls[4];


	for (int j = 0; j < this->tilemap->GetSize().y; j++)
	for (int i = 0; i < this->tilemap->GetSize().x;i++)	
		{ 
		

			for (int x = 0; x < 4; x++)
			{
				walls[x] = 0;
				if (i + dx[x] >= 0 && i + dx[x] < this->tilemap->GetSize().x && j + dy[x] >= 0 && j + dy[x] < this->tilemap->GetSize().y)
					if (this->tilemap->GetTiles()[i][j] >= SOLID_LIMIT)
						walls[x] = 1;
			}
			
			if ((walls[0] == walls[1] || (walls[0] == DOOR_BLOCK && walls[1] >= SOLID_LIMIT) || (walls[0] >= SOLID_LIMIT == DOOR_BLOCK && walls[1] == DOOR_BLOCK)) && walls[0] != walls[3] && walls[0] != walls[2])
				{
					if (walls[0] >= SOLID_LIMIT)
					{
						if (walls[3] >= FLOOR_BLOCK && walls[3] < SOLID_LIMIT)
						{
						
							this->wall_score[i][j][0] = 1;
							this->wall_score[i][j][1] = 1;
						}


						if (walls[2] >= FLOOR_BLOCK && walls[2] < SOLID_LIMIT)
						{
							
							this->wall_score[i][j][2] = 1;
							this->wall_score[i][j][3] = 1;
						}
					}
				}
				else if ((walls[2] == walls[3] || (walls[2] == DOOR_BLOCK && walls[3] >= SOLID_LIMIT) || (walls[2] >= SOLID_LIMIT == DOOR_BLOCK && walls[3] == DOOR_BLOCK)) && walls[2] != walls[0] && walls[2] != walls[1])
				{
					if (walls[2] >= SOLID_LIMIT)
					{
						if (walls[0] >= FLOOR_BLOCK && walls[0] < SOLID_LIMIT)
						{
							this->wall_score[i][j][0] = 1;
							this->wall_score[i][j][3] = 1;
						}
						if (walls[1] >= FLOOR_BLOCK && walls[1] < SOLID_LIMIT)
						{
							this->wall_score[i][j][1] = 1;
							this->wall_score[i][j][2] = 1;
						}
					}
				}
			
			//beware of cancer

			if (walls[0] == 1)
			{
				if (walls[1] == 1)
				{
					if (walls[2] == 0)
					{
						this->wall_score[i][j][2] = 1;
						this->wall_score[i][j][3] = 1;
					}
					if (walls[3] == 0)
					{
						this->wall_score[i][j][0] = 1;
						this->wall_score[i][j][1] = 1;
					}
				}

				if (walls[2] == 1)
					this->wall_score[i][j][3] = 1;

				if (walls[3] == 1)
					this->wall_score[i][j][0] = 1;
			}

			if (walls[1] == 1)
			{
				if (walls[0] == 1)
				{
					if (walls[2] == 0)
					{
						this->wall_score[i][j][2] = 1;
						this->wall_score[i][j][3] = 1;
					}
					if (walls[3] == 0)
					{
						this->wall_score[i][j][0] = 1;
						this->wall_score[i][j][1] = 1;
					}
				}

				if (walls[2] == 1)
					this->wall_score[i][j][2] = 1;

				if (walls[3] == 1)
					this->wall_score[i][j][1] = 1;
			}

			if (walls[2] == 1)
			{
				if (walls[3] == 1)
				{
					if (walls[0] == 0)
					{
						this->wall_score[i][j][0] = 1;
						this->wall_score[i][j][3] = 1;
					}
					if (walls[1] == 0)
					{
						this->wall_score[i][j][2] = 1;
						this->wall_score[i][j][1] = 1;
					}
				}

				if (walls[0] == 1)
					this->wall_score[i][j][3] = 1;

				if (walls[1] == 1)
					this->wall_score[i][j][2] = 1;
			}

			if (walls[3] == 1)
			{
				if (walls[2] == 1)
				{
					if (walls[0] == 0)
					{
						this->wall_score[i][j][0] = 1;
						this->wall_score[i][j][3] = 1;
					}
					if (walls[1] == 0)
					{
						this->wall_score[i][j][2] = 1;
						this->wall_score[i][j][1] = 1;
					}
				}

				if (walls[0] == 1)
					this->wall_score[i][j][0] = 1;

				if (walls[1] == 1)
					this->wall_score[i][j][1] = 1;
			}
			//std::cout << "coords: " << i << "  " << j << std::endl;
		//	std::cout << this->wall_score[i][j][0] << " " << this->wall_score[i][j][1] << " " << this->wall_score[i][j][2] << " " << this->wall_score[i][j][3] << std::endl;
		}

}









void Map::Render(Controller * ctrl, ScreenUniformData * u_data, Sprite * m_sprite,
	glm::ivec2 begin_limit, glm::ivec2 end_limit,
	glm::vec2 offset, GLuint texture, float ** fog, ItemList *item_list)
{
	this->GenerateScore();

	for (int j = begin_limit.y; j < end_limit.y; j++)
	{



		for (int i = begin_limit.x; i < end_limit.x; i++)
		{



			if (this->tilemap->boss_lvl == false)
			{
				u_data->SetNewUV(glm::vec4(i - 1, j, 48, 48));
				this->tilemap->GetDark()->RenderTexture(texture);
				u_data->SetNewUV(glm::vec4(-1, -1, 48, 48));
			}
			else
			{
				u_data->SetNewUV(glm::vec4(i - 1, j, 20, 20));
				this->tilemap->GetDark()->RenderTexture(texture);
				u_data->SetNewUV(glm::vec4(-1, -1, 20, 20));
			}

			u_data->SetAmbientLight(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
			u_data->ApplyMatrix(Translation(glm::vec2(i, j)*this->tilemap->GetTileScale() + offset)*Scale(this->tilemap->GetTileScale()));
			m_sprite->Render(this->tilemap->GetTiles()[i][j]);




		
		
			
				
			


		}

		

	}


	int x, y;

	for (int i = 0; i < item_list->GetDroppedItems().size(); i++)
	{
		x = item_list->GetDroppedItems()[i]->position.x;
		y = item_list->GetDroppedItems()[i]->position.y;




		glm::vec3 temp = glm::vec3(1.0f) * (1 - fog[x][y]);
		u_data->SetAmbientLight(glm::vec4(temp.x, temp.y, temp.y, 1.0f));
		u_data->ApplyMatrix(Translation(glm::vec2(x * 64 + 16, y * 64 + 16) + offset)*Scale(glm::vec2(32, 32)));
		item_list->GetSprite()->Render(item_list->GetDroppedItems()[i]->item->frame);





	}

	for (int i = 0; i < item_list->GetObjects().size(); i++)
	{
		x = item_list->GetObjects()[i]->position.x;
		y = item_list->GetObjects()[i]->position.y;




		glm::vec3 temp = glm::vec3(1.0f) * (1 - fog[x][y]);
		u_data->SetAmbientLight(glm::vec4(temp.x, temp.y, temp.y, 1.0f));
		u_data->ApplyMatrix(Translation(glm::vec2(x * 64, y * 64) + offset)*Scale(glm::vec2(64, 64)));
		item_list->GetObjectSprite()->Render(item_list->GetObjects()[i]->item->id);





	}

	for (int i = 0; i < item_list->GetTraps().size(); i++)
	{
		x = item_list->GetTraps()[i]->position.x;
		y = item_list->GetTraps()[i]->position.y;




		glm::vec3 temp = glm::vec3(1.0f) * (1 - fog[x][y]);
		u_data->SetAmbientLight(glm::vec4(temp.x, temp.y, temp.y, 1.0f));
		u_data->ApplyMatrix(Translation(glm::vec2(x * 64, y * 64) + offset)*Scale(glm::vec2(64, 64)));
		item_list->GetObjectSprite()->Render(item_list->GetTraps()[i]->item->id);





	}

	for (int i = 0; i < this->wall_list.size(); i++)
	{
		x = this->wall_list[i]->position.x;
		y = this->wall_list[i]->position.y;


		if (this->tilemap->GetTiles()[x][y] >= SOLID_LIMIT)
		{
			glm::vec3 temp = glm::vec3(1.0f) * (1 - fog[x][y]);
			u_data->SetAmbientLight(glm::vec4(temp.x, temp.y, temp.y, 1.0f));
			u_data->ApplyMatrix(Translation(glm::vec2(x * 64, y * 64) + offset)*Scale(glm::vec2(64, 64)));
			this->m_walls->Render(this->wall_list[i]->type);
		}
	}


	for (int i = 0; i < this->rooms[0].size(); i++)
	{
		
		for (int j = 0; j < this->rooms[0][i]->GetWallList().size(); j++)
		{
			x = this->rooms[0][i]->GetWallList()[j]->position.x;
			y = this->rooms[0][i]->GetWallList()[j]->position.y;

			
			if (this->tilemap->GetTiles()[x][y] >= SOLID_LIMIT)
			{
				glm::vec3 temp = glm::vec3(1.0f) * (1 - fog[x][y]);
				u_data->SetAmbientLight(glm::vec4(temp.x, temp.y, temp.y, 1.0f));
				u_data->ApplyMatrix(Translation(glm::vec2(x * 64, y * 64) + offset)*Scale(glm::vec2(64, 64)));
				this->m_walls->Render(this->rooms[0][i]->GetWallList()[j]->type);
			}
		}
	}
	
	



}







void Map::TransformAndApplyRoomToTileMap(Room * room, Tilemap * tilemap, GLuint transform_flag)
{



	room->Transform(transform_flag);


	for (int j = 0; j < room->GetHeight(); j++)
	{
		for (int i = 0; i < room->GetWidth(); i++)
		{


			this->tilemap->GetTiles()[i + room->GetOffset().x][j + room->GetOffset().y] = room->GetTileMapPointer()[i][j];



		}
	}




}













