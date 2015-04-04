#pragma once




class UIHandler
{


	UIRender * ui_render;



public:




	inline UIHandler(Tooltip *t_tip){ this->Init(t_tip); }


	void Init(Tooltip*t_tip);


	void Render(SoundManager *sm, Tooltip *t_tip, Controller * ctrl, GameObject * g_obj);



};