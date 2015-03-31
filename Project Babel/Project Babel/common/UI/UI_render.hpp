#pragma once





class UIRender : public Aaether2D
{


	CharPanRender * char_panel;

	ActionSpriteRender * action_sr;

	PanelRender * panel_r;

	public:


		
		inline UIRender(char * vertex_shader, char * fragment_shader){ this->Init(vertex_shader, fragment_shader); }



		void Init(char * vertex_shader, char * fragment_shader);



		void Render(Controller *ctrl, GameObject *g_obj);





	};
