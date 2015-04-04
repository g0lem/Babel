#pragma once



class Inventory: public InventoryProperties
{
	Sprite *skins, *item_skins;

	Sprite *weapon, *armor;

	Button ** m_inventory, **exit, **w_button, **a_button;

	UI_mover * mover;

	void LoadItems(Tooltip *t_tip);

	void LoadSprites();

	void ItemSprites();

	void RenderStaticItems(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj);

	void Update(Tooltip *t_tip, Controller *ctrl);

	bool EquippedWeapon = false;
	bool EquippedArmor = false;
	glm::vec2 a_scale;
	glm::vec2 a_position;
	glm::vec2 w_position;
	glm::vec2 w_scale;

	int WeaponFrame;
	int ArmorFrame;
	Item * weapon_item;
	Item * armor_item;
	

	

public:
	void MoveObject(Controller *ctrl, GameObject *g_obj);

	void AddIntersect(GameObject * g_obj);

	inline Inventory(Tooltip *t_tip){ this->Init(t_tip); }

	void Render(Tooltip *t_tip, SoundManager *sm, Controller *ctrl, ScreenUniformData * u_data, GameObject * g_obj);


	void Init(Tooltip *t_tip);


	inline UI_mover * GetMover(){ return this->mover; }


};

