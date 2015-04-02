#include <common.hpp>

#define MPLAYER_WIDTH 320
#define MPLAYER_HEIGHT 320

void MediaPlayer::Init()
{

	this->CreateWindow(MPLAYER_WIDTH, MPLAYER_HEIGHT, false, "Media Player 0.0.1", NULL, NULL);

	g_object = new GameObject();

	f_manager = new FontManager(g_object);

	s_manager = new SoundManager();

	sprite_m = new SpriteManager(g_object);





	glClearColor(0.f, 0.f, 0.f, 1.f);


}


void MediaPlayer::Render()
{





}



void MediaPlayer::Run()
{

	do{


		glfwSwapBuffers(this->GetWindow());
		glfwPollEvents();

	} while (!this->GetKey(GLFW_KEY_ESCAPE) && glfwWindowShouldClose(this->GetWindow()) == 0);



}

void MediaPlayer::Terminate()
{

	delete s_manager;
	delete f_manager;
	delete sprite_m;


}

