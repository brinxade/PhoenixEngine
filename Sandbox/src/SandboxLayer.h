#pragma once
#include<phoenix/core/Layer.h>

class SandboxLayer :public Phoenix::Layer
{
public:
	SandboxLayer():Phoenix::Layer("test layer") {}

private:
	void onUpdate()
	{
		
	}

	void onDetach()
	{
		
	}
};