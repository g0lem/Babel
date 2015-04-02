//Checked 1





#include <common.hpp>


void FontManager::Init()
{


	this->BindCreate("data/shaders/text_vert.txt", "data/shaders/text_frag.txt");


	this->font = new Font();

	this->font->Create("data/fonts/choco.ttf", 48);

	this->fText = new FloatingText();

	//fText->Add(font, "0", glm::vec2(540, 360), 32, 0, 5, 1);

	this->UnbindCreate();



}



void FontManager::Clean()
{


	TextRender::Clean();

	this->font->Clean();


}



void FontManager::Render(Controller * ctrl)
{


	this->BindRun(ctrl->GetWindowWidth(), ctrl->GetWindowHeight());

	this->fText->Render();

	this->UnbindRun();


}