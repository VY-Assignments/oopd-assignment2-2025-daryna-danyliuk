#pragma once
#include "GameState.h"
class GameEngine;

class PlayingState : public GameState
{
private:
	float fallTimer;
	float fallInterval;
public:
	explicit PlayingState(GameEngine& engine);
	void update(GameEngine& engine, float deltaTime) override;
	void handleInput(GameEngine&) override;
	void onEnter() override;
	void onExit() override;

};