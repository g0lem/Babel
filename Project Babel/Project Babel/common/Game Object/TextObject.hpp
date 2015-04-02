#pragma once





class FontList
{


	Font * f;

public:


	inline FontList(){}
	inline void Load(){ this->f = new Font(); 	this->f->Create("data/fonts/choco.ttf", 48); }


	Font*GetFont(){ return this->f; }



};




struct fText
{
	char *text;
	float alpha;
	glm::vec2 position;
	Font *font;
	float size;
	int direction;
	float speed;
};





class TextObject
{



	std::vector<fText*> *text_vec;


public:





	inline TextObject(){ this->Init(); }
	void Init();


	inline void Clean(){
		this->text_vec->clear();
	}

	inline void Add(Font *font, char *text, glm::vec2 position, float size, int direction, float speed, float alpha){
		fText *t_text = new fText();
		t_text->text = text;
		t_text->alpha = alpha;
		t_text->position = position;
		t_text->font = font;
		t_text->size = size;
		t_text->direction = direction;
		t_text->speed = speed;

		this->text_vec->push_back(t_text);
		printf("%i\n", this->text_vec->size());
	}


	inline std::vector<fText*>* GetTexts(){ return this->text_vec; }



};

