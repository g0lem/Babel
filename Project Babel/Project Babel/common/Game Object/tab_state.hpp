#pragma once




class TabState
{


	GLuint * tab_states;



public:


	inline GLuint*GetTabsState(){ return this->tab_states; }




	inline TabState(){ this->Init(); }



	void Init();



};



