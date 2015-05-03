#pragma once



class EnemyData 
{

public:

	enum item_types
	{
		health_potion_12, health_potion_20, xp_potion_2, Sword = 2, Hammer = 1,
		Leather_Armor_1 = 6, Leather_Armor_2 = 7,Plate_Armor_1 = 8, Plate_Armor_2 = 9, Epic_Sword = 5, 
		Epic_Armor = 10, Scroll, Nothing
	};


	Sprite ** m_sprites;
	GLuint * num_frames;
	GLuint num_dirs;
	Stats * m_stats;
	
	bool ranged;
	bool boss;

	int *chances;
	int *items;
	int num_drop;

	int scale;



};



class EnemyLoader
{


	std::vector<EnemyData*>*data;


	int type = 0;


public:



	inline std::vector<EnemyData*>*GetData(){ return this->data; }


	inline EnemyLoader(){ this->Init(); }

	inline int GetType(){ return this->type; }

	void Init();



};



