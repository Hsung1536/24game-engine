#include <GL/gl.h>
#ifndef MSLIST_H
#define MSLIST_H

#include "Star.h" // Star Ŭ������ ����ϱ� ���� ����

class MSList {
private:
    struct Node {
        Star data;
        Node* next;
        Node(const Star& star) : data(star), next(nullptr) {}
    };
    Node* head;

public:
    MSList(); // ������
    ~MSList(); // �Ҹ���
    void addStar(const Star& star); // ���� ����Ʈ�� �߰��ϴ� �޼���
    void drawStars(); // ��� ���� �׸��� �޼���
};

#endif // MSLIST_H