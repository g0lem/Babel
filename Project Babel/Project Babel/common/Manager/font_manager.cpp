
#include <common.hpp>

void FontManager::Init(GameObject * g_obj)
{
	this->BindCreate("data/shaders/text_vert.txt",
		"data/shaders/text_frag.txt");

	g_obj->GetFontList()->Load();
	this->fText = new FloatingText();
	this->p_text = new PanelText();

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

	this->fText->Render(g_obj, this, ctrl);

	this->p_text->Render(ctrl, this, g_obj);

	this->SetColor(0.f, 0.f, 0.f);
	if (t_tip->GetTooltips()->at(t_tip->GetRenderingIndex())->renderstring == true)
		t_tip->RenderText(g_obj, this, ctrl);

	this->UnbindRun();


}