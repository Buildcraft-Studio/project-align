#include <iostream>

class ui {
private:
    int x, y;

public:
    ui() : x(0), y(0) {}
    void set(int x, int y) {
        this->x = x;
        this->y = y;
    }
    void display() {
        std::cout << "x: " << x << ", y: " << y << "\n";
    }
};

class uiResolution {
private:
    ui resolutionUI;

public:
    uiResolution(int x, int y) {
        resolutionUI.set(x, y);
    }
    void display() {
        resolutionUI.display();
    }
};

class uiBox {
private:
    int width, height;

public:
    uiBox(int w, int h) : width(w), height(h) {}
    void draw() {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                    std::cout << "*";
                else
                    std::cout << " ";
            }
            std::cout << "\n";
        }
    }
};

class uiLine {
private:
    int x1, y1, x2, y2;

public:
    uiLine(int startX, int startY, int endX, int endY)
        : x1(startX), y1(startY), x2(endX), y2(endY) {}
    void draw() {
        std::cout << "Drawing a line from (" << x1 << ", " << y1
                  << ") to (" << x2 << ", " << y2 << ").\n";
    }
};