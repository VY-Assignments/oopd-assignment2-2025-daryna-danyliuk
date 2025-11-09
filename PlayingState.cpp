#include "PlayingState.h"
#include "GameEngine.h"
#include "Board.h"
#include "Tetromino.h"

PlayingState::PlayingState()
    : fallTimer(0.0f), fallInterval(0.5f)
{
}

void PlayingState::update(GameEngine& engine, float deltaTime) {
	fallTimer += deltaTime;
	if (fallTimer >= fallInterval) {
		engine.moveTetromino(0, +1);
		fallTimer = 0;
	}
}

void PlayingState::handleInput(GameEngine& engine) {
}

void PlayingState::onEnter() {
}

void PlayingState::onExit() {
}