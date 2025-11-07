#pragma once
#include "GameState.h"
#include "Board.h"
 
class GameEngine;
class Board;

class PlayingState : public GameState
{
private:
	Board board;
	GameEngine& engine;
	Tetromino current;
	TetrominoFactory factory;
	float fallTimer;
	float fallInterval;
public:
	PlayingState(GameEngine& engine);
	void update(GameEngine& engine, float deltaTime) override;
	void handleInput(GameEngine&) override;
	void onEnter() override;
	void onExit() override;

};