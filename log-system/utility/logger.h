#pragma once
#include <string>
#include <fstream>
using namespace std;

namespace bclog
{
    namespace utility
    {
        class Logger
        {
            public:
                enum Level
                {
                    DEBUG = 0,
                    INFO,
                    WARN,
                    ERROR,
                    FATAL,
                    LEVEL_COUNT
                };
                static Logger * instance();
                void open(const string & filename);
                void close();
                // void log(Level level, const char * file, int line, const char * format, ...);
            private:
                Logger();
                ~Logger();
            private:
                string m_filename;
                ofstream m_fout;
                static const char * s_level[LEVEL_COUNT];
                static Logger * m_instance;
        };
    }
}