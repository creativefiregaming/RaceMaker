#include "raylib.h"	
#include "Scene.h"
#include "Objects.h"
#include <iostream>
#include <memory>
#include <vector>
#include <functional>

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

void Scene::AddGUIWindow(GUIWindow* win)
{
	Scene::windows.push_back(win);
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

	//render GUI

	for (GUIWindow* window : Scene::windows)
	{
		window->render();
	}

	EndDrawing();
}

GUIElement::GUIElement(std::string element_type, std::string content, float x, float y, float w, float h, std::function<void()> command)
{
	etype = element_type;
	cont = content;
	X = x;
	Y = y;
	W = w;
	H = h;
	cmd = command;
}

GUIWindow::GUIWindow(std::string name, bool resizable, bool moveable, bool collapsable, float x, float y, float w, float h)
{
	windowname = name;
	resize = resizable;
	move = moveable;
	collapse = collapsable;
	X = x;
	Y = y;
	W = w;
	H = h;
}

void GUIWindow::AddText(std::string text)
{
	elements.emplace_back("txt", text, 0, 0, 0, 0, []{});
}

void GUIWindow::AddButton(std::string text, float x, float y, float width, float height, std::function<void()> command)
{
	elements.emplace_back("btn", text, x, y, width, height, command);
}

void GUIWindow::render()
{

	rlImGuiBegin();

	ImGui::SetNextWindowPos(ImVec2(GUIWindow::X, GUIWindow::Y), ImGuiCond_Always);
	ImGui::SetNextWindowSize(ImVec2(GUIWindow::W, GUIWindow::H), ImGuiCond_Always);

	ImGuiWindowFlags r;
	if (GUIWindow::resize)
	{
		r = ImGuiWindowFlags_None;
	}
	else {
		r = ImGuiWindowFlags_NoResize;
	}

	ImGuiWindowFlags m;
	if (GUIWindow::move)
	{
		m = ImGuiWindowFlags_None;
	}
	else {
		m = ImGuiWindowFlags_NoMove;
	}

	ImGuiWindowFlags c;
	if (GUIWindow::collapse)
	{
		c = ImGuiWindowFlags_None;
	}
	else {
		c = ImGuiWindowFlags_NoCollapse;
	}


	ImGui::Begin(GUIWindow::windowname.c_str(), nullptr, m | r | c);

	//process GUI elements
	for (GUIElement& ele : GUIWindow::elements)
	{
		//text element
		if (ele.etype == "txt")
		{
			ImGui::Text("%s", ele.cont.c_str());
		}
		//button element
		if (ele.etype == "btn")
		{
			//change pos offset
			ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + ele.X, ImGui::GetCursorPos().y + ele.X));
			//button
			if (ImGui::Button(ele.cont.c_str(), ImVec2(ele.W, ele.H)))
			{
				ele.cmd();
			}
		}
	}
	ImGui::End();

	rlImGuiEnd();
}