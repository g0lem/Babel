#include "common.hpp"

void StatsRender::Init(GameObject *g_obj)
{
	this->button_size = glm::vec2(32, 32);
	this->button_position = glm::vec2(183, 13);
	this->size = glm::vec2(226, 213);
	this->position = glm::vec2( 50, 30);
	
	for (int i = 0; i < 6; i++)
	{
		g_obj->StatPositions->push_back(StatText("", glm::vec2(20, 20*i), 20));
	}

	LoadSprites();
	LoadButtons();

	this->mover = new UI_mover();
}

void StatsRender::LoadSprites()
{
	this->skins = new Sprite();


	char **textures = new char*[2];


	textures[0] = "stats.png";
	textures[1] = "xbutton.png";

	skins->Load(2, "data/UI/", textures);
}

void StatsRender::LoadButtons()
{


	this->exit = new Button*[1];



	Property * m_prop = new Property();
	m_prop->size = glm::vec2(32, 32);
	m_prop->color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

	exit[0] = new Button(m_prop);


}

void StatsRender::RenderStaticItems(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj)
{
	u_data->SetAmbientLight(glm::vec3(1.f, 1.f, 1.f));

	u_data->ApplyMatrix(Translation(position)*Scale(size));
	this->skins->Render(0);

}

void StatsRender::Update(GameObject *g_obj)
{
	
	//char *temp = new char[256], *ito = new char[256];

	//strcpy(temp, "HP: ");
	//
	//	g_obj->StatPositions->at(0).text = ;
	//	g_obj->StatPositions->at(1).text = ;
	//	g_obj->StatPositions->at(2).text = ;
	//	g_obj->StatPositions->at(3).text = ;
	//	g_obj->StatPositions->at(4).text = ;
	//	g_obj->StatPositions->at(5).text = ;


	this->exit[0]->GetProperties()->position = this->position + glm::vec2(182, 12);
}

void StatsRender::Render(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj)
{



	this->MoveObject(ctrl, g_obj);
	this->AddIntersect(g_obj);



	RenderStaticItems(ctrl, u_data, g_obj);
	this->Update(g_obj);


	g_obj->GetUIState()->GetStatState()->GetButtonState()[0] = UI_helper::GetButtonAction(ctrl, this->exit[0]->GetProperties());
	this->exit[0]->Render(ctrl, u_data, this->skins, 1, g_obj->GetUIState()->GetStatState()->GetButtonState()[0]);



}

void StatsRender::AddIntersect(GameObject *g_obj)
{
	if (g_obj->GetUIState()->GetInterHandler()->GetInters()[0][8] == NULL)
	{
		Golem *g = new Golem();

		g->id = RECT;
		g->position = this->position;
		g->size = this->size;


		g_obj->GetUIState()->GetInterHandler()->GetInters()[0][8] = g;
	}



}

void StatsRender::MoveObject(Controller *ctrl, GameObject *g_obj)
{



	glm::vec2 position = this->mover->GetTranslation(ctrl, this->position, this->size);


	if (glm::distance(position, this->position) > 0)
	{
		delete g_obj->GetUIState()->GetInterHandler()->GetInters()[0][8];
		g_obj->GetUIState()->GetInterHandler()->GetInters()[0][8] = NULL;

		this->position = position;
	}



}