//Checked 1


#include <common.hpp>


void Room::d_Print()
{


	for (int j = 0; j < this->height; j++)
	{
		for (int i = 0; i < this->width; i++)
		{


			printf("%i ", tile_map[i][j]);


		}


		printf("\n");


	}

	printf("\n");


}



void Room::Create(glm::vec2 start_point, GLfloat width, GLfloat height)
{



	this->points[0] = start_point;
	this->points[1] = start_point + glm::vec2(width, height);


	this->center = GetCenter(this->points);

	this->width = width;
   
	this->height = height;


}

void Room::CreateBossRoom()
{



	this->points[0] = vec2_0;
	this->points[1] = vec2_0 + glm::vec2(20, 20);


	this->center = GetCenter(this->points);

	this->width = 20;

	this->height = 20;


}





GLboolean Room::Intersects(Room * other)
{


	return (points[0].x < other->points[1].x-1 &&
		points[1].x > other->points[0].x+1 &&
		points[0].y < other->points[1].y-1 &&
		points[1].y > other->points[0].y+1);
		


}



void Room::Transform(GLuint transform_flag)
{

	
	this->type = transform_flag;



	this->tile_map = new GLint*[this->width];
	for (GLuint i = 0; i < this->width; i++)
		this->tile_map[i] = new GLint[this->height];




	for (GLuint j = 0; j < this->height; j++)
	{


		for (GLuint i = 0; i < this->width; i++)


		{


			this->tile_map[i][j] = FLOOR_BLOCK;


		}



	}




	if (transform_flag == EMPTY_ROOM)
	{


		GLuint values[4] = { 2, 1, 1, 1 };


		for (GLuint i = 1; i < this->width-1; i++)
		{
			this->tile_map[i][0] = VISIBLE_WALL;
			this->wall_list.push_back(new Wall(glm::vec2(glm::ivec2(i, 0) + this->points[0]), WALL_UP));
			this->tile_map[i][this->height - 1] = VISIBLE_WALL;
			this->wall_list.push_back(new Wall(glm::vec2(glm::ivec2(i, this->height - 1) + this->points[0]), WALL_DOWN));

		}
		this->tile_map[0][0] = VISIBLE_WALL;
		this->tile_map[0][this->height - 1] = VISIBLE_WALL;
		this->wall_list.push_back(new Wall(glm::vec2(glm::ivec2(0, 0) + this->points[0]), WALL_SE));
		this->wall_list.push_back(new Wall(glm::vec2(glm::ivec2(0, this->height - 1) + this->points[0]), WALL_NE));

		for (GLuint j = 1; j < this->height-1; j++)
		{

			this->tile_map[0][j] = VISIBLE_WALL;

			this->wall_list.push_back(new Wall(glm::vec2(glm::ivec2(0, j) + this->points[0]), WALL_RIGHT));

			this->tile_map[this->width - 1][j] = VISIBLE_WALL;

			this->wall_list.push_back(new Wall(glm::vec2(glm::ivec2(this->width - 1, j) + this->points[0]), WALL_LEFT));

		}
		this->tile_map[this->width - 1][0] = VISIBLE_WALL;

		this->tile_map[this->width - 1][this->height - 1] = VISIBLE_WALL;

		this->wall_list.push_back(new Wall(glm::vec2(glm::ivec2(this->width - 1, 0) + this->points[0]), WALL_SW));

		this->wall_list.push_back(new Wall(glm::vec2(glm::ivec2(this->width - 1, this->height - 1) + this->points[0]), WALL_NW));



	}


}




