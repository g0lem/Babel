#pragma once



class StoryState
{
	int state, col_id;

	int *buttons_state;

public:

	inline StoryState(){ this->Init(); }


	void Init();

	inline int GetState(){ return this->state; }

	inline void SetState(int state){ this->state = state; }

	inline int *GetButtonState(){ return this->buttons_state; }
 
	inline int GetColID(){ return this->col_id; }
	inline void setColID(int col_id){ this->col_id = col_id; }


};

