#pragma once

#include "Window.h"

namespace Lumen
{
	class Win32 : public Window
	{
	private:
		WindowData m_win_data{}; 
		void* m_handle{};

		inline static bool is_initialized{};

	public:
		Win32();
		~Win32();

		void SetVSync(bool v_sync) override;
		bool GetVSync() override;

		std::pair<int, int> GetSize() override;

		void OnUpdate() override;

		void SetEventCallBackFunc(const std::function<void(Event&)>& event_callback) override;
		void Create(const WindowProp win_prop = WindowProp()) override;
	};
}
