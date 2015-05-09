#include "common.hpp"




void PanelRender::Init(Tooltip *t_tip)
{
	wireframe_position = vec2_0;
	wireframe_size = glm::vec2(960, 64);

	menu_position = glm::vec2(459, 11);
	menu_size = glm::vec2(42, 42);

	xp_bar_position = glm::vec2(128, 41);
	xp_bar_size = glm::vec2(319, 20);

	hp_bar_position = glm::vec2(514, 41);
	hp_bar_size = glm::vec2(314, 20);


	spell_position = glm::vec2(0);
	spell_size = glm::vec2(50);


	LoadButtonsSprite(t_tip);


}

void PanelRender::LoadButtonsSprite(Tooltip *t_tip)
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

	t_tip->Add(m_prop->position, glm::vec2(60, 30), "Menu", 40, 0);

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
		m_prop->size = glm::vec2(54, 27);
		m_prop->color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
		if (i != 0)
			m_prop->position = glm::vec2(top_buttons[i - 1]->GetProperties()->position.x + 54, 0);
		else
			m_prop->position = vec2_0;
		top_buttons[i] = new Button(m_prop);


	}
	t_tip->Add(m_prop->position, glm::vec2(144, 53), "Menu", 40, 0);
	t_tip->Add(m_prop->position, glm::vec2(144, 53), "Stats", 40, 0);
	t_tip->Add(m_prop->position, glm::vec2(144, 53), "Story", 40, 0);
	t_tip->Add(m_prop->position, glm::vec2(144, 53), "Inventory", 40, 0);
	t_tip->Add(m_prop->position, glm::vec2(144, 53), "Pass Turn", 40, 0);

	this->spell_skin = new Sprite();
	this->spell_skin->Load("data/UI/SpellFrame.png");

	m_prop = new Property();
	m_prop->size = glm::vec2(50, 50);
	m_prop->color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_prop->position = vec2_0;
	spell_button = new Button(m_prop);
}

void PanelRender::Update(Tooltip *t_tip, Controller *ctrl, GameObject * g_obj)
{



	wireframe_position = glm::vec2((ctrl->GetWindowWidth() - wireframe_size.x) / 2, 0);
	a_button[0]->GetProperties()->position = glm::vec2((ctrl->GetWindowWidth() - wireframe_size.x) / 2 + 459 , 11);


	top_buttons[0]->GetProperties()->position = glm::vec2((ctrl->GetWindowWidth() - wireframe_size.x) / 2 + 340 , 9);
	top_buttons[1]->GetProperties()->position = glm::vec2((ctrl->GetWindowWidth() - wireframe_size.x) / 2 + 394 , 9);
	top_buttons[2]->GetProperties()->position = glm::vec2(a_button[0]->GetProperties()->position.x + 54 , 9);
	top_buttons[3]->GetProperties()->position = glm::vec2(top_buttons[2]->GetProperties()->position.x + 54 , 9);
	spell_button->GetProperties()->position = glm::vec2((ctrl->GetWindowWidth()/2.f) - spell_size.x / 2.f, ctrl->GetWindowHeight() - 75);

	if (ctrl->HasBeenResized())
	{


		delete g_obj->GetUIState()->GetInterHandler()->GetInters()[0][MENU_BUTTON];
		g_obj->GetUIState()->GetInterHandler()->GetInters()[0][MENU_BUTTON] = NULL;


		for (GLuint i = 0; i < 4; i++)
		{
			delete g_obj->GetUIState()->GetInterHandler()->GetInters()[0][i + 2];
			g_obj->GetUIState()->GetInterHandler()->GetInters()[0][i + 2] = NULL;
		}

		delete g_obj->GetUIState()->GetInterHandler()->GetInters()[0][7];
		g_obj->GetUIState()->GetInterHandler()->GetInters()[0][7] = NULL;

		ctrl->SetResized(false);

	}


	if (!g_obj->GetUIState()->GetInterHandler()->GetInters()[0][MENU_BUTTON])
	{
		Golem *g = new Golem();
		g->id = RECT;
		g->position = a_button[0]->GetProperties()->position;
		g->size = glm::vec2(42, 42);
		g_obj->GetUIState()->GetInterHandler()->GetInters()[0][MENU_BUTTON] = g;
	}


	for (GLuint i = 0; i < 4; i++)
		if (!g_obj->GetUIState()->GetInterHandler()->GetInters()[0][i + 2])
		{
		Golem *g = new Golem();
		g->id = RECT;
		g->position = top_buttons[i]->GetProperties()->position;
		g->size = glm::vec2(54, 27);
		g_obj->GetUIState()->GetInterHandler()->GetInters()[0][i + 2] = g;
		}

	if (!g_obj->GetUIState()->GetInterHandler()->GetInters()[0][7])
	{
		Golem *g = new Golem();
		g->id = RECT;
		g->position = spell_button->GetProperties()->position;
		g->size = glm::vec2(50, 50);
		g_obj->GetUIState()->GetInterHandler()->GetInters()[0][7] = g;
	}



	xp_bar_position = glm::vec2((ctrl->GetWindowWidth() - wireframe_size.x) / 2 + 128, 41);
	hp_bar_position = glm::vec2((ctrl->GetWindowWidth() - wireframe_size.x) / 2 + 514, 41);

}


void PanelRender::Render(SoundManager *sm, Tooltip *t_tip, Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj)
{


	this->Update(t_tip, ctrl, g_obj);




	{//MENU BUTTON

		u_data->SetAmbientLight(glm::vec4(1.f, 1.f, 1.f, 1.f));


		g_obj->GetUIState()->GetPanelState()->SetState(UI_helper::GetButtonAction(ctrl, this->a_button[0]->GetProperties()));
		this->a_button[0]->Render(ctrl, u_data, this->button_skins, 0, g_obj->GetUIState()->GetPanelState()->GetState());

		if (g_obj->GetUIState()->GetPanelState()->GetState() == HOVER)
		{
			t_tip->UpdateStatus(DOOR_TOOL_TIP, false);
			t_tip->UpdateStatus(0, true);
			//t_tip->UpdateSize(0, glm::vec2(g_obj->GetFontList()->GetFont()->GetLength(t_tip->GetTooltips()->at(0)->string, 40) + t_tip->corner.x * 2 + t_tip->GetOffset(0), 40 + t_tip->corner.y));			
			t_tip->UpdateSize(0, glm::vec2(g_obj->GetFontList()->GetFont()->GetLength(t_tip->GetTooltips()->at(0)->string, 40) + t_tip->corner.x * 2 + 5, 40 + t_tip->corner.y));

			t_tip->UpdateStringLength(0, g_obj->GetFontList()->GetFont()->GetLength(t_tip->GetTooltips()->at(0)->string, 40));
			t_tip->UpdateStringPosition(0, glm::vec2(10 + ctrl->GetMousePosition().x + 12.f / 2.f + 15.f + 1 / 2.f, ctrl->GetWindowHeight() - (5 + ctrl->GetMousePosition().y + 40 + 13 / 2.f + 1)));
			t_tip->UpdatePosition(0, ctrl->GetMousePosition());
		}
		else
		{
			t_tip->UpdateStatus(0, false);
		}

		if (g_obj->GetUIState()->GetPanelState()->GetState() == PRESSED)
		{
			//sm->PlaySound(MENUPRESSBUTTON);
			g_obj->GetUIState()->GetMenuState()->SetState(!g_obj->GetUIState()->GetMenuState()->GetState());
			t_tip->UpdateStatus(0, g_obj->GetUIState()->GetMenuState()->GetState());
		}

	}


	{//WIREFRAME

		u_data->SetAmbientLight(glm::vec4(1.f, 1.f, 1.f, 1.f));
		u_data->ApplyMatrix(Translation(this->wireframe_position)*Scale(this->wireframe_size));
		this->button_skins->Render(WIREFRAME);


	}


	/*if (g_obj->GetStatState()->GetState() == ACTIVE)
	{
		u_data->SetAmbientLight(glm::vec4(1.f, 1.f, 1.f, 1.f));
		u_data->ApplyMatrix(Translation(this->stat_position)*Scale(this->stat_size));
		this->stat_skin->Render(0);
	

	glm::vec2 position = this->mover->GetTranslation(ctrl, this->stat_position, this->stat_size);


	if (glm::distance(position, this->stat_position) > 0)
		this->stat_position = position;

	}*/

	for (int i = 0; i < 4; i++)//BUTTONS
	{


		g_obj->GetUIState()->GetPanelState()->GetButtonsState()[i] = UI_helper::GetButtonAction(ctrl, this->top_buttons[i]->GetProperties());
		this->top_buttons[i]->Render(ctrl, u_data, this->top_skins, i, g_obj->GetUIState()->GetPanelState()->GetButtonsState()[i]);


	}
	if (g_obj->spellsize > 0){

		this->spell_button->Render(ctrl, u_data, spell_skin, 0, 0);
		u_data->ApplyMatrix(Translation(spell_button->GetProperties()->position + glm::vec2(9, 9))*Scale(g_obj->spellsize)*Rotation(0));
		g_obj->spellsprite->Render(g_obj->spellframe);
	}

	if (g_obj->cooldown > 0)
	{

		
		g_obj->spellPOS.x = spell_button->GetProperties()->position.x + 10;
		g_obj->spellPOS.y = ctrl->GetWindowHeight() - spell_button->GetProperties()->position.y - 38;
	}


	{//INVENTARY AND STORY
		if (g_obj->GetUIState()->GetPanelState()->GetButtonsState()[0] == PRESSED || (g_obj->GetUIState()->GetStatState()->GetButtonState()[0] == PRESSED && g_obj->GetUIState()->GetStatState()->GetState() == ACTIVE))
		{
			g_obj->GetUIState()->GetStatState()->SetState(!g_obj->GetUIState()->GetStatState()->GetState());


			if (g_obj->GetUIState()->GetInterHandler()->GetInters()[0][8] != NULL)
			{
				delete g_obj->GetUIState()->GetInterHandler()->GetInters()[0][8];
				g_obj->GetUIState()->GetInterHandler()->GetInters()[0][8] = NULL;
			}
		}

		if (g_obj->GetUIState()->GetInventoryState()->GetButtonStates()[16] == PRESSED &&
			g_obj->GetUIState()->GetInventoryState()->GetState())
		{


			//sm->PlaySound(MENUPRESSBUTTON);

			g_obj->GetUIState()->GetInventoryState()->SetState(NOT_ACTIVE);

			if (g_obj->GetUIState()->GetInterHandler()->GetInters()[0][INVENTARY_INTER] != NULL)
			{
				delete g_obj->GetUIState()->GetInterHandler()->GetInters()[0][INVENTARY_INTER];
				g_obj->GetUIState()->GetInterHandler()->GetInters()[0][INVENTARY_INTER] = NULL;
			}


		}

		if (g_obj->GetUIState()->GetPanelState()->GetButtonsState()[2] == HOVER)
		{
			t_tip->UpdateStatus(DOOR_TOOL_TIP, false);
			t_tip->UpdateStatus(4, true);
			t_tip->UpdatePosition(4, ctrl->GetMousePosition());
			t_tip->UpdateOffset(4, 10);
			t_tip->UpdateVoffset(4, 6);
			t_tip->UpdateSize(4, glm::vec2(g_obj->GetFontList()->GetFont()->GetLength(t_tip->GetTooltips()->at(4)->string, 40) + t_tip->corner.x * 2 + t_tip->GetOffset(4), 40 + t_tip->corner.y));

			t_tip->UpdateStringPosition(4, glm::vec2(10 + ctrl->GetMousePosition().x + 12.f / 2.f + 15.f + 1 / 2.f, ctrl->GetWindowHeight() - (10 + ctrl->GetMousePosition().y + 40 + 13 / 2.f + 1)));
			t_tip->UpdateStringLength(4, g_obj->GetFontList()->GetFont()->GetLength(t_tip->GetTooltips()->at(4)->string, 40));

			

		}
		else
			t_tip->UpdateStatus(4, false);



		if (g_obj->GetUIState()->GetPanelState()->GetButtonsState()[2] == PRESSED)
		{

			//sm->PlaySound(MENUPRESSBUTTON);


			g_obj->GetUIState()->GetInventoryState()->SetState(!g_obj->GetUIState()->GetInventoryState()->GetState());


			if (g_obj->GetUIState()->GetInterHandler()->GetInters()[0][INVENTARY_INTER] != NULL)
			{
				delete g_obj->GetUIState()->GetInterHandler()->GetInters()[0][INVENTARY_INTER];
				g_obj->GetUIState()->GetInterHandler()->GetInters()[0][INVENTARY_INTER] = NULL;
			}

		}






		if (g_obj->GetUIState()->GetStoryState()->GetButtonState()[12] == PRESSED &&
			g_obj->GetUIState()->GetStoryState()->GetState())
		{



			//sm->PlaySound(MENUPRESSBUTTON);



			g_obj->GetUIState()->GetStoryState()->SetState(NOT_ACTIVE);

			if (g_obj->GetUIState()->GetInterHandler()->GetInters()[0][STORY_INTER] != NULL)
			{
				delete g_obj->GetUIState()->GetInterHandler()->GetInters()[0][STORY_INTER];
				g_obj->GetUIState()->GetInterHandler()->GetInters()[0][STORY_INTER] = NULL;
			}


		}

		if (g_obj->GetUIState()->GetSpellState()->GetState() == PRESSED)
		{
			g_obj->GetItemList()->AddtoInventory(g_obj->GetItemList()->scroll);
			g_obj->GetItemList()->scroll = new Item();
			g_obj->GetItemList()->must_load = true;
		}

		if (g_obj->GetUIState()->GetPanelState()->GetButtonsState()[1] == HOVER)
		{
			t_tip->UpdateStatus(DOOR_TOOL_TIP, false);
			t_tip->UpdateStatus(3, true);
			t_tip->UpdatePosition(3, ctrl->GetMousePosition());
			

			t_tip->UpdateOffset(3, 10);
			t_tip->UpdateVoffset(3, 6);
			t_tip->UpdateSize(3, glm::vec2(g_obj->GetFontList()->GetFont()->GetLength(t_tip->GetTooltips()->at(4)->string, 40) + t_tip->corner.x * 2 + t_tip->GetOffset(4), 40 + t_tip->corner.y));

			t_tip->UpdateStringPosition(3, glm::vec2(40 + ctrl->GetMousePosition().x + 12.f / 2.f + 15.f + 1 / 2.f, ctrl->GetWindowHeight() - (10 + ctrl->GetMousePosition().y + 40 + 13 / 2.f + 1)));
			t_tip->UpdateStringLength(3, g_obj->GetFontList()->GetFont()->GetLength(t_tip->GetTooltips()->at(4)->string, 40));

		}
		else
			t_tip->UpdateStatus(3, false);



		if (g_obj->GetUIState()->GetPanelState()->GetButtonsState()[1] == PRESSED)
		{

			//sm->PlaySound(MENUPRESSBUTTON);


			g_obj->GetUIState()->GetStoryState()->SetState(!g_obj->GetUIState()->GetStoryState()->GetState());


			if (g_obj->GetUIState()->GetInterHandler()->GetInters()[0][STORY_INTER] != NULL)
			{
				delete g_obj->GetUIState()->GetInterHandler()->GetInters()[0][STORY_INTER];
				g_obj->GetUIState()->GetInterHandler()->GetInters()[0][STORY_INTER] = NULL;
			}



		}

		if (g_obj->GetUIState()->GetPanelState()->GetButtonsState()[3] == HOVER)
		{
			t_tip->UpdateStatus(DOOR_TOOL_TIP, false);
			t_tip->UpdateStatus(5, true);
			t_tip->UpdatePosition(5, ctrl->GetMousePosition());
			

			t_tip->UpdateOffset(5, 10);
			t_tip->UpdateVoffset(5, 6);
			t_tip->UpdateSize(5, glm::vec2(g_obj->GetFontList()->GetFont()->GetLength(t_tip->GetTooltips()->at(4)->string, 40) + t_tip->corner.x * 2 + t_tip->GetOffset(4), 40 + t_tip->corner.y));

			t_tip->UpdateStringPosition(5, glm::vec2(10 + ctrl->GetMousePosition().x + 12.f / 2.f + 15.f + 1 / 2.f, ctrl->GetWindowHeight() - (10 + ctrl->GetMousePosition().y + 40 + 13 / 2.f + 1)));
			t_tip->UpdateStringLength(5, g_obj->GetFontList()->GetFont()->GetLength(t_tip->GetTooltips()->at(4)->string, 40));

		}
		else
			t_tip->UpdateStatus(5, false);


		if (g_obj->GetUIState()->GetPanelState()->GetButtonsState()[3] == PRESSED)
		{

			//sm->PlaySound(MENUPRESSBUTTON);


			g_obj->GetTurnSystem()->Wait();
		}

		if (g_obj->GetUIState()->GetPanelState()->GetButtonsState()[0] == HOVER)
		{
			t_tip->UpdateStatus(DOOR_TOOL_TIP, false);
			t_tip->UpdateStatus(2, true);
			t_tip->UpdatePosition(2, ctrl->GetMousePosition());
			

			t_tip->UpdateOffset(2, 10);
			t_tip->UpdateVoffset(2, 6);
			t_tip->UpdateSize(2, glm::vec2(g_obj->GetFontList()->GetFont()->GetLength(t_tip->GetTooltips()->at(4)->string, 40) + t_tip->corner.x * 2 + t_tip->GetOffset(4), 40 + t_tip->corner.y));

			t_tip->UpdateStringPosition(2, glm::vec2(40 + ctrl->GetMousePosition().x + 12.f / 2.f + 15.f + 1 / 2.f, ctrl->GetWindowHeight() - (10 + ctrl->GetMousePosition().y + 40 + 13 / 2.f + 1)));
			t_tip->UpdateStringLength(2, g_obj->GetFontList()->GetFont()->GetLength(t_tip->GetTooltips()->at(4)->string, 40));

		}
		else
			t_tip->UpdateStatus(2, false);


	}


	{//HP AND XP BARS


		u_data->SetAmbientLight(glm::vec3(1.f, 1.f, 1.f));


		glm::vec2 hp_factor = glm::vec2(GLfloat(g_obj->GetPanelState()->hp) / GLfloat(g_obj->GetPanelState()->max_hp), 1.0f);
		u_data->ApplyMatrix(Translation(this->hp_bar_position)*Scale(this->hp_bar_size*hp_factor));
		this->button_skins->Render(HEALTHBAR);

		char *buffer = new char[256];
		char *buffer2 = new char[256];
		char *text = new char[256];
		_itoa(g_obj->GetPanelState()->hp, buffer, 10);
		strcat(buffer, " / ");
		_itoa(g_obj->GetPanelState()->max_hp, buffer2, 10);
		strcat(buffer, buffer2);
		g_obj->hp = buffer;
		g_obj->hp_pos = hp_bar_position + glm::vec2(0, 15 + 1/2.f);

		glm::vec2 xp_factor = glm::vec2(GLfloat(g_obj->GetPanelState()->xp) / GLfloat(g_obj->GetPanelState()->max_xp), 1.0f);
		u_data->ApplyMatrix(Translation(this->xp_bar_position + glm::vec2(this->xp_bar_size.x - (this->xp_bar_size*xp_factor).x, 0))
			*Scale(this->xp_bar_size*xp_factor));
		this->button_skins->Render(XPBAR);
		
		buffer = new char[256];
		buffer2 = new char[256];

		_itoa(g_obj->GetPanelState()->xp, buffer, 10);
		strcat(buffer, " / ");
		_itoa(g_obj->GetPanelState()->max_xp, buffer2, 10);
		strcat(buffer, buffer2);
		g_obj->xp = buffer;
		g_obj->xp_pos = xp_bar_position  + glm::vec2(xp_bar_size.x - 2.f, 15 + 1/2.f) - glm::vec2(g_obj->GetFontList()->GetFont()->GetLength(buffer, 30) + 7.5, 0);



		// Level and Floor rendering 

		buffer = new char[256];
		buffer2 = new char[256];

		

		_itoa(g_obj->GetPanelState()->level, buffer2, 10);
	
		strcpy(buffer, "Level: ");
		strcat(buffer, buffer2);

		g_obj->level = buffer;
		g_obj->level_pos = wireframe_position + glm::vec2(2.f, wireframe_size.y + 1 / 2.f - 7.5);

		buffer = new char[256];
		buffer2 = new char[256];

		_itoa(g_obj->floor_c, buffer2, 10);
		
		strcpy(buffer, "Floor: ");
		strcat(buffer, buffer2);


		g_obj->floor = buffer;
		g_obj->floor_pos = g_obj->level_pos + glm::vec2(0, 30);

	}


}