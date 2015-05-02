#pragma once



#define MENUBUTTON 0
#define WIREFRAME 1
#define HEALTHBAR 2
#define XPBAR 3

class PanelText
{



public:


	void Render(Controller *ctrl, TextRender *tr, GameObject *g_obj)
	{
		tr->SetColor(0.1f, 0.1f, 0.1f);

		g_obj->GetFontList()->GetFont()->Print(g_obj->hp, g_obj->hp_pos.x, ctrl->GetWindowHeight() - g_obj->hp_pos.y, 30);
		g_obj->GetFontList()->GetFont()->Print(g_obj->xp, g_obj->xp_pos.x, ctrl->GetWindowHeight() - g_obj->xp_pos.y, 30);

		tr->SetColor(1.f, 1.f, 1.f);
		g_obj->GetFontList()->GetFont()->Print(g_obj->level, g_obj->level_pos.x, ctrl->GetWindowHeight() - g_obj->level_pos.y, 30);
		g_obj->GetFontList()->GetFont()->Print(g_obj->floor, g_obj->floor_pos.x, ctrl->GetWindowHeight() - g_obj->floor_pos.y, 30);
	}


};


class PanelRender
{

	Sprite * button_skins, *top_skins;

	Button ** a_button;
	Button ** top_buttons;

	glm::vec2 wireframe_position;
	glm::vec2 wireframe_size;

	glm::vec2 menu_position;
	glm::vec2 menu_size;

	glm::vec2 xp_bar_position;
	glm::vec2 xp_bar_size;

	glm::vec2 hp_bar_position;
	glm::vec2 hp_bar_size;

	void LoadButtons(Tooltip *t_tip);
	void LoadButtonsSprite(Tooltip *t_tip);
	void RenderButtons(Controller *ctrl, ScreenUniformData * u_data, GameObject * g_obj);
	void Update(Tooltip *t_tip, Controller *ctrl, GameObject * g_obj);

public:


	inline PanelRender(Tooltip *t_tip) { this->Init(t_tip); }
	void Init(Tooltip *t_tip);
	void Render(SoundManager *sm, Tooltip *t_tip, Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj);



};

