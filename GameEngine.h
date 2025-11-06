#pragma once
#include <memory>
#include "ScoreManager.h"
#include "SaveManager.h"
#include "Board.h"
#include "TetrominoFactory.h"
#include "Controller.h"
#include "GameState.h"



class GameEngine {

public:
	void start();
	void pause();
	void resume();
	void gameLoop();
	void update(GameEngine& engine, float deltaTime);
	void changeState(std::unique_ptr<GameState> newState);
private:
	Board board;
	ScoreManager scoreManager;
	SaveManager saveManager;
	TetrominoFactory factory;
	Controller cmd;
	std::unique_ptr<GameState> currentState;
	bool isRunning;
};

