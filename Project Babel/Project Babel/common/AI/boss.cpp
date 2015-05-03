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

	this->num_drop = data->num_drop;
	this->chances = new int[this->num_drop];
	this->items = new int[this->num_drop];
	this->ranged = data->ranged;

	for (int i = 0; i < data->num_drop; i++)
	{
		this->chances[i] = data->chances[i]; this->items[i] = data->items[i];
	}


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


void Boss::Update(GameObject * g_obj, GLfloat delta)
{



	this->p_attrib->Update(delta);
	g_obj->GetCollisionMap()->AddToList(glm::ivec2(this->p_attrib->target));
	g_obj->GetCollisionMap()->GetTiles()[GLuint(this->p_attrib->target.x)][GLuint(this->p_attrib->target.y)] = 1;

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