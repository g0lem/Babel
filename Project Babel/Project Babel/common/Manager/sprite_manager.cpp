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

	this->m_enemies = new EnemyManager(20+(rand()%3), this->map, g_obj, 2);

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

bool gX, gY, gZ;

void Update(Controller *ctrl, GameObject *g_obj)
{
	for (int i = 0; i < g_obj->GetItemList()->GetList().size(); i++)
	{
		if (g_obj->GetItemList()->GetList()[i]->item_name == "Epic Sword" || g_obj->GetItemList()->GetList()[i]->item_name == "Epic Armor")
		{
			if (g_obj->GetItemList()->GetList()[i]->color.x < g_obj->GetItemList()->GetList()[i]->base_color.x)
				gX = true;
			if (g_obj->GetItemList()->GetList()[i]->color.y < g_obj->GetItemList()->GetList()[i]->base_color.y)
				gY = true;
			if(g_obj->GetItemList()->GetList()[i]->color.z < g_obj->GetItemList()->GetList()[i]->base_color.z)
			{
				gZ= true;
			}
			if (g_obj->GetItemList()->GetList()[i]->color.x > 0.99f)
				gX = false;
			if (g_obj->GetItemList()->GetList()[i]->color.y > 0.60f)
				gY = false;
			if( g_obj->GetItemList()->GetList()[i]->color.z > 0.99f)
			{
				gZ = false;
			}



			//if (gX == false)
			//	g_obj->GetItemList()->GetList()[i]->color.x -= 0.05f;
			//else
			//	g_obj->GetItemList()->GetList()[i]->color.x += 0.05f;
			if (gY == false)
				g_obj->GetItemList()->GetList()[i]->color.y -= 0.04f*ctrl->GetFpsPointer()->Delta()*40;
			else
				g_obj->GetItemList()->GetList()[i]->color.y += 0.04f*ctrl->GetFpsPointer()->Delta() * 80;
			//if (gZ == false)
			//	g_obj->GetItemList()->GetList()[i]->color.z -= 0.03f;
			//else
			//	g_obj->GetItemList()->GetList()[i]->color.z += 0.03f;

		}
	}


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

		Update(ctrl, g_obj);

		g_obj->GetScroller()->ComputeScreenLimits(ctrl, this->map->GetTilemap()->GetSize(), this->map->GetTilemap()->GetTileScale());
		this->map->Render(ctrl, this->GetScreenPointer(), g_obj, player->GetPAttributes()->position);

		g_obj->GetSpellManager()->Render(ctrl, this->GetScreenPointer(), g_obj->GetScroller()->GetOffset() ,g_obj->GetCollisionMap()->GetTiles());
		this->player->Render(sm, ctrl, this->GetScreenPointer(), g_obj, this->map);
		this->m_enemies->Render(sm, ctrl, this->GetScreenPointer(), g_obj, this->map, this->m_enemies->GetType());
		this->m_combat->Action(sm,ctrl, g_obj, this->player, this->m_enemies, this->map, this->m_enemies->GetType());

	}


	this->GetScreenPointer()->ApplyMatrix(Translation(glm::vec2(0, 0))*Scale(ctrl->GetWindowSize()));
	if (g_obj->GetPanelState()->hp == 0 && this->s_screen->Update() == true)
		this->test->Render(0);



	this->UnbindRun();


}