//Checked 1


#include <common.hpp>



void Scroller::Init()
{



	this->offset = glm::vec2(0.0f, 0.0f);



}



void Scroller::Clean()
{






}



void Scroller::ComputeScreenLimits(Controller * ctrl, glm::ivec2 map_size, glm::vec2 tile_scale)
{



	glm::vec2 offset = -GridPosition(this->offset, tile_scale) / tile_scale;


	glm::vec2 screen_limit = GridPosition(glm::vec2(ctrl->GetWindowWidth(), ctrl->GetWindowHeight()), tile_scale) / tile_scale + glm::vec2(3.0f, 3.0f);


	this->end_limit = glm::min(glm::ivec2(offset + screen_limit), map_size);


	this->begin_limit = glm::max(glm::ivec2(offset), glm::ivec2(0, 0));




}