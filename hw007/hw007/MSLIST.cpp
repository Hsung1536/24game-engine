#include <GL/gl.h>
#include "MSList.h"
#include <iostream>

MSList::MSList() : head(nullptr) {}

MSList::~MSList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void MSList::addStar(const Star& star) {
    Node* newNode = new Node(star);
    newNode->next = head;
    head = newNode;
}

void MSList::drawStars() {
    Node* current = head;
    while (current) {
        current->data.draw();
        current = current->next;
    }
}