#pragma once
#include "TetrominoType.h"
#include "Tetromino.h"

class TetrominoFactory {
public:
	Tetromino create(TetrominoType type);
	Tetromino createRandom();

};

