#include <common.hpp>



void CharPanRender::Init()
{


	this->scale = glm::vec2(300, 400);


	this->button_background_offset = glm::vec2(8.5, 224);

	this->button_background_size = glm::vec2(283, 169);

	this->button_offset = glm::vec2(14.5, 238.5);

	this->button_size = glm::vec2(34, 34);

	this->char_background_offset = glm::vec2(8.5f, 40.5f);

	this->char_background_size = glm::vec2(283, 169);

	this->top_background_offset = glm::vec2(0, 0);

	this->top_background_size = glm::vec2(300, 29);

	this->top_button_size = glm::vec2(67, 26);

	this->top_button_offset = glm::vec2(12.f, 0);

	this->position = glm::vec2(530, 150);

	this->tooltip_size = glm::vec2(70, 65);

	this->tooltip_offset = vec2_0;


	this->LoadSprites();


	this->LoadButtons();



	this->mover = new UI_mover();



}




void CharPanRender::LoadBackgroundSprite()
{


	this->background = new Sprite();
	this->tooltip = new Sprite();

	char ** tex_str = new char*[3];
	char ** tex_str_tt = new char*[1];

	tex_str[0] = "background.png";
	tex_str[1] = "button_background.png";
	tex_str[2] = "top_panel.png";

	tex_str_tt[0] = "button_background.png";

	this->background->Load(3, "data/UI/Backpack/", tex_str);
	this->tooltip->Load(1, "data/UI/Backpack/", tex_str_tt);

}



void CharPanRender::LoadButtonsSprite()
{



	this->button_skins = new Sprite();


	char **tex_str = new char*[5];


	tex_str[0] = "slot.png";
	tex_str[1] = "inventory.png";
	tex_str[2] = "stats.png";
	tex_str[3] = "story.png";
	tex_str[4] = "map.png";


	this->button_skins->Load(5, "data/UI/Backpack/", tex_str);




}



void CharPanRender::LoadSprites()
{




	this->LoadBackgroundSprite();


	this->LoadButtonsSprite();


	


}



void CharPanRender::LoadButtons()
{





	m_button = new Button*[NUM_BUTTONS];


	for (GLuint i = 0; i < NUM_BUTTONS; i++)
	{

		Property * m_prop = new Property();
		m_prop->size = this->button_size;
		m_prop->color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

		m_button[i] = new Button(m_prop);

	}

	t_button = new Button*[4];

	for (int i = 0; i < 4; i++)
	{
		Property * m_prop = new Property();
		m_prop->size = this->top_button_size;
		m_prop->color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

		t_button[i] = new Button(m_prop);
	}

}



void CharPanRender::Update(Controller * ctrl, GameObject * g_obj)
{




	for (GLuint j = 0; j < BUTTON_ROWS; j++)
	{

		for (GLuint i = 0; i < BUTTON_COLS; i++)
		{



			this->m_button[j*8+i]->GetProperties()->position = this->position + this->button_offset + glm::vec2(i,j)*this->button_size;


		}
		


	}

	for (int i = 0; i < 4; i++)
	{
		this->t_button[i]->GetProperties()->position = this->position + this->top_button_offset + glm::vec2(i, 0)*this->top_button_size + glm::vec2(i, 0)*3.f;
	}


}




void CharPanRender::RenderBackground(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj)
{


	u_data->SetAmbientLight(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));






	this->Update(ctrl, g_obj);


	// Rendering Background



	u_data->ApplyMatrix(Translation(this->position)*Scale(this->scale));



	this->background->Render(0);



	// Rendering Item Box



	u_data->ApplyMatrix(Translation(this->position + this->button_background_offset)*
		Scale(this->button_background_size));


	this->background->Render(1);


	// Rendering Char Box;


	u_data->ApplyMatrix(Translation(this->position + this->char_background_offset)*Scale(this->char_background_size));


	this->background->Render(1);

	// Rendering Top Panel;

	u_data->ApplyMatrix(Translation(this->position + this->top_background_offset)*Scale(this->top_background_size));

	this->background->Render(2);


}




void CharPanRender::RenderButtons(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj)
{



	/*for (GLuint i = 0; i < NUM_BUTTONS; i++)
	{


		g_obj->GetUIState()->GetCharPanState()->GetBackpackState()->GetButtonStates()[i] = UI_helper::GetButtonAction(ctrl, this->m_button[i]->GetProperties());

		

		this->m_button[i]->Render(ctrl, u_data, this->button_skins, 0,
			g_obj->GetUIState()->GetCharPanState()->GetBackpackState()->GetButtonStates()[i]);

		
	}*/

	// Tooltip

	/*for (int i = 0; i < NUM_BUTTONS; i++)
	{

		if (g_obj->GetUIState()->GetCharPanState()->GetBackpackState()->GetButtonStates()[i] == HOVER)
		{
			this->tooltip_offset = ctrl->GetMousePosition();
			u_data->ApplyMatrix(Translation(this->tooltip_offset)*Scale(this->tooltip_size));
			this->tooltip->Render(0);
		}



	}*/




}

void CharPanRender::RenderTopButtons(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj)
{



	/*for (int i = 0; i < TABS; i++)
	{
		g_obj->GetUIState()->GetCharPanState()->GetTabsState()->GetTabsState()[i] = UI_helper::GetButtonAction(ctrl, this->t_button[i]->GetProperties());




		this->t_button[i]->Render(ctrl, u_data, this->button_skins, i + 1,
			g_obj->GetUIState()->GetCharPanState()->GetTabsState()->GetTabsState()[i]);


	}*/



	

}



void CharPanRender::AddIntersect(GameObject * g_obj)
{



/*	if (g_obj->GetUIState()->GetCharPanState()->GetColID() == NOT_SET)
	{


		Golem * g = new Golem();


		g->id = RECT;
		g->position = this->position;
		g->size = this->scale;


		g_obj->GetUIState()->GetInterHandler()->GetInters()->push_back(g);
		g_obj->GetUIState()->GetCharPanState()->SetColID(g_obj->GetUIState()->GetInterHandler()->GetInters()->size() - 1);



	}*/




}




void CharPanRender::MoveObject(Controller * ctrl, GameObject * g_obj)
{




	/*glm::vec2 new_pos = this->mover->GetTranslation(ctrl, this->position, this->scale);

	if (glm::distance(new_pos, position) > 0)
	{


		g_obj->GetUIState()->GetInterHandler()->GetInters()->erase(g_obj->GetUIState()->GetInterHandler()->GetInters()->begin() +
			g_obj->GetUIState()->GetCharPanState()->GetColID());
		g_obj->GetUIState()->GetCharPanState()->SetColID(NOT_SET);

		position = new_pos;

	}*/



}





void CharPanRender::Render(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj)
{



	this->MoveObject(ctrl, g_obj);



	this->AddIntersect(g_obj);

	

	this->RenderBackground(ctrl, u_data, g_obj);



	this->RenderTopButtons(ctrl, u_data, g_obj);


	this->RenderButtons(ctrl, u_data, g_obj);



}



