#pragma once





#define RECT 0
#define CIRCLE 1




struct Golem
{


	GLuint id;

	glm::vec2 position;

	glm::vec2 size;


};






class UI_intersect
{


	std::vector<Golem*>*inters;


public:



	std::vector<Golem*>*GetInters(){ return this->inters; }




	inline UI_intersect(){ this->Init(); }



	void Init();



};



