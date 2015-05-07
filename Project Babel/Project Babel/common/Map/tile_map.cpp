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

	this->size.x = 48;
	this->size.y = 48;

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
		
	


	}



}






void Tilemap::Init()
{


	this->tile_scale = glm::vec2(32.0f, 32.0f);


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


	this->tile_scale = glm::vec2(32.0f, 32.0f);


	this->size = glm::ivec2(20, 20);



	this->GenerateBossRoom();


	this->dark = new Sprite();


	/*	char ** tex_str = new char*[1];
	tex_str[0] = "dark.png";

	dark->Load(1, "data/tiles/", tex_str);
	*/
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