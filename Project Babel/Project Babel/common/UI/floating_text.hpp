#pragma once

class FloatingText:public TextRender
{

	EffectsHandler * m_effects;

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

	std::vector<fText*> *text_vec;

	int currentSize = 1;

public:
	

	inline FloatingText(){ this->Init(); }

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

	std::vector<fText*> *GetTextVector(){ return this->text_vec; }

	inline void Update()
	{
		for (int i = 0; i < text_vec->size(); i++)
		{
			if (text_vec->at(i)->alpha < 0.5f){
				this->text_vec->erase(this->text_vec->begin() + i);
				currentSize--;
			}
		}



	}
	
	inline void HandleText(int i){
		
		if (i < text_vec->size())
		{
				m_effects->TextFade(text_vec->at(i)->font,
				text_vec->at(i)->text,
				this,
				text_vec->at(i)->position,
				text_vec->at(i)->size,
				text_vec->at(i)->direction,
				text_vec->at(i)->speed,
				text_vec->at(i)->alpha);

		}
	}

	inline void Render()
	{
		if (text_vec->size() > 0)
		{
			Update();

			for (int i = 0; i < currentSize; i++)
			{
				HandleText(i);

				if (text_vec->at(i)->alpha < 0.5f && currentSize < text_vec->size())
					currentSize++;


			}
		}

	}

};

