#ifndef ITEM_LIST_HPP
#define ITEM_LIST_HPP






class ItemList
{



	//Item ** list;
	struct Dropped
	{
		int x, y;
		Item* item;
	};

	
	std::vector<Dropped*> dropped_items;

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

	void AddPotions();

public:



	std::string NameGenerator(std::string type);


	void read_names();

	void AddDroppedItem(int x, int y, Item *item);

	void AddtoInventory(Item *item);

	int listed_name(std::string name);

	void LoadSprites();


	inline std::vector <Item*> GetList(){ return this->list; }

	inline std::vector <Item*> GetInventory(){ return this->Inventory; }

	inline std::vector <Dropped*> GetDroppedItems(){ return this->dropped_items; }

	inline Sprite *GetSprite(){ return this->m_sprite; }

	inline ItemList(){ this->Init(); }



	void Init();



};




#endif