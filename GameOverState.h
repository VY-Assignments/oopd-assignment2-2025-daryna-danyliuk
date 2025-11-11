#pragma once
#include "GameState.h"
class GameEngine;

class GameOverState : public GameState
{
public:
	explicit GameOverState(GameEngine& engine);
	void update(GameEngine&, float deltaTime) override;
	void handleInput(GameEngine&) override;
	void onEnter() override;
	void onExit() override;
};