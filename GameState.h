#pragma once

class GameEngine;

class GameState {
public:
	virtual void update(GameEngine&, float deltaTime) = 0;
	virtual void handleInput(GameEngine&) {};
	virtual void onEnter() {};
	virtual void onExit() {};
	virtual ~GameState() = default;
};