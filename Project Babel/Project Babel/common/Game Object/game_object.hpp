//Checked 1


#ifndef GAME_OBJECT_HPP

#define GAME_OBJECT_HPP

#define DOOR_TOOL_TIP 24

struct StatText
{
	char *text;
	glm::vec2 pos;
	int size;

	StatText(char *text, glm::vec2 pos, int size)
		:
		text(text), pos(pos), size(size)
	{

	}
};


struct untablet
{
	int frameText;
	int frameCon;
	int id;
	glm::vec2 pos;
	int state;
};

class GameObject
{



	Scroller * m_scroller;
	CollisionMap * c_map;


	Miscellaneous * m_misc;
	ItemList *m_list;
	SpellManager *sp_manager;


	TurnSystem * t_system;



	UIState * ui_state;
	panel_state * p_state;


	EnemyLoader * e_loader;
	TextObject * t_object;
	FontList * f_list;

	
	


public:
    bool rebuild;

	Stats * playerStats;
	Sprite * spellsprite;
	int spellframe;
	int spellsize;
	int cooldown;
	glm::vec2 spellPOS;
	inline GameObject(){ this->Init(); }
	inline ~GameObject(){ this->Clean(); }
	std::vector<char*> *statpos2;
	glm::vec2 statpos;

	bool statrender = 0;
	float spelldamage = 0;
	bool triggerstats = false;
	int unlockedtablets = 0;

	inline UIState * GetUIState(){ return this->ui_state; }
	inline Scroller * GetScroller(){ return this->m_scroller; }
	inline CollisionMap * GetCollisionMap(){ return this->c_map; }
	inline Miscellaneous * GetMisc(){ return this->m_misc; }
	inline ItemList * GetItemList(){ return this->m_list; }
	inline TurnSystem * GetTurnSystem(){ return this->t_system; }
	inline panel_state*GetPanelState(){ return this->p_state; }
	inline EnemyLoader * GetEnemyLoader(){ return this->e_loader; }
	inline TextObject * GetTextObject(){ return this->t_object; }
	inline FontList * GetFontList(){ return this->f_list; }
	inline SpellManager * GetSpellManager(){ return this->sp_manager; }


	std::vector<StatText> *StatPositions;

	char *hp;
	char *xp;
	glm::vec2 hp_pos;
	glm::vec2 xp_pos;
	char *level;
	int level_i;
	char *floor;
	int floor_c;
	glm::vec2 level_pos, floor_pos;

	void SpawnSolidObject(int id, glm::vec2 position);

	void Init();

	std::vector<untablet*> *u_t;

	inline std::vector<untablet*> *GetTablets(){ return this->u_t; }

	void Clean();

	void Advance();

	int boss_deal_damage=0;


	glm::vec2 door_position = vec2_0;


};




#endif