#pragma once






class BackpackState
{




	GLuint * button_states;




public:


	
	inline GLuint * GetButtonStates(){ return this->button_states; }




	inline BackpackState(){ this->Init(); }



	void Init();



};



