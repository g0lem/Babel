#include <common.hpp>


void GameRender::Init(GameObject * g_obj)
{




	this->s_manager = new SpriteManager(g_obj);




}



void GameRender::Render(SoundManager * sm, Controller * ctrl, GameObject * g_obj)
{


	this->s_manager->Render(sm,ctrl, g_obj);


}