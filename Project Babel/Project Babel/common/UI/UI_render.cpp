#include <common.hpp>




void UIRender::Init(char * vertex_shader, char * fragment_shader)
{



	this->BindCreate(vertex_shader, fragment_shader);


	this->inventory_r = new Inventory();
	this->panel_r = new PanelRender();
	this->menu_r = new MenuRender();
	this->story_r = new StoryRender();


	this->UnbindCreate();

}





void UIRender::Render(Controller *ctrl,GameObject *g_obj)
{


	this->BindRun(ctrl->GetWindowWidth(), ctrl->GetWindowHeight());

	

	if (g_obj->GetUIState()->GetMenuState()->GetState())
		this->menu_r->Render(ctrl, this->GetScreenPointer(), g_obj);
	


	if (g_obj->GetUIState()->GetMenuState()->GetButtonStates()[0] == PRESSED)
		g_obj->GetUIState()->GetMenuState()->SetState(NOT_ACTIVE);

	


	if (g_obj->GetUIState()->GetMenuState()->GetState() == NOT_ACTIVE)
	{


		if (g_obj->GetUIState()->GetInventoryState()->GetState() == ACTIVE)
			this->inventory_r->Render(ctrl, this->GetScreenPointer(), g_obj);
		else
		{
			this->inventory_r->GetMover()->Reset();
			this->inventory_r->box_position = glm::vec2(ctrl->GetWindowWidth() / 4, ctrl->GetWindowHeight() / 2 - ctrl->GetWindowHeight() / 4);
		}



		if (g_obj->GetUIState()->GetStoryState()->GetState())
			this->story_r->Render(ctrl, this->GetScreenPointer(), g_obj);
		else
		{
			this->story_r->GetMover()->Reset();
			this->story_r->storybox_position = glm::vec2(ctrl->GetWindowWidth() / 2 + ctrl->GetWindowWidth() / 4, ctrl->GetWindowHeight() / 2 - ctrl->GetWindowHeight() / 4);
		}

		this->panel_r->Render(ctrl, this->GetScreenPointer(), g_obj);


	
	}


	this->UnbindRun();


}
