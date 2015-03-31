#include <common.hpp>


void TurnSystem::Init()
{


	this->turns = 0.0f;


}



void TurnSystem::ComputeAttack(GLfloat attack_speed)
{



	this->turns += 1.0f / attack_speed;



}



void TurnSystem::ComputeMovement(GLfloat movement_speed)
{


	this->turns += 1.0f / movement_speed;


}