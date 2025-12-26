#include "raylib.h"	
#include "Scene.h"
#include "Objects.h"
#include <iostream>
#include <memory>
#include <vector>

#include "imgui.h"
#include "rlImGui.h"


Scene::Scene(std::string name)
{
	Scene::SceneName = name;
}

RaceBall* Scene::AddRaceBall(float x, float y, float r, float speedX, float speedY, Texture* texture)
{
	RaceBall* bl = new RaceBall(x, y, r, speedX, speedY, texture, this);
	Scene::raceballs.push_back(bl);
	return Scene::raceballs.back();
}

void Scene::Play()
{
	ClearBackground(BLACK);
	BeginDrawing();
	for (RaceBall* ball : Scene::raceballs)
	{
		ball->Update();
		ball->Render();
	}

	rlImGuiBegin();

	ImGui::SetNextWindowPos(ImVec2(10, 10), ImGuiCond_Always);
	ImGui::SetNextWindowSize(ImVec2(225, 500), ImGuiCond_Always);
	ImGui::Begin("Options", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
	ImGui::Text("Options");
	if (ImGui::Button("Quit RaceMaker", ImVec2(110, 30)))
	{
		CloseWindow();
	}
	ImGui::End();

	rlImGuiEnd();

	EndDrawing();
}