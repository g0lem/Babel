
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

	this->SetColor(0, 0, 0);

	if (g_obj->cooldown > 0){
		char * temp = new char[256], *temp2 = new char[256];
		strcpy(temp, "CD: ");
		_itoa(g_obj->cooldown, temp2, 10);
		strcat(temp, temp2);
		g_obj->GetFontList()->GetFont()->Print(temp, g_obj->spellPOS.x, g_obj->spellPOS.y + 9, 12);
	}
	this->SetColor(0.f, 0.f, 0.f);
	if (t_tip->GetTooltips()->at(t_tip->GetRenderingIndex())->renderstring == true)
		t_tip->RenderText(g_obj, this, ctrl);

	this->UnbindRun();


}