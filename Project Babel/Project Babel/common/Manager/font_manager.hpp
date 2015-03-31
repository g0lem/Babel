//Checked 1




#ifndef FONT_MANAGER_HPP
#define FONT_MANAGER_HPP




class FontManager : private TextRender
{


	char text[256];


	Font *font;


public:


	inline FontManager(){ this->Init(); }


	inline ~FontManager(){ this->Clean(); }

	
	void Init();


	void Render(Controller * ctrl);


	void Clean();


};



#endif