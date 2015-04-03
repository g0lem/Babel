
#include <common.hpp>




void FontManager::Init(GameObject * g_obj)
{


	this->BindCreate("data/shaders/text_vert.txt", "data/shaders/text_frag.txt");


	g_obj->GetFontList()->Load();
	this->fText = new FloatingText();



	this->UnbindCreate();


}



void FontManager::Clean()
{


	TextRender::Clean();



}



void FontManager::Render(Controller * ctrl, GameObject * g_obj)
{


	this->BindRun(ctrl->GetWindowWidth(), ctrl->GetWindowHeight());





	this->fText->Render(g_obj, this, ctrl);





	this->UnbindRun();


}