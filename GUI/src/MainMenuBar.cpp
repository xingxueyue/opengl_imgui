#include "MainMenuBar.h"
#include "imgui.h"
MainMenuBar::MainMenuBar()
{}

MainMenuBar::~MainMenuBar()
{}

void MainMenuBar::showMainMenuBar()
{
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{

			ImGui::EndMenu;
		}

		ImGui::EndMainMenuBar();
	}
}