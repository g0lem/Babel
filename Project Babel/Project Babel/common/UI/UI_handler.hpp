#pragma once




class UIHandler
{


	UIRender * ui_render;



public:




	inline UIHandler(){ this->Init(); }


	void Init();


	void Render(Controller * ctrl, GameObject * g_obj);



};