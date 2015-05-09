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

	int spell;

	GLint frame;


	int type;

	int id;


	inline Item(){ 
		this->id = 0;

		this->armor = 0.0f;


		this->armor_penetration = 0.0f;


		this->attack = vec2_0;


		this->attack_speed = 0.0f;


		this->effect = 0;

		this->base_color = glm::vec4(1, 1, 1, 1);
		this->color = glm::vec4(1.f, 1.f, 1.f, 1.f);

		this->frame = 0;
		this->spell = -1;
		this->type = 0;
	}

	glm::vec4 color;
	glm::vec4 base_color;

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