#include "common.hpp"


void panel_state::Init()
{

	this->state = NOT_ACTIVE;


	this->hp = this->max_hp = 0;

	this->xp = this->max_xp = 0;
}