#ifndef MISCELLANEOUS_HPP
#define MISCELLANEOUS_HPP




#define HP_BAR 0




class Miscellaneous
{





	Sprite ** m_sprites;


	void LoadSprites();


public:



	inline Sprite**GetSprites(){ return this->m_sprites; }


	inline Miscellaneous(){ this->Init(); }



	void Init();


};





#endif





