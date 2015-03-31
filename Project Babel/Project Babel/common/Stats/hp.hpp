#ifndef HP_HPP
#define HP_HPP


class Hp
{


public:


	GLuint hp;

	GLuint max_hp;


	inline Hp(){ this->Init(); }


	inline void Init(){ this->hp = 0; this->max_hp = 0; }


	inline void Buff(GLuint hp){ this->hp += hp; this->max_hp += hp; }


	inline void Damage(glm::vec2 attack){ this->hp -= glm::min(this->hp, Rand(attack.x, attack.y)); }

};




#endif