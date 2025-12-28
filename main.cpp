
#include "raylib.h"
#include "Scene.h"
#include "Application.h"

#include <iostream>
#include <fstream>

#include "imgui.h"
#include "rlImGui.h"


std::string name_buffer;

float targetfps = 120;

Scene* createprojscn;

Scene* currentscene;


Texture t;

void AddBall(Scene* scene)
{
	scene->AddRaceBall(50, 50, 50, 90, 90, &t);
}

void CreateProjSCN()
{
	createprojscn = new Scene("createproj");

	GUIWindow* mainwin = new GUIWindow("Create new simulation", true, true, false, 600, 400, 200, 300);


	mainwin->AddTextInput("input", name_buffer);

	createprojscn->AddGUIWindow(mainwin);
}

void GoToCreateProjectScene(Scene* scene)
{
	CreateProjSCN();
	currentscene = createprojscn;
}


int main()
{
	

	InitWindow(1470, 850, "RaceMaker ALPHA v0.1 Debug");
	
	rlImGuiSetup(true);
	
	ImGuiStyle& style = ImGui::GetStyle();

	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.06f, 0.69f, 0.02f, 1.0f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.39f, 0.01f, 1.0f);

	SetTargetFPS(targetfps);

	Scene* SCN = new Scene("scn");

	Application* app = new Application();

	
	

	GUIWindow* projectselectwindow = new GUIWindow("Project select", false, false, false, 1000, 10, 460, 830);

	projectselectwindow->AddText("You have not created any simulations.");
	projectselectwindow->AddButton("Create new Simulation", 100, 0, 235, 50, [&]() { GoToCreateProjectScene(SCN); });

	GUIWindow* aboutwindow = new GUIWindow("About", false, false, false, 500, 10, 490, 430);

	aboutwindow->AddText("Version: ALPHA v0.1\n");
	aboutwindow->AddText("RaceMaker is an open-source project. \nOriginally created by DiamondSauce \nBuilt in C++");
	aboutwindow->AddButton("RaceMaker Github repo", 105, 50, 250, 50, [&]() { app->OpenURL("https://github.com/creativefiregaming/RaceMaker"); });
	aboutwindow->AddButton("RaceMaker website", 105, -50, 250, 50, [&]() { app->OpenURL("https://engine.creativefiregames.com"); });

	GUIWindow* projectwindow = new GUIWindow("Project", false, false, false, 500, 450, 490, 390);

	projectwindow->AddText("Starter Project\n");
	projectwindow->AddButton("Open Project", 0, 0, 150, 50, [&]() { app->OpenURL("https://engine.creativefiregames.com"); });

	GUIWindow* extraswindow = new GUIWindow("Extras", false, false, false, 10, 10, 480, 830);

	extraswindow->AddText("CREDITS: \n\nProject started by DiamondSauce (@creativefiregaming)\n\nInspired by simulations mad by @Simulando2d \n\nTop contributers: \n \n@creativefiregaming \n\n\n\n\n\nLibraries used: \n\nDear ImGui (GUI) \nRaylib (rendering and handling) \nrlImGui (implementing ImGui to Raylib) \n\n\n\n\n @2025 MIT liscense");

	t = LoadTexture("mmharvey.png");
	if (t.id == 0) {
		std::cout << "Failed to load texture!" << std::endl;
	}


	SCN->AddGUIWindow(projectselectwindow);
	SCN->AddGUIWindow(aboutwindow);
	SCN->AddGUIWindow(projectwindow);
	SCN->AddGUIWindow(extraswindow);

	currentscene = SCN;

	while (!WindowShouldClose())
	{
		currentscene->Play();
	}
	CloseWindow();
	return 0;
}