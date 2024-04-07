#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <iostream>

double translateX = 0.0;
double translateY = 0.0;
double scale = 1.0;
double lastX = 0.0;
bool leftButtonPressed = false;
bool rightButtonPressed = false;

void errorCallback(int error, const char* description)
{
    std::cerr << "GLFW Error: " << description << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void renderStar()
{
    // 별 그리기
    glBegin(GL_TRIANGLES);
    // 흰색
    glColor3f(1.0f, 1.0f, 1.0f);
    // 2d는 double, 2f는 float
    glVertex2f(0.5f, 0.3f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.5f, 0.3f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.0f, -0.2f);

    glEnd();
}

void render2()
{
    // 별 그리기 2
    glBegin(GL_TRIANGLES);
    // 흰색
    glColor3f(1.0f, 1.0f, 1.0f);
    // 2d는 double, 2f는 float
    glVertex2f(0.0f, 0.7f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.2f, -0.1f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.4f, -0.5f);

    glEnd();
}

void render3()
{
    // 별 그리기 3
    glBegin(GL_TRIANGLES);
    // 흰색
    glColor3f(1.0f, 1.0f, 1.0f);
    // 2d는 double, 2f는 float
    glVertex2f(0.0f, 0.7f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.4f, -0.5f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.2f, -0.1f);

    glEnd();
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        leftButtonPressed = true;
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        lastX = xpos;
    }
    else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
    {
        leftButtonPressed = false;
    }
    else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
    {
        rightButtonPressed = true;
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        lastX = xpos;
    }
    else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
    {
        rightButtonPressed = false;
    }
}

void cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
    if (leftButtonPressed)
    {
        double deltaX = xpos - lastX;
        translateX += deltaX * 2.0 / 1280.0;
        lastX = xpos;
    }
    else if (rightButtonPressed)
    {
        double deltaX = xpos - lastX;
        scale += deltaX * 0.01;
        lastX = xpos;
    }
}

int main(void)
{
    // glfw 라이브러리 초기화
    if (!glfwInit())
        return -1;

    GLFWwindow* window;
    window = glfwCreateWindow(1280, 768, "MuSoeunEngine", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetCursorPosCallback(window, cursorPosCallback);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // 별 그리기
        glLoadIdentity();
        glTranslatef(translateX, translateY, 0.0);
        glScalef(scale, scale, 1.0);
        renderStar();
        render2();
        render3();

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}