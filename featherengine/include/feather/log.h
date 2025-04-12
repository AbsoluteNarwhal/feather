#pragma once
#include "spdlog/spdlog.h"
#include <string>
#include <memory>

namespace ft {
    class LoggerManager {
    private:
        static std::shared_ptr<spdlog::logger> coreLogger;
        static std::shared_ptr<spdlog::logger> clientLogger;
    
    public:
        static void init(const std::string& clientLoggerName);
        inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return coreLogger; }
        inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return clientLogger; }
    };
}

#define FT_LOG(...) ft::LoggerManager::getClientLogger()->trace(__VA_ARGS__)
#define FT_LOG_SUCCESS(...) ft::LoggerManager::getClientLogger()->info(__VA_ARGS__)
#define FT_LOG_WARN(...) ft::LoggerManager::getClientLogger()->warn(__VA_ARGS__)
#define FT_LOG_ERROR(...) ft::LoggerManager::getClientLogger()->error(__VA_ARGS__)
#define FT_LOG_CRITICAL(...) ft::LoggerManager::getClientLogger()->critical(__VA_ARGS__)
#define FT_ASSERT(x, ...) if(!(x)) { FT_LOG_CRITICAL(__VA_ARGS__); __debugbreak(); }

#define FT_CORE_LOG(...) LoggerManager::getCoreLogger()->trace(__VA_ARGS__)
#define FT_CORE_LOG_SUCCESS(...) LoggerManager::getCoreLogger()->info(__VA_ARGS__)
#define FT_CORE_LOG_WARN(...) LoggerManager::getCoreLogger()->warn(__VA_ARGS__)
#define FT_CORE_LOG_ERROR(...) LoggerManager::getCoreLogger()->error(__VA_ARGS__)
#define FT_CORE_LOG_CRITICAL(...) LoggerManager::getCoreLogger()->critical(__VA_ARGS__)
#define FT_CORE_ASSERT(x, ...) if(!(x)) { FT_CORE_LOG_CRITICAL(__VA_ARGS__); __debugbreak(); }