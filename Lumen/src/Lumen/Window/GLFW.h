#pragma once

#include "Window.h"

#include "GLFW/glfw3.h"

namespace Lumen
{
	class GLFW : public Window
	{
	private:
		WindowData m_win_data{};
		GLFWwindow* m_glfw_window{};

		bool m_v_sync{};

		inline static bool is_initialized{};

	public:
		GLFW();
		~GLFW();

		void SetVSync(bool v_sync) override;
		bool GetVSync() override;

		std::pair<int, int> GetSize() override;

		void OnUpdate() override;

		void SetEventCallBackFunc(const std::function<void(Event&)>& event_callback) override;
		void Create(const WindowProp win_prop = WindowProp()) override;
	};
}
