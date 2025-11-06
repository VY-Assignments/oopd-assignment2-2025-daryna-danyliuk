#include "GameEngine.h"
#include "PlayingState.h"

void GameEngine::start() {
	auto newState = std::make_unique<PlayingState>(*this);
	changeState(std::move(newState));
	isRunning = true;
	gameLoop();


}
void GameEngine::changeState(std::unique_ptr<GameState> newState) {
	if (currentState) {
		currentState->onExit();
	}
	currentState = std::move(newState);
	currentState->onEnter();

}

void GameEngine::gameLoop() {
	while (isRunning == true) {
		currentState->handleInput(*this);
		currentState->update(*this, 0.0f);
	}

}