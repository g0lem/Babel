//Checked 1


#include <common.hpp>



void SpriteManager::Init(GameObject * g_obj, Tooltip *t_tip)
{


	this->BindCreate("data/shaders/2d_vert.txt", "data/shaders/2d_frag.txt");


	this->level = 1;

	this->map = new Map();
	this->s_screen = new SplashScreen();

	this->test = new Sprite();

	char **tex_str = new char*[1];
	tex_str[0] = "restart.png";
	this->test->Load(1, "data/SplashScreen/", tex_str);


	this->map->Init(g_obj);




	this->player = new Player();
	this->player->Load(g_obj, this->map);

	this->m_enemies = new EnemyManager(6+ (rand() % 3), this->map, g_obj, 0);


	for (int i = 0; i < g_obj->GetItemList()->GetObjects().size(); i++)
	{
		if (g_obj->GetItemList()->GetObjects()[i]->item->id == CHEST_ID)
			this->m_enemies->AddEnemies(this->map, g_obj, 2, glm::vec2(g_obj->GetItemList()->GetObjects()[i]->position.x, g_obj->GetItemList()->GetObjects()[i]->position.y + 1));
	}



	this->m_effects = new EffectsHandler();

	this->font = new Font();

	this->font->Create("data/fonts/arial.ttf", 48);

	this->m_combat = new Combat();



	this->UnbindCreate();



}




void SpriteManager::Advance(GameObject * g_obj, Tooltip *t_tip)
{



	this->BindCreate("data/shaders/2d_vert.txt", "data/shaders/2d_frag.txt");

	this->level++;



	this->map = new Map();



	if (this->level == 3)
	{
		this->map->InitBoss(g_obj);


		this->player->Advance(g_obj, this->map);

		this->player->GetPAttributes()->position = glm::vec2(17, 1);
		this->player->GetPAttributes()->target = glm::vec2(17, 1);

		this->m_enemies = new EnemyManager(1, this->map, g_obj, 3);

		this->m_enemies->GetEnemiesPointer()[0][0]->GetPAttributes()->position = glm::vec2(17, 30);
		this->m_enemies->GetEnemiesPointer()[0][0]->GetPAttributes()->target = glm::vec2(17, 30);
		

		
		


		//this->m_enemies->AddEnemies(1, this->map, g_obj, 3);

	}
	else 
	{
		this->map->Init(g_obj);
		this->player->Advance(g_obj, this->map);

		if (this->level == 2)
		{
			this->m_enemies = new EnemyManager(4, this->map, g_obj, 0);

			for (int i = 0; i < g_obj->GetItemList()->GetObjects().size(); i++)
			{
				if (g_obj->GetItemList()->GetObjects()[i]->item->id == CHEST_ID)
					this->m_enemies->AddEnemies(this->map, g_obj, 2, glm::vec2(g_obj->GetItemList()->GetObjects()[i]->position.x, g_obj->GetItemList()->GetObjects()[i]->position.y + 1));
			}
			
			this->m_enemies->AddEnemies(3, this->map, g_obj, 1);
		}
	}







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



void SpriteManager::Render(SoundManager * sm, Controller * ctrl, GameObject * g_obj, Tooltip *t_tip)
{

	
	this->BindRun(ctrl->GetWindowWidth(), ctrl->GetWindowHeight());


	t_tip->Add(vec2_0, vec2_0, "Press E to close the door", 25, 0);



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
		this->player->Render(sm, ctrl, this->GetScreenPointer(), g_obj, this->map, t_tip);
		this->m_enemies->Render(sm, ctrl, this->GetScreenPointer(), g_obj, this->map, this->m_enemies->GetType());
		this->m_combat->Action(sm,ctrl, g_obj, this->player, this->m_enemies, this->map, this->m_enemies->GetType());

	}


	this->GetScreenPointer()->ApplyMatrix(Translation(glm::vec2(0, 0))*Scale(ctrl->GetWindowSize()));
	if (g_obj->GetPanelState()->hp == 0 && this->s_screen->Update() == true)
		this->test->Render(0);

	

	if (this->player->GetTarget() != NO_TARGET)
	{
		t_tip->UpdateText(DOOR_TOOL_TIP, "Press SPACE to attack");
		t_tip->UpdateStatus(DOOR_TOOL_TIP, true);
	}

	if (g_obj->GetItemList()->CheckTileForItem(this->player->GetPAttributes()->position))
	{
		t_tip->UpdateText(DOOR_TOOL_TIP, "Press E to pick up an item");
		t_tip->UpdateStatus(DOOR_TOOL_TIP, true);
	}



	if (g_obj->GetItemList()->CheckTileForChest(this->player->GetPAttributes()->position))
	{
		t_tip->UpdateText(DOOR_TOOL_TIP, "Press E to open a chest");
		t_tip->UpdateStatus(DOOR_TOOL_TIP, true);
	}


	

	if (g_obj->door_position != vec2_0)
	{
		if (this->player->GetEventHandler()->DoorToolTip(this->player->GetPAttributes()->position, this->map, g_obj, t_tip))
		t_tip->UpdateStatus(DOOR_TOOL_TIP, true);
		else
		t_tip->UpdateStatus(DOOR_TOOL_TIP, false);

		t_tip->UpdateOffset(DOOR_TOOL_TIP, 7.5);
		t_tip->UpdateVoffset(DOOR_TOOL_TIP, 4);
		t_tip->UpdatePosition(DOOR_TOOL_TIP, (g_obj->door_position+g_obj->GetScroller()->GetOffset()));
		//t_tip->UpdatePosition(DOOR_TOOL_TIP, (glm::vec2(10000, 10000) + g_obj->GetScroller()->GetOffset()));

		t_tip->UpdateStringLength(DOOR_TOOL_TIP, g_obj->GetFontList()->GetFont()->GetLength(t_tip->GetTooltips()->at(DOOR_TOOL_TIP)->string, 25));
		t_tip->UpdateStringPosition(DOOR_TOOL_TIP, glm::vec2(g_obj->door_position.x + g_obj->GetScroller()->GetOffset().x + 9 + 15, ctrl->GetWindowHeight() - (g_obj->door_position.y + g_obj->GetScroller()->GetOffset().y + 25 + 15 + 2)));
		
		//t_tip->UpdateStringPosition(DOOR_TOOL_TIP, glm::vec2(ctrl->GetWindowWidth() / 2 + g_obj->GetScroller()->GetOffset().x, ctrl->GetWindowHeight() / 2 - g_obj->GetScroller()->GetOffset().y));

		
		
		t_tip->UpdateSize(DOOR_TOOL_TIP,
			glm::vec2(g_obj->GetFontList()->GetFont()->GetLength(t_tip->GetTooltips()->at(DOOR_TOOL_TIP)->string, 25)
			+ t_tip->corner.x * 2 + t_tip->GetOffset(DOOR_TOOL_TIP), 25 + t_tip->corner.y + t_tip->GetVoffset(DOOR_TOOL_TIP)));

	}





	this->UnbindRun();


}