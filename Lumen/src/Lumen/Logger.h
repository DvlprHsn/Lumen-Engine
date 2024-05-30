#pragma once

#include "Defines.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Lumen
{
	class LUMEN_API Logger
	{
	private:
		std::shared_ptr<spdlog::logger> m_core_logger{ nullptr };
		std::shared_ptr<spdlog::logger> m_client_logger{ nullptr };

		void Init();
		void ShutDown();

		Logger();
	public:
		Logger(const Logger&) = delete;
		Logger operator=(const Logger&) = delete;

		~Logger();

		static Logger& Instance();

		std::shared_ptr<spdlog::logger>GetCoreLogger() { return m_core_logger; }
		std::shared_ptr<spdlog::logger>GetClientLogger() { return m_client_logger; }
	};
}

