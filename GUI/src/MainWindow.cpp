#include "MainWindow.h"

using namespace std;

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <glad/glad.h>
#include <lua.h>
#include <GLFW/glfw3.h>

MainWindow::MainWindow()
{
	//glfw初始化OpenGL
	glfwWindowHint(GLFW_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//glfw创建窗口和上下文
}

MainWindow::~MainWindow(){}

void MainWindow::showData()
{
	
}