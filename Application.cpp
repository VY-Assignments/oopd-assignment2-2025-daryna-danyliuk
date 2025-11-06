#include "Application.h"

Application::Application()
	: window(sf::VideoMode(800, 600), "Tetris"), isRunning(true) {
	engine.start();
}

void Application :: run() {
	clock.restart();
	while (isRunning && window.isOpen()) {
		processEvents();
		float deltaTime = clock.restart().asSeconds();
		engine.update(deltaTime);
		render();
	}
}