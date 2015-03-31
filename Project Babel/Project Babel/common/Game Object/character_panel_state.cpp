#include <common.hpp>





void CharPanState::Init()
{



	this->b_state = new BackpackState();


	this->t_state = new TabState();



	this->state = NOT_ACTIVE;



	this->col_id = NOT_SET;


}


