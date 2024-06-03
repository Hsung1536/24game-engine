#include <GLFW/glfw3.h>
#include <iostream>

// 상자 구조체 정의
struct Box {
    float x, y;       // 상자의 좌상단 위치
    float width, height; // 상자의 너비와 높이
    float velocityX;   // x축 방향의 속도
    float velocityY;   // y축 방향의 속도
};

// 충돌 감지 함수
bool checkCollision(const Box& box1, const Box& box2) {
    return (box1.x < box2.x + box2.width &&
        box1.x + box1.width > box2.x &&
        box1.y < box2.y + box2.height &&
        box1.y + box1.height > box2.y);
}

// 상자를 그리는 함수
void drawBox(const Box& box, float r, float g, float b) {
    glColor3f(r, g, b);  // 색상 설정
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

    // 뷰포트 설정
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    // 투영 행렬 설정
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 600, 0, -1, 1);  // 좌표계를 창 크기에 맞게 설정

    // 모델뷰 행렬 설정
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    Box bigBox = { 100.0f, 100.0f, 1000.0f, 20.0f }; // 큰 상자의 크기를 1000x20으로 설정
    Box smallBox = { 115.0f, 85.0f, 15.0f, 15.0f }; // 작은 상자의 크기를 15x15으로 설정

    bool spacePressed = false;
    bool spaceReleased = true;
    float jumpSpeed = 5.0f / 6.0f * 3.0f; // 점프 속도를 2배 낮춤
    float gravity = 0.2f / 6.0f * 3.0f / 2.0f;   // 중력 가속도를 2배 낮춤
    float moveSpeed = 3.0f / 6.0f; // 좌우 이동 속도 설정

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // 큰 상자를 흰색으로 그림
        drawBox(bigBox, 1.0f, 1.0f, 1.0f);

        // 작은 상자를 녹색으로 그림
        drawBox(smallBox, 0.0f, 1.0f, 0.0f);

        // 스페이스바가 눌렸을 때 작은 상자의 y 속도를 위로 설정하여 점프하게 함
        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && !spacePressed && spaceReleased) {
            smallBox.velocityY = -jumpSpeed;
            spacePressed = true;
            spaceReleased = false;
        }
        // 스페이스바를 누르지 않았을 때 작은 상자가 점프 중이면 중력을 적용함
        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_RELEASE) {
            spacePressed = false;
            spaceReleased = true;
        }
        // 중력에 따라 작은 상자의 y 속도를 증가시키고, 위치를 이동시킴
        smallBox.velocityY += gravity;
        smallBox.y += smallBox.velocityY;

        // 바닥에 닿으면 y 속도를 0으로 설정하여 더 이상 아래로 내려가지 않도록 함
        if (smallBox.y + smallBox.height >= 100.0f) {
            smallBox.y = 100.0f - smallBox.height;
            smallBox.velocityY = 0.0f;
        }

        // 좌우 화살표 키를 누를 때 작은 상자의 x 속도를 설정하여 좌우로 이동함
        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
            smallBox.velocityX = -moveSpeed;
        }
        else if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
            smallBox.velocityX = moveSpeed;
        }
        else {
            smallBox.velocityX = 0.0f;
        }
        // 작은 상자의 x 위치를 이동시킴
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
