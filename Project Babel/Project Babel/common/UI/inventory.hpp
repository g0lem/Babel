#pragma once



class Inventory: public InventoryProperties
{
	Sprite *skins, *item_skins;

	Sprite *weapon, *armor;

	Button ** m_inventory, **exit, **w_button;

	UI_mover * mover;

	void LoadItems();

	void LoadSprites();

	void ItemSprites();

	void RenderStaticItems(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj);

	void Update();

	bool EquippedWeapon = false;

	glm::vec2 w_position;
	glm::vec2 w_scale;

	int WeaponFrame;

	

	

public:
	void MoveObject(Controller *ctrl, GameObject *g_obj);

	void AddIntersect(GameObject * g_obj);

	inline Inventory(){ this->Init(); }

	void Render(Controller *ctrl, ScreenUniformData * u_data, GameObject * g_obj);


	void Init();


	inline UI_mover * GetMover(){ return this->mover; }


};

