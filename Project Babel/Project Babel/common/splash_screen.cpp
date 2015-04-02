#include "common.hpp"
#include "splash_screen.hpp"

#define NUM_SCREENS 3

void SplashScreen::Init()
{
	position = vec2_0;
	scale = glm::vec2(960, 640);

	m_screens = new std::vector <splash*> ;

	m_effects = new EffectsHandler();

	Load();

}

void SplashScreen::Load()
{

	m_screen = new Sprite();

	char **textures = new char*[3];

	textures[0] = "cerberus.png";
	textures[1] = "logo1.png";
	textures[2] = "splash1.png";

	m_screen->Load(3, "data/SplashScreen/", textures);
	for (int i = 0; i < NUM_SCREENS; i++)
	{
		splash *t_splash = new splash();
		t_splash->alpha = 1.0f;
		t_splash->turn = true;
		t_splash->type = 0;
		t_splash->finished = false;
		t_splash->speed = 1;
		m_screens->push_back(t_splash);
	}
	
}

bool SplashScreen::Update()
{

	for (int index = 0; index < NUM_SCREENS; index++)
	{
		if (m_screens->at(index)->finished == false)
			return false;
	}

	return true;
}

void SplashScreen::Render(Controller *ctrl, ScreenUniformData *u_data)
{
	
	if (currentFrame < NUM_SCREENS)
	{
		u_data->ApplyMatrix(Translation(vec2_0)*Scale(ctrl->GetWindowSize()));
		m_effects->FadeOut(ctrl,u_data, m_screen, currentFrame, m_screens->at(currentFrame)->speed, m_screens->at(currentFrame)->alpha);



		if (m_screens->at(currentFrame)->alpha < 0.1f)
		{
			m_screens->at(currentFrame)->finished = true;
			currentFrame++;
		}


		u_data->SetAmbientLight(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	}


}