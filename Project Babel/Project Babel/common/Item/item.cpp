#include <common.hpp>





void Item::Set(GLfloat attack_speed,
	glm::vec2 attack,
	GLfloat armor_penetration,
	GLfloat armor,
	GLint effect,
	GLint frame)
{


	this->attack_speed = attack_speed;


	this->attack = attack;


	this->armor_penetration = armor_penetration;


	this->armor = armor;


	this->effect = effect;


	this->frame = frame;


}















Item Item::GenerateItem(int frame)
{
	
	
		sqlite3 *db;
		sqlite3_stmt *res;

		if (sqlite3_open("itest.db", &db))
			sqlite3_close(db);

		Item new_item;



		sqlite3_prepare_v2(db, "SELECT * FROM ITEMS", 128, &res, NULL);

		sqlite3_step(res);

		srand(time(NULL));
		
		
		while (sqlite3_step(res) == SQLITE_ROW)
		{
			if (frame == sqlite3_column_int(res, 0))
			{
				new_item.attack_speed = Rand(sqlite3_column_int(res, 2), sqlite3_column_int(res, 3));
				new_item.attack.x = sqlite3_column_int(res, 4);
				new_item.attack.y = sqlite3_column_int(res, 5);
                new_item.armor = Rand(sqlite3_column_int(res, 6), sqlite3_column_int(res, 7));
				new_item.dodge = Rand(sqlite3_column_int(res, 8), sqlite3_column_int(res, 9));
				new_item.level = Rand(sqlite3_column_int(res, 10), sqlite3_column_int(res, 11));
				
				//std::cout << sqlite3_column_int(res, 3) << " " << sqlite3_column_int(res, 4) << std::endl;
				new_item.frame = frame;
			}
		}
		//std::cout << "Attack Speed: "<< new_item.attack_speed <<std::endl;
		//std::cout << "Attack: " << new_item.attack.x<<" "<<new_item.attack.y << std::endl;
		//std::cout << "Armor: " << new_item.armor<< std::endl;
		//std::cout << "Dodge: " << new_item.dodge<< std::endl;
		//std::cout << "Level: " << new_item.level << std::endl;

		sqlite3_finalize(res);
		sqlite3_close(db);

		//new_item.name = this->NameGenerator(type);



		return new_item;
}