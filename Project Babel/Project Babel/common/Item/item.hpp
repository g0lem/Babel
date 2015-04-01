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



	GLint type;



	inline Item(){ this->Init(); }



	void Init();


	
	

std::string item_name;

	





	Item GenerateItem(int type);





	void Set(GLfloat attack_speed,
		glm::vec2 attack,
		GLfloat armor_penetration,
		GLfloat armor,
		GLint effect,
		GLint type);



};





#endif