#pragma once

#include "Lumen/Event/MouseEvent.h"
#include "Lumen/Event/WindowEvent.h"
#include "Lumen/Event/KeyEvent.h"

namespace Lumen
{
	struct WindowProp
	{
		int width{};
		int height{};
		std::string name{};

		WindowProp() : width(1280), height(720), name("Lumen") {}
	};

	struct WindowData
	{
		int width{};
		int height{};
		std::function<void(Event&)> event_callback{};
	};

	class Window
	{
	protected:

	public:
		Window() = default;
		virtual ~Window() = default;

		virtual void SetVSync(bool v_sync) = 0;
		virtual bool GetVSync() = 0;

		virtual std::pair<int, int> GetSize() = 0;

		virtual void OnUpdate() = 0;

		virtual void SetEventCallBackFunc(const std::function<void(Event&)>& event_callback) = 0;
		virtual void Create(const WindowProp win_prop = WindowProp()) = 0;
	};
}