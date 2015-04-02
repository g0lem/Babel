//Checked 1




#ifndef FONT_MANAGER_HPP
#define FONT_MANAGER_HPP




class FontManager : private TextRender
{


	char text[256];


	Font *font;

	EffectsHandler *m_effects;

	float alpha = 1.f;

	glm::vec2 position;


public:


	inline FontManager(){ this->Init(); }


	inline ~FontManager(){ this->Clean(); }

	
	void Init();


	void Render(Controller * ctrl);


	void Clean();


};



#endif