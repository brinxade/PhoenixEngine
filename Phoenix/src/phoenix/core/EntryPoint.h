#include"Application.h"

extern Phoenix::Application* createApplication(Phoenix::ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	
	auto app = Phoenix::createApplication({argc, argv});
	app->run();
	delete app;

	return 0;
}