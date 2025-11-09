#include "GameEngine.h"
#include "PlayingState.h"

GameEngine::GameEngine()
	: isRunning(false)
{}

void GameEngine::start() {
	auto newState = std::make_unique<PlayingState>(*this);
	changeState(std::move(newState));
	isRunning = true;
	currentTetromino = factory.createRandom();
}
void GameEngine::pause() {
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
void GameEngine::rotateTetrominoÑCW() {
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
void GameEngine::dropTetromino() {

}
void GameEngine::lockTetromino() {

}