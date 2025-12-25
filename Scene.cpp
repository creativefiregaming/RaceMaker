#include "raylib.h"	
#include "Scene.h"
#include "Objects.h"
#include <iostream>
#include <memory>
#include <vector>


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
	EndDrawing();
}