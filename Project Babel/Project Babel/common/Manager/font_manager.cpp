//Checked 1





#include <common.hpp>


void FontManager::Init()
{


	this->BindCreate("data/shaders/text_vert.txt", "data/shaders/text_frag.txt");


	this->font = new Font();

	this->font->Create("data/fonts/choco.ttf", 48);

	this->position = glm::vec2(540.f, 350.f);
	this->alpha = 1.0f;


	this->UnbindCreate();



}



void FontManager::Clean()
{


	TextRender::Clean();

	this->font->Clean();


}

void localTextFade(Font *font, char* text, glm::vec2 &position, int size)
{
	//u_data->SetAmbientLight(glm::vec4(1.f, 1.f, 1.f, alpha));

	position.y -= 1 / 255.f;

	font->Print(text, position.x, position.y, size);
	printf("%f", position.y);
}



void FontManager::Render(Controller * ctrl)
{


	this->BindRun(ctrl->GetWindowWidth(), ctrl->GetWindowHeight());


	TextRender::SetColor(1.f, 1.f, 1.f, 1.f);
	this->m_effects->TextFade(font, "test",this, position, 32, UP, 5.f, alpha);


	this->UnbindRun();


}