#ifndef STAR_H
#define STAR_H

#include <iostream>

class Star {
private:
    int x;
    int y;
    char symbol;
public:
    Star(int x, int y, char symbol) : x(x), y(y), symbol(symbol) {}
    void draw() const {
        std::cout << "Drawing star at position (" << x << ", " << y << ") with symbol " << symbol << std::endl;
    }
    int getX() const { return x; } // x 좌표값을 반환하는 getter 함수
    int getY() const { return y; } // y 좌표값을 반환하는 getter 함수
};

#endif // STAR_H