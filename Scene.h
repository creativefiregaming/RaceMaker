#pragma once

#include "Objects.h"
#include <iostream>
#include <vector>
#include <functional>

class RaceBall;
class GUIWindow;

class Scene {
private:

	std::string SceneName;

	std::vector<RaceBall*> raceballs;
	std::vector<GUIWindow*> windows;

public:

	Scene(std::string name);

	RaceBall* AddRaceBall(float x, float y, float r, float speedX, float speedY, Texture* texture);

	void AddGUIWindow(GUIWindow* win);

	void Play();
};

class GUIElement {
private:

public:
	std::string* inputoutput;
	std::string etype;
	std::string cont;

	float X;
	float Y;
	float W;
	float H;
	std::function<void()> cmd;

	GUIElement(std::string element_type, std::string content, float x, float y, float w, float h, std::function<void()> command, std::string* io);
	//ELEMENT TYPES:
	//TEXT: txt
	//BUTTON: btn
	//TEXT INPUT: tin
};

class GUIWindow {
public:
	std::vector<GUIElement> elements;

	std::string windowname;

	bool resize;
	bool move;
	bool collapse;

	float X;
	float Y;
	float W;
	float H;
	GUIWindow(std::string name, bool resizable, bool moveable, bool collapsable, float x, float y, float w, float h);

	void AddText(std::string text);
	void AddButton(std::string text, float x, float y, float w, float h, std::function<void()> command);
	void AddTextInput(const std::string& text, std::string& iobuffer);

	void render();


};
