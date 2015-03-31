#ifndef ITEM_LIST_HPP
#define ITEM_LIST_HPP






class ItemList
{



	//Item ** list;

	std::vector <Item*> list;

	void LoadItems();

	struct names
	{
		std::string type;
		std::vector<std::string> prefix;
		std::vector<std::string> sufix;
	};

	std::vector<names*> *namelist;



public:

	std::string NameGenerator(std::string type);


	void read_names();


	int listed_name(std::string name);


	inline std::vector <Item*> GetList(){ return this->list; }


	inline ItemList(){ this->Init(); }



	void Init();



};




#endif