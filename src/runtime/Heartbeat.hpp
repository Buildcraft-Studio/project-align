#ifndef HEARTBEAT_HPP 
#define HEARTBEAT_HPP

#include <string> // Needed for std::string

class Heartbeat
{
private:
    int pulse = 0;  // Initialize member variables
    bool isPulse = false;
    bool debug = false; // Using bool instead of int for debug
    // std::string name = "DebugOut";
    std::string debugOut; // The string to hold debug output

public:
    void runPulse(bool debug); // Function to run the pulse
    int getPulse() const;
    void setPulse(int pulse);
    bool getIsPulse() const;
    void setIsPulse(bool isPulse);
    std::string getDebugOut() const;
    void setDebugOut(const std::string& debugOut); // Setter for debugOut
};

#endif // HEARTBEAT_HPP
