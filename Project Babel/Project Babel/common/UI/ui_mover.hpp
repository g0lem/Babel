#pragma once




class UI_mover
{


	GLboolean is_set;


	glm::vec2 offset;


public:



	inline UI_mover(){ this->Init(); }


	void Init();



	glm::vec2 GetTranslation(Controller * ctrl, glm::vec2 position, glm::vec2 size);


	inline void Reset(){ this->is_set = false; }


};