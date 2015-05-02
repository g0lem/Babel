//Checked 1


#include <common.hpp>



void SpriteManager::Init(GameObject * g_obj)
{


	this->BindCreate("data/shaders/2d_vert.txt","data/shaders/2d_frag.txt");




	this->map = new Map();
	this->s_screen = new SplashScreen();

	this->test = new Sprite();

	char **tex_str = new char*[1];
	tex_str[0] = "restart.png";
	this->test->Load(1, "data/SplashScreen/", tex_str);


	this->map->Init(g_obj);
	



	this->player = new Player();
	this->player->Load(g_obj, this->map);

	this->m_enemies = new EnemyManager(60+(rand()%3), this->map, g_obj, 0);

	for (int i = 0; i < g_obj->GetItemList()->GetObjects().size(); i++)
	{
		if (g_obj->GetItemList()->GetObjects()[i]->item->id == CHEST_ID)
			this->m_enemies->AddEnemies(this->map, g_obj, 2, glm::vec2(g_obj->GetItemList()->GetObjects()[i]->position.x, g_obj->GetItemList()->GetObjects()[i]->position.y+1));
	}



	this->m_effects = new EffectsHandler();

	this->font = new Font();

	this->font->Create("data/fonts/arial.ttf", 48);

	this->m_combat = new Combat();



	this->UnbindCreate();




}




void SpriteManager::Advance(GameObject * g_obj)
{


	this->BindCreate("data/shaders/2d_vert.txt", "data/shaders/2d_frag.txt");

	
	


	this->map = new Map();
	



	this->map->InitBoss(g_obj);


	this->player->Advance(g_obj, this->map);



	
	
	
	this->m_enemies = new EnemyManager(1, this->map, g_obj, 1);


	this->m_effects = new EffectsHandler();

	this->font = new Font();

	this->font->Create("data/fonts/arial.ttf", 48);

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





void SpriteManager::Render(SoundManager * sm, Controller * ctrl, GameObject * g_obj)
{

	
	this->BindRun(ctrl->GetWindowWidth(), ctrl->GetWindowHeight());


	if (this->s_screen->Update() == false)
	{


		this->s_screen->Render(ctrl, this->GetScreenPointer());
		if (ctrl->GetKeyOnce(GLFW_KEY_ENTER) == 1)
			this->s_screen->SkipFrame();


	}
	else
	{
		g_obj->GetScroller()->ComputeScreenLimits(ctrl, this->map->GetTilemap()->GetSize(), this->map->GetTilemap()->GetTileScale());



		g_obj->GetScroller()->ComputeScreenLimits(ctrl, this->map->GetTilemap()->GetSize(), this->map->GetTilemap()->GetTileScale());
		this->map->Render(ctrl, this->GetScreenPointer(), g_obj, player->GetPAttributes()->position);

		g_obj->GetSpellManager()->Render(ctrl, this->GetScreenPointer(), g_obj->GetCollisionMap()->GetTiles());
		this->player->Render(sm, ctrl, this->GetScreenPointer(), g_obj, this->map);
		this->m_enemies->Render(sm, ctrl, this->GetScreenPointer(), g_obj, this->map, this->m_enemies->GetType());
		this->m_combat->Action(sm,ctrl, g_obj, this->player, this->m_enemies, this->map, this->m_enemies->GetType());

	}


	this->GetScreenPointer()->ApplyMatrix(Translation(glm::vec2(0, 0))*Scale(ctrl->GetWindowSize()));
	if (g_obj->GetPanelState()->hp == 0 && this->s_screen->Update() == true)
		this->test->Render(0);



	this->UnbindRun();


}