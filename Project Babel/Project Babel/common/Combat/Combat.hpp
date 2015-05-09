#ifndef COMBAT_HPP
#define COMBAT_HPP




#define MIN_AQUIRE_DISTANCE 8.0f






class Combat
{




	void SetPlayerTarget(Player * player, EnemyManager * enemies);
	void PlayerAttack(SplashScreen *sc, SoundManager * sm, Controller * ctrl, GameObject * g_obj, Player * player, EnemyManager *enemies, Map *current_map, int type);
	void CheckPlayerMoveAbility(Player * player, EnemyManager * enemies);
	void PlayerRelated(SplashScreen *sc, SoundManager * sm, Controller * ctrl, GameObject * g_obj, Player * player, EnemyManager * enemies, Map * map, int type);


	void SortThingsOut(Player * player, EnemyManager * enemies);
	void SetEnemyTarget(Player * player, EnemyManager * enemies);
	void AquireEnemyTarget(Player * player, EnemyManager * enemies);
	void EnemyAttack(SoundManager *sm, Controller * ctrl, GameObject * g_obj, Player * player, EnemyManager *enemies, int type);
	void EnemyMovement(Controller * ctrl, GameObject * g_obj, Player * player, EnemyManager * enemies, Map* currend_map, int type);
	void EnemyRelated(SoundManager *sm, Controller * ctrl, GameObject * g_obj, Player * player, EnemyManager * enemies, Map * map, int type);
	void UpdateTurns(GameObject * g_obj, EnemyManager * enemies);

	sf::Clock *t_clock;

public:



	


	inline Combat(){ this->Init(); }
	void Init();



	void Action(SplashScreen *sc, SoundManager * sm,
		Controller * ctrl,
		GameObject * g_obj, 
		Player * player,
		EnemyManager * enemies,
		Map * map, int type);



};





#endif