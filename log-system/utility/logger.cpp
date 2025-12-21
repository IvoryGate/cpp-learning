#include "logger.h"
using namespace bclog::utility;

#include <time.h>
#include <string.h>
#include <stdexcept>
#include <iostream>

using namespace std;

const char * Logger::s_level[LEVEL_COUNT] = {
    "DEBUG",
    "INFO",
    "WARN",
    "ERROR",
    "FATAL"
};

Logger * Logger::m_instance = NULL;

Logger::Logger()
{

}

Logger::~Logger()
{

}

Logger * Logger::instance()
{
    if (m_instance == NULL)
    {
        m_instance = new Logger();
    }
    return m_instance;
}

void Logger::open(const string & filename)
{
    m_filename = filename;
    m_fout.open(filename, ios::app);
    if (m_fout.fail())
    {
        throw std::logic_error("open file failed" + filename);
    };
}

void Logger::close()
{
    m_fout.close();
}

void Logger::log(Level level, const char * file, int line, const char * format, ...)
{
    if (m_fout.fail())
    {
        throw std::logic_error("open file failed " + m_filename);
    }
    time_t ticks = time(nullptr);
    struct tm * ptm = localtime(&ticks);
    char timestamp[32];
    memset(timestamp, 0, sizeof(timestamp));
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", ptm);
    std::cout << timestamp << std::endl;
    std::cout << file << std::endl;
    std::cout << line << std::endl;
    std::cout << format << std::endl;
}