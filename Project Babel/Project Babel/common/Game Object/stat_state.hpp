#pragma once


class StatState
{


	GLboolean state;
	GLint col_id;
	GLint x_state;


public:


	inline GLboolean GetState(){ return this->state; }
	inline void SetState(GLboolean state){ this->state = state; }
	inline GLint GetColID(){ return this->col_id; }
	inline void SetColID(GLint col_id){ this->col_id = col_id; }
	inline StatState(){ this->Init(); }
	void Init();




};
