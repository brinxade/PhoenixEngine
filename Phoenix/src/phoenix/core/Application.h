#pragma once
#include<Phoenix/core/LayerStack.h>

int main(int argc, char** argv);

namespace Phoenix
{
	struct ApplicationCommandLineArgs
	{
		int count = 0;
		char** args = nullptr;

		const char* operator[](int index) const
		{
			if(index < count)
				return args[index];
			return nullptr;
		}
	};

	class Application
	{
	private:
		LayerStack m_layerStack;
		bool m_isRunning = true;
		ApplicationCommandLineArgs m_cmdArgs;

	private:
		void run();
		friend int ::main(int argc, char** argv);

	public:
		Application();
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	};

	Application* createApplication(ApplicationCommandLineArgs args);
}