#pragma once


class StatsText
{
public:
	std::vector<glm::vec2> *positions;
};


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

	inline StatsRender(){ this->Init(); }

	void MoveObject(Controller *ctrl, GameObject *g_obj);

	void AddIntersect(GameObject *g_obj);

	void Render(Controller *ctrl, ScreenUniformData * u_data, GameObject * g_obj);

	void Init();


	inline UI_mover * GetMover(){ return this->mover; }


};

