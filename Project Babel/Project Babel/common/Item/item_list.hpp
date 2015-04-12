#ifndef ITEM_LIST_HPP
#define ITEM_LIST_HPP






class ItemList
{
	


	//Item ** list;

	struct Dropped
	{
		glm::vec2 position;
		Item* item;
		inline Dropped()
		{
			position = vec2_0;
			item = new Item();
		}
	};

	struct Object
	{
		glm::vec2 position;
		glm::vec2 damage;
		int id;
		inline Object(){ position = vec2_0; damage = vec2_0; id = 0; }
	};
   
	
	std::vector<Dropped*> dropped_items;
	std::vector<Dropped*> traps;

	std::vector<Object*> objectlist;
	
	
	std::vector <Item*> list;
	std::vector <Item*> Inventory;

	void LoadItems();

	struct names
	{
		std::string type;
		std::vector<std::string> prefix;
		std::vector<std::string> sufix;
	};

	std::vector<names*> *namelist;

	Sprite *m_sprite;
	Sprite *s_objects;

	void AddPotions();

public:


	GLboolean must_load = true;
	GLboolean must_heal = false;
	Item * weapon = NULL;
	std::string NameGenerator(std::string type);


	void read_names();

	void AddDroppedItem(int x, int y, Item *item);

	void AddtoInventory(Item *item);

	int listed_name(std::string name);

	void LoadSprites();

	void LoadObjects();

	void SpawnObject(int id, glm::vec2 position);
	void SpawnObject(int id, glm::vec2 position, glm::vec2 damage);
	
	void ClearObjects();
	void ClearDroppedItems();

	void DeleteFromInventory(int i){ this->Inventory.erase(Inventory.begin() + i); }

	void DeleteFromDroppedList(int i){ this->dropped_items.erase(dropped_items.begin() + i); }

	void DeleteFromTraps(int i){ this->traps.erase(dropped_items.begin() + i); }

	inline std::vector <Item*> GetList(){ return this->list; }

	inline std::vector <Item*> GetInventory(){ return this->Inventory; }

	inline std::vector <Dropped*> GetDroppedItems(){ return this->dropped_items; }

	inline std::vector <Dropped*> GetTraps(){ return this->traps; }

	inline std::vector <Object*> GetObjects(){ return this->objectlist; }

	inline Sprite *GetSprite(){ return this->m_sprite; }

	inline Sprite *GetObjectSprite(){ return this->s_objects; }

	inline ItemList(){ this->Init(); }



	void Init();



};




#endif