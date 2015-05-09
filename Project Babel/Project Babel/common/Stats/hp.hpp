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
	inline void Buff(int hp, int maxhp){
		this->hp += hp;
		this->max_hp += maxhp;
	}
	inline void HealToFull(){ this->hp = this->max_hp; }
	inline void Heal(GLuint hp){ if (this->max_hp - this->hp < hp)this->HealToFull(); else this->hp += hp; }
	inline GLint Damage(glm::vec2 attack){ GLint dmg = glm::min(this->hp, Rand(attack.x, attack.y)); hp -= dmg; return dmg; }

};




#endif