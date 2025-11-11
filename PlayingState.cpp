#include "PlayingState.h"
#include "GameEngine.h"
#include "Board.h"
#include "Tetromino.h"

PlayingState::PlayingState(GameEngine& engine)
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
void PlayingState::onEnter() {
	fallTimer = 0.0f;

}
void  PlayingState::onExit() {

}
void PlayingState::handleInput(GameEngine&) {
}
