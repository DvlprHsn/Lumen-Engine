#include "stdafx.h"
#include "GLFW.h"

#include "Lumen/Logger.h"

namespace Lumen
{
	GLFW::GLFW()
	{
		LUMEN_CORE_ASSERT(!is_initialized, "Window Already Created");
	}

	GLFW::~GLFW()
	{
		glfwDestroyWindow(m_glfw_window);
		glfwTerminate();
	}

	void GLFW::SetVSync(bool v_sync)
	{
		m_v_sync = v_sync;
		glfwSwapInterval(v_sync);
	}

	bool GLFW::GetVSync()
	{
		return m_v_sync;
	}

	std::pair<int, int> GLFW::GetSize()
	{
		return std::pair<int, int>(m_win_data.width, m_win_data.height);
	}

	void GLFW::OnUpdate()
	{
		glfwSwapBuffers(m_glfw_window);
		glfwPollEvents();
	}

	void GLFW::SetEventCallBackFunc(const std::function<void(Event&)>& event_callback)
	{
		m_win_data.event_callback = event_callback;
	}

	void GLFW::Create(const WindowProp win_prop)
	{
		LUMEN_CORE_ASSERT(glfwInit(), "GLFW Failed To Initialize")

		int major, minor, rev;
		glfwGetVersion(&major, &minor, &rev);

		LUMEN_CORE_INFO("GLFW Version : {0}.{1}.{2}", major, minor, rev);

		m_glfw_window = glfwCreateWindow(win_prop.width, win_prop.height, win_prop.name.c_str(), NULL, NULL);
		LUMEN_CORE_ASSERT(m_glfw_window, "Failed To Create Window - GLFW")

		glfwMakeContextCurrent(m_glfw_window);

		glfwSetWindowUserPointer(m_glfw_window, &m_win_data);

		glfwSetCursorPosCallback(m_glfw_window, [](GLFWwindow* window, double x, double y)
			{
				WindowData* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));
				
				data->event_callback(MouseMoveEvent(x, y));
			});

		glfwSetKeyCallback(m_glfw_window, [](GLFWwindow* window, int key, int scancode, int action, int release)
			{
				WindowData* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));

				if (action == GLFW_PRESS)
				{
					data->event_callback(KeyPressedEvent(key, 0));
				}
				else if (action == GLFW_REPEAT)
				{
					data->event_callback(KeyPressedEvent(key, 1));
				}
				else if (action == GLFW_RELEASE)
				{
					data->event_callback(KeyReleaseEvent(key));
				}
			});

		glfwSetMouseButtonCallback(m_glfw_window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));

				if (action == GLFW_PRESS)
				{
					data->event_callback(MouseClickEvent(button, 0));
				}
				else if (action == GLFW_REPEAT)
				{
					data->event_callback(MouseClickEvent(button, 1));
				}
				else if (action == GLFW_RELEASE)
				{
					data->event_callback(MouseReleaseEvent(button));
				}
			});

		glfwSetWindowCloseCallback(m_glfw_window, [](GLFWwindow* window)
			{
				WindowData* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));

				data->event_callback(WindowCloseEvent());
			});

		glfwSetWindowSizeCallback(m_glfw_window, [](GLFWwindow* window, int w, int h)
			{
				WindowData* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));

				data->width = w;
				data->height = h;

				data->event_callback(WindowResizeEvent(w, h));
			});

		glfwSetErrorCallback([](int error, const char* discription)
			{
				LUMEN_CORE_ERROR("GLFW Error ({0}) : {1}", error, discription);
			});


		LUMEN_CORE_INFO("Window Created Successfully - GLFW");
	}
}