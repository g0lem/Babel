//Checked 1



#ifndef ROOM_HPP
#define ROOM_HPP






#define EMPTY_ROOM 0


#define MIN_ROOM_WIDTH 5
#define MIN_ROOM_HEIGHT 5
#define MAX_ROOM_WIDTH 10
#define MAX_ROOM_HEIGHT 10



class Room
{


	glm::ivec2 points[2];


	GLuint width, height;


	glm::ivec2 center;


	GLint **tile_map;



	GLuint type;


public:


	void Create(glm::vec2 start_point, GLfloat width, GLfloat height);


	void Transform(GLuint transform_flag);


	GLboolean Intersects(Room * other);


	inline GLboolean InsideMap(GLuint width, GLuint height){ return points[1].x <= width && points[1].y <= height; }


	inline GLint**GetTileMapPointer(){ return this->tile_map; }


	inline glm::ivec2 GetOffset(){ return this->points[0]; }


	inline GLuint GetWidth(){ return this->width; }


	inline GLuint GetHeight(){ return this->height; }


	inline glm::ivec2 GetInternalCenter(){ return this->center; }



	void d_Print();

};




#endif