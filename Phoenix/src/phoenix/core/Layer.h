#pragma once
#include<string>

namespace Phoenix
{
	class Layer
	{
	private:
		std::string m_layerName;

	public:
		Layer(std::string layerName) : m_layerName(layerName) {}

		virtual void onEvent() {}
		virtual void onUpdate() {}
		virtual void onAttach() {}
		virtual void onDetach() {}
	};
}
