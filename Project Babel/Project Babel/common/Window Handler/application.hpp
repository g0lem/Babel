//1




#ifndef APPLICATION
#define APPLICATION




class Application : private Controller
{



	GameRender * g_render;

	SplashScreen *s_screen;

	GameObject * g_object;

	SoundManager * sound_m;

	Tooltip *t_tip;

	UIHandler * ui;

	FontManager * f_m;

public:

	


	inline Application() { this->Init(); }



	inline ~Application() { this->Terminate(); }


	void Init();



	void Run();


	void Terminate();


};

#endif