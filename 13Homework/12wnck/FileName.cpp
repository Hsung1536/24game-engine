#include <GLFW/glfw3.h>
#include <iostream>

// ���� ����ü ����
struct Box {
    float x, y;       // ������ �»�� ��ġ
    float width, height; // ������ �ʺ�� ����
    float velocityX;   // x�� ������ �ӵ�
    float velocityY;   // y�� ������ �ӵ�
};

// �浹 ���� �Լ�
bool checkCollision(const Box& box1, const Box& box2) {
    return (box1.x < box2.x + box2.width &&
        box1.x + box1.width > box2.x &&
        box1.y < box2.y + box2.height &&
        box1.y + box1.height > box2.y);
}

// ���ڸ� �׸��� �Լ�
void drawBox(const Box& box, float r, float g, float b) {
    glColor3f(r, g, b);  // ���� ����
    glBegin(GL_QUADS);
    glVertex2f(box.x, box.y);
    glVertex2f(box.x + box.width, box.y);
    glVertex2f(box.x + box.width, box.y + box.height);
    glVertex2f(box.x, box.y + box.height);
    glEnd();
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Box Collider Example", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // ����Ʈ ����
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    // ���� ��� ����
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 600, 0, -1, 1);  // ��ǥ�踦 â ũ�⿡ �°� ����

    // �𵨺� ��� ����
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    Box bigBox = { 100.0f, 100.0f, 1000.0f, 20.0f }; // ū ������ ũ�⸦ 1000x20���� ����
    Box smallBox = { 115.0f, 85.0f, 15.0f, 15.0f }; // ���� ������ ũ�⸦ 15x15���� ����

    bool spacePressed = false;
    bool spaceReleased = true;
    float jumpSpeed = 5.0f / 6.0f * 3.0f; // ���� �ӵ��� 2�� ����
    float gravity = 0.2f / 6.0f * 3.0f / 2.0f;   // �߷� ���ӵ��� 2�� ����
    float moveSpeed = 3.0f / 6.0f; // �¿� �̵� �ӵ� ����

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // ū ���ڸ� ������� �׸�
        drawBox(bigBox, 1.0f, 1.0f, 1.0f);

        // ���� ���ڸ� ������� �׸�
        drawBox(smallBox, 0.0f, 1.0f, 0.0f);

        // �����̽��ٰ� ������ �� ���� ������ y �ӵ��� ���� �����Ͽ� �����ϰ� ��
        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && !spacePressed && spaceReleased) {
            smallBox.velocityY = -jumpSpeed;
            spacePressed = true;
            spaceReleased = false;
        }
        // �����̽��ٸ� ������ �ʾ��� �� ���� ���ڰ� ���� ���̸� �߷��� ������
        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_RELEASE) {
            spacePressed = false;
            spaceReleased = true;
        }
        // �߷¿� ���� ���� ������ y �ӵ��� ������Ű��, ��ġ�� �̵���Ŵ
        smallBox.velocityY += gravity;
        smallBox.y += smallBox.velocityY;

        // �ٴڿ� ������ y �ӵ��� 0���� �����Ͽ� �� �̻� �Ʒ��� �������� �ʵ��� ��
        if (smallBox.y + smallBox.height >= 100.0f) {
            smallBox.y = 100.0f - smallBox.height;
            smallBox.velocityY = 0.0f;
        }

        // �¿� ȭ��ǥ Ű�� ���� �� ���� ������ x �ӵ��� �����Ͽ� �¿�� �̵���
        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
            smallBox.velocityX = -moveSpeed;
        }
        else if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
            smallBox.velocityX = moveSpeed;
        }
        else {
            smallBox.velocityX = 0.0f;
        }
        // ���� ������ x ��ġ�� �̵���Ŵ
        smallBox.x += smallBox.velocityX;

        // Swap buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
