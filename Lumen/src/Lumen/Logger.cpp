#include "stdafx.h"
#include "Logger.h"

namespace Lumen
{
    void Logger::Init()
    {
        spdlog::set_pattern("%^[%T] %n : %v%$");
        
        m_client_logger = spdlog::stderr_color_mt("Client");
        m_core_logger = spdlog::stdout_color_mt("Core");
        
        m_client_logger->set_level(spdlog::level::trace);
        m_core_logger->set_level(spdlog::level::trace);
    }

    void Logger::ShutDown()
    {
        spdlog::shutdown();
    }

    Logger::Logger()
    {
        Init();
    }

    Logger::~Logger()
    {
        ShutDown();
    }

    Logger& Logger::GetInstance()
    {
        static Logger instance;
        return instance;
    }
}