#ifndef PHYSICAL_ATTRIBUTES_HPP
#define PHYSICAL_ATTRIBUTES_HPP



class PhysicalAttributes
{


public:

	PhysiscalEffects *Peffects;

	glm::vec2 position;
	glm::vec2 target;
	glm::vec2 scale;
	GLfloat speed;
	GLfloat rotation_angle;
	GLboolean visible;

	inline PhysicalAttributes(){ this->Init(); }
	void Init();



	void Update(GLfloat delta);
	GLboolean HasMovedATile(GLfloat delta);
	inline GLboolean HasReachedTarget(){ return position == target; }


};




#endif