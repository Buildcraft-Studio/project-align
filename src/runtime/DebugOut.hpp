#ifndef DEBUGOUT_HPP
#define DEBUGOUT_HPP

#include <string>
#include <iostream>

class DebugOut

{
private:
    int enableDebugModule;
    std::string DebugOut;

public:
    void setDebugOut(std::string DebugOut);
    void printOut();
    int getEnableDebugModule();
    void setEnableDebugModule(int enableDebugModule);
};
#endif // DEBUGOUT_HPP