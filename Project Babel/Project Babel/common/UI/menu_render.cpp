#include "common.hpp"

void MenuRender::Init()
{

	this->LoadSprites();

	this->LoadButtons();


}

void MenuRender::LoadSprites()
{

	this->button_skins = new Sprite();

	char **textures = new char*[4];

	textures[0] = "menubuttonresume.png";
	textures[1] = "menubuttonoptions.png";
	textures[2] = "menubuttonexit.png";
	textures[3] = "menuoverlay.png";

	this->button_skins->Load(4, "data/UI/Menu/", textures);
}

void MenuRender::LoadButtons()
{

	menu_buttons = new Button*[3];

	for (int i = 0; i < 3; i++)
	{
		Property * m_prop = new Property();
		m_prop->size = glm::vec2(226, 62);
		m_prop->color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

		menu_buttons[i] = new Button(m_prop);
	}


}

void MenuRender::Update(Controller *ctrl)
{
	menu_buttons[0]->GetProperties()->position = glm::vec2(ctrl->GetWindowWidth()/2 - 113, ctrl->GetWindowHeight()/2 - 75);
	menu_buttons[1]->GetProperties()->position = glm::vec2(menu_buttons[0]->GetProperties()->position.x, menu_buttons[0]->GetProperties()->position.y + 72);
	menu_buttons[2]->GetProperties()->position = glm::vec2(menu_buttons[1]->GetProperties()->position.x, menu_buttons[1]->GetProperties()->position.y + 102);
}

void MenuRender::RenderButtons(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj)
{

	for (int i = 0; i < 3; i++)
	{
		g_obj->GetUIState()->GetMenuState()->GetButtonStates()[i] = UI_helper::GetButtonAction(ctrl, this->menu_buttons[i]->GetProperties());

		menu_buttons[i]->Render(ctrl, u_data, button_skins, i, g_obj->GetUIState()->GetMenuState()->GetButtonStates()[i]);
	}


}

void MenuRender::Render(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj)
{
	this->Update(ctrl);

	u_data->SetAmbientLight(glm::vec4(1.f, 1.f, 1.f, 1.f));

	u_data->ApplyMatrix(Translation(vec2_0)*Scale(ctrl->GetWindowSize()));

	this->button_skins->Render(MENU_OVERLAY);

	RenderButtons(ctrl, u_data, g_obj);


}
