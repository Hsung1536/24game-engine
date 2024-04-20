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
    int getX() const { return x; } // x ��ǥ���� ��ȯ�ϴ� getter �Լ�
    int getY() const { return y; } // y ��ǥ���� ��ȯ�ϴ� getter �Լ�
};

#endif // STAR_H