//Checked 1





#include <common.hpp>


void FontManager::Init()
{


	this->BindCreate("data/shaders/text_vert.txt", "data/shaders/text_frag.txt");


	this->font = new Font();

	this->font->Create("data/fonts/choco.ttf", 48);



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

	//TextRender::SetColor(0.5, 0.5, 0.5);
	this->font->Print("text", ctrl->GetWindowSize().x / 2, ctrl->GetWindowSize().y / 2, 72);
	//printf("%.2f\n", ctrl->returnFps());


	this->UnbindRun();


}