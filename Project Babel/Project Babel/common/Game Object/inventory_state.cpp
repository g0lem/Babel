#include <common.hpp>



void InventoryState::Init()
{


	this->button_states = new GLuint[17];

	this->State = NOT_ACTIVE;

	this->col_id = NOT_SET;



}