#pragma once




class SpellState
{

	bool state;

public:

	SpellState(){ this->state = 0; }
	void SetState(bool state){ this->state = state; }
	bool GetState(){ return this->state; }

};

