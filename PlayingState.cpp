#include "PlayingState.h"

PlayingState::PlayingState(GameEngine& engine)
    : engine(engine), fallTimer(0.0f), fallInterval(1.0f)
{
}

void PlayingState::update (GameEngine& engine, float deltaTime) {}
void PlayingState::handleInput(GameEngine&) {}
void PlayingState::onEnter() {}
void PlayingState::onExit() {}

