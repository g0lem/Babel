#pragma once



class SplashScreen: public Aaether2D
{
	Sprite *m_screen;
	glm::vec2 position;
	glm::vec2 scale;

	struct splash
	{
		float alpha;
		bool turn;
		int type;
		float speed;
		bool finished;


	};

	int currentFrame;

	EffectsHandler *m_effects;

	std::vector<splash*> *m_screens;

	bool finished = false;

public:
	
	inline SplashScreen(){ this->Init(); }

	void Init();

	void Load();

	void Render(Controller *ctrl, ScreenUniformData *u_data);

	inline std::vector<splash*> *GetSplashVector(){ return this->m_screens; }

	inline int GetCurrentFrame(){ return this->currentFrame; }

	inline void SkipFrame(){ 
			this->m_screens->at(currentFrame)->speed *= 5;
		 }

	void RenderEnd(){
		this->m_screen->Render(3);
	}

	bool Update();

	
};

