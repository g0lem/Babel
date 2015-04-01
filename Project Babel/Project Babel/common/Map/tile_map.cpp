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


}



void Tilemap::Render(Controller * ctrl, ScreenUniformData * u_data, Sprite * m_sprite, 
	glm::ivec2 begin_limit, glm::ivec2 end_limit,
	glm::vec2 offset, float **fog, ItemList *item_list)
{



	



	



	for (int j = begin_limit.y; j < end_limit.y; j++)
	{



		for (int i = begin_limit.x; i < end_limit.x; i++)
		{


			if (this->tiles[i][j] != NO_BLOCK && fog[i][j] == 0.0f)
			{


				u_data->SetAmbientLight(glm::vec4(1.0f, 1.0f, 1.0f,1.0f));
				u_data->ApplyMatrix(Translation(glm::vec2(i, j)*tile_scale + offset)*Scale(tile_scale));
				m_sprite->Render(this->tiles[i][j]);



			}
			
			if (this->tiles[i][j] != NO_BLOCK && fog[i][j] == 0.5f)
			{
				u_data->SetAmbientLight(glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
				u_data->ApplyMatrix(Translation(glm::vec2(i, j)*tile_scale + offset)*Scale(tile_scale));
				m_sprite->Render(this->tiles[i][j]);
			}




		}



	}
	int x, y;
	for (int i = 0; i < item_list->GetDroppedItems().size(); i++)
	{
		x = item_list->GetDroppedItems()[i]->x;
		y = item_list->GetDroppedItems()[i]->y;


		if (this->tiles[x][y] != NO_BLOCK && fog[x][y] == 0.0f)
		{


			u_data->SetAmbientLight(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
			u_data->ApplyMatrix(Translation(glm::vec2(x, y)*tile_scale + offset)*Scale(tile_scale));
			item_list->GetSprite()->Render(item_list->GetDroppedItems()[i]->item->type - 1);
			



		}

		if (this->tiles[x][y] != NO_BLOCK && fog[x][y] == 0.5f)
		{
			u_data->SetAmbientLight(glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
			u_data->ApplyMatrix(Translation(glm::vec2(x, y)*tile_scale + offset)*Scale(tile_scale));
			item_list->GetSprite()->Render(item_list->GetDroppedItems()[i]->item->type - 1);
		}
	}




}