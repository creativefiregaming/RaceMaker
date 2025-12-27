
#include "raylib.h"
#include "Scene.h"
#include "Application.h"

#include <iostream>
#include <fstream>

#include "imgui.h"
#include "rlImGui.h"



float targetfps = 120;


Texture t;

void AddBall(Scene* scene)
{
	scene->AddRaceBall(50, 50, 50, 90, 90, &t);
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

	
	

	GUIWindow* mainGUIwindow = new GUIWindow("Projects", false, false, false, 1000, 10, 460, 830);

	mainGUIwindow->AddText("You have not created any simulations.");
	mainGUIwindow->AddButton("Create new Simulation", 100, 0, 235, 50, [&]() { AddBall(SCN); });

	GUIWindow* aboutwindow = new GUIWindow("About", false, false, false, 500, 10, 490, 430);

	aboutwindow->AddText("Version: ALPHA v0.1\n");
	aboutwindow->AddText("RaceMaker is an open-source project. \nOriginally created by DiamondSauce");
	aboutwindow->AddButton("RaceMaker Github repo", 105, 50, 250, 50, [&]() { app->OpenURL("https://github.com/creativefiregaming/RaceMaker"); });
	aboutwindow->AddButton("RaceMaker website", 105, -50, 250, 50, [&]() { app->OpenURL("https://engine.creativefiregames.com"); });

	t = LoadTexture("mmharvey.png");
	if (t.id == 0) {
		std::cout << "Failed to load texture!" << std::endl;
	}


	SCN->AddGUIWindow(mainGUIwindow);
	SCN->AddGUIWindow(aboutwindow);

	while (!WindowShouldClose())
	{
		SCN->Play();
	}
	CloseWindow();
	return 0;
}