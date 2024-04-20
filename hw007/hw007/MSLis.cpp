#include <GL/gl.h>
#ifndef MSLIST_H
#define MSLIST_H

#include "Star.h" // Star 클래스를 사용하기 위해 포함

class MSList {
private:
    struct Node {
        Star data;
        Node* next;
        Node(const Star& star) : data(star), next(nullptr) {}
    };
    Node* head;

public:
    MSList(); // 생성자
    ~MSList(); // 소멸자
    void addStar(const Star& star); // 별을 리스트에 추가하는 메서드
    void drawStars(); // 모든 별을 그리는 메서드
};

#endif // MSLIST_H