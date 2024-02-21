#include <plog/Log.h>
#include "plog/Initializers/RollingFileInitializer.h"

int main() {
    plog::init(plog::debug, "20220616/Hello.txt");

    PLOGD << "Hello log!"; // short macro
    PLOG_DEBUG << "Hello log!"; // long macro
    PLOG(plog::debug) << "Hello log!"; // function-style macro

    return 0;
}