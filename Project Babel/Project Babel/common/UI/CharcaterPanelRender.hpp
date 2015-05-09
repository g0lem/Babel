#pragma once




#define NUM_BUTTONS 32
#define BUTTON_COLS 8
#define BUTTON_ROWS 4
#define TABS 4





class CharPanRender : public BackpackProperties
{



	Sprite * button_skins, *item_skins, *background, *tooltip;

	Button ** m_button, ** t_button;



	UI_mover * mover;



	void LoadButtons();


	void LoadSprites();


	void LoadBackgroundSprite();


	void LoadButtonsSprite();






	void RenderBackground(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj);

	void RenderButtons(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj);

	void RenderTopButtons(Controller *ctrl, ScreenUniformData *u_data, GameObject * g_obj);

	void Update(Controller * ctrl, GameObject * g_obj);

	


	void AddIntersect(GameObject * g_obj);


	void MoveObject(Controller * ctrl, GameObject * g_obj);



public:




	inline CharPanRender(){this->Init();};

	


	void Render(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj);

	inline glm::vec2 GetBackgroundSize(){ return this->scale; }

	inline glm::vec2 GetBackgroundOffset() { return this->position; }




	void Init();





};

