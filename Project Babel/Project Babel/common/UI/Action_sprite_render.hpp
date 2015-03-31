#pragma once



class ActionSpriteRender : public ActionProperties
{

	Sprite * button_skins;

	Button ** a_button;

	void LoadButtons();

	void LoadButtonsSprite();

	void RenderButtons(Controller *ctrl, ScreenUniformData * u_data, GameObject * g_obj);

	void Update(Controller *ctrl, GameObject * g_obj);


public:

	inline ActionSpriteRender() { this->Init(); }

	void Init();
	
	void Render(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj);
	
};

