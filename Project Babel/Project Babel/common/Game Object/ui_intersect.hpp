#pragma once





#define RECT 0
#define CIRCLE 1




#define INVENTARY_INTER 0
#define STORY_INTER 1
#define BUTTON_1 2
#define BUTTON_2 3
#define BUTTON_3 4
#define BUTTON_4 5
#define MENU_BUTTON 6




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



