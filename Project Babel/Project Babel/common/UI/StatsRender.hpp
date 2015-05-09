#pragma once




class StatsRender
{
	Sprite *skins;





	Button **exit;

	UI_mover *mover;

	void LoadButtons();

	void LoadSprites();

	void RenderStaticItems(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj);

	void Update(GameObject *g_obj);

	bool RenderText = false;



public:

	glm::vec2 size;
	glm::vec2 button_size;
	glm::vec2 position;
	glm::vec2 button_position;

	glm::vec2 textsize;

	inline StatsRender(GameObject *g_obj){ this->Init(g_obj); }

	void MoveObject(Controller *ctrl, GameObject *g_obj);

	void AddIntersect(GameObject *g_obj);

	void Render(Controller *ctrl, ScreenUniformData * u_data, GameObject * g_obj);

	void Init(GameObject *g_obj);


	inline UI_mover * GetMover(){ return this->mover; }


};

