
#include <common.hpp>

void FontManager::Init(GameObject * g_obj)
{


	this->BindCreate("data/shaders/font/v3f-t2f-c4f.vert",
		"data/shaders/font/v3f-t2f-c4f.frag");


	g_obj->GetFontList()->Load();
	this->fText = new FloatingText();


	
	



	this->UnbindCreate();


}



void FontManager::Clean()
{


	TextRender::Clean();



}



void FontManager::Render(Controller * ctrl, GameObject * g_obj, Tooltip *t_tip)
{


	this->BindRun(ctrl->GetWindowWidth(), ctrl->GetWindowHeight());


	this->SetColor(1.f, 1.f, 1.f);
	g_obj->GetFontList()->GetFont()->Print("Text + test II", 200, 400, 45);
	
	





	this->fText->Render(g_obj, this, ctrl);

	this->SetColor(0.f, 0.f, 0.f);
	if (t_tip->GetTooltips()->at(t_tip->GetRenderingIndex())->renderstring == true)
		t_tip->RenderText(g_obj, ctrl);

	this->UnbindRun();


}