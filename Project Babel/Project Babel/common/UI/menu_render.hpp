#pragma once

#define MENU_OVERLAY 3

class MenuRender
{
	Sprite * button_skins;

	Button ** menu_buttons;

	void LoadButtons();

	void LoadSprites();

	

public:

	inline MenuRender(){ this->Init(); }

	void RenderButtons(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj);

	void Render(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj);

	void Update(Controller *ctrl);

	void Init();

};

