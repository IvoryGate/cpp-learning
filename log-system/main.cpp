#include <iostream>
using namespace std;

#include "./utility/logger.h"
using namespace bclog::utility;

int main()
{
    Logger::instance()->open("./test.log");
    return 0;
}