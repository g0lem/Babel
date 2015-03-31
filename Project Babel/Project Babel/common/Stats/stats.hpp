#ifndef STATS_HPP
#define STATS_HPP


class Stats
{


	Hp * m_hp;

	Xp * m_xp;

public:



	glm::vec2 base_attack;
	GLfloat base_attack_speed;
	GLfloat base_movement_speed;
	GLfloat base_armor;



	inline  Hp * GetHp(){ return this->m_hp; }

	inline Xp *GetXp() { return this->m_xp; }

	inline Stats(){ this->Init(); }



	void Init();


	void Copy(Stats * other);


};




#endif