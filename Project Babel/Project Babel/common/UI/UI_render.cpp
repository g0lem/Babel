#include <common.hpp>




void UIRender::Init(char * vertex_shader, char * fragment_shader)
{



	this->BindCreate(vertex_shader, fragment_shader);



	this->char_panel = new CharPanRender();



	this->action_sr = new ActionSpriteRender();



	this->panel_r = new PanelRender();


	this->UnbindCreate();

}





void UIRender::Render(Controller *ctrl,GameObject *g_obj)
{


	this->BindRun(ctrl->GetWindowWidth(), ctrl->GetWindowHeight());



	if (g_obj->GetUIState()->GetCharPanState()->GetState())
		this->char_panel->Render(ctrl, this->GetScreenPointer(), g_obj);

	
	//this->action_sr->Render(ctrl, this->GetScreenPointer(), g_obj);


	this->panel_r->Render(ctrl, this->GetScreenPointer(), g_obj);


	this->UnbindRun();


}
