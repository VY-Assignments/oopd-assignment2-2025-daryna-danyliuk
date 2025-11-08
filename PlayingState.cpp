#include "PlayingState.h"
#include "GameEngine.h"
#include "Board.h"
#include "Tetromino.h"

PlayingState::PlayingState()
    : fallTimer(0.0f), fallInterval(0.5f)
{
}

void PlayingState::update(GameEngine& engine, float deltaTime) {
  
}

void PlayingState::handleInput(GameEngine& engine) {
}

void PlayingState::onEnter() {
}

void PlayingState::onExit() {
}