#pragma once



class SpellManager
{

	std::vector<Spell*> *m_spells;

	void Update()
	{
		for (int i = 0; i < m_spells->size(); i++)
		{
			if (this->m_spells->at(i)->state = FINISHED)
				this->m_spells->erase(this->m_spells->begin() + i);
		}
	}

public:

	SpellManager(){ this->m_spells = new std::vector < Spell* >; }




	void Add(Spell *spell)
	{
		this->m_spells->push_back(spell);
	}
	
	void Render(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj)
	{
		for (int i = 0; i < m_spells->size(); i++)
		{
			printf("test");

			if (this->m_spells->at(i)->active == true)
			{
				this->m_spells->at(i)->Operate(ctrl, u_data, g_obj);
			}
			else
			{
				this->m_spells->erase(this->m_spells->begin() + i);
			}
		}
	}


};

