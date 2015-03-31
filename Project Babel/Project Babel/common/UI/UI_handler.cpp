#include <common.hpp>




void UIHandler::Init()
{


	this->ui_render = new UIRender("data/shaders/2d_vert.txt", "data/shaders/2d_frag.txt");



}



void UIHandler::Render(Controller * ctrl, GameObject * g_obj)
{


	this->ui_render->Render(ctrl, g_obj);



}
