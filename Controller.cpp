#include "Controller.h"
#include "GameEngine.h"

void Controller::handleCommand(InputCommand command, GameEngine& engine) {
    auto& tetromino = engine.getCurrentTetrominoRef();

    switch (command) {
    case InputCommand::MoveLeft:
        engine.moveTetromino(-1, 0);
        break;

    case InputCommand::MoveRight:
        engine.moveTetromino(1, 0);
        break;

    case InputCommand::MoveDown:
        engine.moveTetromino(0, 1);
        break;

    case InputCommand::RotateClockwise:
        engine.rotateTetrominoCW();
        break;

    case InputCommand::RotateCounterClockwise:
        engine.rotateTetrominoCCW();
        break;
    }
}