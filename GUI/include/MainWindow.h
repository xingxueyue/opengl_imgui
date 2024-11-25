﻿#ifndef MAINWINDOW
#define MAINWINDOW

#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>

class MainWindow
{
public:
	MainWindow();
	~MainWindow();

private:
	void InitGLFWwindow();
	void InitIMGUI();
	void renderLoop();
	void deleteWindow();
	void glfwErrorCallback(int error_code, const char* description);

public:

	MainWindow* mainWindow;
private:
	GLFWwindow* glfwWindow;
};


#endif // MAINWINDOW
