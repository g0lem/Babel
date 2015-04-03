#include <common.hpp>






void EnemyLoader::Init()
{


	this->data = new std::vector < EnemyData* > ;



	EnemyData * temp = new EnemyData();
	temp->num_dirs = 8;



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


	temp->m_stats = new Stats();
	temp->m_stats->base_attack = glm::vec2(0.0f, 1.0f);
	temp->m_stats->base_attack_speed = 1.0f;
	temp->m_stats->base_movement_speed = 1.0f;
	temp->m_stats->GetHp()->Buff(15);
	


	this->data->push_back(temp);



}


