//Checked 1

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "common.hpp"



int main(int argc, char *argv[])
{

	Application*app = new Application();

	app->Run();

	delete app;

	


	return 0;



}
