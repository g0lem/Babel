#pragma once



class SpellManager
{

	std::vector<Spell*> *m_spells;

	glm::vec2 offset;

public:

	SpellManager(){ this->m_spells = new std::vector < Spell* >; }




	void Add(Spell *spell)
	{
		this->m_spells->push_back(spell);
	}

	inline Spell *GetSpell(int index){ return this->m_spells->at(index); }
	inline std::vector<Spell *> *GetBuffer(){ return this->m_spells; }
	
	inline void UpdateOffset(glm::vec2 offset){
		offset = offset;
	}
	
	void Render(Controller *ctrl, ScreenUniformData *u_data, glm::vec2 offset, GLboolean **tiles)
	{
		for (int i = 0; i < m_spells->size(); i++)
		{

			if (this->m_spells->at(i)->active == true && this->m_spells->at(i)->state == true)
			{
				this->m_spells->at(i)->Operate(ctrl, u_data, offset, tiles);
			}
			else
			{

				this->m_spells->erase(this->m_spells->begin() + i);
			}
		}
	}


};

