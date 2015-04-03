//Checked 1






#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP


class GameObject
{



	Scroller * m_scroller;
	CollisionMap * c_map;



	Miscellaneous * m_misc;
	ItemList *m_list;



	TurnSystem * t_system;



	UIState * ui_state;
	panel_state * p_state;



	EnemyLoader * e_loader;
	TextObject * t_object;
	FontList * f_list;

	


public:
    bool rebuild;

	inline GameObject(){ this->Init(); }
	inline ~GameObject(){ this->Clean(); }


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


	void Init();


	void Clean();

	void Advance();



};




#endif