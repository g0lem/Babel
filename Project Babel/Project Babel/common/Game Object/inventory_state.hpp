#pragma once



#define NOT_SET -1


class InventoryState
{




	GLuint * button_states;

	bool State;

	int col_id;


public:


	
	inline GLuint * GetButtonStates(){ return this->button_states; }




	inline InventoryState(){ this->Init(); }



	void Init();

	inline bool GetState(){ return this->State; }
	inline void SetState(bool state){ this->State = state; }

	inline int GetColID(){ return this->col_id; }
	inline void setColID(int col_id){ this->col_id = col_id; }

};



