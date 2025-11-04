#pragma once

#include "enginepch.h"
#include "Layer.h"

namespace Engine
{

	class LayerStack
	{
		public:
			LayerStack(/* args */);
			~LayerStack();

			void	PushLayer(Layer* layer);
			void	PushOverLay(Layer* overlay);
			void	PopLayer(Layer* layer);
			void	PopOverLay(Layer* overlay);

			std::vector<Layer*>::iterator	begin() { return m_Layers.begin(); };
			std::vector<Layer*>::iterator	end() { return m_Layers.end(); };
		private:
			std::vector<Layer*>				m_Layers;
			std::vector<Layer*>::iterator	m_LayerInsert;
	};


}