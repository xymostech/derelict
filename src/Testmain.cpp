#include <UnitTest++.h>

#include <GL/glfw.h>

int main() {
	glfwInit();
	glfwOpenWindow(5, 5, 0, 0, 0, 0, 16, 0, GLFW_WINDOW);

	return UnitTest::RunAllTests();

	glfwTerminate();
}
