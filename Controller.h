#pragma once
#include "InputCommand.h"

class GameEngine;

class Controller {
public:
    void handleCommand(InputCommand command, GameEngine& engine);
};