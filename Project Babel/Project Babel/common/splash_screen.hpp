#pragma once



class SplashScreen: public Aaether2D
{
	

public:
	Sprite *m_screen;
	glm::vec2 position;
	glm::vec2 scale;

	struct splash
	{
		float alpha;
		bool turn;
		int type;


	};

	std::vector<splash*> *m_screens;

	bool finished = false;
	void Init();

	void Load();

	void Render(Controller *ctrl, ScreenUniformData *u_data);

	bool Update();

	
};

