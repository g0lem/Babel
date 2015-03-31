#include "common.hpp"

void PanelRender::Init()
{
	wireframe_position = vec2_0;
	wireframe_size = glm::vec2(960, 64);

	menu_position = glm::vec2(459, 11);
	menu_size = glm::vec2(42, 42);

	xp_bar_position = glm::vec2(128, 41);
	xp_bar_size = glm::vec2(319, 20);

	hp_bar_position = glm::vec2(514, 41);
	hp_bar_size = glm::vec2(314, 20);

	t_clock = new sf::Clock();

	LoadButtonsSprite();


}

void PanelRender::LoadButtonsSprite()
{
	this->button_skins = new Sprite();

	char **tex_str = new char*[4];

	tex_str[MENUBUTTON] = "menu_button.png";
	tex_str[WIREFRAME] = "wireframe.png";
	tex_str[HEALTHBAR] = "healthbar.png";
	tex_str[XPBAR] = "xpbar.png";


	this->button_skins->Load(4, "data/UI/CPanel/", tex_str); 

	this->a_button = new Button*[1];

	Property * m_prop = new Property();
	m_prop->size = this->menu_size;
	m_prop->color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_prop->position = this->menu_position;

	a_button[0] = new Button(m_prop);
}




void PanelRender::Render(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj)
{
	u_data->SetAmbientLight(glm::vec4(1.f, 1.f, 1.f, 1.f));


	g_obj->GetUIState()->GetPanelState()->SetState(UI_helper::GetButtonAction(ctrl, this->a_button[0]->GetProperties()));

	this->a_button[0]->Render(ctrl, u_data, this->button_skins, 0, g_obj->GetUIState()->GetPanelState()->GetState());
	

	if (t_clock->getElapsedTime().asSeconds() > 0.2f)
		if (g_obj->GetUIState()->GetPanelState()->GetState() == 2)
		{
			if (pressed == false){
				g_obj->GetUIState()->GetCharPanState()->SetState(ACTIVE);
				pressed = true;
			}
			else
			{
				g_obj->GetUIState()->GetCharPanState()->SetState(NOT_ACTIVE);
				pressed = false;
			}

			t_clock->restart();
		}



	u_data->SetAmbientLight(glm::vec4(1.f, 1.f, 1.f, 1.f));

	u_data->ApplyMatrix(Translation(this->wireframe_position)*Scale(this->wireframe_size));

	this->button_skins->Render(WIREFRAME);


	
	glm::vec2 hp_factor = glm::vec2(GLfloat(g_obj->GetPanelState()->hp) / GLfloat(g_obj->GetPanelState()->max_hp), 1.0f);
	u_data->ApplyMatrix(Translation(this->hp_bar_position)*Scale(this->hp_bar_size*hp_factor));
	this->button_skins->Render(HEALTHBAR);


	u_data->ApplyMatrix(Translation(this->xp_bar_position)*Scale(this->xp_bar_size));


	this->button_skins->Render(XPBAR);



	
}