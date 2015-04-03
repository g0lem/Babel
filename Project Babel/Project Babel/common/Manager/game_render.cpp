#include <common.hpp>


void GameRender::Init(GameObject * g_obj)
{




	this->s_manager = new SpriteManager(g_obj);


	this->f_manager = new FontManager(g_obj);


}



void GameRender::Render(SoundManager * sm, Controller * ctrl, GameObject * g_obj)
{


	this->s_manager->Render(sm,ctrl, g_obj);
	this->f_manager->Render(ctrl, g_obj);


}