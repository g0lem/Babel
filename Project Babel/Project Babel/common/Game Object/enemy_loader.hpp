#pragma once



class EnemyData 
{

public:

	Sprite ** m_sprites;
	GLuint * num_frames;
	GLuint num_dirs;
	Stats * m_stats;

};



class EnemyLoader
{


	std::vector<EnemyData*>*data;


public:



	inline std::vector<EnemyData*>*GetData(){ return this->data; }


	inline EnemyLoader(){ this->Init(); }



	void Init();



};



