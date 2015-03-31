#include <common.hpp>





void Combat::Init()
{





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



			if (player->GetAttackingState())
			{
				player->GetDirection()->Compute(DIR_TYPE_4, player->GetPAttributes()->position,
					enemies->GetEnemiesPointer()[0][i]->GetPAttributes()->target);

			}


			break;



		}


	}




}

  

void Combat::PlayerAttack(GameObject * g_obj, Player * player, EnemyManager *enemies)
{



	if (player->GetTarget() > NO_TARGET && player->GetAttackingState())
	{




		enemies->GetEnemiesPointer()[0][player->GetTarget()]->GetStats()->GetHp()->Damage(player->GetItems()[ITEM_SLOT_WEAPON]->attack);
		player->SetAttackingState(false);
		g_obj->GetTurnSystem()->ComputeAttack(player->GetItems()[ITEM_SLOT_WEAPON]->attack_speed);




	}




}




void Combat::PlayerRelated(GameObject * g_obj, Player * player, EnemyManager * enemies, Map * map)
{


	this->SetPlayerTarget(player, enemies);
	this->PlayerAttack(g_obj, player, enemies);



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
		{
			current_enemy->SetTargetPosition(player->GetPAttributes()->target);
			player->GetEnemiesNear()->Add();
		}
		else
		{
			current_enemy->SetTargetPosition(vec2_0);
			player->GetEnemiesNear()->Remove();
		}




	}




}




void Combat::EnemyAttack(GameObject * g_obj, Player * player, EnemyManager *enemies)
{


	for (GLuint i = 0; i < enemies->GetEnemiesPointer()->size(); i++)
	{


		Enemy * current_enemy = enemies->GetEnemiesPointer()[0][i];


		if (current_enemy->GetTarget() > NO_TARGET)
		{


			while (current_enemy->GetTurnSystem()->GetTurns() >= 1.0f/current_enemy->GetStats()->base_attack_speed)
			{


				current_enemy->GetDirection()->Compute(DIR_TYPE_4, current_enemy->GetPAttributes()->position, current_enemy->GetTargetPosition());
				player->GetStats()->GetHp()->Damage(current_enemy->GetStats()->base_attack);
				current_enemy->GetTurnSystem()->ComputeAttack(-current_enemy->GetStats()->base_attack_speed);

			}


		}




	}


}





void Combat::EnemyMovement(Controller * ctrl, GameObject * g_obj, Player * player, EnemyManager * enemies)
{




	if (player->GetPAttributes()->HasMovedATile(ctrl->GetFpsPointer()->Delta()))
		enemies->GetEnemiesPointer()[0][0]->GetTurnLogic()->Advance();



	for (GLuint i = 0; i < enemies->GetEnemiesPointer()->size(); i++)
	{


		Enemy * enemy = enemies->GetEnemiesPointer()[0][i];
		PhysicalAttributes * attr = enemy->GetPAttributes();
		TurnSystem * turns = enemy->GetTurnSystem();
		AutoPath * a_path = enemy->GetAutoPath();
		Stats * stats = enemy->GetStats();




		if (!enemy->GetTurnLogic()->IsUseless())
		{

			if (attr->position == attr->target &&
				enemy->GetTargetPosition() != vec2_0 &&
				turns->GetTurns() >= 1.0f / stats->base_movement_speed)
			{




				a_path->GetPathfinder()->Init(g_obj, attr->position, enemy->GetTargetPosition());
				a_path->Reset();



				if (a_path->GetPathfinder()->GetPathFound())
				{


					a_path->SetPath(a_path->GetPathfinder()->GetPath());
					a_path->Advance();


				}
				else
				{
					enemy->GetTurnLogic()->Reset();
					turns->Reset();

				}

			}



			if (a_path->IsSet() && !a_path->FinishedWithoutLast() && turns->GetTurns() >= 1.0f / stats->base_movement_speed)
			{



				attr->target = a_path->GetStep();
				g_obj->GetCollisionMap()->AddToList(glm::ivec2(attr->target));

	

				if (attr->HasMovedATile(ctrl->GetFpsPointer()->Delta()))
				{
			
					turns->ComputeMovement(-stats->base_movement_speed);
					enemy->GetTurnLogic()->Advance();
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





void Combat::EnemyRelated(Controller * ctrl, GameObject * g_obj, Player * player, EnemyManager * enemies, Map * map)
{



	this->UpdateTurns(g_obj, enemies);
	this->SortThingsOut(player, enemies);
	this->SetEnemyTarget(player, enemies);
	this->AquireEnemyTarget(player, enemies);
	this->EnemyAttack(g_obj, player, enemies);
	this->EnemyMovement(ctrl, g_obj, player, enemies);


}




void Combat::Action(Controller * ctrl,GameObject * g_obj, Player * player, EnemyManager * enemies, Map * map)
{


	
	this->PlayerRelated(g_obj, player, enemies, map);
	this->EnemyRelated(ctrl,g_obj, player, enemies, map);



	g_obj->GetTurnSystem()->Advance();


}






