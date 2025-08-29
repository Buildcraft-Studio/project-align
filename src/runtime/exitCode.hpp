#ifndef EXITCODE_HPP
#define EXITCODE_HPP
#pragma once
#include <exception>

namespace Runtime {
    void handleException(const std::exception& e, int exitCode = 1);
    void handleUnknownException(int exitCode = 1);
}
#endif // EXITCODE_HPP