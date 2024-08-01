#ifndef LOGGER_H
#define LOGGER_H

#include <vector>
#include <string>

enum LogType
{
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
};

struct LogEntry
{
    LogType type;
    std::string message;
};

class Logger
{
private:
    static std::string GetCurrentTime();

public:
    Logger(/* args */);
    ~Logger();

    static std::vector<LogEntry> messages;
    static void Log(const std::string& message);
    static void Error(const std::string& message);
};



#endif
