#pragma once



#define NONE 0
#define HOVER 1
#define PRESSED 2
#define RIGHT_CLICKED 3

struct PanelProperties
{
	
};

struct InventoryProperties
{
	glm::vec2 box_position;
	glm::vec2 box_size;

	glm::vec2 text_position;
	glm::vec2 text_size;

	glm::vec2 armor_text_position;
	glm::vec2 armor_text_size;
	glm::vec2 armor_slot_position;
	glm::vec2 armor_slot_size;

	glm::vec2 weapon_text_position;
	glm::vec2 weapon_text_size;
	glm::vec2 weapon_slot_position;
	glm::vec2 weapon_slot_size;

	glm::vec2 xbutton_position;
	glm::vec2 xbutton_size;

	glm::vec2 inventory_slot_size;
};


struct BackpackProperties
{
	glm::vec2 position;
	glm::vec2 scale;
	glm::vec2 button_background_offset;
	glm::vec2 button_background_size;
	glm::vec2 char_background_offset;
	glm::vec2 char_background_size;
	glm::vec2 top_background_offset;
	glm::vec2 top_background_size;
	glm::vec2 top_button_size;
	glm::vec2 top_button_offset;
	glm::vec2 button_offset;
	glm::vec2 button_size;

	glm::vec2 tooltip_size;
	glm::vec2 tooltip_offset;
};

class ActionProperties
{

public:


	glm::vec2 left_position;
	glm::vec2 left_size;
	glm::vec2 left_radius;
	glm::vec2 right_position;
	glm::vec2 right_size;
	glm::vec2 right_radius;
	glm::vec2 size;
	glm::vec2 radius;

	inline glm::vec2 GetLeftSize(){ return this->left_size; }

	inline glm::vec2 GetRightSize(){ return this->right_size; }

	inline glm::vec2 GetLeftPosition() { return this->left_position; }

	inline glm::vec2 GetRightPosition() { return this->right_position; }

	inline glm::vec2 GetLeftRadius() { return this->left_radius; }

	inline glm::vec2 GetRightRadius() { return this->right_radius; }
};

struct Property
{


	glm::vec2 position;
	glm::vec2 size;
	glm::vec4 color;


};



class UI_helper
{


public:



	static GLuint GetButtonAction(Controller * ctrl,Property * m_prop);
	static int GetItemAction(Controller *ctrl, Property *m_prop);


};