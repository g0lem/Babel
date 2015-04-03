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





void Tilemap::Init()
{


	this->tile_scale = glm::vec2(64.0f, 64.0f);


	this->size = glm::ivec2(48, 48);



	this->GenerateTileMap();


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





				u_data->SetNewUV(glm::vec2(i - 1, j));
				dark->RenderTexture(texture);
				u_data->SetNewUV(glm::vec2(-1, -1));
				u_data->SetAmbientLight(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
				u_data->ApplyMatrix(Translation(glm::vec2(i, j)*tile_scale + offset)*Scale(tile_scale));
				m_sprite->Render(this->tiles[i][j]);
		


		}



	}


	int x, y;
	
	for (int i = 0; i < item_list->GetDroppedItems().size(); i++)
	{
		x = item_list->GetDroppedItems()[i]->x;
		y = item_list->GetDroppedItems()[i]->y;

		if (x != -1 && y != -1)
		{



			glm::vec3 temp = glm::vec3(1.0f) * (1 - fog[x][y]);
			u_data->SetAmbientLight(glm::vec4(temp.x, temp.y, temp.y, 1.0f));
			u_data->ApplyMatrix(Translation(glm::vec2(x, y)*tile_scale + offset)*Scale(tile_scale));
			item_list->GetSprite()->Render(item_list->GetDroppedItems()[i]->item->frame);


		}


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