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
