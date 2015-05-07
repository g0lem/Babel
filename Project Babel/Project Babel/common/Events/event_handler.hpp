#pragma once




class EventHandler
{
	int **e_map;
	
	void Load(Map *current_map, GameObject *g_obj);
	void Door(glm::vec2 position, Map *current_map, GameObject *g_obj);
	void OpenChest(glm::vec2 position, Map *current_map, GameObject *g_obj);
	void PickUp(glm::vec2 position, Map *current_map, GameObject *g_obj);
	void Lever(glm::vec2 position, Map *current_map, GameObject *g_obj);
	void NextLvl(glm::vec2 position, Map *current_map, GameObject *g_obj);
	void Health(glm::vec2 position, Map *current_map, Stats *m_stats, GameObject *g_obj);

	bool n_check = false;

	void Trap(glm::vec2 position, Map *current_map, GameObject *g_obj);


public:
	void Init(Map *current_map, GameObject *g_obj);
	void TriggerEvent(glm::vec2 position, Map *current_map, GameObject *g_obj, Stats *m_stats);
    int **GetEventMapTiles(){ return this->e_map; }
	static void AutomaticallyOpenDoor(glm::vec2 position, Map *current_map, GameObject *g_obj, glm::vec2 &door_pos);
	static void EventHandler::DestroyDoor(glm::vec2 position, Map *&current_map, GameObject *g_obj);
	static void DisplayTablet(int id);

};

