#pragma once





class UIRender : public Aaether2D
{

	PanelRender * panel_r;

	Inventory * inventory_r;

	StoryRender * story_r;

	MenuRender * menu_r;

	StatsRender * stat_r;

	public:


		
		inline UIRender(char * vertex_shader, char * fragment_shader, GameObject *g_obj, Tooltip *tooltips){ this->Init(vertex_shader, fragment_shader, g_obj,tooltips); }



		void Init(char * vertex_shader, char * fragment_shader, GameObject *g_obj, Tooltip *tooltips);



		void Render(SoundManager *sm, Tooltip *tooltips, Controller *ctrl, GameObject *g_obj, glm::vec2 player_positon);





	};
