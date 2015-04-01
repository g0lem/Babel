#include "common.hpp"

void StoryRender::Init()
{
	storybox_position = vec2_0;
	storybox_size = glm::vec2(226, 405);

	conscious_position = glm::vec2(97, 213);
	conscious_size = glm::vec2(32, 32);

	storylogo_position = glm::vec2(50, 61);
	storylogo_size = glm::vec2(128, 128);

	story_text_position = glm::vec2(13, 13);
	story_text_size = glm::vec2(169, 31);

	exit_position = glm::vec2(182, 12);
	exit_size = glm::vec2(32, 32);

	letter_size = glm::vec2(34, 34);
	inventory_size = glm::vec2(40, 40);

	LoadSprites();

	LoadButtons();

	this->mover = new UI_mover();
}

void StoryRender::LoadSprites()
{
	this->skins = new Sprite();
	this->b_skins = new Sprite();
	this->t_skins = new Sprite();

	char **textures = new char*[4];
	char **btextures = new char*[2];
	char **ttextures = new char*[12];

	textures[0] = "storybox2.png";
	textures[1] = "consciousplaceholder.png";
	textures[2] = "storyplaceholder.png";
	textures[3] = "storyboxtoptext.png";

	btextures[0] = "inventoryslot.png";
	btextures[1] = "xbutton.png";

	ttextures[0] = "1.png";
	ttextures[1] = "2.png";
	ttextures[2] = "3.png";
	ttextures[3] = "4.png";
	ttextures[4] = "5.png";
	ttextures[5] = "6.png";
	ttextures[6] = "7.png";
	ttextures[7] = "8.png";
	ttextures[8] = "9.png";
	ttextures[9] = "10.png";
	ttextures[10] = "11.png";
	ttextures[11] = "12.png";
	ttextures[0] = "1.png";

	this->skins->Load(4, "data/UI/Story/", textures);
	this->b_skins->Load(2, "data/UI/Story/", btextures);
	this->t_skins->Load(12, "data/UI/Story/", ttextures);
}

void StoryRender::LoadButtons()
{


	this->tablets = new Button*[12];
	this->exit = new Button*[1];

	for (int i = 0; i < 12; i++)
	{

		Property * m_prop = new Property();
		m_prop->size = inventory_size;
		m_prop->color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

		tablets[i] = new Button(m_prop);


	}

	Property * m_prop = new Property();
	m_prop->size = exit_size;
	m_prop->color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

	exit[0] = new Button(m_prop);


}

void StoryRender::RenderStaticItems(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj)
{
	u_data->SetAmbientLight(glm::vec3(1.f, 1.f, 1.f));


	u_data->ApplyMatrix(Translation(this->storybox_position)*Scale(this->storybox_size));
	this->skins->Render(0);

	u_data->ApplyMatrix(Translation(this->storybox_position + this->conscious_position)*Scale(this->conscious_size));
	this->skins->Render(1);

	u_data->ApplyMatrix(Translation(this->storybox_position + this->storylogo_position)*Scale(this->storylogo_size));
	this->skins->Render(2);

	u_data->ApplyMatrix(Translation(this->storybox_position + this->story_text_position)*Scale(this->story_text_size));
	this->skins->Render(3);
}

void StoryRender::Update()
{
		for (GLuint j = 0; j < 3; j++)
		{

			for (GLuint i = 0; i < 4; i++)
			{

				this->tablets[j * 4 + i]->GetProperties()->position = this->storybox_position + glm::vec2(33, 265) + glm::vec2(i, j)*this->inventory_size;
			}
		}

		this->exit[0]->GetProperties()->position = this->storybox_position + glm::vec2(182, 11);
}

void StoryRender::Render(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj)
{

	this->MoveObject(ctrl, g_obj);

	this->AddIntersect(g_obj);

	RenderStaticItems(ctrl, u_data, g_obj);

	this->Update();

	for (int i = 0; i < 12; i++)
	{

		g_obj->GetUIState()->GetStoryState()->GetButtonState()[i] = UI_helper::GetButtonAction(ctrl, this->tablets[i]->GetProperties());

		this->tablets[i]->RenderItem(ctrl, u_data, this->b_skins, 0, g_obj->GetUIState()->GetStoryState()->GetButtonState()[i]);

		u_data->ApplyMatrix(Translation(this->tablets[i]->GetProperties()->position + glm::vec2(3, 3))*Scale(letter_size));
		this->t_skins->Render(i);
	}

	g_obj->GetUIState()->GetStoryState()->GetButtonState()[12] = UI_helper::GetButtonAction(ctrl, this->exit[0]->GetProperties());

	this->exit[0]->Render(ctrl, u_data, this->b_skins, 1, g_obj->GetUIState()->GetStoryState()->GetButtonState()[12]);
}

void StoryRender::AddIntersect(GameObject *g_obj)
{
	if (g_obj->GetUIState()->GetStoryState()->GetColID() == NOT_SET)
	{
		Golem *g = new Golem();

		g->id = RECT;
		g->position = this->storybox_position;
		g->size = this->storybox_size;


		g_obj->GetUIState()->GetInterHandler()->GetInters()->push_back(g);
		g_obj->GetUIState()->GetStoryState()->setColID(g_obj->GetUIState()->GetInterHandler()->GetInters()->size() - 1);
	}



}

void StoryRender::MoveObject(Controller *ctrl, GameObject *g_obj)
{



	glm::vec2 position = this->mover->GetTranslation(ctrl, this->storybox_position, this->storybox_size);


	if (glm::distance(position, this->storybox_position) > 0)
	{
		g_obj->GetUIState()->GetInterHandler()->GetInters()->erase(g_obj->GetUIState()->GetInterHandler()->GetInters()->begin() +
			g_obj->GetUIState()->GetStoryState()->GetColID());
		g_obj->GetUIState()->GetStoryState()->setColID(NOT_SET);

		this->storybox_position = position;
	}
}