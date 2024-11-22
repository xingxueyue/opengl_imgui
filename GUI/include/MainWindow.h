#ifndef MAINWINDOW
#define MAINWINDOW

#include <iostream>

class MainWindow
{
public:
	MainWindow();
	~MainWindow();

	void showData();

public:
	MainWindow* mainWindow;
private:
	int data;
};


#endif // MAINWINDOW
