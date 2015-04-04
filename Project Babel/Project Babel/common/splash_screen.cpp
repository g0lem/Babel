#include "common.hpp"

#define NUM_SCREENS 4

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

	char **textures = new char*[NUM_SCREENS];
	textures[0] = "1st.png";
	textures[1] = "logo1.png";
	textures[2] = "logo1.png";
	textures[3] = "3rd.png";

	m_screen->Load(NUM_SCREENS, "data/SplashScreen/", textures);
	for (int i = 0; i < NUM_SCREENS - 2  ; i++)
	{
		splash *t_splash = new splash();
		t_splash->alpha = 0;
		t_splash->turn = true;
		t_splash->type = 1;
		t_splash->finished = false;
		t_splash->speed = 1;
		m_screens->push_back(t_splash);
	}

	splash *t_splash = new splash();
	t_splash->alpha = 1;
	t_splash->turn = true;
	t_splash->type = 0;
	t_splash->finished = false;
	t_splash->speed = 1;
	m_screens->push_back(t_splash);

	t_splash = new splash();
	t_splash->alpha = 1;
	t_splash->turn = true;
	t_splash->type = 2;
	t_splash->finished = false;
	t_splash->speed = 1;
	m_screens->push_back(t_splash);
	
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

		if (m_screens->at(currentFrame)->type == 0)
		{
			m_effects->FadeOut(ctrl, u_data, m_screen, currentFrame, m_screens->at(currentFrame)->speed, m_screens->at(currentFrame)->alpha);


			if (m_screens->at(currentFrame)->alpha < 0.1f)
			{
				m_screens->at(currentFrame)->finished = true;
				currentFrame++;
			}
		}
		else if (m_screens->at(currentFrame)->type == 1)
		{
			m_effects->FadeIn(ctrl, u_data, m_screen, currentFrame, m_screens->at(currentFrame)->speed, m_screens->at(currentFrame)->alpha);


			if (m_screens->at(currentFrame)->alpha > 0.9f)
			{
				m_screens->at(currentFrame)->finished = true;
				currentFrame++;
			}
		}
		else if (m_screens->at(currentFrame)->type == 2)
		{	
			
			m_effects->Blink(ctrl, u_data, m_screen, currentFrame, m_screens->at(currentFrame)->speed, m_screens->at(currentFrame)->alpha, m_screens->at(currentFrame)->turn);



			if (ctrl->GetKeyOnce(GLFW_KEY_ENTER) == GLFW_PRESS || ctrl->GetKeyOnce(GLFW_KEY_SPACE) == GLFW_PRESS)
			{
				if (m_screens->at(currentFrame)->alpha > 0.1f)
					m_screens->at(currentFrame)->type = 1;
				else if (m_screens->at(currentFrame)->alpha < 0.9f)
					m_screens->at(currentFrame)->type = 0;
			}
		}
		


		u_data->SetAmbientLight(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	}


}