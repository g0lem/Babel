#pragma once



#define NOT_SET -1


class InventoryState
{




	GLint * button_states;

	bool State;



public:


	
	inline GLint * GetButtonStates(){ return this->button_states; }




	inline InventoryState(){ this->Init(); }



	void Init();

	inline bool GetState(){ return this->State; }
	inline void SetState(bool state){ this->State = state; }



};



