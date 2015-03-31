#include <common.hpp>


void Stats::Init()
{



	this->m_hp = new Hp();
	this->m_xp = new Xp();
	this->base_attack = vec2_0;
	this->base_attack_speed = 0.0f;
	this->base_movement_speed = 0.0f;
	this->base_armor = 0.0f;



}




void Stats::Copy(Stats*other)
{


	this->m_hp->hp = other->GetHp()->hp;
	this->m_xp->xp = other->GetXp()->xp;
	this->m_hp->max_hp = other->GetHp()->max_hp;
	this->base_attack = other->base_attack;
	this->base_attack_speed = other->base_attack_speed;
	this->base_movement_speed = other->base_movement_speed;
	this->base_armor = other->base_armor;




}