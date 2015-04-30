#ifndef ITEM_HPP
#define ITEM_HPP

class Item
{


public:

	
	

	GLfloat level;



	GLfloat attack_speed;



	glm::vec2 attack;



	GLfloat armor_penetration;



	GLfloat  armor;

	
	
	GLfloat  dodge;


    
	GLint effect;



	GLint frame;


	int type;

	int id;


	inline Item(){ this->Init(); }



	void Init();


	
	

char * item_name;

	





	Item GenerateItem(int frame);





	void Set(GLfloat attack_speed,
		glm::vec2 attack,
		GLfloat armor_penetration,
		GLfloat armor,
		GLint effect,
		GLint type);



};





#endif