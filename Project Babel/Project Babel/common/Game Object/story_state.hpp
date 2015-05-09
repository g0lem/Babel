#pragma once



class StoryState
{
	int state;

	int *buttons_state;

public:

	inline StoryState(){ this->Init(); }


	void Init();

	inline int GetState(){ return this->state; }

	inline void SetState(int state){ this->state = state; }

	inline int *GetButtonState(){ return this->buttons_state; }
 


};

