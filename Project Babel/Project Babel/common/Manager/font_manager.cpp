
#include <common.hpp>




void FontManager::Init(GameObject * g_obj)
{


	this->BindCreate("data/shaders/text_vert.txt", "data/shaders/text_frag.txt");


	g_obj->GetFontList()->Load();
	this->fText = new FloatingText();




	texture_atlas_t *atlas = texture_atlas_new(512, 512, 1);
	const char * filename = "data/fonts/Vera.ttf";
	wchar_t *text = L"IM GONNA FUCKING KILL MYSELF";
	vertex_buffer_t *buffer = vertex_buffer_new("vertex:3f,tex_coord:2f,color:4f");
	texture_font_t *font = texture_font_new_from_file(atlas, 128, filename);
	vec2 pen = { { 200, 400 } };
	vec4 black = { { 0.5, 0.5, 0.5, 1 } };

	g_obj->GetFontList()->GetFont()->add_text(buffer, font, text, &black, &pen);
	




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