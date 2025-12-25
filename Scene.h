#pragma once

#include "Objects.h"
#include <iostream>
#include <vector>

class RaceBall;

class Scene {
private:

	std::string SceneName;

	std::vector<RaceBall*> raceballs;
public:

	Scene(std::string name);

	RaceBall* AddRaceBall(float x, float y, float r, float speedX, float speedY, Texture* texture);

	void Play();
};