#include "GameEngine.h"
#include "GameState.h"
#include "PlayingState.h"
#include "GameOverState.h"

GameEngine::GameEngine()
	: isRunning(false)
{}

void GameEngine::start() {
	auto newState = std::make_unique<PlayingState>(*this);
	changeState(std::move(newState));
	isRunning = true;
	currentTetromino = factory.createRandom();
}
void GameEngine::resume() {
}
void GameEngine::changeState(std::unique_ptr<GameState> newState) {
	if (currentState) {
		currentState->onExit();
	}
	currentState = std::move(newState);
	currentState->onEnter();

}
void GameEngine::update(float deltaTime) {
	if (currentState)
		currentState->update(*this, deltaTime);
}
void GameEngine::rotateTetrominoCW() {
	Tetromino testTetromino = currentTetromino;
	testTetromino.rotateClockwise();
	auto coords = testTetromino.getGlobalCoords();
	for (int i = 0; i < BLOCKS_NUM; ++i) {
		int x = coords[i].first;
		int y = coords[i].second;
		if (!board.isInside(x, y) || board.isOccupied(x, y)) {
			return;
		}
	}
	currentTetromino.rotateClockwise();
}
void GameEngine::rotateTetrominoCCW() {
	Tetromino testTetromino = currentTetromino;
	testTetromino.rotateCounterClockwise();
	auto coords = testTetromino.getGlobalCoords();
	for (int i = 0; i < BLOCKS_NUM; ++i) {
		int x = coords[i].first;
		int y = coords[i].second;
		if (!board.isInside(x, y) || board.isOccupied(x, y)) {
			return;
		}
	}
	currentTetromino.rotateCounterClockwise();
}
void GameEngine::lockTetromino() {
	board.placeTetromino(currentTetromino);
	board.clearFullLines();
	currentTetromino = factory.createRandom();
	auto coords = currentTetromino.getGlobalCoords();
	for (int i = 0; i < BLOCKS_NUM; ++i) {
		int x = coords[i].first;
		int y = coords[i].second;
		if (board.isOccupied(x, y)) {
			isRunning = false;
			changeState(std::make_unique<GameOverState>(*this));
			return;
		}
	}
}
void GameEngine::moveTetromino(int dx, int dy) {
	Tetromino testTetromino = currentTetromino;
	testTetromino.move(dx, dy);
	auto coords = testTetromino.getGlobalCoords();
	for (int i = 0; i < BLOCKS_NUM; ++i) {
		int x = coords[i].first;
		int y = coords[i].second;
		if (!board.isInside(x, y) || board.isOccupied(x, y)) {
			if (dy > 0) {
				lockTetromino();
			}
			return;
		}
	}
	currentTetromino.move(dx, dy);
}
void GameEngine::dropTetromino() {
	Tetromino testTetromino = currentTetromino;
	bool isDropping = true;
	while (isDropping) {
		testTetromino.move(0, +1);
		auto coords = testTetromino.getGlobalCoords();
		bool isColision = false;
		for (int i = 0; i < BLOCKS_NUM; ++i) {
			int x = coords[i].first;
			int y = coords[i].second;
			if (!board.isInside(x, y) || board.isOccupied(x, y)) {
				isColision = true;
				break;
			}
		}
		if (isColision) {
			isDropping = false;
		}
		else {
			currentTetromino.move(0, +1);
		}
	}
	lockTetromino();
}