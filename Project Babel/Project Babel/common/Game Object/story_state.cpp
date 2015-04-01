#include "common.hpp"

void StoryState::Init()
{



	this->state = NOT_ACTIVE;

	this->col_id = NOT_SET;

	this->buttons_state = new int[13];

}