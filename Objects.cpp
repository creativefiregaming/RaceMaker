#include "Objects.h"
#include "Scene.h"
#include "raylib.h"

RaceBall::RaceBall(float xPosition, float yPosition, float radius, float xSpeed, float ySpeed, Texture* balltxt, Scene* scene) 
{
	scn = scene;
	balltexture = balltxt;
	x = xPosition;
	y = yPosition;
	r = radius;
	spdX = xSpeed;
	spdY = ySpeed;
	vx = spdX;
	vy = spdY;
}

void RaceBall::Update()
{
	RaceBall::x += RaceBall::vx * GetFrameTime();
	RaceBall::y += RaceBall::vy * GetFrameTime();
}

void RaceBall::Render()
{
	Rectangle src = { 0.0f, 0.0f, RaceBall::balltexture->width, RaceBall::balltexture->height };
	Rectangle dest = { RaceBall::x - RaceBall::r, RaceBall::y - RaceBall::r, RaceBall::r * 2, RaceBall::r * 2 };
	Vector2 ori = { 0, 0 };
	DrawTexturePro(*RaceBall::balltexture, src, dest, ori, 0.0f, WHITE);
}