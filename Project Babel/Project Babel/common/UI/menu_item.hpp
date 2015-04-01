#pragma once






class Button
{


	Property * m_prop;


public:


	inline Property * GetProperties(){ return this->m_prop; }


	inline Button(Property * m_prop){ this->Init(m_prop); }
	

	void Init(Property * m_prop);


	void Render(Controller * ctrl, ScreenUniformData * u_data, Sprite * m_sprite, GLuint frame, GLuint action);

	void RenderItem(Controller * ctrl, ScreenUniformData * u_data, Sprite * m_sprite, GLuint frame, GLuint action);

};

class InventoryItem
{

	Property *m_prop;

public:

	inline Property *GetProperties(){ return this->m_prop; }

	inline InventoryItem(Property *m_prop){ this->Init(m_prop); }

	void Init(Property * m_prop);

	void Render(Controller * ctrl, ScreenUniformData * u_data, Sprite * m_sprite, GLuint frame, GLuint action);


};


