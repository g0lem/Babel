#pragma once




class StoryRender: public StoryProperties
{
	Sprite *skins, *b_skins, *t_skins;

	Button ** tablets, **exit;
	
	UI_mover *mover;

	void LoadButtons();

	void LoadSprites();

	void RenderStaticItems(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj);

	void Update();


public:
	
	inline StoryRender(){ this->Init(); }

	void MoveObject(Controller *ctrl, GameObject *g_obj);

	void AddIntersect(GameObject *g_obj);

	void Render(Controller *ctrl, ScreenUniformData * u_data, GameObject * g_obj);

	void Init();


	inline UI_mover * GetMover(){ return this->mover; }


};

