#include <common.hpp>






void EnemyLoader::Init()
{


	this->data = new std::vector < EnemyData* > ;
	

	//Scorpions

	EnemyData * temp = new EnemyData();
	temp->num_dirs = 8;

	temp->ranged = false;
	temp->boss = false;
	temp->scale = 1;

	temp->num_frames = new GLuint[temp->num_dirs];
	temp->num_frames[0] = 5;
	temp->num_frames[1] = 3;
	temp->num_frames[2] = 6;
	temp->num_frames[3] = 6;
	temp->num_frames[4] = 8;
	temp->num_frames[5] = 8;
	temp->num_frames[6] = 8;
	temp->num_frames[7] = 8;



	char ** tex_str;


	tex_str = new char*[8];
	tex_str[0] = "1.png";
	tex_str[1] = "2.png";
	tex_str[2] = "3.png";
	tex_str[3] = "4.png";
	tex_str[4] = "5.png";
	tex_str[5] = "6.png";
	tex_str[6] = "7.png";
	tex_str[7] = "8.png";



	temp->m_sprites = new Sprite*[temp->num_dirs];
	temp->m_sprites[0] = new Sprite();
	temp->m_sprites[0]->Load(temp->num_frames[0], "data/sprites/mob0/back/", tex_str);
	temp->m_sprites[1] = new Sprite();
	temp->m_sprites[1]->Load(temp->num_frames[1], "data/sprites/mob0/front/", tex_str);
	temp->m_sprites[2] = new Sprite();
	temp->m_sprites[2]->Load(temp->num_frames[2], "data/sprites/mob0/left/", tex_str);
	temp->m_sprites[3] = new Sprite();
	temp->m_sprites[3]->Load(temp->num_frames[3], "data/sprites/mob0/right/", tex_str);
	temp->m_sprites[4] = new Sprite();
	temp->m_sprites[4]->Load(temp->num_frames[4], "data/sprites/mob0/attack/back/", tex_str);
	temp->m_sprites[5] = new Sprite();
	temp->m_sprites[5]->Load(temp->num_frames[5], "data/sprites/mob0/attack/front/", tex_str);
	temp->m_sprites[6] = new Sprite();
	temp->m_sprites[6]->Load(temp->num_frames[6], "data/sprites/mob0/attack/left/", tex_str);
	temp->m_sprites[7] = new Sprite();
	temp->m_sprites[7]->Load(temp->num_frames[7], "data/sprites/mob0/attack/right/", tex_str);


	

	temp->num_drop = 10;
	temp->chances = new int[temp->num_drop];
	temp->items = new int[temp->num_drop];
	


	temp->chances[0] = 24;  temp->items[0] = EnemyData::item_types::health_potion_12;
	temp->chances[1] = 10; temp->items[1] = EnemyData::item_types::health_potion_12;
	temp->chances[2] = 10;  temp->items[2] = EnemyData::item_types::health_potion_12;
	temp->chances[3] = 5; temp->items[3] = EnemyData::item_types::Sword;
	temp->chances[4] = 3;  temp->items[4] = EnemyData::item_types::Hammer;
	temp->chances[5] = 5; temp->items[5] = EnemyData::item_types::Leather_Armor_1;
	temp->chances[6] = 3;  temp->items[6] = EnemyData::item_types::Plate_Armor_1;
	temp->chances[7] = 1; temp->items[7] = EnemyData::item_types::Epic_Sword;
	temp->chances[8] = 1; temp->items[8] = EnemyData::item_types::Epic_Armor;
	temp->chances[9] = 38; temp->items[9] = EnemyData::item_types::Nothing;








	temp->m_stats = new Stats();
	temp->m_stats->base_attack = glm::vec2(1.0f, 3.0f);
	temp->m_stats->base_attack_speed = 1.0f;
	temp->m_stats->base_movement_speed = 1.0f;
	temp->m_stats->GetHp()->Buff(7);
	
	temp->m_stats->path_type = PATH_WITH_DOORS;

	this->data->push_back(temp);








	//Hydra

	

	temp = new EnemyData();
	temp->num_dirs = 8;
	temp->boss = false;
	tex_str = new char*[3];
	tex_str[0] = "frame1.png";
	tex_str[1] = "frame2.png";
	tex_str[2] = "frame3.png";

	temp->num_frames = new GLuint[temp->num_dirs];
	temp->num_frames[0] = 3;
	temp->num_frames[1] = 3;
	temp->num_frames[2] = 3;
	temp->num_frames[3] = 3;
	temp->num_frames[4] = 3;
	temp->num_frames[5] = 3;
	temp->num_frames[6] = 3;
	temp->num_frames[7] = 3;



	temp->m_sprites = new Sprite*[temp->num_dirs];
	temp->m_sprites[0] = new Sprite();
	temp->m_sprites[0]->Load(temp->num_frames[0], "data/sprites/hydra/back/", tex_str);
	temp->m_sprites[1] = new Sprite();
	temp->m_sprites[1]->Load(temp->num_frames[1], "data/sprites/hydra/front/", tex_str);
	temp->m_sprites[2] = new Sprite();
	temp->m_sprites[2]->Load(temp->num_frames[2], "data/sprites/hydra/left/", tex_str);
	temp->m_sprites[3] = new Sprite();
	temp->m_sprites[3]->Load(temp->num_frames[3], "data/sprites/hydra/right/", tex_str);
	temp->m_sprites[4] = new Sprite();
	temp->m_sprites[4]->Load(temp->num_frames[4], "data/sprites/hydra/back/", tex_str);
	temp->m_sprites[5] = new Sprite();
	temp->m_sprites[5]->Load(temp->num_frames[5], "data/sprites/hydra/front/", tex_str);
	temp->m_sprites[6] = new Sprite();
	temp->m_sprites[6]->Load(temp->num_frames[6], "data/sprites/hydra/left/", tex_str);
	temp->m_sprites[7] = new Sprite();
	temp->m_sprites[7]->Load(temp->num_frames[7], "data/sprites/hydra/right/", tex_str);
	
	
	
	
	temp->m_stats = new Stats();
	temp->m_stats->base_attack = glm::vec2(0.0f, 0.0f);
	temp->m_stats->base_attack_speed = 1.0f;
	temp->m_stats->base_movement_speed = 1.0f;
	temp->m_stats->GetHp()->Buff(30);

	temp->ranged = true;
	temp->scale = 1;

	temp->num_drop = 10;
	temp->chances = new int[temp->num_drop];
	temp->items = new int[temp->num_drop];



	temp->chances[0] = 0;  temp->items[0] = EnemyData::item_types::health_potion_12;
	temp->chances[1] = 10; temp->items[1] = EnemyData::item_types::health_potion_12;
	temp->chances[2] = 0;  temp->items[2] = EnemyData::item_types::health_potion_12;
	temp->chances[3] = 5; temp->items[3] = EnemyData::item_types::Sword;
	temp->chances[4] = 5;  temp->items[4] = EnemyData::item_types::Hammer;
	temp->chances[5] = 5; temp->items[5] = EnemyData::item_types::Leather_Armor_2;
	temp->chances[6] = 5;  temp->items[6] = EnemyData::item_types::Plate_Armor_2;
	temp->chances[7] = 20; temp->items[7] = EnemyData::item_types::Epic_Sword;
	temp->chances[8] = 20; temp->items[8] = EnemyData::item_types::Epic_Armor;
	temp->chances[9] = 20; temp->items[9] = EnemyData::item_types::Nothing;







	this->data->push_back(temp);





	//Golem

	temp = new EnemyData();
	temp->num_dirs = 9;
	temp->boss = false; 
	tex_str = new char*[4];
	tex_str[0] = "1.png";
	tex_str[1] = "2.png";
	tex_str[2] = "3.png";
	tex_str[3] = "4.png";

	temp->num_frames = new GLuint[temp->num_dirs];
	temp->num_frames[0] = 4;
	temp->num_frames[1] = 4;
	temp->num_frames[2] = 4;
	temp->num_frames[3] = 4;
	temp->num_frames[4] = 4;
	temp->num_frames[5] = 4;
	temp->num_frames[6] = 4;
	temp->num_frames[7] = 4;
	temp->num_frames[8] = 1;


	temp->m_sprites = new Sprite*[temp->num_dirs];
	temp->m_sprites[0] = new Sprite();
	temp->m_sprites[0]->Load(temp->num_frames[0], "data/sprites/golem/back/", tex_str);
	temp->m_sprites[1] = new Sprite();
	temp->m_sprites[1]->Load(temp->num_frames[1], "data/sprites/golem/front/", tex_str);
	temp->m_sprites[2] = new Sprite();
	temp->m_sprites[2]->Load(temp->num_frames[2], "data/sprites/golem/left/", tex_str);
	temp->m_sprites[3] = new Sprite();
	temp->m_sprites[3]->Load(temp->num_frames[3], "data/sprites/golem/right/", tex_str);
	temp->m_sprites[4] = new Sprite();
	temp->m_sprites[4]->Load(temp->num_frames[4], "data/sprites/golem/attack/back/", tex_str);
	temp->m_sprites[5] = new Sprite();
	temp->m_sprites[5]->Load(temp->num_frames[5], "data/sprites/golem/attack/front/", tex_str);
	temp->m_sprites[6] = new Sprite();
	temp->m_sprites[6]->Load(temp->num_frames[6], "data/sprites/golem/attack/left/", tex_str);
	temp->m_sprites[7] = new Sprite();
	temp->m_sprites[7]->Load(temp->num_frames[7], "data/sprites/golem/attack/right/", tex_str);
	temp->m_sprites[8] = new Sprite();
	temp->m_sprites[8]->Load(temp->num_frames[8], "data/sprites/golem/sleep/", tex_str);



	temp->m_stats = new Stats();
	temp->m_stats->aggressive = false;
	temp->m_stats->base_attack = glm::vec2(2.0f, 4.0f);
	temp->m_stats->base_attack_speed = 1.0f;
	temp->m_stats->base_movement_speed = 1.0f;
	temp->m_stats->path_type = PATH_PLAYER;
	temp->m_stats->GetHp()->Buff(27);

	temp->ranged = false;
	temp->scale = 1;

	temp->num_drop = 10;
	temp->chances = new int[temp->num_drop];
	temp->items = new int[temp->num_drop];


	temp->chances[0] = 9;  temp->items[0] = EnemyData::item_types::health_potion_12;
	temp->chances[1] = 0; temp->items[1] = EnemyData::item_types::health_potion_12;
	temp->chances[2] = 5;  temp->items[2] = EnemyData::item_types::health_potion_12;
	temp->chances[3] = 3; temp->items[3] = EnemyData::item_types::Sword;
	temp->chances[4] = 1;  temp->items[4] = EnemyData::item_types::Hammer;
	temp->chances[5] = 3; temp->items[5] = EnemyData::item_types::Leather_Armor_2;
	temp->chances[6] = 3;  temp->items[6] = EnemyData::item_types::Plate_Armor_2;
	temp->chances[7] = 1; temp->items[7] = EnemyData::item_types::Epic_Sword;
	temp->chances[8] = 1; temp->items[8] = EnemyData::item_types::Epic_Armor;
	temp->chances[9] = 74; temp->items[9] = EnemyData::item_types::Nothing;






	this->data->push_back(temp);


	//BOSS



	temp = new EnemyData();
	temp->num_dirs = 8;

	temp->ranged = false;
	temp->boss = false;
	temp->scale = 2;

	temp->num_frames = new GLuint[temp->num_dirs];
	temp->num_frames[0] = 5;
	temp->num_frames[1] = 3;
	temp->num_frames[2] = 6;
	temp->num_frames[3] = 6;
	temp->num_frames[4] = 8;
	temp->num_frames[5] = 8;
	temp->num_frames[6] = 8;
	temp->num_frames[7] = 8;



	


	tex_str = new char*[8];
	tex_str[0] = "1.png";
	tex_str[1] = "2.png";
	tex_str[2] = "3.png";
	tex_str[3] = "4.png";
	tex_str[4] = "5.png";
	tex_str[5] = "6.png";
	tex_str[6] = "7.png";
	tex_str[7] = "8.png";



	temp->m_sprites = new Sprite*[temp->num_dirs];
	temp->m_sprites[0] = new Sprite();
	temp->m_sprites[0]->Load(temp->num_frames[0], "data/sprites/mob0/back/", tex_str);
	temp->m_sprites[1] = new Sprite();
	temp->m_sprites[1]->Load(temp->num_frames[1], "data/sprites/mob0/front/", tex_str);
	temp->m_sprites[2] = new Sprite();
	temp->m_sprites[2]->Load(temp->num_frames[2], "data/sprites/mob0/left/", tex_str);
	temp->m_sprites[3] = new Sprite();
	temp->m_sprites[3]->Load(temp->num_frames[3], "data/sprites/mob0/right/", tex_str);
	temp->m_sprites[4] = new Sprite();
	temp->m_sprites[4]->Load(temp->num_frames[4], "data/sprites/mob0/attack/back/", tex_str);
	temp->m_sprites[5] = new Sprite();
	temp->m_sprites[5]->Load(temp->num_frames[5], "data/sprites/mob0/attack/front/", tex_str);
	temp->m_sprites[6] = new Sprite();
	temp->m_sprites[6]->Load(temp->num_frames[6], "data/sprites/mob0/attack/left/", tex_str);
	temp->m_sprites[7] = new Sprite();
	temp->m_sprites[7]->Load(temp->num_frames[7], "data/sprites/mob0/attack/right/", tex_str);




	temp->num_drop = 10;
	temp->chances = new int[temp->num_drop];
	temp->items = new int[temp->num_drop];



	temp->chances[0] = 24;  temp->items[0] = EnemyData::item_types::health_potion_12;
	temp->chances[1] = 10; temp->items[1] = EnemyData::item_types::health_potion_12;
	temp->chances[2] = 10;  temp->items[2] = EnemyData::item_types::health_potion_12;
	temp->chances[3] = 5; temp->items[3] = EnemyData::item_types::Sword;
	temp->chances[4] = 3;  temp->items[4] = EnemyData::item_types::Hammer;
	temp->chances[5] = 5; temp->items[5] = EnemyData::item_types::Leather_Armor_1;
	temp->chances[6] = 3;  temp->items[6] = EnemyData::item_types::Plate_Armor_1;
	temp->chances[7] = 1; temp->items[7] = EnemyData::item_types::Epic_Sword;
	temp->chances[8] = 1; temp->items[8] = EnemyData::item_types::Epic_Armor;
	temp->chances[9] = 38; temp->items[9] = EnemyData::item_types::Nothing;








	temp->m_stats = new Stats();
	temp->m_stats->base_attack = glm::vec2(1.0f, 3.0f);
	temp->m_stats->base_attack_speed = 1.0f;
	temp->m_stats->base_movement_speed = 1.0f;
	temp->m_stats->GetHp()->Buff(7);



	this->data->push_back(temp);


}


