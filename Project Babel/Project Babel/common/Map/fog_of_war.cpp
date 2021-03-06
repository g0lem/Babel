#include "common.hpp"


#define RANGE 7
#define LIT 0.0f
#define SEMILIT 0.75f
#define UNSEEN 0.5f
#define DARK 1.0f

void fog_of_war::Init(GameObject *g_obj)
{
	//std::cout << "AM INTRAT!\n";
	////for (int i = 0; i < g_obj->GetCollisionMap()->GetSize().x; i++)
	////{
	////	for (int j = 0; j < g_obj->GetCollisionMap()->GetSize().y; j++)
	////		if (g_obj->GetCollisionMap()->GetTiles()[i][j] == 0)
	////			std::cout << " ";
	////		else
	////			std::cout << (char)(219);
	////	std::cout << "\n";
	////}

	//std::cout << "AM IESIT!\n";

	s_map = new float*[g_obj->GetCollisionMap()->GetSize().x];
	for (int i = 0; i < g_obj->GetCollisionMap()->GetSize().x; i++)
		s_map[i] = new float[g_obj->GetCollisionMap()->GetSize().y];

	for (int i = 0; i < g_obj->GetCollisionMap()->GetSize().x; i++)
		for (int j = 0; j < g_obj->GetCollisionMap()->GetSize().y; j++)
			s_map[i][j] = DARK;

	m_sprite = new Sprite();
	char **tex_str;
	tex_str = new char*[1];
	tex_str[0] = "fog.png";

	m_sprite->Load(1,"data/sprites", tex_str);
}

void fog_of_war::Advance(GameObject *g_obj)
{
	for (int i = 0; i < g_obj->GetCollisionMap()->GetSize().x; i++)
		for (int j = 0; j < g_obj->GetCollisionMap()->GetSize().y; j++)
			if (s_map[i][j] == LIT || s_map[i][j] == SEMILIT)
				s_map[i][j] = UNSEEN;
}



float **fog_of_war::GetFOW(GameObject *g_obj, glm::ivec2 position)
{
	
	this->Advance(g_obj);

	//FILL THE X AND Y AXIS

	for (int i = position.y; i < position.y + RANGE; i++)	
		if (i >= 0 && i<g_obj->GetCollisionMap()->GetSize().y)
		if (g_obj->GetCollisionMap()->GetVisibleTiles()[position.x][i] != 1)
		{
			s_map[position.x][i] = LIT;
		}
		else
		{
			s_map[position.x][i] = LIT;
			break;
		}


	for (int i = position.x; i < position.x + RANGE; i++)
		if (i >= 0 && i<g_obj->GetCollisionMap()->GetSize().x)
			if (g_obj->GetCollisionMap()->GetVisibleTiles()[i][position.y] != 1)
				s_map[i][position.y] = LIT;
			else
			{
				s_map[i][position.y] = LIT;
				break;
			}




	for (int i = position.y; i > position.y - RANGE; i--)
		if (i >= 0 && i<g_obj->GetCollisionMap()->GetSize().y)
			if (g_obj->GetCollisionMap()->GetVisibleTiles()[position.x][i] != 1)
				s_map[position.x][i] = LIT;
			else
			{
				s_map[position.x][i] = LIT;
				break;
			}

	for (int i = position.x; i > position.x - RANGE; i--)
		if (i >= 0 && i<g_obj->GetCollisionMap()->GetSize().x)
			if (g_obj->GetCollisionMap()->GetVisibleTiles()[i][position.y] != 1)
				s_map[i][position.y] = LIT;
			else
			{
				s_map[i][position.y] = LIT;
				break;
			}

	//Diagonals

	for (int i = 0; i < RANGE; i++)
	{
		if (i >= 0 && position.x + i <g_obj->GetCollisionMap()->GetSize().x && position.y + i<g_obj->GetCollisionMap()->GetSize().y)
			if (g_obj->GetCollisionMap()->GetVisibleTiles()[position.x + i][position.y + i] != 1)
				s_map[position.x + i][position.y + i] = LIT;
			else
			{
				s_map[position.x + i][position.y + i] = LIT;
				break;
			}
	}

	for (int i = 0; i < RANGE; i++)
	{
		if (i >= 0 && position.x - i<g_obj->GetCollisionMap()->GetSize().x && position.y - i <g_obj->GetCollisionMap()->GetSize().y)
			if (g_obj->GetCollisionMap()->GetVisibleTiles()[position.x - i][position.y - i] != 1)
				s_map[position.x - i][position.y - i] = LIT;
			else
			{
				s_map[position.x - i][position.y - i] = LIT;
				break;
			}
		
	}

	for (int i = 0; i < RANGE; i++)
	{
		if (i >= 0 && position.x + i<g_obj->GetCollisionMap()->GetSize().x && position.y - i <g_obj->GetCollisionMap()->GetSize().y)
			if (g_obj->GetCollisionMap()->GetVisibleTiles()[position.x + i][position.y - i] != 1)
				s_map[position.x + i][position.y - i] = LIT;
			else
			{
				s_map[position.x + i][position.y - i] = LIT;
				break;
			}
		
	}

	for (int i = 0; i < RANGE; i++)
	{
		if (i >= 0 && position.x - i<g_obj->GetCollisionMap()->GetSize().x && position.y + i <g_obj->GetCollisionMap()->GetSize().y)
			if (g_obj->GetCollisionMap()->GetVisibleTiles()[position.x - i][position.y + i] != 1)
				s_map[position.x - i][position.y + i] = LIT;
			else
			{
				s_map[position.x - i][position.y + i] = LIT;
				break;
			}
		
	}



	

	//Cadranul 1\\
			

	for (int i = position.x - 1; i > position.x - RANGE; i--)
		for (int j = position.y + 1; j < position.y + RANGE; j++)
		{

		
		if (i >= 0 && i < g_obj->GetCollisionMap()->GetSize().x && j >= 0 && j < g_obj->GetCollisionMap()->GetSize().y)
		{
			if (g_obj->GetCollisionMap()->GetVisibleTiles()[i][j] == false && g_obj->GetCollisionMap()->GetVisibleTiles()[i + 1][j] == false && g_obj->GetCollisionMap()->GetVisibleTiles()[i][j - 1] == false && g_obj->GetCollisionMap()->GetVisibleTiles()[i + 1][j - 1] == false)
				if (s_map[i + 1][j] == LIT && s_map[i][j - 1] == LIT && s_map[i + 1][j - 1] == LIT)
				{			
				s_map[i][j] = LIT;
				}
			if (g_obj->GetCollisionMap()->GetVisibleTiles()[i][j] == true)
				if (s_map[i + 1][j] == LIT && s_map[i][j - 1] == LIT && s_map[i + 1][j - 1] == LIT)
				{				
				s_map[i][j] = LIT;
				}
		}
		
		}


	//Cadranul 2\\

	for (int i = position.x - 1; i > position.x - RANGE; i--)
		for (int j = position.y - 1; j > position.y - RANGE; j--)
		{
		
		if (i >= 0 && i < g_obj->GetCollisionMap()->GetSize().x && j >= 0 && j < g_obj->GetCollisionMap()->GetSize().y)
		{
			if (g_obj->GetCollisionMap()->GetVisibleTiles()[i][j] == false && g_obj->GetCollisionMap()->GetVisibleTiles()[i + 1][j] == false && g_obj->GetCollisionMap()->GetVisibleTiles()[i][j + 1] == false && g_obj->GetCollisionMap()->GetVisibleTiles()[i + 1][j + 1] == false)
			if (s_map[i + 1][j] == LIT && s_map[i][j + 1] == LIT && s_map[i + 1][j + 1] == LIT)
			{
				s_map[i][j] = LIT;
			}
			if (g_obj->GetCollisionMap()->GetVisibleTiles()[i][j] == true)
				if (s_map[i + 1][j] == LIT && s_map[i][j + 1] == LIT && s_map[i + 1][j + 1] == LIT)
				{
				s_map[i][j] = LIT;
				}

		
			
		}
		}

	//Cadranul 3\\
					
	
	for (int i = position.x + 1; i < position.x + RANGE; i++)
		for (int j = position.y - 1; j > position.y - RANGE; j--)
		{

		if (i >= 0 && i < g_obj->GetCollisionMap()->GetSize().x && j >= 0 && j < g_obj->GetCollisionMap()->GetSize().y)
		{
		
			if (g_obj->GetCollisionMap()->GetVisibleTiles()[i][j] == false && g_obj->GetCollisionMap()->GetVisibleTiles()[i - 1][j] == false && g_obj->GetCollisionMap()->GetVisibleTiles()[i][j + 1] == false && g_obj->GetCollisionMap()->GetVisibleTiles()[i - 1][j + 1] == false)
		    if(s_map[i - 1][j] == LIT && s_map[i][j + 1] == LIT && s_map[i - 1][j + 1] == LIT)
			{
				
				s_map[i][j] = LIT;
			}
			if (g_obj->GetCollisionMap()->GetVisibleTiles()[i][j] == true)
				if (s_map[i - 1][j] == LIT && s_map[i][j + 1] == LIT && s_map[i - 1][j + 1] == LIT)
				{
				s_map[i][j] = LIT;
				}

		}
		}





	//Cadranul 4\\
					
	for (int i = position.x + 1; i < position.x + RANGE; i++)
		for (int j = position.y + 1; j < position.y + RANGE; j++)
		{
		if (i >= 0 && i < g_obj->GetCollisionMap()->GetSize().x && j >= 0 && j < g_obj->GetCollisionMap()->GetSize().y)
		{
			if (g_obj->GetCollisionMap()->GetVisibleTiles()[i][j] == false && g_obj->GetCollisionMap()->GetVisibleTiles()[i - 1][j] == false && g_obj->GetCollisionMap()->GetVisibleTiles()[i][j - 1] == false && g_obj->GetCollisionMap()->GetVisibleTiles()[i - 1][j - 1] == false)
			if(s_map[i - 1][j] == LIT && s_map[i][j - 1] == LIT && s_map[i - 1][j - 1] == LIT)
			{
				s_map[i][j] = LIT;
			}
			if (g_obj->GetCollisionMap()->GetVisibleTiles()[i][j] == true)
				if (s_map[i - 1][j] == LIT && s_map[i][j - 1] == LIT && s_map[i - 1][j - 1] == LIT)
				{
				s_map[i][j] = LIT;
				}

			

		}
		}

	
	
	return s_map;

}



void fog_of_war::Render(Controller * ctrl, ScreenUniformData * u_data, glm::vec2 position, GameObject *g_obj)
{

	this->GetFOW(g_obj,glm::ivec2(position));

	


	for (int j = g_obj->GetScroller()->GetBeginLimit().y; j < g_obj->GetScroller()->GetEndLimit().y; j++)
	{



		for (int i = g_obj->GetScroller()->GetBeginLimit().x; i < g_obj->GetScroller()->GetEndLimit().x; i++)
		{



			if (this->s_map[i][j] == DARK)
			{


				u_data->SetAmbientLight(glm::vec4(1.f, 1.f, 1.f, 0.8f));
				u_data->ApplyMatrix(Translation(glm::vec2(i * 32, j * 32))*Scale(glm::vec2(32, 32)));
				this->m_sprite->Render(NULL);



			}



		}



	}

	this->Advance(g_obj);
}



unsigned char* fog_of_war::GetBuffer(GameObject * g_obj, glm::ivec2 position)
{


	glm::ivec2 size = g_obj->GetCollisionMap()->GetSize();

	unsigned char * buffer = new unsigned char[size.x * size.y];



	float** temp = this->GetFOW(g_obj, position);


	for (GLuint j = 0; j < size.y; j++)
		for (GLuint i = 0; i < size.x; i++)
			buffer[j*size.x + i] = unsigned char(temp[i][j]*255.0f);
 



	return buffer;

}




void fog_of_war::MakeTexture(GameObject * g_obj, glm::ivec2 position)
{

	glDeleteTextures(1, &this->tex_id);

	unsigned char * buffer = this->GetBuffer(g_obj, position);
	glm::ivec2 size = g_obj->GetCollisionMap()->GetSize();


	glGenTextures(1, &this->tex_id);
	glBindTexture(GL_TEXTURE_2D, this->tex_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, size.x, size.y, 0, GL_RED, GL_UNSIGNED_BYTE, buffer);


}

