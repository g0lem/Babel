#pragma once



class FloatingText:public TextRender
{

	EffectsHandler * m_effects;


	int currentSize = 1;

public:
	

	inline FloatingText(){ this->Init(); }

	void Init();




	inline void Update(GameObject * g_obj)
	{

		std::vector<fText*>* t_list = g_obj->GetTextObject()->GetTexts();


		for (int i = 0; i < t_list->size(); i++)
		{
			if (t_list->at(i)->alpha < 0.5f){
			    t_list->erase(t_list->begin() + i);
				currentSize--;
			}
		}



	}
	
	inline void HandleText(int i, GameObject * g_obj){
		

		std::vector<fText*>* text_vec = g_obj->GetTextObject()->GetTexts();



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




	inline void Render(GameObject * g_obj)
	{

		std::vector<fText*>* t_list = g_obj->GetTextObject()->GetTexts();


		if (t_list->size() > 0)
		{
			Update(g_obj);

			for (int i = 0; i < currentSize; i++)
			{
				HandleText(i, g_obj);

				if (t_list->at(i)->alpha < 0.5f && currentSize < t_list->size())
					currentSize++;


			}
		}

	}

};

