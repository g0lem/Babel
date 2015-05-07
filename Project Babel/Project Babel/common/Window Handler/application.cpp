//Checked 2014


#include <common.hpp>











void Application::Init()
{




    this->CreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT,
		false,
		"Project Babel 0.1.7a",
		4, 0);





	g_object = new GameObject();
	sound_m = new SoundManager();
	g_render = new GameRender(g_object);
	t_tip = new Tooltip();
	ui = new UIHandler(t_tip);
	f_m = new FontManager(g_object);



	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);


}



void Application::Run()
{
	

	//this->sound_m->setMusicLoop("Green Hills", true);

	do{


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		this->Enable();



		g_render->Render(sound_m,this, g_object);



		if (g_render->GetDrawCode() == true)
		{
			ui->Render(sound_m, t_tip, this, g_object, g_render->GetSpriteManager()->GetPlayer()->GetPAttributes()->position);
			f_m->Render(this, g_object,t_tip);
			g_object->GetUIState()->Update(sound_m, this);
		}



		glfwSwapBuffers(this->GetWindow());
		glfwPollEvents();

		

	} while (g_object->GetUIState()->GetMenuState()->GetButtonStates()[2] != PRESSED && glfwWindowShouldClose(this->GetWindow()) == 0);


}


void Application::Terminate()
{



	delete g_render;
	delete g_object;
	delete sound_m;
	delete ui;



}




