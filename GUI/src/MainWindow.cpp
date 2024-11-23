#include "MainWindow.h"

using namespace std;

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <lua.h>

MainWindow::MainWindow()
{
	//glfw创建窗口和上下文
	InitGLFWwindow();
	//初始化IMGUI
	InitIMGUI();
	//渲染循环
	renderLoop();
	//释放资源
	deleteWindow();
}

MainWindow::~MainWindow(){}

void MainWindow::InitGLFWwindow()
{
	if (!glfwInit())
		std::exit(1);

	//glfw初始化OpenGL参数
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//创建窗口
	glfwWindow = glfwCreateWindow(1280, 720, "OpenGLDemo", nullptr, nullptr);
	if (glfwWindow == nullptr)
	{
		std::cout << "create glfwWindow fail" << std::endl;
		glfwTerminate();
		std::exit(1);
	}
	glfwMakeContextCurrent(glfwWindow); //建立上下文
	glfwSwapInterval(1); //垂直同步，0关闭，1开启

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		std::exit(1);
	}
}

void MainWindow::InitIMGUI()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
}

void MainWindow::renderLoop()
{}

void MainWindow::deleteWindow()
{}