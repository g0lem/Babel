#pragma once

#define NOT_ACTIVE 0;

class MenuState
{
	int *button_state;

	bool state;

public:

	inline MenuState(){ this->Init(); }

	void Init();

	inline int *GetButtonStates(){ return this->button_state; }

	inline bool GetState(){ return this->state; }

	inline void SetState(bool state){ this->state = state; }

};

