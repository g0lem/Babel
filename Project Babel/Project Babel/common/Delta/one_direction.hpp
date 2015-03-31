#ifndef ONE_DIRECTION_HPP
#define ONE_DIRECTION_HPP





#define DIR_TYPE_4 0 
#define DIR_TYPE_8 1


#define DIR_UP 0
#define DIR_DOWN 1
#define DIR_LEFT 2
#define DIR_RIGHT 3



class Direction
{



	GLuint last_dir;



public:



	inline Direction(){ this->Init(); }


	void Init();


	GLuint Compute(GLuint type, glm::vec2 position, glm::vec2 target);


};



#endif