#pragma once




class UIHandler
{


	UIRender * ui_render;



public:




	inline UIHandler(GameObject *g_obj, Tooltip *t_tip){ this->Init(g_obj, t_tip); }


	void Init(GameObject *g_obj, Tooltip*t_tip);


	void Render(SoundManager *sm, Tooltip *t_tip, Controller * ctrl, GameObject * g_obj, glm::vec2 player_position);



};