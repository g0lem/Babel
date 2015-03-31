#include <common.hpp>




void Miscellaneous::Init()
{


	this->LoadSprites();


}



void Miscellaneous::LoadSprites()
{


	this->m_sprites = new Sprite*[1];


	this->m_sprites[HP_BAR] = new Sprite();


    



	char ** tex_str = new char*[1];
	tex_str[0] = "hp_bar.png";


	this->m_sprites[HP_BAR]->Load(1, "data/sprites/misc/", tex_str);



}





