#pragma once
#include <SFML/Graphics.hpp>
#include "GameEngine.h"
#include "Renderer.h"
#include "Controller.h"
#include "InputCommand.h"


class Application
{
private: 
	sf::RenderWindow window;
	sf::Clock clock;
	GameEngine engine;
	Renderer renderer;
	Controller controller;
	bool isRunning = true;
	InputCommand mapKeyToCommand(sf::Keyboard::Key key);

public:
	Application();
	void run();
	void processEvents();
	void update(float deltaTime);
	void render();
	void close();
};

