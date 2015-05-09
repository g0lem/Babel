#include <common.hpp>



void Button::Init(Property * m_prop)
{


	this->m_prop = m_prop;



}



void Button::Render(Controller * ctrl, ScreenUniformData * u_data, Sprite * m_sprite, GLuint frame, GLuint action)
{


	u_data->ApplyMatrix(Translation(this->m_prop->position)*Scale(this->m_prop->size));


	glm::vec4 color;
	if (action == NONE)
		color = this->m_prop->color;
	else if (action == HOVER)
		color = this->m_prop->color * glm::vec4(1.5f, 1.5f, 1.5f, 1.0f);
	else if (action == PRESSED)
		color = this->m_prop->color * glm::vec4(0.7f, 0.7f, 0.7f, 1.0f);



	u_data->SetAmbientLight(color);


	m_sprite->Render(frame);


}

void Button::RenderItem(Controller * ctrl, ScreenUniformData * u_data, Sprite * m_sprite, GLuint frame, GLuint action)
{
	u_data->ApplyMatrix(Translation(this->m_prop->position)*Scale(this->m_prop->size));


	glm::vec4 color;
	if (action == NONE)
		color = this->m_prop->color;
	else if (action == HOVER)
		color = this->m_prop->color * glm::vec4(1.2f, 1.2f, 1.2f, 1.0f);
	else if (action == PRESSED)
		color = this->m_prop->color * glm::vec4(0.8f, 0.8f, 0.8f, 1.0f);



	u_data->SetAmbientLight(color);


	m_sprite->Render(frame);


}

void InventoryItem::Init(Property *m_prop)
{

	this->m_prop = m_prop;


}

void InventoryItem::Render(Controller * ctrl, ScreenUniformData * u_data, Sprite * m_sprite, GLuint frame, GLuint action)
{

	glm::vec4 color;
	if (action == NONE)
		color = this->m_prop->color;
	else if (action == HOVER)
		color = this->m_prop->color * glm::vec4(1.2f, 1.2f, 1.2f, 1.0f);



	u_data->SetAmbientLight(color);


	m_sprite->Render(frame);



}