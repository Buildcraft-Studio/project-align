#ifndef UI_H
#define UI_H

#include <iostream>

// Declare the `ui` class.
class ui {
private:
    int x, y;

public:
    ui();
    void set(int x, int y);
    void display();
};

// Declare the `uiResolution` class.
class uiResolution {
private:
    ui resolutionUI;

public:
    uiResolution(int x, int y);
    void display();
};

#endif // UI_H
