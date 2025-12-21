#include <iostream>
using namespace std;

#include "./utility/logger.h"
using namespace bclog::utility;

int main()
{
    Logger::instance()->open("./test.log");
    Logger::instance()->log(Logger::DEBUG, __FILE__, __LINE__, "hello world");
    return 0;
}