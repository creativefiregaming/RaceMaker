#include "raylib.h"
#include "Scene.h"
#include <iostream>


int main()
{
	InitWindow(1470, 850, "Create a ball race!");

	SetTargetFPS(60);

	Scene* SCN = new Scene("scn");

	Texture plrtext = LoadTexture("mmharvey.png");
	if (plrtext.id == 0) {
		std::cout << "Failed to load texture!" << std::endl;
	}

	SCN->AddRaceBall(50, 50, 50, 3, 3, &plrtext);
	while (!WindowShouldClose())
	{
		SCN->Play();
	}
	CloseWindow();
	return 0;
}