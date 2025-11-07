#pragma once
#include "TetrominoType.h"
#include "Tetromino.h"

class TetrominoFactory {
	Tetromino create(TetrominoType type);
	Tetromino createRandom();

};

