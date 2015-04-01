#ifndef COMBAT_HPP
#define COMBAT_HPP




#define MIN_AQUIRE_DISTANCE 8.0f






class Combat
{




	void SetPlayerTarget(Player * player, EnemyManager * enemies);
	void PlayerAttack(GameObject * g_obj, Player * player, EnemyManager *enemies, Map *current_map);
	void PlayerRelated(GameObject * g_obj, Player * player, EnemyManager * enemies, Map * map);





	void SortThingsOut(Player * player, EnemyManager * enemies);
	void SetEnemyTarget(Player * player, EnemyManager * enemies);
	void AquireEnemyTarget(Player * player, EnemyManager * enemies);
	void EnemyAttack(GameObject * g_obj, Player * player, EnemyManager *enemies);
	void EnemyMovement(Controller * ctrl, GameObject * g_obj, Player * player ,EnemyManager * enemies);
	void EnemyRelated(Controller * ctrl,GameObject * g_obj, Player * player, EnemyManager * enemies, Map * map);
	void UpdateTurns(GameObject * g_obj, EnemyManager * enemies);



public:



	inline Combat(){ this->Init(); }
	void Init();



	void Action(Controller * ctrl, GameObject * g_obj, Player * player, EnemyManager * enemies, Map * map);



};





#endif