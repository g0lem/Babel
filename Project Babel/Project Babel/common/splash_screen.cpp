#include "common.hpp"
#include "splash_screen.hpp"

#define NUM_SCREENS 1

void SplashScreen::Init()
{
	position = vec2_0;
	scale = glm::vec2(960, 640);

	m_screens = new std::vector <splash*> ;

	Load();

}

void SplashScreen::Load()
{

	m_screen = new Sprite();

	char **textures = new char*[1];

	textures[0] = "splash1.png";

	m_screen->Load(1, "data/SplashScreen/", textures);

	splash *t_splash = new splash();
	t_splash->alpha = 1.0f;
	t_splash->turn = true;
	t_splash->type = 0;
	m_screens->push_back(t_splash);
}

bool SplashScreen::Update()
{

	for (int index = 0; index < NUM_SCREENS; index++)
	{
		if (m_screens->at(index)->alpha > 0.1f)
			return false;
	}

	return true;
}

void SplashScreen::Render(Controller *ctrl, ScreenUniformData *u_data)
{
	
	for (int index = 0; index < NUM_SCREENS; index++)
	{
		
		

		u_data->ApplyMatrix(Translation(position)*Scale(scale));
		EffectsHandler::FadeOut(u_data, m_screen, index, m_screens->at(index)->alpha);
			
			

			if (m_screens->at(index)->alpha < 0.1f)
				finished = true;
			if (m_screens->at(index)->type == 2)
				if (ctrl->GetKey(GLFW_KEY_ENTER) == GLFW_PRESS)
					while (m_screens->at(index)->alpha > 0.1f)
						EffectsHandler::FadeOut(u_data, m_screen, index, m_screens->at(index)->alpha);

			

		

		u_data->SetAmbientLight(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	}


}