#include <common.hpp>



void GameRender::Init(GameObject * g_obj, Tooltip *t_tip)
{




	this->s_manager = new SpriteManager(g_obj, t_tip);



}



void GameRender::Render(SoundManager * sm, Controller * ctrl, GameObject * g_obj, Tooltip *t_tip)
{



	if (ctrl->GetKeyOnce(GLFW_KEY_N) || g_obj->rebuild == true)
	{
		level_list.push_back(new save(this, g_obj));
		g_obj->Advance();
		g_obj->GetFontList()->Load();
		this->s_manager->Advance(g_obj, t_tip);
		
	}
	if (ctrl->GetKeyOnce(GLFW_KEY_R))
	{
		g_obj->Init();
		g_obj->GetFontList()->Load();
		this->s_manager->Init(g_obj, t_tip);

	}





	this->s_manager->Render(sm,ctrl, g_obj, t_tip);


}