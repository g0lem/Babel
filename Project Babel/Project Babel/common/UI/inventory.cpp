#include "common.hpp"

void Inventory::Init(Tooltip *t_tip)
{

	this->box_position = vec2_0;
	this->box_size = glm::vec2(226, 365);

	this->armor_slot_position = vec2_0;
	this->armor_slot_size = glm::vec2(50, 50);
	this->armor_text_position = vec2_0;
	this->armor_text_size = glm::vec2(57, 74);

	this->weapon_text_position = vec2_0;
	this->weapon_text_size = glm::vec2(70, 74);
	this->weapon_slot_position = vec2_0;
	this->weapon_slot_size = glm::vec2(50, 50);

	this->text_position = vec2_0;
	this->text_size = glm::vec2(169, 31);

	this->xbutton_position = vec2_0;
	this->xbutton_size = glm::vec2(32, 32);

	this->inventory_slot_size = glm::vec2(40, 40);

	this->LoadSprites();
	this->LoadItems(t_tip);

	this->mover = new UI_mover();

}

void Inventory::LoadSprites()
{



	this->skins = new Sprite();
	this->weapon = new Sprite();
	this->armor = new Sprite();


	char **textures = new char*[10];

	textures[0] = "inventoryslot.png";
	textures[1] = "inventorybox.png";
	textures[2] = "inventoryboxtoptext.png";
	textures[3] = "armorslotwithtext.png";
	textures[4] = "armorslot.png";
	textures[5] = "weaponslotwithtext.png";
	textures[9] = "equippeditemslot.png";
	textures[6] = "weaponslot.png";
	textures[7] = "xbutton.png";
	textures[8] = "";

	this->skins->Load(10, "data/UI/Inventory/", textures);

}

void Inventory::LoadItems(Tooltip *t_tip)
{
	m_inventory = new Button*[16];

	t_tip->Add(vec2_0, glm::vec2(60, 30), "Weapon", 25, 0);
	t_tip->Add(vec2_0, glm::vec2(60, 30), "Armor", 25, 0);

	for (int i = 0; i < 16; i++)
	{

		Property * m_prop = new Property();
		m_prop->size = inventory_slot_size;
		m_prop->color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

		m_inventory[i] = new Button(m_prop);

		t_tip->Add(m_prop->position, glm::vec2(60, 30), "", 25, 0);


	}

	exit = new Button*[1];
	Property * m_prop = new Property();
	m_prop->size = this->xbutton_size;
	m_prop->color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

	exit[0] = new Button(m_prop);

	w_button = new Button*[1];

	Property * m1_prop = new Property();
	m1_prop->size = weapon_slot_size;
	m1_prop->color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	w_button[0] = new Button(m1_prop);

	for (GLuint j = 0; j < 4; j++)
	{

		for (GLuint i = 0; i < 4; i++)
		{

			this->m_inventory[j * 4 + i]->GetProperties()->position = this->box_position + glm::vec2(33, 173) + glm::vec2(i, j)*this->inventory_slot_size;

		}
	}

	a_button = new Button*[1];
	m1_prop = new Property();
	m1_prop->size = armor_slot_size;
	m1_prop->color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	a_button[0] = new Button(m1_prop);
}

void Inventory::RenderStaticItems(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj)
{
	u_data->SetAmbientLight(glm::vec3(1.f, 1.f, 1.f));

	u_data->ApplyMatrix(Translation(this->box_position)*Scale(this->box_size));
	this->skins->Render(1);

	u_data->ApplyMatrix(Translation(this->box_position + glm::vec2(13, 13))*Scale(text_size));
	this->skins->Render(2);

	u_data->ApplyMatrix(Translation(this->box_position + glm::vec2(129, 69))*Scale(armor_text_size));
	this->skins->Render(3);

	u_data->ApplyMatrix(Translation(this->box_position + glm::vec2(32, 68))*Scale(weapon_text_size));
	this->skins->Render(5);

}

void Inventory::Update(Tooltip *t_tip, Controller *ctrl)
{
	for (GLuint j = 0; j < 4; j++)
	{

		for (GLuint i = 0; i < 4; i++)
		{

			this->m_inventory[j * 4 + i]->GetProperties()->position = this->box_position + glm::vec2(33, 173) + glm::vec2(i, j)*this->inventory_slot_size;

		}
	}

	this->exit[0]->GetProperties()->position = this->box_position + glm::vec2(182, 11);
	this->w_button[0]->GetProperties()->position = box_position + glm::vec2(32, 68) + glm::vec2(11, 0);
	this->a_button[0]->GetProperties()->position = this->box_position + glm::vec2(129, 69) + glm::vec2(5, 0);


}

void Inventory::Render(Tooltip *t_tip, SoundManager *sm, Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj, glm::vec2 player_position)
{



	this->MoveObject(ctrl, g_obj);
	this->AddIntersect(g_obj);



	RenderStaticItems(ctrl, u_data, g_obj);
	this->Update(t_tip, ctrl);




	for (int i = 0; i < 16; i++)
	{
		t_tip->UpdateStatus(INVENTORY_START + i, false);
		g_obj->GetUIState()->GetInventoryState()->GetButtonStates()[i] = UI_helper::GetItemAction(ctrl, this->m_inventory[i]->GetProperties());

		this->m_inventory[i]->RenderItem(ctrl, u_data, this->skins, 0, g_obj->GetUIState()->GetInventoryState()->GetButtonStates()[i]);

		if (i < g_obj->GetItemList()->GetInventory().size())
		{
			u_data->ApplyMatrix(Translation(this->m_inventory[i]->GetProperties()->position + glm::vec2(6, 6))*Scale(glm::vec2(28, 28)));
			g_obj->GetItemList()->GetSprite()->Render(g_obj->GetItemList()->GetInventory()[i]->frame);

			if (g_obj->GetUIState()->GetInventoryState()->GetButtonStates()[i] == PRESSED)
			{

				if (g_obj->GetItemList()->GetInventory()[i]->type == ITEM_TYPE_WEAPON && this->EquippedWeapon == false)
				{

					sm->PlaySound(EQUIPITEM);

					this->weapon = g_obj->GetItemList()->GetSprite();
					this->WeaponFrame = g_obj->GetItemList()->GetInventory()[i]->frame;

					this->w_position = box_position + glm::vec2(32, 68) + glm::vec2(11, 0) + glm::vec2(5, 6);
					this->w_scale = glm::vec2(40, 40);

					this->EquippedWeapon = true;

					this->weapon_item = g_obj->GetItemList()->GetInventory()[i];
					g_obj->GetItemList()->weapon = this->weapon_item;
					g_obj->GetItemList()->must_load = true;
					g_obj->GetItemList()->DeleteFromInventory(i);
				}
				else if (g_obj->GetItemList()->GetInventory()[i]->type == ITEM_TYPE_ARMOR && this->EquippedArmor == false)
				{
					sm->PlaySound(EQUIPITEM);

					this->armor = g_obj->GetItemList()->GetSprite();
					this->ArmorFrame = g_obj->GetItemList()->GetInventory()[i]->frame;

					//this->w_position = box_position + glm::vec2(32, 68) + glm::vec2(11, 0) + glm::vec2(5, 6);
					this->a_position = box_position + glm::vec2(129, 69) + glm::vec2(5, 0) + glm::vec2(5, 6);
					this->w_scale = glm::vec2(40, 40);

					this->EquippedArmor = true;

					this->armor_item = g_obj->GetItemList()->GetInventory()[i];
					g_obj->GetItemList()->armor = this->armor_item;
					g_obj->GetItemList()->must_load = true;
					g_obj->GetItemList()->DeleteFromInventory(i);

				}
				else if (g_obj->GetItemList()->GetInventory()[i]->type == ITEM_TYPE_TRAP)
				{
					g_obj->GetItemList()->SpawnObject(g_obj->GetItemList()->GetInventory()[i]->id, player_position, g_obj->GetItemList()->GetInventory()[i]->attack);
					g_obj->GetItemList()->DeleteFromInventory(i);
				}
				else if (g_obj->GetItemList()->GetInventory()[i]->type == 0)
				{
					g_obj->GetItemList()->must_heal = true;
					g_obj->GetItemList()->DeleteFromInventory(i);
				}


				/*if (g_obj->GetItemList()->GetInventory()[i]->type == 2 && this->EquippedArmor == false)
				{
				sm->PlaySound(EQUIPITEM);

				this->armor = g_obj->GetItemList()->GetSprite();
				this->ArmorFrame = g_obj->GetItemList()->GetInventory()[i]->frame;

				this->a_position = box_position + glm::vec2(129, 69) + glm::vec2(5, 0) + glm::vec2(5, 6);
				this->a_scale = glm::vec2(40, 40);

				this->EquippedArmor = true;

				this->weapon_item = g_obj->GetItemList()->GetInventory()[i];
				g_obj->GetItemList()->armor = this->armor_item;
				g_obj->GetItemList()->must_load = true;
				g_obj->GetItemList()->DeleteFromInventory(i);
				}*/
			}


			if (g_obj->GetUIState()->GetInventoryState()->GetButtonStates()[i] == HOVER)
			{

				t_tip->UpdateStatus(INVENTORY_START + i, true);
				t_tip->UpdateText(INVENTORY_START + i, g_obj->GetItemList()->GetInventory()[i]->item_name);
				t_tip->UpdateSize(INVENTORY_START + i, glm::vec2(g_obj->GetFontList()->GetFont()->GetLength(t_tip->GetTooltips()->at(INVENTORY_START + i)->string, 20) + BORDER_SIZE * 3 + 2, 25 + 13.f));
				t_tip->UpdateStringPosition(INVENTORY_START + i, glm::vec2(ctrl->GetMousePosition().x + 12.f / 2.f + 15.f + 1 / 2.f, ctrl->GetWindowHeight() - (ctrl->GetMousePosition().y + 25 + 15)));
				t_tip->UpdateStringLength(INVENTORY_START + i, g_obj->GetFontList()->GetFont()->GetLength(t_tip->GetTooltips()->at(INVENTORY_START + i)->string, 20));
				t_tip->UpdatePosition(INVENTORY_START + i, ctrl->GetMousePosition());
			}


		}




	}

	g_obj->GetUIState()->GetInventoryState()->GetButtonStates()[16] = UI_helper::GetButtonAction(ctrl, this->exit[0]->GetProperties());
	this->exit[0]->Render(ctrl, u_data, this->skins, 7, g_obj->GetUIState()->GetInventoryState()->GetButtonStates()[16]);


	g_obj->GetUIState()->GetInventoryState()->GetButtonStates()[17] = UI_helper::GetItemAction(ctrl, this->w_button[0]->GetProperties());

	g_obj->GetUIState()->GetInventoryState()->GetButtonStates()[18] = UI_helper::GetItemAction(ctrl, this->a_button[0]->GetProperties());
	if (EquippedWeapon == true)
	{

		this->w_button[0]->Render(ctrl, u_data, this->skins, 9, g_obj->GetUIState()->GetInventoryState()->GetButtonStates()[17]);


		t_tip->UpdateStatus(WEAPON, false);
		w_position = box_position + glm::vec2(32, 68) + glm::vec2(11, 0) + glm::vec2(5, 6);
		u_data->ApplyMatrix(Translation(w_position)*Scale(w_scale));
		this->weapon->Render(WeaponFrame);

		if (g_obj->GetUIState()->GetInventoryState()->GetButtonStates()[17] == PRESSED)
		{
			sm->PlaySound(EQUIPITEM);

			this->EquippedWeapon = false;
			this->w_scale = vec2_0;
			g_obj->GetItemList()->AddtoInventory(weapon_item);
			g_obj->GetItemList()->weapon = g_obj->GetItemList()->GetList()[0];
			g_obj->GetItemList()->must_load = true;
		}

		if (g_obj->GetUIState()->GetInventoryState()->GetButtonStates()[17] == HOVER)
		{
			t_tip->UpdateStatus(WEAPON, true);
			t_tip->UpdatePosition(WEAPON, ctrl->GetMousePosition());
			t_tip->UpdateText(WEAPON, weapon_item->item_name);
		}

	}
	else
	{
		this->w_button[0]->Render(ctrl, u_data, this->skins, 6, g_obj->GetUIState()->GetInventoryState()->GetButtonStates()[17]);

	}


    if (EquippedArmor == true)
	{
	/*this->a_button[0]->Render(ctrl, u_data, this->skins, 9, g_obj->GetUIState()->GetInventoryState()->GetButtonStates()[18]);


	//t_tip->UpdateStatus(WEAPON, false);
	a_position = box_position + glm::vec2(129, 69) + glm::vec2(5, 0) + glm::vec2(5, 6);
	u_data->ApplyMatrix(Translation(a_position)*Scale(a_scale));
	this->armor->Render(ArmorFrame);

	if (g_obj->GetUIState()->GetInventoryState()->GetButtonStates()[18] == PRESSED)
	{
	sm->PlaySound(EQUIPITEM);

	this->EquippedWeapon = false;
	this->a_scale = vec2_0;
	g_obj->GetItemList()->AddtoInventory(armor_item);
	g_obj->GetItemList()->armor = g_obj->GetItemList()->GetList()[0];
	g_obj->GetItemList()->must_load = true;
	}

	if (g_obj->GetUIState()->GetInventoryState()->GetButtonStates()[18] == HOVER)
	{
	//t_tip->UpdateStatus(WEAPON, true);
	//t_tip->UpdatePosition(WEAPON, ctrl->GetMousePosition());
	}
	*/
	}
	else
	{
		this->a_button[0]->Render(ctrl, u_data, this->skins, 4, g_obj->GetUIState()->GetInventoryState()->GetButtonStates()[18]);

	}
}

void Inventory::AddIntersect(GameObject *g_obj)
{




	if (!g_obj->GetUIState()->GetInterHandler()->GetInters()[0][INVENTARY_INTER])
	{

		Golem *g = new Golem();

		g->id = RECT;
		g->position = this->box_position;
		g->size = this->box_size;


		g_obj->GetUIState()->GetInterHandler()->GetInters()[0][INVENTARY_INTER] = g;
	}



}

void Inventory::MoveObject(Controller *ctrl, GameObject *g_obj)
{



	if (g_obj->GetUIState()->GetInterHandler()->GetInters()[0][INVENTARY_INTER] != NULL)
	{



		glm::vec2 position = this->mover->GetTranslation(ctrl, this->box_position, this->box_size);



		if (glm::distance(position, this->box_position) > 0)
		{
			delete g_obj->GetUIState()->GetInterHandler()->GetInters()[0][INVENTARY_INTER];
			g_obj->GetUIState()->GetInterHandler()->GetInters()[0][INVENTARY_INTER] = NULL;

			this->box_position = position;
		}

	}




}
