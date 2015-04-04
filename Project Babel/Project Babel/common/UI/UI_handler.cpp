#include <common.hpp>




void UIHandler::Init(Tooltip *t_tip)
{


	this->ui_render = new UIRender("data/shaders/2d_vert.txt", "data/shaders/2d_frag.txt", t_tip);



}



void UIHandler::Render(SoundManager *sm, Tooltip *t_tip, Controller * ctrl, GameObject * g_obj)
{


	this->ui_render->Render(sm, t_tip, ctrl, g_obj);



}
