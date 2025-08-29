#include "exitCode.hpp"
#include <iostream>
#include <cstdlib>

namespace Runtime {

void handleException(const std::exception& e, int exitCode) {
    std::cerr << "Exception: " << e.what() << std::endl;
    std::exit(exitCode);
}

void handleUnknownException(int exitCode) {
    std::cerr << "Unknown exception occurred." << std::endl;
    std::exit(exitCode);
}

} // namespace Runtime