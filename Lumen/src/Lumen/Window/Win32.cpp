#include "stdafx.h"
#include "Win32.h"

#include "Lumen/Logger.h"

namespace Lumen
{
	Win32::Win32()
	{
		LUMEN_CORE_ASSERT(!is_initialized, "Window Already Created");
	}

	Win32::~Win32()
	{
		DestroyWindow((HWND)m_handle);
	}

	void Win32::SetVSync(bool v_sync)
	{
	}

	bool Win32::GetVSync()
	{
		return false;
	}

	std::pair<int, int> Win32::GetSize()
	{
		return std::pair<int, int>();
	}

	void Win32::OnUpdate()
	{
		MSG msg{};

		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessageW(&msg);
		}
	}

	void Win32::SetEventCallBackFunc(const std::function<void(Event&)>& event_callback)
	{
		m_win_data.event_callback = event_callback;
	}

	void Win32::Create(const WindowProp win_prop)
	{
		m_win_data.width = win_prop.width;
		m_win_data.height = win_prop.height;

		WNDCLASSEX wc = {};
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		wc.lpfnWndProc = DefWindowProc;
		wc.hInstance = GetModuleHandle(NULL);
		wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.lpszClassName = L"LumenWindowClass";

		LUMEN_CORE_ASSERT(RegisterClassEx(&wc), "Failed To Register Window Class - Win32");

		RECT rc = { 0, 0, win_prop.width, win_prop.height };
		AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, false);

		std::wstring wname(win_prop.name.begin(), win_prop.name.end());

		m_handle = CreateWindowEx(
			NULL,
			wc.lpszClassName,
			wname.c_str(),
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT,
			rc.right - rc.left, rc.bottom - rc.top,
			NULL, NULL,
			wc.hInstance, NULL
		);

		LUMEN_CORE_ASSERT(m_handle, "Failed To Create Window Handle - Win32");

		ShowWindow((HWND)m_handle, SW_SHOW);
		UpdateWindow((HWND)m_handle);


		LUMEN_CORE_INFO("Window Created Successfully - Win32");
	}
}