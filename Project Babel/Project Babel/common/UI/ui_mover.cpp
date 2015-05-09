#include <common.hpp>


void UI_mover::Init()
{


	this->is_set = false;


	this->offset = glm::vec2(0, 0);


}




glm::vec2 UI_mover::GetTranslation(Controller * ctrl, glm::vec2 position, glm::vec2 size)
{


	if (!ctrl->GetMouseButton(GLFW_MOUSE_BUTTON_LEFT))
		this->is_set = false;




	if (this->is_set == false )
	{



		if (Between(ctrl->GetMousePosition(), position, position + size))
		{


			this->offset = ctrl->GetMousePosition() - position;


			this->is_set = true;


		}

			return position;



	}
	else
		return ctrl->GetMousePosition() - offset;



}




