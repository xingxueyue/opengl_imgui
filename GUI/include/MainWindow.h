#ifndef MAINWINDOW
#define MAINWINDOW

#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <imgui.h>

class MainWindow
{
public:
	MainWindow();
	~MainWindow();

	static void glfwErrorCallback(int error_code, const char* description);
private:
	void InitGLFWwindow();
	void InitIMGUI();
	void renderLoop();
	void deleteWindow();

public:

	MainWindow* mainWindow;
private:
	GLFWwindow* glfwWindow;
	ImGuiIO& io;
};


#endif // MAINWINDOW
