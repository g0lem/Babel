#include <common.hpp>


void Boss::Init(EnemyData *data)
{
	this->turn_sys = new TurnSystem();
	this->m_dir = new Direction();
	this->LoadAttrib();
	this->LoadStats(data);
	this->LoadSprites(data);

	this->target_position = vec2_0;
	this->target = NO_TARGET;

	this->t_logic = new TurnLogic();
	this->a_handler = new ActionHandler();

}

void Boss::LoadSprites(EnemyData *data)
{
	this->m_sprite = data->m_sprites[0];
}
void Boss::LoadAttrib()
{
	this->p_attrib = new PhysicalAttributes();
	this->p_attrib->position = this->p_attrib->target = vec2_0;
	this->p_attrib->scale = glm::vec2(32.f, 32.f);
	this->p_attrib->speed = 10.f;
	this->p_attrib->rotation_angle = 0.f;
}

void Boss::LoadStats(EnemyData *data)
{
	this->m_stats = new Stats();
	this->m_stats->Copy(data->m_stats);
	this->SetChances(data);
}

void Boss::SetChances(EnemyData * data)
{


	this->num_drop = 9;
	this->chances = new int[this->num_drop];
	this->items = new int[this->num_drop];
	this->ranged = data->ranged;


	this->chances[0] = data->chances[0]; this->items[0] = data->items[0];
	this->chances[1] = data->chances[1]; this->items[1] = data->items[1];
	this->chances[2] = data->chances[2]; this->items[2] = data->items[2];
	this->chances[3] = data->chances[3]; this->items[3] = data->items[3];
	this->chances[4] = data->chances[4]; this->items[4] = data->items[4];
	this->chances[5] = data->chances[5]; this->items[5] = data->items[5];
	this->chances[6] = data->chances[6]; this->items[6] = data->items[6];
	this->chances[7] = data->chances[7]; this->items[7] = data->items[7];
	this->chances[8] = data->chances[8]; this->items[8] = data->items[8];

}

void Boss::SetPosition(glm::vec2 pos)
{

	this->p_attrib->position = pos;
	this->p_attrib->target = pos;

	this->m_stats->GetHp()->Buff(40);
}

void Boss::Render(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj, Map *map)
{


	u_data->ApplyMatrix(Translation(p_attrib->position * p_attrib->scale + g_obj->GetScroller()->GetOffset()) * Scale(p_attrib->scale));
	int dir = m_dir->Compute(DIR_TYPE_4, p_attrib->position, p_attrib->target);

	this->Update(g_obj, ctrl->GetFpsPointer()->Delta());

	this->RenderHPBar(u_data, g_obj);

}

void Boss::RenderHPBar(ScreenUniformData *u_data, GameObject *g_obj)
{

	if (this->m_stats->GetHp()->hp < this->m_stats->GetHp()->max_hp && this->p_attrib->visible == true)
	{
		glm::vec2 hp_factor = glm::vec2(GLfloat(this->m_stats->GetHp()->hp) / GLfloat(this->m_stats->GetHp()->max_hp), 1.0f);



		u_data->ApplyMatrix(Translation(p_attrib->position * p_attrib->scale + g_obj->GetScroller()->GetOffset()
			- glm::vec2(0, 1)*p_attrib->scale)*
			Scale(p_attrib->scale*hp_factor));



		u_data->SetAmbientLight(glm::vec3(0.0f, 1.0f, 0.0f));



		g_obj->GetMisc()->GetSprites()[0]->Render(0);



		u_data->ApplyMatrix(Translation(p_attrib->position * p_attrib->scale + g_obj->GetScroller()->GetOffset()
			- glm::vec2(0, 1)*p_attrib->scale + glm::vec2(hp_factor.x, 0.0f)*p_attrib->scale)*
			Scale(p_attrib->scale*glm::vec2(1 - hp_factor.x, 1.0f)));



		u_data->SetAmbientLight(glm::vec3(1.0f, 0.0f, 0.0f));



		g_obj->GetMisc()->GetSprites()[0]->Render(0);

	}

}