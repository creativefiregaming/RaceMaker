#pragma once

#include "raylib.h"
#include "Scene.h"

class Scene;


class RaceBall {
private:
	float vx;
	float vy;
	Scene* scn;
public:
	Texture* balltexture;
	float spdX;
	float spdY;
	float x;
	float y;
	float r;
	RaceBall(float xPosition, float yPosition, float radius, float xSpeed, float ySpeed, Texture* balltxt, Scene* scene);

	void Update();

	void Render();
};