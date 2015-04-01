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
	m_prop->position = vec2_0;

	a_button[0] = new Button(m_prop);

	this->top_skins = new Sprite();

	tex_str[0] = "inspectbutton.png";
	tex_str[1] = "storybutton.png";
	tex_str[2] = "backpackbutton.png";
	tex_str[3] = "skipbutton.png";


	this->top_skins->Load(4, "data/UI/CPanel/", tex_str);


	this->top_buttons = new Button*[4];
	
	for (int i = 0; i < 4; i++)
	{
		Property * m_prop = new Property();
		m_prop->size =glm::vec2(54, 27);
		m_prop->color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
		if (i != 0)
			m_prop->position = glm::vec2(top_buttons[i -1]->GetProperties()->position.x + 54, 0);
		else
			m_prop->position = vec2_0;
		top_buttons[i] = new Button(m_prop);


	}
}

void PanelRender::Update(Controller *ctrl)
{
	
	340, 9;

	wireframe_position = glm::vec2((ctrl->GetWindowWidth() - wireframe_size.x)/2, 0);

	a_button[0]->GetProperties()->position = glm::vec2((ctrl->GetWindowWidth() - wireframe_size.x) / 2 + 459, 11);

	top_buttons[0]->GetProperties()->position = glm::vec2((ctrl->GetWindowWidth() - wireframe_size.x) / 2 + 340, 9);
	top_buttons[1]->GetProperties()->position = glm::vec2((ctrl->GetWindowWidth() - wireframe_size.x) / 2 + 394, 9);
	top_buttons[2]->GetProperties()->position = glm::vec2(a_button[0]->GetProperties()->position.x + 54, 9);
	top_buttons[3]->GetProperties()->position = glm::vec2(top_buttons[2]->GetProperties()->position.x + 54, 9);

	xp_bar_position = glm::vec2((ctrl->GetWindowWidth() - wireframe_size.x) / 2+ 128, 41);

	hp_bar_position = glm::vec2((ctrl->GetWindowWidth() - wireframe_size.x) / 2+ 514, 41);
	
}


void PanelRender::Render(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj)
{

	this->Update(ctrl);

	u_data->SetAmbientLight(glm::vec4(1.f, 1.f, 1.f, 1.f));


	g_obj->GetUIState()->GetPanelState()->SetState(UI_helper::GetButtonAction(ctrl, this->a_button[0]->GetProperties()));

	this->a_button[0]->Render(ctrl, u_data, this->button_skins, 0, g_obj->GetUIState()->GetPanelState()->GetState());
	

		if (g_obj->GetUIState()->GetPanelState()->GetState() == 2)
		{
			if (MenuPressed == false){
				g_obj->GetUIState()->GetMenuState()->SetState(ACTIVE);
				MenuPressed = true;
			}
			else
			{
				g_obj->GetUIState()->GetMenuState()->SetState(NOT_ACTIVE);
				MenuPressed = false;
			}

			
		}



	u_data->SetAmbientLight(glm::vec4(1.f, 1.f, 1.f, 1.f));

	u_data->ApplyMatrix(Translation(this->wireframe_position)*Scale(this->wireframe_size));

	this->button_skins->Render(WIREFRAME);


	for (int i = 0; i < 4; i++)
	{
		
		g_obj->GetUIState()->GetPanelState()->GetButtonsState()[i] = UI_helper::GetButtonAction(ctrl, this->top_buttons[i]->GetProperties());



		this->top_buttons[i]->Render(ctrl, u_data, this->top_skins, i, g_obj->GetUIState()->GetPanelState()->GetButtonsState()[i]);


	}

	if (g_obj->GetUIState()->GetInventoryState()->GetButtonStates()[16] == 2 && g_obj->GetUIState()->GetInventoryState()->GetState() == ACTIVE)
	{
		g_obj->GetUIState()->GetInventoryState()->SetState(NOT_ACTIVE);
		InventoryPressed = !InventoryPressed;
	}
	else
	{


		if (t_clock->getElapsedTime().asSeconds() > 0.2f)
			if (g_obj->GetUIState()->GetPanelState()->GetButtonsState()[2] == 2)
			{
			if (InventoryPressed == false){
				g_obj->GetUIState()->GetInventoryState()->SetState(ACTIVE);
				InventoryPressed = true;

			}
			else
			{
				g_obj->GetUIState()->GetInventoryState()->SetState(NOT_ACTIVE);
				InventoryPressed = false;
			}

			t_clock->restart();
			}

	}
	u_data->SetAmbientLight(glm::vec3(1.f, 1.f, 1.f));
	
	glm::vec2 hp_factor = glm::vec2(GLfloat(g_obj->GetPanelState()->hp) / GLfloat(g_obj->GetPanelState()->max_hp), 1.0f);
	u_data->ApplyMatrix(Translation(this->hp_bar_position)*Scale(this->hp_bar_size*hp_factor));
	this->button_skins->Render(HEALTHBAR);


	u_data->ApplyMatrix(Translation(this->xp_bar_position)*Scale(this->xp_bar_size));


	this->button_skins->Render(XPBAR);



	
}