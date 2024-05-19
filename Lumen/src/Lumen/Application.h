#pragma once

#include "Defines.h"

namespace Lumen
{
	class LUMEN_API Application
	{
	private:
	
	public:
		Application() = default;
		virtual ~Application() = default;
	
		void Run();
	};

	Application* CreateApplication();
}