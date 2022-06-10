#include"Application.h"
#include<iostream>

namespace Phoenix
{
	Application::Application()
	{

	}

	void Application::run()
	{
		for (auto layer : m_layerStack)
			layer->onUpdate();
	}

	void Application::PushLayer(Layer* layer)
	{
		m_layerStack.pushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_layerStack.pushOverlay(layer);
	}
}