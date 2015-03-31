#include <common.hpp>


void GameRender::Init(GameObject * g_obj)
{




	this->s_manager = new SpriteManager(g_obj);


	this->f_manager = new FontManager();


}



void GameRender::Render(Controller * ctrl, GameObject * g_obj)
{


	this->s_manager->Render(ctrl, g_obj);



	this->f_manager->Render(ctrl);


}