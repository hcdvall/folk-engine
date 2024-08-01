#include "Logger.h"
#include <iostream>
#include <ctime>

std::vector<LogEntry> Logger::messages;

std::string Logger::GetCurrentTime()
{
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);
    return std::string(buffer);
}

void Logger::Log(const std::string &message)
{
    LogEntry logEntry;
    logEntry.type = LOG_INFO;
    logEntry.message = "[" + GetCurrentTime() + "] [LOG]: " + message;
    std::cout << "\033[92m" << logEntry.message << "\033[0m" << std::endl;
    messages.push_back(logEntry);
}

void Logger::Error(const std::string &message)
{
    LogEntry logEntry;
    logEntry.type = LOG_ERROR;
    logEntry.message = "[" + GetCurrentTime() + "] [ERROR]: " + message;
    std::cerr << "\033[91m" << logEntry.message << "\033[0m" << std::endl;
    messages.push_back(logEntry);
}
