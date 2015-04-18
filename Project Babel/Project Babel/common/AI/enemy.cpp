#include <common.hpp>


void Enemy::Init(EnemyData * data)
{

	

	this->a_path = new AutoPath();
	this->turn_system = new TurnSystem();
	this->m_dir = new Direction();


	this->LoadPhysicalAttributes();
	
	this->LoadStats(data);
	this->LoadSprites(data);


	this->last_position = vec2_0;
	this->target_position = vec2_0;
	this->target = NO_TARGET;
	this->t_logic = new TurnLogic();
	this->a_handler = new ActionHandler();


}



void Enemy::Render(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj, Map *map)
{




	this->last_position = this->p_attributes->position;
	u_data->ApplyMatrix(Translation(p_attributes->position * p_attributes->scale + g_obj->GetScroller()->GetOffset())*
		Scale(p_attributes->scale));
	u_data->SetAmbientLight(color * (glm::abs(1.5f*glm::sin(glfwGetTime()*5.0f)) + 0.6f));



	GLuint dir = m_dir->Compute(DIR_TYPE_4, p_attributes->position, p_attributes->target);
	if ((!a_handler->IsStopped() && a_handler->GetAction() == MOVING) || this->animations[dir]->Started())
		this->animations[dir]->Update(GLfloat(this->animations[dir]->GetNumFrames())*7.5f, ctrl->GetFpsPointer()->Delta());
	else if ((!a_handler->IsStopped() && a_handler->GetAction() == ATTACKING) || this->animations[dir + 4]->Started())
		this->animations[dir + 4]->Update(GLfloat(this->animations[dir + 4]->GetNumFrames())*7.5f, ctrl->GetFpsPointer()->Delta());



	this->Update(g_obj, ctrl->GetFpsPointer()->Delta());



	if (a_handler->GetAction() == ATTACKING)
		this->m_sprites[dir + 4]->Render(this->animations[dir + 4]->GetIFrames());
	else
		this->m_sprites[dir]->Render(this->animations[dir]->GetIFrames());


	this->RenderMisc(u_data, g_obj);




}




void Enemy::LoadSprites(EnemyData * data)
{



	this->m_sprites = data->m_sprites;
	this->animations = new Animation*[data->num_dirs];
	for (GLuint i = 0; i < data->num_dirs; i++)
		this->animations[i] = new Animation(data->num_frames[i]);



}




void Enemy::SetRandomPosition(Map * map)
{
	

	GLboolean ok = false;

	while (!ok)
	{
		Room *room;
		room = map->GetRoomsPointer()->at(Rand(map->GetRoomsPointer()->size()));
		this->p_attributes->position = glm::vec2(Rand(room->GetOffset().x + 1, room->GetOffset().x + room->GetHeight() - 1), Rand(room->GetOffset().y + 1, room->GetOffset().y + room->GetWidth() - 1));
		//this->p_attributes->position = glm::vec2(Rand(map->GetTilemap()->GetSize().x), Rand(map->GetTilemap()->GetSize().y));
		this->p_attributes->target = this->p_attributes->position;

		

		GLint result = map->GetTilemap()->GetTiles()[GLuint(this->p_attributes->position.x)][GLuint(this->p_attributes->position.y)];


		if (result >= 0 && result < SOLID_LIMIT)
		{
			ok = true;
			
		}
		GLint r = Rand(10);
		if (r > 0 || r == 0)
		{
			color = glm::vec4(GLfloat(Rand(10)) / 10, GLfloat(Rand(10)) / 10, GLfloat(Rand(10)) / 10, 1.0f)*GLfloat(Rand(10) + 1);
			this->m_stats->GetHp()->Buff(Rand(8));
		}
		else
			color = glm::vec4(1, 1, 1, 1);

	}


}



void Enemy::LoadPhysicalAttributes()
{


	this->p_attributes = new PhysicalAttributes();
	this->p_attributes->position = this->p_attributes->target = vec2_0;
	this->p_attributes->scale = glm::vec2(32.0f,32.0f);
	this->p_attributes->speed = 10.0f;
	this->p_attributes->rotation_angle - 0.0f;


}



void Enemy::Update(GameObject * g_obj, GLfloat delta)
{



	this->p_attributes->Update(delta);
	g_obj->GetCollisionMap()->AddToList(glm::ivec2(this->p_attributes->target));
	g_obj->GetCollisionMap()->GetTiles()[GLuint(this->p_attributes->target.x)][GLuint(this->p_attributes->target.y)] = 1;

}



void Enemy::RenderMisc(ScreenUniformData * u_data, GameObject * g_obj)
{



	if (this->m_stats->GetHp()->hp < this->m_stats->GetHp()->max_hp)
	this->RenderHpBar(u_data, g_obj);



}



void Enemy::RenderHpBar(ScreenUniformData * u_data, GameObject * g_obj)
{




	glm::vec2 hp_factor = glm::vec2(GLfloat(this->m_stats->GetHp()->hp) / GLfloat(this->m_stats->GetHp()->max_hp), 1.0f);



	u_data->ApplyMatrix(Translation(p_attributes->position * p_attributes->scale + g_obj->GetScroller()->GetOffset()
		- glm::vec2(0, 1)*p_attributes->scale)*
		Scale(p_attributes->scale*hp_factor));



	u_data->SetAmbientLight(glm::vec3(0.0f, 1.0f, 0.0f));



	g_obj->GetMisc()->GetSprites()[0]->Render(0);



	u_data->ApplyMatrix(Translation(p_attributes->position * p_attributes->scale + g_obj->GetScroller()->GetOffset()
		- glm::vec2(0, 1)*p_attributes->scale + glm::vec2(hp_factor.x, 0.0f)*p_attributes->scale)*
		Scale(p_attributes->scale*glm::vec2(1 - hp_factor.x, 1.0f)));



	u_data->SetAmbientLight(glm::vec3(1.0f, 0.0f, 0.0f));



	g_obj->GetMisc()->GetSprites()[0]->Render(0);



}





void Enemy::LoadStats(EnemyData * data)
{


	this->m_stats = new Stats();
	this->m_stats->Copy(data->m_stats);

    

}









