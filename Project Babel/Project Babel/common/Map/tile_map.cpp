//Checked 1



#include <common.hpp>




void Tilemap::GenerateTileMap()
{




	this->tiles = new GLint*[this->size.x];
	for (GLuint i = 0; i < this->size.x; i++)
		this->tiles[i] = new GLint[this->size.y];



	for (GLuint j = 0; j < this->size.y; j++)
	{


		for (GLuint i = 0; i < this->size.x; i++)


		{


			this->tiles[i][j] = NO_BLOCK;


		}



	}



}


void Tilemap::GenerateBossRoom()
{

	this->size.x = 20;
	this->size.y = 20;

	std::ifstream f("boss_map.txt");


	this->boss_lvl = true;


	this->tiles = new GLint*[this->size.x];
	for (GLuint i = 0; i < this->size.x; i++)
		this->tiles[i] = new GLint[this->size.y];



	for (GLuint j = 0; j < this->size.y; j++)
	{


		for (GLuint i = 0; i < this->size.x; i++)


		{

			
			f>>tiles[i][j];
			

		}
		std::cout << "\n";



	}



}






void Tilemap::Init()
{


	this->tile_scale = glm::vec2(64.0f, 64.0f);


	this->size = glm::ivec2(48, 48);

	this->boss_lvl = false;

	this->GenerateTileMap();


	this->dark = new Sprite();


	/*	char ** tex_str = new char*[1];
	tex_str[0] = "dark.png";

	dark->Load(1, "data/tiles/", tex_str);
	*/
}

void Tilemap::InitBoss()
{


	this->tile_scale = glm::vec2(64.0f, 64.0f);


	this->size = glm::ivec2(20, 20);



	this->GenerateBossRoom();


	this->dark = new Sprite();


	/*	char ** tex_str = new char*[1];
	tex_str[0] = "dark.png";

	dark->Load(1, "data/tiles/", tex_str);
	*/
}



void Tilemap::Render(Controller * ctrl, ScreenUniformData * u_data, Sprite * m_sprite,
	glm::ivec2 begin_limit, glm::ivec2 end_limit,
	glm::vec2 offset, GLuint texture, float ** fog, ItemList *item_list)
{



	for (int j = begin_limit.y; j < end_limit.y; j++)
	{



		for (int i = begin_limit.x; i < end_limit.x; i++)
		{



			if (boss_lvl == false)
			{
				u_data->SetNewUV(glm::vec4(i - 1, j, 48, 48));
				dark->RenderTexture(texture);
				u_data->SetNewUV(glm::vec4(-1, -1, 48, 48));
			}
			else
			{
				u_data->SetNewUV(glm::vec4(i - 1, j, 20, 20));
				dark->RenderTexture(texture);
				u_data->SetNewUV(glm::vec4(-1, -1, 20, 20));
			}
				u_data->SetAmbientLight(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
				u_data->ApplyMatrix(Translation(glm::vec2(i, j)*tile_scale + offset)*Scale(tile_scale));
				m_sprite->Render(this->tiles[i][j]);
		


		}



	}


	int x, y;
	
	for (int i = 0; i < item_list->GetDroppedItems().size(); i++)
	{
		x = item_list->GetDroppedItems()[i]->position.x;
		y = item_list->GetDroppedItems()[i]->position.y;

	


			glm::vec3 temp = glm::vec3(1.0f) * (1 - fog[x][y]);
			u_data->SetAmbientLight(glm::vec4(temp.x, temp.y, temp.y, 1.0f));
			u_data->ApplyMatrix(Translation(glm::vec2(x*64+16, y*64+16) + offset)*Scale(glm::vec2(32, 32)));
			item_list->GetSprite()->Render(item_list->GetDroppedItems()[i]->item->frame);


		


	}

	for (int i = 0; i < item_list->GetObjects().size(); i++)
	{
		x = item_list->GetObjects()[i]->position.x;
		y = item_list->GetObjects()[i]->position.y;




		glm::vec3 temp = glm::vec3(1.0f) * (1 - fog[x][y]);
		u_data->SetAmbientLight(glm::vec4(temp.x, temp.y, temp.y, 1.0f));
		u_data->ApplyMatrix(Translation(glm::vec2(x * 64, y * 64) + offset)*Scale(glm::vec2(64, 64)));
		item_list->GetObjectSprite()->Render(item_list->GetObjects()[i]->id);





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





}





void Tilemap::SmootherFOW(float **fog, glm::ivec2 position, ScreenUniformData * u_data)
{

	for (int z = 0; z < 6; z++)
	{
		if (z >= 0 && position.x + z < this->size.x && position.y + z < this->size.y)
		{
			//prima parte
			if (fog[position.x + z][position.y + z] == 0.0f && fog[position.x + z][position.y + z - 1] == 0.0f)
				for (int i = 0; i < 8; i++)
					for (int j = 7 - i; j >= i; j--)
					{
				u_data->SetAmbientLight(glm::vec4(1.0f, 1.0f, 1.0f, 0.95f));
				u_data->ApplyMatrix(Translation(glm::vec2(position.x + i, position.y + j)*glm::vec2(8,8))*Scale(8, 8));
				this->dark->Render(0);
					}
			//if (fog[position.x + i][position.y + i] == 0.0f && fog[position.x + i][position.y + i + 1] == 0.0f)
			//smooth pe stanga
		}

	}
}