#pragma once




class StoryRender: public StoryProperties
{
	Sprite *skins, *b_skins, *t_skins, *story, *cons;

	Button ** tablets, **exit;
	
	UI_mover *mover;

	void LoadButtons();

	void LoadSprites();

	void RenderStaticItems(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj);

	void Update(GameObject *g_obj);

	int currentTextFrame = -1;

	bool RenderText = false;

	int currentConsFrame = -1;

	bool RenderCons = false;


public:

	glm::vec2 textsize;
	
	inline StoryRender(){ this->Init(); }

	void MoveObject(Controller *ctrl, GameObject *g_obj);

	void AddIntersect(GameObject *g_obj);

	void Render(Controller *ctrl, ScreenUniformData * u_data, GameObject * g_obj);

	void Init();


	inline UI_mover * GetMover(){ return this->mover; }


};

