#include <common.hpp>



void InventoryState::Init()
{


	this->button_states = new GLint[17];

	this->State = NOT_ACTIVE;

	this->col_id = NOT_SET;



}