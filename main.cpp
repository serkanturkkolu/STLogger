#include "stlogger.h"

using namespace std;


int main()
{
    STLogger logger("test.log");
    logger.log("Hello world!");
    return 0;
}

