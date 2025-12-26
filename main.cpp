#include "raylib.h"
#include "Scene.h"
#include <iostream>

#include "imgui.h"
#include "rlImGui.h"

void doth()
{
	std::cout << "BUTTON PRESSED \n";
}

int main()
{
	InitWindow(1470, 850, "Create a ball race!");

	rlImGuiSetup(true);

	SetTargetFPS(60);

	Scene* SCN = new Scene("scn");


	GUIWindow* mainGUIwindow = new GUIWindow("Main", false, false, false, 10, 10, 100, 500);

	mainGUIwindow->AddText("This is \na cool \nwindow");

	mainGUIwindow->AddButton("button", 50, 0, 75, 50, doth);

	Texture plrtext = LoadTexture("mmharvey.png");
	if (plrtext.id == 0) {
		std::cout << "Failed to load texture!" << std::endl;
	}

	SCN->AddRaceBall(50, 50, 50, 3, 3, &plrtext);

	SCN->AddGUIWindow(mainGUIwindow);

	while (!WindowShouldClose())
	{
		SCN->Play();
	}
	CloseWindow();
	return 0;
}