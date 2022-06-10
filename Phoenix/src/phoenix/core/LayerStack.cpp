#include "LayerStack.h"
#include<algorithm>

namespace Phoenix
{
	LayerStack::~LayerStack()
	{
		for (auto layer : m_layers) {
			layer->onDetach();
			delete layer;
		}
	}

	void LayerStack::pushLayer(Layer* layer)
	{
		m_layers.emplace(m_layers.begin() + m_layerInsertIndex, layer);
		m_layerInsertIndex++;
	}

	void LayerStack::popLayer(Layer* layer)
	{
		auto it = std::find(m_layers.begin(), m_layers.end(), layer);

		if (it != m_layers.end())
		{
			layer->onDetach();
			m_layers.erase(it);
			m_layerInsertIndex--;
		}
	}

	void LayerStack::pushOverlay(Layer* layer)
	{
		m_layers.push_back(layer);
	}

	void LayerStack::popOverlay(Layer* layer)
	{
		auto it = std::find(m_layers.begin(), m_layers.end(), layer);

		if (it != m_layers.end())
		{
			layer->onDetach();
			m_layers.erase(it);
		}
	}
}