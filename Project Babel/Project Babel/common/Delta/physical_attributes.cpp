#include <common.hpp>


void PhysicalAttributes::Init()
{


	this->position = vec2_0;
	this->target = vec2_0;
	this->scale = vec2_0;
	this->speed = 0.0f;
	this->rotation_angle = 0.0f;
	

}



void PhysicalAttributes::Update(GLfloat delta)
{



	if (position.y - target.y > speed * delta)
		position.y -= speed * delta;
	else if (target.y - position.y > speed * delta)
		position.y += speed * delta;
	else
		position.y = target.y;



	if (position.x - target.x > speed * delta)
		position.x -= speed * delta;
	else if (target.x - position.x > speed * delta)
		position.x += speed * delta;
	else
		position.x = target.x;




}



GLboolean PhysicalAttributes::HasMovedATile(GLfloat delta)
{


	GLfloat distance = glm::distance(position, target);
	return distance < speed*delta && distance > 0;


}



