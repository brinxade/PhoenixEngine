#include <phoenix.h>
#include <phoenix/core/EntryPoint.h>
#include "SandboxLayer.h"

class Sandbox : public Phoenix::Application
{
public:
	Sandbox(Phoenix::ApplicationCommandLineArgs args)
	{
		PushLayer(new SandboxLayer());
	}

	~Sandbox()
	{
	}
};

Phoenix::Application* Phoenix::createApplication(Phoenix::ApplicationCommandLineArgs args)
{
	return new Sandbox(args);
}