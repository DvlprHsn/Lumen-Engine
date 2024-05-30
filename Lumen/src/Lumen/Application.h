#pragma once

#include "Window/Win32.h"
#include "Window/GLFW.h"

#include "Layers/LayerStack.h"

namespace Lumen
{
	class LUMEN_API Application
	{
	private:
		std::shared_ptr<Window> m_window{};
		bool m_shutdown{};
		LayerStack m_layer_stack{};

		void SetupWindow();
		bool OnWindowClose(WindowCloseEvent& ev);

	public:
		Application();
		virtual ~Application();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	
		void Run();
		void OnEvent(Event& ev);
	};

	Application* CreateApplication();
}