#pragma once



class FloatingText
{

	EffectsHandler * m_effects;
	int k = 0;

	int currentSize = 1;

public:
	

	inline FloatingText(){ this->Init(); }

	void Init();




	inline void Update(GameObject * g_obj)
	{

		std::vector<fText*>* t_list = g_obj->GetTextObject()->GetTexts();


		for (int i = 0; i < t_list->size(); i++)
		{
			if (t_list->at(i)->color.a < 0.5f){
			    t_list->erase(t_list->begin() + i);
				currentSize--;
			}
		}



	}
	
	inline void HandleText(int i, GameObject * g_obj, TextRender * tr,Controller * ctrl){
		

		std::vector<fText*>* text_vec = g_obj->GetTextObject()->GetTexts();



		if (i < text_vec->size())
		{
				m_effects->TextFade(ctrl,
				text_vec->at(i)->font,
				text_vec->at(i)->text,
				tr,
				text_vec->at(i)->position,
				text_vec->at(i)->color,
				text_vec->at(i)->size,
				text_vec->at(i)->direction,
				text_vec->at(i)->speed);

		}
	}




	inline void Render(GameObject * g_obj, TextRender * tr, Controller * ctrl)
	{





		std::vector<fText*>* t_list = g_obj->GetTextObject()->GetTexts();


		if (t_list->size() > 0)
		{

			HandleText(0, g_obj, tr, ctrl);

			if (t_list->at(0)->color.a < 0.2f)
				t_list->erase(t_list->begin());

		}
	}


};

