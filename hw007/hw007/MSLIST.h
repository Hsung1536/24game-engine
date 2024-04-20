#ifndef MSLIST_H
#define MSLIST_H

#include "Star.h"

class MSList {
private:
    struct Node {
        Star data;
        Node* next;
        Node(const Star& star) : data(star), next(nullptr) {}
    };
    Node* head;

public:
    MSList();
    ~MSList();
    void addStar(const Star& star);
    void drawStars();
};

#endif // MSLIST_H