#pragma once





class UIRender : public Aaether2D
{

	PanelRender * panel_r;

	Inventory * inventory_r;

	StoryRender * story_r;

	MenuRender * menu_r;

	public:


		
		inline UIRender(char * vertex_shader, char * fragment_shader){ this->Init(vertex_shader, fragment_shader); }



		void Init(char * vertex_shader, char * fragment_shader);



		void Render(Controller *ctrl, GameObject *g_obj);





	};
