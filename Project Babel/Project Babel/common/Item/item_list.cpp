#include <common.hpp>




void ItemList::Init()
{

	namelist = new std::vector < names * > ;
	
	this->LoadItems();
    this->LoadSprites();
	


}

void ItemList::AddPotions()
{
	Item *new_item = new Item;
	new_item->Init();
	this->list.push_back(new_item);


}


void ItemList::SpawnObject(int id, glm::vec2 position)
{
	Object *obj = new Object();
	obj->position = position;
	obj->item->id = id;
	this->objectlist.push_back(obj);
    
}

void ItemList::SpawnObject(int id, glm::vec2 position, glm::vec2 damage)
{
	Object *obj = new Object();
	obj->position = position;
	obj->item = new Item();
	obj->item->attack = damage;
 	obj->item->id = id;
	this->traps.push_back(obj);
}

bool ItemList::CheckTileForItem(glm::vec2 position)
{
	for (int i = 0; i < this->dropped_items.size(); i++)
		if (this->dropped_items[i]->position == position)
			return true;

	return false;

}

bool ItemList::CheckTileForChest(glm::vec2 position)
{
	for (int i = 0; i < this->objectlist.size(); i++)
		if (this->objectlist[i]->position == position && this->objectlist[i]->item->id == CHEST_ID)
			return true;

	return false;

}



void ItemList::ClearObjects()
{
	this->objectlist.clear();
}

void ItemList::ClearDroppedItems()
{
	this->dropped_items.clear();
}

void ItemList::LoadItems()
{
	//this->AddPotions();

   

	/*Item *new_item = new Item;
	read_names();


	sqlite3 *db;
	sqlite3_stmt *res;

	if (sqlite3_open("itest.db", &db))
		sqlite3_close(db);

	



	sqlite3_prepare_v2(db, "SELECT * FROM ITEMS", 128, &res, NULL);

	sqlite3_step(res);

	srand(time(NULL));


	while (sqlite3_step(res) == SQLITE_ROW)
	{
		    new_item->frame = sqlite3_column_int(res, 0);
			new_item->attack_speed = Rand(sqlite3_column_int(res, 2), sqlite3_column_int(res, 3));
			new_item->attack.x = sqlite3_column_int(res, 4);
			new_item->attack.y = sqlite3_column_int(res, 5);
			new_item->armor = Rand(sqlite3_column_int(res, 6), sqlite3_column_int(res, 7));
			new_item->dodge = Rand(sqlite3_column_int(res, 8), sqlite3_column_int(res, 9));
			new_item->level = Rand(sqlite3_column_int(res, 10), sqlite3_column_int(res, 11));
		
			this->list.push_back(new_item);


		new_item = new Item;
	}
	

	sqlite3_finalize(res);
	sqlite3_close(db);*/



	Item * m_item = new Item;
	m_item->Init();
	m_item->attack = glm::vec2(0, 0);
	m_item->armor = 0;
	m_item->type = 0;
	m_item->attack_speed = 1.0f; 
	m_item->id = EnemyData::item_types::health_potion_12;
	m_item->item_name = "Health Potion 12";
	this->list.push_back(m_item);
	this->weapon = m_item;
	this->armor = m_item;
	

	m_item = new Item;
	m_item->Init();
	m_item->attack = glm::vec2(0, 0);
	m_item->armor = 0;
	m_item->type = 0;
	m_item->attack_speed = 1.0f;
	m_item->item_name = "Health Potion 20";	
	m_item->id = EnemyData::item_types::health_potion_20;
	this->list.push_back(m_item);
	this->weapon = m_item;
	this->armor = m_item;



	m_item = new Item;
	m_item->Init();
	m_item->attack = glm::vec2(0, 0);
	m_item->armor = 0;
	m_item->type = 0;
	m_item->attack_speed = 1.0f;
	m_item->item_name = "Experience Potion";
	m_item->id = EnemyData::item_types::xp_potion_2;
	this->list.push_back(m_item);
	this->weapon = m_item;
	this->armor = m_item;
	

	m_item = new Item;
	m_item->Init();
	m_item->frame = 1;
	m_item->type = ITEM_TYPE_WEAPON;
	m_item->attack_speed = 1.0f;
	m_item->attack = glm::vec2(2, 3);
	m_item->item_name = "Hammer";
	m_item->id = EnemyData::item_types::Hammer;
	this->list.push_back(m_item);
	

	m_item = new Item;
	m_item->Init();
	m_item->frame = 2;
	m_item->type = ITEM_TYPE_WEAPON;
	m_item->attack_speed = 1.0f;
	m_item->attack = glm::vec2(1, 2);
	m_item->item_name = "Sword"; 
	m_item->id = EnemyData::item_types::Sword;
	this->list.push_back(m_item);
	


	m_item = new Item;
	m_item->Init();
	m_item->frame = 2;
	m_item->type = ITEM_TYPE_WEAPON;
	m_item->attack_speed = 1.0f;
	m_item->attack = glm::vec2(4, 4);
	m_item->item_name = "Epic Sword";
	m_item->base_color = glm::vec4(0.58f, 0.f, 0.82f, 1.f);
	EnemyData::item_types::Epic_Sword;

	this->list.push_back(m_item);
	


	m_item = new Item;
	m_item->Init();
	m_item->frame = 6;
	m_item->type = ITEM_TYPE_ARMOR;
	m_item->armor = 2;
	m_item->item_name = "Leather Armor";
	this->list.push_back(m_item);
	EnemyData::item_types::Leather_Armor_1;

	m_item = new Item;
	m_item->Init();
	m_item->frame = 6;
	m_item->type = ITEM_TYPE_ARMOR;
	m_item->armor = 1;
	m_item->item_name = "Leather Armor";EnemyData::item_types::Leather_Armor_2;
	this->list.push_back(m_item);
	

	m_item = new Item;
	m_item->Init();
	m_item->frame = 5;
	m_item->type = ITEM_TYPE_ARMOR;
	m_item->armor = 2;
	m_item->item_name = "Plate Armor";EnemyData::item_types::Plate_Armor_1;
	this->list.push_back(m_item);
	


	m_item = new Item;
	m_item->Init();
	m_item->frame = 5;
	m_item->type = ITEM_TYPE_ARMOR;
	m_item->armor = 3;
	m_item->item_name = "Plate Armor";EnemyData::item_types::Plate_Armor_2;
	this->list.push_back(m_item);
	


	m_item = new Item;
	m_item->Init();
	m_item->frame = 5;
	m_item->type = ITEM_TYPE_ARMOR;
	m_item->armor = 4;
	m_item->item_name = "Epic Armor";	EnemyData::item_types::Epic_Armor;
	m_item->base_color = glm::vec4(0.58f, 0.f, 0.82f, 1.f);
	this->list.push_back(m_item);




	m_item = new Item();
	m_item->Init();
	m_item->frame = 3;
	m_item->id = CHAINS_ID;
	m_item->type = ITEM_TYPE_TRAP;
	m_item->item_name = "Chains";
	m_item->id = EnemyData::item_types::Chains;
	this->list.push_back(m_item);
	

	m_item = new Item();
	m_item->Init();
	m_item->frame = 4;
	m_item->id = SPIKES_ID;
	m_item->type = ITEM_TYPE_TRAP;
	m_item->item_name = "Spikes";
	m_item->attack = glm::vec2(10, 10);
	m_item->id = EnemyData::item_types::Spikes;
	this->list.push_back(m_item);
}

int ItemList::listed_name(std::string name)
{
	for (int i = 0; i < namelist->size(); i++)
		if (name == namelist->at(i)->type)
			return i;
	return -1;
}



void ItemList::read_names()
{
	sqlite3 *db;
	sqlite3_stmt *res;
	const char *tail;

	if (sqlite3_open("itest.db", &db))
		sqlite3_close(db);

	if (sqlite3_prepare_v2(db, "SELECT * FROM ITEM_NAMES", 128, &res, &tail) != SQLITE_OK)
		sqlite3_close(db);

	

	std::ostringstream buf;
	names *new_name;
	int index;
	while (sqlite3_step(res) == SQLITE_ROW)
	{

		buf << sqlite3_column_text(res, 2);
		if (listed_name(buf.str()) == -1)
		{
			new_name = new names;

			new_name->type = buf.str();
			buf.str("");

			buf << sqlite3_column_text(res, 1);
			new_name->prefix.push_back(buf.str());
			buf.str("");

			buf << sqlite3_column_text(res, 3);
			new_name->sufix.push_back(buf.str());
			buf.str("");

			namelist->push_back(new_name);
		}
		else
		{
			index = listed_name(buf.str());
			buf.str("");

			buf << sqlite3_column_text(res, 1);
			namelist->at(index)->prefix.push_back(buf.str());
			buf.str("");

			buf << sqlite3_column_text(res, 3);
			namelist->at(index)->sufix.push_back(buf.str());
			buf.str("");

		}
		buf.str("");
	}
	sqlite3_finalize(res);
}



std::string ItemList::NameGenerator(std::string type)
{
	int index, random;
	index = this->listed_name(type);



	std::ostringstream buf;

	random = Rand(namelist->at(index)->prefix.size());
	buf << namelist->at(index)->prefix[random] << " ";
	buf << type << " ";

	
	
	random = Rand(namelist->at(index)->sufix.size());
	buf << namelist->at(index)->sufix[random] << " ";

	return buf.str();
	return type;

}


void ItemList::LoadSprites()
{
	char ** tex_str = new char*[7];

	tex_str[0] = "potion.png";
	tex_str[1] = "hammer.png";
	tex_str[2] = "sword.png";
	tex_str[3] = "chains-icon.png";
	tex_str[4] = "spikes-icon.png";
	tex_str[5] = "iron-chestplate.png";
	tex_str[6] = "leather-chestplate-2.png";


	this->m_sprite = new Sprite();

	this->m_sprite->Load(7, "data/items/", tex_str);


	char ** tex_str2 = new char*[13];

	tex_str2[0] = "tablet.png";
	tex_str2[1] = "stairs.png";
	tex_str2[2] = "spikes.png";
	tex_str2[3] = "spikes-fired.png";
	tex_str2[4] = "chains.png";
	tex_str2[5] = "chains-deployed.png";
	tex_str2[6] = "statue.png";
	tex_str2[7] = "pillar.png";
	tex_str2[8] = "chest.png";
	tex_str2[9] = "chest-opened.png";
	tex_str2[10] = "lever.png";
	tex_str2[11] = "lever.png";
	tex_str2[12] = "pitt.png";

	this->s_objects= new Sprite();

	this->s_objects->Load(13, "data/tiles/", tex_str2);

}


void ItemList::AddDroppedItem(int x, int y, Item *item)
{
	Object *dropped_item = new Object();
	dropped_item->position = glm::vec2(x, y);
	dropped_item->item = item;
	dropped_items.push_back(dropped_item);

}

void ItemList::AddtoInventory(Item *item)
{
	this->Inventory.push_back(item);
}