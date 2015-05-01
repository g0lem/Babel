#pragma once



class EnemyData 
{

public:

	enum item_types
	{
		health_potion_12, health_potion_20, xp_potion_2, Sword, Hammer, Leather_Armor, Plate_Armor, Epic_Sword, Scroll, Nothing
	};


	Sprite ** m_sprites;
	GLuint * num_frames;
	GLuint num_dirs;
	Stats * m_stats;
	
	bool ranged;

	int *chances;
	int *items;
	int num_drop;

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



