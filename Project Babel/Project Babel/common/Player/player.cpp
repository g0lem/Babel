//Checked 1





#include <common.hpp>

#define fireballdata "data/spells/fireball.png"

void Player::Load(GameObject * g_obj, Map * current_tilemap)
{

	this->items = new Item*[6];
	this->items[0] = NULL;
	this->items[1] = NULL;
	this->items[2] = NULL;
	this->items[3] = NULL;
	this->items[4] = NULL;
	this->items[5] = NULL;

	this->scroll = new Item();

	this->LoadSprites();
	this->LoadPhysicalAttributes(current_tilemap, g_obj);


	this->a_path = new AutoPath();
	this->m_dir = new Direction();
	this->m_stats = new Stats();
	this->m_stats->GetXp()->lvl = 1;
	this->h_event = new EventHandler();
	h_event->Init(current_tilemap, g_obj);
	this->t_clock = new sf::Clock();
	this->last_wanted_position = glm::vec2(0, 0);
	this->a_handler = new ActionHandler();
	this->able_to_move = false;
	created = false;
	this->LoadItems(g_obj);
	this->LoadStats(g_obj);
	this->last_pos_door = vec2_0;

	trigger = false;

}

void Player::Advance(GameObject * g_obj, Map * current_tilemap)
{


	this->LoadPhysicalAttributes(current_tilemap, g_obj);
	this->SetTarget(-1);

	this->a_path = new AutoPath();
	this->m_dir = new Direction();
	this->h_event = new EventHandler();
	h_event->Init(current_tilemap, g_obj);
	this->t_clock = new sf::Clock();
	this->last_wanted_position = glm::vec2(0, 0);
	this->a_handler = new ActionHandler();
	this->able_to_move = false;


    
	


	this->LoadItems(g_obj);
	



}





void Player::Render(SoundManager *sm, Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj, Map * current_map, Tooltip *t_tip)
{


	this->LoadItems(g_obj);

	//std::cout << this->attributes->position.x << " " << this->attributes->position.y << std::endl;



	u_data->ApplyMatrix(Translation(GridPosition(attributes->position*attributes->scale + g_obj->GetScroller()->GetOffset(), attributes->scale))*
		Scale(attributes->scale));
	u_data->SetAmbientLight(glm::vec3(1.0f, 1.0f, 1.0f));







		if (ctrl->GetKeyOnce(GLFW_KEY_SPACE) && this->target > NO_TARGET && a_handler->IsStopped())
		{

			a_handler->SetAction(ATTACKING);
			a_handler->Start();

		}




		if (attributes->HasReachedTarget() && a_handler->IsStopped())
			Move::TileMove(ctrl, g_obj, attributes->target);

		this->attributes->Update(ctrl->GetFpsPointer()->Delta());
		this->HandleAutoPath(sm, ctrl, g_obj, current_map, t_tip);





	Move::UpdateScroller(ctrl, g_obj, attributes->position, attributes->scale);




	if (this->a_handler->IsStopped() && !this->attributes->HasReachedTarget())
	{
		this->a_handler->Start();
		this->a_handler->SetAction(MOVING);
	}




		if (this->a_handler->IsStopped() && !this->walk_animation->Finished() && this->walk_animation->Started())
			this->walk_animation->Update(60.0f, ctrl->GetFpsPointer()->Delta());




		if (!this->a_handler->IsStopped() && this->a_handler->GetAction() == MOVING)
		{
			if (!this->a_handler->HasReachedLifetime(TIME_FOR_ACTION))
				this->walk_animation->Update(60.0f, ctrl->GetFpsPointer()->Delta());
			else
			{
				g_obj->GetTurnSystem()->ComputeMovement(this->m_stats->base_movement_speed);
				this->a_handler->Stop();
			}
		}

	

		int frame = m_dir->Compute(DIR_TYPE_4, attributes->position, attributes->target);
		


		if (a_handler->GetAction() != ATTACKING)
			this->m_sprite[m_dir->Compute(DIR_TYPE_4, attributes->position, attributes->target)]->Render(this->walk_animation->GetIFrames());
		else
			this->m_sprite[4]->Render(m_dir->Compute(DIR_TYPE_4, attributes->position, attributes->target));



		if (ctrl->GetKeyOnce(GLFW_KEY_1) && trigger == false && g_obj->cooldown == 0)
		{

			if (this->GetActionHandler()->GetAction() != ATTACKING && this->scroll->spell > -1)
			{


					g_obj->GetTurnSystem()->ComputeAttack(1.f);
					this->GetActionHandler()->SetAction(ATTACKING);
					this->GetActionHandler()->Stop();



					g_obj->GetSpellManager()->Add(new Spell(this->scroll->spell, this->scroll->attack.x, GridPosition(attributes->position*attributes->scale + g_obj->GetScroller()->GetOffset(), attributes->scale),
						g_obj->GetScroller()->GetOffset(), attributes->scale,
						5.f, frame, true));

					g_obj->cooldown = 8;
				
			}
		}
		else if (trigger == true && ctrl->GetKey(GLFW_KEY_1))
		{
			g_obj->GetSpellManager()->Add(new Spell(FIREBALL, 10, GridPosition(attributes->position*attributes->scale + g_obj->GetScroller()->GetOffset(), attributes->scale),
				g_obj->GetScroller()->GetOffset(), attributes->scale,
				5.f, 0, glm::vec3(0, 1.f, 1.f)));
			g_obj->GetSpellManager()->Add(new Spell(FIREBALL, 10, GridPosition(attributes->position*attributes->scale + g_obj->GetScroller()->GetOffset(), attributes->scale),
				g_obj->GetScroller()->GetOffset(), attributes->scale,
				5.f, 1, glm::vec3(0, 1.f, 1.f)));
			g_obj->GetSpellManager()->Add(new Spell(FIREBALL, 10, GridPosition(attributes->position*attributes->scale + g_obj->GetScroller()->GetOffset(), attributes->scale),
				g_obj->GetScroller()->GetOffset(), attributes->scale,
				5.f, 2, glm::vec3(0, 1.f, 1.f)));
			g_obj->GetSpellManager()->Add(new Spell(FIREBALL, 10, GridPosition(attributes->position*attributes->scale + g_obj->GetScroller()->GetOffset(), attributes->scale),
				g_obj->GetScroller()->GetOffset(), attributes->scale,
				5.f, 3, glm::vec3(0, 1.f, 1.f)));
		}
		else if (ctrl->GetKeyOnce(GLFW_KEY_END))
		{
			trigger = !trigger;
		}
		else if (g_obj->cooldown != 0)
		{
			g_obj->cooldown -= g_obj->GetTurnSystem()->GetTurns();
		}

		this->UpdateUI(g_obj);
		

}





void Player::LoadSprites()
{



	this->walk_animation = new Animation(8);



	char ** tex_str;


	tex_str = new char*[8];
	tex_str[0] = "1.png";
	tex_str[1] = "2.png";
	tex_str[2] = "3.png";
	tex_str[3] = "4.png";
	tex_str[4] = "5.png";
	tex_str[5] = "6.png";
	tex_str[6] = "7.png";
	tex_str[7] = "8.png";
	char **atk_str = new char*[4];
	atk_str[0] = "back.png";
	atk_str[1] = "front.png";
	atk_str[2] = "left.png";
	atk_str[3] = "right.png";


	this->m_sprite = new Sprite*[5];
	this->m_sprite[0] = new Sprite();
	this->m_sprite[0]->Load(8, "data/sprites/player0/back/", tex_str);
	this->m_sprite[1] = new Sprite();
	this->m_sprite[1]->Load(8, "data/sprites/player0/front/", tex_str);
	this->m_sprite[2] = new Sprite();
	this->m_sprite[2]->Load(8, "data/sprites/player0/left/", tex_str);
	this->m_sprite[3] = new Sprite();
	this->m_sprite[3]->Load(8, "data/sprites/player0/right/", tex_str);
	this->m_sprite[4] = new Sprite();
	this->m_sprite[4]->Load(4, "data/sprites/player0/attack/", atk_str);




}



void Player::LoadPhysicalAttributes(Map * current_tilemap, GameObject *g_obj)
{

	this->attributes = new PhysicalAttributes();
	this->attributes->scale = glm::vec2(32.0f, 32.0f);
	
	for (int i = 0; i < current_tilemap->GetRoomsPointer()[0].size();i++)
		if (current_tilemap->GetTilemap()->GetTiles()[current_tilemap->GetRoomsPointer()[0][i]->GetInternalCenter().x][current_tilemap->GetRoomsPointer()[0][i]->GetInternalCenter().y] < SOLID_LIMIT
			&& g_obj->GetCollisionMap()->AcquirePoland()[current_tilemap->GetRoomsPointer()[0][i]->GetInternalCenter().x][current_tilemap->GetRoomsPointer()[0][i]->GetInternalCenter().y] == false)
		{
		this->attributes->position = glm::vec2(current_tilemap->GetRoomsPointer()[0][i]->GetInternalCenter());
		g_obj->GetCollisionMap()->AcquirePoland()[current_tilemap->GetRoomsPointer()[0][i]->GetInternalCenter().x][current_tilemap->GetRoomsPointer()[0][i]->GetInternalCenter().y] = true;
		}
	
	
	this->attributes->target = this->attributes->position;
	this->attributes->speed = 10.0f;
	this->attributes->rotation_angle = 0.0f;


}





void Player::LoadItems(GameObject * g_obj)
{
	
	
	if (g_obj->GetItemList()->must_load)
	{
		this->items[ITEM_SLOT_WEAPON] = g_obj->GetItemList()->weapon;
		this->items[ITEM_SLOT_ARMOR] = g_obj->GetItemList()->armor;
		this->items[ITEM_SLOT_SPELL] = g_obj->GetItemList()->scroll;
		g_obj->GetItemList()->must_load = false;
	}
	if (g_obj->GetItemList()->heal!=0)
	{
		
		if (this->GetStats()->GetHp()->hp + g_obj->GetItemList()->heal > this->GetStats()->GetHp()->max_hp)
			this->GetStats()->GetHp()->hp = this->GetStats()->GetHp()->max_hp;
		else
			this->GetStats()->GetHp()->hp += g_obj->GetItemList()->heal;
		g_obj->GetItemList()->heal = 0;
	}
	if (g_obj->GetItemList()->xp != 0)
	{

		if (this->GetStats()->GetXp()->xp + g_obj->GetItemList()->xp > this->GetStats()->GetXp()->max_xp)
			this->GetStats()->GetXp()->xp = this->GetStats()->GetXp()->max_xp;
		else
			this->GetStats()->GetXp()->xp += g_obj->GetItemList()->xp;
		g_obj->GetItemList()->xp = 0;
	}
	if (g_obj->GetItemList()->must_scroll)
	{
		this->scroll = g_obj->GetItemList()->scroll;
		g_obj->GetItemList()->must_scroll = false;
	}

}



GLboolean Player::CheckAdvance(Controller * ctrl, GameObject * g_obj)
{


	GLboolean advance = true;


		for (GLuint i = 0; i < g_obj->GetUIState()->GetInterHandler()->GetInters()->size(); i++)

		{


		Golem * g = g_obj->GetUIState()->GetInterHandler()->GetInters()[0][i];

		if (!g)
			continue;

		if (g->id == RECT)
		{

			if (Contains::Rectangle(ctrl->GetMousePosition(), g->position, g->size))
			{
				advance = false;
				break;
			}


		}

		if (g->id == CIRCLE)
		{


			if (Contains::Circle(ctrl->GetMousePosition(), g->position, g->size))
			{
				advance = false;
				break;
			}

		}

		

		}
	if (g_obj->GetUIState()->GetMenuState()->GetState() == ACTIVE)
		advance = false;




	return advance;



}


void Player::HandleAutoPath(SoundManager *sm, Controller * ctrl, GameObject * g_obj, Map *current_map, Tooltip *t_tip)
{



	if (ctrl->GetKeyOnce(GLFW_KEY_E))
	{
		h_event->TriggerEvent(attributes->position, current_map, g_obj, this->GetStats());
	}

	h_event->DoorToolTip(attributes->position, current_map, g_obj, t_tip);

	
	EventHandler::AutomaticallyOpenDoor(this->last_pos_door, current_map, g_obj, this->last_pos_door);
		EventHandler::AutomaticallyOpenDoor(attributes->position, current_map, g_obj, last_pos_door);
	

	
	

	
	if (CheckAdvance(ctrl, g_obj))
	if (ctrl->GetMouseButtonOnce(GLFW_MOUSE_BUTTON_LEFT) && this->GetActionHandler()->GetAction() != ATTACKING)
	{

		this->last_wanted_position = Move::GetMapPosition(g_obj, ctrl->GetMousePosition(), attributes->scale);
		a_path->Start(g_obj, attributes->position, last_wanted_position, PATH_PLAYER);
	
		//if (current_map->GetTilemap()->GetTiles[attributes->position.x][attributes->position.y] == TABLET_ID)
		//h_event->DisplayTablet(TABLET_ID);
	}
	
	





	if (a_path->IsSet() && !a_path->Finished())
	{


		
		this->attributes->target = a_path->GetStep();
		

		if (attributes->HasMovedATile(ctrl->GetFpsPointer()->Delta()) || attributes->HasReachedTarget())
		{
			a_path->Advance();
			/*if (sm->getSoundStatus(WALKSOUND) != 2)
				sm->PlaySound(WALKSOUND);*/
			if (!able_to_move)
			a_path->Start(g_obj, attributes->target, last_wanted_position, PATH_PLAYER);
		}



	}
	if (a_path->Finished())
		a_path->GetPathfinder()->Delete();


}



void Player::LoadStats(GameObject *g_obj)
{

	//Player Stats

	this->m_stats->GetHp()->Buff(18);
	this->m_stats->base_movement_speed = 1.0f;
	this->m_stats->base_attack = glm::vec2(3, 3);
	this->m_stats->GetXp()->max_xp = 4;
	this->m_stats->GetXp()->xp = 0;
	g_obj->playerStats = m_stats;

}




void Player::UpdateUI(GameObject * g_obj)
{
	g_obj->GetPanelState()->hp = this->m_stats->GetHp()->hp;
	g_obj->GetPanelState()->max_hp = this->m_stats->GetHp()->max_hp;
	
	g_obj->GetPanelState()->xp = this->m_stats->GetXp()->xp;
	g_obj->GetPanelState()->max_xp = this->m_stats->GetXp()->max_xp;
	g_obj->GetPanelState()->level = this->m_stats->GetXp()->lvl;

}




