
#include <common.hpp>


Font * f;



void FontManager::Init(GameObject * g_obj)
{


	this->BindCreate("data/shaders/text_vert.txt", "data/shaders/text_frag.txt");
	g_obj->GetFontList()->Load();
	this->fText = new FloatingText();

	g_obj->GetTextObject()->Add(g_obj->GetFontList()->GetFont(), "0", glm::vec2(540, 360), 32, 0, 5, 1);

	this->UnbindCreate();

	f = new Font();
	f->Create("data/fonts/choco.ttf", 40);

}



void FontManager::Clean()
{


	TextRender::Clean();



}



void FontManager::Render(Controller * ctrl, GameObject * g_obj)
{


	this->BindRun(ctrl->GetWindowWidth(), ctrl->GetWindowHeight());

	this->fText->Render(g_obj);
	f->Print("WHYYY", 200, 200, 40);

	this->UnbindRun();


}