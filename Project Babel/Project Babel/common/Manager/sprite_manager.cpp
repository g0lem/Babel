//Checked 1


#include <common.hpp>



void SpriteManager::Init(GameObject * g_obj)
{


	this->BindCreate("data/shaders/2d_vert.txt","data/shaders/2d_frag.txt");








	this->map = new Map();


	this->s_screen = new SplashScreen();

	this->map->Init(g_obj);


	g_obj->GetCollisionMap()->CreateOutOfMap(this->map->GetTilemap());



	this->player = new Player();



	this->player->Load(g_obj, this->map);



	this->m_enemies = new EnemyManager(10, this->map, g_obj);



	this->m_combat = new Combat();


	this->UnbindCreate();




}



void SpriteManager::Clean()
{


	Aaether2D::Clean();


	delete player;
	delete map;
	delete m_enemies;
	delete m_combat;



}





void SpriteManager::Render(Controller * ctrl, GameObject * g_obj)
{


	this->BindRun(ctrl->GetWindowWidth(), ctrl->GetWindowHeight());


	if (this->s_screen->Update() == false)
	{
		this->s_screen->Render(ctrl, this->GetScreenPointer());


		if (ctrl->GetKeyOnce(GLFW_KEY_ENTER) == 1 || ctrl->GetKeyOnce(GLFW_KEY_SPACE) == 1 || ctrl->GetKeyOnce(GLFW_KEY_ESCAPE) == 1)
			this->s_screen->SkipFrame();
	}
	else
	{
		g_obj->GetScroller()->ComputeScreenLimits(ctrl, this->map->GetTilemap()->GetSize(), this->map->GetTilemap()->GetTileScale());


		this->map->Render(ctrl, this->GetScreenPointer(), g_obj, player->GetPAttributes()->position);


		this->player->Render(ctrl, this->GetScreenPointer(), g_obj, this->map);


		this->m_enemies->Render(ctrl, this->GetScreenPointer(), g_obj, this->map);


		this->m_combat->Action(ctrl, g_obj, this->player, this->m_enemies, this->map);

		this->s_screen->Render(ctrl, this->GetScreenPointer());
	}


	this->UnbindRun();


}