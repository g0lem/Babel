#pragma once



#define NOT_SET -1



class CharPanState
{


	GLboolean state;



	GLint col_id;



	BackpackState * b_state;



	TabState * t_state;




public:


	inline BackpackState*GetBackpackState(){ return this->b_state; }



	inline TabState*GetTabsState(){ return this->t_state; }



	inline GLboolean GetState(){ return this->state; }



	inline void SetState(GLboolean state){ this->state = state; }



	inline GLint GetColID(){ return this->col_id; }



	inline void SetColID(GLint col_id){ this->col_id = col_id; }



	inline CharPanState(){ this->Init(); }



	void Init();




};



