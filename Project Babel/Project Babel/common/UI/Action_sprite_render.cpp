#include "common.hpp"

void ActionSpriteRender::Init()
{

	//this->left_position = glm::vec2();
	this->left_size = glm::vec2(240, 240);
	this->left_radius = glm::vec2(120, 120);

	//this->right_position = glm::vec2();
	this->right_size = glm::vec2(240, 240);
	this->right_radius = glm::vec2(120, 120);

	this->size = glm::vec2();

	this->radius = glm::vec2();

	this->LoadButtonsSprite();

	this->LoadButtons();

}

void ActionSpriteRender::LoadButtonsSprite()
{
	this->button_skins = new Sprite();

	char **tex_str = new char*[2];

	tex_str[0] = "left.png";
	tex_str[1] = "right.png";

	this->button_skins->Load(2, "data/UI/Action/", tex_str);
}

void ActionSpriteRender::LoadButtons()
{

	this->a_button = new Button*[2];


	Property * m_prop = new Property();
	m_prop->size = this->left_size;
	m_prop->color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

	a_button[0] = new Button(m_prop);

	Property *m_prop2 = new Property();
	m_prop2->size = this->right_size;
	m_prop2->color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

	a_button[1] = new Button(m_prop2);




}

void ActionSpriteRender::Update(Controller *ctrl, GameObject  *g_obj)
{
	this->left_position = glm::vec2(-left_size.x / 2, ctrl->GetWindowSize().y - left_size.y / 2);
	this->right_position = glm::vec2(ctrl->GetWindowSize().x - right_size.x / 2, ctrl->GetWindowSize().y - right_size.y / 2);

	this->a_button[0]->GetProperties()->position = left_position;
	this->a_button[1]->GetProperties()->position = right_position;




}


void ActionSpriteRender::Render(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj)
{





	this->Update(ctrl, g_obj);

	for (int i = 0; i < 2; i++)
	{
		g_obj->GetUIState()->GetCharPanState()->GetBackpackState()->GetButtonStates()[i] = UI_helper::GetButtonAction(ctrl, this->a_button[i]->GetProperties());


		this->a_button[i]->Render(ctrl, u_data, this->button_skins, i,
			g_obj->GetUIState()->GetCharPanState()->GetBackpackState()->GetButtonStates()[i]);


	}

}