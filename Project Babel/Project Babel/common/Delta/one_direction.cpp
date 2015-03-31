#include <common.hpp>



void Direction::Init()
{



	this->last_dir = DIR_UP;



}


GLuint Direction::Compute(GLuint type, glm::vec2 position, glm::vec2 target)
{


	if (type == DIR_TYPE_4)
	{




		if (position == target)
			return this->last_dir;
		else
		{


			glm::vec2 dir = glm::normalize(target - position);



			if (!vec2_i(dir))
			{


				if ((dir.x < 0 && dir.y < 0) || (dir.x > 0 && dir.y < 0))

				{

					this->last_dir = DIR_UP;
					return DIR_UP;

				}


				if ((dir.x > 0 && dir.y > 0) || (dir.x < 0 && dir.y > 0))

				{

					this->last_dir = DIR_DOWN;
					return DIR_DOWN;

				}


				return this->last_dir;


			}

			else
			{


				if (dir == glm::vec2(-1, 0))
				{

					this->last_dir = DIR_LEFT;
					return DIR_LEFT;

				}


				if (dir == glm::vec2(1, 0))
				{

					this->last_dir = DIR_RIGHT;
					return DIR_RIGHT;

				}


				if (dir == glm::vec2(0, -1))
				{

					this->last_dir = DIR_UP;
					return DIR_UP;

				}


				if (dir == glm::vec2(0, 1))
				{

					this->last_dir = DIR_DOWN;
					return DIR_DOWN;

				}

			}


		}
		



	}
	else if (type == DIR_TYPE_8)
	{






	}



}