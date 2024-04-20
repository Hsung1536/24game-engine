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
        // 별을 그리는 함수를 여기에 추가해야 합니다.
        // 예를 들어서, 콘솔에 별을 출력하는 코드를 사용할 수 있습니다.
        std::cout << "Drawing star at position (" << current->data.getX() << ", " << current->data.getY() << ")" << std::endl;
        current = current->next;
    }
}