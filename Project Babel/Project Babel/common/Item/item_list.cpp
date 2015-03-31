#include <common.hpp>




void ItemList::Init()
{

	namelist = new std::vector < names * > ;

	this->LoadItems();

	



}



void ItemList::LoadItems()
{


   

	Item *new_item = new Item;
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
		
		    
		
		    new_item->type = sqlite3_column_int(res, 0);
			new_item->attack_speed = Rand(sqlite3_column_int(res, 2), sqlite3_column_int(res, 3));
			new_item->attack.x = sqlite3_column_int(res, 4);
			new_item->attack.y = sqlite3_column_int(res, 5);
			new_item->armor = Rand(sqlite3_column_int(res, 6), sqlite3_column_int(res, 7));
			new_item->dodge = Rand(sqlite3_column_int(res, 8), sqlite3_column_int(res, 9));
			new_item->level = Rand(sqlite3_column_int(res, 10), sqlite3_column_int(res, 11));
			//new_item->item_name = NameGenerator(new_item->type);
			std::cout <<"TEST:"<< NameGenerator("sword")<<"\n";

			//std::cout << sqlite3_column_int(res, 3) << " " << sqlite3_column_int(res, 4) << std::endl;
			this->list.push_back(new_item);

			// test
			    /*std::cout << "AS:" << new_item->attack_speed << std::endl;
				std::cout << "AT:" << new_item->attack.x << " " << new_item->attack.y << std::endl;
				std::cout << "AM:" << new_item->armor << std::endl;
				std::cout << "DG:" << new_item->dodge << std::endl;
				std::cout << "LV:" << new_item->level<< std::endl;
				std::cout << "NM:" << new_item->item_name<< std::endl;
				std::cout << "\n\n\n\n *************************************** \n\n\n\n";*/


			


				new_item = new Item;

		
	}
	

	sqlite3_finalize(res);
	sqlite3_close(db);

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
		//is visited == 0
		if (listed_name(buf.str()) == -1)
		{
			new_name = new names;

			new_name->type = buf.str();
			//std::cout << buf.str() << std::endl;
			buf.str("");

			buf << sqlite3_column_text(res, 1);
			new_name->prefix.push_back(buf.str());
			//std::cout << buf.str() << std::endl;
			buf.str("");

			buf << sqlite3_column_text(res, 3);
			new_name->sufix.push_back(buf.str());
			//std::cout << buf.str() << std::endl;
			buf.str("");

			namelist->push_back(new_name);
		}
		else
		{
			index = listed_name(buf.str());
			//std::cout << buf.str() << std::endl;
			buf.str("");

			buf << sqlite3_column_text(res, 1);
			namelist->at(index)->prefix.push_back(buf.str());
			//std::cout << buf.str() << std::endl;
			buf.str("");

			buf << sqlite3_column_text(res, 3);
			namelist->at(index)->sufix.push_back(buf.str());
			//std::cout << buf.str() << std::endl;
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

	//srand(Rand(1000));
	

	random = Rand(namelist->at(index)->prefix.size());
	buf << namelist->at(index)->prefix[random] << " ";
	buf << type << " ";

	
	
	random = Rand(namelist->at(index)->sufix.size());
	buf << namelist->at(index)->sufix[random] << " ";

	return buf.str();
	return type;

}

