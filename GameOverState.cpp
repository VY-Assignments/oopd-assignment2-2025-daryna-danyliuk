#include "GameOverState.h"
#include "GameEngine.h"
#include "PlayingState.h"
#include <iostream>

GameOverState::GameOverState(GameEngine& engine)
{};

void GameOverState::update(GameEngine& engine, float deltaTime) {
	std::cout << "Game Over state is active" << std::endl;
}

void GameOverState::onEnter() {
	std::cout << "Game over mode" << std::endl;

}
void  GameOverState::onExit() {

}
void GameOverState::handleInput(GameEngine& engine) {
	std::cout << "Restart pressed" << std::endl;
	engine.getBoardRef().clear();
	engine.changeState(std::make_unique<PlayingState>(engine));
	engine.start();
}