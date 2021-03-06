#include <common.hpp>





void Combat::Init()
{

	t_clock = new sf::Clock();

}



void Combat::SetPlayerTarget(Player * player, EnemyManager * enemies)
{




	player->SetTarget(NO_TARGET);


	for (GLuint i = 0; i < enemies->GetEnemiesPointer()->size(); i++)
	{




		if (glm::distance(player->GetPAttributes()->position, enemies->GetEnemiesPointer()[0][i]->GetPAttributes()->position) < MIN_DISTANCE)
		{


			if (player->GetTarget() == NO_TARGET)
				player->SetTarget(i);



			if (player->GetActionHandler()->GetAction() == ATTACKING)
			{
				player->GetDirection()->Compute(DIR_TYPE_4, player->GetPAttributes()->position,
					enemies->GetEnemiesPointer()[0][i]->GetPAttributes()->target);

			}


			break;



		}
		//else if (glm::distance(player->GetPAttributes()->position + glm::vec2(1, 0), enemies->GetEnemiesPointer()[0][i]->GetPAttributes()->position + glm::vec2(1, 0)) < MIN_DISTANCE || glm::distance(player->GetPAttributes()->position + glm::vec2(0, 1), enemies->GetEnemiesPointer()[0][i]->GetPAttributes()->position + glm::vec2(0, 1)) < MIN_DISTANCE)
		//{

		//	if (player->GetTarget() == NO_TARGET)
		//		player->SetTarget(i);



		//	if (player->GetActionHandler()->GetAction() == ATTACKING)
		//	{
		//		player->GetDirection()->Compute(DIR_TYPE_4, player->GetPAttributes()->position,
		//			enemies->GetEnemiesPointer()[0][i]->GetPAttributes()->target);

		//	}


		//	break;
		//}


	}




}



void Combat::PlayerAttack(SplashScreen *sc, SoundManager * sm, Controller * ctrl, GameObject * g_obj, Player * player, EnemyManager *enemies, Map *current_map, int type)
{

	Item *item;



	SpellManager *spell = g_obj->GetSpellManager();


	if (player->GetTarget() > NO_TARGET &&
		player->GetActionHandler()->GetAction() == ATTACKING &&
		player->GetActionHandler()->HasReachedLifetime(TIME_FOR_ACTION) && spell->SpellActive() == false)
	{





		g_obj->GetTurnSystem()->ComputeAttack(player->GetItems()[ITEM_SLOT_WEAPON]->attack_speed);
		player->GetActionHandler()->SetAction(NO_ACTION);
		player->GetActionHandler()->Stop();



		{

			PhysicalAttributes * e_attr = enemies->GetEnemiesPointer()[0][player->GetTarget()]->GetPAttributes();




			GLint hp = enemies->GetEnemiesPointer()[0][player->GetTarget()]->GetStats()->GetHp()->hp;
			GLint dmg = enemies->GetEnemiesPointer()[0][player->GetTarget()]->GetStats()->GetHp()->Damage(player->GetItems()[ITEM_SLOT_WEAPON]->attack + player->GetStats()->base_attack);


			int rand_item_number;
			if (dmg >= hp)
			{
				player->GetStats()->GetXp()->xp++;

				rand_item_number = enemies->GetEnemiesPointer()[0][player->GetTarget()]->items[Dice::Get((GLuint*)(enemies->GetEnemiesPointer()[0][player->GetTarget()]->chances), (GLuint)(enemies->GetEnemiesPointer()[0][player->GetTarget()]->num_drop), 100)];

				if (rand_item_number != EnemyData::item_types::Nothing)
				{

					item = g_obj->GetItemList()->GetList()[rand_item_number];
					g_obj->GetItemList()->AddDroppedItem((int)(enemies->GetEnemiesPointer()[0][player->GetTarget()]->GetPAttributes()->position.x), (int)(enemies->GetEnemiesPointer()[0][player->GetTarget()]->GetPAttributes()->position.y), item);
				}
				enemies->GetEnemiesPointer()[0][player->GetTarget()]->GetStats()->GetHp()->Damage(player->GetItems()[ITEM_SLOT_WEAPON]->attack);
				player->GetEventHandler()->Init(current_map, g_obj);

				if (enemies->GetEnemiesPointer()[0][player->GetTarget()]->scale == 2)
				{
					ctrl->freeze = true;
				}
			}


			if (player->GetStats()->GetXp()->xp >= player->GetStats()->GetXp()->max_xp)
			{

				player->GetStats()->base_attack += 2;
				player->GetStats()->GetXp()->lvl++;
				int hp = player->GetStats()->GetHp()->hp
					/ player->GetStats()->GetHp()->max_hp;
				int mhp = player->GetStats()->GetXp()->lvl * 2;


				player->GetStats()->GetHp()->Buff(hp * mhp, mhp);
				player->GetStats()->GetXp()->xp = 0;
				player->GetStats()->GetXp()->max_xp = player->GetStats()->GetXp()->lvl * 4;
			}

			enemies->GetEnemiesPointer()[0][player->GetTarget()]->GetStats()->aggressive = true;


			glm::vec2 text_pos = e_attr->position *
				e_attr->scale +
				g_obj->GetScroller()->GetOffset();



			text_pos.y -= 10;
			text_pos.x -= 10;

			char *buffer = new char[256];
			_itoa(dmg, buffer, 10);
			strcat(buffer, " DMG");

			g_obj->GetTextObject()->Add(g_obj->GetFontList()->GetFont(),
				buffer,
				text_pos,
				glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), 15,
				UP,
				50);



			sm->PlaySound(ATTACK2);


		}
	}
	else
	{
		for (int i = 0; i < spell->GetBuffer()->size(); i++)
		{
			int nextSpell = false;

			if (spell->GetSpell(i)->active == false)
			{
				for (int j = 0; j < enemies->GetEnemiesPointer()->size() && nextSpell == false && spell->GetSpell(i)->state == true; j++)
				{



					if ((glm::ivec2)enemies->GetEnemiesPointer()[0][j]->GetPAttributes()->position == spell->GetSpell(i)->rPosition || Contains::Rectangle((glm::vec2)spell->GetSpell(i)->rPosition, enemies->GetEnemiesPointer()[0][j]->GetPAttributes()->position, glm::vec2(enemies->GetEnemiesPointer()[0][j]->scale, enemies->GetEnemiesPointer()[0][j]->scale)))
					{

						nextSpell == true;

						GLint hp = enemies->GetEnemiesPointer()[0][j]->GetStats()->GetHp()->hp;
						GLint dmg = enemies->GetEnemiesPointer()[0][j]->GetStats()->GetHp()->Damage(glm::vec2(spell->GetSpell(i)->damage, spell->GetSpell(i)->damage));

						PhysicalAttributes * e_attr = enemies->GetEnemiesPointer()[0][j]->GetPAttributes();

						int rand_item_number;
						if (dmg >= hp)
						{
							player->GetStats()->GetXp()->xp++;

							rand_item_number = enemies->GetEnemiesPointer()[0][j]->items[Dice::Get((GLuint*)(enemies->GetEnemiesPointer()[0][j]->chances), (GLuint)(enemies->GetEnemiesPointer()[0][j]->num_drop), 100)];

							if (rand_item_number != EnemyData::item_types::Nothing)
							{

								item = g_obj->GetItemList()->GetList()[rand_item_number];
								g_obj->GetItemList()->AddDroppedItem((int)(enemies->GetEnemiesPointer()[0][j]->GetPAttributes()->position.x), (int)(enemies->GetEnemiesPointer()[0][j]->GetPAttributes()->position.y), item);
							}

							enemies->GetEnemiesPointer()[0][j]->GetStats()->GetHp()->Damage(glm::vec2(spell->GetSpell(i)->damage, spell->GetSpell(i)->damage));
							player->GetEventHandler()->Init(current_map, g_obj);

							if (enemies->GetEnemiesPointer()[0][j]->scale == 2)
							{
								ctrl->freeze = true;
							}
						}

						if (player->GetStats()->GetXp()->xp >= player->GetStats()->GetXp()->max_xp)
						{
							player->GetStats()->base_attack += 2;
							player->GetStats()->GetXp()->lvl++;

							int mhp = player->GetStats()->GetXp()->lvl * 2;


							player->GetStats()->GetHp()->Buff(mhp);
							player->GetStats()->GetHp()->hp = player->GetStats()->GetHp()->max_hp;
							player->GetStats()->GetXp()->xp = 0;
							player->GetStats()->GetXp()->max_xp = player->GetStats()->GetXp()->lvl * 4;
						}

						enemies->GetEnemiesPointer()[0][j]->GetStats()->aggressive = true;


						glm::vec2 text_pos = e_attr->position *
							glm::vec2(32, 32)  +
							g_obj->GetScroller()->GetOffset();



						text_pos.y -= 10;
						text_pos.x -= 10;

						if (enemies->GetEnemiesPointer()[0][j]->scale == 2)
						{

						}
						

						char *buffer = new char[256];
						_itoa(dmg, buffer, 10);
						strcat(buffer, " DMG");


						if (enemies->GetEnemiesPointer()[0][j]->scale == 2)
						{
							text_pos.y -= 10;

							g_obj->GetTextObject()->Add(g_obj->GetFontList()->GetFont(),
								buffer,
								text_pos,
								glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), 35,
								UP,
								50);
						}
						else{
							g_obj->GetTextObject()->Add(g_obj->GetFontList()->GetFont(),
								buffer,
								text_pos,
								glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), 20,
								UP,
								50);
						}
						spell->GetSpell(i)->state = false;

					}

					g_obj->GetTurnSystem()->ComputeAttack(-1.f);
					player->GetActionHandler()->SetAction(NO_ACTION);
					player->GetActionHandler()->Stop();
				}
			}
		}
	}




}




void Combat::CheckPlayerMoveAbility(Player * player, EnemyManager * enemies)
{


	GLboolean advance = true;


	for (GLuint i = 0; i < enemies->GetEnemiesPointer()->size(); i++)
	{


		if (glm::distance(player->GetPAttributes()->position, enemies->GetEnemiesPointer()->at(i)->GetPAttributes()->position) < 4.0f)
		{
			advance = false;
			break;
		}

	}


	player->SetMoveAbility(advance);



}




void Combat::PlayerRelated(SplashScreen *sc, SoundManager * sm, Controller *ctrl, GameObject * g_obj, Player * player, EnemyManager * enemies, Map * map, int type)
{

	if (player->GetTarget() == NO_TARGET)
	{
		this->CheckPlayerMoveAbility(player, enemies);
	}
	this->SetPlayerTarget(player, enemies);
	
	this->PlayerAttack(sc, sm, ctrl, g_obj, player, enemies, map, type);


}




void Combat::SortThingsOut(Player * player, EnemyManager * enemies)
{


	std::vector<Enemy*>*m_enemies = enemies->GetEnemiesPointer();



	for (GLuint i = 0; i < m_enemies->size(); i++)
	{


		for (GLuint j = 0; j < m_enemies->size(); j++)
		{


			if (glm::distance(m_enemies[0][i]->GetPAttributes()->position, player->GetPAttributes()->position) <
				glm::distance(m_enemies[0][j]->GetPAttributes()->position, player->GetPAttributes()->position))
				std::swap(m_enemies[0][i], m_enemies[0][j]);


		}


	}




}



void Combat::SetEnemyTarget(Player * player, EnemyManager * enemies)
{




	for (GLuint i = 0; i < enemies->GetEnemiesPointer()->size(); i++)
	{


		enemies->GetEnemiesPointer()[0][i]->SetTarget(NO_TARGET);


		if (glm::distance(player->GetPAttributes()->position, enemies->GetEnemiesPointer()[0][i]->GetPAttributes()->position) < MIN_DISTANCE)
			enemies->GetEnemiesPointer()[0][i]->SetTarget(0);



	}


}




void Combat::AquireEnemyTarget(Player * player, EnemyManager * enemies)
{



	for (GLuint i = 0; i < enemies->GetEnemiesPointer()->size(); i++)
	{


		Enemy * current_enemy = enemies->GetEnemiesPointer()[0][i];



		if (glm::distance(player->GetPAttributes()->position, current_enemy->GetPAttributes()->position) < MIN_AQUIRE_DISTANCE)
			current_enemy->SetTargetPosition(player->GetPAttributes()->target);
		if (glm::distance(player->GetPAttributes()->position, current_enemy->GetPAttributes()->position) > 2.0f * MIN_AQUIRE_DISTANCE)
			current_enemy->SetTargetPosition(player->GetPAttributes()->target);




	}




}


int nein = 0;

void Combat::EnemyAttack(SoundManager *sm, Controller * ctrl, GameObject * g_obj, Player * player, EnemyManager *enemies, int type)
{

	SpellManager *spell = g_obj->GetSpellManager();
	for (GLuint i = 0; i < enemies->GetEnemiesPointer()->size(); i++)
	{


		Enemy * current_enemy = enemies->GetEnemiesPointer()[0][i];


		if (current_enemy->GetTarget() > NO_TARGET && current_enemy->GetActionHandler()->IsStopped())
		{



			if (current_enemy->GetTurnSystem()->GetTurns() >= 1.0f / current_enemy->GetStats()->base_attack_speed && current_enemy->GetStats()->aggressive == true)
			{


				current_enemy->GetDirection()->Compute(DIR_TYPE_4, current_enemy->GetPAttributes()->position, current_enemy->GetTargetPosition());
				current_enemy->GetActionHandler()->SetAction(ATTACKING);
				current_enemy->GetActionHandler()->Start();


			}

			


		}
		else
		{
			if (current_enemy->ranged == true && (current_enemy->GetTurnSystem()->GetTurns() >= 1.0f && current_enemy->GetStats()->aggressive == true) && nein == 0)
			{


				int t_dir = -1;

				if ((player->GetPAttributes()->position.x == current_enemy->GetPAttributes()->position.x && player->GetPAttributes()->position.y - current_enemy->GetPAttributes()->position.y < 10) && player->GetPAttributes()->position.y > current_enemy->GetPAttributes()->position.y)
					t_dir = DOWN;
				else if (player->GetPAttributes()->position.y == current_enemy->GetPAttributes()->position.y && player->GetPAttributes()->position.x - current_enemy->GetPAttributes()->position.x < 10 && player->GetPAttributes()->position.x > current_enemy->GetPAttributes()->position.x)
					t_dir = RIGHT;
				else if (player->GetPAttributes()->position.x == current_enemy->GetPAttributes()->position.x &&	current_enemy->GetPAttributes()->position.y - player->GetPAttributes()->position.y < 10 && player->GetPAttributes()->position.y < current_enemy->GetPAttributes()->position.y)
					t_dir = UP;
				else if (player->GetPAttributes()->position.y == current_enemy->GetPAttributes()->position.y &&  current_enemy->GetPAttributes()->position.x - player->GetPAttributes()->position.x < 10 && player->GetPAttributes()->position.x < current_enemy->GetPAttributes()->position.x)
					t_dir = LEFT;
				else if ((player->GetPAttributes()->position.x == current_enemy->GetPAttributes()->position.x + (float)(current_enemy->scale - 1) && player->GetPAttributes()->position.y - current_enemy->GetPAttributes()->position.y < 10) && player->GetPAttributes()->position.y > current_enemy->GetPAttributes()->position.y)
					t_dir = DOWN;
				else if (player->GetPAttributes()->position.y  == current_enemy->GetPAttributes()->position.y + (float)(current_enemy->scale - 1) && player->GetPAttributes()->position.x - current_enemy->GetPAttributes()->position.x < 10 && player->GetPAttributes()->position.x > current_enemy->GetPAttributes()->position.x)
					t_dir = RIGHT;
				else if (player->GetPAttributes()->position.x == current_enemy->GetPAttributes()->position.x + (float)(current_enemy->scale - 1) && current_enemy->GetPAttributes()->position.y - player->GetPAttributes()->position.y < 10 && player->GetPAttributes()->position.y < current_enemy->GetPAttributes()->position.y)
					t_dir = UP;
				else if (player->GetPAttributes()->position.y  == current_enemy->GetPAttributes()->position.y + (float)(current_enemy->scale - 1) && current_enemy->GetPAttributes()->position.x - player->GetPAttributes()->position.x < 10 && player->GetPAttributes()->position.x < current_enemy->GetPAttributes()->position.x)
					t_dir = LEFT;

				if (t_dir > -1)
				{
					current_enemy->GetDirection()->last_dir = t_dir;
					current_enemy->GetActionHandler()->SetAction(ATTACKING);
					current_enemy->GetActionHandler()->Start();
					nein = 1;



					if (enemies->GetEnemiesPointer()[0][i]->scale == 1 && enemies->GetEnemiesPointer()[0][i]->ranged == true)
					{
						g_obj->GetSpellManager()->Add(new Spell(FIREBALL, 5, (current_enemy->GetPAttributes()->position + glm::vec2(0, 0))* current_enemy->GetPAttributes()->scale  + g_obj->GetScroller()->GetOffset(),
							player->GetPAttributes()->position, g_obj->GetScroller()->GetOffset(), current_enemy->GetPAttributes()->scale,
							current_enemy->scale,
							5.f, 0));
						g_obj->GetSpellManager()->Add(new Spell(FIREBALL, 5, (current_enemy->GetPAttributes()->position+glm::vec2(0, 0)) * current_enemy->GetPAttributes()->scale  + g_obj->GetScroller()->GetOffset(),
							player->GetPAttributes()->position, g_obj->GetScroller()->GetOffset(), current_enemy->GetPAttributes()->scale,
							current_enemy->scale,
							5.f, 1));
						g_obj->GetSpellManager()->Add(new Spell(FIREBALL, 5, (current_enemy->GetPAttributes()->position +glm::vec2(0, 0))* current_enemy->GetPAttributes()->scale  + g_obj->GetScroller()->GetOffset(),
							player->GetPAttributes()->position, g_obj->GetScroller()->GetOffset(), current_enemy->GetPAttributes()->scale,
							current_enemy->scale,
							5.f, 2));
						g_obj->GetSpellManager()->Add(new Spell(FIREBALL, 5, (current_enemy->GetPAttributes()->position + glm::vec2(0, 0))* current_enemy->GetPAttributes()->scale  + g_obj->GetScroller()->GetOffset(),
							player->GetPAttributes()->position, g_obj->GetScroller()->GetOffset(), current_enemy->GetPAttributes()->scale,
							current_enemy->scale,
							5.f, 3));
					}
					else if (t_dir == RIGHT)
						g_obj->GetSpellManager()->Add(new Spell(FIREBALL, 10, (current_enemy->GetPAttributes()->position + glm::vec2(1, 0)*(float)(current_enemy->scale - 1)) * glm::vec2(32, 32) + g_obj->GetScroller()->GetOffset(),
						player->GetPAttributes()->position, g_obj->GetScroller()->GetOffset(), current_enemy->GetPAttributes()->scale,
						current_enemy->scale,
						5.f, t_dir));
					else if (t_dir == DOWN)
						g_obj->GetSpellManager()->Add(new Spell(FIREBALL, 10, (current_enemy->GetPAttributes()->position + glm::vec2(0, 1)*(float)(current_enemy->scale - 1)) * glm::vec2(32, 32) + g_obj->GetScroller()->GetOffset(),
						player->GetPAttributes()->position, g_obj->GetScroller()->GetOffset(), current_enemy->GetPAttributes()->scale,
						current_enemy->scale,
						5.f, t_dir));
					else if (t_dir == UP || t_dir == LEFT)
						g_obj->GetSpellManager()->Add(new Spell(FIREBALL, 10, current_enemy->GetPAttributes()->position * current_enemy->GetPAttributes()->scale / 2.f + g_obj->GetScroller()->GetOffset(),
						player->GetPAttributes()->position, g_obj->GetScroller()->GetOffset(), current_enemy->GetPAttributes()->scale,
						current_enemy->scale,
						5.f, t_dir));
				}


			}
		}



		if (current_enemy->GetActionHandler()->GetAction() == ATTACKING &&
			current_enemy->GetActionHandler()->HasReachedLifetime(TIME_FOR_ACTION) && current_enemy->ranged == false)
		{



			current_enemy->GetTurnSystem()->ComputeAttack(-current_enemy->GetStats()->base_attack_speed);
			current_enemy->GetActionHandler()->SetAction(NO_ACTION);
			current_enemy->GetActionHandler()->Stop();




			PhysicalAttributes * e_attr = player->GetPAttributes();
			glm::vec2 text_pos = e_attr->position *
				e_attr->scale +
				g_obj->GetScroller()->GetOffset();
			text_pos.y = ctrl->GetWindowHeight() - text_pos.y;
			text_pos.x -= 4;

			int dmg;

			if (current_enemy->GetStats()->base_attack.x > g_obj->GetItemList()->armor->armor)
			{
				dmg = player->GetStats()->GetHp()->Damage(current_enemy->GetStats()->base_attack - g_obj->GetItemList()->armor->armor);
			}
			else
			{
				dmg = player->GetStats()->GetHp()->Damage(glm::vec2(0, 0));
			}


			char *buffer = new char[256];
			_itoa(dmg, buffer, 10);
			strcat(buffer, " DMG");
			if (type == 0)
				sm->PlaySound(SCORPIONATTACK);
				if (type == 1)
					sm->PlaySound(HYDRAATTACK);
					if (type == 2)
						sm->PlaySound(HYDRAATTACK);


						g_obj->GetTextObject()->Add(g_obj->GetFontList()->GetFont(),
						buffer,
						text_pos,
						glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), 20,
						UP,
						50);



		}

		for (int i = 0; i < spell->GetBuffer()->size(); i++)
		{
			int nextSpell = false;

			if (spell->GetSpell(i)->active == false)
			{
				for (int j = 0; j < enemies->GetEnemiesPointer()->size() && nextSpell == false && spell->GetSpell(i)->state == true; j++)
				{

					//if (Contains::Rectangle((glm::vec2)spell->GetSpell(i)->rPosition, player->GetPAttributes()->position, (float)current_enemy->scale*glm::vec2(32, 32)))
					if ((glm::ivec2)player->GetPAttributes()->position == spell->GetSpell(i)->rPosition)
					{
						nextSpell = true;

						if (current_enemy->GetActionHandler()->GetAction() == ATTACKING && 
							current_enemy->ranged == true)
						{

							t_clock->restart();

							current_enemy->GetTurnSystem()->ComputeAttack(-spell->GetSpell(i)->speed);
							current_enemy->GetActionHandler()->SetAction(NO_ACTION);
							current_enemy->GetActionHandler()->Stop();

							nein = 0;

							int dmg = player->GetStats()->GetHp()->Damage(glm::vec2(spell->GetSpell(i)->damage, spell->GetSpell(i)->damage));

							PhysicalAttributes * e_attr = player->GetPAttributes();


							glm::vec2 text_pos = e_attr->position *
								e_attr->scale +
								g_obj->GetScroller()->GetOffset();




							text_pos.y -= 10;
							text_pos.x -= 4;

							char *buffer = new char[256];
							_itoa(dmg, buffer, 10);
							strcat(buffer, " DMG");

							g_obj->GetTextObject()->Add(g_obj->GetFontList()->GetFont(),
								buffer,
								text_pos,
								glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), 20,
								UP,
								50);

							spell->GetSpell(i)->state = false;
						}

					}
					else
					{
						if (spell->GetSpell(i)->active == false)
						{
							current_enemy->GetTurnSystem()->ComputeAttack(-1);
						}

						current_enemy->GetActionHandler()->SetAction(NO_ACTION);
						current_enemy->GetActionHandler()->Stop();

						t_clock->restart();
						nein = 0;
					}
				}
			}
		}
		if (spell->GetBuffer()->size() == 0 && current_enemy->ranged == true)
		{
			current_enemy->GetActionHandler()->SetAction(NO_ACTION);
			current_enemy->GetActionHandler()->Stop();

			t_clock->restart();
			nein = 0;
		}

	}


	


}





void Combat::EnemyMovement(Controller * ctrl, GameObject * g_obj, Player * player, EnemyManager * enemies, Map* current_map, int type)
{




	if (player->GetPAttributes()->HasReachedTarget() &&
		player->GetActionHandler()->GetAction() != ATTACKING &&
		enemies->GetEnemiesPointer()->size() > 0)
		enemies->GetEnemiesPointer()[0][0]->GetTurnLogic()->Advance();



	for (GLuint i = 0; i < enemies->GetEnemiesPointer()->size(); i++)
	{


		Enemy * enemy = enemies->GetEnemiesPointer()[0][i];
		PhysicalAttributes * attr = enemy->GetPAttributes();
		TurnSystem * turns = enemy->GetTurnSystem();
		AutoPath * a_path = enemy->GetAutoPath();
		Stats * stats = enemy->GetStats();
		ActionHandler * a_handler = enemy->GetActionHandler();

		EventHandler::DestroyDoor(attr->position, current_map, g_obj);


		if (g_obj->boss_deal_damage != 0 && enemy->scale != 1)
		{
			enemy->GetStats()->GetHp()->Damage(glm::vec2(g_obj->boss_deal_damage, g_obj->boss_deal_damage));
			g_obj->boss_deal_damage = 0;
		}



		if (!enemy->GetTurnLogic()->IsUseless() && enemy->GetStats()->aggressive == true)
		{

			if (attr->position == attr->target &&
				enemy->GetTargetPosition() != vec2_0 &&
				turns->GetTurns() >= 1.0f / stats->base_movement_speed
				&& a_handler->IsStopped())
			{




				a_path->Start(g_obj, enemy->GetPAttributes()->position, enemy->GetTargetPosition(), enemy->GetStats()->path_type);


				if (enemy->scale == 1)
				 {
					a_path->Start(g_obj, enemy->GetPAttributes()->position, enemy->GetTargetPosition(), enemy->GetStats()->path_type);
				 }
				else
			    {
					a_path->Start(g_obj, enemy->GetPAttributes()->position, enemy->GetTargetPosition(), enemy->GetStats()->path_type, enemy->scale);
				}

				a_path->Reset();


				int reset_position;
				for (int j = 0; j < g_obj->GetItemList()->GetTraps().size(); j++)
				{
					if (enemy->GetPAttributes()->position == g_obj->GetItemList()->GetTraps()[j]->position && g_obj->GetItemList()->GetTraps()[j]->item->id == CHAINS_ID)
					{
						enemy->GetPAttributes()->Peffects->freeze = true;
						g_obj->GetItemList()->GetTraps()[j]->item->id = CHAINS_ACTIVE_ID;
						reset_position = j;
					}
				}



				if (a_path->GetPathfinder()->GetPathFound() && enemy->GetPAttributes()->Peffects->freeze == false)
				{


					a_path->SetPath(a_path->GetPathfinder()->GetPath());
					a_path->Advance();




				}
				else
				{
					enemy->GetTurnLogic()->Reset();
					turns->Reset();
					//enemy->GetPAttributes()->Peffects->freeze = false;

				}

			}



			if (a_path->IsSet() && !a_path->FinishedWithoutLast() && turns->GetTurns() >= 1.0f / stats->base_movement_speed)
			{



				attr->target = a_path->GetStep();
				g_obj->GetCollisionMap()->AddToList(glm::ivec2(attr->target));
				g_obj->GetCollisionMap()->GetTiles()[glm::ivec2(attr->target).x][glm::ivec2(attr->target).y] = 1;


				if (a_handler->IsStopped())
				{
					a_handler->Start();
					a_handler->SetAction(MOVING);
				}


				if (a_handler->HasReachedLifetime(TIME_FOR_ACTION))
				{

					turns->ComputeMovement(-stats->base_movement_speed);
					enemy->GetTurnLogic()->Advance();

					a_handler->Stop();
					a_handler->SetAction(NO_ACTION);
				}



			}


		}
	}


}



void Combat::UpdateTurns(GameObject * g_obj, EnemyManager * enemies)
{


	for (GLuint i = 0; i < enemies->GetEnemiesPointer()->size(); i++)
		if (enemies->GetEnemiesPointer()[0][i]->GetTargetPosition() != vec2_0)
			g_obj->GetTurnSystem()->Update(enemies->GetEnemiesPointer()[0][i]->GetTurnSystem());

}





void Combat::EnemyRelated(SoundManager *sm, Controller * ctrl, GameObject * g_obj, Player * player, EnemyManager * enemies, Map * map, int type)
{



	this->UpdateTurns(g_obj, enemies);
	this->SortThingsOut(player, enemies);
	this->SetEnemyTarget(player, enemies);
	this->AquireEnemyTarget(player, enemies);
	this->EnemyMovement(ctrl, g_obj, player, enemies, map, type);
	this->EnemyAttack(sm, ctrl, g_obj, player, enemies, type);

}




void Combat::Action(SplashScreen *sc, SoundManager * sm, Controller * ctrl, GameObject * g_obj, Player * player, EnemyManager * enemies, Map * map, int type)
{



	this->PlayerRelated(sc, sm, ctrl, g_obj, player, enemies, map, type);
	this->EnemyRelated(sm, ctrl, g_obj, player, enemies, map, type);



	g_obj->GetTurnSystem()->Reset();


}






