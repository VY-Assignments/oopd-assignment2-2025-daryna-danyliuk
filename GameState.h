#pragma once

class GameEngine;

class GameState {
private:
public:
	virtual void update(GameEngine&, float deltaTime) = 0;
	virtual void handleInput(GameEngine&) = 0;
	virtual void onEnter() = 0;
	virtual void onExit() = 0;
	virtual ~GameState() = default;
};

