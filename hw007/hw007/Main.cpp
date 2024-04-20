#include <GLFW/glfw3.h>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

void drawStar(float x, float y) {
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

int main() {
    GLFWwindow* window;

    // Initialize the library
    if (!glfwInit())
        return -1;

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(800, 600, "Stars", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Seed the random number generator
    srand(time(nullptr));

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)) {
        // Render here
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw stars
        for (int i = 0; i < 300; ++i) {
            float x = (rand() % 800) / 800.0f * 2.0f - 1.0f; // Random x-coordinate (-1.0 to 1.0)
            float y = (rand() % 600) / 600.0f * 2.0f - 1.0f; // Random y-coordinate (-1.0 to 1.0)
            glColor3f((float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX); // Random color
            drawStar(x, y);
        }

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}