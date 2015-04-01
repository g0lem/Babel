#pragma once



class Inventory: public InventoryProperties
{
	Sprite *skins, *item_skins;

	Button ** m_inventory, **exit;

	UI_mover * mover;

	void LoadItems();

	void LoadSprites();

	void ItemSprites();

	void RenderStaticItems(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj);

	void Update();

	

	

public:
	void MoveObject(Controller *ctrl, GameObject *g_obj);

	void AddIntersect(GameObject * g_obj);

	inline Inventory(){ this->Init(); }

	void Render(Controller *ctrl, ScreenUniformData * u_data, GameObject * g_obj);


	void Init();


};

