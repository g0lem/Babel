#pragma once



#define NONE 0
#define HOVER 1
#define PRESSED 2
#define RIGHT_CLICKED 3

struct StoryProperties
{
	glm::vec2 storybox_position;
	glm::vec2 storybox_size;

	glm::vec2 conscious_position;
	glm::vec2 conscious_size;

	glm::vec2 storylogo_position;
	glm::vec2 storylogo_size;

	glm::vec2 story_text_position;
	glm::vec2 story_text_size;

	glm::vec2 exit_position;
	glm::vec2 exit_size;

	glm::vec2 letter_size;
	glm::vec2 inventory_size;

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



	static GLuint GetButtonAction(Controller * ctrl, Property * m_prop);
	static int GetItemAction(Controller *ctrl, Property *m_prop);


};

struct ttvec
{
	glm::vec2 size;
	glm::vec2 position;
	char *string;
	int stringsize;
	glm::vec2 stringposition;
	bool status;
	int frame;
	bool renderstring;

};

#define TOOLTIP_ACTIVE 1
#define TOOLTIP_NOT_ACTIVE 0

#define MENU 1
#define INSPECT 2
#define STORY 3
#define INVENTORY 4
#define PASSTURN 5

#define WEAPON 6
#define ARMOR 7

#define INVENTORY_START 8
#define INVENTORY_STOP 24

class Tooltip
{

	Sprite *t_sprite;

	std::vector<ttvec*> *tooltips;

	int r_index;

public:


	inline Tooltip(){ this->Init(); }

	inline void Init(){
		this->tooltips = new std::vector < ttvec* >;
		this->t_sprite = new Sprite();

		char **textures = new char*[8];
		textures[0] = "menubutton.png";
		textures[1] = "menubutton.png";
		textures[2] = "menubutton.png";
		textures[3] = "menubutton.png";
		textures[4] = "menubutton.png";
		textures[5] = "weapontooltip.png";
		textures[6] = "armortooltip.png";
		textures[7] = "potiontooltip.png";

		this->t_sprite->Load(8, "data/UI/", textures);

	}

	inline std::vector<ttvec*> *GetTooltips(){ return this->tooltips; }

	inline void Add(glm::vec2 position, glm::vec2 size, char *string, int stringsize, int frame){
		ttvec *temp = new ttvec;

		temp->position = position;
		temp->size = size;
		temp->string = string;
		temp->frame = frame;
		temp->stringsize = stringsize;
		temp->status = false;
		temp->renderstring = false;

		this->tooltips->push_back(temp);
	}

	inline void UpdateStatus(int index, bool status)
	{

		this->tooltips->at(index)->status = status;

	}

	inline void UpdateSize(int index, glm::vec2 size)
	{
		this->tooltips->at(index)->size = size;
	}

	inline void UpdatePosition(int index, glm::vec2 position)
	{

		this->tooltips->at(index)->position = position + glm::vec2(15, 15);

	}

	inline void UpdateText(int index, char *text)
	{
		this->tooltips->at(index)->string = text;
	}

	inline void RenderText(GameObject *g_obj, TextRender *tr, Controller *ctrl)
	{

		int i = this->GetRenderingIndex();
		if (tooltips->at(i)->status == TOOLTIP_ACTIVE && tooltips->at(i)->renderstring == true)
		{
		tr->SetColor(1, 1, 1);
		g_obj->GetFontList()->GetFont()->Print(this->tooltips->at(i)->string ,this->tooltips->at(i)->stringposition.x, this->tooltips->at(i)->stringposition.y, this->tooltips->at(i)->stringsize);
		}

	}

	inline int GetRenderingIndex(){ return this->r_index; }


	inline void Render(Controller *ctrl, ScreenUniformData *u_data){

		for (int i = 0; i < this->tooltips->size(); i++)
			if (tooltips->at(i)->status == TOOLTIP_ACTIVE)
			{
			r_index = i;
			u_data->SetAmbientLight(glm::vec3(1.f, 1.f, 1.f));
			u_data->ApplyMatrix(Translation(tooltips->at(i)->position)*Scale(tooltips->at(i)->size));
			this->t_sprite->Render(tooltips->at(i)->frame);

			tooltips->at(i)->stringposition = glm::vec2(this->tooltips->at(i)->position.x +
				this->tooltips->at(i)->size.x / 10.f + 3.5f,
				ctrl->GetWindowHeight() - this->tooltips->at(i)->position.y - this->tooltips->at(i)->size.y * 0.75f);
			this->tooltips->at(i)->renderstring = true;
			}
			else
				this->tooltips->at(i)->renderstring = false;


	}
};