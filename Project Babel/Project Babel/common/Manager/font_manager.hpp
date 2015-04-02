//Checked 1




#ifndef FONT_MANAGER_HPP
#define FONT_MANAGER_HPP




class FontManager : private TextRender
{


	char text[256];


	Font *font;

	float alpha = 1.f;

	glm::vec2 position;

	FloatingText *fText;


public:

	inline FontManager(){ this->Init(); }


	inline ~FontManager(){ this->Clean(); }


	
	void Init();

	inline Font *GetFont(){ return this->font; }

	void Render(Controller * ctrl);


	void Clean();


};



#endif