#include "stdafx.h"
#include "Application.h"

#include "Logger.h"

namespace Lumen
{
	void Application::SetupWindow()
	{

#ifdef LUMEN_PLATFORM_WIN32
		m_window = std::make_shared<GLFW>();
#elif defined LUMEN_PLATFORM_WIN64
		m_window = std::make_shared<GLFW>();
#elif defined LUMEN_PLATFORM_MACOS
		m_window = std::make_shared<GLFW>();
#elif defined LUMEN_PLATFORM_LINUX
		m_window = std::make_shared<GLFW>();
#else
#error "Unknown Platform!"
#endif

		m_window->Create();
		m_window->SetEventCallBackFunc(std::bind(&Application::OnEvent, this, std::placeholders::_1));

	}

	bool Application::OnWindowClose(WindowCloseEvent& ev)
	{
		m_shutdown = true;
		return true;
	}

	Application::Application()
	{
		SetupWindow();
	}

	Application::~Application()
	{
	}

	void Application::PushLayer(Layer* layer)
	{
		m_layer_stack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_layer_stack.PushOverlay(overlay);
	}

	void Application::Run()
	{
		while (!m_shutdown)
		{
			for (Layer* layer : m_layer_stack)
			{
				layer->OnUpdate();
			}

			m_window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& ev)
	{
		EventDispatcher dispatcher(ev);
		
		dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));

		for (auto it = m_layer_stack.rbegin(); it != m_layer_stack.rend(); ++it)
		{
			Layer* layer = *it;
			layer->OnEvent(ev);
			if (ev.m_is_handled)
				break;
		}
	}
}