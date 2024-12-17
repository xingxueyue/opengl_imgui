#include "MainMenuBar.h"
#include "imgui.h"
MainMenuBar::MainMenuBar()
{}

MainMenuBar::~MainMenuBar()
{}

void MainMenuBar::showMenuBar()
{
	//注意BeginMenuBar和BeginMainMenuBar
	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			showFileMenu();
			ImGui::EndMenu();
		}

		ImGui::EndMenuBar();
	}
}


void MainMenuBar::showFileMenu()
{
	ImGui::MenuItem(("fileMenu"), NULL, false, false);
	if (ImGui::MenuItem("New")) {}
	if (ImGui::MenuItem("Open", "Ctrl+O")) {}
}