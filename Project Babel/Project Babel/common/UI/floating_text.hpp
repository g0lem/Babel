#pragma once

#define MAX_TEXT 20

class FloatingText:public Aaether2D
{

	EffectsHandler * m_effects;

	struct fText
	{
		char *text;
		float alpha;
		glm::vec2 position;
		Font *font;
		int size;
		int direction;
		float speed;
	};

	std::vector<fText*> *text_vec;

public:
	

	inline FloatingText(){ this->Init(); }

	void Init();

	inline void Clean(){
		this->text_vec->clear();
	}

	inline void Add(fText *ftext){ this->text_vec->push_back(ftext); }

	std::vector<fText*> *GetTextVector(){ return this->text_vec; }
	
	inline void HandleText(){

		for (int i = 0; i < text_vec->size(); i++)
		{
		//	m_effects->TextFade(text_vec->at(i)->text, text_vec->at(i)->position, text_vec->at(i)->font,
				//text_vec->at(i)->size, text_vec->at(i)->direction, text_vec->at(i)->alpha, text_vec->at(i)->speed);

		}

	}

};

