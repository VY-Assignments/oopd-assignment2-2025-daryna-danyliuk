#include "Controller.h"
#include "GameEngine.h"

void Controller::handleCommand(InputCommand command, GameEngine& engine) {
    auto& tetromino = engine.getCurrentTetrominoRef();

    switch (command) {
    case InputCommand::MoveLeft:
        tetromino.move(-1, 0);
        break;

    case InputCommand::MoveRight:
        tetromino.move(1, 0);
        break;

    case InputCommand::MoveDown:
        tetromino.move(0, 1);
        break;

    case InputCommand::RotateClockwise:
        tetromino.rotateClockwise();
        break;

    case InputCommand::RotateCounterClockwise:
        tetromino.rotateCounterClockwise();
        break;

    case InputCommand::Pause:
        engine.pause();
        break;

    default:
        break;
    }
}