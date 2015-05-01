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
	float stringlenght;
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

#define BORDER_SIZE 13
#define LOWER_BORDER_SIZE 12
#define BORDER_CANVAS 1

class Tooltip
{

	Sprite *t_sprite;

	std::vector<ttvec*> *tooltips;

	glm::vec2 corner;

	int r_index;

	float border_size = 13;

	float offset = 13;

public:
	inline Tooltip(){ this->Init(); }

	inline void Init(){
		this->tooltips = new std::vector < ttvec* >;
		this->t_sprite = new Sprite();

		char **textures = new char*[9];
		textures[0] = "body.png";
		textures[1] = "top.png";
		textures[2] = "bottom.png";
		textures[3] = "left.png";
		textures[4] = "right.png";
		textures[5] = "top-left.png";
		textures[6] = "top-right.png";
		textures[7] = "bottom-left.png";
		textures[8] = "bottom-right.png";

		this->corner = glm::vec2(13, 12);

		this->t_sprite->Load(9, "data/UI/Tooltips/", textures);

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

	inline void UpdateStringPosition(int index, glm::vec2 position)
	{
		this->tooltips->at(index)->stringposition = position;
	}

	inline void UpdateStringLength(int index, float lenght)
	{
		this->tooltips->at(index)->stringlenght = lenght;
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
		g_obj->GetFontList()->GetFont()->Print(this->tooltips->at(i)->string ,
			this->tooltips->at(i)->position.x + border_size/2.f - 1/2.f, ctrl->GetWindowHeight() - (this->tooltips->at(i)->position.y + this->tooltips->at(i)->stringsize - border_size/2.f),
			this->tooltips->at(i)->stringsize);
		}

	}

	inline int GetRenderingIndex(){ return this->r_index; }

	inline void RenderCorners(int i, ScreenUniformData *u_data)
	{
		u_data->SetAmbientLight(glm::vec3(1.f, 1.f, 1.f));



		u_data->ApplyMatrix(Translation(tooltips->at(i)->position + glm::vec2(0, tooltips->at(i)->stringsize))*Scale(this->corner));
		this->t_sprite->Render(7);

		u_data->ApplyMatrix(Translation(tooltips->at(i)->position)*Scale(this->corner));
		this->t_sprite->Render(5);




		u_data->ApplyMatrix(Translation(tooltips->at(i)->position + glm::vec2(tooltips->at(i)->stringlenght + corner.x + offset, 0))*Scale(this->corner));
		this->t_sprite->Render(6);

		u_data->ApplyMatrix(Translation(tooltips->at(i)->position + glm::vec2(tooltips->at(i)->stringlenght + corner.x + offset, tooltips->at(i)->stringsize))*Scale(this->corner));
		this->t_sprite->Render(8);

	}

	inline void RenderBorders(int i, ScreenUniformData *u_data)
	{
		u_data->SetAmbientLight(glm::vec3(1.f, 1.f, 1.f));

		u_data->ApplyMatrix(Translation(tooltips->at(i)->position
			+ glm::vec2(corner.x, tooltips->at(i)->stringsize)) * Scale(glm::vec2(tooltips->at(i)->stringlenght + offset, border_size - 1)));
		this->t_sprite->Render(2);

		u_data->ApplyMatrix(Translation(tooltips->at(i)->position + glm::vec2(corner.x, 0)) * Scale(glm::vec2(tooltips->at(i)->stringlenght + offset, border_size - 1)));
		this->t_sprite->Render(1);



		u_data->ApplyMatrix(Translation(tooltips->at(i)->position + glm::vec2(0, corner.y)) * Scale(glm::vec2(border_size, tooltips->at(i)->stringsize)));
		this->t_sprite->Render(3);

		u_data->ApplyMatrix(Translation(tooltips->at(i)->position + corner + glm::vec2(tooltips->at(i)->stringlenght + offset, 0)) * Scale(glm::vec2(border_size, tooltips->at(i)->stringsize)));
		this->t_sprite->Render(4);
	}

	inline void RenderBody(int i, ScreenUniformData *u_data)
	{
		u_data->SetAmbientLight(glm::vec3(1.f, 1.f, 1.f));

		u_data->ApplyMatrix(Translation(tooltips->at(i)->position)* Scale(glm::vec2(tooltips->at(i)->stringlenght + corner.x * 2 + offset, tooltips->at(i)->stringsize + corner.y)));
		this->t_sprite->Render(0);

	}

	inline void Render(Controller *ctrl, ScreenUniformData *u_data){

		for (int i = 0; i < this->tooltips->size(); i++)
			if (tooltips->at(i)->status == TOOLTIP_ACTIVE)
			{
			r_index = i;
			
			
			RenderBody(i, u_data);
			RenderBorders(i, u_data);
			RenderCorners(i, u_data);

			this->tooltips->at(i)->renderstring = true;
			}
			else
				this->tooltips->at(i)->renderstring = false;


	}
};