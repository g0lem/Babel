#pragma once



#define ACTIVE 1
#define NOT_ACTIVE 0

#define MENU_KEY GLFW_KEY_ESCAPE
#define INVENTORY_KEY GLFW_KEY_1



class UIState
{



	//CharPanState * char_panel;

	panel_state *p_state;

	MenuState *m_state;

	InventoryState *i_state;

	StoryState * s_state;

	UI_intersect * inter_handler;


	void ProcessKeys(SoundManager *sm, Controller * ctrl);


	void ManageQuits();


public:


	inline UI_intersect * GetInterHandler(){ return this->inter_handler; }


	inline UIState(){ this->Init(); }

	inline panel_state *GetPanelState(){ return this->p_state; }

	inline MenuState *GetMenuState(){ return this->m_state; }

	inline InventoryState *GetInventoryState(){ return this->i_state; }

	inline StoryState *GetStoryState(){ return this->s_state; }

	void Init();



	void Update(SoundManager *sm, Controller * ctrl);



};



