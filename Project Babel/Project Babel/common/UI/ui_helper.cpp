#include <common.hpp>




GLuint UI_helper::GetButtonAction(Controller * ctrl, Property * m_prop)
{

	if (!Between(ctrl->GetMousePosition(),m_prop->position,m_prop->position + m_prop->size))
	return NONE;


	if (ctrl->GetMouseButton(GLFW_MOUSE_BUTTON_LEFT))
		return PRESSED;
	else
		return HOVER;


}

int UI_helper::GetItemAction(Controller * ctrl, Property * m_prop)
{

	if (!Between(ctrl->GetMousePosition(), m_prop->position, m_prop->position + m_prop->size))
		return NONE;


	if (ctrl->GetMouseButton(GLFW_MOUSE_BUTTON_RIGHT))
		return PRESSED;
	else
		return HOVER;


}
