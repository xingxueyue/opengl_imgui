#include "MainWindow.h"

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

MainWindow::~MainWindow() {}

void MainWindow::InitGLFWwindow()
{
	//设置glfw的错误函数回调
	glfwSetErrorCallback(glfwErrorCallback);

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
	ImGuiIO& io = ImGui::GetIO();
	(void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; //键盘信号
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad; //手柄信号

	//设置初始ImGui的初始风格
	ImGui::StyleColorsDark();

	//设置OpenGL为渲染器
	ImGui_ImplGlfw_InitForOpenGL(glfwWindow, true);
	ImGui_ImplOpenGL3_Init("#version 420"); //OpenGL对应的GLSL版本

}

void MainWindow::renderLoop()
{
	ImGuiIO& io = ImGui::GetIO();
	//窗口背景颜色
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	//目前测试用的变量
	bool show_Imgui_officialDemo = true;
	float sliderValue;

	//渲染循环
	while (!glfwWindowShouldClose(glfwWindow))
	{
		glfwPollEvents();

		//如果窗口最小化则休眠10ms,不进行后续渲染，减少资源消耗
		if (glfwGetWindowAttrib(glfwWindow, GLFW_ICONIFIED) != 0)
		{
			ImGui_ImplGlfw_Sleep(10);
			continue;
		}

		//为ImGui和OpenGL准备新一帧,即清除之前的状态
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		//显示官方的demo窗口
		if (show_Imgui_officialDemo)
			ImGui::ShowDemoWindow(&show_Imgui_officialDemo);

		//ImGUI窗口
		ImGui::Begin("MainImGuiWindow");

		ImGui::Text("This is ImGui Window");
		ImGui::Checkbox("Offical Demo Window", &show_Imgui_officialDemo);

		ImGui::SliderFloat("slider", &sliderValue, 0.0f, 1.0f);
		//ImGui::SameLine(0.0f,5.0f);//两个控件
		ImGui::ColorEdit3("background color", (float*)&clear_color);

		//显示IMGUI窗口帧率
		ImGui::Text("Now frame is : %.1f FPS", io.Framerate);

		ImGui::End();

		//渲染
		ImGui::Render();
		int display_w, display_h;
		glfwGetFramebufferSize(glfwWindow, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);//设置视图属性
		glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);//刷新颜色缓冲
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(glfwWindow);//交换缓冲区
	}
}

void MainWindow::deleteWindow()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(glfwWindow);
	glfwTerminate();
}

void MainWindow::glfwErrorCallback(int error_code, const char* description)
{
	std::cout << "error_code: " << error_code << std::endl;
	std::cout << "error_description" << description << std::endl;
}