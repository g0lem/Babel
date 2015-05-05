#pragma once



class EnemyData 
{

public:

	enum item_types
	{
		health_potion_12, health_potion_20, xp_potion_2, Hammer, Sword, Epic_Sword,
		Leather_Armor_1, Leather_Armor_2 ,Plate_Armor_1 , Plate_Armor_2, 
		Epic_Armor, Scroll, Chains, Spikes, Nothing
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



