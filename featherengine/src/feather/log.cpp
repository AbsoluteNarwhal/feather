#include "feather/log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace ft {
    std::shared_ptr<spdlog::logger> LoggerManager::coreLogger;
    std::shared_ptr<spdlog::logger> LoggerManager::clientLogger;

    void LoggerManager::init(const std::string& clientLoggerName) {
        coreLogger = spdlog::stdout_color_mt("FEATHER");
        clientLogger = spdlog::stdout_color_mt(clientLoggerName);

        coreLogger->set_pattern("%^[%T] %n: %v%$");
        clientLogger->set_pattern("%^[%T] %n: %v%$");
        
        coreLogger->set_level(spdlog::level::trace);
        clientLogger->set_level(spdlog::level::trace);
    }
}