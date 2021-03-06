#include <common.hpp>



void UIRender::Init(char * vertex_shader, char * fragment_shader, GameObject *g_obj, Tooltip *tooltips)
{



	this->BindCreate(vertex_shader, fragment_shader);


	this->panel_r = new PanelRender(tooltips);
	this->inventory_r = new Inventory(tooltips);
	this->menu_r = new MenuRender();
	this->story_r = new StoryRender();
	this->stat_r = new StatsRender(g_obj);
	


	this->UnbindCreate();

}





void UIRender::Render(SoundManager *sm, Tooltip *tooltips, Controller *ctrl, GameObject *g_obj, glm::vec2 player_positon)
{

	this->BindRun(ctrl->GetWindowWidth(), ctrl->GetWindowHeight());

	tooltips->UpdateStatus(0, g_obj->GetUIState()->GetMenuState()->GetState());

	tooltips->GetTooltips()->at(tooltips->GetRenderingIndex())->renderstring = false;

	if (g_obj->GetUIState()->GetMenuState()->GetState())
		this->menu_r->Render(ctrl, this->GetScreenPointer(), g_obj);



	if (g_obj->GetUIState()->GetMenuState()->GetButtonStates()[0] == PRESSED && g_obj->GetUIState()->GetMenuState()->GetState() == ACTIVE)
	{
		sm->PlaySound(MENUPRESSBUTTON);
		g_obj->GetUIState()->GetMenuState()->SetState(NOT_ACTIVE);
	}

	if (ctrl->GetKeyOnce(GLFW_KEY_I))
	{
		if (g_obj->GetUIState()->GetInventoryState()->GetState() == NOT_ACTIVE)
			g_obj->GetUIState()->GetInventoryState()->SetState(ACTIVE);

		else if (g_obj->GetUIState()->GetInventoryState()->GetState() == ACTIVE)
			g_obj->GetUIState()->GetInventoryState()->SetState(NOT_ACTIVE);
	}

	if (ctrl->GetKeyOnce(GLFW_KEY_C))
	{
		if (g_obj->GetUIState()->GetStatState()->GetState() == NOT_ACTIVE)
			g_obj->GetUIState()->GetStatState()->SetState(ACTIVE);

		else if (g_obj->GetUIState()->GetStatState()->GetState() == ACTIVE)
			g_obj->GetUIState()->GetStatState()->SetState(NOT_ACTIVE);
	}
	if (ctrl->GetKeyOnce(GLFW_KEY_Q))
		g_obj->GetTurnSystem()->Wait();


	if (g_obj->GetUIState()->GetMenuState()->GetState() == NOT_ACTIVE)
	{
		tooltips->GetTooltips()->at(tooltips->GetRenderingIndex())->renderstring = true;



		if (g_obj->GetUIState()->GetInventoryState()->GetState() == ACTIVE)
			this->inventory_r->Render(tooltips, sm, ctrl, this->GetScreenPointer(), g_obj, player_positon);
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


		if (g_obj->GetUIState()->GetStatState()->GetState() == ACTIVE)
		{
			this->stat_r->Render(ctrl, this->GetScreenPointer(), g_obj);
			g_obj->statrender = true;
		}
		else
		{
			this->stat_r->GetMover()->Reset();
			this->stat_r->position = glm::vec2(ctrl->GetWindowWidth() / 6, ctrl->GetWindowHeight() / 2 - ctrl->GetWindowHeight() / 4);
			g_obj->statrender = false;

		}


		this->panel_r->Render(sm, tooltips, ctrl, this->GetScreenPointer(), g_obj);

		
		tooltips->Render(ctrl, this->GetScreenPointer());
		
	}


	

	this->UnbindRun();


}
